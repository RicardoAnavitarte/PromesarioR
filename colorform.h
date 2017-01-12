#ifndef COLORFORM_H
#define COLORFORM_H

#include <QWidget>

namespace Ui {
class ColorForm;
}

class ColorForm : public QWidget
{
    Q_OBJECT

public:
    explicit ColorForm(QWidget *parent = nullptr);
    ~ColorForm();
signals:
    void R_Changed(int);
    void G_Changed(int);
    void B_Changed(int);

private slots:
    void on_horizontalSlider_R_valueChanged(int value);
    void on_horizontalSlider_2_G_valueChanged(int value);
    void on_horizontalSlider_3_B_valueChanged(int value);

    void eviado_elementoColorRGB(QColor Col_RGB);
    //void eviado_elementoColorGUARDADO(QColor Col_GUARDADO);

private:
    Ui::ColorForm *ui;
};

#endif // COLORFORM_H
