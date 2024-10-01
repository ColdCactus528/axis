#include "axis.h"
#include <QQuaternion>
#include <QtMath>  // Для работы с углами и тригонометрией
#include <QDebug>
#include <cmath>

#define FLT_EPSILON 0.000002

// Конструктор по умолчанию, создающий три оси
Axis::Axis() {
    xAxis = new Line(QVector3D(0, 0, 0), QVector3D(100, 0, 0), QColor("red"));
    yAxis = new Line(QVector3D(0, 0, 0), QVector3D(0, 100, 0), QColor("green"));
    zAxis = new Line(QVector3D(0, 0, 0), QVector3D(0, 0, 100), QColor("blue"));
}

void Axis::initializeFirstLabels(int flag) {
    if (flag == 0) {
        xAxis->setStart(QVector3D(98,2,0));
        xAxis->setEnd(QVector3D(100,6,0));

        yAxis->setStart(QVector3D(98,6,0));
        yAxis->setEnd(QVector3D(100,2,0));
        yAxis->setColor(QColor("red"));
    }

    if (flag == 1) {
        xAxis->setStart(QVector3D(2,92.5,0));
        xAxis->setEnd(QVector3D(6,99,0));
        xAxis->setColor(QColor("green"));

        yAxis->setStart(QVector3D(4,95,0));
        yAxis->setEnd(QVector3D(2,100,0));
    }

    if (flag == 2) {
        xAxis->setStart(QVector3D(0,6,97));
        xAxis->setEnd(QVector3D(0,6,100));
        xAxis->setColor(QColor("blue"));

        yAxis->setStart(QVector3D(0,6,97));
        yAxis->setEnd(QVector3D(0,2,100));
        yAxis->setColor(QColor("blue"));

        zAxis->setStart(QVector3D(0,2,97));
        zAxis->setEnd(QVector3D(0,2,100));
    }
}

Axis* Axis::initializeSecondLabels(const QVector3D& vec, int flag) {
    double x = vec.x();
    double y = vec.y();
    double z = vec.z();

    if (flag == 0 ) {
        Line *newXAxis = new Line(QVector3D(x+2, y+2, z+2), QVector3D(x+6, y+9, z+2), QColor("orange"));
        Line *newYAxis = new Line(QVector3D(x+6, y+2, z+2), QVector3D(x+2,y+7+2,z+2), QColor("orange"));
        Line *newZAxis = new Line(vec, vec, QColor("orange"));

        Axis* newAxis = new Axis();
        newAxis->xAxis = newXAxis;
        newAxis->yAxis = newYAxis;
        newAxis->zAxis = newZAxis;

    return newAxis;
    }

    if (flag == 1) {
        Line *newXAxis = new Line(QVector3D(x+2, y+2, z+2), QVector3D(x+4+2, y+7+2, z+2), QColor("brown"));
        Line *newYAxis = new Line(QVector3D(x+2, y+7+2, z+2), QVector3D(x+2+2,y+3+2,z+2), QColor("brown"));
        Line *newZAxis = new Line(vec, vec, QColor("brown"));

        Axis* newAxis = new Axis();
        newAxis->xAxis = newXAxis;
        newAxis->yAxis = newYAxis;
        newAxis->zAxis = newZAxis;

        return newAxis;
    }

    if (flag == 2) {

        Line *newXAxis = new Line(QVector3D(x+2, y+2, z+3+2), QVector3D(x+2, y+4+2, z+2), QColor("brown"));
        Line *newYAxis = new Line(QVector3D(x+2, y+2, z+2), QVector3D(x+2,y+2,z+3+2), QColor("brown"));
        Line *newZAxis = new Line(QVector3D(x+2, y+4+2, z+2), QVector3D(x+2, y+4+2, z+3+2), QColor("brown"));

        Axis* newAxis = new Axis();
        newAxis->xAxis = newXAxis;
        newAxis->yAxis = newYAxis;
        newAxis->zAxis = newZAxis;

        return newAxis;
    }

}

// Возвращаем ссылки на оси
Line* Axis::getXAxis() const {
    // qDebug() << "getXAxis called: Start" << xAxis->start() << "End" << xAxis->end();
    return xAxis;
}

Line* Axis::getYAxis() const {
    return yAxis;
}

Line* Axis::getZAxis() const {
    return zAxis;
}

