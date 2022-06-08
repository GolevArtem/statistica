#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE"); // В метод передали драйвер
    db.setDatabaseName("./TestDB.db"); // Путь не указали(хранится в файле со всем)
    if(db.open())
    {
        qDebug("open");
    }
    else
    {
       qDebug("no open");
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Statistica(Number, Result);");

    model = new QSqlTableModel(this, db);
    model->setTable("Statistica");
    model->select();

    ui->tableView->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_enter_clicked()
{
    model->insertRow(model->rowCount());
}
