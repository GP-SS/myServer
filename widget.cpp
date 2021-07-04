#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //初始化服务器
    ui->edt_port->setText("5550");

    //代码中定义的槽函数的命名是按照qt的命名规则命名的，所以qt系统默认会帮我们把信号与槽连接起来，
    //而我们在构造函数中再一次进行了连接，所以槽函数就被连接了两次，当按钮点击后，也自然而然的执行了两次槽函数。所以此处的connect函数应该删除

    //connect(ui->btn_initSocket, SIGNAL(clicked()), this, SLOT(on_btn_initSocket_clicked()));因为在ui文件中点击的
    //connect(ui->btn_send, SIGNAL(clicked()), this, SLOT(on_btn_send_clicked()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btn_initSocket_clicked()
{
    mp_TCPServer = new QTcpServer();
    int port = ui->edt_port->text().toInt();
    if(!mp_TCPServer->listen(QHostAddress::Any, port))
    {
        QMessageBox::information(this, "QT网络通信", "服务器端监听失败！");
        return;
    }
    else
    {
        QMessageBox::information(this, "QT网络通信", "服务器监听成功！");
    }
    connect(mp_TCPServer, SIGNAL(newConnection()), this, SLOT(ServerNewConnection()));
    return;
}


void Widget::on_btn_send_clicked()
{
    char sendMsgChar[1024] = {0};
    QString sendMsg = ui->text_send->toPlainText();
    if(sendMsg.isEmpty())
    {
        QMessageBox::information(this, "QT网络通信", "发送数据为空，请输入数据");
        return;
    }
    strcpy_s(sendMsgChar, sendMsg.toStdString().c_str());
    if(mp_TCPSocket->isValid())
    {
        int sendRe = mp_TCPSocket->write(sendMsgChar, strlen(sendMsgChar));
        if( -1 == sendRe)
        {
            QMessageBox::information(this, "QT网络通信", "服务端发送数据失败！");
        }
    }
    else
    {
        QMessageBox::information(this, "QT网络通信", "套接字无效！");
    }
}

//1.2,5,6,2.6,9,8,6,5,4,5,10,2.3,5,8.8,9.3,1

void Widget::ServerReadData()
{
    char buffer[1024] = {0};
    mp_TCPSocket->read(buffer, 1024);
    if( strlen(buffer) > 0)
    {
        QString showNsg = buffer;
        ui->text_receive->append(showNsg);
    }
    else
    {
        QMessageBox::information(this, "QT网络通信", "未正确接收数据");
        return;
    }
}

void Widget::ServerNewConnection()
{
    //获取客户端连接
    mp_TCPSocket = mp_TCPServer->nextPendingConnection();
    if(!mp_TCPSocket)
    {
        QMessageBox::information(this, "QT网络通信", "未正确获取客户端连接！");
        return;
    }
    else
    {
        QMessageBox::information(this, "QT网络通信", "成功接受客户端的连接");
        connect(mp_TCPSocket, SIGNAL(readyRead()), this, SLOT(ServerReadData()));
        connect(mp_TCPSocket, SIGNAL(disconnected()), this, SLOT(sServerDisConnection()));
    }
}


void Widget::sServerDisConnection()
{
    QMessageBox::information(this, "QT网络通信", "与客户端的连接断开");
        return;
}

