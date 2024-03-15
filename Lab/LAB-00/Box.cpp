#include "Box.h"

Box::Box()
{
    width = 1;
    height = 1;
    depth = 1;
}

Box::Box(int width, int height, int depth)
{
    this->width = width;
    this->height = height;
    this->depth = depth;
}

void Box::setWidth(int width)
{
    this->width = width;
}

void Box::setHeight(int height)
{
    this->height = height;
}

void Box::setDepth(int depth)
{
    this->depth = depth;
}

int Box::getWidth()
{
    return this->width;
}

int Box::getHeight()
{
    return this->height;
}

int Box::getDepth()
{
    return this->depth;
}

int Box::volume()
{
    return width*height*depth;
}

