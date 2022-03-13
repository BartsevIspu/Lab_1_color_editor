#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLabel"
#include "QRadioButton"
#include "QGroupBox"
#include "QGridLayout"
#include "QPushButton"
#include "QKeyEvent"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Lab_1"));
    resize(350, 170);

    lbl = new QLabel("Text color");
    lbl->setStyleSheet(QString("font-size: %1px; font-weight: bold;").arg(32));
    lbl->setAlignment(Qt::AlignBottom);

    QPushButton* plus = new QPushButton("+");
    plus->setStyleSheet(QString("font-size: 28px; font-weight: bold;"));
    plus->setFixedSize(65,65);
    QPushButton* minus = new QPushButton("-");
    minus->setStyleSheet(QString("font-size: 28px; font-weight: bold;"));
    minus->setFixedSize(65,65);

    QGroupBox *groupBox = new QGroupBox(tr("The color to be changed"));
    groupBox->setAlignment(Qt::AlignCenter);

    radio1 = new QRadioButton(tr("Red"));
    radio2 = new QRadioButton(tr("Green"));
    radio3 = new QRadioButton(tr("Blue"));

    radio1->setStyleSheet(QString("color: red"));
    radio2->setStyleSheet(QString("color: green"));
    radio3->setStyleSheet(QString("color: blue"));

    QVBoxLayout *vlayout = new QVBoxLayout();
    vlayout->addWidget(radio1);
    vlayout->addWidget(radio2);
    vlayout->addWidget(radio3);
    groupBox->setLayout(vlayout);

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(groupBox, 1, 2);
    grid->addWidget(lbl, 2, 2, Qt::AlignHCenter);
    grid->addWidget(plus, 1, 3);
    grid->addWidget(minus, 1, 1);
    setLayout(grid);

    QObject::connect(plus, SIGNAL(released()), this, SLOT(PlusPressed()));
    QObject::connect(minus, SIGNAL(released()), this, SLOT(MinusPressed()));

    QWidget* wdg = new QWidget();
    wdg->setLayout(grid);
    this->setCentralWidget(wdg);
}

void MainWindow::PlusPressed()
{
    if (radio1->isChecked())
    {
        red += 51;
        if (red > 255)
            red = 255;
    }
    if (radio2->isChecked())
    {
        green += 51;
        if (green > 255)
            green = 255;
    }
    if (radio3->isChecked())
    {
        blue += 51;
        if (blue > 255)
            blue = 255;
    }
    QString stl = "color: rgb(%1,%2,%3); font-size: 32px; font-weight: bold;";
    QString stl2 = stl.arg(red).arg(green).arg(blue);
    lbl->setStyleSheet(stl2);
}

void MainWindow::MinusPressed()
{
    if (radio1->isChecked())
    {
        red -= 51;
        if (red < 0)
            red = 0;
    }
    if (radio2->isChecked())
    {
        green -= 51;
        if (green < 0)
            green = 0;
    }
    if (radio3->isChecked())
    {
        blue -= 51;
        if (blue < 0)
            blue = 0;
    }
    QString stl = "color: rgb(%1,%2,%3); font-size: 32px; font-weight: bold;";
    QString stl2 = stl.arg(red).arg(green).arg(blue);
    lbl->setStyleSheet(stl2);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //QString oldText = label1->text();
    int key=event->key();//event->key() - целочисленный код клавиши
    //QString str = QString(QChar(key));

    if (key==Qt::Key_Plus)
        PlusPressed();
    if (key==Qt::Key_Minus)
        MinusPressed();
}

MainWindow::~MainWindow()
{
    delete ui;
}

