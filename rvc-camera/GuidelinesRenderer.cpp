#include "GuidelinesRenderer.h"
#include "GuidelineItem.h"
#include <QOpenGLShaderProgram>

GuidelinesRenderer::GuidelinesRenderer()
{
    initializeOpenGLFunctions();
}

void GuidelinesRenderer::synchronize(QQuickFramebufferObject *item) {
    auto *guideline = static_cast<GuidelineItem *>(item);
    m_angle = guideline->steeringAngle();
}

void GuidelinesRenderer::render()
{
    glViewport(0, 0, 800, 480);
    glClearColor(0, 0, 0, 0);  // Transparent background
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Setup a simple shader program
    QOpenGLShaderProgram program;
    program.addShaderFromSourceCode(QOpenGLShader::Vertex,
        "attribute vec2 pos;\n"
        "void main() {\n"
        "    gl_Position = vec4(pos, 0.0, 1.0);\n"
        "}"
    );
    program.addShaderFromSourceCode(QOpenGLShader::Fragment,
        "void main() {\n"
        "    gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);\n"  // Green
        "}"
    );
    program.link();
    program.bind();

    // Line coordinates (normalized device coords)
    GLfloat vertices[] = {
        -0.8f, -0.8f,
        -0.2f, m_angle
    };
    GLint posAttr = program.attributeLocation("pos");
    program.enableAttributeArray(posAttr);
    program.setAttributeArray(posAttr, GL_FLOAT, vertices, 2);

    glLineWidth(4.0f);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDrawArrays(GL_LINES, 0, 2);

    program.disableAttributeArray(posAttr);
    program.release();
}
