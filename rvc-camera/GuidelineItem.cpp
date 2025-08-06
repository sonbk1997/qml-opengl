#include "GuidelineItem.h"
#include "GuidelinesRenderer.h"

QQuickFramebufferObject::Renderer *GuidelineItem::createRenderer() const {
    return new GuidelinesRenderer();
}

float GuidelineItem::steeringAngle() const
{
    return m_angle;
}

void GuidelineItem::setSteeringAngle(float angle) {
    if (qFuzzyCompare(m_angle, angle))
        return;
    m_angle = angle;
    update();  // Triggers re-render
}
