#API Dokumentation SmHoEzMa


Setzbare Werte: 
```
Name:           (String)    bis 255 Zeichen
IP:             (String)    gültige Adressen im eigenen Netz (sollte nicht selbständig modifiziert werden)
GeraeteNummer:  (INT)       0-für Sensoren 1-X gibt die Lampe in der Hue Bridge an
Colour:         (INT)       0-65535 Farbwert für Hue Lampen
Saturation:     (INT)       0-254   Sättigung für Hue und Lux Lampen
Brightness:     (INT)       0-254   Sättigung für Hue und Lux Lampen
Switch          (INT)       0/1     Schaltet Hue und Lux Lampen ein/aus
```

GeräteIP:5002/api/alldevices  

Ruft alle verfügbaren Geräte aus der MySQL Db ab.
```
[GET]
[
    {
        "DeviceID": 1, 
        "Name": "test", 
        "IP": "test", 
        "GeraeteNummer": 2, 
        "Heat": 2, 
        "Light": null, 
        "Colour": null, 
        "Saturation": null, 
        "Switch": null, 
        "Brightness": null
    }, 
    {
        "DeviceID": 2, 
        "Name": "test2", 
        "IP": "1.2.3.4", 
        "GeraeteNummer": 2, 
        "Heat": null, 
        "Light": null, 
        "Colour": 32, 
        "Saturation": null, 
        "Switch": null, 
        "Brightness": null}, 
   }
]
```

GeräteIP:5002/api/device  

Ruft Daten zu spezifischen Gerät auf. Sensoren haben dabei immer die GeraeteNummer 0, da diese nur für Philips Hue Bridge
eine Rolle spielt.

```
[POST]
{
    "IP": "10.10.10.10"
    "GeraeteNummer": "1"
}
[GET]
[
    {
        "DeviceID": 1, 
        "Name": "test", 
        "IP": "test", 
        "GeraeteNummer": 2, 
        "Heat": 2, 
        "Light": null, 
        "Colour": null, 
        "Saturation": null, 
        "Switch": null, 
        "Brightness": null
    }
]
```

GeräteIP:5002/api/lamp 

GET Request lässt alle Lampen zurückgeben, der Indikator für eine Lmape ist das sie die GeraeteNummer nicht auf 0 hat.
POST Request setzt die Farbwerte auf die gewünschten Werte.

```
[POST]
{
    "IP":"1.2.3.4",
    "GeraeteNummer":"2",
    "Hue":"50",
    "Saturation":"05",
    "Brightness":"50",
    "Switch":"1"
}
[GET]
[
    {
        "DeviceID": 1, 
        "Name": "test", 
        "IP": "test", 
        "GeraeteNummer": 2, 
        "Heat": null, 
        "Light": null, 
        "Colour": 50, 
        "Saturation": 50, 
        "Switch": null,
        "Brightness": 50
    }, 
    {
        "DeviceID": 2, 
        "Name": "test2", 
        "IP": "1.2.3.4", 
        "GeraeteNummer": 2, 
        "Heat": null, 
        "Light": null, 
        "Colour": 20, 
        "Saturation": 20, 
        "Switch": null, 
        "Brightness": 20
    }, 
    {
        "DeviceID": 4,
        "Name": "test2", 
        "IP": "1.2.3.4", 
        "GeraeteNummer": 7,
        "Heat": null, 
        "Light": null, 
        "Colour": null, 
        "Saturation": null, 
        "Switch": null, 
        "Brightness": null
    }
]
```
GeräteIP:5002/api/name 

Setzt den Namen des Geräates welches mit der IP und GeräteNummer in Verbindung steht

```
[POST]
{
    "IP": "10.10.10.10"
    "GeraeteNummer": "1"
    "Name: "Flur Sensor"
}
```

GeräteIP:5002/api/sensor 

Gibt alle Sensoren zurück, werden durch Geraetenummer 0 gekennzeichnet.

```
[GET]
[
    {
        "DeviceID": 1, 
        "Name": "Sensor2", 
        "IP": "test", 
        "GeraeteNummer": 0, 
        "Heat": 2, 
        "Light": 500, 
        "Colour": null, 
        "Saturation": null, 
        "Switch": null,
        "Brightness": null
    }, 
    {
        "DeviceID": 2, 
        "Name": "Sensor1", 
        "IP": "1.2.3.4", 
        "GeraeteNummer": 0, 
        "Heat": 20, 
        "Light": 1050, 
        "Colour": 20, 
        "Saturation": null, 
        "Switch": null, 
        "Brightness": null
    }, 
    {
        "DeviceID": 3,
        "Name": "Sensor3", 
        "IP": "1.2.3.4", 
        "GeraeteNummer": 0,
        "Heat": 30, 
        "Light": 100, 
        "Colour": null, 
        "Saturation": null, 
        "Switch": null, 
        "Brightness": null
    }
]
```

