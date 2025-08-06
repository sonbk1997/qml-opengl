#ifndef GUIDELINESRENDERER_H
#define GUIDELINESRENDERER_H

#include <QtGui/qvector3d.h>
#include <QtGui/qmatrix4x4.h>
#include <QtGui/qopenglshaderprogram.h>
#include <QtGui/qopenglfunctions.h>
#include <QtGui/QOpenGLFramebufferObject>
#include <QtQuick/QQuickWindow>
#include <qsgsimpletexturenode.h>

#include <QTime>
#include <QVector>
#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>

#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>

class GuidelinesRenderer : public QQuickFramebufferObject::Renderer, public QOpenGLFunctions
{
public:
    GuidelinesRenderer();
    ~GuidelinesRenderer();

    void synchronize(QQuickFramebufferObject *item) override;

    void render() override;
private:
    GLfloat m_pos = 0.3;

    QOpenGLShaderProgram program1;
    int vertexAttr1;
    int normalAttr1;
    int matrixUniform1;
};

#endif // GUIDELINESRENDERER_H
