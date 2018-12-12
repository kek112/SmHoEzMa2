import json
import mysql.connector


def send_query_to_db_no_response(query, data):
    mysql_obj = get_mysql_connection()
    cur = mysql_obj.cursor()
    cur.execute(query, data)
    mysql_obj.commit()
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
    return mysql.connector.connect(user='root', host='192.168.0.2', port='3306', password='test', database='smhoezma')
    # karl
    #return mysql.connector.connect(user='root', host='192.168.178.30', port='3306', password='test', database='smhoezma', autocommit=True)
