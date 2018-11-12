from flask import Flask, jsonify, request
from collections import namedtuple
import json
import mysql.connector

app = Flask(__name__)



#### QUERY SECTION ####

query_get_all_devices = ("SELECT * FROM Devices")


#### QUERY SECTION ####


# important dont ferget to close the connction through obj.close() at the end of your function
def getMysqlConnection():
    #complete
    #return mysql.connector.connect(user='root', host='db', port='3306', password='test', database='smhoezma')
    #dev
    return mysql.connector.connect(user='root', host='192.168.178.30', port='3306', password='test', database='smhoezma')


class Payload(object):
    def __init__(self, j):
        self.__dict__ = json.loads(j)


@app.route("/")
def hello():
    return "Hello World!"


@app.route('/test', methods=['GET', 'POST'])
def get_tasks():
    # load json file which contains node
    with open('nodes.json', 'r') as myfile:
        return json.dumps({'success': True}), 200, {'ContentType': 'application/json'}
    return json.dumps({'success': False}), 400, {'ContentType': 'application/json'}

    # return saved_data[0].ip


# connect to mysql server inside docker network and get all devices return them as described in readme
# will return whole list of devices
@app.route('/api/alldevices', methods=['GET'])
def return_all_devices():
    try:
        mysql_obj= getMysqlConnection()
        cur = mysql_obj.cursor()
        cur.execute(query_get_all_devices)

        row_headers = [x[0] for x in cur.description]  # this will extract row headers
        rv = cur.fetchall()
        json_data = []
        for result in rv:
            json_data.append(dict(zip(row_headers, result)))
        return json.dumps(json_data)

    except IOError:
        return json.dumps({'success': False}), 400, {'ContentType': 'application/json'}


# return the object of one specific device which is found by the ip
#{
#  "Ip": "10.10.10.10"
#}
@app.route('/api/device', methods=['POST'])
def return_one_devices():
    data = request.get_json()
    device_ip = data['Ip']
    try:
        with open('../nodes.json', 'r') as myfile:
            data = myfile.read().replace('\n', '')
    except IOError:
        return json.dumps({'success': False, 'Errorcode': 'Please enter valid ip'}), 400, {'ContentType': 'application/json'}


# just return all the sensor values
@app.route('/api/sensor', methods=['POST'])
def return_sensors():
    return json.dumps({'success': False, 'Errorcode': 'Please enter valid ip'}), 400, {'ContentType': 'application/json'}


def find_object_by_ip(ip, saved_data):
    for val in saved_data.Devices:
        if val.Ip == ip:
            return val
        return False


def compare_json_data(received_data, saved_data):
    counter = 0
    for val in saved_data:
        counter += 1
        if received_data.ip == val.ip:
            return counter

    return False


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')