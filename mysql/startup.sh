#!/bin/bash
set -e
service mysql start
mysql < /mysql/startup.sql
service mysql stop