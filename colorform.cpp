#include "colorform.h"
#include "ui_colorform.h"
#include "dialog.h"

ColorForm::ColorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorForm)
{
    ui->setupUi(this);
    setMaximumSize(size());
    setMinimumSize(size());
    ui->horizontalSlider_R->setMaximum(255);
    ui->horizontalSlider_2_G->setMaximum(255);
    ui->horizontalSlider_3_B->setMaximum(255);
}

ColorForm::~ColorForm()
{
    delete ui;
}

void ColorForm::on_horizontalSlider_R_valueChanged(int value)
{
    emit R_Changed(value);
}

void ColorForm::on_horizontalSlider_2_G_valueChanged(int value)
{
    emit G_Changed(value);
}

void ColorForm::on_horizontalSlider_3_B_valueChanged(int value)
{
    emit B_Changed(value);
}

void ColorForm::eviado_elementoColorRGB(QColor Col_RGB)
{
//    QColor col;
//    col.setRgb(0,0,0);
    ui->label_4_RGB->setPalette(QPalette(Col_RGB));
    ui->label_4_RGB->setAutoFillBackground(true);
}

//void ColorForm::eviado_elementoColorGUARDADO(QColor Col_GUARDADO)
//{
//    ui->label_4_RGB->setPalette(QPalette(Col_GUARDADO));
//    ui->label_4_RGB->setAutoFillBackground(true);
//}

