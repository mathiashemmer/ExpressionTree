#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    auto drawFrame = ui->drawFrame->geometry();
    int halfX = drawFrame.width() / 2 + drawFrame.x();
    int halfY = drawFrame.height() / 2 + drawFrame.y();

    QPainter painter(this);

    painter.setPen(QPen(Qt::blue, 2));
    painter.drawLine(halfX, drawFrame.y()+15, halfX+150, halfY);
}

void MainWindow::on_Evaluate_clicked(){
    QString expressionString = ui->Expression->text();
    bool isOk = EvaluateExpressionString(expressionString.toStdString());
    if(isOk)
        ui->label->setText("Expression OK");
    else
        ui->label->setText("DUMB");
}
