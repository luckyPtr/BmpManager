#ifndef QGRAPHICSCANVASITEM_H
#define QGRAPHICSCANVASITEM_H

#include <QGraphicsItem>
#include <QObject>



class QGraphicsCanvasItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    enum Action
    {
        ActionNull,
        ActionResizeVer,
        ActionResizeHor,
        ActionResizeFDiag,
        ActionMove,
    };

    QGraphicsView *view;
    QImage image;
    QPoint startPoint;  // 左上角其实位置坐标
    QPoint currentPoint;
    QPoint currentPixel;    // 当前鼠标所在的坐标（图片像素）
    QPoint moveStartPixel;  // 开始移动画布的坐标(像素)
    QPoint pointToPixel(QPoint point);  // 坐标转换为画布上的像素坐标
    bool isResezeMode;  // 是否为重新设置画布大小的模式
    bool isInSizeVerArea(QPoint point); // 是否处于垂直调整画布大小的区域内
    bool isInSizeHorArea(QPoint point); // 是否处于水平调整画布大小的区域内
    bool isInSizeFDiagArea(QPoint point);
    quint8 action = ActionNull;  // 调整画布大小的步骤 0-初始状态 1-按下
    void resizeImage(QImage &img, int width, int heighy);
    void moveImage(QImage &img,  int OffsetX, int OffsetY);
    void reserveImage(QImage &img);
    void flipHor(QImage &img);
    void flipVer(QImage &img);
    void rotateLeft(QImage &img);
    void rotateRight(QImage &img);
    void getMargin(int &up, int &down, int &left, int &right);  // 获取四周的距离
public:
    QGraphicsCanvasItem(QWidget *parent = nullptr);
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) Q_DECL_OVERRIDE;
    void setImage(QImage &image);
    QImage getImage();

public slots:
    void on_ResizeMouseMove(QPoint point);
    void on_ResizeMousePress(QPoint point);
    void on_ResizeMouseRelease(QPoint point);
    void on_MoveMouseMove(QPoint point);
    void on_MoveMousePress(QPoint point);
    void on_MoveMouseRelease(QPoint point);
    void on_Reserve();  // 反色
    void on_Center();   // 居中
    void on_AutoResize();   // 自动裁剪
    void on_MoveUp();
    void on_MoveDown();
    void on_MoveLeft();
    void on_MoveRight();
    void on_FlipHor();
    void on_FlipVer();
    void on_RotateLeft();
    void on_RotateRight();
};

#endif // QGRAPHICSCANVASITEM_H
