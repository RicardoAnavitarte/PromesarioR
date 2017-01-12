#ifndef READALL_H
#define READALL_H

#include <QDialog>

namespace Ui {
class ReadAll;
}

class MarcarEspecifico;

class ReadAll : public QDialog
{
    Q_OBJECT
    MarcarEspecifico* me;
public:
    explicit ReadAll(QWidget *parent= nullptr);
    ~ReadAll();
    QList<QString> todo;
    int cap_g = 0;
    int Conteo_Rueda;

    Ui::ReadAll *ui;
private slots://[4]
    void en_elemento_agregado_QLIST(/*QList<QString> envio,*/int cap,/*int verc,*/int che);
    //void en_elemento_agregado(int cap, int che);
    void on_listWidget_customContextMenuRequested();
    void on_CLEAR();
    void on_BUSCAR_clicked();

private:
    void creating_action();

    QAction *SalirAct;
    //QAction *NotSelecArct;
    QAction *EliminaArct;

protected:
  void wheelEvent(QWheelEvent * e);
};

#endif // READALL_H
