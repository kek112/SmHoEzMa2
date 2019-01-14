#include "philipsLux.h"



CPhilipsLux::CPhilipsLux(QObject *parent)
{

}

CPhilipsLux::CPhilipsLux(QObject *parent,
                           bool _swtichedOn,
                           int _brightness,
                           int _saturation,
                           int _lampnumber,
                           QString _ip):CPhilips(parent,
                                                  _swtichedOn,
                                                  _brightness,
                                                  _saturation,
                                                  _lampnumber,
                                                  _ip)
{

}
