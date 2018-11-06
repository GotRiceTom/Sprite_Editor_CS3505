#include "frame.h"
#include <QDebug>
Frame::Frame()
{
    image= QImage(900,900,QImage::Format_RGB32);
    currentPixelSize=30;
//    painter = QPainter(&image);

}

//QPainter Frame::getPainter()
//{
//    return this->painter;
//}

QImage& Frame::getImage()
{
    return this->image;
}

void Frame::setCurrentPixelSize(int newSize)
{
      this->currentPixelSize = newSize;
}

int Frame::getCurrentPixelSize()
{
    return this->currentPixelSize;
}

int* Frame::getPixelOfCoordinates(int x, int y)
{
    int xStarting = (x/currentPixelSize)*currentPixelSize;
    int xEnding = xStarting + currentPixelSize -1;
    int yStarting = (y/currentPixelSize)*currentPixelSize;
    int yEnding = yStarting + currentPixelSize -1;

    static int result [4];
    result[0] = xStarting;
    result[1] = xEnding;
    result[2] = yStarting;
    result[3] = yEnding;
    return result;
}

void Frame::drawPixel(int x, int y, QColor color) {
    int* points = getPixelOfCoordinates(x,y);
    QPainter painter(&image);

    QRgb white;
    white = qRgb(255,0,0);
    QBrush brush(white);

    painter.setBrush(brush);

    painter.drawRect(points[0],points[1],points[2],points[3]);
}

void Frame::drawGrid()
{

    QPainter painter(&image);

    QRgb white;
    white = qRgb(255,255,255);

    QPen pen(white);

    painter.setPen(pen);
    for(int i = 0; i<=(image.height()/this->getCurrentPixelSize()); i++)
    {
        painter.drawLine(0,i*this->getCurrentPixelSize(),900,i*this->getCurrentPixelSize());
    }
    for(int i = 0; i<=(image.width()/this->getCurrentPixelSize()); i++)
    {
        painter.drawLine(i*this->getCurrentPixelSize(),0,i*this->getCurrentPixelSize(),image.height());
    }
}
