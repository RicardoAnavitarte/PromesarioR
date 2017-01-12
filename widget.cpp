#include "widget.h"
#include "ui_widget.h"
//[1]
#include <QMediaPlayer>
#include <QFileDialog>
#include <QApplication>
#include <QDir>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent)/*,
    ui(new Ui::Widget)*/
{
    //ui->setupUi(this);
    //[2]
    mMediaPlayer = new QMediaPlayer(this);

    //    connect(mMediaPlayer, &QMediaPlayer::positionChanged, [&](qint64 pos){
    //        ui->progressBar->setValue(pos);
    //    });
    //    connect(mMediaPlayer, &QMediaPlayer::durationChanged, [&](qint64 dur){
    //        ui->progressBar->setMaximum(dur);
    //    });

}

Widget::~Widget()
{
   // delete ui;
}

void Widget::Progress_Sonido()
{
    const QString f1 ("E:/Cosas que estaban en el escritorio/SW QT/salve/PromesarioRgit/SONIDOS/tic_hard.mp3");
    mMediaPlayer->setMedia(QUrl::fromLocalFile(f1));
    mMediaPlayer->setVolume(50);
    mMediaPlayer->play();
}

void Widget::Button_More()
{
    const QString f1 ("E:/Cosas que estaban en el escritorio/SW QT/salve/PromesarioRgit/SONIDOS/3.mp3");
    mMediaPlayer->setMedia(QUrl::fromLocalFile(f1));
    mMediaPlayer->setVolume(50);
    mMediaPlayer->play();
}

void Widget::Menu_context_sonido()
{
    const QString f1 ("E:/Cosas que estaban en el escritorio/SW QT/salve/PromesarioRgit/SONIDOS/4.mp3");
    mMediaPlayer->setMedia(QUrl::fromLocalFile(f1));
    mMediaPlayer->setVolume(50);
    mMediaPlayer->play();
}

void Widget::Button_atras_sonido()
{
    const QString f2 ("E:/Cosas que estaban en el escritorio/SW QT/salve/PromesarioRgit/SONIDOS/tic_hard2.mp3.mp3");
    mMediaPlayer->setMedia(QUrl::fromLocalFile(f2));
    mMediaPlayer->setVolume(50);
    mMediaPlayer->play();
}

void Widget::Button_adelante_sonido()
{
    const QString f1 ("E:/Cosas que estaban en el escritorio/SW QT/salve/PromesarioRgit/SONIDOS/CLICK2_ADELANTE.mp3");
    mMediaPlayer->setMedia(QUrl::fromLocalFile(f1));
    mMediaPlayer->setVolume(50);
    mMediaPlayer->play();
}

//void Widget::on_pushButton_AbrirMedio_clicked()
//{
////    QFileDialog dial(this);
////    QString filename =dial.getOpenFileName(this, "Abrir");

//    //QString filename = QFileDialog::getOpenFileName(this, "Abrir");
//   // QString filename = QFileDialog::getOpenFileName(this,":/SONIDOS/1.mp3");
////    if(filename.isEmpty()){
////        return;
////    }
////    const QString filename("E:/Cosas que estaban en el escritorio/SW QT/salve/PromesarioRgit/SONIDOS/1.mp3");
//    //qDebug() << filename;
//    const QString filename ("E:/Cosas que estaban en el escritorio/SW QT/salve/PromesarioRgit/SONIDOS/4.mp3");
//   //4 para el boton e setting
//    qDebug() << filename;
//    mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
//    ui->slider_Volumen->setValue(50);
//    mMediaPlayer->setVolume(ui->slider_Volumen->value());
////    on_pushButton_2_Play_clicked();
//}

//void Widget::on_pushButton_2_Play_clicked()
//{
//    mMediaPlayer->play();
//}

//void Widget::on_pushButton_3_Pause_clicked()
//{
//    mMediaPlayer->pause();
//}

//void Widget::on_pushButton_4_Stop_clicked()
//{
//    mMediaPlayer->stop();
//}

//void Widget::on_pushButton_5_Mute_clicked()
//{
//    if(ui->pushButton_5_Mute->text() == "Mute"){
//        mMediaPlayer->setMuted(true);
//        ui->pushButton_5_Mute->setText("Unmute");
//    }else{
//        mMediaPlayer->setMuted(false);
//        ui->pushButton_5_Mute->setText("Mute");
//    }

//}

//void Widget::on_slider_Volumen_valueChanged(int value)
//{
//    mMediaPlayer->setVolume(value);
//}
