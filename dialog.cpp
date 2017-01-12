#include "dialog.h"
#include "ui_dialog.h"
#include "readall.h"
#include "ui_readall.h"
#include "widget.h"
#include "ui_widget.h"
#include "colorform.h"
#include "ui_colorform.h"

#include <QWidget>
#include <QTextStream>
#include <ctime>
#include <QTimer>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QIcon>
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
#include <QVBoxLayout>
#include <QAction>
#include <QPoint>
#include <QMessageBox>
#include <QStringList>
#include <QSettings>
#include <QPlainTextEdit>
#include <QCursor>
#include <QActionGroup>
#include <QWheelEvent>//para el event de la rueda del maus
#include <QMouseEvent>


QPair<int,int>c_v_s;
QPair<int,int>conteo_maximo;
QPair<bool,bool>marc_1_2_seg;
QPair<bool,bool>marc_3_default;
QPair<bool,bool>marc_PRO_SAL;
QPair<bool,bool>marc_AT_NT;
QPair<bool,int>marc_SELCTODO_time;
//QPair<unsigned , int>Conteo_Rueda_Max_Min;

//bool marc_SELCTODO;

Dialog::Dialog(QWidget *parent) :QDialog(parent),ui(new Ui::Dialog){
    ui->setupUi(this);
    ui->Slider_Size->setMaximum(72);
    ui->textEdit->setFont(col_font.second);
    //Quitar el Zoom manual:
    ui->label_menor->close();
    ui->Slider_Size->close();
    ui->label_2_mayor->close();

    V_P_P_P<<33<<22<<35<<27<<23<<35<<27<<36<<18<<32
          <<31<<28<<25<<35<<33<<33<<28<<24<<29<<30<<31
         <<29<<35<<34<<28<<28<<27<<28<<27<<33<<31;

    V_P_P_C<<6<<12<<8<<8<<12<<10<<17<<9<<20<<18<<7<<8<<6<<7<<5<<11<<15<<50<<14<<9<<13<<31<<6<<10<<22<<12<<14<<9
          <<11<<12<<24<<11<<22<<22<<28<<12<<40<<22<<13<<17<<13<<11<<5<<26<<17<<11<<9<<14
         <<20<<23<<19<<9<<6<<7<<23<<13<<11<<11<<17<<12<<8<<12<<11<<10<<13<<20<<7<<35
        <<36<<5<<24<<20<<28<<23<<10<<12<<20<<72<<13<<19<<16<<8<<18<<12<<13<<17<<7<<18
       <<52<<17<<16<<15<<5<<23<<11<<13<<12<<9<<9<<5<<8<<28<<22<<35<<45<<48<<43<<13
      <<31<<7<<10<<10<<9<<7<<18<<19<<2<<29<<176<<7<<8<<9<<4<<8<<6<<6<<5<<5<<8<<8
     <<3<<18<<3<<3<<21<<26<<9<<8<<24<<13<<10<<7<<12<<15<<20<<10<<20<<14<<9<<6;

    //TEMPORIZADOR
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout(/*QPrivateSignal*/)),this, SLOT(tiempofuera()));
    //tiempofuera();
    read =  new ReadAll(this);//no se puede poner en otra parte porque sino se bloque el sw
    ui->widget->setVisible(false);
    //PARA LOS EFECTOS DE SONIDOS:
    wid = new Widget(this);

    //PARA COLOR_RGB
    mColor_ClF = new ColorForm(this);
    mLayout = new QVBoxLayout;
    mMenu = new QMenu("RGB",this);
    mLayout->addWidget(mColor_ClF);
    mLayout->setMenuBar(0);
    mMenu->setLayout(mLayout);
    ui->COLOR_R_G_B_2->setMenu(mMenu);
    updateRGB();
    connect(mColor_ClF, &ColorForm::R_Changed, [&](int value){
        mColor.setRed(value);
        updateRGB();
        guardar_ajustes_color_fuente();
    });
    connect(mColor_ClF, &ColorForm::G_Changed, [&](int value){
        mColor.setGreen(value);
        updateRGB();
        guardar_ajustes_color_fuente();
    });
    connect(mColor_ClF, &ColorForm::B_Changed, [&](int value){
        mColor.setBlue(value);
        updateRGB();
        guardar_ajustes_color_fuente();
    });
    //PARA CREAR LAS ACTION EL MENU CONSTEXTUAL:
    createActions();
    //PARA CUANDO PONGAMOS EL MAUS ENSIMA DEL LOS BOTONES NOS MUESTRE PARA QUE SIRVE:
    ui->GENERAR->setToolTip("Genera un <font color='orange'>proverbio</front>.");
    ui->UNOMAS->setToolTip("Pasa al siguiente  <font color='orange'>versículo</font> de lo generado.");
    ui->UNOATRAS->setToolTip("Pasa el anterior  <font color='orange'>versículo</font> de lo generado.");
    ui->GUARDAR->setToolTip("<img src=':/Iconos/savee.png'> Guardar el <font color='orange'>proverbio</front> actual.");
    ui->LIMPIAR->setToolTip("<img src=':/Iconos/erase.png'> Limpia lo <font color='orange'>generado</front> .");
    ui->SALIR->setToolTip("<img src=':/Iconos/salida.png'> Salir del programa.");

    ui->STARTBUTTON->setToolTip("<font color='orange'> Inicia </font> el tiempo de generación automática.");
    ui->PAUSEBUTTON->setToolTip("<font color='orange'> Detiene </font> el tiempo de generación automática.");
    ui->RESETBUTTON->setToolTip("<font color='orange'> Resetea </font> el tiempo de generación automática.");
    ui->progressBar->setToolTip("Configuraciones para la generación aleatoria, como su control:<font color='orange'> Clic Derecho</font>");
    ui->moreButton->setToolTip("<font color='orange'> Configuración </font> de opciones de generacion, fuente y color.");

    ui->COLOR->setToolTip("<font color='orange'> Configuración </font> de opcion de color.");
    ui->FUENTE_2->setToolTip("<font color='orange'> Configuración </font> de opcion fuente.");
    ui->GUARDARAGENERAR->setToolTip("<font color='orange'> Guarda </font> la opcion de configuración.");
    ui->READALL->setToolTip("<font color='orange'> Muestra </font> el capitulo del versículo generado.");
    ui->GUARDARAGENERAR->setToolTip("<font color='orange'> Guarda </font> todas las configuraciones selecionadas en A Generar.");

    ui->READALL->setIcon(QIcon(":/Iconos/selec_all.png"));
    ui->UNOMAS->setIcon(QIcon(":/Iconos/next.png"));
    ui->GUARDAR->setIcon(QIcon(":/Iconos/savee.png"));
    ui->LIMPIAR->setIcon(QIcon(":/Iconos/erase.png"));
    ui->SALIR->setIcon(QIcon(":/Iconos/salida.png"));
    ui->GENERAR->setIcon(QIcon(":/Iconos/unomas.png"));
    //ui->ACERCADE->setIcon(QIcon(":/Iconos/acercade2.png") );//acercade
    ui->moreButton->setIcon(QIcon(":/Iconos/setting1.png"));

    cargar_ajustes_timer();
    cargar_ajustes_color_fuente();

    //para que el se inicie la progrs bar con el valor guardado
    if(seg1Act->isChecked()){
        marc_SELCTODO_time.second = 10;
        timer->start(marc_SELCTODO_time.second);
        }
    if(seg2Act->isChecked()){
        marc_SELCTODO_time.second = 20;
        timer->start(marc_SELCTODO_time.second);
    }
    if(seg3Act->isChecked()){
        marc_SELCTODO_time.second = 30;
        timer->start(marc_SELCTODO_time.second);
    }
    if(defaulAct->isChecked()){
        marc_SELCTODO_time.second = 40;
        timer->start(marc_SELCTODO_time.second);
    }
    if(seg1Act->isChecked()==false && seg2Act->isChecked()==false && seg3Act->isChecked()==false && defaulAct->isChecked()==false){
        //pra que se apaguen todos los botones del dialogo de la generacion automatica,todos menos el de reset
        disable_pause();
        ui->STARTBUTTON->setDisabled(true);
        StartAct->setDisabled(true);
    }

    //cargar los ajustes guardados al ejecutar el programa
    cargar_ajustes();
    //Para cuando se marque SELECCIONARTODO y se salga del programa, se pueda deseleccionar ese checbox
    if(ui->SELECCIONARTODO->isChecked() == true){ui->SELECCIONARTODO->setDisabled(false);}

    apagar_menos_generar();
    apagar_menos_generar_act();
    wid->Button_atras_sonido();

    //connect clases
    connect(this,SIGNAL(elementoAgregado_QLIST(/*QList<QString>,*/int,int)/*(QString)*/),read,SLOT(en_elemento_agregado_QLIST(/*QList<QString>,*/int,int)/*(QString)*/));
    connect(this,SIGNAL(elementoColorRGB(QColor)),mColor_ClF,SLOT(eviado_elementoColorRGB(QColor)));
    //connect(this,SIGNAL(elementoColorGUARDADO(QColor)),mColor_ClF,SLOT(eviado_elementoColorGUARDADO(QColor)));
    //connect(this,SIGNAL(elementoAgregado(int,int)),read,SLOT(en_elemento_agregado(int,int)));
    //connect(this,SIGNAL(elementoAgregadoSonido(QString)),wid,SLOT(en_elemento_agregado_sonido(QString)));
    //TAMANNO DEL DIALOG:
    setMinimumSize(510,362);
    resize(510,362);
    setMaximumSize(510,362);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::apagar_menos_generar(){
    if(!conteo_maximo.first){
        ui->GUARDAR->setEnabled(false);
        ui->LIMPIAR->setEnabled(false);
        ui->UNOMAS->setEnabled(false);
        ui->UNOATRAS->setEnabled(false);
    }
}

