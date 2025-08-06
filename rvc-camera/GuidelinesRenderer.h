#ifndef GUIDELINESRENDERER_H
#define GUIDELINESRENDERER_H

#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>

#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>

class GuidelinesRenderer : public QQuickFramebufferObject::Renderer, protected QOpenGLFunctions {
public:
    GuidelinesRenderer();

    void render() override;
    void synchronize(QQuickFramebufferObject *item) override;

private:
    float m_angle = -1.0f;
};

#endif // GUIDELINESRENDERER_H
