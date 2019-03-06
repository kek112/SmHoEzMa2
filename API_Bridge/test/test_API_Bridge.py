import unittest
import requests
import json
from mysql_helper import mysql_helper

class TestAPBridgeAPI(unittest.TestCase):
    '''
    Start the /API_Bridge/app.py
    Start the docker-compose -f ./docker-compose-dev.yml up
    Start the Hue-Emulator-v0.8
    '''


    '''
    Init functions
    '''
    def clean_database(self):
        sql="DELETE FROM Devices"
        data=("")
        mysql_helper.send_query_to_db_no_response(sql,data)
        pass

    '''
    Test functions
    '''
    def test_update_lamp_states(self):
        '''
        IMPORTANT: Hue emulator has to e started
        set Lights in the Emulator and get the states from it and insert it into the Database
        this test checks if the standards lamps are set and set in the mysql
        '''

        self.clean_database()

        url = "http://127.0.0.1:5001/update_lamp_states"
        headers = {'content-type' : 'application/json'}
        r = requests.get(url)

        self.assertEqual(r.status_code, 200)

        # check if inserted
        sql="Select * FROM Devices"
        data=("")
        response = mysql_helper.send_query_to_db(sql,data)

        dict=[
            {'DeviceID': 38, 'Name': 'Lamp 1', 'IP': '127.0.0.1', 'GeraeteNummer': 1, 'Heat': None, 'Light': None, 'Hue': 4444, 'Saturation': 254, 'Switch': 1, 'Brightness': 254},
            {'DeviceID': 39, 'Name': 'Lamp 2', 'IP': '127.0.0.1', 'GeraeteNummer': 2, 'Heat': None, 'Light': None, 'Hue': 23536, 'Saturation': 144, 'Switch': 1, 'Brightness': 254},
            {'DeviceID': 40, 'Name': 'Lamp 3', 'IP': '127.0.0.1', 'GeraeteNummer': 3, 'Heat': None, 'Light': None, 'Hue': 65136, 'Saturation': 254, 'Switch': 1, 'Brightness': 254}]

        self.assertEqual(r.status_code, 200)


        self.assertEqual(dict[0]['Hue'], response[0]['Hue'])
        self.assertEqual(dict[0]['Saturation'],response[0]['Saturation'])
        self.assertEqual(dict[0]['Brightness'],response[0]['Brightness'])

        self.assertEqual(dict[1]['Hue'],response[1]['Hue'])
        self.assertEqual(dict[1]['Saturation'],response[1]['Saturation'])
        self.assertEqual(dict[1]['Brightness'],response[1]['Brightness'])


        self.assertEqual(dict[2]['Hue'],response[2]['Hue'])
        self.assertEqual(dict[2]['Saturation'],response[2]['Saturation'])
        self.assertEqual(dict[2]['Brightness'],response[2]['Brightness'])
        self.clean_database()

    def test_upddate_lamp(self):

        payload = {'num':'1','hue' : '10', 'sat' : '10', 'on': '1','bri':'10'}
        url = "http://127.0.0.1:5001/update_lamp"
        headers = {'content-type' : 'application/json'}
        r = requests.post(url, data=json.dumps(payload), headers = headers)
        data = r.json

        self.assertEqual(r.status_code, 200)

        sql="Select * FROM Devices"
        data=("")
        response = mysql_helper.send_query_to_db(sql,data)

        dict= [
            {'DeviceID': 41, 'Name': 'Lamp 1', 'IP': '127.0.0.1', 'GeraeteNummer': 1, 'Heat': None, 'Light': None, 'Hue': 10, 'Saturation': 10, 'Switch': 1, 'Brightness': 10},
            {'DeviceID': 42, 'Name': 'Lamp 2', 'IP': '127.0.0.1', 'GeraeteNummer': 2, 'Heat': None, 'Light': None, 'Hue': 23536, 'Saturation': 144, 'Switch': 1, 'Brightness': 254},
            {'DeviceID': 43, 'Name': 'Lamp 3', 'IP': '127.0.0.1', 'GeraeteNummer': 3, 'Heat': None, 'Light': None, 'Hue': 65136, 'Saturation': 254, 'Switch': 1, 'Brightness': 254}]

        self.assertEqual(dict[0]['Hue'],10)
        self.assertEqual(dict[0]['Saturation'],10)
        self.assertEqual(dict[0]['Brightness'],10)

        #revert to original state
        payload = {'num':'1','hue' : '4444', 'sat' : '254', 'on': '1','bri':'254'}
        url = "http://127.0.0.1:5001/update_lamp"
        headers = {'content-type' : 'application/json'}
        r = requests.post(url, data=json.dumps(payload), headers = headers)
        data = r.json

        self.clean_database()
        pass

if __name__ == '__main__':
    unittest.main()