// Метод для применения кватернионного преобразования (остается без изменений)
Axis* Axis::applyQuaternion(float angle, QVector3D rotationAxis) {
    rotationAxis.normalize();
    float radAngle = qDegreesToRadians(angle);

    float sinHalfAngle = qSin(radAngle / 2.0);
    float cosHalfAngle = qCos(radAngle / 2.0);

    QQuaternion quaternion(
        cosHalfAngle,
        rotationAxis.x() * sinHalfAngle,
        rotationAxis.y() * sinHalfAngle,
        rotationAxis.z() * sinHalfAngle
        );

    Line *newXAxis = new Line(QVector3D(0, 0, 0), quaternion.rotatedVector(xAxis->end()), QColor("red"));
    Line *newYAxis = new Line(QVector3D(0, 0, 0), quaternion.rotatedVector(yAxis->end()), QColor("green"));
    Line *newZAxis = new Line(QVector3D(0, 0, 0), quaternion.rotatedVector(zAxis->end()), QColor("blue"));

    Axis* newAxis = new Axis();
    newAxis->xAxis = newXAxis;
    newAxis->yAxis = newYAxis;
    newAxis->zAxis = newZAxis;
    // newAxis->xAxis->setColor(QColor("orange"));
    // newAxis->yAxis->setColor(QColor("brown"));
    // newAxis->zAxis->setColor(QColor("purple"));

    return newAxis;
}

QVector3D Axis::createVector(double x, double y, double z, const QString& order) {
    QVector3D result;

    if (order == "X-Y-Z") {
        result = QVector3D(x, y, z);  // Порядок X, Y, Z
    } else if (order == "X-Z-Y") {
        result = QVector3D(x, z, y);  // Порядок X, Z, Y
    } else if (order == "Y-Z-X") {
        result = QVector3D(z, x, y);  // Порядок Y, Z, X
    } else if (order == "Y-X-Z") {
        result = QVector3D(y, x, z);  // Порядок Y, X, Z

    } else if (order == "Z-X-Y") {
        result = QVector3D(y, z, x);  // Порядок Z, X, Y

    } else if (order == "Z-Y-X") {
        result = QVector3D(z, y, x);  // Порядок Z, Y, X
    } else if (order == "X-Y-X") {
        result = QVector3D(x, y, z);  // Порядок X, Y, X

    } else if (order == "X-Z-X") {
        result = QVector3D(x, z, y);  // Порядок X, Z, X

    } else if (order == "Y-X-Y") {
        result = QVector3D(y, x, z);  // Порядок Y, X, Y
    } else if (order == "Y-Z-Y") {
        result = QVector3D(x, z, y);  // Порядок Y, Z, Y

    } else if (order == "Z-X-Z") {
        result = QVector3D(y, x, z);  // Порядок Z, X, Z

    } else if (order == "Z-Y-Z") {
        result = QVector3D(x, y, z);  // Порядок Z, Y, Z
    } /*else {
        // Если передан неизвестный порядок, выводим предупреждение
        qWarning("Неверный порядок осей: %s", qPrintable(order));
        result = QVector3D(x, y, z);  // Возвращаем вектор в исходном порядке
    }*/

    qDebug() << "X =  " << x << "Y = " << y << "Z = " << z << result;
    qDebug() << "Преобразования " << result;

    return result;
}

