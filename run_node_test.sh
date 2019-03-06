#!/usr/bin/env bash

docker-compose -f ./docker-compose-dev.yml up -d

python ./API_NodeMCU/app.py

python ./API_NodeMCU/test/test_API_NodeMCU.py


docker-compose -f ./docker-compose-dev.yml down

pkill -f ./API_NodeMCU/app.py
pkill -f ./API_NodeMCU/test/test_API_NodeMCU.py