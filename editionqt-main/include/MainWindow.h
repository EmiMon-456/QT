#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QCalendarWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_buttonClicked();
    void on_calendarClicked(const QDate &date) {
        textEdit_->append("Fecha seleccionada: " + date.toString());
    }

private:
    QLabel      *label_;
    QPushButton *button_;
    QPushButton *calendarButton_;
    QCalendarWidget *calendarWidget_;
    QLineEdit   *lineEdit_;
    QTextEdit   *textEdit_;
};
