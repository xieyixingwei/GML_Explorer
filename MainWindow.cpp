#include "MainWindow.h"
#include "ItemGml.h"
#include "Gml.h"
#include "Item.h"
#include <QTabWidget>
#include <QMenuBar>
#include <QMenu>
#include <QTextEdit>
#include <QTabBar>
#include <QFrame>
#include <QLabel>
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QProgressBar>
#include <QComboBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QFileDialog>
#include <QString>
#include <QChar>
#include <QDebug>
#include <QTextStream>
#include <QAction>
#include <QBoxLayout>

struct ui {
    QMenuBar *menubar;
    QMenu *menu_file;
    QAction *act_importgml;
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(nullptr),
    m_gml(nullptr)
{
    m_ui = new struct ui;
    m_ui->menubar = this->menuBar();
    m_ui->menu_file = m_ui->menubar->addMenu(tr("File"));
    m_ui->act_importgml = m_ui->menu_file->addAction(tr("Import GML"));

    connect(m_ui->act_importgml, SIGNAL(triggered(bool)), this, SLOT(ImportGml_Slot()));
#if 0
    QTabWidget *tab_widget = new QTabWidget;
    this->setCentralWidget(tab_widget);

    QFrame* pFrame = new QFrame;
    tab_widget->addTab(pFrame, "tab");

    QHBoxLayout *mlayout = new QHBoxLayout(pFrame);

    QGroupBox* gbox = new QGroupBox;
    gbox->setStyleSheet("QGroupBox{border:none;}");
    mlayout->addWidget(gbox);

    QHBoxLayout *layout = new QHBoxLayout(gbox);

    QLabel* pLabel1 = new QLabel("label1");
    layout->addWidget(pLabel1, 0);

    QPushButton* pBtn1 = new QPushButton("test");
    layout->addWidget(pBtn1, 1);

    QPalette palette = pBtn1->palette();
    palette.setColor(QPalette::Button, Qt::black);//QColor(std::stoi(color, nullptrptr, 0)));
    pBtn1->setAutoFillBackground(true);
    pBtn1->setPalette(palette);
    pBtn1->setFlat(true);
#endif
#if 0
    QTabWidget *tab_widget = new QTabWidget;
    QFrame *frame = new QFrame;

    QTabWidget* tab1 = new QTabWidget(frame);
    QFrame *frame1 = new QFrame;

    QTabWidget* tab2 = new QTabWidget(frame1);
    QFrame *frame2 = new QFrame;

    QTabWidget* tab3 = new QTabWidget(frame2);
    QFrame *frame3 = new QFrame;

    QFrame *frame4 = new QFrame;

    tab3->addTab(frame4, "3");
    QHBoxLayout *tab3_layout = new QHBoxLayout(frame4);
    //tab3_layout->addWidget(tab2);

    tab2->addTab(frame3, "2");
    QHBoxLayout *tab2_layout = new QHBoxLayout(frame3);
    tab2_layout->addWidget(tab3);

    tab1->addTab(frame2, "1");
    QHBoxLayout *tab1_layout = new QHBoxLayout(frame2);
    tab1_layout->addWidget(tab2);

    tab_widget->addTab(frame1, "0");
    QHBoxLayout *tab_layout = new QHBoxLayout(frame1);
    tab_layout->addWidget(tab1);




    this->setCentralWidget(tab_widget);
#endif
}

MainWindow::~MainWindow()
{

}

void MainWindow::NewGmlPage(const QString &gmlText)
{
    if(nullptr != m_gml)
    {
        delete m_gml;
        m_gml = nullptr;
    }

    m_gml = new Gml(gmlText);
    //m_gml->Print();

    if(nullptr != m_gml)
    {
        this->setCentralWidget(m_gml->Create()->Widget());
    }
}

void MainWindow::ImportGml_Slot()
{
    QString pathfile = QFileDialog::getOpenFileName(this, tr("Open GML File"), ".", "files(*.txt)");
    if(pathfile.isEmpty())
    {
        return;
    }

    QFile file(pathfile);
    if(!file.open(QIODevice::ReadWrite))
    {
        return;
    }

    QTextStream stream(&file);
    stream.setCodec("UTF-8");

    NewGmlPage(stream.readAll());

    file.close();
}

