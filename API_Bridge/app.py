from flask import Flask
import requests
import json
import mysql.connector

app = Flask(__name__)
ip = '192.168.137.173'
port = '8000'

def getMysqlConnection():
    return mysql.connector.connect(user='testing', host='db', port='3306', password='testing', database='test')


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

"""@app.route('/update_lamp_states', methods=['GET', 'POST'])
def update_lamp_states():
    lamp_states = get_lamp_states()
    mysql_obj = getMysqlConnection()
    cur = mysql_obj.cursor()
    for lamps in lamp_states:
        for settings in lamp_states[lamps]['state']:
            cur.execute('INSERT INTO '+lamp_states[lamps]['state'][settings])
    mysql_obj.close()
    return 'OK'
"""
def get_lamp_states():
    r = requests.get('http://'+ip+':'+port+'/api/newdeveloper/lights/').json()
    return r #.text #content

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')