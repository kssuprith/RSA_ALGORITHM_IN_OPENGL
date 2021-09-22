// rsa encryption decryption.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#define SCENE 10
using namespace std;
void *currentfont;

enum { FRONTPAGE,ENCRYPTION,ENCRYPTIONINFO,WITHOUTENCRYPTION,EXIT };

int width = 650, height = 650;
int lineheight=500;
int linemargin=500;
int currentheight=400;

void *font =GLUT_BITMAP_HELVETICA_12;
void *fonts[] =
{
	GLUT_BITMAP_9_BY_15,
	GLUT_BITMAP_TIMES_ROMAN_10,
	GLUT_BITMAP_TIMES_ROMAN_24,
	GLUT_BITMAP_HELVETICA_12,
	GLUT_BITMAP_HELVETICA_10,
	GLUT_BITMAP_HELVETICA_18,
};


void output2(int x, int y, char *string,int j)
{
	int len, i;
	glColor3f(1.0f,0.0f,1.0f);
	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for(i = 0; i < len; i++)
		glutBitmapCharacter(fonts[j], string[i]);
}


void output(int x, int y, char *string,int j)
{
	int len,i;
	glColor3f(1.0f,1.0f,0.0f);
	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for(i = 0; i < len; i++)
		glutBitmapCharacter(fonts[j], string[i]);
}

void delay(void)
{
	int i,j,k;
	for(i=0;i<5000;i++)
	{
		for(j=0;j<10000;j++);
		for(k=0;k<15000;k++);
		
	}
}
void delay1(void)
{
	int i;
	for(i=0;i<100000;i++);
}

void front_page()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glClearColor(0.4f,0.2f,0.3f,1.0f);
	output(160,650,"SAPTHAGIRI COLLEGE OF ENGINEERING BANGALORE",2);
	output(150,620,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING",2);
	output(140,550," COMPUTER GRAPHICS LABORATORY WITH MINI PROJECT(18CSL67)",2);
	output(150,520,"TOPIC : RSA ENCRYPTION AND DECRYPTION ALGORITHM",2);
	output(280,450," NIRANJAN S[1SG18CS065]",2 );
	output(280,400,"SUPRITH K S[1SG18CS116]",2);
	output(180,350,"UNDER THE GUIDANCE OF",2);
	output(250,310,"PROF.SURESH KUMAR & PROF.ANURADHA B",2);
	output(230,280,"ASSISTANT PROFESSOR,DEPARTMENT OF CSE,SCE",2);
	//output(175,150,"name 2",2);
	
	output(275,150,"->PRESS S TO START",2);
	glutPostRedisplay();
	glFlush();
	glCallList(SCENE);
	glPopMatrix();
	glutSwapBuffers();
}

void encryptioninfo()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glClearColor(1.0f,0.1f,2.1f,1.0f);
	output(170,550," the message is:",2);
	output(290,500,"SCE",2);
	output(160,450,"the key is :",2);
	output(290,400,"p=11 &q=13",2);
	output(100,100,"->press w or W to view without using rsa encryption and decryption",2);
	output(100,50,"->press e or E to view  rsa encryption and decryption",2);
	glFlush();
	glCallList(SCENE);
	glPopMatrix();
	glutSwapBuffers();
}

GLint movement_angle=0,packet_angle=0,head_angle=0,packet_angle1=0,head_angle1=0,packet_angle2=0,head_angle2=0,packet_angle3=0,head_angle3=0,packet_angle4=0;
GLdouble mov_speed = 1;
GLint head_angle4=0,packet_angle5=0,head_angle5=0,packet_angle6=0,head_angle6=0,packet_angle7,head_angle7=0,packet_angle8=40;

GLint movement_angle1=0,arrow_angle=0,rev_arrow_angle=0,phy_header_angle=0,rev_phy_header_angle=0,rev_phy_header_angle1=0,phy_header_angle1=0,analog_sig_angle=0,rev_analog_sig_angle = 0;


