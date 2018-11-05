#ifndef PhilipsCOLOR_H
#define PhilipsCOLOR_H
#include "Philips.h"

class CPhilipsColor : public CPhilips
{
public:
    CPhilipsColor(QObject *parent = 0);
    CPhilipsColor(QObject *parent,
                   bool     _swtichedOn,
                   int      _brightness,
                   int      _saturation,
                   int      _lampnumber,
                   QString  _ip,
                   int      _hueValue);


public:
    void setHueValue(int _huevalue);

private:
    int            m_hueValue;
};

#endif // PhilipsCOLOR_H
