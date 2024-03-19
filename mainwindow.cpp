#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

int fun=0;
double camLeft=-1, camRight=1, camBottom=-1, camTop=1, prevHor=0, prevVer=0, prevZoom=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*void MainWindow::on_polygonsides_valueChanged(int arg1)
{
    if(arg1>2){
        this->ui->widget->lados=arg1;
        this->ui->widget->updateGL();
    }
}


void MainWindow::on_polygonradius_valueChanged(double arg1)
{
    if(arg1>0){
        this->ui->widget->raio=arg1;
        this->ui->widget->updateGL();
    }
}*/


void MainWindow::on_addline_released()
{
    this->ui->widget->newLine(this->ui->linex1->value() ,
                              this->ui->liney1->value() ,
                              this->ui->linex2->value() ,
                              this->ui->liney2->value());
}


void MainWindow::on_addpoint_released()
{
    this->ui->widget->newPoint(this->ui->pointx->value() ,
                               this->ui->pointy->value());
}


void MainWindow::on_addpolygon_released()
{
    if(this->ui->polygonradius->value() > 0 && this->ui->polygonsides->value() > 2){
        this->ui->widget->newPolygon(this->ui->polygonradius->value() ,
                                     this->ui->polygonsides->value() ,
                                     this->ui->polygonx->value() ,
                                     this->ui->polygony->value());
    }
}


void MainWindow::on_fun_clicked()
{

}


void MainWindow::on_fun_released()
{
    if(fun==10){
        QMessageBox about;
        about.setIconPixmap(QPixmap(":/calor/qcalor.png"));
        about.exec();
    }
    fun++;
}


void MainWindow::on_zoom_valueChanged(double arg1)
{
    camLeft-=prevZoom;
    camRight+=prevZoom;
    camBottom-=prevZoom;
    camTop+=prevZoom;
    prevZoom=arg1;
    camLeft+=arg1;
    camRight-=arg1;
    camBottom+=arg1;
    camTop-=arg1;
    //if(this->ui->zoom->value()>0){
        this->ui->widget->Zoom(camLeft ,
                               camRight ,
                               camBottom ,
                               camTop);
    //}
}

void MainWindow::on_horcam_valueChanged(double arg1)
{
    camLeft-=prevHor;
    camRight-=prevHor;
    prevHor=arg1;
    camLeft+=arg1;
    camRight+=arg1;
    //if(this->ui->zoom->value()>0){
        this->ui->widget->Zoom(camLeft ,
                               camRight ,
                               camBottom ,
                               camTop);
    //}
}


void MainWindow::on_vercam_valueChanged(double arg1)
{
    camBottom+=prevVer;
    camTop+=prevVer;
    prevVer=arg1;
    camBottom-=arg1;
    camTop-=arg1;
    //if(this->ui->zoom->value()>0){
        this->ui->widget->Zoom(camLeft ,
                               camRight ,
                               camBottom ,
                               camTop);
    //}
}