void animation_encrypt(void)
{
	delay1();
	if ((movement_angle += mov_speed) >= 600)
		movement_angle=600;

	if ((arrow_angle +=mov_speed)>=150)
		arrow_angle=150;
	if (arrow_angle==150)
		if((phy_header_angle +=mov_speed)>=100)
			phy_header_angle=100;
	if (phy_header_angle==100)
		if((phy_header_angle1 +=mov_speed)>=100)
			phy_header_angle1=100;
	if (phy_header_angle1==100)
		if((analog_sig_angle += mov_speed)>=100)
			analog_sig_angle=100;
	if (analog_sig_angle==100)
		if((movement_angle1 += mov_speed)>=420)
			movement_angle1=420;
	if (movement_angle1==420)
		if((rev_analog_sig_angle +=mov_speed)>=100)
			rev_analog_sig_angle=100;
	if (rev_analog_sig_angle ==100)
		if((rev_phy_header_angle +=mov_speed)>=200)
			rev_phy_header_angle=200;
	if (rev_phy_header_angle==200)
		if((rev_phy_header_angle1 +=mov_speed)>=100)
			rev_phy_header_angle1=100;
	if (rev_phy_header_angle==200)
		if((rev_arrow_angle +=mov_speed)>=100)
			rev_arrow_angle=100;
	glutPostRedisplay();
}

void computer()
{
	glColor3f(0.75,0.85,0.65);
	glBegin(GL_QUADS);
	glVertex2f(55.0,340.0);
	glVertex2f(145.0,340.0);
	glVertex2f(150.0,350.0);
	glVertex2f(60.0,350.0);
	glEnd();

	glColor3f(0.75,0.85,0.65);
	glBegin(GL_LINE_LOOP);
	glVertex2f(60.0,355.0);
	glVertex2f(150.0,355.0);
	glVertex2f(150.0,370.0);
	glVertex2f(60.0,370.0);
	glEnd();

	glColor3f(0.75,0.85,0.65);
	glBegin(GL_LINE_LOOP);
	glVertex2f(75.0,380.0);
	glVertex2f(135.0,380.0);
	glVertex2f(135.0,430.0);
	glVertex2f(75.0,430.0);
	glEnd();

	glColor3f(0.7,0.8,0.6);
	glBegin(GL_QUADS);
	glVertex2f(80.0,385.0);
	glVertex2f(130.0,385.0);
	glVertex2f(130.0,425.0);
	glVertex2f(80.0,425.0);
	glEnd();

	glColor3f(0.75,0.85,0.65);
	glBegin(GL_LINES);
	glVertex2f(90.0,370.0);
	glVertex2f(90.0,380.0);
	glVertex2f(120.0,370.0);
	glVertex2f(120.0,380.0);
	glEnd();
}

void computer_dest()
{
	glColor3f(0.75,0.85,0.65);
	glBegin(GL_QUADS);
	glVertex2f(545.0,525.0);
	glVertex2f(635.0,525.0);
	glVertex2f(640.0,535.0);
	glVertex2f(550.0,535.0);
	glEnd();

	glColor3f(0.75,0.85,0.65);
	glBegin(GL_LINE_LOOP);
	glVertex2f(550.0,540.0);
	glVertex2f(640.0,540.0);
	glVertex2f(640.0,555.0);
	glVertex2f(550.0,555.0);
	glEnd();

	glColor3f(0.75,0.85,0.65);
	glBegin(GL_LINE_LOOP);
	glVertex2f(565.0,565.0);
	glVertex2f(625.0,565.0);
	glVertex2f(625.0,615.0);
	glVertex2f(565.0,615.0);
	glEnd();

	glColor3f(0.7,0.8,0.6);
	glBegin(GL_QUADS);
	glVertex2f(570.0,570.0);
	glVertex2f(620.0,570.0);
	glVertex2f(620.0,610.0);
	glVertex2f(570.0,610.0);
	glEnd();

	glColor3f(0.75,0.85,0.65);
	glBegin(GL_LINES);
	glVertex2f(580.0,555.0);
	glVertex2f(580.0,565.0);
	glVertex2f(610.0,555.0);
	glVertex2f(610.0,565.0);
	glEnd();
}

