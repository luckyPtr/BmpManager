#ifndef DIALOGIMPORTIMG_H
#define DIALOGIMPORTIMG_H

#include <QDialog>
#include <QImage>

namespace Ui {
class DialogImportImg;
}

class DialogImportImg : public QDialog
{
    Q_OBJECT
private:
    QImage rawImg;      // 原始图片
    QImage monoImg;     // 二值化后的图片
    quint8 grayscale = 128;
    bool invert = false;        // 取反

public:
    explicit DialogImportImg(QImage &img, QWidget *parent = nullptr);
    ~DialogImportImg();

    void setRawImg(QImage &img) {rawImg = img;}
    QImage getMonoImg() {return monoImg;}
    void imgTransform();
    void displayImg();
private slots:
    void on_sliderGrayscale_valueChanged(int value);

    void on_checkBoxInvert_toggled(bool checked);

private:
    Ui::DialogImportImg *ui;


};

#endif // DIALOGIMPORTIMG_H
