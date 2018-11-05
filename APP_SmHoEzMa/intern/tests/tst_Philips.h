#ifndef TST_Philips_H
#define TST_Philips_H

#include "../src/philips.h"
#include <QtTest/QtTest>
#include <QObject>

///
/// The job of a remote API client is to issue certain calls - no more, no less. Therefore, its test should verify that it issues those calls - no more, no less.
/// Sure, if the API provider changes the semantics of their responses,
/// then your system will fail in production. But that isn't your client class's fault;
/// it's something that can only be caught in integration tests.
/// By relying on code not under your control you have given up the ability to verify correctness via internal testing - it was a trade-off, and this is the price.
/// That said, testing a class that consists only of delegations to another class may be low-priority,
/// because there is comparatively little risk of complex errors.
/// But that goes for any class that consists only of uniform one-liners,
/// it has nothing to do with calling out into another vendor's code.
/// ///
class tst_Philips : public QObject
{
    Q_OBJECT
public:
    explicit tst_Philips(QObject *parent = nullptr);

signals:

private slots:

    void        tst_updateAPICall   ();

};

#endif // TST_Philips_H
