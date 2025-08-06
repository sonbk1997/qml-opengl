#include "GuidelinesRenderer.h"
#include "GuidelineItem.h"

GuidelinesRenderer::GuidelinesRenderer()
{
    initializeOpenGLFunctions(); // Ensure GL functions are loaded
}

GuidelinesRenderer::~GuidelinesRenderer()
{

}

void GuidelinesRenderer::synchronize(QQuickFramebufferObject *item)
{
    auto *guidelineItem = static_cast<GuidelineItem *>(item);
    m_pos = guidelineItem->angle();
}

void GuidelinesRenderer::render()
{
//    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    // Setup basic OpenGL state
//    glDisable(GL_DEPTH_TEST);
//    glDisable(GL_CULL_FACE);

//    glViewport(0, 0, 1920, 720); // Adjust to your FBO/viewport size

//    // Setup orthographic projection
//    QMatrix4x4 ortho;
//    ortho.ortho(-1, 1, -1, 1, -1, 1);
//    QOpenGLShaderProgram program;
//    program.addShaderFromSourceCode(QOpenGLShader::Vertex,
//        "attribute vec2 pos;\n"
//        "uniform mat4 matrix;\n"
//        "void main() {\n"
//        "    gl_Position = matrix * vec4(pos, 0.0, 1.0);\n"
//        "}"
//    );
//    program.addShaderFromSourceCode(QOpenGLShader::Fragment,
//        "void main() {\n"
//        "    gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);\n"  // Yellow
//        "}"
//    );
//    program.link();
//    program.bind();
//    program.setUniformValue("matrix", ortho);

//    // Define two points for the line
//    GLfloat vertices[] = {
//        -0.8f, -0.8f,
//         0.8f,  m_pos
//    };

//    GLuint posAttr = program.attributeLocation("pos");
//    program.enableAttributeArray(posAttr);
//    program.setAttributeArray(posAttr, GL_FLOAT, vertices, 2);

//    glDrawArrays(GL_LINES, 0, 2);

//    program.disableAttributeArray(posAttr);
//    program.release();
//    qDebug() << "update";
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
        -0.2f, m_pos
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
    qDebug() << "release";
}