void computer_mid()
{
	glColor3f(0.75,0.85,0.65);
	glBegin(GL_QUADS);
	glVertex2f(300.0,50.0);
	glVertex2f(410.0,50.0);
	glVertex2f(420.0,60.0);
	glVertex2f(305.0,60.0);
	glEnd();

	glColor3f(0.75,0.85,0.65);
	glBegin(GL_LINE_LOOP);
	glVertex2f(305.0,65.0);
	glVertex2f(415.0,65.0);
	glVertex2f(415.0,80.0);
	glVertex2f(305.0,80.0);
	glEnd();

	glColor3f(0.75,0.85,0.65);
	glBegin(GL_LINE_LOOP);
	glVertex2f(320.0,100.0);
	glVertex2f(400.0,100.0);
	glVertex2f(400.0,150.0);
	glVertex2f(320.0,150.0);
	glEnd();

	glColor3f(0.7,0.8,0.6);
	glBegin(GL_QUADS);
	glVertex2f(325.0,105.0);
	glVertex2f(395.0,105.0);
	glVertex2f(395.0,145.0);
	glVertex2f(325.0,145.0);
	glEnd();

	glColor3f(0.75,0.85,0.65);
	glBegin(GL_LINES);
	glVertex2f(335.0,80.0);
	glVertex2f(335.0,100.0);
	glVertex2f(385.0,80.0);
	glVertex2f(385.0,100.0);
	glEnd();
}

static long gcd(long m,long n)
{
	long r;
	while(n!=0)
	{
		r=m%n;
		m=n;
		n=r;
	}
	return m;
}

void encrypt(int x,int y,int z)
{
	string msg="SCE";
	long encrypted[100];
	long num[100];
	int p=11,q=13,phi,i,len,e,d,j;
	int n=p*q;
	phi=(p-1)*(q-1);
	for(i=2;i<phi;i++)
		if(gcd(i,phi)==1)
			break;
	e=i;
	for(i=2;i<phi;i++)
		if((e*i-1)%phi==0)
			break;
	d=i;
	len=msg.length();

	for(i=0;i<len;i++)
		num[i]=msg[i];

	for(i=0;i<len;i++)
	{
		encrypted[i]=1;
		for(j=0;j<e;j++)
		{
			encrypted[i]=((encrypted[i]*num[i])%n);
		}
	}
	glRasterPos3i(x,y,z);
	for(i=0;encrypted[i]!='\0';i++){
		glutBitmapCharacter(font,encrypted[i]);
	}
	glutPostRedisplay();
	glFlush();
}
void cipher()
{
	glColor3f(0.0f,0.0f,1.0f);
	glPushMatrix();
	glScalef(40,20,.5);
	glTranslatef(3,14,0);
	glutWireCube(2);
	encrypt(-1,0,0);
	glPopMatrix();
}

void cipher2()
{
	glColor3f(0.0f,0.0f,1.0f);
	glPushMatrix();
	glScalef(40,20,.5);
	glTranslatef(3,14,0);
	glutWireCube(2);
	output(-1,0,"SCE",2);
	glPopMatrix();
}

void message_data()
{
	glColor3f(1.0f,1.0f,0.0f);
	glPushMatrix();
	glScalef(40,20,.5);
	glTranslatef(3,14,0);
	glutWireCube(2);
	output(-1,0,"SCE",2);
	glPopMatrix();
}
	

void message_key(void)
{
	glColor3f(0.0f,1.0f,0.0f);
	glPushMatrix();
	glScalef(20,20,.5);
	glTranslatef(3,14,0);
	glutWireCube(2);

	output(-1,0,"p=11,q=13",2);
	glPopMatrix();

}

void decrypt(float x, float y, float z)
{
	string msg="FrSH";
	long encrypted[100];
	long decrypted[100];
	long num[100];
	int p=11,q=13,phi=0,i=0,len=0,e=0,d=0,j=0;
	int n=p*q;
	phi=(p-1)*(q-1);
	for(i=2;i<phi;i++)
		if(gcd(i,phi)==1)
			break;
	e=i;
	for(i=2;i<phi;i++)
		if((e*i-1)%phi==0)
			break;
	d=i;
	len=msg.length();

	for(i=0;i<len;i++)
		num[i]=msg[i];
	glRasterPos3i(x,y,z);
	for(int i=0;i<len;i++)
	{
		decrypted[i]=1;
		for(int j=0;j<d;j++)
		{
			decrypted[i]=((decrypted[i]*msg[i])%n);
		}
	}

	for(i=0;i<=3;i++){
		glutBitmapCharacter(font,(char)decrypted[i]);
	}
	glutPostRedisplay();
	glFlush();
}

