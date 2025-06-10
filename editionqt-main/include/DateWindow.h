#pragma once

#include <QDialog>
#include <QDate>

class DateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DateWindow(const QString &text, const QDate &date, QWidget *parent = nullptr);

private:
    void setupUI();
};
