#ifndef HANDLERQVECTOR3D_H
#define HANDLERQVECTOR3D_H

#include <QVector3D>
#include <QObject>

class HandlerQVector3D : public QObject {
    Q_OBJECT
public:
    explicit HandlerQVector3D(QObject *parent);

    HandlerQVector3D(QVector3D&);

    Q_INVOKABLE QVector3D& getVector();

private:
    QVector3D vec;
};


#endif // HANDLERQVECTOR3D_H