void Dialog::apagar_menos_generar_act()
{
    UnomasAct->setEnabled(false);
    GuardarAct->setEnabled(false);
    LimpiarAct->setEnabled(false);
    UnoatrasAct->setEnabled(false);
    UnomasAct->setEnabled(false);
}
void Dialog::encender_menos_generar(){
    if(conteo_maximo.first){
        ui->GUARDAR->setEnabled(true);
        ui->LIMPIAR->setEnabled(true);
        ui->UNOMAS->setEnabled(true);
        ui->UNOATRAS->setEnabled(true);
    }
}

void Dialog::encender_menos_generar_act()
{
    UnomasAct->setEnabled(true);
    GuardarAct->setEnabled(true);
    LimpiarAct->setEnabled(true);
    UnoatrasAct->setEnabled(true);
    UnomasAct->setEnabled(true);
}

void Dialog::disable_start()
{
    //botones del dialogo
    ui->STARTBUTTON->setDisabled(true);
    ui->PAUSEBUTTON->setDisabled(false);
    //botones del menucontextual de la progressbar
    StartAct->setDisabled(true);
    PausaAct->setDisabled(false);
}
void Dialog::disable_pause()
{
    //botones del dialogo
    ui->STARTBUTTON->setDisabled(false);
    ui->PAUSEBUTTON->setDisabled(true);
    //botones del menucontextual de la progressbar
    StartAct->setDisabled(false);
    PausaAct->setDisabled(true);
}

void Dialog::actualizar_seg1()
{
    if (actions_LIST[0]->isChecked()) {
        seg2Act->setDisabled(actions_LIST[0]);
        seg3Act->setDisabled(actions_LIST[0]);
        defaulAct->setDisabled(actions_LIST[0]);
        marc_SELCTODO_time.second = 10;
        timer->start(marc_SELCTODO_time.second);
        disable_start();
    } else {
        seg2Act->setDisabled(false);
        seg3Act->setDisabled(false);
        defaulAct->setDisabled(false);
        timer->stop();
        disable_pause();
        ui->STARTBUTTON->setDisabled(true);
        StartAct->setDisabled(true);
       // marc_SELCTODO_time.second = 40;
    }
    guardar_ajustes_timer();
}

void Dialog::actualizar_seg2()
{
    if (actions_LIST[1]->isChecked()) {
        seg1Act->setDisabled(actions_LIST[1]);
        seg3Act->setDisabled(actions_LIST[1]);
        defaulAct->setDisabled(actions_LIST[1]);
        marc_SELCTODO_time.second = 20;
        timer->start(marc_SELCTODO_time.second);
        disable_start();
    } else {
        seg1Act->setDisabled(false);
        seg3Act->setDisabled(false);
        defaulAct->setDisabled(false);
        timer->stop();
        disable_pause();
        ui->STARTBUTTON->setDisabled(true);
        StartAct->setDisabled(true);
        //marc_SELCTODO_time.second = 40;
    }
    guardar_ajustes_timer();
}

void Dialog::actualizar_seg3()
{
    if (actions_LIST[2]->isChecked()) {
        seg1Act->setDisabled(actions_LIST[2]);
        seg2Act->setDisabled(actions_LIST[2]);
        defaulAct->setDisabled(actions_LIST[2]);
        marc_SELCTODO_time.second = 30;
        timer->start(marc_SELCTODO_time.second);
        disable_start();
    } else {
        seg1Act->setDisabled(false);
        seg2Act->setDisabled(false);
        defaulAct->setDisabled(false);
        timer->stop();
        disable_pause();
        ui->STARTBUTTON->setDisabled(true);
        StartAct->setDisabled(true);
        //marc_SELCTODO_time.second = 40;
    }
    guardar_ajustes_timer();
}

void Dialog::actualizar_defaul()
{
    if (actions_LIST[3]->isChecked()) {
        seg1Act->setDisabled(actions_LIST[3]);
        seg2Act->setDisabled(actions_LIST[3]);
        seg3Act->setDisabled(actions_LIST[3]);
        marc_SELCTODO_time.second = 40;
        timer->start(marc_SELCTODO_time.second);
        disable_start();
    } else {
        seg1Act->setDisabled(false);
        seg2Act->setDisabled(false);
        seg3Act->setDisabled(false);
        timer->stop();
        StartAct->setDisabled(false);
        PausaAct->setDisabled(true);
        disable_pause();
        ui->STARTBUTTON->setDisabled(true);
        StartAct->setDisabled(true);
        //marc_SELCTODO_time.second = 40;
    }
    guardar_ajustes_timer();
}

void Dialog::cargar_ajustes_timer()
{
    //para ajustes del tiempo:
    QSettings ajustes_timer;
    ajustes_timer.beginGroup("Generar en");//para comenzar el grupo

    marc_1_2_seg.first = ajustes_timer.value("1seg",marc_1_2_seg.first).toBool();//qui se va a cargar lo que se guarde en los ajustes
    marc_1_2_seg.second = ajustes_timer.value("2seg",marc_1_2_seg.second).toBool();
    marc_3_default.first = ajustes_timer.value("3seg", marc_3_default.first).toBool();
    marc_3_default.second= ajustes_timer.value("4default", marc_3_default.second).toBool();
    //if(marc_default==true||marc_3seg==true||marc_2seg==true||marc_1seg==true){
    if(marc_3_default.second==true||marc_3_default.first==true||marc_1_2_seg.second==true||marc_1_2_seg.first==true){
        //if(marc_default==true){
        if(marc_3_default.second==true){
            seg1Act->setDisabled(marc_3_default.second);
            seg2Act->setDisabled(marc_3_default.second);
            seg3Act->setDisabled(marc_3_default.second);
        }
        if(marc_3_default.first==true){
            seg1Act->setDisabled(marc_3_default.first);
            seg2Act->setDisabled(marc_3_default.first);
            defaulAct->setDisabled(marc_3_default.first);
        }
        if(marc_1_2_seg.second==true){
            seg1Act->setDisabled(marc_1_2_seg.second);
            seg3Act->setDisabled(marc_1_2_seg.second);
            defaulAct->setDisabled(marc_1_2_seg.second);
        }
        if(marc_1_2_seg.first==true){
            seg2Act->setDisabled(marc_1_2_seg.first);
            seg3Act->setDisabled(marc_1_2_seg.first);
            defaulAct->setDisabled(marc_1_2_seg.first);
        }
        disable_start();//para cuando se guarde alguno de los tiempo y se inicie el sw se pueda detener solamente
    }
    seg1Act->setChecked(marc_1_2_seg.first);
    seg2Act->setChecked(marc_1_2_seg.second);
    seg3Act->setChecked(marc_3_default.first);
    defaulAct->setChecked(marc_3_default.second);
    ajustes_timer.endGroup();
}

void Dialog::guardar_ajustes_timer()
{
    QSettings ajustes_timer;
    ajustes_timer.beginGroup("Generar en");//para comenzar el grupo
    marc_1_2_seg.first = seg1Act->isChecked();
    marc_1_2_seg.second = seg2Act->isChecked();
    marc_3_default.first = seg3Act->isChecked();
    marc_3_default.second = defaulAct->isChecked();
    ajustes_timer.setValue("1seg", marc_1_2_seg.first );
    ajustes_timer.setValue("2seg", marc_1_2_seg.second );
    ajustes_timer.setValue("3seg", marc_3_default.first );
    ajustes_timer.setValue("4default", marc_3_default.second);
    ajustes_timer.endGroup();
}


int Dialog::gene_cap(){
    srand(time(NULL));
    if(/*chek_c==1*/ui->PROVERBIO->isChecked()){
        int cap= 1+ (rand()%31);//PRO 31, estamos probando por eso se puso que genero solo del 1 al 2
        return cap;}
    if(/*chek_c==2*/ui->SALMOS->isChecked()){
        int cap= 1+ (rand()%150);//SAlMOS
        return cap;}
    //    if(/*chek_c==3*/){
    //        int cap= 2+ (rand()%4);//AT
    //        return cap;}
    return 1+ (rand()%31);//-1;
}