Axis* Axis::applyEulerAnglesWithOrder(float ang0, float ang1, float ang2, const QString& order) {
    // Уопрядочиваем углы в правльную последовательность для работы
    QVector3D vec = createVector(ang0, ang1, ang2, order);
    qDebug() << "углы: \n" << "1 = " << ang0 << "\n" << "2 = " << ang1 << "\n" << "3 = " << ang2 << "\n";

    // Кватернионы для осей
    QQuaternion qRoll = QQuaternion::fromAxisAndAngle(QVector3D(1,0,0), vec.x());
    QQuaternion qPitch = QQuaternion::fromAxisAndAngle(QVector3D(0,1,0), vec.y());
    QQuaternion qYaw = QQuaternion::fromAxisAndAngle(QVector3D(0,0,1), vec.z());

    QQuaternion finalQuaternion;
    // Порядок введения
    if (order == "X-Y-Z") {
        finalQuaternion = qRoll * qPitch * qYaw;
    } else if (order == "X-Z-Y") {
        finalQuaternion = qRoll * qYaw * qPitch;
    } else if (order == "Y-Z-X") {
        finalQuaternion = qPitch * qYaw * qRoll;
    } else if (order == "Y-X-Z") {
        finalQuaternion = qPitch * qRoll * qYaw;
    } else if (order == "Z-X-Y") {
        finalQuaternion = qYaw * qRoll * qPitch; 
    } else if (order == "Z-Y-X") {
        finalQuaternion = qYaw * qPitch * qRoll;

    } else if (order == "Y-Z-Y") {
        qRoll = QQuaternion::fromAxisAndAngle(QVector3D(0,1,0), vec.x());
        finalQuaternion = qRoll * qYaw * qPitch;
    } else if (order == "Y-X-Y") {
        qYaw = QQuaternion::fromAxisAndAngle(QVector3D(0,1,0), vec.z());
        finalQuaternion = qPitch * qRoll * qYaw;

    } else if (order == "Z-X-Z") {
        qPitch = QQuaternion::fromAxisAndAngle(QVector3D(0,0,1), vec.y());
        finalQuaternion = qPitch * qRoll * qYaw;
    } else if (order == "Z-Y-Z") {
        qRoll = QQuaternion::fromAxisAndAngle(QVector3D(0,0,1), vec.x());
        finalQuaternion = qRoll * qPitch * qYaw;

    } else if (order == "X-Z-X") {
        qPitch = QQuaternion::fromAxisAndAngle(QVector3D(1,0,0), vec.y());
        finalQuaternion = qRoll * qYaw * qPitch;
    } else if (order == "X-Y-X") {
        qYaw = QQuaternion::fromAxisAndAngle(QVector3D(1,0,0), vec.z());
        finalQuaternion = qRoll * qPitch * qYaw;
    }

    currentQuaernion = finalQuaternion;

    Line *newXAxis = new Line(QVector3D(0, 0, 0), finalQuaternion.rotatedVector(xAxis->end()), QColor("red"));
    Line *newYAxis = new Line(QVector3D(0, 0, 0), finalQuaternion.rotatedVector(yAxis->end()), QColor("green"));
    Line *newZAxis = new Line(QVector3D(0, 0, 0), finalQuaternion.rotatedVector(zAxis->end()), QColor("blue"));

    Axis* newAxis = new Axis();
    newAxis->xAxis = newXAxis;
    newAxis->yAxis = newYAxis;
    newAxis->zAxis = newZAxis;

    return newAxis;
}

