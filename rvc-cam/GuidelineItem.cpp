#include "GuidelineItem.h"
#include "GuidelinesRenderer.h"

QQuickFramebufferObject::Renderer *GuidelineItem::createRenderer() const
{
    return new GuidelinesRenderer();
}
