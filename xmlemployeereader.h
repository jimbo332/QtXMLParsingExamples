#ifndef XMLEMPLOYEEREADER_H
#define XMLEMPLOYEEREADER_H

#include <QTreeWidget>
#include <QXmlStreamReader>

class XmlEmployeeReader
{
public:
    XmlEmployeeReader(QString fileName = "", QTreeWidget* treeWidget = Q_NULLPTR);

    void read();
    void setFileName(const QString& fileName);
    const QString& getFileName();

private:
    void readEmployees(QTreeWidgetItem* treeWidgetItem = Q_NULLPTR);
    void readEmployee(QTreeWidgetItem* treeWidgetItem = Q_NULLPTR);

    QTreeWidgetItem* createChildItem(QTreeWidgetItem *item = Q_NULLPTR);

    QXmlStreamReader m_xml;
    QString m_fileName;
    QTreeWidget *m_pTreeWidget = Q_NULLPTR;
};

#endif // XMLEMPLOYEEREADER_H
