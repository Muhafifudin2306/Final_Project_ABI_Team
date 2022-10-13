/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#include <GL/glut.h>

#include <stdlib.h>

//Deklarasi fungsi Mouse agar gambar 3d dapat diputar putar menggunakan Mouse
float xrot =0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mouseDown = false;




//Deklarasi pengaturan lembaran kerja agar Gambar 3d yang kita buat saat diputar atau di geser tidak kemana mana
void ukur(int lebar, int tinggi){
if(tinggi==0) tinggi=1;
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45,lebar/tinggi, 5, 450);
glTranslatef(0,0,-300);// jarak object dari lembaran kerja
glMatrixMode(GL_MODELVIEW);
}
void myinit(void){
glClearColor (0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glEnable(GL_DEPTH_TEST);

glMatrixMode(GL_MODELVIEW);
glPointSize(10.0);
glLineWidth(7.0f);
}

//Dan selanjutnya yaitu fungsi mouse
void idle()
{
if (!mouseDown)
{
xrot += 0.3;
yrot += 0.4;
}
glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
mouseDown = true;
xdiff = x - yrot;
ydiff = -y + xrot;
}
else
mouseDown = false;
}

void mouseMotion(int x, int y)
{
if(mouseDown)
{
yrot = x - xdiff;
xrot = y + ydiff;
glutPostRedisplay();
}
}

//Dibawah ini dimulai koding untuk membuat object
void tampilan(void){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(0,0,3,0,0,0,0,1,0);
glRotatef(xrot, 1, 0,0);
glRotatef(yrot, 0,1,0);
glPushMatrix();


//ALAS MEJA
glBegin(GL_POLYGON);//ATAS
glColor3f(1,1,0);
glVertex3f(-50,15,40);
glVertex3f(50,15,40);
glVertex3f(50,15,-10);
glVertex3f(-50,15,-10);
glEnd();
glBegin(GL_POLYGON);//BAWAH
glColor3f(1,1,1);
glVertex3f(-50,10,40);
glVertex3f(50,10,40);
glVertex3f(50,10,-10);
glVertex3f(-50,10,-10);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(0,1,1);
glVertex3f(50,10,40);
glVertex3f(50,15,40);
glVertex3f(50,15,-10);
glVertex3f(50,10,-10);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(0,1,1);
glVertex3f(-50,10,40);
glVertex3f(-50,15,40);
glVertex3f(-50,15,-10);
glVertex3f(-50,10,-10);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0,0,1);
glVertex3f(-50,10,40);
glVertex3f(-50,15,40);
glVertex3f(50,15,40);
glVertex3f(50,10,40);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0,0,1);
glVertex3f(-50,10,-10);
glVertex3f(-50,15,-10);
glVertex3f(50,15,-10);
glVertex3f(50,10,-10);
glEnd();

//KAKI MEJA 1
glBegin(GL_POLYGON);//ALAS BAWAH
glColor3f(1,1,1);
glVertex3f(-50,-40,30);
glVertex3f(-40,-40,30);
glVertex3f(-40,-40,40);
glVertex3f(-50,-40,40);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0,0,1);
glVertex3f(-50,10,40);
glVertex3f(-40,10,40);
glVertex3f(-40,-40,40);
glVertex3f(-50,-40,40);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0,0,1);
glVertex3f(-50,10,30);
glVertex3f(-40,10,30);
glVertex3f(-40,-40,30);
glVertex3f(-50,-40,30);
glEnd();
glBegin(GL_POLYGON);//KIRI
glColor3f(0,1,1);
glVertex3f(-50,10,30);
glVertex3f(-50,-40,30);
glVertex3f(-50,-40,40);
glVertex3f(-50,10,40);
glEnd();
glBegin(GL_POLYGON);//KANAN
glColor3f(0,1,1);
glVertex3f(-40,10,30);
glVertex3f(-40,-40,30);
glVertex3f(-40,-40,40);
glVertex3f(-40,10,40);
glEnd();

//KAKI MEJA 2
glBegin(GL_POLYGON);//ALAS BAWAH
glColor3f(1,1,1);
glVertex3f(50,-40,30);
glVertex3f(40,-40,30);
glVertex3f(40,-40,40);
glVertex3f(50,-40,40);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0,0,1);
glVertex3f(50,10,40);
glVertex3f(40,10,40);
glVertex3f(40,-40,40);
glVertex3f(50,-40,40);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0,0,1);
glVertex3f(50,10,30);
glVertex3f(40,10,30);
glVertex3f(40,-40,30);
glVertex3f(50,-40,30);
glEnd();
glBegin(GL_POLYGON);//KIRI
glColor3f(0,1,1);
glVertex3f(50,10,30);
glVertex3f(50,-40,30);
glVertex3f(50,-40,40);
glVertex3f(50,10,40);
glEnd();
glBegin(GL_POLYGON);//KANAN
glColor3f(0,1,1);
glVertex3f(40,10,30);
glVertex3f(40,-40,30);
glVertex3f(40,-40,40);
glVertex3f(40,10,40);
glEnd();

