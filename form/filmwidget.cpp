#include "filmwidget.h"
#include "ui_filmwidget.h"

#include <QFile>

FilmWidget::FilmWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilmWidget)
{
    ui->setupUi(this);
}

FilmWidget::FilmWidget(const Film& film, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilmWidget),film(film)
{
    ui->setupUi(this);
    initFilmWidget();
}

FilmWidget::~FilmWidget()
{
    delete ui;
}

Film FilmWidget::getFilm() const
{
    return film;
}

void FilmWidget::setFilm(const Film &value)
{
    film = value;
}

void FilmWidget::initFilmWidget()
{
    ui->fnameLabel_2->setText(film.getFname());
    ui->durationLabel_2->setText(QString::number(film.getDuration())+"分钟");
    ui->introductionBrowser->setText(film.getIntroduction());
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
    QImage image(film.getPreview());
    QImage scalImg=image.scaled(ui->imagLabel->size());
    ui->imagLabel->setPixmap(QPixmap::fromImage(scalImg));
}
