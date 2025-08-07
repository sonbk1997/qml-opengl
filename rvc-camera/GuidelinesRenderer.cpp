#include "GuidelinesRenderer.h"
#include "GuidelineItem.h"
#include <QOpenGLFramebufferObjectFormat>
#include <math.h>

GuidelinesRenderer::GuidelinesRenderer()
{
    initializeOpenGLFunctions();

    if (!m_program) {
        m_program = new QOpenGLShaderProgram();
    }
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex,
        "attribute vec2 pos;\n"
        "attribute vec4 a_color;\n"
        "varying vec4 v_color;\n"
        "void main() {\n"
        "    v_color = a_color;"
        "    gl_Position = vec4(pos, 0.0, 1.0);\n"
        "}"
    );
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment,
        "varying vec4 v_color;\n"
        "void main() {\n"
        "    gl_FragColor = v_color;\n"  // Green
        "}"
    );
    m_program->link();
}

void GuidelinesRenderer::synchronize(QQuickFramebufferObject *item) {
    auto *guideline = static_cast<GuidelineItem *>(item);
    m_angle = guideline->steeringAngle();
}

QOpenGLFramebufferObject *GuidelinesRenderer::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::NoAttachment);
    return new QOpenGLFramebufferObject(size, format);
}

void GuidelinesRenderer::render()
{
    x_left = -0.25 + 0.725*tan(m_angle);
    x_right = 0.25 - 0.725*tan(m_angle);

    glViewport(0, 0, 1920, 720);
    glClearColor(0, 0, 0, 0);  // Transparent background
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    m_program->bind();

    GLint posAttr = m_program->attributeLocation("pos");
    GLint attr = m_program->attributeLocation("a_color");

    // 1 lines
    GLfloat vertices1[] = {-0.25f, 0.95f, x_left, -0.5f};
    m_program->enableAttributeArray(posAttr);
    m_program->setAttributeArray(posAttr, GL_FLOAT, vertices1, 2);
    GLfloat colors1[] = {1.0f, 1.0f, 0.0f, 1.0f,
                         1.0f, 1.0f, 0.0f, 1.0f};
    m_program->enableAttributeArray(attr);
    m_program->setAttributeArray(attr, GL_FLOAT, colors1, 4);
    glLineWidth(4.0f);
    glDrawArrays(GL_LINES, 0, 2);

    // 2 lines
    GLfloat vertices2[] = {0.25f, 0.95f, x_right, -0.5f};
    m_program->enableAttributeArray(posAttr);
    m_program->setAttributeArray(posAttr, GL_FLOAT, vertices2, 2);
    GLfloat colors2[] = {1.0f, 1.0f, 0.0f, 1.0f,
                         1.0f, 1.0f, 0.0f, 1.0f};
     m_program->enableAttributeArray(attr);
     m_program->setAttributeArray(attr, GL_FLOAT, colors2, 4);
     glLineWidth(4.0f);
     glDrawArrays(GL_LINES, 0, 2);

    m_program->disableAttributeArray(posAttr);
    m_program->release();
}