QVector3D Axis::quatToEul(const QString& order) {
    // QQuaternion q = currentQuaernion.normalized();
    QQuaternion q = currentQuaernion;
    float Nq = q.x()*q.x() + q.y()*q.y() + q.z()*q.z() + q.scalar()*q.scalar();
    float s;

    if (Nq > 0)
        s = 2/Nq;
    else
        s = 0;


    float xs = q.x() * s;
    float ys = q.y() * s;
    float zs = q.z() * s;

    float wx = q.scalar() * xs;
    float wy = q.scalar() * ys;
    float wz = q.scalar() * zs;

    float xx = q.x() * xs;
    float xy = q.x() * ys;
    float xz = q.x() * zs;

    float yy = q.y() * ys;
    float yz = q.y() * zs;
    float zz = q.z() * zs;

    std::array<std::array<float,4>,4> M = {0};

    // Заполняем матрицу M
    M[0][0] = 1.0 - (yy + zz);
    M[0][1] = xy - wz;
    M[0][2] = xz + wy;
    M[0][3] = 0.0;

    M[1][0] = xy + wz;
    M[1][1] = 1.0 - (xx + zz);
    M[1][2] = yz - wx;
    M[1][3] = 0.0;

    M[2][0] = xz - wy;
    M[2][1] = yz + wx;
    M[2][2] = 1.0 - (xx + yy);
    M[2][3] = 0.0;

    M[3][0] = 0.0;
    M[3][1] = 0.0;
    M[3][2] = 0.0;
    M[3][3] = 1.0;

    float cy, sy;
    float gamma_rad, beta_rad, alpha_rad;

    if (order == "Z-Y-X") {
        cy = sqrt(M[0][0] * M[0][0] + M[1][0] * M[1][0]);
        if (cy > 16 * FLT_EPSILON) {
            gamma_rad = atan2(M[2][1], M[2][2]); // ea.x
            beta_rad = atan2(-M[2][0], cy);      // ea.y
            alpha_rad = atan2(M[1][0], M[0][0]); // ea.z
        } else {
            gamma_rad = atan2(-M[1][2], M[1][1]); // ea.x
            beta_rad = atan2(-M[2][0], cy);       // ea.y
            alpha_rad = 0;                        // ea.z
        }
    } else if (order == "X-Y-X") {
        sy = sqrt(M[0][1] * M[0][1] + M[0][2] * M[0][2]);
        if (sy > 16 * FLT_EPSILON) {
            gamma_rad = atan2(M[0][1], M[0][2]);
            beta_rad = atan2(sy, M[0][0]);
            alpha_rad = atan2(M[1][0], -M[2][0]);
        } else {
            gamma_rad = atan2(-M[1][2], M[1][1]);
            beta_rad = atan2(sy, M[0][0]);
            alpha_rad = 0;
        }
    } else if (order == "Y-Z-X") {
        cy = sqrt(M[0][0] * M[0][0] + M[2][0] * M[2][0]);
        if (cy > 16 * FLT_EPSILON) {
            gamma_rad = -atan2(M[1][2], M[1][1]);
            beta_rad = -atan2(-M[1][0], cy);
            alpha_rad = -atan2(M[2][0], M[0][0]);
        } else {
            gamma_rad = -atan2(-M[2][1], M[2][2]);
            beta_rad = -atan2(-M[1][0], cy);
            alpha_rad = 0;
        }
    } else if (order == "X-Z-X") {
        sy = sqrt(M[0][2] * M[0][2] + M[0][1] * M[0][1]);
        if (sy > 16 * FLT_EPSILON) {
            gamma_rad = -atan2(M[0][2], M[0][1]);
            beta_rad = -atan2(sy, M[0][0]);
            alpha_rad = -atan2(M[2][0], -M[1][0]);
        } else {
            gamma_rad = -atan2(-M[2][1], M[2][2]);
            beta_rad = -atan2(sy, M[0][0]);
            alpha_rad = 0;
        }
    } else if (order == "X-Z-Y") {
        cy = sqrt(M[1][1] * M[1][1] + M[2][1] * M[2][1]);
        if (cy > 16 * FLT_EPSILON) {
            gamma_rad = atan2(M[0][2], M[0][0]);
            beta_rad = atan2(-M[0][1], cy);
            alpha_rad = atan2(M[2][1], M[1][1]);
            qDebug() << "ppppppppppp!";
        } else {
            gamma_rad = atan2(-M[2][0], M[2][2]);
            beta_rad = atan2(-M[0][1], cy);
            alpha_rad = 0;
            qDebug() << "oooooooooooo";
        }
    } else if (order == "Y-Z-Y") {
        sy = sqrt(M[1][2] * M[1][2] + M[1][0] * M[1][0]);
        if (sy > 16 * FLT_EPSILON) {
            gamma_rad = atan2(M[1][2], M[1][0]);
            beta_rad = atan2(sy, M[1][1]);
            alpha_rad = atan2(M[2][1], -M[0][1]);
        } else {
            gamma_rad = atan2(-M[2][0], M[2][2]);
            beta_rad = atan2(sy, M[1][1]);
            alpha_rad = 0;
        }
    } else if (order == "Z-X-Y") {
        cy = sqrt(M[1][1] * M[1][1] + M[0][1] * M[0][1]);
        if (cy > 16 * FLT_EPSILON) {
            gamma_rad = -atan2(M[2][0], M[2][2]);
            beta_rad = -atan2(-M[2][1], cy);
            alpha_rad = -atan2(M[0][1], M[1][1]);
        } else {
            gamma_rad = -atan2(-M[0][2], M[0][0]);
            beta_rad = -atan2(-M[2][1], cy);
            alpha_rad = 0;
        }
    } else if (order == "Y-X-Y") {
        sy = sqrt(M[1][0] * M[1][0] + M[1][2] * M[1][2]);
        if (sy > 16 * FLT_EPSILON) {
            gamma_rad = -atan2(M[1][0], M[1][2]);
            beta_rad = -atan2(sy, M[1][1]);
            alpha_rad = -atan2(M[0][1], -M[2][1]);
        } else {
            gamma_rad = -atan2(-M[0][2], M[0][0]);
            beta_rad = -atan2(sy, M[1][1]);
            alpha_rad = 0;
        }
    } else if (order == "Y-X-Z") {
        cy = sqrt(M[2][2] * M[2][2] + M[0][2] * M[0][2]);
        if (cy > 16 * FLT_EPSILON) {
            gamma_rad = atan2(M[1][0], M[1][1]);
            beta_rad = atan2(-M[1][2], cy);
            alpha_rad = atan2(M[0][2], M[2][2]);
        } else {
            gamma_rad = atan2(-M[0][1], M[0][0]);
            beta_rad = atan2(-M[1][2], cy);
            alpha_rad = 0;
        }
    } else if (order == "Z-X-Z") {
        sy = sqrt(M[2][0] * M[2][0] + M[2][1] * M[2][1]);
        if (sy > 16 * FLT_EPSILON) {
            gamma_rad = atan2(M[2][0], M[2][1]);
            beta_rad = atan2(sy, M[2][2]);
            alpha_rad = atan2(M[0][2], -M[1][2]);
        } else {
            gamma_rad = atan2(-M[0][1], M[0][0]);
            beta_rad = atan2(sy, M[2][2]);
            alpha_rad = 0;
        }
    } else if (order == "X-Y-Z") {
        cy = sqrt(M[2][2] * M[2][2] + M[1][2] * M[1][2]);
        if (cy > 16 * FLT_EPSILON) {
            gamma_rad = -atan2(M[0][1], M[0][0]);
            beta_rad = -atan2(-M[0][2], cy);
            alpha_rad = -atan2(M[1][2], M[2][2]);
        } else {
            gamma_rad = -atan2(-M[1][0], M[1][1]);
            beta_rad = -atan2(-M[0][2], cy);
            alpha_rad = 0;
        }
    } else if (order == "Z-Y-Z") {
        sy = sqrt(M[2][1] * M[2][1] + M[2][0] * M[2][0]);
        if (sy > 16 * FLT_EPSILON) {
            gamma_rad = -atan2(M[2][1], M[2][0]);
            beta_rad = -atan2(sy, M[2][2]);
            alpha_rad = -atan2(M[1][2], -M[0][2]);
            qDebug() << "lllll" << "\n";
        } else {
            gamma_rad = -atan2(-M[1][0], M[1][1]);
            beta_rad = -atan2(sy, M[2][2]);
            alpha_rad = 0;
            qDebug() << "fffffff" << "\n";
        }
    }

    return QVector3D(qRadiansToDegrees(gamma_rad), qRadiansToDegrees(beta_rad), qRadiansToDegrees(alpha_rad));
}

