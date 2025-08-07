#ifndef GUIDELINESRENDERER_H
#define GUIDELINESRENDERER_H

#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>
#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>

class GuidelinesRenderer : public QQuickFramebufferObject::Renderer, protected QOpenGLFunctions {
public:
    GuidelinesRenderer();

    void render() override;
    void synchronize(QQuickFramebufferObject *item) override;
    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;

private:
    float m_angle = 0.0f;
    float x_left = -0.25;
    float x_right = 0.25;
    QOpenGLShaderProgram *m_program;
    GLuint m_posAttr;
    GLuint m_colAttr;
};

#endif // GUIDELINESRENDERER_H
