## Mobile Computing 2 Projekt SmHoEzMa 2.0
#### Start der Umgebung 
Um das Projekt zu starten ist es notwendig, dass sowohl Docker als auch Docker-Compose installiert sind 
(Docker-Compose ist in Docker unter Windows enthalten). 
Nachdem das Projekt gecloned wurde wird im Verzeichnis, welches die docker-compose.yml beinhaltet, "docker-compose up"
ausgeführt. Empfehlung ist das "docker-compose up -d" ausgeführt wird, um diesen als Deamon zu starten und keine Konsolen Logs zu erhalten.


Zum Beenden der Anwendung muss zuerst "Strg+c" gerdückt werden und danach "docker-compose down" in der Konsole eingegeben werden, um das erzeugte Docker Netzwerk und die Images zu beenden. 


#### Docker-Compose
Docker-Compose wird benutzt um das Managment verschiedener Container zu vereinfachen. Hier wird eine yaml Datei erzeugt welche das starten der Container repräsentiert. 
Dies ersetzt das Ausführen eines unübersichtlichen Scripts welches diverse "docker run" Befehle beinhaltet. 
Hier erleichtert das yaml-Format das Lesen der diversen Docker Parameter welche im Hintergrund genauso in "Docker run" übersetzt werden.

Dies erlaubt es die einzelnen Images als Microsservices zu starten was den Vorteil hat, dass sobald Änderungen in einer API
vorgenommen werden nicht alle aktualisiert werden.   

Über Dockerhub wird automatisiert ein Image gebaut von welchem die Dockerfile sich auf Github befindet. Dies bedeutet in der
vorhandenen docker-compose yml wird nur noch das Image gepullt und nicht auf dem ausführenden Client gebaut. 

#### NodeMCU 
Da ein Teil der zu verarbeitenden Daten von einem Mikrocontroller kommen, muss dieser entsprechend aufgebaut und programmiert werden.
Die dazu notwendige Anleitung befindet sind in (Link zur NodeMCU readme). Hier wurden im Moment 2 Sensoren implementiert welche 
die Temperatur sowie das Umgebungslicht messen. Es ist hier ein einfaches noch weitere Seonsoren anzuschließen aber wir haben und auf 
die grundlegenden Sensoren beschränkt welche am ANfang den meisten Sinn machen. 

Hier wäre es auch sinnvoll sobald mehrere Sensoren eingesetzt werden eine PCB Zeichnung vorzunehmen und diese dann Drucken zu lassen.
Somit würden sich Größe und Kosten pro NodeMCU Konfiguration verringern und man könnte diese in einer Vielzahl im Haushalt anbringen.