void Dialog::gene_chek(){
    srand(time(NULL));
    chek_c= 1+ (rand()%2);//3
}

int Dialog::gene_verc(int capitulo){
    srand(time(NULL));
    capitulo =gene_cap();
    gene_chek();
    if(chek_c==1){
        if(capitulo==1){int verc= 1+ (rand()%33);return verc;}
        if(capitulo==2){int verc= 1+ (rand()%22);return verc;}
        if(capitulo==3){int verc= 1+ (rand()%35);return verc;}
        if(capitulo==4){int verc= 1+ (rand()%27);return verc;}
        if(capitulo==5){int verc= 1+ (rand()%23);return verc;}
        if(capitulo==6){int verc= 1+ (rand()%35);return verc;}
        if(capitulo==7){int verc= 1+ (rand()%27);return verc;}
        if(capitulo==8){int verc= 1+ (rand()%36);return verc;}
        if(capitulo==9){int verc= 1+ (rand()%18);return verc;}
        if(capitulo==10){int verc=1+ (rand()%32);return verc;}
        if(capitulo==11){int verc=1+ (rand()%31);return verc;}
        if(capitulo==12){int verc=1+ (rand()%28);return verc;}
        if(capitulo==13){int verc=1+ (rand()%25);return verc;}
        if(capitulo==14){int verc=1+ (rand()%35);return verc;}
        if(capitulo==15){int verc=1+ (rand()%33);return verc;}
        if(capitulo==16){int verc=1+ (rand()%33);return verc;}
        if(capitulo==17){int verc=1+ (rand()%28);return verc;}
        if(capitulo==18){int verc=1+ (rand()%24);return verc;}
        if(capitulo==19){int verc=1+ (rand()%29);return verc;}
        if(capitulo==20){int verc=1+ (rand()%30);return verc;}
        if(capitulo==21){int verc=1+ (rand()%31);return verc;}
        if(capitulo==22){int verc=1+ (rand()%29);return verc;}
        if(capitulo==23){int verc=1+ (rand()%35);return verc;}
        if(capitulo==24){int verc=1+ (rand()%34);return verc;}
        if(capitulo==25){int verc=1+ (rand()%28);return verc;}
        if(capitulo==26){int verc=1+ (rand()%28);return verc;}
        if(capitulo==27){int verc=1+ (rand()%27);return verc;}
        if(capitulo==28){int verc=1+ (rand()%28);return verc;}
        if(capitulo==29){int verc=1+ (rand()%27);return verc;}
        if(capitulo==30){int verc=1+ (rand()%33);return verc;}
        if(capitulo==31){int verc=1+ (rand()%31);return verc;}
    }
    if(chek_c==2){
        if(capitulo==1){int verc= 1+ (rand()%6);return verc;}
        if(capitulo==2){int verc= 1+ (rand()%12);return verc;}
        if(capitulo==3){int verc= 1+ (rand()%8);return verc;}
        if(capitulo==4){int verc= 1+ (rand()%8);return verc;}
        if(capitulo==5){int verc= 1+ (rand()%12);return verc;}
        if(capitulo==6){int verc= 1+ (rand()%10);return verc;}
        if(capitulo==7){int verc= 1+ (rand()%17);return verc;}
        if(capitulo==8){int verc= 1+ (rand()%9);return verc;}
        if(capitulo==9){int verc= 1+ (rand()%20);return verc;}
        if(capitulo==10){int verc=1+ (rand()%18);return verc;}//10
        if(capitulo==11){int verc=1+ (rand()%7);return verc;}
        if(capitulo==12){int verc=1+ (rand()%8);return verc;}
        if(capitulo==13){int verc=1+ (rand()%6);return verc;}
        if(capitulo==14){int verc=1+ (rand()%7);return verc;}
        if(capitulo==15){int verc=1+ (rand()%5);return verc;}
        if(capitulo==16){int verc=1+ (rand()%11);return verc;}
        if(capitulo==17){int verc=1+ (rand()%15);return verc;}
        if(capitulo==18){int verc=1+ (rand()%50);return verc;}
        if(capitulo==19){int verc=1+ (rand()%14);return verc;}
        if(capitulo==20){int verc=1+ (rand()%9);return verc;}
        if(capitulo==21){int verc=1+ (rand()%13);return verc;}
        if(capitulo==22){int verc=1+ (rand()%31);return verc;}
        if(capitulo==23){int verc=1+ (rand()%6);return verc;}
        if(capitulo==24){int verc=1+ (rand()%10);return verc;}
        if(capitulo==25){int verc=1+ (rand()%22);return verc;}
        if(capitulo==26){int verc=1+ (rand()%12);return verc;}
        if(capitulo==27){int verc=1+ (rand()%14);return verc;}
        if(capitulo==28){int verc=1+ (rand()%9);return verc;}
        if(capitulo==29){int verc=1+ (rand()%11);return verc;}
        if(capitulo==30){int verc=1+ (rand()%12);return verc;}
        if(capitulo==31){int verc=1+ (rand()%24);return verc;}
        if(capitulo==32){int verc=1+ (rand()%11);return verc;}
        if(capitulo==33){int verc=1+ (rand()%22);return verc;}
        if(capitulo==34){int verc=1+ (rand()%22);return verc;}
        if(capitulo==35){int verc=1+ (rand()%28);return verc;}
        if(capitulo==36){int verc=1+ (rand()%12);return verc;}
        if(capitulo==37){int verc=1+ (rand()%40);return verc;}
        if(capitulo==38){int verc=1+ (rand()%22);return verc;}
        if(capitulo==39){int verc=1+ (rand()%13);return verc;}
        if(capitulo==40){int verc=1+ (rand()%17);return verc;}
        if(capitulo==41){int verc=1+ (rand()%13);return verc;}
        if(capitulo==42){int verc=1+ (rand()%11);return verc;}
        if(capitulo==43){int verc=1+ (rand()%5);return verc;}
        if(capitulo==44){int verc=1+ (rand()%26);return verc;}
        if(capitulo==45){int verc=1+ (rand()%17);return verc;}
        if(capitulo==46){int verc=1+ (rand()%11);return verc;}
        if(capitulo==47){int verc=1+ (rand()%9);return verc;}
        if(capitulo==48){int verc=1+ (rand()%14);return verc;}
        if(capitulo==49){int verc=1+ (rand()%20);return verc;}
        if(capitulo==50){int verc=1+ (rand()%23);return verc;}//50
        if(capitulo==51){int verc=1+ (rand()%19);return verc;}
        if(capitulo==52){int verc=1+ (rand()%9);return verc;}
        if(capitulo==53){int verc=1+ (rand()%6);return verc;}
        if(capitulo==54){int verc=1+ (rand()%7);return verc;}
        if(capitulo==55){int verc=1+ (rand()%23);return verc;}
        if(capitulo==56){int verc=1+ (rand()%13);return verc;}
        if(capitulo==57){int verc=1+ (rand()%11);return verc;}
        if(capitulo==58){int verc=1+ (rand()%11);return verc;}
        if(capitulo==59){int verc=1+ (rand()%17);return verc;}
        if(capitulo==60){int verc=1+ (rand()%12);return verc;}
        if(capitulo==61){int verc=1+ (rand()%8);return verc;}
        if(capitulo==62){int verc=1+ (rand()%12);return verc;}
        if(capitulo==63){int verc=1+ (rand()%11);return verc;}
        if(capitulo==64){int verc=1+ (rand()%10);return verc;}
        if(capitulo==65){int verc=1+ (rand()%13);return verc;}
        if(capitulo==66){int verc=1+ (rand()%20);return verc;}
        if(capitulo==67){int verc=1+ (rand()%7);return verc;}
        if(capitulo==68){int verc=1+ (rand()%35);return verc;}
        if(capitulo==69){int verc=1+ (rand()%36);return verc;}
        if(capitulo==70){int verc=1+ (rand()%5);return verc;}
        if(capitulo==71){int verc=1+ (rand()%24);return verc;}
        if(capitulo==72){int verc=1+ (rand()%20);return verc;}
        if(capitulo==73){int verc=1+ (rand()%28);return verc;}
        if(capitulo==74){int verc=1+ (rand()%23);return verc;}
        if(capitulo==75){int verc=1+ (rand()%10);return verc;}
        if(capitulo==76){int verc=1+ (rand()%12);return verc;}
        if(capitulo==77){int verc=1+ (rand()%20);return verc;}
        if(capitulo==78){int verc=1+ (rand()%72);return verc;}
        if(capitulo==79){int verc=1+ (rand()%13);return verc;}
        if(capitulo==80){int verc=1+ (rand()%19);return verc;}//80
        if(capitulo==81){int verc=1+ (rand()%16);return verc;}
        if(capitulo==82){int verc=1+ (rand()%8);return verc;}
        if(capitulo==83){int verc=1+ (rand()%18);return verc;}
        if(capitulo==84){int verc=1+ (rand()%12);return verc;}
        if(capitulo==85){int verc=1+ (rand()%13);return verc;}
        if(capitulo==86){int verc=1+ (rand()%17);return verc;}
        if(capitulo==87){int verc=1+ (rand()%7);return verc;}
        if(capitulo==88){int verc=1+ (rand()%18);return verc;}
        if(capitulo==89){int verc=1+ (rand()%52);return verc;}
        if(capitulo==90){int verc=1+ (rand()%17);return verc;}
        if(capitulo==91){int verc=1+ (rand()%16);return verc;}
        if(capitulo==92){int verc=1+ (rand()%15);return verc;}
        if(capitulo==93){int verc=1+ (rand()%5);return verc;}
        if(capitulo==94){int verc=1+ (rand()%23);return verc;}
        if(capitulo==95){int verc=1+ (rand()%11);return verc;}
        if(capitulo==96){int verc=1+ (rand()%13);return verc;}
        if(capitulo==97){int verc=1+ (rand()%12);return verc;}
        if(capitulo==98){int verc=1+ (rand()%9);return verc;}
        if(capitulo==99){int verc=1+ (rand()%9);return verc;}
        if(capitulo==100){int verc=1+ (rand()%5);return verc;}//100
        if(capitulo==101){int verc=1+ (rand()%8);return verc;}
        if(capitulo==102){int verc=1+ (rand()%28);return verc;}
        if(capitulo==103){int verc=1+ (rand()%22);return verc;}
        if(capitulo==104){int verc=1+ (rand()%35);return verc;}
        if(capitulo==105){int verc=1+ (rand()%45);return verc;}
        if(capitulo==106){int verc=1+ (rand()%48);return verc;}
        if(capitulo==107){int verc=1+ (rand()%43);return verc;}
        if(capitulo==108){int verc=1+ (rand()%13);return verc;}
        if(capitulo==109){int verc=1+ (rand()%31);return verc;}
        if(capitulo==110){int verc=1+ (rand()%7);return verc;}
        if(capitulo==111){int verc=1+ (rand()%10);return verc;}
        if(capitulo==112){int verc=1+ (rand()%10);return verc;}
        if(capitulo==113){int verc=1+ (rand()%9);return verc;}
        if(capitulo==114){int verc=1+ (rand()%7);return verc;}
        if(capitulo==115){int verc=1+ (rand()%18);return verc;}
        if(capitulo==116){int verc=1+ (rand()%19);return verc;}
        if(capitulo==117){int verc=1+ (rand()%2);return verc;}
        if(capitulo==118){int verc=1+ (rand()%29);return verc;}
        if(capitulo==119){int verc=1+ (rand()%176);return verc;}
        if(capitulo==120){int verc=1+ (rand()%7);return verc;}
        if(capitulo==121){int verc=1+ (rand()%8);return verc;}
        if(capitulo==122){int verc=1+ (rand()%9);return verc;}
        if(capitulo==123){int verc=1+ (rand()%4);return verc;}
        if(capitulo==124){int verc=1+ (rand()%8);return verc;}
        if(capitulo==125){int verc=1+ (rand()%6);return verc;}
        if(capitulo==126){int verc=1+ (rand()%6);return verc;}
        if(capitulo==127){int verc=1+ (rand()%5);return verc;}
        if(capitulo==128){int verc=1+ (rand()%5);return verc;}
        if(capitulo==129){int verc=1+ (rand()%8);return verc;}
        if(capitulo==130){int verc=1+ (rand()%8);return verc;}
        if(capitulo==131){int verc=1+ (rand()%3);return verc;}
        if(capitulo==132){int verc=1+ (rand()%18);return verc;}
        if(capitulo==133){int verc=1+ (rand()%3);return verc;}
        if(capitulo==134){int verc=1+ (rand()%3);return verc;}
        if(capitulo==135){int verc=1+ (rand()%21);return verc;}
        if(capitulo==136){int verc=1+ (rand()%26);return verc;}
        if(capitulo==137){int verc=1+ (rand()%9);return verc;}
        if(capitulo==138){int verc=1+ (rand()%8);return verc;}
        if(capitulo==139){int verc=1+ (rand()%24);return verc;}
        if(capitulo==140){int verc=1+ (rand()%13);return verc;}
        if(capitulo==141){int verc=1+ (rand()%10);return verc;}
        if(capitulo==142){int verc=1+ (rand()%7);return verc;}
        if(capitulo==143){int verc=1+ (rand()%12);return verc;}
        if(capitulo==144){int verc=1+ (rand()%15);return verc;}
        if(capitulo==145){int verc=1+ (rand()%20);return verc;}
        if(capitulo==146){int verc=1+ (rand()%10);return verc;}
        if(capitulo==147){int verc=1+ (rand()%20);return verc;}
        if(capitulo==148){int verc=1+ (rand()%14);return verc;}
        if(capitulo==149){int verc=1+ (rand()%9);return verc;}
        if(capitulo==150){int verc=1+ (rand()%6);return verc;}
    }
    //    if(chek_c==3){
    //        if(capitulo==2){
    //            int verc=1+ (rand()%2);
    //            if(verc==1){
    //                verc=1;
    //                return verc;
    //            }else{
    //                verc=2;
    //                return verc;
    //            }
    //        }
    //        if(capitulo==3){
    //            int verc = 1;
    //            return verc;
    //        }
    //        if(capitulo==4){
    //            int verc = 1;
    //            return verc;
    //        }
    //    }
    return -1;
}

