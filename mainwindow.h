#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();

    void createConnections();

public slots:
    void parseFileBtnClicked(bool checked = false);
private:
    Ui::MainWindow *ui;
    QHBoxLayout *m_pHbox;
    QLineEdit *m_pFileNameEdit;
    QCheckBox *m_pPrependXmlExt;
    QPushButton *m_pParseFileBtn;
};

#endif // MAINWINDOW_H