void messagedata2()
{
	glColor3f(1.0f,1.0f,0.0f);
	glPushMatrix();
	glScalef(40,20,.5);
	glTranslatef(3,14,0);
	glutWireCube(2);
	decrypt(-1,0,0);
	glPopMatrix();
}

void messagedata3()
{
	glColor3f(1.0f,1.0f,0.0f);
	glPushMatrix();
	glScalef(40,20,.5);
	glTranslatef(3,14,0);
	glutWireCube(2);
	output(-1,0,"error",2);
	glPopMatrix();
}

void withoutencryption()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.5f,0.5f,0.5f,1.0f);
	glColor3f(0.0f,1.0f,0.0f);
	output(120,670," without using rsa encryption and decryption",2);
	glColor3f(1.0f,1.0f,1.0f);
	glPushMatrix();
	glTranslatef(-30,200,0);
	output(75,440,"sender",2);
	computer();
	glPopMatrix();

	glColor3f(1.0f,1.0f,1.0f);
	glPushMatrix();
	output(565,630,"receiver",2);
	computer_dest();
	glPopMatrix();

	glColor3f(1.0f,1.0f,1.0f);
	glPushMatrix();
	output(320,190,"intruder",2);
	computer_mid();
	glPopMatrix();

	glColor3f(1.0f,1.0f,1.0f);
	glPushMatrix();
	glScalef(70,40,.5);
	glTranslatef(1.5,7,0);
	glutWireCube(2);
	glPopMatrix();

	if(phy_header_angle1!=100)
	{
		glPushMatrix();
		glTranslatef(0,-phy_header_angle1,0);
		glPushMatrix();
		glTranslatef(0,-arrow_angle,0);
		glTranslatef(0,150,0);
		message_data();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(phy_header_angle,0,0);
		glTranslatef(-100,0,0);

		glPopMatrix();
		glPushMatrix();
	}
	glPushMatrix();
	glTranslatef(movement_angle1,0,0);
	if(phy_header_angle1==100)
	{
		glPushMatrix();
		if(movement_angle1>=420)
		{
			glTranslatef(0,rev_analog_sig_angle,0);
		}
		glTranslatef(0,-analog_sig_angle,0);
		if(rev_analog_sig_angle!=100)
			cipher2();
		glPopMatrix();
	}

	glPopMatrix();
	glPushMatrix();
	glTranslatef(movement_angle1,0,0);
	if(phy_header_angle1==100)
	{
		glPushMatrix();
		glScalef(50,30,.5);
		glTranslatef(2.5,2.5,0);
		glutWireCube(2);
		glPopMatrix();
	}
	glPopMatrix();
	if(rev_analog_sig_angle==100)
	{
		glPushMatrix();
		glTranslatef(450,rev_phy_header_angle1,0);
		glPushMatrix();
		glTranslatef(0,rev_arrow_angle,0);
		glTranslatef(0,0,0);
		messagedata3();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(rev_phy_header_angle,0,0);
		glTranslatef(-10,0,0);
		glPopMatrix();
		glPopMatrix();
	}
	glColor3f(1.0f,1.0f,1.0f);
	glPushMatrix();
	glTranslatef(450,0,0);
	glScalef(70,40,.5);
	glTranslatef(1.5,7,0);
	glutWireCube(2);
	glPopMatrix();
	animation_encrypt();
	glFlush();
	glutSwapBuffers();
}