QVector3D Axis::quatToAir(const QString& order) {
    QQuaternion q = currentQuaernion;
    float Nq = q.x()*q.x() + q.y()*q.y() + q.z()*q.z() + q.scalar()*q.scalar();
    float s;

    if (Nq > 0)
        s = 2/Nq;
    else
        s = 0;


    float xs = q.x() * s;
    float ys = q.y() * s;
    float zs = q.z() * s;

    float wx = q.scalar() * xs;
    float wy = q.scalar() * ys;
    float wz = q.scalar() * zs;

    float xx = q.x() * xs;
    float xy = q.x() * ys;
    float xz = q.x() * zs;

    float yy = q.y() * ys;
    float yz = q.y() * zs;
    float zz = q.z() * zs;

    std::array<std::array<float,4>,4> M = {0};

    // Заполняем матрицу M
    M[0][0] = 1.0 - (yy + zz);
    M[0][1] = xy - wz;
    M[0][2] = xz + wy;
    M[0][3] = 0.0;

    M[1][0] = xy + wz;
    M[1][1] = 1.0 - (xx + zz);
    M[1][2] = yz - wx;
    M[1][3] = 0.0;

    M[2][0] = xz - wy;
    M[2][1] = yz + wx;
    M[2][2] = 1.0 - (xx + yy);
    M[2][3] = 0.0;

    M[3][0] = 0.0;
    M[3][1] = 0.0;
    M[3][2] = 0.0;
    M[3][3] = 1.0;

    float cy, sy;
    float gamma_rad, beta_rad, alpha_rad;

    if (order == "X-Y-Z") {
        cy = sqrt(M[0][0] * M[0][0] + M[1][0] * M[1][0]);
        if (cy > 16 * FLT_EPSILON) {
            gamma_rad = atan2(M[2][1], M[2][2]); // ea.x
            beta_rad = atan2(-M[2][0], cy);      // ea.y
            alpha_rad = atan2(M[1][0], M[0][0]); // ea.z
        } else {
            gamma_rad = atan2(-M[1][2], M[1][1]); // ea.x
            beta_rad = atan2(-M[2][0], cy);       // ea.y
            alpha_rad = 0;                        // ea.z
        }
    }

    return QVector3D(qRadiansToDegrees(gamma_rad), qRadiansToDegrees(beta_rad), qRadiansToDegrees(alpha_rad));
}

