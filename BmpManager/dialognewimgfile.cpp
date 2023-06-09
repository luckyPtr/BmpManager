#include "dialognewimgfile.h"
#include "ui_dialognewimgfile.h"
#include <QDebug>

DialogNewImgFile::DialogNewImgFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewImgFile)
{
    ui->setupUi(this);

    // 限制图片名称输入格式同C语言变量命名规则
    QRegExp regx("^[a-zA-Z_][a-zA-Z0-9_]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->lineEditImgFileName);
    ui->lineEditImgFileName->setValidator(validator);
}

DialogNewImgFile::~DialogNewImgFile()
{
    delete ui;
}

quint16 DialogNewImgFile::width()
{
    return ui->spinBoxWidth->value();
}

quint16 DialogNewImgFile::height()
{
    return ui->spinBoxHeight->value();
}

QString DialogNewImgFile::imgFileName()
{
    return ui->lineEditImgFileName->text();
}

void DialogNewImgFile::setExistFile(QVector<QString> files)
{
    existFile = files;
}

bool DialogNewImgFile::checkImgFileName()
{
    if(existFile.contains(imgFileName()))
    {
        return false;
    }

    return true;
}

void DialogNewImgFile::on_lineEditImgFileName_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    if(!checkImgFileName())
    {
        ui->lineEditImgFileName->setStyleSheet("color:red");
    }
    else
    {
        ui->lineEditImgFileName->setStyleSheet("color:black");
    }
    ui->btnOK->setEnabled(checkImgFileName());
}