int Dialog::mostrar_salva_struct(){
    int CAPITULO=gene_cap();
    c_v_s.first = CAPITULO;
    return c_v_s.first;
}

int Dialog::mostrar_salva_struct2(){
    int CAPITULO=gene_cap();
    c_v_s.first = CAPITULO;
    c_v_s.second = gene_verc(CAPITULO);
    return c_v_s.second;
}

void Dialog::on_GENERAR_clicked()
{
    if(ui->PROVERBIO->isChecked()){
        GENERAR_proverbio();
        wid->Progress_Sonido();
    }
    if(ui->SALMOS->isChecked()){
        GENERAR_salmo();
        wid->Progress_Sonido();
    }
    if(ui->ANTIGUOTESTAMENTO->isChecked()){
        //aun no se a realizado este metodo
        wid->Progress_Sonido();
    }
    //falton el antiguo testamento y el nuevo por poner
    if(ui->SELECCIONARTODO->isChecked()){
        GENERADOR_GENERAl();
        wid->Progress_Sonido();
    }
    //GENERADOR_GENERAl();//para si no hay nada seleccionado se genere el  metodo para generar todo
    conteo_maximo.second=-1;
}

void Dialog::GENERADOR_GENERAl()
{
    int r1,r2;
    r1=mostrar_salva_struct();
    r2=mostrar_salva_struct2();
    //emit elementoAgregado(c_v_s.first,chek_c);
    encender_menos_generar();
    encender_menos_generar_act();
    QVariant variante;
    variante.setValue<int>(r1);
    QString verc_strin = variante.value<QString>();
    QString cual;
    if(chek_c==1){
        cual="PRO";
    }
    else{
        cual="SALMOS";
    }
    txt= ".txt";
    QString direc = QString(":/%1/%2%3").arg(cual).arg(verc_strin).arg(txt);
    QFileDialog dialogo(this);
    dialogo.setAcceptMode(QFileDialog::AcceptOpen);
    dialogo.setFileMode(QFileDialog::AnyFile);
    QFile archivo(direc);
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!archivo.isOpen()){return;}

    QTextStream  str(&archivo);
    //if(checked && chek_c==1){

    tiempofuera();
//    if(chek_c ==1){
//        qDebug () <<"dialog:"<<"Cap= " << r1 << " y " <<"Verc_total = " << V_P_P_P[r1];
//    }else{
//        qDebug () <<"dialog:"<<"Cap= " << r1 << " y " <<"Verc_total = " << V_P_P_C[r1];
//    }

    for(int i=0;i</*verci*/r2 ;i++){
        list_contenido.append(str.readLine());
        conteo_maximo.first++;
    }
    list_contenido.append(str.readLine());
    //qDebug() << list_contenido[--conteo_maximo.first];
    if(!list_contenido[conteo_maximo.first].isEmpty()){//cuando tiene algo esta vacio
        ui->textEdit->setText(list_contenido[conteo_maximo.first]);

        emit elementoAgregado_QLIST(/*list_contenido,*/r1,/*V_P_P_P[r1-1],*/chek_c/*verci*/);

    }
    str.flush();
    archivo.flush();
    archivo.close();

}

