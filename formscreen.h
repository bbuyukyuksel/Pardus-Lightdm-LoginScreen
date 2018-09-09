#ifndef FORMSCREEN_H
#define FORMSCREEN_H

#include <QDialog>

namespace Ui {
class formscreen;
}

class formscreen : public QDialog
{
    Q_OBJECT

public:
    explicit formscreen(QWidget *parent = 0);
    ~formscreen();

private slots:
    void on_button_onayla_clicked();

    void on_button_cikis_clicked();

private:
    Ui::formscreen *ui;
};

#endif // FORMSCREEN_H
