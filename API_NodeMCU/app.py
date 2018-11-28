from flask import Flask, request
import json
import mysql.connector


app = Flask(__name__)


@app.route("/")
def hello():
    return "Hello World!"


@app.route('/api/nodemcu', methods=['GET', 'POST'])
def set_values():
    data = request.get_json()
    query_check_existence = """SELECT * FROM Devices WHERE IP = %s"""
    sql_data =(data["IP"])
    query_result = send_query_to_db(query_check_existence, sql_data)

    # if result is not empty than update the value
    if query_result:
        query_update_values = """UPDATE Devices SET Heat = %s, Light = %s"""
        sql_data = (data['Temp'], data['Light'])
        send_query_to_db_no_response(query_update_values,sql_data)
    # if the result is empty insert new value
    else:
        query_insert_values = """INSERT INTO Devices (Name,IP,GeraeteNummer,Heat,Light) VALUES(%s, %s, %s, %s, %s)"""
        sql_data = ("Sensor", data['IP'], "0", data['Temp'], data['Light'])
        send_query_to_db(query_insert_values,sql_data)

    return


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
    return json.dumps(json_data)



# important dont ferget to close the connction through obj.close() at the end of your function
def get_mysql_connection():
    #live
    #return mysql.connector.connect(user='root', host='db', port='3306', password='test', database='smhoezma')
    #dev
    return mysql.connector.connect(user='root', host='192.168.178.30', port='3306', password='test', database='smhoezma')


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')