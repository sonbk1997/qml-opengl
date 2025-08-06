#include "GuidelineItem.h"
#include "GuidelineRenderer.h"

QQuickFramebufferObject::Renderer *GuidelineItem::createRenderer() const {
    return new GuidelineRenderer();
}

void GuidelineItem::setSteeringAngle(float angle) {
    if (qFuzzyCompare(m_angle, angle))
        return;
    m_angle = angle;
    update();  // Triggers re-render
}
