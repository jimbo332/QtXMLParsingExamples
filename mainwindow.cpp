#include <QMessageBox>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xmlemployeereader.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pHbox = new QHBoxLayout(this);
    m_pFileNameEdit = new QLineEdit(this);
    m_pPrependXmlExt = new QCheckBox(this);
    m_pParseFileBtn = new QPushButton(tr("Parse Employees info"));

    connect(m_pParseFileBtn, &QPushButton::clicked, this, &MainWindow::parseFileBtnClicked);

    m_pHbox->addWidget(m_pFileNameEdit);
    m_pHbox->addWidget(m_pPrependXmlExt);
    m_pHbox->addWidget(m_pParseFileBtn);
    ui->centralWidget->setLayout(m_pHbox);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createConnections()
{

}

void MainWindow::parseFileBtnClicked(bool checked)
{
    QString fileName = m_pFileNameEdit->text();
    if(fileName.isEmpty())
    {
        QMessageBox::critical(this, "Warning", "Empty Filename", QMessageBox::StandardButton::Ok);
        return;
    }

    Qt::CheckState isXmlExtChecked = m_pPrependXmlExt->checkState();
    if(isXmlExtChecked == Qt::CheckState::Checked)
    {
        fileName.append(".xml");
    }

    qDebug() << fileName;
    XmlEmployeeReader xmlReader(fileName);
    xmlReader.read();

}
