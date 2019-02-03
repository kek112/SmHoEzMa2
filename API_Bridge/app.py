from flask import Flask, request
import json
import requests
from mysql_helper import mysql_helper


app = Flask(__name__)
ip = '192.168.178.30'
port = '8000'


@app.route('/print_lamp_states', methods=['GET'])
def print_lamp_states():
    lamp_states = get_lamp_states()
    string = '<table>'
    for lamps in lamp_states:
        string += "<tr><th>Lampe "+lamps+'</th></tr>'
        for settings in lamp_states[lamps]['state']:
            string += '<tr><td>'+str(settings)+'</td><td>'+str(lamp_states[lamps]['state'][settings])+'</td></tr>'
    string += '</table>'
    return string


@app.route('/update_lamp_states', methods=['GET'])
def update_lamp_states():
    lamp_states = get_lamp_states()
    for lamp_number in lamp_states:
        settings = lamp_states[lamp_number]['state']
        name = "Lamp "+str(lamp_number)
        write_to_db(settings['hue'], settings['sat'], settings['on'], settings['bri'],
                    name, ip, lamp_number)
    return 'All lamps were inserted or updated!'


def write_to_db(_hue, _saturation, _on, _brightness, _name, _ip_string, _lamp_number):
    hue = str(_hue)
    saturation = str(_saturation)
    on = str(int(_on))
    brightness = str(_brightness)
    ip_string = str(_ip_string)
    lamp_number = str(_lamp_number)
    lamp_exists = is_lamp_in_db(lamp_number)
    sql_data = (_name, ip_string, hue, saturation, on, brightness, lamp_number)
    if lamp_exists:
        sql = """UPDATE Devices \
              SET Name=%s, IP=%s, Hue=%s, Saturation=%s, \
              Switch=%s, Brightness=%s \
              WHERE GeraeteNummer=%s"""
    else:
        sql = """INSERT INTO Devices (Name, IP, Hue, Saturation, Switch, Brightness, GeraeteNummer) 
                VALUES (%s, %s, %s, %s, %s, %s, %s)"""
    mysql_helper.send_query_to_db_no_response(sql, sql_data)


def is_lamp_in_db(lamp_number):
    sql = """SELECT COUNT(*) AS 'num' FROM Devices WHERE GeraeteNummer=%s"""
    result = mysql_helper.send_query_to_db(sql, (lamp_number,))
    return bool(result[0]["num"])


def get_lamp_states():
    r = requests.get('http://'+ip+':'+port+'/api/newdeveloper/lights/').json()
    return r


@app.route('/update_lamp', methods=['POST'])
def update_lamp():
    data = request.get_json()
    payload = json.dumps({'hue': int(data['hue']), 'sat': int(data['sat']), 'on': (False if data['on'] == "0" else True), 'bri': int(data['bri'])})
    r = requests.put('http://'+ip+':'+port+'/api/newdeveloper/lights/'+str(data['num'])+'/state', data=payload)
    #write_to_db(data['hue'], data['sat'], data['on'], data['bri'], data['name'], data['ip'], data['num'])
    return "Status-Code: " + str(r.status_code)


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5001)
