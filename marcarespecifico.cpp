#include "marcarespecifico.h"
#include "ui_marcarespecifico.h"
#include <QFileDialog>
#include <QDebug>
#include <ctime>
#include <QListView>
#include <QMenu>
#include <QComboBox>
//#include <dialog.h>

QPair<int,int>conteo_maximo2;

MarcarEspecifico::MarcarEspecifico(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MarcarEspecifico)
{
    ui->setupUi(this);

    conteo_maximo2.first=0;
    ui->comboBox_2_VERCICULO_SALMO->setDisabled(true);
    ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(true);
   inicializando_variables_verciculos();

    for(int i = 0; i < 150; i++){
        if(i==0)
            ui->comboBox_CAPITULO_SALMOS->addItem(/*"item " + */'\0');

        ui->comboBox_CAPITULO_SALMOS->addItem(/*"item " + */QString::number(i+1));
    }
    for (int i = 0; i <31; ++i) {
        if(i==0)
            ui->comboBox_3_CAPITULO_PROVERBIOS->addItem(/*"item " + */'\0');

        ui->comboBox_3_CAPITULO_PROVERBIOS->addItem(/*"item " + */QString::number(i+1));
    }
    crear_action();

    setMinimumSize(560,560);
    resize(560,560);//160
    setMaximumSize(560,560);
}

MarcarEspecifico::~MarcarEspecifico()
{
    delete ui;
}

void MarcarEspecifico::inicializando_variables_verciculos()
{
    V_P_P_C<<6<<12<<8<<8<<12<<10<<17<<9<<20<<18<<7<<8<<6<<7<<5<<11<<15<<50<<14<<9<<13<<31<<6<<10<<22<<12<<14<<9
          <<11<<12<<24<<11<<22<<22<<28<<12<<40<<22<<13<<17<<13<<11<<5<<26<<17<<11<<9<<14
         <<20<<23<<19<<9<<6<<7<<23<<13<<11<<11<<17<<12<<8<<12<<11<<10<<13<<20<<7<<35
        <<36<<5<<24<<20<<28<<23<<10<<12<<20<<72<<13<<19<<16<<8<<18<<12<<13<<17<<7<<18
       <<52<<17<<16<<15<<5<<23<<11<<13<<12<<9<<9<<5<<8<<28<<22<<35<<45<<48<<43<<13
      <<31<<7<<10<<10<<9<<7<<18<<19<<2<<29<<176<<7<<8<<9<<4<<8<<6<<6<<5<<5<<8<<8
     <<3<<18<<3<<3<<21<<26<<9<<8<<24<<13<<10<<7<<12<<15<<20<<10<<20<<14<<9<<6;

    V_P_P_P<<33<<22<<35<<27<<23<<35<<27<<36<<18<<32
          <<31<<28<<25<<35<<33<<33<<28<<24<<29<<30<<31
         <<29<<35<<34<<28<<28<<27<<28<<27<<33<<31;
}


