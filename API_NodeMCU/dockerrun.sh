#!/usr/bin/env bash
docker build -t nodeapi .

docker run -d -p 5000:5000 nodeapi

