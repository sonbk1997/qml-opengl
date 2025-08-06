#ifndef GUIDELINEITEM_H
#define GUIDELINEITEM_H

#include <QtQuick/QQuickFramebufferObject>

class GuidelinesRenderer;

class GuidelineItem : public QQuickFramebufferObject
{
    Q_OBJECT
    Q_PROPERTY(float angle READ angle WRITE setAngle NOTIFY steeringAngleChanged)
public:
    Renderer *createRenderer() const;

    float angle() const
    {
        return m_angle;
    }

    void setAngle(float angle)
    {
        if (qFuzzyCompare(m_angle, angle))
            return;
        m_angle = angle;
        emit steeringAngleChanged();
        update();  // Triggers re-render
    }

signals:
    void steeringAngleChanged();

private:
    float m_angle = 0.0f;
};

#endif // GUIDELINEITEM_H
