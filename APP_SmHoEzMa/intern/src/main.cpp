#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

//This is the entry point of the application even for a qml application
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickStyle::setStyle("Material");

    //The QQmlApplicationEngine loads the "MainView" and shows it
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/MainView.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    //Eventloop
    return app.exec();
}
