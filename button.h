#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QTimer>

class Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = nullptr);
    void setAnimationColor(QColor color);
    void setAnimationEnable(bool enable);

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

signals:

public slots:
    void proRadiusChange();

private:
    bool m_bPressed;
    QPoint m_pPoint;
    int m_r;
    QTimer m_timer;
    bool m_animationEnable;
    QColor m_animationColor;
    bool m_isFinish; //结束绘制
};

#endif // BUTTON_H
