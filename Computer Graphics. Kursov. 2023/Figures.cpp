#include <Windows.h>
#include "figures.h"
Figures::Figures()
{
	x[0] = 550; y[0] = 250; z[0] = -35;
	x[1] = 630; y[1] = 140; z[1] = 50;
	x[2] = 510; y[2] = 180; z[2] = 120;
	x[3] = 590; y[3] = 180; z[3] = 150;
	x[4] = 510; y[4] = 280; z[4] = 80;
	x[5] = 540; y[5] = 140; z[5] = 20;
	x[6] = 570; y[6] = 210; z[6] = 70;
	x[7] = 510; y[7] = 240; z[7] = -50;
	x[8] = 500; y[8] = 140; z[8] = 10;
	x[9] = 470; y[9] = 290; z[9] = 60;
	intersection(0, 2, 4, 6, 7, 10);
	intersection(0, 2, 4, 6, 8, 11);
	intersection(0, 2, 4, 6, 9, 12);
	clearTransformationMatrix();
	center();

	HWND handle = GetConsoleWindow();
	HDC deviceContext = GetDC(handle);
	memDeviceContext = CreateCompatibleDC(deviceContext);
	memBitmap = CreateCompatibleBitmap(deviceContext, 1080, 700);
	SelectObject(memDeviceContext, memBitmap);
}

Figures::~Figures()
{
	DeleteDC(memDeviceContext);
	DeleteObject(memBitmap);
}

void Figures::transformationMatrixMultiplication()
{
	float buf[4], buf1[4];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 4; j++)
			buf1[j] = 0;
		buf[0] = (float)x[i];
		buf[1] = (float)y[i];
		buf[2] = (float)z[i];
		buf[3] = 1;

		for (int k = 0; k < 4; k++)
			for (int t = 0; t < 4; t++)
				buf1[k] += buf[t] * transformationMatrix[t][k];

		x[i] = (int)buf1[0];
		y[i] = (int)buf1[1];
		z[i] = (int)buf1[2];
	}
}

void Figures::center()
{
	xCenter = 0;
	yCenter = 0;
	zCenter = 0;

	for (int i = 0; i < N; i++)
	{
		xCenter += x[i];
		yCenter += y[i];
		zCenter += z[i];
	}

	xCenter /= N;
	yCenter /= N;
	zCenter /= N;
}

void Figures::center(int index1, int index2)
{
	xCenter = 0;
	yCenter = 0;
	zCenter = 0;

	for (int i = index1; i < index2; i++)
	{
		xCenter += x[i];
		yCenter += y[i];
		zCenter += z[i];
	}

	xCenter /= (index2 - index1);
	yCenter /= (index2 - index1);
	zCenter /= (index2 - index1);
}

void Figures::clearTransformationMatrix()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (i == j)
				transformationMatrix[i][j] = 1;
			else
				transformationMatrix[i][j] = 0;
}

void Figures::intersection(int planePoint1, int planePoint2, int planePoint3,
	int linePoint1, int linePoint2, int resultIndex)
{
	int delta21[3], delta31[3];

	delta21[0] = x[planePoint2] - x[planePoint1];
	delta21[1] = y[planePoint2] - y[planePoint1];
	delta21[2] = z[planePoint2] - z[planePoint1];

	delta31[0] = x[planePoint3] - x[planePoint1];
	delta31[1] = y[planePoint3] - y[planePoint1];
	delta31[2] = z[planePoint3] - z[planePoint1];

	int A = delta21[1] * delta31[2] - delta31[1] * delta21[2];
	int B = delta21[2] * delta31[0] - delta31[2] * delta21[0];
	int C = delta21[0] * delta31[1] - delta31[0] * delta21[1];
	int D = -(A * x[planePoint1] + B * y[planePoint1] + C * z[planePoint1]);

	int m = x[linePoint2] - x[linePoint1];
	int n = y[linePoint2] - y[linePoint1];
	int p = z[linePoint2] - z[linePoint1];

	float t = (float)(-A * x[linePoint1] - B * y[linePoint1] - C * z[linePoint1] - D) / (A * m + B * n + C * p);

	x[resultIndex] = m * t + x[linePoint1];
	y[resultIndex] = n * t + y[linePoint1];
	z[resultIndex] = p * t + z[linePoint1];
}

