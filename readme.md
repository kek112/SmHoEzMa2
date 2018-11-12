## Mobile Computing 2 Projekt SmHoEzMa 2.0
#### Start der Umgebung 
Um das Projekt zu starten ist es notwendig, dass sowohl Docker als auch Docker-Compose installiert sind 
(Docker-Compose ist in Docker unter Windows enthalten). 
Nachdem das Projekt gecloned wurde wird im Verzeichnis, welches die docker-compose.yml beinhaltet, "docker-compose up"
ausgeführt. Empfehlung ist das "docker-compose up -d" ausgeführt wird, damit keine Konsolen Logs ausgegeben werden.


Zum Beenden der Anwendung muss zuerst "Strg+c" gerdückt werden und danach "docker-compose down" in der Konsole eingegeben werden, um das erzeugte Docker Netzwerk und die Images zu beenden. 


#### Docker-Compose
Docker-Compose wird benutzt um das Managment verschiedener Container zu vereinfachen. Hier wird eine yaml Datei erzeugt welche das starten der Container repräsentiert. 
Dies ersetzt das Ausführen eines unübersichtlichen Scripts welches diverse "docker run" Befehle beinhaltet. 
Hier erleichtert das yaml-Format das Lesen der diversen Docker Parameter welche im Hintergrund genauso in "Docker run" übersetzt werden.
