#ifndef GUIDELINEITEM_H
#define GUIDELINEITEM_H

#include <QQuickFramebufferObject>

class GuidelineItem : public QQuickFramebufferObject {
    Q_OBJECT
    Q_PROPERTY(float steeringAngle READ steeringAngle WRITE setSteeringAngle NOTIFY steeringAngleChanged)

public:
    float steeringAngle() const { return m_angle; }
    void setSteeringAngle(float angle);

    Renderer *createRenderer() const override;

signals:
    void steeringAngleChanged();

private:
    float m_angle = 0.0f;
};
#endif // GUIDELINEITEM_H