QVector3D Axis::quaternionToEulerAngles(const QString& order) {
    QQuaternion q = currentQuaernion.normalized();
    float roll = 1, pitch = 2, yaw = 3;
    // float s, nq;
    // nq = q.x()*q.x() + q.y()*q.y() + q.z()*q.z() + q.scalar()*q.scalar();
    // if (nq > 0)
    //     s = 2/nq;
    // else
    //     s = 0;

    // есть функция toEulerAngles которая возвращает QVector3D и берет это от кватерниона.

    // if (order == "X-Z-Y") {
    if (order == "Y-Z-X") {
        roll = std::atan2(2 * (q.scalar() * q.z() + q.x() * q.y()), 1 - 2 * (q.y() * q.y() + q.z() * q.z()));
        pitch = std::asin(2 * (q.scalar() * q.x() - q.y() * q.z()));
        yaw = std::atan2(2 * (q.scalar() * q.x() + q.y() * q.z()), 1 - 2 * (q.x() * q.x() + q.z() * q.z()));
    }
    if (order == "Y-X-Z") {
        roll = std::atan2(2 * (q.scalar() * q.y() + q.x() * q.z()), 1 - 2 * (q.y() * q.y() + q.z() * q.z()));
        pitch = std::asin(2 * (q.scalar() * q.z() + q.x() * q.y()));
        yaw = std::atan2(2 * (q.scalar() * q.z() + q.y() * q.x()), 1 - 2 * (q.x() * q.x() + q.z() * q.z()));
    }


    // if (order == "Y-Z-X") {
    if (order == "X-Z-Y") {
        roll = std::atan2(2 * (q.scalar() * q.y() + q.z() * q.x()), 1 - 2 * (q.y() * q.y() + q.z() * q.z()));
        pitch = std::asin(2 * (-q.scalar() * q.z() + q.y() * q.x()));
        yaw = std::atan2(2 * (q.scalar() * q.x() + q.z() * q.y()), 1 - 2 * (q.x() * q.x() + q.y() * q.y()));
    }


    // if (order == "Z-X-Y") {
    //     roll = std::atan2(2 * (q.scalar() * q.z() + q.x() * q.y()), 1 - 2 * (q.z() * q.z() + q.y() * q.y()));
    //     pitch = std::asin(2 * (q.scalar() * q.x() - q.z() * q.y()));
    //     yaw = std::atan2(2 * (q.scalar() * q.y() + q.z() * q.x()), 1 - 2 * (q.y() * q.y() + q.x() * q.x()));
    // }
    // НЕ РАБОТАЕТ
    if (order == "Z-X-Y") {
        float cy = sqrt( (1.0-(q.x()*q.x() + q.z()*q.z()) ));
        roll = - std::atan2(2 * (- q.scalar() * q.y() + q.x() * q.z()), 1 - 2 * (q.x() * q.x() + q.y() * q.y()));
        pitch = std::asin(2 * (q.scalar() * q.z() - q.y() * q.x()));
        yaw = std::atan2(2 * (q.scalar() * q.z() + q.x() * q.y()), 1 - 2 * (q.z() * q.z() + q.y() * q.y()));
    }

    // РАБОТАЕТ
    if (order == "Z-Y-X") {
        roll = std::atan2(2 * (q.scalar() * q.x() + q.y() * q.z()), 1 - 2 * (q.x() * q.x() + q.y() * q.y()));
        pitch = std::asin(2 * (q.scalar() * q.y() - q.z() * q.x()));
        yaw = std::atan2(2 * (q.scalar() * q.z() + q.x() * q.y()), 1 - 2 * (q.y() * q.y() + q.z() * q.z()));
    }

    else if (order == "X-Z-X") {
        roll = std::atan2(2 * (q.scalar() * q.x() + q.z() * q.y()), 1 - 2 * (q.x() * q.x() + q.z() * q.z()));
        pitch = std::atan2(2 * (q.scalar() * q.z() + q.x() * q.y()), 1 - 2 * (q.y() * q.y() + q.z() * q.z()));
        yaw = std::asin(2 * (q.scalar() * q.x() - q.y() * q.z()));
    }
    if (order == "X-Y-X") {
        roll = std::atan2(2 * (q.scalar() * q.x() + q.y() * q.z()), 1 - 2 * (q.x() * q.x() + q.y() * q.y()));
        pitch = std::atan2(2 * (q.scalar() * q.y() - q.x() * q.z()), 1 - 2 * (q.x() * q.x() + q.z() * q.z()));
        yaw = std::asin(2 * (q.scalar() * q.x() - q.y() * q.z()));
    }
    if (order == "Y-X-Y") {
        roll = std::atan2(2 * (q.scalar() * q.y() + q.x() * q.z()), 1 - 2 * (q.y() * q.y() + q.z() * q.z()));
        pitch = std::atan2(2 * (q.scalar() * q.x() - q.z() * q.y()), 1 - 2 * (q.x() * q.x() + q.y() * q.y()));
        yaw = std::asin(2 * (q.scalar() * q.y() - q.x() * q.z()));
    }
    if (order == "Y-Z-Y") {
        roll = std::atan2(2 * (q.scalar() * q.y() + q.z() * q.x()), 1 - 2 * (q.y() * q.y() + q.x() * q.x()));
        pitch = std::atan2(2 * (q.scalar() * q.z() - q.x() * q.y()), 1 - 2 * (q.x() * q.x() + q.z() * q.z()));
        yaw = std::asin(2 * (q.scalar() * q.y() - q.x() * q.z()));
    }
    if (order == "Z-X-Z") {
        roll = std::atan2(2 * (q.scalar() * q.z() + q.x() * q.y()), 1 - 2 * (q.z() * q.z() + q.y() * q.y()));
        pitch = std::atan2(2 * (q.scalar() * q.x() - q.z() * q.y()), 1 - 2 * (q.x() * q.x() + q.z() * q.z()));
        yaw = std::asin(2 * (q.scalar() * q.z() - q.x() * q.y()));
    }
    if (order == "Z-Y-Z") {
        roll = std::atan2(2 * (q.scalar() * q.z() + q.y() * q.x()), 1 - 2 * (q.z() * q.z() + q.x() * q.x()));
        pitch = std::atan2(2 * (q.scalar() * q.y() - q.z() * q.x()), 1 - 2 * (q.y() * q.y() + q.z() * q.z()));
        yaw = std::asin(2 * (q.scalar() * q.z() - q.x() * q.y()));
    }
    // else {
    //     qDebug() << "Unknown order!";
    //     return;
    // }

    return QVector3D(qRadiansToDegrees(roll), qRadiansToDegrees(pitch), qRadiansToDegrees(yaw));
}


