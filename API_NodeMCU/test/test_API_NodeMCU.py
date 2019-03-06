import unittest
import requests
import json
from mysql_helper import mysql_helper

class TestAPINodeMCU(unittest.TestCase):
'''
Start the /API_NodeMCU/app.py
And run docker-compose -f ./docker-compose-dev.yml up -d

This testcase will setup the database and will clean it afterwards

'''
    def populate_database(self):
        # test daodemcu_routeta for update
        sql="INSERT INTO Devices (Name,IP,GeraeteNummer,Heat,Light) VALUES(%s, %s, %s, %s, %s)"
        data=("Sensor", "192.168.178.123", "0", "12", "70")
        mysql_helper.send_query_to_db_no_response(sql,data)

    def clean_database(self):
        sql="DELETE FROM Devices"
        data=("")
        mysql_helper.send_query_to_db_no_response(sql,data)
        pass

    def test_nodemcu_route(self):
        # populate database and test either if value is updated or is inserted correctly
        # afterward check if the data is correctly in the database

        self.populate_database()
        # test if data comes correctly from database
        payload = {'IP' : '192.168.178.123', 'Temp' : '17', 'Light': '430'}
        url = "http://127.0.0.1:5002/api/nodemcu"
        headers = {'content-type' : 'application/json'}
        r = requests.post(url, data=json.dumps(payload), headers = headers)

        #check if updated
        self.assertEqual(r.status_code, 200)

        # check if inserted
        payload = {'IP' : '10.10.10.10', 'Temp' : '10', 'Light': '500'}
        r = requests.post(url, data=json.dumps(payload), headers = headers)
        data = r.json

        self.assertEqual(r.status_code, 250)

        self.clean_database()

if __name__ == '__main__':
    unittest.main()