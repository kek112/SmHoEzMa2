#ifndef PINGMODEL_H
#define PINGMODEL_H

#include <QString>
#include <QDebug>
#include <QObject>
#include <QProcess>
#include <QtNetwork>

class CPingModel : public QObject
{
    Q_OBJECT
public:
    explicit CPingModel(QObject *parent = 0);
    ~CPingModel();

    QString CheckForIP();
    bool is_running();
    bool finished();

signals:

public slots:
    void verifyStatus();
    void readResult();

private:
    QProcess *ping;
    bool running;
};

#endif // PINGMODEL_H
