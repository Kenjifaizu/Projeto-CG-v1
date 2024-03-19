#include "glwidget.h"
#include <cmath>

int nPoints=0, nLines=0, nPolygons=0, i=0;
std::vector<point> Points;
std::vector<line> Lines;
std::vector<polygon> Polygons;

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    setFormat(QGL::DoubleBuffer | QGL::DepthBuffer);
}

void GLWidget::initializeGL(){
}

void GLWidget::paintGL(){
       (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

       glTranslated(0.0, 0.0, 0.0);

      glClear(GL_COLOR_BUFFER_BIT);
      glColor3f(0.5,0.5,0.5);
      glBegin(GL_LINES);
      glVertex3f(-1.0 ,0.0, 0.0);
      glVertex3f(1.0, 0.0, 0.0);
      glEnd();

      glColor3f(0.5,0.5,0.5);
      glBegin(GL_LINES);
      glVertex3f(0.0 ,-1.0, 0.0);
      glVertex3f(0.0, 1.0, 0.0);
      glEnd();

      if(!Lines.empty()){
        for(i = 0; i != nLines; i++){
            glColor3f(0.5,0.5,0.5);
            glBegin(GL_LINES);
            glVertex3f(Lines[i].x1 , Lines[i].y1, 0.0);
            glVertex3f(Lines[i].x2 , Lines[i].y2, 0.0);
            glEnd();
        }
      }

      if(!Points.empty()){
          for(i = 0; i != nPoints; i++){
            glColor3f(0.5,0.5,0.5);
            glPointSize(5);
            glBegin(GL_POINTS);
            glVertex3f(Points[i].x , Points[i].y, 0.0);
            glEnd();
          }
      }

      if(!Polygons.empty()){
          for(i = 0; i != nPolygons; i++){
            glColor3f(0,0.7f,0.7f); // Define a cor de desenho: vermelho
            glBegin(GL_POLYGON);
            for (int j = 0; j < Polygons[i].sides; ++j)
              glVertex2f(((Polygons[i].radius)*cos(j*2*3.14159265/(Polygons[i].sides)))+Polygons[i].x,
                         ((Polygons[i].radius)*sin(j*2*3.14159265/(Polygons[i].sides)))+Polygons[i].y);
            glEnd();
          }
      }

      /*double j=-1;
      for(i=-1000;i!=1000;j+=0.001, i++){
          glColor3f(0.5,0.5,0.5);
          glPointSize(5);
          glBegin(GL_POINTS);
          glVertex3f(j , sin(20*j), 0.0);
          glEnd();
      }*/
}

void GLWidget::resizeGL(int width, int height){

    glViewport(0, 0, width, height);
}

void GLWidget::newPoint(double x, double y){
    nPoints++;
    Points.resize(nPoints);
    Points[nPoints-1].x = x;
    Points[nPoints-1].y = y;
    updateGL();
}

void GLWidget::newLine(double x1, double y1, double x2, double y2){
    nLines++;
    Lines.resize(nLines);
    Lines[nLines-1].x1 = x1;
    Lines[nLines-1].x2 = x2;
    Lines[nLines-1].y1 = y1;
    Lines[nLines-1].y2 = y2;
    updateGL();
}

void GLWidget::newPolygon(double radius, int sides, double x, double y){
    nPolygons++;
    Polygons.resize(nPolygons);
    Polygons[nPolygons-1].radius = radius;
    Polygons[nPolygons-1].sides = sides;
    Polygons[nPolygons-1].x = x;
    Polygons[nPolygons-1].y = y;
    updateGL();
}

void GLWidget::Zoom(double left, double right, double bottom, double top){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(left, right, bottom, top, 1, -1);
    updateGL();
}
