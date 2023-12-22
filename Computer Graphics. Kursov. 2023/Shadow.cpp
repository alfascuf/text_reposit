#include "Shadow.h"
Shadow::Shadow() : RobertsAlgorithm(0, 0, 10000)
{
	center();
	xLight = xCenter;
	yLight = 1;
	zLight = zCenter;
	calculatePlaneCoefficients();
}

void Shadow::calculatePlaneCoefficients()
{
	int xPl[3], yPl[3], zPl[3];
	xPl[0] = 470; yPl[0] = 500; zPl[0] = 20;
	xPl[1] = 570; yPl[1] = 500; zPl[1] = 20;
	xPl[2] = 490; yPl[2] = 520; zPl[2] = 180;

	int vector1[3], vector2[3];
	vector1[0] = xPl[1] - xPl[0];
	vector2[0] = xPl[2] - xPl[0];
	vector1[1] = yPl[1] - yPl[0];
	vector2[1] = yPl[2] - yPl[0];
	vector1[2] = zPl[1] - zPl[0];
	vector2[2] = zPl[2] - zPl[0];

	A = vector1[1] * vector2[2] - vector2[1] * vector1[2];
	B = vector1[2] * vector2[0] - vector2[2] * vector1[0];
	C = vector1[0] * vector2[1] - vector2[0] * vector1[1];
	D = -(A * xPl[0] + B * yPl[0] + C * zPl[0]);

	m = xLight - x[0];
	n = yLight - y[0];
	p = zLight - z[0];
}

void Shadow::paint()
{
	algorithm();
	intersection();

	int arrayBuf[N][4];
	for (int i = 0; i < N; i++)
	{
		arrayBuf[i][0] = xShadow[i];
		arrayBuf[i][1] = yShadow[i];
		arrayBuf[i][2] = zShadow[i];
		arrayBuf[i][3] = 1;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			transformationMatrix[i][j] = 0;
	}

	// oblique
	transformationMatrix[3][3] = 1;
	int a = 45;
	transformationMatrix[0][0] = 1;
	transformationMatrix[1][1] = 1;
	transformationMatrix[3][3] = 1;
	transformationMatrix[0][2] = -cos(a * 3.141592 / 180);
	transformationMatrix[1][2] = -sin(a * 3.141592 / 180);

	float buf[4], buf1[4];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 4; j++)
			buf1[j] = 0;
		buf[0] = (float)arrayBuf[i][0];
		buf[1] = (float)arrayBuf[i][1];
		buf[2] = (float)arrayBuf[i][2];
		buf[3] = (float)arrayBuf[i][3];

		for (int k = 0; k < 4; k++)
			for (int t = 0; t < 4; t++)
				buf1[k] += buf[t] * transformationMatrix[t][k];

		arrayBuf[i][0] = (int)buf1[0];
		arrayBuf[i][1] = (int)buf1[1];
	}

	SelectObject(memDeviceContext, GetStockObject(DC_PEN));
	SetDCPenColor(memDeviceContext, RGB(255, 255, 255));


	MoveToEx(memDeviceContext, arrayBuf[0][0], arrayBuf[0][1], NULL);
	LineTo(memDeviceContext, arrayBuf[1][0], arrayBuf[1][1]);
	LineTo(memDeviceContext, arrayBuf[5][0], arrayBuf[5][1]);
	LineTo(memDeviceContext, arrayBuf[0][0], arrayBuf[0][1]);
	LineTo(memDeviceContext, arrayBuf[4][0], arrayBuf[4][1]);
	LineTo(memDeviceContext, arrayBuf[2][0], arrayBuf[2][1]);
	LineTo(memDeviceContext, arrayBuf[3][0], arrayBuf[3][1]);
	LineTo(memDeviceContext, arrayBuf[4][0], arrayBuf[4][1]);

	MoveToEx(memDeviceContext, arrayBuf[1][0], arrayBuf[1][1], NULL);
	LineTo(memDeviceContext, arrayBuf[3][0], arrayBuf[3][1]);

	MoveToEx(memDeviceContext, arrayBuf[2][0], arrayBuf[2][1], NULL);
	LineTo(memDeviceContext, arrayBuf[5][0], arrayBuf[5][1]);
	fillBlock(0, 6, arrayBuf, RGB(100, 100, 100));


	MoveToEx(memDeviceContext, arrayBuf[8][0], arrayBuf[8][1], NULL);
	LineTo(memDeviceContext, arrayBuf[9][0], arrayBuf[9][1]);
	LineTo(memDeviceContext, arrayBuf[7][0], arrayBuf[7][1]);
	LineTo(memDeviceContext, arrayBuf[8][0], arrayBuf[8][1]);

	MoveToEx(memDeviceContext, arrayBuf[6][0], arrayBuf[6][1], NULL);
	LineTo(memDeviceContext, arrayBuf[8][0], arrayBuf[8][1]);

	MoveToEx(memDeviceContext, arrayBuf[6][0], arrayBuf[6][1], NULL);
	LineTo(memDeviceContext, arrayBuf[9][0], arrayBuf[9][1]);

	MoveToEx(memDeviceContext, arrayBuf[6][0], arrayBuf[6][1], NULL);
	LineTo(memDeviceContext, arrayBuf[7][0], arrayBuf[7][1]);

	fillBlock(6, 10, arrayBuf, RGB(100, 100, 100));


	HWND handle = GetConsoleWindow();
	HDC deviceContext = GetDC(handle);
	BitBlt(deviceContext, 0, 0, 1080, 700, memDeviceContext, 0, 0, SRCCOPY);
}

void Shadow::intersection()
{
	for (int i = 0; i < N; i++)
	{
		float t = (float)(-A * x[i] - B * y[i] - C * z[i] - D) / (A * m + B * n + C * p);
		xShadow[i] = m * t + x[i];
		yShadow[i] = n * t + y[i];
		zShadow[i] = p * t + z[i];
	}
}