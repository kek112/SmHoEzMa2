from flask import Flask, jsonify, request
from collections import namedtuple
import json
import mysql.connector

app = Flask(__name__)


def _json_object_hook(d): return namedtuple('X', d.keys())(*d.values())


def json2obj(data): return json.loads(data, object_hook=_json_object_hook)


def getMysqlConnection():
    return mysql.connector.connect(user='testing', host='db', port='3306', password='testing', database='test')


class Payload(object):
    def __init__(self, j):
        self.__dict__ = json.loads(j)


@app.route("/")
def hello():
    return "Hello World!"


@app.route('/test', methods=['GET', 'POST'])
def get_tasks():
    received_data = json2obj(request.data)

    # load json file which contains node
    with open('nodes.json', 'r') as myfile:
        data = myfile.read().replace('\n', '')

    loaded_data = data
    saved_data = json2obj(loaded_data)
    json_obj = compare_json_data(received_data, saved_data)

    if json_obj:
        return json.dumps({'success': True}), 200, {'ContentType': 'application/json'}
    else:
        # add json obj to string
        saved_data.append(received_data)
        # save json structure back to file
        return json.dumps({'success': False}), 400, {'ContentType': 'application/json'}

    # return saved_data[0].ip


def compare_json_data(received_data, saved_data):
    counter = 0
    for val in saved_data:
        counter += 1
        if received_data.ip == val.ip:
            return counter

    return False


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')