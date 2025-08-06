#ifndef GUIDELINERENDERER_H
#define GUIDELINERENDERER_H

#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>

#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>

class GuidelineRenderer : public QQuickFramebufferObject::Renderer, protected QOpenGLFunctions {
public:
    GuidelineRenderer();
    void render() override;
    void synchronize(QQuickFramebufferObject *item) override;
private:
    float m_angle = -1.0f;
};

#endif // GUIDELINERENDERER_H
