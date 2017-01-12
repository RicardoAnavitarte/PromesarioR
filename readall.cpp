#include <readall.h>
#include "ui_readall.h"
#include "dialog.h"
#include "ui_dialog.h"
#include "marcarespecifico.h"
#include <QModelIndex>
#include <QListWidgetItem>
#include <QTextStream>
#include <ctime>
#include <QTimer>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <QMessageBox>
#include <QtCore>
#include <QList>
#include <QIcon>
#include <QContextMenuEvent>
#include <QMenu>
#include <QAction>
#include <QPoint>
#include <QMessageBox>
#include <QStringList>//para la lista de filtros al guardar
#include <QSettings>
#include <QPlainTextEdit>
#include <QCursor>
#include <QActionGroup>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QWheelEvent>

ReadAll::ReadAll(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReadAll)
{
    ui->setupUi(this);
    creating_action();
    ui->listWidget->close();

//    Dialog dial;
//qDebug() <<dial.col_font.second;
//    ui->textEdit->setFont(dial.col_font.second);

    ui->BUSCAR->setToolTip("Para <font color='orange'>buscar o leer </font> un versículo o capítulo en especifico .");

    setMinimumSize(650,355);
    resize(650,600);
    setMaximumSize(650,630);
}

ReadAll::~ReadAll()
{
    delete ui;
}

void ReadAll::creating_action()
{
    SalirAct = new QAction (QIcon(":/Iconos/salida.png"),tr("Salir"), this);
    connect(SalirAct, SIGNAL(triggered()), this, SLOT(close()));

    EliminaArct = new QAction (QIcon(":/Iconos/erase.png"),tr("Eliminar"), this);
    connect(EliminaArct, SIGNAL(triggered()), this, SLOT(on_CLEAR()));
}

void ReadAll::wheelEvent(QWheelEvent *e)
{
    //QString result;
    if (e->delta() > 0) {

        if (e->orientation() == Qt::Vertical) {
            Conteo_Rueda++;
            //ui->textEdit->selectAll();
           ui->textEdit->setFontPointSize(Conteo_Rueda);
        } else {
        }
    } else if (e->delta() < 0) {
        if (e->orientation() == Qt::Vertical) {
                Conteo_Rueda=8;
            //ui->textEdit->selectAll();
          ui->textEdit->setFontPointSize(8);
        } else {
            //result = "Mouse Rueda Event: RIGHT";
        }
    }
}

//void ReadAll::en_elemento_agregado(int cap,  int che)
//{
//    qDebug()<<cap<<"-"<<che;
//    QVariant variante;
//    variante.setValue<int>(cap);
//    QString verc_strin = variante.value<QString>();
//    QString cual;
//    if(che==1){
//        cual="PRO";
//    }
//    else{
//        cual="SALMOS";
//    }
//    QString txt= ".txt";
//    QString direc = QString(":/%1/%2%3").arg(cual).arg(verc_strin).arg(txt);
//    QFileDialog dialogo(this);
//    dialogo.setAcceptMode(QFileDialog::AcceptOpen);
//    dialogo.setFileMode(QFileDialog::AnyFile);
//    QFile archivo(direc);
//    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
//    if(!archivo.isOpen()){return;}

//    QTextStream  str(&archivo);
//    str.flush();
//    todo.append(str.readAll());
//    archivo.flush();
//    archivo.close();

//    QListIterator<QString> i(todo);
//    while (i.hasNext()){
//        ui->listWidget->clear();
//        ui->listWidget->addItem(i.next());
//    }
//}

void ReadAll::en_elemento_agregado_QLIST(/*QList<QString> envio,*/int cap,/*int verc,*/int che)
{
    //qDebug()<<"readll"<< "Cap= " << cap /* << " y " << verc */<< " y "  <<"Chec_c= " << che;
    QVariant variante;
    variante.setValue<int>(cap);
    QString verc_strin = variante.value<QString>();
    QString cual;
    if(che==1){
        cual="PRO";
    }
    else{
        cual="SALMOS";
    }
    QString txt= ".txt";
    QString direc = QString(":/%1/%2%3").arg(cual).arg(verc_strin).arg(txt);
    QFileDialog dialogo(this);
    dialogo.setAcceptMode(QFileDialog::AcceptOpen);
    dialogo.setFileMode(QFileDialog::AnyFile);
    QFile archivo(direc);
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!archivo.isOpen()){return;}

    QTextStream  str(&archivo);
    str.flush();
    todo.append(str.readAll());
    archivo.flush();
    archivo.close();


    for (int var = 0; var < todo.size(); ++var) {
        ui->textEdit->clear();
        ui->textEdit->setText(todo[var]);
    }
    QListIterator<QString> i(todo);
    while (i.hasNext()){
        ui->listWidget->clear();
        ui->listWidget->addItem(i.next());    
//setFont(setPixelSize(Conteo_Rueda));
    }

}

    void ReadAll::on_listWidget_customContextMenuRequested()
    {
        QMenu menu10(this);
        menu10.addAction(EliminaArct);
        menu10.addAction(SalirAct);
        menu10.exec(QCursor::pos());
    }

    void ReadAll::on_CLEAR()
    {
        delete ui->listWidget->currentItem();
    }

    void ReadAll::on_BUSCAR_clicked()
    {
        me=new MarcarEspecifico(this);
        me->exec();
    }
