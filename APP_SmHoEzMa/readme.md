# SmHoEzMa App

Die SmHoEzMa App wurde für MC2 komplett neugeschrieben. Hierfür wurde zwar weiterhin Qt verwendet jedoch wurde anstatt C++, QML verwendet.

Die Quelldateien (QML) des Projekts liegen im Verzeichnis: "intern/qml"

Eine Kompilierte Version der App liegt als Windows Programm und als APK im Verzeichnis: "intern/build"

## QML

QML ist eine Deklarative Programmiersprache die von Qt Entwickelt wurde. Mit dieser ist es möglich schnell un deinfach ein GUI zu erstellen. Die Syntax ist hierbei so aufgebaut das Objekte in einander verschachtelt werden und entweder über Anchor, ein Layout oder statisch platziert. Funktionen in QML werden in Javascript geschrieben.
```QML
Rectangle {
    id: root    //id is the name of the object which can be used to reference it
    Text {
        id: helloWorld
        anchors.fill: parent    //parent references the encabsulating object

        text: "Hello World"
    }
}
```
Der QtCreator behinhaltet zusätzlich einen Designer für QML, dies ermöglicht dem nutzer eine Oberfläche über Drag and Drop zu erstellen.

Eine weitere Besonderheit ist das wenn eine property gesetzt wird aktualisiert sich die property automatisch wenn sich die angegebenen Werte verändern. Dies nennt sich property binding.
```QML
Item {
    property int a: 10
    property int b: a*2 //should the value `a` be changed `b` automatically changes to
}
```
QML Dateien werden zur Laufzeit vom Programm geöffnet und verarbeitet. Daher werden meist die QML Dateien selbst mit dem Programm mitgeliefert. Dies ermöglicht es die Dateien zu ändern ohne das eigentliche Programm zu verändern. Um jedoch zu verhindern das Nutzer die Dateien nicht ändern können kann das Ressourcen System von Qt verwendet um die QML Dateien direkt in die Executable zu speichern.

## QtQuick
QtQuick ist die bibliothek für QML die eine Vielzahl an bereits existierenden UI Elementen beinhaltet. Diese Elemente sind nach dem Material Standard von Google Designed.
Die QtQuick Typen und deren Dokumentation kann unter [QtQuick Documentation](https://doc.qt.io/qt-5/qtquick-qmlmodule.html) gefunden werden

## App


Das Hauptelement der APP ist die `Mainview` und die darin enthaltene `StackView`. Die `StackView` stapelt verschiedene Objekte die über das Push und Pop verfahren hinzugefügt und wieder entfernt werden können. Die Objekte werden in dem `SlideMenu` gelagert und werden beim Druck des entschprechendes Button an die `MainView` übergben. Dies ermöglicht es eine Zentrale Datenstruktur zu halten und diese nicht über zwei Dateien zu verteilen, und dadurch leicht die Menüstruktur und Reihenfolge zu ändern. In dem `SlideMenu` muss ein `MainItem` angegeben werden dammit die `MainView` weiss welches Objekt das Basis Objekt ist. Im Fall der App ist dies die `DeviceListView` die aus einer Liste aus `AccordionElement` besteht. Da es in QML kein `QToolBox` wie in C++ gibt musste eine eigene Alternative programmiert werden. Der einzige Unterschied hierbei ist das bei der eigens programmierte Version mehrere Elemente gleichzeitig geöffnet sein können. Das `AccordionElement` besteht aus einem Titel und einem Körper der Titel besteht nur aus dem Namen des Gerätes und einem Icon. Wenn der Titel gedrückt wird klappt sich das Element zusammen und lässt den Körper verschwinden. Dies ermöglicht es bei vielen Gäreten den Überblick zu behalten. Der Körper enthält die Geräte Einstellungesmöglichkeiten und Daten. Neben der `DeviceListView` Gibt es noch eine `SettingsView` und eine `InfoView` die über das Menü verfügbar sind. Eine zusätzliche Funktion der App ist es das die `MainView` ein Kontextmenü erstellt (oben rechts) falls die momentane View des `StackView` die property `settingsMenu` besitzt und dies eine `Menu` Objekt ist. Auch dies ermöglicht es das Menü der entsprechenden View direkt in der eigenen Datei zu schreiben. Dies hat nicht nur den Vorteil einer Zentralen Datenhaltung sondern auch den Vorteil das die Funktionen die eine View betreffen nicht ausserhalb der betroffenen Datei geschrieben werden müssen.

```QML
//Example Menu in DeviceListView
property var settingsMenu: Menu {
        id: deviceSettingsMenu
        x: mainView.width - deviceSettingsMenu.width //the coordinates needs to be set to these values, this should be done in the MainView
        y: 0
        MenuItem {
            text: "Sleep"
            onClicked: {
                mainStack.currentItem.sleepAllDevices();
            }
        }
        MenuItem {
            text: "Reload"
            onClicked: {
                mainStack.currentItem.loadDevices();
            }
        }
    }
```

## Fazit
Wie die meisten anderen Sprache hat auch QML Vor- und Nachteile. Wie bereits erwähnt lässt sich sehr schnell und einfach eine Oberfläche für Programme erstellen. Zusätzlich kann die Software für verschiedenste Plattformen leicht deployed werden. Im direkten Vergleich mit der C++ Bibliothek ist QML zwar besser geignet für Android Entwicklung da es weitesgehend dem Material Design entspricht jedoch hängt die Funktionalität und Menge der Elmente der C++ Bibliothek hinterher. Auch ist die Dokumentation bei weitem schlechter oder einfach noch nicht so ausgereift  wie die der C++ Bibliothek.