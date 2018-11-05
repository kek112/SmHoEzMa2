#ifndef SWITCHWIDGET_H
#define SWITCHWIDGET_H

#include <QtWidgets>

/**
 * @brief The CSwitchWidget class
 * @details Subclasses the QAbstractButton class to create a Android like switch
 */

class CSwitchWidget : public QAbstractButton
{
    Q_OBJECT
    //needed for QPropertyAnimation
    Q_PROPERTY(int offset READ offset WRITE setOffset)
    Q_PROPERTY(QBrush brush READ brush WRITE setBrush)

public:
    CSwitchWidget(QWidget* parent = nullptr);
    CSwitchWidget(const QBrush& brush, QWidget* parent = nullptr);

    QBrush brush() const;
    void setBrush(const QBrush &brsh);

    int offset() const;
    void setOffset(int o);

    void setChecked(bool _checked);
    bool isChecked();

protected:
    void paintEvent(QPaintEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void enterEvent(QEvent*) override;

private:
    bool _switch;
    qreal _opacity;
    int _x, _height, _margin;
    QBrush _thumb, _track, _brush;
    QPropertyAnimation *_anim = nullptr;
};

#endif // SWITCHWIDGET_H
