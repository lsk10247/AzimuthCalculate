#include "pch.h"
#include <math.h>
#include "Tools.h"
//Radian:3.32
//Angle:63.85
//Degree:23.25365

//����ת�����Ƕ�
double RadianToAngle(double radian) {
	return radian / PI * 180;
}
//�Ƕ�ת��������
double AngleToRadian(double angle) {
	return angle / 180 * PI;
}
//�ȷ���ת�����Ƕ�
double DegreeToAngle(double degree) {
	int d = int(degree);
	degree = (degree - d) * 100;
	int f = int(degree);
	degree = (degree - f) * 100;
	return d + (f / 60.) + (degree / 3600);
}
//�Ƕ�ת�����ȷ���
double AngleToDegree(double angle) {
	int d = int(angle);
	angle = (angle - d)*60;
	int f = int(angle);
	angle = (angle - f) * 60;
	return d + f / 100. + angle / 10000;
}
//����ת�����ȷ���
double RadianToDegree(double radian) {
	return AngleToDegree(RadianToAngle(radian));
}
//�ȷ���ת������
double DegreeToRadian(double degree) {
	return AngleToRadian(DegreeToAngle(degree));
}
//���㷽λ��
double CalculateAzimuth(double x1, double y1, double x2, double y2) {
	double result = atan2(y2 - y1, x2 - x1);
	if (result < 0) {
		result += 2*PI;
	}
	return result;
}