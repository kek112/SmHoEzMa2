from flask import Flask, jsonify, request
from collections import namedtuple
import json
import mysql.connector

app = Flask(__name__)


#### QUERY SECTION ####



#### QUERY SECTION ####



@app.route("/")
def hello():
    return "Hello World!"


# connect to mysql server inside docker network and get all devices return them as described in readme
# will return whole list of devices
@app.route('/api/alldevices', methods=['GET'])
def return_all_devices():
    query_get_all_devices = "SELECT * FROM Devices"
    try:
        return send_query_to_db(query_get_all_devices)
    except IOError:
        return json.dumps({'success': False}), 400, {'ContentType': 'application/json'}


# return the object of one specific device which is found by the ip
#{
#  "IP": "10.10.10.10"
#}
@app.route('/api/device', methods=['Get','POST'])
def return_one_devices():
    data = request.get_json()
    device_ip = data['IP']
    query_specific_device = "SELECT * FROM `Devices` WHERE IP = \"" + device_ip + "\""
    try:
        return send_query_to_db(query_specific_device)
    except IOError:
        return json.dumps({'success': False, 'Errorcode': 'Please enter valid ip'}), 400, {'ContentType': 'application/json'}

# just return all the lamps
@app.route('/api/lamps', methods=['GET'])
def return_lamps():
    query_get_lamp = "SELECT * FROM `Devices` WHERE `GeraeteNummer` != 0"
    try:
        return send_query_to_db(query_get_lamp)
    except IOError:
        return json.dumps({'success': False}), 400, {'ContentType': 'application/json'}


# just return all the sensor values
@app.route('/api/sensor', methods=['GET'])
def return_sensors():
    query_get_sensor = "SELECT * FROM `Devices` WHERE `GeraeteNummer` = 0"
    try:
        return send_query_to_db(query_get_sensor)
    except IOError:
        return json.dumps({'success': False}), 400, {'ContentType': 'application/json'}


def send_query_to_db(query):
    mysql_obj = getMysqlConnection()
    cur = mysql_obj.cursor()
    cur.execute(query)

    row_headers = [x[0] for x in cur.description]  # this will extract row headers
    rv = cur.fetchall()  # ectract data
    mysql_obj.close()  # close connection

    json_data = []
    for result in rv:
        json_data.append(dict(zip(row_headers, result)))
    return json.dumps(json_data)


# important dont ferget to close the connction through obj.close() at the end of your function
def getMysqlConnection():
    #complete
    #return mysql.connector.connect(user='root', host='db', port='3306', password='test', database='smhoezma')
    #dev
    return mysql.connector.connect(user='root', host='192.168.178.30', port='3306', password='test', database='smhoezma')


class Payload(object):
    def __init__(self, j):
        self.__dict__ = json.loads(j)




if __name__ == '__main__':

    app.run(debug=True, host='0.0.0.0')