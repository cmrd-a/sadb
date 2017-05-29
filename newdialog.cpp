#include "newdialog.h"
#include "ui_newdialog.h"
#include "class.h"

#include "room.h"
#include "data.h"
#include "factory.h"
#include "mainwindow.h"

NewDialog::NewDialog(QWidget *parent) : QDialog(parent), ui(new Ui::NewDialog) {
    ui->setupUi(this);
}
NewDialog::NewDialog(QWidget *parent, Data *d_ptr, Factory *f_ptr) : QDialog(parent), ui(new Ui::NewDialog) {
    ui->setupUi(this);
    this->d_ptr=d_ptr;
    this->f_ptr=f_ptr;
    upd_room();
}

NewDialog::~NewDialog() { delete ui; }

void NewDialog::upd_room(){
    ui->roomCB->clear();
    for(unsigned i=0; i<d_ptr->room.size(); i++){
        ui->roomCB->addItem(d_ptr->room.at(i).room);
    }
}

void NewDialog::DisableAll() {
    ui->lineEditId->clear();
    ui->lineEditCpu->clear();
    ui->lineEditRam->clear();
    ui->lineEditDisplay->clear();
    ui->lineEditPrinter->clear();
    ui->lineEditProjector->clear();
    ui->lineEditUps->clear();
    ui->lineEditGpu->clear();
    ui->label_5->setEnabled(false);
    ui->lineEditDisplay->setEnabled(false);
    ui->label_6->setEnabled(false);
    ui->lineEditPrinter->setEnabled(false);
    ui->label_7->setEnabled(false);
    ui->lineEditProjector->setEnabled(false);
    ui->label_8->setEnabled(false);
    ui->lineEditUps->setEnabled(false);
    ui->label_9->setEnabled(false);
    ui->lineEditGpu->setEnabled(false);
}

void NewDialog::on_typeBox_currentIndexChanged(int index)
{


}

void NewDialog::on_buttonBox_accepted()
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

    switch (ui->typeCB->currentIndex()) {
    case 0:{
        baseComputer *ptr = new officeComputer(id,cpu,ram,display,printer);
        f_ptr->createObject(ptr, d_ptr->room.at(ui->roomCB->currentIndex()));
        break;
    }
    /*case 1:{
        baseComputer *ptr = new lectureComputer(id,cpu,ram,display,projector);
        f_ptr->createObject(ptr, d_ptr->room.back());
        break;
    }*/
    default:
        break;
    }
}

void NewDialog::on_typeCB_currentIndexChanged(int index)
{
    switch (index) {
    case 0: {
        DisableAll();
        ui->label_5->setEnabled(true);
        ui->lineEditDisplay->setEnabled(true);
        ui->label_6->setEnabled(true);
        ui->lineEditPrinter->setEnabled(true);
        break;
    }
    case 1: {
        DisableAll();
        ui->label_5->setEnabled(true);
        ui->lineEditDisplay->setEnabled(true);
        ui->label_7->setEnabled(true);
        ui->lineEditProjector->setEnabled(true);
        break;
    }
    case 2: {
        DisableAll();
        ui->label_5->setEnabled(true);
        ui->lineEditDisplay->setEnabled(true);
        break;
    }
    case 3: {
        DisableAll();
        ui->label_5->setEnabled(true);
        ui->lineEditDisplay->setEnabled(true);
        ui->label_9->setEnabled(true);
        ui->lineEditGpu->setEnabled(true);
        break;
    }
    case 4: {
        DisableAll();
        ui->label_8->setEnabled(true);
        ui->lineEditUps->setEnabled(true);
        break;
    }
    }

}
