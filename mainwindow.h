#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGLWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    /*void on_polygonsides_valueChanged(int arg1);

    void on_polygonradius_valueChanged(double arg1);*/

    void on_addline_released();

    void on_addpoint_released();

    void on_addpolygon_released();

    void on_fun_clicked();

    void on_fun_released();

    void on_zoom_valueChanged(double arg1);

    void on_horcam_valueChanged(double arg1);

    void on_vercam_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
