#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


namespace Ui {
class Widget;
}

//[0]
class QMediaPlayer;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent= nullptr);
    ~Widget();
    void Progress_Sonido();
    void Button_More();
    void Menu_context_sonido();
    void Button_atras_sonido();
    void Button_adelante_sonido();


private slots:
    //void en_elemento_agregado_sonido(QString valor);


//    void on_pushButton_AbrirMedio_clicked();
//    void on_pushButton_2_Play_clicked();
//    void on_pushButton_3_Pause_clicked();
//    void on_pushButton_4_Stop_clicked();
//    void on_pushButton_5_Mute_clicked();
//    void on_slider_Volumen_valueChanged(int value);

private:
   // Ui::Widget *ui;
    QMediaPlayer *mMediaPlayer;

};

#endif // WIDGET_H
