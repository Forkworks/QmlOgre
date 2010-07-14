#ifndef OGREWIDGET_H
#define OGREWIDGET_H

#include <QGLWidget>

#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)
#define OGRE_PLUGIN_DIR STRINGIFY(OGRE_PLUGIN_VAR)

namespace Ogre {
class Root;
class Camera;
class SceneManager;
class RenderWindow;
class Viewport;
class RenderTarget;
}
class DeclarativeViewTexture;

class OgreWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit OgreWidget(QWidget *parent = 0);
    virtual ~OgreWidget();

    Ogre::Root *ogreRoot() const
    { return m_root; }
    Ogre::Camera *ogreCamera() const
    { return m_camera; }
    Ogre::SceneManager *ogreSceneManager() const
    { return m_sceneManager; }
    Ogre::RenderWindow *ogreRenderWindow() const
    { return m_renderWindow; }
    Ogre::Viewport *ogreViewport() const
    { return m_viewport; }

protected:
    void initOgre();
    void timerEvent(QTimerEvent *);

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:
    Ogre::Root *m_root;
    Ogre::Camera *m_camera;
    Ogre::SceneManager *m_sceneManager;
    Ogre::RenderWindow *m_renderWindow;
    Ogre::Viewport *m_viewport;

    DeclarativeViewTexture *m_QmlUI;
};

#endif // OGREWIDGET_H