void MarcarEspecifico::on_comboBox_CAPITULO_SALMOS_currentIndexChanged(int index)
{
    switch(index){
    case 1:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i <V_P_P_C[0]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 2:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i <V_P_P_C[1]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 3:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[2]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 4:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[3]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 5:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[4]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 6:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[6]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 7:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[6]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 8:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[7]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 9:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[8]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 10:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[9]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 11:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[10]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 12:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[11]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 13:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[12]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 14:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[13]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 15:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[4]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 16:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[15]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 17:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[16]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 18:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[17]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 19:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[18]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 20:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[19]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 21:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[20]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 22:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[21]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 23:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[22]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 24:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[23]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 25:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[24]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 26:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[25]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 27:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[26]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 28:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[27]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 29:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[28]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 30:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[29]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 31:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[30]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 32:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[31]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 33:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[32]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 34:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[33]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 35:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[34]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 36:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[35]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 37:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[36]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 38:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[37]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 39:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[38]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 40:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[39]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 41:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[40]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 42:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[41]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 43:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[42]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 44:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[43]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 45:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[44]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 46:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[45]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 47:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[46]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 48:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[47]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 49:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[48]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 50:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[49]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 51:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[50]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 52:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[51]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 53:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[52]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 54:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[53]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 55:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[54]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 56:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[55]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 57:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[56]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 58:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[57]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 59:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[58]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 60:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[59]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 61:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[60]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 62:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[61]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 63:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[62]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 64:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[63]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 65:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[64]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 66:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[65]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 67:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[66]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 68:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[67]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 69:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[68]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 70:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[69]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 71:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[70]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 72:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[71]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 73:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[72]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 74:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[73]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 75:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[74]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 76:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[75]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 77:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[76]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 78:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[77]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 79:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[78]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 80:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[79]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 81:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[80]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 82:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[81]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 83:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[82]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 84:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[83]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 85:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[84]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 86:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[85]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 87:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[86]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 88:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[87]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 89:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[88]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 90:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[89]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 91:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[90]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 92:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[91]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 93:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[92]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 94:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[93]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 95:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[94]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 96:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[95]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 97:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[96]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 98:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[97]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 99:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[98]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 100:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[99]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 101:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[100]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 102:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[101]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 103:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[102]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 104:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[103]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 105:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[104]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 106:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[105]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 107:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[106]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 108:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[107]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 109:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[108]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 110:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[109]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 111:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[110]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 112:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[111]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 113:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[112]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 114:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[113]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 115:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[114]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 116:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[115]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 117:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[116]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 118:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[117]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 119:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[118]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 120:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[119]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 121:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[120]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 122:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[121]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 123:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[122]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 124:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[123]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 125:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[124]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 126:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[125]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 127:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[126]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 128:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[127]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 129:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[128]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 130:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[129]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 131:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[130]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 132:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[131]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 133:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[132]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 134:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[133]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 135:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[134]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 136:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[135]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 137:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[136]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 138:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[137]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 139:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[138]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 140:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[139]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 141:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[140]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 142:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[141]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 143:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[142]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 144:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[143]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 145:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[144]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 146:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[145]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 147:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[146]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 148:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[147]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 149:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[148]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    case 150:
        ui->comboBox_2_VERCICULO_SALMO->clear();
        for (int i = 0; i < V_P_P_C[149]; ++i) {
            if(i==0){
                ui->comboBox_2_VERCICULO_SALMO->setDisabled(false);
                ui->comboBox_2_VERCICULO_SALMO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_2_VERCICULO_SALMO->addItem(QString::number(i+1));
        }
        break;break;
    }
}

void MarcarEspecifico::on_comboBox_3_CAPITULO_PROVERBIOS_currentIndexChanged(int index)
{
    ui->listWidget_MARCADORESPECIFICO->clear();
    switch(index){
    case 1:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[0]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 2:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[1]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 3:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[2]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 4:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[3]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 5:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[4]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 6:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[5]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 7:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[6]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 8:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[7]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 9:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[8]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 10:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[9]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 11:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[10]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 12:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[11]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 13:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[12]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 14:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[13]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 15:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[14]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 16:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[15]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 17:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[16]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 18:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[17]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 19:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[18]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 20:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[19]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 21:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[20]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 22:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[21]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 23:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[22]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 24:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[23]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 25:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[24]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 26:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[25]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 27:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[26]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 28:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[27]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 29:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[28]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 30:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[29]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    case 31:
        ui->comboBox_4_VERCICUL_PROVERBIO->clear();
        for (int i = 0; i < V_P_P_P[30]; ++i) {
            if(i==0){
                ui->comboBox_4_VERCICUL_PROVERBIO->setDisabled(false);
                ui->comboBox_4_VERCICUL_PROVERBIO->addItem(/*"item " + */'\0');
            }
            ui->comboBox_4_VERCICUL_PROVERBIO->addItem(QString::number(i+1));
        }
        break;break;
    }
}

void MarcarEspecifico::on_comboBox_4_VERCICUL_PROVERBIO_activated(int index)
{
    marcado2= index;
    //qDebug()<<"index:"<<index<<"marcado2:"<<marcado2;
}

void MarcarEspecifico::on_comboBox_3_CAPITULO_PROVERBIOS_activated(int index)
{
    marcado1=index;
    //qDebug()<<"index:"<<index<<"marcado1:"<<marcado1;
}

void MarcarEspecifico::on_pushButton_3_LEER_CAPITULO_clicked()
{//salmos
    QVariant variante;
    variante.setValue<int>(marcado1);
    QString verc_strin = variante.value<QString>();

    QString txt= ".txt";
    QString direc = QString(":/SALMOS/%1%2")/*.arg(cual)*/.arg(verc_strin).arg(txt);
    QFileDialog dialogo(this);
    dialogo.setAcceptMode(QFileDialog::AcceptOpen);
    dialogo.setFileMode(QFileDialog::AnyFile);
    QFile archivo(direc);
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!archivo.isOpen()){return;}

    QTextStream  str(&archivo);
    str.flush();
    todo_marca.append(str.readAll());
    archivo.flush();
    archivo.close();

    QListIterator<QString> i(todo_marca);
    while (i.hasNext()){
        ui->listWidget_MARCADORESPECIFICO->clear();
        ui->listWidget_MARCADORESPECIFICO->addItem(i.next());
    }
    //}
}
void MarcarEspecifico::on_comboBox_CAPITULO_SALMOS_activated(int index)
{
    marcado1=index;
    //qDebug()<<"capitulo: "<<index;
}
void MarcarEspecifico::on_comboBox_2_VERCICULO_SALMO_activated(int index)
{
    marcado2=index;
    //qDebug()<<"verciculo: "<<index;
}
void MarcarEspecifico::on_pushButton_CAPITULOPROVERBIOS_clicked()
{
    QVariant variante;
    variante.setValue<int>(marcado1);
    QString verc_strin = variante.value<QString>();

    QString txt= ".txt";
    QString direc = QString(":/PRO/%1%2").arg(verc_strin).arg(txt);
    QFileDialog dialogo(this);
    dialogo.setAcceptMode(QFileDialog::AcceptOpen);
    dialogo.setFileMode(QFileDialog::AnyFile);
    QFile archivo(direc);
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!archivo.isOpen()){return;}

    QTextStream  str(&archivo);
    str.flush();
    todo_marca.append(str.readAll());
    archivo.flush();
    archivo.close();

    QListIterator<QString> i(todo_marca);
    while (i.hasNext()){
        ui->listWidget_MARCADORESPECIFICO->clear();
        ui->listWidget_MARCADORESPECIFICO->addItem(i.next());
    }
}
void MarcarEspecifico::crear_action(){
    SalirAct = new QAction (QIcon(":/Iconos/salida.png"),tr("Salir"), this);
    connect(SalirAct, SIGNAL(triggered()), this, SLOT(close()));

    EliminaArct = new QAction (QIcon(":/Iconos/erase.png"),tr("Eliminar"), this);
    connect(EliminaArct, SIGNAL(triggered()), this, SLOT(limpiar_listWid()));
}
void MarcarEspecifico::limpiar_listWid(){
    delete ui->listWidget_MARCADORESPECIFICO->currentItem();
}
void MarcarEspecifico::on_MarcarEspecifico_customContextMenuRequested()
{
    QMenu menu11(this);
    menu11.addAction(SalirAct);
    menu11.exec(QCursor::pos());
}
void MarcarEspecifico::on_listWidget_MARCADORESPECIFICO_customContextMenuRequested(){
    QMenu menu12(this);
    menu12.addAction(EliminaArct);
    menu12.addAction(SalirAct);
    menu12.exec(QCursor::pos());
}

