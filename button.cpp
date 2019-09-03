#include "button.h"
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QDebug>

Button::Button(QWidget *parent)
    : QPushButton (parent)
    , m_r(0)
    , m_animationEnable(true)
    , m_animationColor(QColor("#d0e2f6"))
    , m_isFinish(true)
{
    m_timer.setInterval(10);
    m_timer.setTimerType(Qt::PreciseTimer);
    connect(&m_timer, &QTimer::timeout, this, &Button::proRadiusChange);
    setFocusPolicy(Qt::NoFocus);
}

void Button::setAnimationColor(QColor color)
{
    m_animationColor = color;
}

void Button::setAnimationEnable(bool enable)
{
    m_animationEnable = enable;
}

void Button::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);
    if (!m_isFinish)
    {
        QPainter painter(this);
        painter.setRenderHints(QPainter::SmoothPixmapTransform);
        painter.setPen(m_animationColor);
        painter.setBrush(m_animationColor);
        painter.drawEllipse(m_pPoint, m_r, m_r);
    //		qWarning() << "-------paintEvent" << m_r;
    }
}

void Button::mousePressEvent(QMouseEvent *event)
{
    QPushButton::mousePressEvent(event);
    if (m_animationEnable &&  event->button() == Qt::LeftButton)
    {
        m_bPressed = true;
        m_isFinish = false;
        m_pPoint = event->pos();
        m_timer.start();
        m_r = 0;
        update();
    }
}

void Button::mouseReleaseEvent(QMouseEvent *event)
{
    QPushButton::mouseReleaseEvent(event);
    m_bPressed = false;
    update();
    if (event && event->button() == Qt::LeftButton)
    {
        QPoint globalPos = mapToGlobal(QPoint(0, 0));
        QRect globalRect = QRect(globalPos, this->size());
        //当鼠标释放的时候 鼠标不在按钮的区域里面
        if (!globalRect.contains(event->globalPos()))
        {
            m_timer.stop();
        }
    }
    if (m_r > this->height() && m_r > this->width())
    {
//		qWarning() << "-------mouseReleaseEvent" << m_r;
        m_isFinish = true;
    }
}

void Button::mouseMoveEvent(QMouseEvent *e)
{
    QPushButton::mouseMoveEvent(e);
}

void Button::proRadiusChange()
{
    //绘制半径超过可见区域
    if (m_r > this->height() && m_r > this->width())
    {
        if(!m_bPressed)
        {
            //释放了鼠标时
            m_r = 0;
//			qWarning() << "-------radiusChange" << m_r;
            m_isFinish = true;
        }
        m_timer.stop();
    }
    m_r += 8;
    update();
}
