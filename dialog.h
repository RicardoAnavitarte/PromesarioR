#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}
class ColorForm;
class ReadAll;
class Widget;
QT_BEGIN_NAMESPACE
class QVBoxLayout;
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
    class QTimer *timer;
    ReadAll *read;
    Widget *wid;
public:
    explicit Dialog(QWidget *parent= nullptr);
    ~Dialog();
    //variables a utilizar:
    int chek_c;
    //para la fuente y el color:
    QPair<QColor,QFont>col_font;

    QString txt;
    QList<QString> list_contenido;
    QList<QAction *> actions_LIST;
    QList<QString> list_all;
    QList<int> V_P_P_P;
    QList<int> V_P_P_C;
    unsigned Conteo_Rueda;

    int gene_cap();
    void gene_chek();
    int gene_verc(int capitulo);
    int mostrar_salva_struct();
    int mostrar_salva_struct2();
    void apagar_menos_generar();
    void apagar_menos_generar_act();
    void encender_menos_generar();
    void encender_menos_generar_act();

    //para el start y stop:
    void disable_start();
    void disable_pause();

    //actualizar el temporizador seleccionado:
    void actualizar_seg1();
    void actualizar_seg2();
    void actualizar_seg3();
    void actualizar_defaul();
    void cargar_ajustes_timer();
    void guardar_ajustes_timer();

private slots:
    void on_SALIR_clicked();
    void on_LIMPIAR_clicked();
    void on_GUARDAR_clicked();
    void on_UNOMAS_clicked();
    void on_UNOATRAS_clicked();
    //PARA GENERAR TODOS AUNQUE NO ESTEN MARCADOS LOS CHEKBOX:
    void on_GENERAR_clicked();//para enerr segun de seleccione independientemente los cekbox
    void GENERADOR_GENERAl();
    void GENERAR_proverbio();
    void GENERAR_salmo();
    void GENERAR_antiguotestamento();
    //void GENERAR_nuevotestamento();
    //TEMPORIZADOR
    void tiempofuera();
    void tiempoStart();
    void tiempoStart1();//1seg
    void tiempoStart2();//2seg
    void tiempoStart3();//3seg
    void tiempoStart4();//3seg
    void tiempoStop();//default
    void tiempoReset();
    //FUENTE  Y COLOR
    void on_COLOR_clicked();
    void on_FUENTE_2_clicked();
    //PARA SI ESTAN MARCADOS LOS CHEKBOX,PARA QUE GENEREN:
    void on_PROVERBIO_toggled(bool checked);
    void on_SALMOS_toggled(bool checked);
    //MENU CONTEXTUAL:
    //void on_textEdit_customContextMenuRequested(const QPoint &pos);
    void on_moreButton_toggled(bool checked);
    void on_ANTIGUOTESTAMENTO_clicked(bool checked);
    void on_NUEVOTESTAMNETO_clicked(bool checked);
    void on_SELECCIONARTODO_clicked(bool checked);
    void on_PROVERBIO_clicked(bool checked);
    void on_SALMOS_clicked(bool checked);
    void SELECCIONARTODO();
    void on_ACERCADE_clicked();

    //para guardar ajustes:
    void cargar_ajustes();
    void guardar_ajustes();

    //para cargar color y fuente:
    void cargar_ajustes_color_fuente();
    void guardar_ajustes_color_fuente();

    //botones de los ajustes:
    void on_GUARDARAGENERAR_clicked();

    //para el menu contextual del textedit:
    void on_textEdit_customContextMenuRequested();
    //para el menu contextual de los botones:
    void on_GENERAR_customContextMenuRequested();
    void on_UNOMAS_customContextMenuRequested();
    void on_GUARDAR_customContextMenuRequested();
    void on_LIMPIAR_customContextMenuRequested();
    void on_SALIR_customContextMenuRequested();
    void on_moreButton_customContextMenuRequested();
    void on_progressBar_customContextMenuRequested();
    //para timer pero en botones no en menu contextual:
    void on_STARTBUTTON_clicked();
    void on_PAUSEBUTTON_clicked();
    void on_RESETBUTTON_clicked();
    void on_READALL_clicked();

    void on_Slider_Size_valueChanged(int value);

private:
    void createActions();

    QMenu *menu10;
    QAction *GenerarAct;
    QAction *UnomasAct;
    QAction *UnoatrasAct;
    QAction *GuardarAct;
    QAction *saveallAct;
    QAction *LimpiarAct;
    QAction *SalirAct;
    //action del timer:
    QAction *StartAct;
    QAction *PausaAct;
    QAction *ResetAct;
    QActionGroup *segundos;
    QAction *seg1Act;
    QAction *seg2Act;
    QAction *seg3Act;
    QAction *defaulAct;
    //QAction *saveAct;
    //QAction *MoreButtonAct;
    QAction *MoreButtonAct;

    //PARA COLOR_RGB
    ColorForm *mColor_ClF;
    QVBoxLayout *mLayout;
    QMenu *mMenu;
    QColor mColor;

    void updateRGB();

    Ui::Dialog *ui;
signals:
    void elementoAgregado_QLIST(/*QList<QString>,*/int,int);//(QString);//esta es la funcion que se emitira para la clase readall para que se muestre lo mismo que sale en el textedit de la clase dialog
    void elementoColorRGB(QColor);
    //void elementoColorGUARDADO(QColor);
    //void elementoAgregado(int, int);
    // void elementoAgregadoSonido(QString);//farta llamar en el .cpp de dialog a esta funcion con el Qstring a emitir

protected:
    void wheelEvent(QWheelEvent * e);//para la rueda del maus, para hacer Zoom
    //void clickEvent(QMouseEvent *e);
};
#endif // DIALOG_H
