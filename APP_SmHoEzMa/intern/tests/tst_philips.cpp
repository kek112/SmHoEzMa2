#include "tst_Philips.h"

tst_Philips::tst_Philips(QObject *parent) : QObject(parent)
{

}


void tst_Philips::tst_updateAPICall()
{
       CPhilips *tester = new CPhilips(this,true,5,5,3,"166.166.166.166");
       QString ip = "166.166.166.166";
       int lnumber = 3;

       QVERIFY(tester->getAPICall() ==  QString("http://")+ip+":8000/api/newdeveloper/lights/"+QString::number(lnumber)+"/state");
}

