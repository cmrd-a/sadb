#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newdialog.h"
#include "class.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startup();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startup(){
    /*QVector<officeComputer> ofpc;
    QVector<lectureComputer> lcpc;
    QVector<programmingComputer> prpc;
    QVector<graphicComputer> grpc;
    QVector<server> srvpc;
    QVector<baseComputer> vecpc;
    officeComputer *newpc=new officeComputer;
    vecpc.push_back(newpc);
    baseComputer* mypc = new officeComputer;*/

    setData();
}


void MainWindow::setData(){

}

void MainWindow::on_menuNew_triggered()
{
    NewDialog* objNewDialog = new NewDialog();
    if(objNewDialog->exec()==QDialog::Accepted){
        objNewDialog->addPC();
        QTableWidgetItem *item_00 = new QTableWidgetItem();
        item_00->setText("as");
        ui->table->setItem(0,0,item_00);
    }
}

void MainWindow::on_menuExit_triggered()
{
    QCoreApplication::exit();
}

void MainWindow::on_pushButton_clicked()
{
    int id, cpu, ram;
    QString display, printer, projector, ups, gpu;

    id=ui->lineEditId->text().toInt();
    cpu=ui->lineEditCpu->text().toInt();
    ram=ui->lineEditRam->text().toInt();
    display=ui->lineEditDisplay->text();
    printer=ui->lineEditPrinter->text();
    projector=ui->lineEditProjector->text();
    ups=ui->lineEditUps->text();
    gpu=ui->lineEditGpu->text();



    switch (ui->comboBox->currentIndex()) {
    case 0:{
        baseComputer *ptr = new officeComputer(id,cpu,ram,display,printer);
        data.agregators.push_back(Agregator("agx"));
        factory.createObject(ptr, data.agregators.back());
        data.print();
        break;
    }
    default:
        break;
    }
}

void MainWindow::on_pushButton_2_clicked()
{

}
