#include "DateWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

DateWindow::DateWindow(const QString &text, const QDate &date, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Fecha y Texto");
    resize(300, 150);
    setupUI();

    QString info = QString("Texto ingresado: %1\nFecha seleccionada: %2")
                   .arg(text.isEmpty() ? "Ninguno" : text)
                   .arg(date.toString("dd/MM/yyyy"));

    QLabel *infoLabel = new QLabel(info, this);
    QVBoxLayout *layout = static_cast<QVBoxLayout*>(this->layout());
    layout->insertWidget(0, infoLabel);
}

void DateWindow::setupUI()
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *closeButton = new QPushButton("Cerrar", this);
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
    layout->addWidget(closeButton);
}