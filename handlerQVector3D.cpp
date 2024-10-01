#include "handlerQVector3D.h"

HandlerQVector3D::HandlerQVector3D(QObject *parent = nullptr) : QObject(parent) {
    vec.setX(0);
    vec.setY(0);
    vec.setZ(0);
}

HandlerQVector3D::HandlerQVector3D(QVector3D& vector) {
    vec = vector;
}

QVector3D& HandlerQVector3D::getVector() {
    return vec;
}
