#include "pingmodel.h"


///
/// erster versuch um netzwerk nach geräten abzusuchen
/// fehlschlag da dieser ansatz ca 20min gedauert hat
/// wird nun hart eingespeichert, vlt im nächsten release
///
///

CPingModel::CPingModel(QObject *parent) :
    QObject(parent), running(false)
{
    ping = new QProcess(this);
    connect(ping, SIGNAL(started()), this, SLOT(verifyStatus()));
    connect(ping, SIGNAL(finished(int)), this, SLOT(readResult()));
//    ping->setProcessChannelMode(QProcess::MergedChannels);
}


CPingModel::~CPingModel()
{
}

QString CPingModel::CheckForIP()
{
    QString Temp    = "";

    QString network = "192.168.178.";

    if(ping)
    {
            for(int i=0;i<255;i++)
            {
                QString command = "ping";
                QStringList args;
                args << "-w" <<  "1" <<  network+QString::number(i);
                ping->start(command, args);
                ping->waitForStarted(7000);
                running = true;
                ping->waitForFinished(5000);

                Temp += ping->readLine();

            }
    }
    return Temp;
}

void CPingModel::verifyStatus()
{
    if(ping->isReadable())
    {
        qDebug() << "read on ...";
        connect(ping, SIGNAL(readyRead()), this, SLOT(readResult()));
        if(ping->canReadLine()){
            qDebug() << "LINE read on ...";
        }
    }else{
        qDebug() << "not able to read ...";
    }
}

void CPingModel::readResult()
{
    qDebug() << "Acabou!!!";
    running = false;
    qDebug() << "LENDO: " << ping->readLine();
}
bool CPingModel::is_running()
{
    return running;
}

bool CPingModel::finished()
{
    return ping->atEnd();
}
