#include "stdafx.h"
#include "gltools.h" 
#include "math3d.h" 
#include "glframe.h" 
#include <stdio.h>
#include <gl/glut.h>
#include <gl/glu.h>
#include <gl/gl.h>

GLfloat xr = -2.8;
GLfloat yr = 4;//太阳


GLfloat y4=6;
GLfloat y3 = 6;
GLfloat y2 = 6;
GLfloat y5 = 6;
GLfloat y6 = 6;
GLfloat y7 = 6;
GLfloat y8 = 6;
GLfloat y9 = 6;
GLfloat y10 = 6;
GLfloat y11 = 6;
GLfloat y12 = 6;
GLfloat y13 = 6;
GLfloat y14 = 6;
GLfloat y15 = 6;
GLfloat y16 = 6;
GLfloat y17 = 6;
GLfloat y18 = 6;
GLfloat y19 = 6;
GLfloat y20 = 6;
GLfloat y21 = 6;
GLfloat y22 = 6;
GLfloat y23 = 6;






// move steps
GLfloat xrstep = 0.006;
GLfloat yrstep = 0.0008;

GLfloat ystep=0.01;//
GLfloat ystep3 = 0.11;
GLfloat ystep2 = 0.02;
GLfloat ystep5 = 0.023;
GLfloat ystep6 = 0.031;
GLfloat ystep7 = 0.015;
GLfloat ystep8 = 0.017;
GLfloat ystep9 = 0.024;
GLfloat ystep10 = 0.021;
GLfloat ystep11 = 0.009;
GLfloat ystep12 = 0.026;

GLfloat ystep13 = 0.1;
GLfloat ystep14 = 0.02;
GLfloat ystep15 = 0.015;

GLfloat ystep16 = 0.011;
GLfloat ystep17 = 0.021;
GLfloat ystep18 = 0.014;
GLfloat ystep19 = 0.017;
GLfloat ystep20 = 0.019;
GLfloat ystep21 = 0.012;
GLfloat ystep22 = 0.024;
GLfloat ystep23 = 0.008;




void TimerFunction(int value)
{

	
	if (y4<-0.5)
	{
		ystep = -ystep;
	}
	if (y3<-0.5)
	{
		ystep3 = -ystep3;
	}
	if (y2<-0.5)
	{
		ystep2 = -ystep2;
	}
	if (y5<-0.5)
	{
		ystep5 = -ystep5;
	}
	if (y6<-0.5)
	{
		ystep6 = -ystep6;
	}
	if (y7<-0.5)
	{
		ystep7 = -ystep7;
	}
	
	if (y8<-0.5)
	{
		ystep8 = -ystep8;
	}
	if (y9<-0.5)
	{
		ystep9 = -ystep9;
	}
	if (y10<-0.5)
	{
		ystep10 = -ystep10;
	}
	if (y11<-0.5)
	{
		ystep11 = -ystep11;
	}
	if (y12<-0.5)
	{
		ystep12 = -ystep12;
	}

	if (y13<1.6)
	{
		y13 = -100;
	}
	if (y14<1.8)
	{
		y14 = -100;
	}
	if (y15<1.7)
	{
		y15 = -100;
	}

	if (y16<2.4)
	{
		y16 = -100;
	}
	if (y17<2.6)
	{
		y17 = -100;
	}
	if (y18<3)
	{
		y18 = -100;
	}
	if (y19<3.9)
	{
		y19 = -100;
	}
	if (y20<4.2)
	{
		y20 = -100;
	}
	if (y21<2.7)
	{
		y21 = -100;
	}
	if (y22<2.2)
	{
		y22 = -100;
	}
	if (y23<3.8)
	{
		y23 = -100;
	}
	
	y4 -= ystep;
	y2 -= ystep;
	y3 -= ystep3;
	y5 -= ystep5;
	y6 -= ystep6;
	y7 -= ystep7;
	y8 -= ystep8;
	y9 -= ystep9;
	y10 -= ystep10;
	y11 -= ystep11;
	y12 -= ystep12;
	y13 -= ystep13;
	y14 -= ystep14;
	y15 -= ystep15;
	y16 -= ystep16;
	y17 -= ystep17;
	y18 -= ystep18;
	y19 -= ystep19;
	y20 -= ystep20;
	y21 -= ystep21;
	y22 -= ystep22;
	y23 -= ystep23;
	xr += xrstep;
	yr -= yrstep;

	// redraw the scene with new coordinates
	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}



