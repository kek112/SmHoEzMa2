## Mobile Computing 2 Projekt SmHoEzMa 2.0

Dieses Programm ist im Rahmen der Lehrveranstaltung Mobile Computing 2 entstanden. Es soll ein Beispiel dafür geben 
wie eine grundlegendeine Microservice Struktur aufgebaut werden kann. Dafür werden unter anderen Docker, Python sowie QT
/QML genutzt. 

#### Vorraussetzungen
In diesem Projekt werden folgende Tools genutzt: 

- Python/Flask
    - mysql-connector-python
- QT
    - QML 
- Arduino
    - C++
    - Hardware-Sensoren
- Hue-Emulator

Der Hue Emulator ist im Verzeichnis der API-Bridge enthalten und simuliert eine Philips Hue mit diversen Lampen.
  


#### Start der Umgebung 
Um das Projekt zu starten ist es notwendig, dass sowohl Docker als auch Docker-Compose installiert sind.
Damit die Microservice Struktur geladen wird, führt man `docker-compose up` im Verzeichnis aus in dem sich die 
docker-compose.yml befindet. Oder wenn nur die Datenbank für Testzwecke hochgefahren werden soll so kann 
`docker-compose -f docker-compose-dev.yml up` ausgeführt werden. Bitte auf korrekte Adressen achten

##### Einfacher Start
Wer nicht die Hardware bestitzt oder jedes Modul hochfahren möchte hat folgende Möglichkeiten: 

Grundsätzlich sollte immer die MySQL Datenbank gestartet werden über `docker-compose -f docker-compose-dev.yml up` 
Danach können die einzelnen Flask APIs gestartet werden und ausgeführt werden. 
Für die API_Bridge wird noch der Hue Emulator benötigt. Diesen einfach starten und auf auf den Button starten drücken.
Für die NodeMCU API wird eigentlich eine NodeMCu mit dem notwendigen Aufbau, welcher in der readme der NodeMCU zu sehen
ist, benötigt wird. 


#### API Dokumentationen

Dies soll einer Übersicht bieten welche Links zu allen Dokumentationen für jedes EInzelteil aus welchem diese Projekt 
besteht

- [API_Bridge](/API_Bridge/readme.md)
- [API_NodeMCU](/API_NodeMCU/readme.md)
- [API_SmHoEzMa](/API_SmHoEzMa/readme.md)
- [APP_SmoHoEzMa](/APP_SmHoEzMa/readme.md)
- [NodeMCU Code](/NodeMCU_Code/readme.md)


