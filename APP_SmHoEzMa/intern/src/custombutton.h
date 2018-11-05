#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>

/**
 * @brief The CCustomButton class
 * @details This is a simple Button Subclass of QPushbutton to remove the focus border around it when the button is pressed aswell as scale the possible icon
 *          at a single position in the code for all Buttons instead for every single button
 */

class CCustomButton : public QPushButton
{
    Q_OBJECT
public:
    CCustomButton(QWidget *parent = Q_NULLPTR);
    CCustomButton(const QString &text, QWidget *parent = Q_NULLPTR);
    CCustomButton(const QIcon &icon, const QString &text, QWidget *parent = Q_NULLPTR);


private:
    void setupButton();
};

#endif // CUSTOMBUTTON_H