GLFrame objFrame; void SetupRC()
{
	glClearColor(0.3f, 0.3f, 0.5f, 1.0f); //开启深度检测，消除隐藏面 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW); //开启光照 
	GLfloat whiteLight[] = { 0.05f, 0.05f, 0.05f, 1.0f };
	GLfloat sourceLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };
	GLfloat lightPos[] = { -5.0f, 15.0f, 5.0f, 1.0f };

	glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE, sourceLight);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0); //开启颜色追踪 
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

} void ChangeSize(GLsizei w, GLsizei h)
{
	if (h == 0)
		h = 1;

	glViewport(0, 0, w, h);
	GLfloat aspect = (GLfloat)w / (GLfloat)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(35.0, aspect, 1.0, 40.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void pause()
{
	xrstep = 0;
	yrstep = 0;
}

void changeX(GLfloat direction)
{
	xrstep = xrstep + 1.0f*direction;
}

void changeY(GLfloat direction)
{
	yrstep = yrstep + 1.0f*direction;
}

void keyboard(unsigned char key, int x, int y)

{
	switch (key)
	{

	case 'd':
		
		xr = xr + 0.6;
		yr = yr - 0.1;
		glutPostRedisplay();
		break;
	case 'a':
		xr = xr - 0.6;
		yr = yr + 0.1;;
		glutPostRedisplay();
		break;
	case 'p':
		pause();
		glutPostRedisplay();
		break;
	case 'q':
		changeX(0.08);
		changeY(0.015);
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //设置二次方程的状态 
	GLUquadricObj *quadricObj = gluNewQuadric();
	gluQuadricNormals(quadricObj, GLU_SMOOTH);

	glPushMatrix();
	glTranslatef(0.0f, -2.0f, -8.0f);

	glPushMatrix(); 
	//画三个雪球 
	glColor3f(1.0f, 1.0f, 1.0f);
	gluSphere(quadricObj, 0.65f, 26, 13);

	glTranslatef(0.0f, 0.85f, 0.0f);
	gluSphere(quadricObj, 0.42f, 26, 13);

	glTranslatef(0.0f, 0.63f, 0.0f);
	gluSphere(quadricObj, 0.36f, 26, 13); 
	//画两个眼睛 
	glTranslatef(-0.2f, 0.1f, 0.31f);
	glColor3f(0.0f, 0.0f, 0.0f);
	gluSphere(quadricObj, 0.05f, 26, 13);

	glTranslatef(0.4f, 0.0f, 0.0f);
	gluSphere(quadricObj, 0.05f, 26, 13); 
	//画一个鼻子 
	glTranslatef(-0.2f, -0.08f, 0.03f);
	glColor3f(1.0f, 0.3f, 0.3f);
	gluCylinder(quadricObj, 0.04f, 0.0f, 0.6f, 26, 13);
	
	glPopMatrix(); 

	//化雪
	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(-1.3f, y4-ystep, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.8f, y3 - ystep3, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0f, y2 - ystep2, 0.0f);
    gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.2f, y5 - ystep5, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.6f, y6 - ystep6, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
    glTranslatef(-2.2f, y7 - ystep7, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.3f, y8 - ystep8, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.6f, y9 - ystep9, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.8f, y10 - ystep10, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.1f, y11- ystep11, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.2f, y12 - ystep12, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.7f, y13 - ystep13, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4f, y14 - ystep14, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, y15 - ystep15, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.7f, y16 - ystep16, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0f, y17 - ystep17, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.3f, y18 - ystep18, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.7f, y19 - ystep19, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0f, y20 - ystep20, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.0f, y21 - ystep21, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.6f, y22 - ystep22, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.3f, y23 - ystep23, 0.0f);
	gluSphere(quadricObj, 0.06f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0.6, 0.0);
	glTranslatef(xr, yr, 0.0f);
	gluSphere(quadricObj, 0.3f, 26, 13);
	glPopMatrix();//画太阳

	//画帽子 
	glPushMatrix();
	glColor3f(0.1, 0.8, 0.0);
	glTranslatef(-0.4f, 1.2f, 0.8f);
	gluCylinder(quadricObj, 0.2f, 0.0f, 3.3f, 26, 13);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.8, 0.0);
	glTranslatef(0.4f, 1.2f, 0.8f);
	gluCylinder(quadricObj, 0.2f, 0.0f, 3.3f, 26, 13);
	glPopMatrix();

	

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	
	glTranslatef(0.0f, 2.2f, 0.0f);
	glRotatef(90.0, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadricObj, 0.2f, 0.2f, 0.4f, 26, 13);

	glPushMatrix();
	glColor3f(1.0f, 0.6f, 0.2f);
	glTranslatef(6.0f, -15.2f, 0.2f);
	gluCylinder(quadricObj, 0.5f, 0.5f, 152.0f, 26, 13);
	glColor3f(0.0f, 0.8f, 0.0f);
	glTranslatef(1.2f, -5.2f, -5.0f);
	gluCylinder(quadricObj, 0.0f, 5.8f, 5.0f, 56, 13);
	glColor3f(0.0f, 0.6f, 0.0f);
	glTranslatef(0.0f, 0.0f, -2.0f);
	gluCylinder(quadricObj, 0.0f, 3.62f, 5.0f, 56, 13);
	glColor3f(0.0f, 0.2f, 0.0f);
	glTranslatef(0.0f, 0.0f, -0.3f);
	gluCylinder(quadricObj, 0.0f, 2.22f, 2.5f, 56, 13);
	glPopMatrix();//tree

	glDisable(GL_CULL_FACE);
	glColor3f(0, 1, 0);
	gluDisk(quadricObj, 0.17f, 0.2f, 26, 13);

	glTranslatef(0.0f, 0.0f, 0.40f);
	gluDisk(quadricObj, 0.0f, 0.4f, 26, 13);
	glEnable(GL_CULL_FACE);
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
} //通过按键来移动和旋转

int main(int args, char **argv)
{
	glutInit(&args, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowSize(1000, 640);
	glutCreateWindow("下雪");

	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(13, TimerFunction, 1);
	SetupRC();


	glutMainLoop();
	return 0;
}