#include "unit.h"
#include "ui_unit.h"

Unit::Unit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Unit)
{
    ui->setupUi(this);
}

Unit::~Unit()
{
    delete ui;
}

