#API Dokumentation NodeMCU


Diese API ist nur für die Kommunikation zwischen der NodeMCU und der SmHoEzMa Bridge. 
Es werden die periodischen Requests der NodeMCU verarbeitet und die DAten entsprechend in der DB aktualisiert.
Hier geschieht nichts anderes als, das die die NodeMCU permanent ihre aktuellen Sensordaten an die API schickt damit 
diese in die Datenbank eingetragen wird. 
Es wird auch gleichzeitig geprüft ob das Gerät breits in der DB eingetragen ist. 

Sollten weitere Seonsoren in die NodeMCU eingebaut werden so müssten hier das SQl Statement angepasst werden.

GeräteIP:5002/api/updatenodemcu  
```
[POST] 
JSON
{
    "Ip":"10.10.10.10",
    "Temp":"30",
    "Light":"1005"
}
```

Dieser Microservice ist abhängig vom MYSQL Container. 