void Dialog::GENERAR_proverbio()
{
    int r1,r2;
    r1=mostrar_salva_struct();
    r2=mostrar_salva_struct2();
    //emit elementoAgregado(c_v_s.first,chek_c);
    encender_menos_generar();
    encender_menos_generar_act();
    QVariant variante;
    variante.setValue<int>(r1);
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
    //if(checked && chek_c==1){

    tiempofuera();
    if(chek_c == 2 || chek_c == 3){ chek_c =1;}

    //r1=1;
    //switch(r1){
    //case 1:
    //qDebug () <<"dialog:"<<"Cap= " << r1 << " y " <<"Verc_total = " << V_P_P_P[r1];
    //        int verci = V_P_P_P[r1-1];
    for(int i=0;i</*verci*/r2 ;i++){
        list_contenido.append(str.readLine());
        conteo_maximo.first++;
    }
    list_contenido.append(str.readLine());
    //qDebug() << list_contenido[--conteo_maximo.first];
    if(!list_contenido[conteo_maximo.first].isEmpty()){//cuando tiene algo esta vacio
        ui->textEdit->setText(list_contenido[conteo_maximo.first]);

        emit elementoAgregado_QLIST(/*list_contenido,*/r1,/*V_P_P_P[r1-1],*/chek_c/*verci*/);

    }
    str.flush();
    archivo.flush();
    archivo.close();

}

void Dialog::GENERAR_salmo()
{
    int r1,r2;
    r1=mostrar_salva_struct();
    r2=mostrar_salva_struct2();
    //emit elementoAgregado(c_v_s.first,chek_c);
    encender_menos_generar();
    encender_menos_generar_act();
    QVariant variante;
    variante.setValue<int>(r1);
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

    tiempofuera();
    if(chek_c == 1 || chek_c == 3){ chek_c =2;}

    //qDebug () <<"dialog:"<<"Cap= " << r1 << " y " <<"Verc_total = " << V_P_P_C[r1];
    for(int i=0;i</*verci*/r2 ;i++){
        list_contenido.append(str.readLine());
        conteo_maximo.first++;
    }
    list_contenido.append(str.readLine());
    if(!list_contenido[conteo_maximo.first].isEmpty()){//cuando tiene algo esta vacio
        ui->textEdit->setText(list_contenido[conteo_maximo.first]);
        emit elementoAgregado_QLIST(/*list_contenido,*/r1,/*V_P_P_P[r1-1],*/chek_c/*verci*/);
    }
    str.flush();
    archivo.flush();
    archivo.close();

}

void Dialog::GENERAR_antiguotestamento()
{
    int r1,r2;
    r1=mostrar_salva_struct();
    r2=mostrar_salva_struct2();
    //emit elementoAgregado(c_v_s.first,chek_c);
    encender_menos_generar();
    encender_menos_generar_act();
    QVariant variante;
    variante.setValue<int>(r1);
    QString verc_strin = variante.value<QString>();
    QString txt= ".txt";
    QString direc = QString(":/AT/%1%2").arg(verc_strin).arg(txt);
    QFileDialog dialogo(this);
    dialogo.setAcceptMode(QFileDialog::AcceptOpen);
    dialogo.setFileMode(QFileDialog::AnyFile);
    QFile archivo(direc);
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!archivo.isOpen()){return;}

    QTextStream  str(&archivo);

    switch(r1){
    case 1:
        for(int i=0;i<r2;i++){
            list_contenido.append(str.readLine());
            conteo_maximo.first++;
        }
        //list_contenido.append(str.readLine());
        list_contenido.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->textEdit->setText(list_contenido[--conteo_maximo.first]);
        list_all.append(list_contenido[--conteo_maximo.first]);
        break;break;
    case 2:
        for(int i=0;i<r2;i++){
            list_contenido.append(str.readLine());
            conteo_maximo.first++;
        }
        //list_contenido.append(str.readLine());
        list_contenido.append(str.readLine());
        str.flush();
        archivo.flush();
        archivo.close();
        ui->textEdit->setText(list_contenido[--conteo_maximo.first]);
        list_all.append(list_contenido[--conteo_maximo.first]);
        break;break;
    }
}

void Dialog::on_UNOMAS_clicked()
{
    ++conteo_maximo.second;
    if(conteo_maximo.second==3){
        wid->Button_adelante_sonido();
        ui->UNOMAS->setEnabled(false);
        UnomasAct->setEnabled(false);
        conteo_maximo.second=0;
    }
    else{
        ui->textEdit->setText(list_contenido[++conteo_maximo.first]);
        wid->Button_adelante_sonido();
    }
}

void Dialog::on_UNOATRAS_clicked()
{
    ++conteo_maximo.second;
    if(conteo_maximo.second==3){
        //ui->UNOMAS->setEnabled(false);
        UnoatrasAct->setEnabled(false);
        wid->Button_atras_sonido();
    }
    else{
        ui->textEdit->setText(list_contenido[--conteo_maximo.first]);
        wid->Button_atras_sonido();
    }
}

void Dialog::on_GUARDAR_clicked()
{
    //timer->stop();
    //Definimos los filtros para el guardado:
    QStringList filters;
    filters << "Archivo de Texto (*.txt)"<< "Otros Archivo (*)";
    QFileDialog dialogo(this);
    //introducimos los filtros en el dialogo de guardar
    dialogo.setNameFilters(filters);

    QString nombreArchivo= dialogo.getSaveFileName(this, tr("Guardar"),list_contenido[conteo_maximo.first].left(9),tr("Archivo de Texto (*.txt);;Otros Archivo (*)"));
    if (nombreArchivo != "") {
        QFile archivo(nombreArchivo);
        if (!archivo.open(QIODevice::WriteOnly)) {
            QMessageBox msgBox;
            msgBox.setWindowTitle(tr("Guardar"));
            msgBox.setText(tr("Error al guardar"));
            msgBox.exec();
        } else {
            QTextStream stream(&archivo);
            stream << ui->textEdit->toPlainText();
            stream.flush();
            archivo.close();
        }
    }
}

void Dialog::on_LIMPIAR_clicked()
{
    //emit elementoAgregadoSonido("2");
    ui->textEdit->clear();
    //list_contenido.clear();
    ui->UNOMAS->setEnabled(false);
    ui->GUARDAR->setEnabled(false);
    UnomasAct->setEnabled(false);
    GuardarAct->setEnabled(false);
    //PausaAct->setEnabled(false);
}

void Dialog::on_SALIR_clicked()
{
    close();
}

void Dialog::tiempofuera()
{
    static short valor = 0;//el valor tiene que ser static para que se mantenga vivo
    ui->progressBar->setValue(valor);

    ++valor;
    if(valor == 100){
        valor=0;
        if(!valor){
            if(ui->PROVERBIO->isChecked())GENERAR_proverbio();wid->Progress_Sonido();
            if(ui->SALMOS->isChecked())GENERAR_salmo();wid->Progress_Sonido();
            if(ui->SELECCIONARTODO->isChecked())GENERADOR_GENERAl();wid->Progress_Sonido();
            if(ui->SELECCIONARTODO->isChecked())GENERAR_antiguotestamento();wid->Progress_Sonido();
            //if(ui->SELECCIONARTODO->isChecked())GENERAR_nuevotestamento();
        }
    }
}

void Dialog::tiempoStart()
{
    //    StartAct->setEnabled(false);
    //    PausaAct->setEnabled(true);
    timer->start(marc_SELCTODO_time.second);
    disable_pause();
}
void Dialog::tiempoStart1()
{
    //marc_SELCTODO_time.second = 10;
    timer->start(marc_SELCTODO_time.second);
    //    StartAct->setEnabled(false);
    //    PausaAct->setEnabled(true);
    disable_pause();
    actualizar_seg1();
}
void Dialog::tiempoStart2()
{
    //marc_SELCTODO_time.second = 20;
    timer->start(marc_SELCTODO_time.second);
    //    StartAct->setEnabled(false);
    //    PausaAct->setEnabled(true);
    disable_pause();
    actualizar_seg2();
}
void Dialog::tiempoStart3()
{
    //marc_SELCTODO_time.second = 30;
    timer->start(marc_SELCTODO_time.second);
    //    StartAct->setEnabled(false);
    //    PausaAct->setEnabled(true);
    disable_pause();
    actualizar_seg3();
}

void Dialog::tiempoStart4()
{
    //marc_SELCTODO_time.second = 40;
    timer->start(marc_SELCTODO_time.second);
    //    StartAct->setEnabled(false);
    //    PausaAct->setEnabled(true);
    disable_pause();
    actualizar_defaul();
}

void Dialog::tiempoStop()
{
    timer->stop();
    //    StartAct->setEnabled(true);
    //    PausaAct->setEnabled(false);
    disable_start();
}

void Dialog::tiempoReset()
{
    timer->stop();
    timer->destroyed();
    disable_pause();
    if(seg1Act->isChecked()==false && seg2Act->isChecked()==false && seg3Act->isChecked()==false && defaulAct->isChecked()==false){
        ui->STARTBUTTON->setDisabled(true);
        StartAct->setDisabled(true);}
    ui->textEdit->clear();
    ui->progressBar->reset();
    on_LIMPIAR_clicked();

}

