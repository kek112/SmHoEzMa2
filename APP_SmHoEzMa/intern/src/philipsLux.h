#ifndef PhilipsLUX_H
#define PhilipsLUX_H
#include "Philips.h"

class CPhilipsLux : public CPhilips
{
public:
    CPhilipsLux(QObject *parent = 0);
    CPhilipsLux(QObject *parent,
                   bool     _swtichedOn,
                   int      _brightness,
                   int      _saturation,
                   int      _lampnumber,
                   QString  _ip);
};


#endif // PhilipsLUX_H
