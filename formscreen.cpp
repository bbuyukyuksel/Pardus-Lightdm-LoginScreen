#include <QPixmap>
#include <QBitmap>
#include <QMessageBox>
#include <QtNetwork>

#include "formscreen.h"
#include "ui_formscreen.h"
#include "mainwindow.h"


formscreen::formscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formscreen)
{
    ui->setupUi(this);
}

formscreen::~formscreen()
{
    delete ui;
}

void formscreen::on_button_onayla_clicked()
{

    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QNetworkRequest request;

    QObject::connect(manager, &QNetworkAccessManager::finished,
    this, [&](QNetworkReply *reply) {
        if (reply->error()) {
        qDebug() << reply->errorString();
        return;
        }

        QString answer = reply->readAll();
        QMessageBox myBox;
        myBox.setWindowTitle("Get Response");
        myBox.setText(answer);
        myBox.exec();
        qDebug() << answer;

        }
    );

    request.setUrl(QUrl("http://taconpazarlama.com/qrcode_process.php?c=1"));
    manager->get(request);
}

void formscreen::on_button_cikis_clicked()
{
    this->close();
}