void Dialog::on_COLOR_clicked()
{
    if (ui->COLOR->isChecked())
        col_font.first = QColorDialog::getColor(Qt::black, this);
    else
        col_font.first = QColorDialog::getColor(Qt::black, this, "Color", QColorDialog::DontUseNativeDialog);
    if (col_font.first.isValid()) {
        ui->labelCOLOR->setText(col_font.first.name());
        ui->labelCOLOR->setPalette(QPalette(col_font.first));
        ui->textEdit->selectAll();
        ui->textEdit->setTextColor(col_font.first);//para poner el color cambiado en el textedit
        ui->labelCOLOR->setAutoFillBackground(true);
       // guardar_ajustes_color_fuente();
    }
}

void Dialog::on_FUENTE_2_clicked()
{
    bool ok;
    col_font.second = QFontDialog::getFont(&ok, QFont(ui->labelFUENTE->text()),this,(tr("Fuente")));
    if (ok) {
        ui->labelFUENTE->setText(col_font.second.key());
        ui->labelFUENTE->setFont(col_font.second);
        ui->textEdit->setFont(col_font.second);
        //col_font.second.setPixelSize(9);
        guardar_ajustes_color_fuente();
    }
}

void Dialog::on_PROVERBIO_toggled(bool checked)
{
    if(!checked){
        int r1,r2;
        r1=mostrar_salva_struct();
        r2=mostrar_salva_struct2();
        //emit elementoAgregado(c_v_s.first,chek_c);
        encender_menos_generar();
        encender_menos_generar_act();
        QVariant variante;
        variante.setValue<int>(r1);
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
        //if(checked && chek_c==1){

        tiempofuera();
        if(chek_c == 2 || chek_c == 3){ chek_c =1;}

        //r1=1;
        //switch(r1){
        //case 1:
        qDebug () <<"dialog:"<<"Cap= " << r1 << " y " <<"Verc_total = " << V_P_P_P[r1];
        //        int verci = V_P_P_P[r1-1];
        for(int i=0;i</*verci*/r2 ;i++){
            list_contenido.append(str.readLine());
            conteo_maximo.first++;
        }
        list_contenido.append(str.readLine());
        //qDebug() << list_contenido[--conteo_maximo.first];
        if(!list_contenido[conteo_maximo.first].isEmpty()){//cuando tiene algo esta vacio
            ui->textEdit->setText(list_contenido[conteo_maximo.first]);

            emit elementoAgregado_QLIST(/*list_contenido,*/r1,/*V_P_P_P[r1-1],*/chek_c/*verci*/);

        }
        str.flush();
        archivo.flush();
        archivo.close();

    }
}

void Dialog::on_SALMOS_toggled(bool checked)
{
    if(!checked){
        int r1,r2;
        r1=mostrar_salva_struct();
        r2=mostrar_salva_struct2();
        //emit elementoAgregado(c_v_s.first,chek_c);
        encender_menos_generar();
        encender_menos_generar_act();
        QVariant variante;
        variante.setValue<int>(r1);
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

        tiempofuera();
        if(chek_c == 1 || chek_c == 3){ chek_c =2;//}

            qDebug () <<"dialog:"<<"Cap= " << r1 << " y " <<"Verc_total = " << V_P_P_C[r1];
            for(int i=0;i</*verci*/r2 ;i++){
                list_contenido.append(str.readLine());
                conteo_maximo.first++;
            }
            list_contenido.append(str.readLine());
            if(!list_contenido[conteo_maximo.first].isEmpty()){//cuando tiene algo esta vacio
                ui->textEdit->setText(list_contenido[conteo_maximo.first]);
                emit elementoAgregado_QLIST(/*list_contenido,*/r1,/*V_P_P_P[r1-1],*/chek_c/*verci*/);
            }
            str.flush();
            archivo.flush();
            archivo.close();
        }

    }
}

void Dialog::createActions()
{
    GenerarAct = new QAction(QIcon(":/Iconos/unomas.png"),tr("&Generar"), this);
    connect(GenerarAct, SIGNAL(triggered()), this, SLOT(on_GENERAR_clicked()));

    UnomasAct = new QAction (QIcon(":/Iconos/next.png"),tr("&Uno mas"), this);
    connect(UnomasAct, SIGNAL(triggered()), this, SLOT(on_UNOMAS_clicked()));

    UnoatrasAct = new QAction (QIcon(":/Iconos/back.png"),tr("&Uno atras"), this);
    connect(UnoatrasAct, SIGNAL(triggered()), this, SLOT(on_UNOATRAS_clicked()));

    GuardarAct = new QAction (QIcon(":/Iconos/savee.png"),tr("Guardar"), this);
    connect(GuardarAct, SIGNAL(triggered()), this, SLOT(on_GUARDAR_clicked()));

    LimpiarAct = new QAction (QIcon(":/Iconos/erase.png"),tr("Limpiar"), this);
    connect(LimpiarAct, SIGNAL(triggered()), this, SLOT(on_LIMPIAR_clicked()));

    StartAct = new QAction(QIcon(":/Iconos/play16.png"),tr("Start"),this);
    connect(StartAct, SIGNAL(triggered()), this, SLOT(on_STARTBUTTON_clicked()));

    PausaAct = new QAction(QIcon(":/Iconos/stop.png"),tr("Stop"),this);
    connect(PausaAct, SIGNAL(triggered()), this, SLOT(on_PAUSEBUTTON_clicked()));

    ResetAct = new QAction(QIcon(":/Iconos/reset.png"),tr("Reset"),this);
    connect(ResetAct, SIGNAL(triggered()), this, SLOT(on_RESETBUTTON_clicked()));

    SalirAct = new QAction (QIcon(":/Iconos/salida.png"),tr("Salir"), this);
    connect(SalirAct, SIGNAL(triggered()), this, SLOT(on_SALIR_clicked()));

    seg1Act = new QAction (/*QIcon(":/Iconos/salida.png"),*/tr("1seg"), this);
    seg1Act->setCheckable(true);//para que se pueda marcar el action
    connect(seg1Act, SIGNAL(triggered()), this, SLOT(tiempoStart1()));

    seg2Act = new QAction (/*QIcon(":/Iconos/salida.png"),*/tr("2seg"), this);
    seg2Act->setCheckable(true);//para que se pueda marcar el action
    connect(seg2Act, SIGNAL(triggered()), this, SLOT(tiempoStart2()));

    seg3Act = new QAction (/*QIcon(":/Iconos/salida.png"),*/tr("3seg"), this);
    seg3Act->setCheckable(true);//para que se pueda marcar el action
    connect(seg3Act, SIGNAL(triggered()), this, SLOT(tiempoStart3()));

    defaulAct = new QAction (/*QIcon(":/Iconos/salida.png"),*/tr("default"), this);
    defaulAct->setCheckable(true);//para que se pueda marcar el action
    connect(defaulAct, SIGNAL(triggered()), this, SLOT(tiempoStart4()));

    saveallAct = new QAction (QIcon(":/Iconos/save.png"),tr("Guardar Config"), this);
    connect(saveallAct, SIGNAL(triggered()), this, SLOT(on_GUARDARAGENERAR_clicked()));
}
void Dialog::updateRGB()
{
    auto p = palette();
                        //Text, cambia el color no solo del texto del textedit sino tambien del seleccionadr de a generar
    p.setColor(QPalette::BrightText,QColor(mColor));
    setPalette(p);
    col_font.first = mColor;
    ui->textEdit->selectAll();
    ui->textEdit->setTextColor(col_font.first);
   // ui->labelCOLOR->setPalette(QPalette(col_font.first));
    //ui->labelCOLOR->setAutoFillBackground(true);//para que se colore el fondo del label y no solo el borde
    //guardar_ajustes_color_fuente();
    emit elementoColorRGB(col_font.first);
}

void Dialog::wheelEvent(QWheelEvent *e)
{
    //QString result;
    if (e->delta() > 0) {

        if (e->orientation() == Qt::Vertical) {
            //result = "Mouse Rueda Event: UP";
            Conteo_Rueda++;
            //ui->textEdit->selectAll();
            ui->textEdit->setFontPointSize(Conteo_Rueda);
        } else {
            //result = "Mouse Rueda Event: LEFT";
        }
    } else if (e->delta() < 0) {
        if (e->orientation() == Qt::Vertical) {
            //result = "Mouse Rueda Event: DOWN";
                Conteo_Rueda=12;
            //ui->textEdit->selectAll();
            ui->textEdit->setFontPointSize(12);
        } else {
            //result = "Mouse Rueda Event: RIGHT";
        }
    }
    //qDebug() << result<<"Conteo= "<<Conteo_Rueda;
    //    this->setText(result);
}

