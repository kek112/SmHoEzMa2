from flask import Flask, request
import json
import mysql.connector
from mysql_helper import mysql_helper


app = Flask(__name__)


@app.route("/")
def hello():
    return "Hello World!"


@app.route('/api/nodemcu', methods=['GET', 'POST'])
def set_values():
    data = request.get_json()
    query_check_existence = """SELECT * FROM Devices WHERE IP = %s"""
    sql_data =(data["IP"])
    query_result = json.dumps(mysql_helper.send_query_to_db_no_response(query_check_existence, sql_data))

    # if result is not empty than update the value
    if query_result:
        query_update_values = """UPDATE Devices SET Heat = %s, Light = %s"""
        sql_data = (data['Temp'], data['Light'])
        json.dumps(mysql_helper.send_query_to_db_no_response(query_update_values, sql_data))
    # if the result is empty insert new value
    else:
        query_insert_values = """INSERT INTO Devices (Name,IP,GeraeteNummer,Heat,Light) VALUES(%s, %s, %s, %s, %s)"""
        sql_data = ("Sensor", data['IP'], "0", data['Temp'], data['Light'])
        json.dumps(mysql_helper.send_query_to_db_no_response(query_insert_values, sql_data))
    return


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')