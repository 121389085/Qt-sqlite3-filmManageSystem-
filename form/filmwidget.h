#ifndef FILMWIDGET_H
#define FILMWIDGET_H

#include <QWidget>
#include "entity/film.h"
namespace Ui {
class FilmWidget;
}

class FilmWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FilmWidget(QWidget *parent = nullptr);
    explicit FilmWidget(const Film&,QWidget *parent = nullptr);
    ~FilmWidget();

    Film getFilm() const;
    void setFilm(const Film &value);

private:
    Ui::FilmWidget *ui;
    Film film;
    void initFilmWidget();
};

#endif // FILMWIDGET_H
