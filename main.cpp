#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include "form/formlogin.h"
#include "form/mainwindowadmin.h"
#include "form/formsessionmanage.h"
#include "form/filmwidget.h"
#include "form/mainwindowuser.h"
#include"form/formbuyticket.h"
#include "service/sessionserviceimpl.h"
#include "form/mybutton.h"
#include "form/formselectseat.h"
#include "form/seatwidget.h"
#include "form/commentwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormLogin w;
    w.show();
    return a.exec();
}


//  // 输出选择的文件路径
//  qDebug() << "Selected File: " << filePath;


//QFile file("./");
//file.open(QIODevice::ReadOnly);
//qDebug()<<file.readAll();


//    QString filePath = QFileDialog::getOpenFileName(
//          nullptr,
//          "Open File",
//          "./",
//          "Imag files (*.png *.jpg *.bmp);;All files (*)"
//      );
//    QFile file(filePath);
//    file.open(QIODevice::ReadOnly);
//    QByteArray imagData=file.readAll();
//QPixmap pixmap.loadFromData(imagData,"PNG");


//QFile qss("://qss/style2.qss");
//if(!qss.open(QFile::ReadOnly))
//{
//    QMessageBox::critical(nullptr, "错误提示", "未能成功加载qss");
//}
//a.setStyleSheet(qss.readAll());






//    // 创建数据模型
//    QStandardItemModel model;

//    // 设置表头
//    model.setHorizontalHeaderLabels({"Name", "Age", "City"});

//    // 添加数据
//    QList<QStandardItem*> rowData1 = {new QStandardItem("John"), new QStandardItem("25"), new QStandardItem("New York")};
//    QList<QStandardItem*> rowData2 = {new QStandardItem("Alice"), new QStandardItem("30"), new QStandardItem("London")};

//    // 插入一行数据
//    model.appendRow(rowData1);
//    model.appendRow(rowData2);

//    // 创建表格视图
//    QTableView tableView;

//    // 将数据模型设置给表格视图
//    tableView.setModel(&model);

//    // 获取选择模型
//    QItemSelectionModel *selectionModel = tableView.selectionModel();

//    // 连接单击事件的槽函数
//    QObject::connect(selectionModel, &QItemSelectionModel::currentChanged, [&](const QModelIndex &current, const QModelIndex &previous) {
//        // 输出所选单元格的信息
//        qDebug() << "Current Row:" << current.row() << "Column:" << current.column();
//    });
//tableView.setSelectionBehavior(QAbstractItemView::SelectRows);
//    // 显示表格视图
//    tableView.show();
