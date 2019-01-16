from flask import Flask, request
import json
from mysql_helper import mysql_helper


app = Flask(__name__)


@app.route("/api", methods=['GET', 'POST'])
def hello():
    query = """UPDATE Devices SET Name = %s WHERE IP = %s"""
    data = ("testinsert_node", "1.2.3.4")
    mysql_helper.send_query_to_db_no_response(query, data)
    return "Hello World"

@app.route('/api/nodemcu', methods=['GET', 'POST'])
def set_values():
    data = request.get_json()
    query_check_existence = ("SELECT * FROM Devices WHERE IP = '%(IP)s'" % {'IP': data['IP']})
    sql_data = ("")

    query_result = mysql_helper.send_query_to_db(query_check_existence, sql_data)

    # if result is not empty than update the value
    if query_result.__len__() == 0:
        query_insert_values = "INSERT INTO Devices (Name,IP,GeraeteNummer,Heat,Light) VALUES(%s, %s, %s, %s, %s)"
        sql_data = ("Sensor", data['IP'], "0", data['Temp'], data['Light'])
        mysql_helper.send_query_to_db_no_response(query_insert_values, sql_data)
        return json.dumps({'success': True}), 250, {'ContentType': 'application/json'}
    # if the result is empty insert new value
    else:
        query_update_values = """UPDATE Devices SET Heat = %s, Light = %s WHERE IP = %s"""
        sql_data = (data['Temp'], data['Light'], data['IP'])
        mysql_helper.send_query_to_db_no_response(query_update_values, sql_data)
        return json.dumps({'success': True}), 200, {'ContentType': 'application/json'}
    return


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')
