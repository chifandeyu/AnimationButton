#ifndef TOTOBUTTON_H
#define TOTOBUTTON_H

#include "button.h"
#include <QLabel>

class totoButton : public Button
{
    Q_OBJECT
public:
    totoButton(QWidget *parent = Q_NULLPTR);
    void setContext(const QString &text);
    void setAlignment(Qt::Alignment alignment);
    QLabel *m_textLab;
};

#endif // TOTOBUTTON_H