Axis* Axis::aircraftAngles(float ang0, float ang1, float ang2, const QString& order) {
    // Уопрядочиваем углы в правльную последовательность для работы
    QVector3D vec = createVector(ang0, ang1, ang2, order);

    // Кватернионы для осей
    QQuaternion qRoll = QQuaternion::fromAxisAndAngle(QVector3D(1,0,0), vec.x());
    QQuaternion qPitch = QQuaternion::fromAxisAndAngle(QVector3D(0,1,0), vec.y());
    QQuaternion qYaw = QQuaternion::fromAxisAndAngle(QVector3D(0,0,1), vec.z());

    QQuaternion finalQuaternion;

    // Порядок введения
    if (order == "X-Y-Z") {
        finalQuaternion = qYaw * qPitch * qRoll;
    } else if (order == "X-Z-Y") {
        finalQuaternion = qPitch * qYaw * qRoll;
    } else if (order == "Y-Z-X") {
        finalQuaternion = qRoll * qYaw * qPitch;
    } else if (order == "Y-X-Z") {
        finalQuaternion = qYaw * qRoll * qPitch;
    } else if (order == "Z-X-Y") {
        finalQuaternion = qPitch * qRoll * qYaw;
    } else if (order == "Z-Y-X") {
        finalQuaternion = qRoll * qPitch * qYaw;
    } else if (order == "Z-Y-X") {
        finalQuaternion = qRoll * qPitch * qYaw;
    }

    finalQuaternion.normalize();
    currentQuaernion = finalQuaternion;

    Line *newXAxis = new Line(QVector3D(0, 0, 0), finalQuaternion.rotatedVector(xAxis->end()), QColor("red"));
    Line *newYAxis = new Line(QVector3D(0, 0, 0), finalQuaternion.rotatedVector(yAxis->end()), QColor("green"));
    Line *newZAxis = new Line(QVector3D(0, 0, 0), finalQuaternion.rotatedVector(zAxis->end()), QColor("blue"));

    Axis* newAxis = new Axis();
    newAxis->xAxis = newXAxis;
    newAxis->yAxis = newYAxis;
    newAxis->zAxis = newZAxis;

    return newAxis;
}

// Функция для поворота вектора вокруг оси X
QVector3D Axis::rotateAroundX(const QVector3D& v, float angle) {
    float rad = qDegreesToRadians(angle);
    float cosA = qCos(rad);
    float sinA = qSin(rad);

    // Поворачиваем вектор вокруг оси X
    return QVector3D(v.x(), v.y() * cosA - v.z() * sinA, v.y() * sinA + v.z() * cosA);
}

// Функция для поворота вектора вокруг оси Y
QVector3D Axis::rotateAroundY(const QVector3D& v, float angle) {
    float rad = qDegreesToRadians(angle);
    float cosA = qCos(rad);
    float sinA = qSin(rad);

    // Поворачиваем вектор вокруг оси Y
    return QVector3D(v.x() * cosA + v.z() * sinA, v.y(), -v.x() * sinA + v.z() * cosA);
}

