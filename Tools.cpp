#include "pch.h"
#include <math.h>
#include "Tools.h"
//Radian:3.32
//Angle:63.85
//Degree:23.25365

//弧度转换至角度
double RadianToAngle(double radian) {
	return radian / PI * 180;
}
//角度转换至弧度
double AngleToRadian(double angle) {
	return angle / 180 * PI;
}
//度分秒转换至角度
double DegreeToAngle(double degree) {
	int d = int(degree);
	degree = (degree - d) * 100;
	int f = int(degree);
	degree = (degree - f) * 100;
	return d + (f / 60.) + (degree / 3600);
}
//角度转换至度分秒
double AngleToDegree(double angle) {
	int d = int(angle);
	angle = (angle - d)*60;
	int f = int(angle);
	angle = (angle - f) * 60;
	return d + f / 100. + angle / 10000;
}
//弧度转换至度分秒
double RadianToDegree(double radian) {
	return AngleToDegree(RadianToAngle(radian));
}
//度分秒转至弧度
double DegreeToRadian(double degree) {
	return AngleToRadian(DegreeToAngle(degree));
}
//计算方位角
double CalculateAzimuth(double x1, double y1, double x2, double y2) {
	double result = atan2(y2 - y1, x2 - x1);
	if (result < 0) {
		result += 2*PI;
	}
	return result;
}