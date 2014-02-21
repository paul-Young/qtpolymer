#include "qtpolymer.h"
#include "ui_qtpolymer.h"
#include <QFileDialog>
#include "protein.h"
#include "force.h"
#include <iostream>

qtpolymer::qtpolymer(QWidget *parent) : QMainWindow(parent), ui(new Ui::qtpolymer){
    ui->setupUi(this);
}

qtpolymer::~qtpolymer(){
    delete ui;
}

void qtpolymer::on_choose_file_clicked(){
    // open protein file and display protein name
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "/home/paul/Desktop", tr("*.pdb"));

    model.protein.read( fileName.toStdString() );
    model.ref.read( fileName.toStdString() );

    ui->protein_name->setText(QString::fromStdString(model.protein.name));
}

void qtpolymer::on_start_clicked()
{
    ui->E->setText(QString::number( model.protein.size ));
    model.applyForce();
    ui->E->setText(QString::number( model.E ));
    ui->E_bond->setText(QString::number( model.E_bond ));
    ui->E_repel->setText(QString::number( model.E_repel ));
    //model.applyForce();

    //ui->E->setText(QString::number( model.E ));
    //ui->E_bond->setText(QString::number( model.E_bond ));
    //ui->E_repel->setText(QString::number( model.E_repel ));

}
