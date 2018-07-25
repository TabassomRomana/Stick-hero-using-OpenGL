#include <stdio.h>
#include <windows.h>
#include <gl/glut.h>
#include <math.h>
#include <time.h>
double x0, x1, x2, x3, xs, Y0, Y1, Y2, Y3, ys, YS;
double angle, ang, update, upDown, touch, tempxs, tempxs2, tempYS;
double x4, x5, Y4, Y5;
double firsttranslate = 0;
double secondtranslate = 0;
double isReEvaluated = 0;
int start = 0;
void translate();
void Initialize()
{
	srand ( time(NULL) );
	x0 = 30;
	x1 = 100;
	xs = 100;

	Y0 = 200;
	Y1 = Y0;
	ys = Y0;
	YS = ys;
	do {
		x2 = rand() % 400;
		if(x2<1)
		{
			x2 = x2 + 100;
		}
		x3 = rand() % 400;
		if(x3 < x2)
		{
			x3 = x2 + 50;
		}
	} while (x2 > 500);

	Y2 = 200;
	Y3 = Y2;

	angle = 0;
	update = 0;
	upDown = 0;
	touch = 0;

}

void ReEvaluate()
{
		x4 = x2;
		x5 = x3;
		Y4 = 200;
		Y5 = Y4;
}

void init2() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 800);
}



void Object()
{

	glBegin(GL_POLYGON);
	glVertex2f(0, 800);
	glVertex2f(500, 800);
	glColor3f(1.0, 0.550, 1.0);
	glVertex2f(500, 0);
	glVertex2f(0, 0);
	glEnd();

	glColor4f(0.0, 0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(90,209);
	glVertex2i(90,225);
	glVertex2i(100,225);
	glVertex2i(100,209);
	glEnd();

	glColor4f(1.0, 0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(90,225);
	glVertex2i(90,227);
	glVertex2i(100,227);
	glVertex2i(100,225);
	glEnd();

	glColor4f(1.0, 0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(90,210);
	glVertex2i(90,211);
	glVertex2i(100,211);
	glVertex2i(100,210);
	glEnd();

	glColor4f(1.0, 1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(97,221);
	glVertex2i(97,222);
	glVertex2i(98.5,222);
	glVertex2i(98,221);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(80,224);
	glVertex2i(90,224);
	glEnd();



	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(83.5,221);
	glVertex2i(90,224);
	glEnd();

	glColor4f(0.0, 0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(90,203);
	glVertex2i(90,207);
	glVertex2f(93,207);
	glVertex2f(93,203);
	glEnd();

	glColor4f(0.0, 0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(97,203);
	glVertex2i(97,207);
	glVertex2i(100,207);
	glVertex2i(100,203);
	glEnd();



	 GLfloat twicePi = 2.0f * 3.1416f;
     glBegin(GL_TRIANGLE_FAN);
     glColor3f(1.0, 1.0, 1.0);
     for (double i = 0; i <= 20; i++)
     {
       glVertex2f(100 + (70  *cos(i * twicePi / 20)), 600 + (70 * sin (i * twicePi / 20)));
     }

	 glEnd();
	 glBegin(GL_POLYGON);
	 glColor3f(0.0, 0.0, 0.0);
	 glVertex2f(x0, 0);
	 glVertex2f(x0, Y0);
	 glVertex2f(x1, Y1);
	 glVertex2f(x1, 0);
	 glEnd();

	 glBegin(GL_POLYGON);
	 glColor3f(0.0, 0.0, 0.0);
	 glVertex2f(x2, 0);
	 glVertex2f(x2, Y2);
	 glVertex2f(x3, Y3);
	 glVertex2f(x3, 0);
	 glEnd();

	translate();

	glLineWidth(4);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(xs, ys);
	glVertex2f(xs, YS);
	glEnd();
	glutSwapBuffers();
}
void translate(){

	glTranslatef(xs, ys, 0.0);
	glRotatef(-angle, 0.0, 0.0, 1.0);
	glTranslatef(-xs, -ys, 0.0);

}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	Object();
	glPopMatrix();
	glFlush();
}



void updateStick(int value)
{
	if ((YS < 720) && (upDown == 0) && (update == 0))
	{
		YS += 10;
		if (YS >= 620)
			upDown = 1;
	}

	if ((YS > ys) && (upDown == 1) && (update == 0))
	{
		YS -= 10;
		if (YS <= ys)
			upDown = 0;
	}

	if ((update == 1) && (angle < 90))
	{
		angle += 2;

		tempxs = 0;
		tempxs2 = tempxs;
		tempYS = YS - ys;
		ang = (angle * 3.1416) / 180;

		tempxs = tempxs * cos(ang) + tempYS * sin(ang);
		tempYS = tempxs2 * sin(ang) + tempYS * cos(ang);
		tempxs = tempxs + xs;
		tempYS = tempYS + ys;

		if (tempxs >= x2)
		{
			if(tempxs <= x3)
			{
				touch = 1;
			}
			else{
				touch = 0;
			}

		}
		else{
			touch = 0;
		}

	}
	else {
		if (touch == 1 && firsttranslate == 0)
		{

			xs = 0;
			ys = 0;
			YS = 0;
			if (x1 > 0)
			{
				x0 = x0 - 4;
				x1 = x1 - 4;
			}

			else
			{
				firsttranslate = 1;
				x0 = x2;
				x1 = x3;
				Y0 = Y2;
				Y1 = Y3;
				if (isReEvaluated == 0)
				{
					ReEvaluate();
					isReEvaluated = 1;
				}
					srand ( time(NULL) );
				x2 = rand() % 400;
				if(x2<1)
				{
					x2 = x2 + 100;
				}
				x3 = rand() % 400;
				if(x3 < x2)
				{
					x3 = x2 + 50;
				}
                Y2 = Y4;
				Y3 = Y5;
			}
		}

		if (firsttranslate == 1)
		{
			if (x0 > 30)
			{
				x0 = x0 - 4;
				x1 = x1 - 4;
			}
			if (x2 > x4)
			{
				x2 = x2 - 4;
				x3 = x3 - 4;
			}
			else
			{
				secondtranslate = 1;
				firsttranslate = 0;
			}
		}
		if (secondtranslate == 1)
		{
			x0 = 50;
			x1 = 100;
			xs = 100;
			ys = Y0;
			YS = ys;
			srand ( time(NULL) );
				x2 = rand() % 400;
				if(x2<1)
				{
					x2 = x2 + 100;
				}
				x3 = rand() % 400;
				if(x3 < x2)
				{
					x3 = x2 + 50;
				}

			secondtranslate = 0;
			update = 0;
			angle = 0;
			touch = 0;
			isReEvaluated = 0;
		}
	}

	glutPostRedisplay();
	if (update == 0)
		glutTimerFunc(45, updateStick, update);
	else glutTimerFunc(30, updateStick, update);
}

void keyboard(unsigned char key, int x, int y) {
	if (key == ' ')
	{
		update = 1;
	}
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 800);
}

int main(int argc, char** argv)
{
	if (start == 0)
	{
		Initialize();
		start = 1;
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Stick Hero");
	glutDisplayFunc(display);
	init();
	glutKeyboardFunc(keyboard);
	glutTimerFunc(45, updateStick, update);
	glutMainLoop();
}

