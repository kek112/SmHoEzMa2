import unittest
import requests
import json
from mysql_helper import mysql_helper

class TestAPISmHoEzMa(unittest.TestCase):
    '''
    Start the /API_SmHoEzMa/app.py
    Start the docker-compose -f ./docker-compose-dev.yml up
    Start the /API_Bridge/app.py
    Start the Hue-Emulator-v0.8
    '''

    '''
    Init functions
    '''
    def populate_database(self):
        # test data for update
        sql="INSERT INTO Devices (Name,IP,GeraeteNummer,Hue, Saturation, Switch, Brightness)  \
            VALUES(%s, %s, %s, %s, %s, %s, %s)"

        data=("Philips", "192.168.178.123", "0", "255", "100", "0", "100")
        mysql_helper.send_query_to_db_no_response(sql,data)

    def clean_database(self):
        sql="DELETE FROM Devices"
        data=("")
        mysql_helper.send_query_to_db_no_response(sql,data)
        pass

    def test_all_devices(self):
        self.populate_database()

        url = "http://127.0.0.1:5003/api/alldevices"
        r = requests.get(url)

        self.assertEqual(r.status_code,200)
        self.clean_database()
        pass

    def test_device(self):
        self.populate_database()
        payload = {'IP': '192.168.178.123', 'GeraeteNummer': '0'}
        url = "http://127.0.0.1:5003/api/device"
        headers = {'content-type' : 'application/json'}
        r = requests.post(url, data=json.dumps(payload), headers = headers)
        data = r.json

        self.assertEqual(r.status_code,200)
        self.clean_database()
        pass

    def test_lamp(self):
        self.populate_database()
        sql="INSERT INTO Devices (Name,IP,GeraeteNummer,Hue, Saturation, Switch, Brightness)  \
            VALUES(%s, %s, %s, %s, %s, %s, %s)"

        data=("Philips", "192.168.178.123", "1", "255", "100", "0", "100")
        mysql_helper.send_query_to_db_no_response(sql,data)

        url = "http://127.0.0.1:5003/api/lamp"
        r = requests.get(url)
        check_data = r.json()


        assert_data={"DeviceID": 133, "Name": "Philips", "IP": "192.168.178.123", "GeraeteNummer": 1, "Heat": 'null', "Light": 'null', "Hue": 255, "Saturation": 100, "Switch": 0, "Brightness": 100}

        self.assertEqual(check_data[0]['Name'],assert_data['Name'])
        self.assertEqual(check_data[0]['IP'],assert_data['IP'])
        self.assertEqual(check_data[0]['GeraeteNummer'],assert_data['GeraeteNummer'])
        self.assertEqual(check_data[0]['Hue'],assert_data['Hue'])

        self.clean_database()
        pass

    def test_name(self):
        self.populate_database()

        payload = {'IP': '192.168.178.123', 'Name': 'Testcheck', 'GeraeteNummer':'0'}
        url = "http://127.0.0.1:5003/api/name"
        headers = {'content-type' : 'application/json'}
        r = requests.post(url, data=json.dumps(payload), headers = headers)
        check_data = r.json()


        self.assertEqual(r.status_code,200)

        sql="Select * FROM Devices WHERE Name = 'Testcheck'"
        data = ()

        response = (mysql_helper.send_query_to_db(sql,data))

        self.assertEqual(response[0]['Name'],'Testcheck')

        self.clean_database()
        pass

    def test_sensor(self):
        self.populate_database()

        url = "http://127.0.0.1:5003/api/sensor"
        r = requests.get(url)
        check_data = r.json()

        assert_data={"DeviceID": 133, "Name": "Philips", "IP": "192.168.178.123", "GeraeteNummer": 0, "Heat": 'null', "Light": 'null', "Hue": 255, "Saturation": 100, "Switch": 0, "Brightness": 100}

        self.assertEqual(check_data[0]['Name'],assert_data['Name'])
        self.assertEqual(check_data[0]['IP'],assert_data['IP'])
        self.assertEqual(check_data[0]['GeraeteNummer'],assert_data['GeraeteNummer'])
        self.assertEqual(check_data[0]['Hue'],assert_data['Hue'])

        self.clean_database()
        pass

if __name__ == '__main__':
    unittest.main()