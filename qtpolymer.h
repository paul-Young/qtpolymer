#ifndef QTPOLYMER_H
#define QTPOLYMER_H

#include <QMainWindow>
#include "go.h"

namespace Ui {
class qtpolymer;
}

class qtpolymer : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit qtpolymer(QWidget *parent = 0);
    ~qtpolymer();
    
    GO model;

private slots:
    void on_choose_file_clicked(); // get protein
    // get parameter

    // show progress

    // display results

    // start simulation
    void on_start_clicked();

private:
    Ui::qtpolymer *ui;
};

#endif // QTPOLYMER_H
