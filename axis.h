#ifndef AXIS_H
#define AXIS_H

#include "axisLine.h"
#include <QVector3D>
#include <QQuaternion>
#include <QObject>

class Axis : public QObject {
    Q_OBJECT

    // Делаем оси доступными как QML-свойства
    Q_PROPERTY(Line* xAxis READ getXAxis CONSTANT)
    Q_PROPERTY(Line* yAxis READ getYAxis CONSTANT)
    Q_PROPERTY(Line* zAxis READ getZAxis CONSTANT)

public:
    Axis();


    // Теперь возвращаем ссылки на объекты Line как Q_PROPERTY
    Line* getXAxis() const;
    Line* getYAxis() const;
    Line* getZAxis() const;

    Q_INVOKABLE Axis* applyQuaternion(float, QVector3D);

    Q_INVOKABLE Axis* applyEulerAnglesWithOrder(float, float, float, const QString&);

    Q_INVOKABLE Axis* applyAircraftAnglesGlobal(float, float, float, const QString&);

    Q_INVOKABLE Axis* aircraftAngles(float, float, float, const QString&);

    // Q_INVOKABLE QVector3D getEulerAnglesFromQuaternion(const QString&);

    // Q_INVOKABLE Axis* applyAircraftAnglesGlobal_1(float, float, float, const QString&);

    Q_INVOKABLE QVector3D quatToEul(const QString&);

    Q_INVOKABLE QVector3D quatToAir(const QString&);

    Q_INVOKABLE QVector3D quaternionToEulerAngles(const QString&);

    Q_INVOKABLE void initializeFirstLabels(int);

    Q_INVOKABLE Axis* initializeSecondLabels(const QVector3D&, int);

private:
    QVector3D createVector(double, double, double, const QString&);

    QVector3D rotateAroundX(const QVector3D&, float);
    QVector3D rotateAroundY(const QVector3D&, float);
    QVector3D rotateAroundZ(const QVector3D&, float);

    Line *xAxis, *yAxis, *zAxis;  // Оси X, Y, Z
    QQuaternion currentQuaernion;
};

#endif // AXIS_H
