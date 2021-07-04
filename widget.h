#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:


    void ServerReadData();
    void ServerNewConnection();
    void sServerDisConnection();


    void on_btn_send_clicked();

    void on_btn_initSocket_clicked();

private:
    Ui::Widget *ui;

    QTcpServer *mp_TCPServer;
    QTcpSocket *mp_TCPSocket;
};
#endif // WIDGET_H
