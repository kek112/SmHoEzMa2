from flask import Flask
import json
import mysql.connector
import re
import requests

app = Flask(__name__)
ip = '192.168.137.173'
port = '8000'

def getMysqlConnection():
    return mysql.connector.connect(user='root', host=ip, port='3306', password='test', database='smhoezma')


class Payload(object):
    def __init__(self, j):
        self.__dict__ = json.loads(j)


@app.route("/")
def hello():
    return "Hello World!"

@app.route('/print_lamp_states', methods=['GET', 'POST'])
def print_lamp_states():
    lamp_states = get_lamp_states()
    string = '<table>'
    for lamps in lamp_states:
        string += "<tr><th>Lampe "+lamps+'</th></tr>'
        for settings in lamp_states[lamps]['state']:
            string += '<tr><td>'+str(settings)+'</td><td>'+str(lamp_states[lamps]['state'][settings])+'</td></tr>'
    string += '</table>'
    return string

@app.route('/update_lamp_states', methods=['GET', 'POST'])
def update_lamp_states():
    lamp_states = get_lamp_states()
    mysql_obj = getMysqlConnection()
    cur = mysql_obj.cursor()
    for lamp_number in lamp_states:
        settings = re.sub('u\'', '', str(lamp_states[lamp_number]['state']))
        settings = re.sub('\'', '', settings)
        values = "'Lampe "+str(lamp_number)+"', '"+str(ip)+"', '"+str(lamp_number)+"', '"+settings+"'"
        # TODO: UPDATE when device already in db
        sql = 'INSERT INTO Devices (Name, IP, GeraeteNummer, Settings) VALUES ('+values+')'
        print sql
        cur.execute(sql)
        mysql_obj.commit()
    mysql_obj.close()
    return 'All lamps were inserted!'

def get_lamp_states():
    r = requests.get('http://'+ip+':'+port+'/api/newdeveloper/lights/').json()
    return r

@app.route('/update_lamp', methods=['GET', 'POST'])
def update_lamp():
    settings = {"hue": 34, "on": False, "bri": 56}
    payload = json.dumps(settings)
    r = requests.put('http://'+ip+':'+port+'/api/newdeveloper/lights/1/state', data=payload)
    return "Status-Code: "+str(r.status_code)

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')