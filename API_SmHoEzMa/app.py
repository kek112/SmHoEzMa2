from flask import Flask, request
import json
from mysql_helper import mysql_helper

app = Flask(__name__)
api_url = 'http://api_bridge:5001/update_lamp'

@app.route("/")
def hello():

    query = """UPDATE Devices SET Name = %s WHERE IP = %s"""
    data = ("testinsert", "test")
    mysql_helper.send_query_to_db_no_response(query, data)
    return "Hello World"


# connect to mysql server inside docker network and get all devices return them as described in readme
# will return whole list of devices
@app.route('/api/alldevices', methods=['GET'])
def return_all_devices():
    query_get_all_devices = """SELECT * FROM Devices"""
    sql_data = ""
    try:
        return json.dumps(mysql_helper.send_query_to_db(query_get_all_devices, sql_data))
    except IOError:
        return json.dumps({'success': False}), 400, {'ContentType': 'application/json'}


@app.route('/api/device', methods=['GET', 'POST'])
def return_one_devices():
    data = request.get_json()
    query_specific_device = """SELECT * FROM Devices WHERE IP = '%s' AND GeraeteNummer = %s """
    sql_data = (data['IP'], data['GeraeteNummer'])

    try:
        return json.dumps(mysql_helper.send_query_to_db_no_response(query_specific_device, sql_data))
    except IOError:
        return json.dumps({'success': False, 'Errorcode': 'Please enter valid ip'}), 400, {'ContentType': 'application/json'}


# just return all the lamps
@app.route('/api/lamp', methods=['GET', 'POST'])
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

            create_row_data = {'hue': data['heu'],'sat':data['sat'],'on':data['on'],'bri':data['bri'],'name':data['name'],'num':data['GeraeteNummer']}
            r=request.post(api_url,data=create_row_data)

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


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')