//KAKI MEJA 3
glBegin(GL_POLYGON);//ALAS BAWAH
glColor3f(1,1,1);
glVertex3f(-50,-40,0);
glVertex3f(-40,-40,0);
glVertex3f(-40,-40,-10);
glVertex3f(-50,-40,-10);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0,0,1);
glVertex3f(-50,10,0);
glVertex3f(-40,10,0);
glVertex3f(-40,-40,0);
glVertex3f(-50,-40,0);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0,0,1);
glVertex3f(-50,10,-10);
glVertex3f(-40,10,-10);
glVertex3f(-40,-40,-10);
glVertex3f(-50,-40,-10);
glEnd();
glBegin(GL_POLYGON);//KIRI
glColor3f(0,1,1);
glVertex3f(-50,10,0);
glVertex3f(-50,-40,0);
glVertex3f(-50,-40,-10);
glVertex3f(-50,10,-10);
glEnd();
glBegin(GL_POLYGON);//KANAN
glColor3f(0,1,1);
glVertex3f(-40,10,0);
glVertex3f(-40,-40,0);
glVertex3f(-40,-40,-10);
glVertex3f(-40,10,-10);
glEnd();

//KAKI MEJA 4
glBegin(GL_POLYGON);//ALAS BAWAH
glColor3f(1,1,1);
glVertex3f(50,-40,0);
glVertex3f(40,-40,0);
glVertex3f(40,-40,-10);
glVertex3f(50,-40,-10);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0,0,1);
glVertex3f(50,10,0);
glVertex3f(40,10,0);
glVertex3f(40,-40,0);
glVertex3f(50,-40,0);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0,0,1);
glVertex3f(50,10,-10);
glVertex3f(40,10,-10);
glVertex3f(40,-40,-10);
glVertex3f(50,-40,-10);
glEnd();
glBegin(GL_POLYGON);//KIRI
glColor3f(0,1,1);
glVertex3f(50,10,0);
glVertex3f(50,-40,0);
glVertex3f(50,-40,-10);
glVertex3f(50,10,-10);
glEnd();
glBegin(GL_POLYGON);//KANAN
glColor3f(0,1,1);
glVertex3f(40,10,0);
glVertex3f(40,-40,0);
glVertex3f(40,-40,-10);
glVertex3f(40,10,-10);
glEnd();

//ALAS KURSI
glBegin(GL_POLYGON);//ATAS
glColor3f(1,1,0);
glVertex3f(-20,-15,-20);
glVertex3f(20,-15,-20);
glVertex3f(20,-15,-50);
glVertex3f(-20,-15,-50);
glEnd();
glBegin(GL_POLYGON);//BAWAH
glColor3f(1,1,1);
glVertex3f(-20,-10,-20);
glVertex3f(20,-10,-20);
glVertex3f(20,-10,-50);
glVertex3f(-20,-10,-50);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(0,1,1);
glVertex3f(20,-10,-20);
glVertex3f(20,-15,-20);
glVertex3f(20,-15,-50);
glVertex3f(20,-10,-50);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(0,1,1);
glVertex3f(-20,-10,-20);
glVertex3f(-20,-15,-20);
glVertex3f(-20,-15,-50);
glVertex3f(-20,-10,-50);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0,0,1);
glVertex3f(-20,-10,-20);
glVertex3f(-20,-15,-20);
glVertex3f(20,-15,-20);
glVertex3f(20,-10,-20);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0,0,1);
glVertex3f(-20,-10,-50);
glVertex3f(-20,-15,-50);
glVertex3f(20,-15,-50);
glVertex3f(20,-10,-50);
glEnd();

//KAKI KURSI 1
glBegin(GL_POLYGON);//ALAS BAWAH
glColor3f(1,1,1);
glVertex3f(-20,-40,-30);
glVertex3f(-10,-40,-30);
glVertex3f(-10,-40,-20);
glVertex3f(-20,-40,-20);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0,0,1);
glVertex3f(-20,-10,-20);
glVertex3f(-10,-10,-20);
glVertex3f(-10,-40,-20);
glVertex3f(-20,-40,-20);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0,0,1);
glVertex3f(-20,-10,-30);
glVertex3f(-10,-10,-30);
glVertex3f(-10,-40,-30);
glVertex3f(-20,-40,-30);
glEnd();
glBegin(GL_POLYGON);//KIRI
glColor3f(0,1,1);
glVertex3f(-20,-10,-30);
glVertex3f(-20,-40,-30);
glVertex3f(-20,-40,-20);
glVertex3f(-20,-10,-20);
glEnd();
glBegin(GL_POLYGON);//KANAN
glColor3f(0,1,1);
glVertex3f(-10,-10,-30);
glVertex3f(-10,-40,-30);
glVertex3f(-10,-40,-20);
glVertex3f(-10,-10,-20);
glEnd();

