## Mobile Computing 2 Projekt SmHoEzMa 2.0
#### Start der Umgebung 
Um das Projekt zu starten ist es notwendig das zum einen Docker sowie Docker-Compose. 
Nach dem das Projekt gecloned wurde wird im Verzeichnis welches die docker-compose.yml beinhaltet "docker-compose up"
ausgeführt. Empfehlung ist das "docker-compose up -d" ausgeführt wird, damit keine Konsolen Logs ausgeben wird.


Zum beenden der Anwendung kann zum einen "Strg+c" sowie danach "docker-compose down" um das erzeugte Docker Netzwerk und die Images zu beenden. 


#### Docker-Compose
Docker-Compose wird benutzt um das Managment verschiedener Container zu vereinfachen. Hier wird eine yaml Datei erzeugt welche das starten der Container repräsentiert. 
Dies ersetzt das ausführen eines unübersichtlichen scripts welches diverse "docker run" Befehle beinhaltet. 
Hier erleichtert es zum einen das yaml Format das Lesen der diversen Docker Parameter welche im Hintergrund genauso in "Docker run" übersetzt werden.
