#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QLabel"
#include "QRadioButton"
#include "QGroupBox"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
void PlusPressed();
void MinusPressed();
void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QLabel* lbl;
    QRadioButton *radio1;
    QRadioButton *radio2;
    QRadioButton *radio3;
    int red = 0, green = 0, blue = 0;
};

#endif // MAINWINDOW_H
