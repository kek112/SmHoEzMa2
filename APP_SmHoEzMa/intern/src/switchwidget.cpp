#include "switchwidget.h"

CSwitchWidget::CSwitchWidget(QWidget *parent)
    : QAbstractButton(parent)
    , _height(16)
    , _opacity(0.000)
    , _switch(false)
    , _margin(3)
    , _thumb("#d5d5d5")
    , _anim(new QPropertyAnimation(this, "offset", this))
{
    setOffset(0);
    setBrush(QColor("#009688"));
    setCheckable(true);
}

CSwitchWidget::CSwitchWidget(const QBrush &brush, QWidget *parent)
    : QAbstractButton(parent)
    , _height(16)
    , _switch(false)
    , _opacity(0.000)
    , _margin(3)
    , _thumb("#d5d5d5")
    , _anim(new QPropertyAnimation(this, "offset", this))
{
    setOffset(0);
    setBrush(brush);
    setCheckable(true);
}

void CSwitchWidget::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.setPen(Qt::NoPen);

    if(isEnabled())
    {
        p.setBrush(_switch ? brush() : Qt::black);
        p.setOpacity(_switch ? 0.5 : 0.38);
        p.setRenderHint(QPainter::Antialiasing, true);
    }
    else
    {
        p.setBrush(Qt::black);
        p.setOpacity(0.12);
    }

    p.drawRoundedRect(QRect(_margin, _margin, width() - 2 * _margin, height() - 2 * _margin), height() / 2, height() / 2); //Bar under the Round switch
                                                      //2* da oben und unten das margin abgezogen werden muss

    if(isEnabled())
    {
        p.setBrush(_thumb);
        p.setOpacity(1.0);
    }
    else
    {
        p.setBrush(QColor("#BDBDBD"));
        p.setOpacity(1.0);
    }

    p.drawEllipse(QRectF(offset(), 0, height(), height())); //round Switch

}

void CSwitchWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() & Qt::LeftButton)
    {
        _switch = !_switch ;
        _thumb = _switch ? _brush : QBrush("#d5d5d5");

        if (_switch)
        {
            _anim->setStartValue(0);
            _anim->setEndValue(width() - height());
            _anim->setDuration(120);
            _anim->start();
        }
        else
        {
            _anim->setStartValue(width() - height());
            _anim->setEndValue(0);
            _anim->setDuration(120);
            _anim->start();
        }
    }
    QAbstractButton::mouseReleaseEvent(e);
}

void CSwitchWidget::enterEvent(QEvent *e)
{
    setCursor(Qt::PointingHandCursor);
    QAbstractButton::enterEvent(e);
}

QBrush CSwitchWidget::brush() const
{
    return _brush;
}

void CSwitchWidget::setBrush(const QBrush &brsh)
{
    _brush = brsh;
}

int CSwitchWidget::offset() const
{
    return _x;
}

void CSwitchWidget::setOffset(int o)
{
    _x = o;
    update();
}

void CSwitchWidget::setChecked(bool _checked)
{
    if(_checked != _switch)
    {
        _switch = _checked;
        _thumb = _switch ? _brush : QBrush("#d5d5d5");

        if (_switch)
        {
            _anim->setStartValue(0);
            _anim->setEndValue(width() - height());
            _anim->setDuration(120);
            _anim->start();
        }
        else
        {
            _anim->setStartValue(width() - height());
            _anim->setEndValue(0);
            _anim->setDuration(120);
            _anim->start();
        }
        QAbstractButton::setChecked(_checked);
    }
}

bool CSwitchWidget::isChecked()
{
    return QAbstractButton::isChecked();
}
