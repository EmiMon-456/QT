#include "MainWindow.h"
#include "DateWindow.h"
#include <QCalendarWidget>
#include <QDialog>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QDate>
#include <QAction>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      label_(new QLabel("Texto inicial", this)),
      button_(new QPushButton("Presióname", this)),
      lineEdit_(new QLineEdit(this)),
      textEdit_(new QTextEdit(this))
      
{
    // Inicialización del calendario y botón nuevo
    calendarWidget_ = new QCalendarWidget(this);
    calendarButton_ = new QPushButton("Seleccionar Fecha", this);

    connect(calendarButton_, &QPushButton::clicked, this, [this]() {
        QDate date = calendarWidget_->selectedDate();
        on_calendarClicked(date);
    });


    // 1) Configurar la ventana principal
    setWindowTitle("Ejemplo Qt – Controles Básicos");
    resize(600, 400);

    // 2) Barra de menú con acción "Salir"
    QMenu *fileMenu = menuBar()->addMenu("&Archivo");
    QAction *exitAction = fileMenu->addAction("Salir");
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);

    // 3) Barra de estado
    statusBar()->showMessage("Listo");

    // 4) Barra de herramientas que reutiliza la acción "Salir"
    QToolBar *toolbar = addToolBar("Principal");
    toolbar->addAction(exitAction);
    toolbar->addWidget(label_); // Añadir QLabel a la barra de herramientas

    // 5) Conectar el botón al slot
    connect(button_, &QPushButton::clicked, this, &MainWindow::on_buttonClicked);

    // 6) Crear un widget central con layout
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    // Layout vertical principal
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(label_);

    // Layout horizontal para QLabel + QLineEdit + QPushButton
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(new QLabel("Ingresa texto:", this));
    hbox->addWidget(lineEdit_);
    hbox->addWidget(button_);
    vbox->addLayout(hbox);

    // QLabel y QTextEdit para mostrar líneas
    vbox->addWidget(new QLabel("Editor de Texto:", this));
    vbox->addWidget(textEdit_);
    vbox->addWidget(calendarWidget_); // Añadir calendario al layout
    vbox->addWidget(calendarButton_); // Añadir botón de calendario al layout

    central->setLayout(vbox);
}

MainWindow::~MainWindow()
{
    // Qt libera los hijos automáticamente
}


void MainWindow::on_buttonClicked()
{
    QString input = lineEdit_->text();
    if (input.isEmpty()) {
        QMessageBox::warning(this, "Advertencia", "El campo de texto está vacío.");
        return;
    }

    // Actualizar QLabel e insertar línea en QTextEdit
    label_->setText("Último ingreso: " + input);
    textEdit_->append("Ingresaste: " + input);
}

// Definición de la función on_calendarClicked fuera de on_buttonClicked
void MainWindow::on_calendarClicked(const QDate &date)
{
    textEdit_->append("Fecha seleccionada: " + date.toString());
    DateWindow *dateWindow = new DateWindow(lineEdit_->text(), date, this);
    dateWindow->exec();
}