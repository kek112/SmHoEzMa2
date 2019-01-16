from flask import Flask, request
import json
import mysql.connector
from mysql_helper import mysql_helper

app = Flask(__name__)


@app.route("/")
def hello():

    query = """UPDATE Devices SET Name = %s WHERE IP = %s"""
    data = ("testinsert", "1.2.3.4")
    mysql_helper.send_query_to_db_no_response(query, data)
    return "Hello World"


# connect to mysql server inside docker network and get all devices return them as described in readme
# will return whole list of devices
@app.route('/api/alldevices', methods=['GET'])
def return_all_devices():
    query_get_all_devices = "SELECT * FROM Devices"
    sql_data = ""
    try:
        return send_query_to_db(query_get_all_devices, sql_data)
    except IOError:
        return json.dumps({'success': False}), 400, {'ContentType': 'application/json'}

@app.route('/api/device', methods=['GET','POST'])
def return_one_devices():
    data = request.get_json()
    query_specific_device = """SELECT * FROM Devices WHERE IP =%s AND GeraeteNummer = %s """
    sql_data = ( data['IP'], data['GeraeteNummer'])

    try:
        return json.dumps(mysql_helper.send_query_to_db_no_response(query_specific_device, sql_data))
    except IOError:
        return json.dumps({'success': False, 'Errorcode': 'Please enter valid ip'}), 400, {'ContentType': 'application/json'}


# just return all the lamps
@app.route('/api/lamp', methods=['GET','POST'])
def return_lamps():
    data = request.get_json()
    if request.method == 'GET':

        query_get_lamp = """SELECT * FROM Devices WHERE GeraeteNummer != 0"""
        sql_data = ""
        try:
            return json.dumps(mysql_helper.send_query_to_db_no_response(query_get_lamp, sql_data))
        except IOError:
            return json.dumps({'success': False}), 400, {'ContentType': 'application/json'}

    if request.method == 'POST':
        query_lamp = """UPDATE Devices SET  Colour = %s, Saturation = %s, Brightness = %s, Switch = %s WHERE IP = %s AND GeraeteNummer = %s """
        sql_data = (data['Hue'], data['Saturation'], data['Brightness'], data['Switch'], data['IP'], data['GeraeteNummer'])

        try:
            mysql_helper.send_query_to_db_no_response(query_lamp, sql_data)
            #
            # TODO: API CALL FOR BRIDGE API
            #
            return json.dumps({'success': True}), 200, {'ContentType': 'application/json'}
        except IOError:
            return json.dumps({'success': False}), 400, {'ContentType': 'application/json'}


@app.route('/api/name', methods=['POST'])
def set_name():
    data = request.get_json()

    query_update_name = """UPDATE Devices SET Name = %s  WHERE IP = %s  AND GeraeteNummer = %s"""
    sql_data = (data['Name'], data['IP'], data['GeraeteNummer'])

    try:
        mysql_helper.send_query_to_db_no_response(query_update_name, sql_data)
        return json.dumps({'success': True}), 200, {'ContentType': 'application/json'}
    except IOError:
        return json.dumps({'success': False}), 400, {'ContentType': 'application/json'}


# just return all the sensor values
@app.route('/api/sensor', methods=['GET'])
def return_sensors():

    query_get_sensor = """SELECT * FROM Devices WHERE GeraeteNummer = 0 """
    sql_data = ""
    try:
        return json.dumps(mysql_helper.send_query_to_db_no_response(query_get_sensor, sql_data))
    except IOError:
        return json.dumps({'success': False}), 400, {'ContentType': 'application/json'}


def send_query_to_db_no_response(query, data):
    mysql_obj = get_mysql_connection()
    cur = mysql_obj.cursor()
    cur.execute(query, data)
    mysql_obj.close()


def send_query_to_db(query, data):
    mysql_obj = get_mysql_connection()
    cur = mysql_obj.cursor()
    cur.execute(query, data)

    row_headers = [x[0] for x in cur.description]  # this will extract row headers
    rv = cur.fetchall()  # extract data
    mysql_obj.close()  # close connection

    json_data = []
    for result in rv:
        json_data.append(dict(zip(row_headers, result)))
    return json_data


def get_mysql_connection():
    # live
    # return mysql.connector.connect(user='root', host='db', port='3306', password='test', database='smhoezma')
    # martin
    #return mysql.connector.connect(user='root', host='192.168.0.2', port='3306', password='test', database='smhoezma')
    # karl
    return mysql.connector.connect(user='root', host='192.168.178.30', port='3306', password='test', database='smhoezma', autocommit=True)


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')