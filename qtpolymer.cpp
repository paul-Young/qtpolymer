#include "qtpolymer.h"
#include "ui_qtpolymer.h"
#include <QFileDialog>
#include "protein.h"

qtpolymer::qtpolymer(QWidget *parent) : QMainWindow(parent), ui(new Ui::qtpolymer){
    ui->setupUi(this);
}

qtpolymer::~qtpolymer(){
    delete ui;
}

void qtpolymer::on_choose_file_clicked(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Opoen file"), "/home/paul/Desktop", tr("*.pdb"));
    Protein myoVI( fileName.toStdString() );
    qtpolymer::sim.protein = &myoVI;

    ui->protein_name->setText(QString::fromStdString(myoVI.name));
}
