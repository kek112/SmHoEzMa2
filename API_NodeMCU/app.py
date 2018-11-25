from flask import Flask, jsonify, request
from collections import namedtuple
import json
import mysql.connector

app = Flask(__name__)


@app.route("/")
def hello():
    return "Hello World!"


@app.route('/api/sendvalues', methods=['GET', 'POST'])
def get_tasks():
    data = request.get_json()
    query_result = send_query_to_db("SELECT * FROM `Devices` WHERE IP = '" + data['IP'] + "'")
    #if result is not empty than update the value
    if query_result:
        send_query_to_db("UPDATE 'devices' SET Heat = '" + data['Temp'] + "', Light = '" + data['Light'] + "'")
    #if the result is empty insert new value
    else:
        send_query_to_db("INSERT INTO `Devices` (Name,IP,GeraeteNummer,Heat,Light) VALUES('Sensor_','" + data['IP'] + "','" + data['Temp'] + "','0','" + data['Light'] + "')")

    return


def send_query_to_db(query):
    mysql_obj = get_mysql_connection()
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
def get_mysql_connection():
    #live
    #return mysql.connector.connect(user='root', host='db', port='3306', password='test', database='smhoezma')
    #dev
    return mysql.connector.connect(user='root', host='192.168.178.30', port='3306', password='test', database='smhoezma')


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')