void MarcarEspecifico::on_pushButton_LEER_VERCICULO_PROVERBIO_clicked()
{
    // if(marcado1!=0 && !marcado2){
    conteo_maximo2.first=0;
    QVariant variante;
    variante.setValue<int>(marcado1);
    QString verc_strin = variante.value<QString>();
    QString txt= ".txt";
    QString direc = QString(":/PRO/%1%2").arg(verc_strin).arg(txt);
    QFileDialog dialogo(this);
    dialogo.setAcceptMode(QFileDialog::AcceptOpen);
    dialogo.setFileMode(QFileDialog::AnyFile);
    QFile archivo(direc);
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!archivo.isOpen()){return;}

    QTextStream  str(&archivo);

    switch(marcado1){
    case 1:
        for(int i=0;i<=marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 2:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 3:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 4:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 5:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 6:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 7:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 8:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 9:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 10:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 11:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 12:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 13:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 14:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 15:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 16:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 17:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 18:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 19:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 20:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 21:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 22:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 23:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 24:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 25:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 26:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 27:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 28:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 29:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 30:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 31:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    }
}
//}

void MarcarEspecifico::on_pushButton_LEER_VERCICULO_SALMO_clicked()
{
    //if(marcado1!=0 && marcado2!=0){
    conteo_maximo2.first=0;
    QVariant variante;
    variante.setValue<int>(marcado1);
    QString verc_strin = variante.value<QString>();
    QString txt= ".txt";
    QString direc = QString(":/SALMOS/%1%2").arg(verc_strin).arg(txt);
    QFileDialog dialogo(this);
    dialogo.setAcceptMode(QFileDialog::AcceptOpen);
    dialogo.setFileMode(QFileDialog::AnyFile);
    QFile archivo(direc);
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!archivo.isOpen()){return;}

    QTextStream  str(&archivo);

    switch(marcado1){
    case 1:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 2:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 3:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 4:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 5:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 6:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 7:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 8:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 9:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 10:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 11:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 12:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 13:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 14:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 15:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 16:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 17:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 18:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 19:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 20:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 21:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 22:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 23:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 24:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 25:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 26:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 27:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 28:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 29:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 30:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 31:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 32:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;

    case 33:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 34:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 35:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 36:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 37:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 38:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 39:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 40:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 41:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 42:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 43:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 44:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 45:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 46:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 47:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 48:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 49:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 50:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 51:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 52:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 53:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 54:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 55:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 56:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 57:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 58:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 59:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 60:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 61:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 62:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 63:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 64:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 65:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 66:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 67:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 68:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 69:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 70:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 71:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 72:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 73:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 74:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 75:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 76:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 77:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 78:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 79:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 80:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 81:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 82:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 83:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 84:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 85:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 86:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 87:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 88:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 89:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 90:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 91:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 92:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 93:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 94:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 95:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 96:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 97:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 98:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 99:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 100:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 101:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 102:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 103:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 104:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 105:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 106:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 107:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 108:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 109:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 110:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 111:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 112:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 113:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 114:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 115:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 116:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 117:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 118:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 119:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 120:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 121:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 122:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 123:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 124:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 125:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 126:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 127:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 128:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 129:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 130:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 131:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 132:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 133:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 134:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 135:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 136:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 137:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 138:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 139:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 140:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 141:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 142:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 143:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 144:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 145:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 146:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 147:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 148:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 149:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    case 150:
        for(int i=0;i<marcado2;i++){
            todo_marca.append(str.readLine());
            conteo_maximo2.first++;
        }
        todo_marca.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->listWidget_MARCADORESPECIFICO->addItem(todo_marca[--conteo_maximo2.first]);
        todo_marca.clear();
        break;break;
    }
}
//}