void encryption()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode(GL_MODELVIEW);

	glColor3f(1.0f,1.0f,1.0f);
	output(150,670,"rsa encryption and decryption process",2);

	glColor3f(1.0f,1.0f,1.0f);
	glPushMatrix();
	glTranslatef(-30,200,0);
	output(75,440,"sender",2);
	computer();
	glPopMatrix();

	glColor3f(1.0f,1.0f,1.0f);
	glPushMatrix();
	output(565,630,"receiver",2);
	computer_dest();
	glPopMatrix();

	glColor3f(1.0f,1.0f,1.0f);
	glPushMatrix();
	output(320,190,"intruder",2);
	computer_mid();
	glPopMatrix();

	glColor3f(1.0f,1.0f,1.0f);
	glPushMatrix();
	glScalef(70,40,.5);
	glTranslatef(1.5,7,0);
	glutWireCube(2);
	glPopMatrix();

	if(phy_header_angle1!=100)
	{
		glPushMatrix();
		glTranslatef(0,-phy_header_angle1,0);
		glPushMatrix();
		glTranslatef(0,-arrow_angle,0);
		glTranslatef(0,150,0);
		message_data();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(phy_header_angle,0,0);
		glTranslatef(-100,0,0);
		message_key();
		glPopMatrix();
		glPopMatrix();
	}
	glPushMatrix();
	glTranslatef(movement_angle1,0,0);
	if(phy_header_angle1==100)
	{
		glPushMatrix();
		if(movement_angle1>=420)
		{
			glTranslatef(0,rev_analog_sig_angle,0);
		}
		glTranslatef(0,-analog_sig_angle,0);
		if(rev_analog_sig_angle!=100)
			cipher();
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(movement_angle1,0,0);
	if(phy_header_angle1==100)
	{
		glPushMatrix();
		glScalef(50,30,.5);
		glTranslatef(2.5,2.5,0);
		glutWireCube(2);
		glPopMatrix();
	}
	glPopMatrix();
	if(rev_analog_sig_angle==100)
	{
		glPushMatrix();
		glTranslatef(450,rev_phy_header_angle1,0);
		glPushMatrix();
		messagedata2();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(rev_phy_header_angle,0,0);
		glTranslatef(-10,0,0);
		if(rev_phy_header_angle<200)
			message_key();
		glPopMatrix();
		glPopMatrix();
	}
	glColor3f(1.0f,1.0f,1.0f);
	glPushMatrix();
	glTranslatef(450,0,0);
	glScalef(70,40,.5);
	glTranslatef(1.5,7,0);
	glutWireCube(2);
	glPopMatrix();
	animation_encrypt();
	glFlush();
	glutSwapBuffers();
}

void myinit()
{
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,700.0,0.0,700.0);
}
void display()
{
	
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0,0.0,0.4,1.0);
	front_page();
	glFlush();
	glutSwapBuffers();
}

void key (unsigned char key ,int x,int y)
{
	switch(key)
	{
	case 'S' :
	case 's' :glutDisplayFunc(encryptioninfo);
		break;
	case 'W' :
	case 'w' :glutDisplayFunc(withoutencryption);
		break;
	case 'E' :
	case 'e' :glutDisplayFunc(encryption);
		break;
	case 'q' :
	case 'Q' :
		exit(0);
	}
	glutPostRedisplay();
}

static void menu(int mode)
{
	switch(mode)
	{
	case FRONTPAGE:glutDisplayFunc(front_page);
		break;
	case ENCRYPTIONINFO:glutDisplayFunc(encryptioninfo);
		break;
	case WITHOUTENCRYPTION :glutDisplayFunc(withoutencryption);
		break;
	case ENCRYPTION:glutDisplayFunc(encryption);
		break;
	case EXIT :exit(0);
	}
	glutPostRedisplay();
}


void main (int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,700);
	glutInitWindowPosition(0,0);
	glClearColor(0.9f,0.5f,0.2f,1.0);

	glutCreateWindow("ENCRYPTION");
	glutKeyboardFunc(key);

	myinit();
	glutDisplayFunc(display);
	glutCreateMenu(menu);
	glutAddMenuEntry("front page", FRONTPAGE);

	glutAddMenuEntry("Encryptioninfo",ENCRYPTIONINFO);
	glutAddMenuEntry("withoutencryption",WITHOUTENCRYPTION);
	glutAddMenuEntry("with encryption", ENCRYPTION);
	glutAddMenuEntry("EXIT",EXIT);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
}







