// Функция для поворота вектора вокруг оси Z
QVector3D Axis::rotateAroundZ(const QVector3D& v, float angle) {
    float rad = qDegreesToRadians(angle);
    float cosA = qCos(rad);
    float sinA = qSin(rad);

    // Поворачиваем вектор вокруг оси Z
    return QVector3D(v.x() * cosA - v.y() * sinA, v.x() * sinA + v.y() * cosA, v.z());
}

// Функция для применения самолётных углов (Roll, Pitch, Yaw) вокруг глобальных осей
Axis* Axis::applyAircraftAnglesGlobal(float roll, float pitch, float yaw, const QString& order) {
    QVector3D newX = xAxis->end();
    QVector3D newY = yAxis->end();
    QVector3D newZ = zAxis->end();

    // Применяем вращения в зависимости от переданного порядка осей
    if (order == "X-Y-Z") {
        // Поворот сначала вокруг оси X, затем Y, затем Z
        newX = rotateAroundX(newX, roll);
        newX = rotateAroundY(newX, pitch);
        newX = rotateAroundZ(newX, yaw);

        newY = rotateAroundX(newY, roll);
        newY = rotateAroundY(newY, pitch);
        newY = rotateAroundZ(newY, yaw);

        newZ = rotateAroundX(newZ, roll);
        newZ = rotateAroundY(newZ, pitch);
        newZ = rotateAroundZ(newZ, yaw);
    } else if (order == "X-Z-Y") {
        newX = rotateAroundX(newX, roll);
        newX = rotateAroundZ(newX, yaw);
        newX = rotateAroundY(newX, pitch);

        newY = rotateAroundX(newY, roll);
        newY = rotateAroundZ(newY, yaw);
        newY = rotateAroundY(newY, pitch);

        newZ = rotateAroundX(newZ, roll);
        newZ = rotateAroundZ(newZ, yaw);
        newZ = rotateAroundY(newZ, pitch);
    } else if (order == "Y-X-Z") {
        newX = rotateAroundY(newX, pitch);
        newX = rotateAroundX(newX, roll);
        newX = rotateAroundZ(newX, yaw);

        newY = rotateAroundY(newY, pitch);
        newY = rotateAroundX(newY, roll);
        newY = rotateAroundZ(newY, yaw);

        newZ = rotateAroundY(newZ, pitch);
        newZ = rotateAroundX(newZ, roll);
        newZ = rotateAroundZ(newZ, yaw);
    } else if (order == "Y-Z-X") {
        newX = rotateAroundY(newX, pitch);
        newX = rotateAroundZ(newX, yaw);
        newX = rotateAroundX(newX, roll);

        newY = rotateAroundY(newY, pitch);
        newY = rotateAroundZ(newY, yaw);
        newY = rotateAroundX(newY, roll);

        newZ = rotateAroundY(newZ, pitch);
        newZ = rotateAroundZ(newZ, yaw);
        newZ = rotateAroundX(newZ, roll);
    } else if (order == "Z-X-Y") {
        newX = rotateAroundZ(newX, yaw);
        newX = rotateAroundX(newX, roll);
        newX = rotateAroundY(newX, pitch);

        newY = rotateAroundZ(newY, yaw);
        newY = rotateAroundX(newY, roll);
        newY = rotateAroundY(newY, pitch);

        newZ = rotateAroundZ(newZ, yaw);
        newZ = rotateAroundX(newZ, roll);
        newZ = rotateAroundY(newZ, pitch);
    } else if (order == "Z-Y-X") {
        newX = rotateAroundZ(newX, yaw);
        newX = rotateAroundY(newX, pitch);
        newX = rotateAroundX(newX, roll);

        newY = rotateAroundZ(newY, yaw);
        newY = rotateAroundY(newY, pitch);
        newY = rotateAroundX(newY, roll);

        newZ = rotateAroundZ(newZ, yaw);
        newZ = rotateAroundY(newZ, pitch);
        newZ = rotateAroundX(newZ, roll);
    } else {
        // Если порядок не распознан, выводим предупреждение и возвращаем оригинальные оси без изменений
        qWarning() << "Unknown rotation order: " << order;
        return this;
    }

    // Применяем результат вращения к осям
    Line* newXAxis = new Line(QVector3D(0, 0, 0), newX, QColor("orange"));
    Line* newYAxis = new Line(QVector3D(0, 0, 0), newY, QColor("brown"));
    Line* newZAxis = new Line(QVector3D(0, 0, 0), newZ, QColor("purple"));

    // Создаём и возвращаем новый Axis с обновлёнными осями
    Axis* newAxis = new Axis();
    newAxis->xAxis = newXAxis;
    newAxis->yAxis = newYAxis;
    newAxis->zAxis = newZAxis;

    return newAxis;
}
