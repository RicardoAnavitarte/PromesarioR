#ifndef MARCARESPECIFICO_H
#define MARCARESPECIFICO_H

#include <QDialog>

namespace Ui {
class MarcarEspecifico;
}

class MarcarEspecifico : public QDialog
{
    Q_OBJECT
    QAction* SalirAct;
    QAction* EliminaArct;

public:
    explicit MarcarEspecifico(QWidget *parent= nullptr);
    ~MarcarEspecifico();
    QList<int> V_P_P_C;
    QList<int> V_P_P_P;

    QList<QString> todo_marca;

    int marcado1=0;//para guardar los capitulos
    int marcado2=0;//para guardar los verciculos

   void inicializando_variables_verciculos();

    void crear_action();
    Ui::MarcarEspecifico *ui;


private slots:
    //metodo para limpiar la list_widgwts en marcador es:
    void limpiar_listWid();

    void on_comboBox_CAPITULO_SALMOS_currentIndexChanged(int index);
    void on_comboBox_3_CAPITULO_PROVERBIOS_currentIndexChanged(int index);

    //para tomar el valor del combobox
    void on_comboBox_4_VERCICUL_PROVERBIO_activated(int index);
    void on_comboBox_3_CAPITULO_PROVERBIOS_activated(int index);
    void on_comboBox_CAPITULO_SALMOS_activated(int index);
    void on_comboBox_2_VERCICULO_SALMO_activated(int index);

    //leer capitulo y verciculo de salmos:
    void on_pushButton_3_LEER_CAPITULO_clicked();
    void on_pushButton_CAPITULOPROVERBIOS_clicked();

    //leer capitulo y verciculo de proverbios:
    void on_pushButton_LEER_VERCICULO_PROVERBIO_clicked();

    //menu contextual para salir y eliminar pero eliminar no funciona:
    void on_MarcarEspecifico_customContextMenuRequested();
    void on_listWidget_MARCADORESPECIFICO_customContextMenuRequested();

    void on_pushButton_LEER_VERCICULO_SALMO_clicked();
};

#endif // MARCARESPECIFICO_H
