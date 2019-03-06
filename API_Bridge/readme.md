#API Dokumentation Bridge

Funktionen welche aufgerufen werden damit die Phillips Hue Bridge angestuert wird

Beispiel json Format für update_lamp:  
{ "hue": "120", "sat": "78", "on": "0", "bri": "210", "name": "Super Lampe", "ip": "192.168.0.87", "num": "5"}  
http://192.168.0.2:5000/update_lamp  
http://192.168.0.2:5000/print_lamp_states  
http://192.168.0.2:8000/api/newdeveloper/lights/1/state