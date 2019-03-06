from mysql_helper import mysql_helper
import unittest import mock
import simple

class TestMysqlHelper(unittest.TestCase):
    def setUp(self):
        pass

    @mock.patch('mysql_helper.get_mysql_connection')
    def test_get_mysql_connection(connection):
        connection.reruen_value= "success"
        result = mysql_helper.get_mysql_connection()
        print(result)
        pass


if __name__ == '__main__':
    unittest.main()