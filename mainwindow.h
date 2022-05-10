#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "auth_window.h"
#include <QtSql/QtSql>
#include "reg_window.h"



#include "dataset.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void display();
    bool connectDB();
    void wipeDB();
    int Get_user_id();
signals:
    void butt_clicked();


private:
    Ui::MainWindow *ui_Main;
    auth_window ui_Auth;
    reg_window ui_Reg;
    QString m_username;
    QString m_userpass;
    QString m_login;
    QString db_input;
    QSqlDatabase mw_db;
    int user_counter;
    bool m_loginSuccesfull;
private slots:
    void authorizeUser();
    void registerWindowShow();
    void registerUser();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H