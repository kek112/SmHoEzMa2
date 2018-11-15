from flask import Flask, jsonify, request
from collections import namedtuple
import json
import mysql.connector

app = Flask(__name__)


@app.route("/")
def hello():
    return "Hello World!"


@app.route('/test', methods=['GET', 'POST'])
def get_tasks():
    return


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')