#include <QXmlStreamReader>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QDebug>

#include "xmlemployeereader.h"

XmlEmployeeReader::XmlEmployeeReader(QString fileName, QTreeWidget* treeWidget)
    : m_fileName(fileName)
{
    m_pTreeWidget = new QTreeWidget();
}

void XmlEmployeeReader::read()
{
    QFile xmlFile(m_fileName);
    xmlFile.open(QIODevice::ReadOnly);
    m_xml.setDevice(&xmlFile);

    if(m_xml.readNextStartElement() && m_xml.name() == "employees")
    {
        readEmployees();
    }

    if(m_xml.tokenType() == QXmlStreamReader::Invalid)
    {
        m_xml.readNext();
    }

    if(m_xml.hasError())
    {
        m_xml.raiseError();
        qDebug() << "Error occured!";
    }

    qDebug() << "At the end of the read() funcion\n";
}

void XmlEmployeeReader::setFileName(const QString &fileName)
{
    m_fileName = fileName;
}

const QString &XmlEmployeeReader::getFileName()
{
    return m_fileName;
}

void XmlEmployeeReader::readEmployees(QTreeWidgetItem *treeWidgetItem)
{
    if(!m_xml.isStartElement() || !(m_xml.name() != "employees"))
    {
        return;
    }

    qDebug() << "Reading employees\n";
    while(m_xml.readNextStartElement())
    {
        if(m_xml.name() == "employee")
        {
            qDebug() << "Reading employee!!!\n";
            readEmployee();
        }
        else
        {
            m_xml.skipCurrentElement();
        }
    }
}

void XmlEmployeeReader::readEmployee(QTreeWidgetItem *treeWidgetItem)
{
    QString firstname;
    QString lastname;
    QString age;
    QString position;
    QString salary;
    QString login;
    QString officelocation;

    qDebug() << "Hi there\n";
    while(m_xml.readNextStartElement())
    {
        if(m_xml.name() == "firstname")
        {
            firstname = m_xml.readElementText();
        }
        else if(m_xml.name() == "lastname")
        {
            lastname = m_xml.readElementText();
        }
        else if(m_xml.name() == "age")
        {
            age = m_xml.readElementText();
        }
        else if(m_xml.name() == "position")
        {
            position = m_xml.readElementText();
        }
        else if(m_xml.name() == "salary")
        {
            salary = m_xml.readElementText();
        }
        else if(m_xml.name() == "login")
        {
            login = m_xml.readElementText();
        }
        else if(m_xml.name() == "officeloaction")
        {
            officelocation = m_xml.readElementText();
        }

        QStringList info;
        info.reserve(7);
        info.push_back(firstname);
        info.push_back(lastname);
        info.push_back(age);
        info.push_back(position);
        info.push_back(salary);
        info.push_back(login);
        info.push_back(officelocation);

        qDebug() << "HERE!" << '\n';
        qDebug() << "Size: " << info.size() << "\n";
        for(int i = 0; i < info.size(); i++)
        {
            qDebug() << info[i] << '\n';
        }

//        QTreeWidgetItem *item = new QTreeWidgetItem(info);
//        m_pTreeWidget->addTopLevelItem(item);
//        m_pTreeWidget->show();
    }
}

QTreeWidgetItem *XmlEmployeeReader::createChildItem(QTreeWidgetItem *item)
{
 return new QTreeWidgetItem();
}
