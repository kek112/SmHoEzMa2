import unittest
from unittest.mock import patch
from mysql_helper import mysql_helper


class TestMySQLHelper(unittest.TestCase):

    def test_getconnection(self):
        result = 10+5
        self.assertEqual(result,15)

    # test if function is called with credentials
    def test_mysql_helper_get_connection(self):
        with patch('mysql.connector.connect') as mocked_mysql_connection:
            mysql_helper.get_mysql_connection()
            mocked_mysql_connection.assert_called()
            mocked_mysql_connection.assert_called_with(user='user', host='192.168.178.30', port='3306', password='test', database='smhoezma', autocommit=True)

    @patch("mysql.connector.connect")
    def test_mysql_helper_get_connection(self, mock_connection):

        query = ("SELECT * FROM Devices")
        data = ("")

        mock_cur = mock_connection.cursor.return_value

        mysql_helper.send_query_to_db_no_response(query,data)
        mock_cur.execute.assert_called_once_with(query,data)



if __name__ == '__main__':
    unittest.main()