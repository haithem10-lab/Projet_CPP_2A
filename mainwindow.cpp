#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseurs.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->stackedWidget->setCurrentIndex(0);
    ui->table->setModel(f.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_HomeBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addeq_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_HomeBtn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addeq_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_HomeBtn_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addeq_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_HomeBtn_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_DataBtn_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addeq_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_LogoutBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_LogoutBtn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_LogoutBtn_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_LogoutBtn_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_buttonBox_2_accepted()
{
    QString nom =ui->lineEdit->text();
    QString prenom =ui->lineEdit_11->text();
    QString email =ui->lineEdit_4->text();
    QString adresse =ui->lineEdit_3->text();
    int num_tel =ui->lineEdit_1->text().toUInt();

    fournisseurs f(nom,prenom,email,adresse,num_tel);

    bool test=f.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajoute \n"
                                             "click to cancel"), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);

}


void MainWindow::on_PdfBtn_3_clicked()
{
    ui->table->setModel(f.afficher());
}

void MainWindow::on_pushButton_3_clicked()
{
    {
        int id =ui->lineEdit_4->text().toUInt();
        bool test=f.supprimer(id);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Supprimé \n"
                                                 "click to cancel"), QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("suppression non effectué"),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
      int id =ui->lineEdit_5->text().toUInt();
      QString nom =ui->lineEdit_6->text();
      QString prenom =ui->lineEdit_7->text();
      QString email =ui->lineEdit_8->text();
      QString adresse =ui->lineEdit_9->text();
      int num_tel =ui->lineEdit_10->text().toInt();
      bool test=f.modifier_fournisseurs(id,nom,prenom,email,adresse,num_tel);
      if(test)
      {
          QMessageBox::information(nullptr, QObject::tr("ok"),
                                   QObject::tr("modifié \n"
                                               "click to cancel"), QMessageBox::Cancel);
      }
  else
      QMessageBox::critical(nullptr,QObject::tr("not ok"),
                            QObject::tr("modification non effectué"),QMessageBox::Cancel);

}