//KAKI KURSI 2
glBegin(GL_POLYGON);//ALAS BAWAH
glColor3f(1,1,1);
glVertex3f(-10,-40,-50);
glVertex3f(-20,-40,-50);
glVertex3f(-20,-40,-40);
glVertex3f(-10,-40,-40);
glEnd();
glBegin(GL_POLYGON);//ALAS ATAS
glColor3f(1,1,1);
glVertex3f(-10,30,-50);
glVertex3f(-20,30,-50);
glVertex3f(-20,30,-40);
glVertex3f(-10,30,-40);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0,0,1);
glVertex3f(-10,30,-40);
glVertex3f(-20,30,-40);
glVertex3f(-20,-40,-40);
glVertex3f(-10,-40,-40);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0,0,1);
glVertex3f(-10,30,-50);
glVertex3f(-20,30,-50);
glVertex3f(-20,-40,-50);
glVertex3f(-10,-40,-50);
glEnd();
glBegin(GL_POLYGON);//KIRI
glColor3f(0,1,1);
glVertex3f(-10,30,-50);
glVertex3f(-10,-40,-50);
glVertex3f(-10,-40,-40);
glVertex3f(-10,30,-40);
glEnd();
glBegin(GL_POLYGON);//KANAN
glColor3f(0,1,1);
glVertex3f(-20,30,-50);
glVertex3f(-20,-40,-50);
glVertex3f(-20,-40,-40);
glVertex3f(-20,30,-40);
glEnd();

//KAKI KURSI 3
glBegin(GL_POLYGON);//ALAS BAWAH
glColor3f(1,1,1);
glVertex3f(20,-40,-30);
glVertex3f(10,-40,-30);
glVertex3f(10,-40,-20);
glVertex3f(20,-40,-20);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0,0,1);
glVertex3f(20,-10,-20);
glVertex3f(10,-10,-20);
glVertex3f(10,-40,-20);
glVertex3f(20,-40,-20);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0,0,1);
glVertex3f(20,-10,-30);
glVertex3f(10,-10,-30);
glVertex3f(10,-40,-30);
glVertex3f(20,-40,-30);
glEnd();
glBegin(GL_POLYGON);//KIRI
glColor3f(0,1,1);
glVertex3f(20,-10,-30);
glVertex3f(20,-40,-30);
glVertex3f(20,-40,-20);
glVertex3f(20,-10,-20);
glEnd();
glBegin(GL_POLYGON);//KANAN
glColor3f(0,1,1);
glVertex3f(10,-10,-30);
glVertex3f(10,-40,-30);
glVertex3f(10,-40,-20);
glVertex3f(10,-10,-20);
glEnd();

//KAKI KURSI 2
glBegin(GL_POLYGON);//ALAS BAWAH
glColor3f(1,1,1);
glVertex3f(10,-40,-50);
glVertex3f(20,-40,-50);
glVertex3f(20,-40,-40);
glVertex3f(10,-40,-40);
glEnd();
glBegin(GL_POLYGON);//ALAS ATAS
glColor3f(1,1,1);
glVertex3f(10,30,-50);
glVertex3f(20,30,-50);
glVertex3f(20,30,-40);
glVertex3f(10,30,-40);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0,0,1);
glVertex3f(10,30,-40);
glVertex3f(20,30,-40);
glVertex3f(20,-40,-40);
glVertex3f(10,-40,-40);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0,0,1);
glVertex3f(10,30,-50);
glVertex3f(20,30,-50);
glVertex3f(20,-40,-50);
glVertex3f(10,-40,-50);
glEnd();
glBegin(GL_POLYGON);//KIRI
glColor3f(0,1,1);
glVertex3f(10,30,-50);
glVertex3f(10,-40,-50);
glVertex3f(10,-40,-40);
glVertex3f(10,30,-40);
glEnd();
glBegin(GL_POLYGON);//KANAN
glColor3f(0,1,1);
glVertex3f(20,30,-50);
glVertex3f(20,-40,-50);
glVertex3f(20,-40,-40);
glVertex3f(20,30,-40);
glEnd();

//SENDERAN KURSI
glBegin(GL_POLYGON);//DEPAN
glColor3f(0,0,1);
glVertex3f(-10,30,-40);
glVertex3f(-10,10,-40);
glVertex3f(10,10,-40);
glVertex3f(10,30,-40);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0,0,1);
glVertex3f(-10,30,-45);
glVertex3f(-10,10,-45);
glVertex3f(10,10,-45);
glVertex3f(10,30,-45);
glEnd();
glBegin(GL_POLYGON);//ATAS
glColor3f(1,1,1);
glVertex3f(-10,30,-40);
glVertex3f(-10,30,-45);
glVertex3f(10,30,-45);
glVertex3f(10,30,-40);
glEnd();
glBegin(GL_POLYGON);//BAWAH
glColor3f(1,1,1);
glVertex3f(-10,10,-40);
glVertex3f(-10,10,-45);
glVertex3f(10,10,-45);
glVertex3f(10,10,-40);
glEnd();


glPushMatrix();
glPopMatrix();
glutSwapBuffers();
}


int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(240, 80);
    glutInitWindowSize(750, 600);
    glutCreateWindow("MEJA DAN KURSI 3D");
    myinit();
    glutDisplayFunc(tampilan);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukur);
    glutMainLoop();
}