void Dialog::on_textEdit_customContextMenuRequested()
{
    wid->Menu_context_sonido();
    QMenu menu(this);
    menu.addAction(UnoatrasAct);
    menu.addAction(GenerarAct);
    menu.addAction(UnomasAct);
    menu.addAction(LimpiarAct);
    menu.addSeparator();
    //menu.addAction();
    menu.addAction(StartAct);
    menu.addAction(PausaAct);
    menu.addAction(ResetAct);
    menu.addAction(StartAct);
    menu.addAction(PausaAct);
    menu.addAction(ResetAct);
    menu.addSeparator();
    actions_LIST.append(seg1Act);
    actions_LIST.append(seg2Act);
    actions_LIST.append(seg3Act);
    actions_LIST.append(defaulAct);
    //actions_LIST.append(saveAct);
    menu.addMenu(QIcon(":/Iconos/tm-pl.png"),tr("generar en"))->addActions(actions_LIST);
    menu.addAction(GuardarAct);
    menu.addAction(saveallAct);
    menu.addSeparator();
    menu.addAction(SalirAct);
    menu.exec(QCursor::pos());

}

void Dialog::on_moreButton_toggled(bool checked)
{
    ui->widget->setVisible(checked);
    wid->Button_More();
}

void Dialog::SELECCIONARTODO()
{
    tiempoReset();
    timer->start();
    disable_pause();//aqui no se pone el disable_start
    ui->PROVERBIO->setChecked(true);
    ui->SALMOS->setChecked(true);
    ui->NUEVOTESTAMNETO->setChecked(true);
    ui->ANTIGUOTESTAMENTO->setChecked(true);
    //PARA desavilitar el boton:
    ui->PROVERBIO->setDisabled(true);
    ui->SALMOS->setDisabled(false);
    ui->NUEVOTESTAMNETO->setDisabled(true);
    ui->ANTIGUOTESTAMENTO->setDisabled(true);
}

void Dialog::on_ACERCADE_clicked()
{
    timer->stop();
    const QString texto = "\nAutor: Ricardo Anavitarte Lopez\nCompañía: AnySofG\nCorreo: ricardoanavitarte22@gmail.com";
    QMessageBox::about(this,"Acerca de...",texto);
    //timer->start();
    //esta activacion de acciones es necesaria porque se pausamos y damos al acerca de y dmos ok se activa el temporizador y no nos deja detenerlo
    disable_pause();
}

void Dialog::cargar_ajustes()
{
    //para los ajustes de a generar
    QSettings ajustes;
    ajustes.beginGroup("A_Generar");//para comenzar el grupo
    marc_PRO_SAL.first = ajustes.value("Proverbio",marc_PRO_SAL.first).toBool();//qui se va a cargar lo que se guarde en los ajustes
    marc_PRO_SAL.second = ajustes.value("Salmos",marc_PRO_SAL.second).toBool();
    marc_AT_NT.first = ajustes.value("Antiguo Testamento",marc_AT_NT.first).toBool();
    marc_AT_NT.second = ajustes.value("Nuevo Testamento",marc_AT_NT.second).toBool();
    marc_SELCTODO_time.first= ajustes.value("Selec.Todo",marc_SELCTODO_time.first).toBool();
    marc_SELCTODO_time.second= ajustes.value("time", marc_SELCTODO_time.second).toInt();

    ui->PROVERBIO->setChecked(marc_PRO_SAL.first);
    ui->SALMOS->setChecked(marc_PRO_SAL.second);
    ui->ANTIGUOTESTAMENTO->setChecked(marc_AT_NT.first);
    ui->NUEVOTESTAMNETO->setChecked(marc_AT_NT.second);
    ui->SELECCIONARTODO->setChecked(marc_SELCTODO_time.first);
    //marc_SELCTODO_time.second = marc_SELCTODO_time.second;

    //para cuando se cargue lo guardado en a generar si es sele.todod salgan los demas chekbox desavilitados:
    if(ui->SELECCIONARTODO->isChecked()){
        ui->SELECCIONARTODO->setChecked(marc_SELCTODO_time.first);
        ui->PROVERBIO->setDisabled(true);
        ui->SALMOS->setDisabled(false);
        ui->ANTIGUOTESTAMENTO->setDisabled(true);
        ui->NUEVOTESTAMNETO->setDisabled(true);
    }
    if(ui->NUEVOTESTAMNETO->isChecked()){
        ui->NUEVOTESTAMNETO->setChecked(marc_AT_NT.second);
        ui->PROVERBIO->setDisabled(true);
        ui->SALMOS->setDisabled(true);
        ui->ANTIGUOTESTAMENTO->setDisabled(true);
        ui->SELECCIONARTODO->setDisabled(true);
    }
    if(ui->ANTIGUOTESTAMENTO->isChecked()){
        ui->ANTIGUOTESTAMENTO->setChecked(marc_AT_NT.first);
        ui->PROVERBIO->setDisabled(true);
        ui->SALMOS->setDisabled(true);
        ui->NUEVOTESTAMNETO->setDisabled(true);
        ui->SELECCIONARTODO->setDisabled(true);
    }
    if(ui->SALMOS->isChecked()){
        ui->SALMOS->setChecked(marc_PRO_SAL.second);
        ui->PROVERBIO->setDisabled(true);
        ui->ANTIGUOTESTAMENTO->setDisabled(true);
        ui->NUEVOTESTAMNETO->setDisabled(true);
        ui->SELECCIONARTODO->setDisabled(true);
    }
    if(ui->PROVERBIO->isChecked()){
        ui->PROVERBIO->setChecked(marc_PRO_SAL.first);
        ui->SALMOS->setDisabled(true);
        ui->ANTIGUOTESTAMENTO->setDisabled(true);
        ui->NUEVOTESTAMNETO->setDisabled(true);
        ui->SELECCIONARTODO->setDisabled(true);
    }

    ajustes.endGroup();
}

void Dialog::guardar_ajustes()
{
    QSettings ajustes;
    ajustes.beginGroup("A_Generar");//para comenzar el grupo
    marc_PRO_SAL.first = ui->PROVERBIO->isChecked();
    marc_PRO_SAL.second = ui->SALMOS->isChecked();
    marc_AT_NT.first = ui->ANTIGUOTESTAMENTO->isChecked();
    marc_AT_NT.second = ui->NUEVOTESTAMNETO->isChecked();
    marc_SELCTODO_time.first= ui->SELECCIONARTODO->isChecked();


    ajustes.setValue("Proverbio", marc_PRO_SAL.first);
    ajustes.setValue("Salmos", marc_PRO_SAL.second);
    ajustes.setValue("Antiguo Testamento",marc_AT_NT.first);
    ajustes.setValue("Nuevo Testamento",marc_AT_NT.second);
    ajustes.setValue("Selec.Todo", marc_SELCTODO_time.first);

    ajustes.endGroup();
}

void Dialog::cargar_ajustes_color_fuente()
{
    QSettings ajustes_color_fuente;
    ajustes_color_fuente.beginGroup("color_fuente");
    /*QColor col1*/col_font.first=ajustes_color_fuente.value("color",col_font.first).value<QColor>();
    //ajustes_color_fuente.setValue("col1", col1);
    col_font.second = ajustes_color_fuente.value("font",col_font.second).value<QFont>();
    ajustes_color_fuente.setValue("font",col_font.second);
    ui->textEdit->selectAll();
    ui->textEdit->setTextColor(/*col1*/col_font.first);
    ui->textEdit->setFont(col_font.second);
    ajustes_color_fuente.endGroup();
}

void Dialog::guardar_ajustes_color_fuente()
{
    QSettings ajustes_color_fuente;
    ajustes_color_fuente.beginGroup("color_fuente");
    ajustes_color_fuente.setValue("color", col_font.first);
    ajustes_color_fuente.setValue("font",col_font.second);
    ajustes_color_fuente.endGroup();
}

void Dialog::on_GUARDARAGENERAR_clicked()
{
    guardar_ajustes();
    timer->stop();
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Ajustes Guardados"));
    msgBox.setText(tr("Se a guardado los ajustes."));
    msgBox.exec();
}

void Dialog::on_GENERAR_customContextMenuRequested()
{
    QMenu menu3(this);
    menu3.addAction(UnoatrasAct);
    menu3.addAction(GenerarAct);
    menu3.addAction(UnomasAct);
    menu3.exec(QCursor::pos());
}

void Dialog::on_UNOMAS_customContextMenuRequested()
{
    QMenu menu4(this);
    menu4.addAction(UnoatrasAct);
    menu4.addAction(UnomasAct);
    menu4.exec(QCursor::pos());
}

void Dialog::on_GUARDAR_customContextMenuRequested()
{
    QMenu menu5(this);
    menu5.addAction(GuardarAct);
    menu5.exec(QCursor::pos());
}

void Dialog::on_LIMPIAR_customContextMenuRequested()
{
    QMenu menu6(this);
    menu6.addAction(LimpiarAct);
    menu6.exec(QCursor::pos());
}

void Dialog::on_SALIR_customContextMenuRequested()
{
    QMenu menu7(this);
    menu7.addAction(SalirAct);
    menu7.exec(QCursor::pos());
}

void Dialog::on_moreButton_customContextMenuRequested()
{
    QMenu menu8(this);
    menu8.addAction(SalirAct);
    menu8.exec(QCursor::pos());
}

