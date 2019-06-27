#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QMainWindow>
#include <QImage>

class QAction;
class QLabel;
class QMenu;
class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    ImageViewer(QWidget *parent = nullptr);
    bool loadFile(const QString &);

private slots:
    void open();
    void saveAs();
    void zoomIn();
    void zoomOut();
    void normalSize();
    void fitToWindow();

private:
    void createActions();
    void createMenus();
    void updateActions();
    void rotateLabelRight();
    void rotateLabelLeft();
    bool saveFile(const QString &fileName);
    void setImage(const QImage &newImage);
    void scaleImage(double factor);

    QImage image;
    QLabel *imageLabel;
    double scaleFactor;

    QAction *rotateLeftAct;
    QAction *rotateRightAct;
    QAction *saveAsAct;
    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *normalSizeAct;
    QAction *fitToWindowAct;
};

#endif
