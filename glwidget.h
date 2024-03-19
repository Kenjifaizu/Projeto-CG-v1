#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QObject>

class line{
    public:
        double x1, y1, x2, y2;
};

class point{
    public:
        double x, y;
};

class polygon{
    public:
        int sides;
        double radius;
        double x, y;
};

class GLWidget : public QGLWidget
{
public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void newPoint(double x, double y);
    void newLine(double x1, double y1, double x2, double y2);
    void newPolygon(double radius, int sides, double x, double y);
    void Zoom(double left, double right, double bottom, double top);
signals:

public slots:
    void alterarLado(int l);
    void alterarRaio(double r);
    void Mudar();
};

#endif // GLWIDGET_H
