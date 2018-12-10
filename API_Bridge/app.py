from flask import Flask, request
import json
import mysql.connector
import requests


app = Flask(__name__)
ip = '192.168.137.173'
port = '8000'

def getMysqlConnection():
    return mysql.connector.connect(user='root', host=ip, port='3306', password='test', database='smhoezma')


class Payload(object):
    def __init__(self, j):
        self.__dict__ = json.loads(j)


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
    mysql_obj = getMysqlConnection()
    cur = mysql_obj.cursor()
    for lamp_number in lamp_states:
        settings = lamp_states[lamp_number]['state']
        name = "Lamp "+str(lamp_number)
        write_to_db(mysql_obj, cur, settings['hue'], settings['sat'], settings['on'], settings['bri'],
                    name, ip, lamp_number)
    mysql_obj.close()
    return 'All lamps were inserted or updated!'


def write_to_db(_mysql_obj, _cur, _hue, _saturation, _on, _brightness, _name, _ip_string, _lamp_number):
    assert _cur is not None
    hue = str(_hue)
    saturation = str(_saturation)
    on = str(int(_on))
    brightness = str(_brightness)
    ip_string = str(_ip_string)
    lamp_number = str(_lamp_number)
    values = "'" + _name + "', '" + ip_string + "', " + lamp_number + ", " + hue + ", " + saturation + ", " + \
             on + ", " + brightness
    lamp_exists = is_lamp_in_db(_cur, lamp_number)
    if lamp_exists:
        sql = "UPDATE Devices " \
              "SET Name='" + _name + "', IP='" + ip_string + "', Hue=" + hue + ", Saturation=" + saturation + \
              ", Switch=" + on + ", Brightness=" + brightness + " " \
              "WHERE GeraeteNummer=" + lamp_number
    else:
        sql = 'INSERT INTO Devices (Name, IP, GeraeteNummer, Hue, Saturation, Switch, Brightness) VALUES (' + values+')'
    print sql
    _cur.execute(sql)
    _mysql_obj.commit()


def is_lamp_in_db(cursor, lamp_number):
    assert cursor is not None
    sql = 'SELECT COUNT(*) FROM Devices WHERE GeraeteNummer='+lamp_number
    cursor.execute(sql)
    result = cursor.fetchone()
    return True if result[0] > 0 else False


def get_lamp_states():
    r = requests.get('http://'+ip+':'+port+'/api/newdeveloper/lights/').json()
    return r


@app.route('/update_lamp', methods=['GET', 'POST'])
def update_lamp():
    # example json:{ "hue": 120, "sat": 78, "on": "true", "bri": 210, "name": Super Lampe, "ip": 192.168.0.87, "num": 5}
    data = request.get_json()
    payload = json.dumps(data)
    r = requests.put('http://'+ip+':'+port+'/api/newdeveloper/lights/1/state', data=payload)
    mysql_obj = getMysqlConnection()
    cur = mysql_obj.cursor()
    write_to_db(mysql_obj, cur, data['hue'], data['sat'], data['on'], data['bri'], data['name'],
                data['ip'], data['num'])
    mysql_obj.close()
    return "Status-Code: "+str(r.status_code)


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')