void Dialog::on_progressBar_customContextMenuRequested()
{
    bool ok=ui->PAUSEBUTTON->isChecked();
    if(ok){
        disable_pause();
    }
    QMenu menu9(this);
    menu9.addAction(StartAct);
    menu9.addAction(PausaAct);
    menu9.addAction(ResetAct);
    menu9.addAction(StartAct);
    menu9.addAction(PausaAct);
    menu9.addAction(ResetAct);
    menu9.addSeparator();
    actions_LIST.append(seg1Act);
    actions_LIST.append(seg2Act);
    actions_LIST.append(seg3Act);
    actions_LIST.append(defaulAct);
    //actions_LIST.append(saveAct);
    menu9.addMenu(QIcon(":/Iconos/tm-pl.png"),tr("generar en"))->addActions(actions_LIST);
    menu9.exec(QCursor::pos());
}

void Dialog::on_STARTBUTTON_clicked()
{
    tiempoStart();
    disable_start();
}

void Dialog::on_PAUSEBUTTON_clicked()
{
    tiempoStop();
    disable_pause();
}

void Dialog::on_RESETBUTTON_clicked()
{

    tiempoReset();
}

void Dialog::on_READALL_clicked()
{
    read->exec();
}

void Dialog::on_SELECCIONARTODO_clicked(bool checked)
{
    if(checked){
        tiempoReset();
        timer->start();
        disable_start();
        ui->PAUSEBUTTON->setDisabled(false);
        ui->PROVERBIO->setChecked(true);
        ui->SALMOS->setChecked(true);
        ui->NUEVOTESTAMNETO->setChecked(true);
        ui->ANTIGUOTESTAMENTO->setChecked(true);
        //PARA desavilitar el boton:
        ui->PROVERBIO->setDisabled(true);
        ui->SALMOS->setDisabled(true);
        ui->NUEVOTESTAMNETO->setDisabled(true);
        ui->ANTIGUOTESTAMENTO->setDisabled(true);
    }
    if(!checked){//cuando se marque
        tiempoReset();
        timer->stop();
        ui->textEdit->clear();
        //este p[uede ser un futuro error esta puesto que si no hay nada seleccionado en a generar se quede los botones igual a si todo estubiese seleccciona
        disable_start();
        ui->PAUSEBUTTON->setDisabled(true);
        ui->PROVERBIO->setChecked(false);
        ui->SALMOS->setChecked(false);
        ui->NUEVOTESTAMNETO->setChecked(false);
        ui->ANTIGUOTESTAMENTO->setChecked(false);
        //PARA habilitar el boton:
        ui->PROVERBIO->setDisabled(false);
        ui->SALMOS->setDisabled(false);
        ui->NUEVOTESTAMNETO->setDisabled(false);
        ui->ANTIGUOTESTAMENTO->setDisabled(false);
    }
}

void Dialog::on_PROVERBIO_clicked(bool checked)
{
    if(checked){
        tiempoReset();
        timer->start();
        disable_start();
        ui->SALMOS->setChecked(false);
        ui->SELECCIONARTODO->setChecked(false);
        ui->NUEVOTESTAMNETO->setChecked(false);
        ui->ANTIGUOTESTAMENTO->setChecked(false);
        //PARA desavilitar el boton:
        ui->SELECCIONARTODO->setDisabled(true);
        ui->SALMOS->setDisabled(true);
        ui->NUEVOTESTAMNETO->setDisabled(true);
        ui->ANTIGUOTESTAMENTO->setDisabled(true);
    }
    if(!checked){//cuando se marque
        tiempoReset();
        timer->stop();
        ui->textEdit->clear();
        //este p[uede ser un futuro error esta puesto que si no hay nada seleccionado en a generar se quede los botones igual a si todo estubiese seleccciona
        disable_start();
        ui->PAUSEBUTTON->setDisabled(true);
        ui->SALMOS->setChecked(false);
        ui->SELECCIONARTODO->setChecked(false);
        ui->NUEVOTESTAMNETO->setChecked(false);
        ui->ANTIGUOTESTAMENTO->setChecked(false);
        //PARA habilitar el boton:
        ui->SELECCIONARTODO->setDisabled(false);
        ui->SALMOS->setDisabled(false);
        ui->NUEVOTESTAMNETO->setDisabled(false);
        ui->ANTIGUOTESTAMENTO->setDisabled(false);
    }
}

void Dialog::on_SALMOS_clicked(bool checked)
{
    if(checked){
        tiempoReset();
        timer->start();
        disable_start();
        ui->PROVERBIO->setChecked(false);
        ui->SELECCIONARTODO->setChecked(false);
        ui->NUEVOTESTAMNETO->setChecked(false);
        ui->ANTIGUOTESTAMENTO->setChecked(false);
        //PARA desavilitar el boton:
        ui->SELECCIONARTODO->setDisabled(true);
        ui->PROVERBIO->setDisabled(true);
        ui->NUEVOTESTAMNETO->setDisabled(true);
        ui->ANTIGUOTESTAMENTO->setDisabled(true);
    }
    if(!checked){//cuando se marque
        tiempoReset();
        timer->stop();
        ui->textEdit->clear();
        //este p[uede ser un futuro error esta puesto que si no hay nada seleccionado en a generar se quede los botones igual a si todo estubiese seleccciona
        disable_start();
        ui->PAUSEBUTTON->setDisabled(true);
        ui->PROVERBIO->setChecked(false);
        ui->SELECCIONARTODO->setChecked(false);
        ui->NUEVOTESTAMNETO->setChecked(false);
        ui->ANTIGUOTESTAMENTO->setChecked(false);
        //PARA habilitar el boton:
        ui->SELECCIONARTODO->setDisabled(false);
        ui->PROVERBIO->setDisabled(false);
        ui->NUEVOTESTAMNETO->setDisabled(false);
        ui->ANTIGUOTESTAMENTO->setDisabled(false);
    }
}

void Dialog::on_ANTIGUOTESTAMENTO_clicked(bool checked)
{
    if(checked){//cuando se marca
        tiempoReset();
        timer->start();
        disable_start();
        ui->SALMOS->setChecked(false);
        ui->PROVERBIO->setChecked(false);
        ui->SELECCIONARTODO->setChecked(false);
        ui->NUEVOTESTAMNETO->setChecked(false);
        //PARA desavilitar el boton:
        ui->SALMOS->setDisabled(true);
        ui->SELECCIONARTODO->setDisabled(true);
        ui->PROVERBIO->setDisabled(true);
        ui->NUEVOTESTAMNETO->setDisabled(true);
    }
    if(!checked){//cuando se desmarque
        tiempoReset();
        timer->stop();
        ui->textEdit->clear();
        //este p[uede ser un futuro error esta puesto que si no hay nada seleccionado en a generar se quede los botones igual a si todo estubiese seleccciona
        disable_start();
        ui->PAUSEBUTTON->setDisabled(true);
        ui->SALMOS->setDisabled(false);
        ui->PROVERBIO->setChecked(false);
        ui->SELECCIONARTODO->setChecked(false);
        ui->NUEVOTESTAMNETO->setChecked(false);
        //PARA habilitar el boton:
        ui->SALMOS->setDisabled(false);
        ui->SELECCIONARTODO->setDisabled(false);
        ui->PROVERBIO->setDisabled(false);
        ui->NUEVOTESTAMNETO->setDisabled(false);
    }
}

void Dialog::on_NUEVOTESTAMNETO_clicked(bool checked)
{
    if(checked){
        tiempoReset();
        timer->start();
        disable_start();
        ui->SALMOS->setChecked(false);
        ui->PROVERBIO->setChecked(false);
        ui->SELECCIONARTODO->setChecked(false);
        ui->ANTIGUOTESTAMENTO->setChecked(false);
        //PARA desavilitar el boton:
        ui->SALMOS->setDisabled(true);
        ui->SELECCIONARTODO->setDisabled(true);
        ui->PROVERBIO->setDisabled(true);
        ui->ANTIGUOTESTAMENTO->setDisabled(true);
    }
    if(!checked){//cuando se marque
        tiempoReset();
        timer->stop();
        ui->textEdit->clear();
        //este p[uede ser un futuro error esta puesto que si no hay nada seleccionado en a generar se quede los botones igual a si todo estubiese seleccciona
        disable_start();
        ui->PAUSEBUTTON->setDisabled(true);
        ui->SALMOS->setDisabled(true);
        ui->PROVERBIO->setChecked(false);
        ui->SELECCIONARTODO->setChecked(false);
        ui->ANTIGUOTESTAMENTO->setChecked(false);
        //PARA habilitar el boton:
        ui->SALMOS->setDisabled(false);
        ui->SELECCIONARTODO->setDisabled(false);
        ui->PROVERBIO->setDisabled(false);
        ui->ANTIGUOTESTAMENTO->setDisabled(false);
    }
}

void Dialog::on_Slider_Size_valueChanged(int value)
{
    ui->textEdit->selectAll();
    ui->textEdit->setFontPointSize(value);
}