void Figures::move(arguments coordinate, arguments sign)
{
	clearTransformationMatrix();

	float i = (sign == PLUS) ? 10 : -10;
	if (coordinate == X)
		transformationMatrix[3][0] = i;
	if (coordinate == Y)
		transformationMatrix[3][1] = i;
	if (coordinate == Z)
		transformationMatrix[3][2] = i;
	transformationMatrixMultiplication();
}
void Figures::scale(arguments sign)
{
	clearTransformationMatrix();

	center();

	float scaleCoefficient = (sign == PLUS) ? (float)1.1 : (float)0.9;

	transformationMatrix[0][0] = transformationMatrix[1][1] = transformationMatrix[2][2] = scaleCoefficient;
	transformationMatrix[3][0] = xCenter * (1 - scaleCoefficient);
	transformationMatrix[3][1] = yCenter * (1 - scaleCoefficient);
	transformationMatrix[3][2] = zCenter * (1 - scaleCoefficient);

	transformationMatrixMultiplication();
}

void Figures::rotate(arguments coordinate, arguments sign)
{
	clearTransformationMatrix();
	center();
	int fi = (sign == PLUS) ? 5 : -5;

	switch (coordinate)
	case X:
	{
		transformationMatrix[1][1] = transformationMatrix[2][2] = (float)cos(fi * M_PI / 180);
		transformationMatrix[1][2] = (float)sin(fi * M_PI / 180);
		transformationMatrix[2][1] = (float)-sin(fi * M_PI / 180);
		transformationMatrix[3][1] = yCenter * (1 - (float)cos(fi * M_PI / 180)) + zCenter * (float)sin(fi * M_PI / 180);
		transformationMatrix[3][2] = zCenter * (1 - (float)cos(fi * M_PI / 180)) - yCenter * (float)sin(fi * M_PI / 180);

		break;
	case Y:
		transformationMatrix[0][0] = transformationMatrix[2][2] = (float)cos(fi * M_PI / 180);
		transformationMatrix[0][2] = (float)-sin(fi * M_PI / 180);
		transformationMatrix[2][0] = (float)sin(fi * M_PI / 180);
		transformationMatrix[3][0] = xCenter * (1 - (float)cos(fi * M_PI / 180)) - zCenter * (float)sin(fi * M_PI / 180);
		transformationMatrix[3][2] = zCenter * (1 - (float)cos(fi * M_PI / 180)) + xCenter * (float)sin(fi * M_PI / 180);

		break;
	case Z:
		transformationMatrix[0][0] = transformationMatrix[1][1] = (float)cos(fi * M_PI / 180);
		transformationMatrix[0][1] = (float)sin(fi * M_PI / 180);
		transformationMatrix[1][0] = (float)-sin(fi * M_PI / 180);
		transformationMatrix[3][0] = xCenter * (1 - (float)cos(fi * M_PI / 180)) + yCenter * (float)sin(fi * M_PI / 180);
		transformationMatrix[3][1] = yCenter * (1 - (float)cos(fi * M_PI / 180)) - xCenter * (float)sin(fi * M_PI / 180);

		break;
	}

	transformationMatrixMultiplication();
}
void Figures::drawEdges()
{
	int coordinates[N][4];

	for (int i = 0; i < N; i++)
	{
		coordinates[i][0] = x[i];
		coordinates[i][1] = y[i];
		coordinates[i][2] = z[i];
		coordinates[i][3] = 1;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			transformationMatrix[i][j] = 0;
	}

	/* isometric */
	/*
	matrix[3][3] = 1;
	int a = 45;
	int b = 35.26;
	matrix[0][0] = cos(a * M_PI / 180);
	matrix[0][1] = sin(a * M_PI / 180) * sin(b * M_PI / 180);
	matrix[1][1] = cos(b * M_PI / 180);
	matrix[2][0] = sin(a * M_PI / 180);
	matrix[2][1] = -cos(a * M_PI / 180) * sin(b * M_PI / 180);
	*/

	/* oblique */
	transformationMatrix[3][3] = 1;
	int a = 45;
	transformationMatrix[0][0] = 1;
	transformationMatrix[1][1] = 1;
	transformationMatrix[3][3] = 1;
	transformationMatrix[0][2] = -cos(a * M_PI / 180);
	transformationMatrix[1][2] = -sin(a * M_PI / 180);
	float buf[4], buf1[4];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 4; j++)
			buf1[j] = 0;
		buf[0] = (float)coordinates[i][0];
		buf[1] = (float)coordinates[i][1];
		buf[2] = (float)coordinates[i][2];
		buf[3] = (float)coordinates[i][3];
		for (int k = 0; k < 4; k++)
			for (int t = 0; t < 4; t++)
				buf1[k] += buf[t] * transformationMatrix[t][k];
		coordinates[i][0] = (int)buf1[0];
		coordinates[i][1] = (int)buf1[1];
	}

	SelectObject(memDeviceContext, GetStockObject(DC_BRUSH));
	SetDCBrushColor(memDeviceContext, RGB(12, 12, 12));
	SelectObject(memDeviceContext, GetStockObject(DC_PEN));
	SetDCPenColor(memDeviceContext, RGB(12, 12, 12));
	Rectangle(memDeviceContext, 0, 0, 1080, 700);
	SelectObject(memDeviceContext, GetStockObject(DC_BRUSH));
	SetDCBrushColor(memDeviceContext, RGB(255, 255, 255));
	SelectObject(memDeviceContext, GetStockObject(DC_PEN));
	SetDCPenColor(memDeviceContext, RGB(255, 255, 255));


	MoveToEx(memDeviceContext, coordinates[0][0], coordinates[0][1], NULL);
	LineTo(memDeviceContext, coordinates[1][0], coordinates[1][1]);
	LineTo(memDeviceContext, coordinates[7][0], coordinates[7][1]);
	LineTo(memDeviceContext, coordinates[2][0], coordinates[2][1]);
	LineTo(memDeviceContext, coordinates[0][0], coordinates[0][1]);
	LineTo(memDeviceContext, coordinates[3][0], coordinates[3][1]);
	LineTo(memDeviceContext, coordinates[6][0], coordinates[6][1]);
	LineTo(memDeviceContext, coordinates[4][0], coordinates[4][1]);
	LineTo(memDeviceContext, coordinates[5][0], coordinates[5][1]);
	LineTo(memDeviceContext, coordinates[3][0], coordinates[3][1]);
	MoveToEx(memDeviceContext, coordinates[1][0], coordinates[1][1], NULL);
	LineTo(memDeviceContext, coordinates[6][0], coordinates[6][1]);
	MoveToEx(memDeviceContext, coordinates[2][0], coordinates[2][1], NULL);
	LineTo(memDeviceContext, coordinates[5][0], coordinates[5][1]);
	MoveToEx(memDeviceContext, coordinates[4][0], coordinates[4][1], NULL);
	LineTo(memDeviceContext, coordinates[7][0], coordinates[7][1]);
	MoveToEx(memDeviceContext, coordinates[8][0], coordinates[8][1], NULL);
	LineTo(memDeviceContext, coordinates[9][0], coordinates[9][1]);
	LineTo(memDeviceContext, coordinates[10][0], coordinates[10][1]);
	LineTo(memDeviceContext, coordinates[8][0], coordinates[8][1]);
	MoveToEx(memDeviceContext, coordinates[11][0], coordinates[11][1], NULL);
	LineTo(memDeviceContext, coordinates[8][0], coordinates[8][1]);
	MoveToEx(memDeviceContext, coordinates[11][0], coordinates[11][1], NULL);
	LineTo(memDeviceContext, coordinates[9][0], coordinates[9][1]);
	MoveToEx(memDeviceContext, coordinates[11][0], coordinates[11][1], NULL);
	LineTo(memDeviceContext, coordinates[10][0], coordinates[10][1]);
	HWND handle = GetConsoleWindow();
	HDC deviceContext = GetDC(handle);
	BitBlt(deviceContext, 0, 0, 1080, 700, memDeviceContext, 0, 0, SRCCOPY);
}