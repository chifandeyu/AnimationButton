#include "totobutton.h"
#include <QBoxLayout>

totoButton::totoButton(QWidget *parent)
    : Button(parent)
{
    QHBoxLayout *p = new QHBoxLayout(this);
    p->setSpacing(0);
    p->setMargin(0);
    m_textLab = new QLabel;
    m_textLab->setStyleSheet("background-color: transparent;");
    p->addWidget(m_textLab);
}

void totoButton::setContext(const QString &text)
{
    m_textLab->setText(text);
}

void totoButton::setAlignment(Qt::Alignment alignment)
{
    m_textLab->setAlignment(alignment);
}
