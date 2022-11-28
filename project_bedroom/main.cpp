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
gluPerspective(55,lebar/tinggi, 5, 450);
glTranslatef(45,-70,-300);// jarak object dari lembaran kerja
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
glColor4f(1.0f, 0.2f, 0.1f, 0.0f);//orange/brown
glVertex3f(-80,15,150); // kiri_bawah lebar = -80, tingginya = 15, panjang-z = 150
glVertex3f(80,15,150);//kanan_bawah = 80, tingginya = 15, panjang-z = 150
glVertex3f(80,15,-10);//kanan_atas = 80, tingginya = 15 
glVertex3f(-80,15,-10);//kiri_atas = -80, tingginya = 15, panjang-z = -10
glEnd();


glBegin(GL_POLYGON);//BAWAH
glColor3f(1,1,1);
glVertex3f(-80,5,150);
glVertex3f(80,5,150);
glVertex3f(80,5,-10);
glVertex3f(-80,5,-10);
glEnd();


glBegin(GL_POLYGON);//SAMPING KANAN
glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white
glVertex3f(80,5,150);
glVertex3f(80,15,150);
glVertex3f(80,15,-10);
glVertex3f(80,5,-10);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
glVertex3f(-80,5,150);
glVertex3f(-80,160,150);
glVertex3f(-80,160,-10);
glVertex3f(-80,5,-10);
glEnd();




glBegin(GL_POLYGON);//DEPAN
glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white
glVertex3f(-80,5,150);
glVertex3f(-80,15,150);
glVertex3f(80,15,150);
glVertex3f(80,5,150);
glEnd();


glBegin(GL_POLYGON);//BELAKANG
glColor3f(0.0f, 0.0f, 1.0f);//Blue
glVertex3f(-80,5,-10);
glVertex3f(-80,160,-10);
glVertex3f(80,160,-10);
glVertex3f(80,5,-10);
glEnd();


//AC
glBegin(GL_POLYGON);//Body AC
glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white
glVertex3f(-77,120,110);
glVertex3f(-77,135,110);
glVertex3f(-77,135,70);
glVertex3f(-77,120,70);
glEnd();

glBegin(GL_POLYGON);//Penutup
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(-76.95,125,110);
glVertex3f(-76.95,135,110);
glVertex3f(-76.95,135,70);
glVertex3f(-76.95,125,70);
glEnd();

glBegin(GL_POLYGON);//Penutup_Atas
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(-80,135,110);
glVertex3f(-77,135,110);
glVertex3f(-77,135,70);
glVertex3f(-80,135,70);
glEnd();

glBegin(GL_POLYGON);//Rak Kiri
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//grey
glVertex3f(-77,120,110);
glVertex3f(-80,120,110);
glVertex3f(-80,120,70);
glVertex3f(-77,120,70);
glEnd();

glBegin(GL_POLYGON);//SPenutup amoing Kiri
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//grey
glVertex3f(-80,135,110.1);
glVertex3f(-77,135,110.1);
glVertex3f(-77,125,110.1);
glEnd();

glBegin(GL_POLYGON);//SPenutup amoing Kiri
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//grey
glVertex3f(-80,135,69.9);
glVertex3f(-77,135,69.9);
glVertex3f(-77,125,69.9);
glEnd();


glBegin(GL_POLYGON);//Samping Kiri
glColor3f(1,1,1);
glVertex3f(-80,120,110);
glVertex3f(-80,135,110);
glVertex3f(-77,135,110);
glVertex3f(-77,120,110);
glEnd();

glBegin(GL_POLYGON);//Samping Kana
glColor3f(1,1,1);
glVertex3f(-80,120,70);
glVertex3f(-80,135,70);
glVertex3f(-77,135,70);
glVertex3f(-77,120,70);
glEnd();


//Kasur
glBegin(GL_POLYGON);//Depan
glColor3f(1,1,1);
glVertex3f(-10,15,110);
glVertex3f(-10,50,110);
glVertex3f(-77,50,110);
glVertex3f(-77,15,110);
glEnd();

glBegin(GL_POLYGON);//Depan
glColor3f(1,1,1);
glVertex3f(-10,15,108);
glVertex3f(-10,50,108);
glVertex3f(-77,50,108);
glVertex3f(-77,15,108);
glEnd();

glBegin(GL_POLYGON);//Depan
glColor3f(1,1,1);
glVertex3f(-10,15,0);
glVertex3f(-10,70,0);
glVertex3f(-77,70,0);
glVertex3f(-77,15,0);
glEnd();

glBegin(GL_POLYGON);//Depan
glColor3f(1,1,1);
glVertex3f(-10,15,2);
glVertex3f(-10,70,2);
glVertex3f(-77,70,2);
glVertex3f(-77,15,2);
glEnd();

//Belakang
glBegin(GL_POLYGON);//penutup samping kanan
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//grey
glVertex3f(-10,15,2);
glVertex3f(-10,70,2);
glVertex3f(-10,70,0);
glVertex3f(-10,15,0);
glEnd();

glBegin(GL_POLYGON);//penutup samping kiri
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//grey
glVertex3f(-77,15,2);
glVertex3f(-77,70,2);
glVertex3f(-77,70,0);
glVertex3f(-77,15,0);
glEnd();

glBegin(GL_POLYGON);//Penutup atas
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(-77.95,70,2);
glVertex3f(-10,70,2);
glVertex3f(-10,70,0);
glVertex3f(-77.95,70,0);
glEnd();

//Depan
glBegin(GL_POLYGON);//penutup samping kanan
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//grey
glVertex3f(-10,15,110);
glVertex3f(-10,50,110);
glVertex3f(-10,50,108);
glVertex3f(-10,15,108);
glEnd();

glBegin(GL_POLYGON);//penutup samping kiri
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//grey
glVertex3f(-77,15,110);
glVertex3f(-77,50,110);
glVertex3f(-77,50,108);
glVertex3f(-77,15,108);
glEnd();

glBegin(GL_POLYGON);//Penutup atas
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(-77.95,50,110);
glVertex3f(-10,50,110);
glVertex3f(-10,50,108);
glVertex3f(-77.95,50,108);
glEnd();

//Kasur
glBegin(GL_POLYGON);//penutup samping kiri
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//grey
glVertex3f(-74,20,110);
glVertex3f(-74,40,110);
glVertex3f(-74,40,0);
glVertex3f(-74,20,0);
glEnd();
glBegin(GL_POLYGON);//penutup samping kiri
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//grey
glVertex3f(-72,20,110);
glVertex3f(-72,40,110);
glVertex3f(-72,40,0);
glVertex3f(-72,20,0);
glEnd();

glBegin(GL_POLYGON);//penutup samping kanan
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//grey
glVertex3f(-13,20,110);
glVertex3f(-13,40,110);
glVertex3f(-13,40,0);
glVertex3f(-13,20,0);
glEnd();

glBegin(GL_POLYGON);//penutup samping kanan
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//grey
glVertex3f(-15,20,110);
glVertex3f(-15,40,110);
glVertex3f(-15,40,0);
glVertex3f(-15,20,0);
glEnd();

glBegin(GL_POLYGON);//Penutup_Atas Kiri
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(-74,40,110);
glVertex3f(-72,40,110);
glVertex3f(-72,40,0);
glVertex3f(-74,40,0);
glEnd();

glBegin(GL_POLYGON);//Penutup_Bawah Kiri
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(-74,20,110);
glVertex3f(-72,20,110);
glVertex3f(-72,20,0);
glVertex3f(-74,20,0);
glEnd();

glBegin(GL_POLYGON);//Penutup_Atas Kanan
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(-15,40,110);
glVertex3f(-13,40,110);
glVertex3f(-13,40,0);
glVertex3f(-15,40,0);
glEnd();

glBegin(GL_POLYGON);//Penutup_Bawah Kiri
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(-15,20,110);
glVertex3f(-13,20,110);
glVertex3f(-13,20,0);
glVertex3f(-15,20,0);
glEnd();

glBegin(GL_POLYGON);//Penutup_Atas Tengah
glColor4f(0.2f, 0.2f, 0.1f, 0.0f);//orange/brown
glVertex3f(-72,45,110);
glVertex3f(-15,45,110);
glVertex3f(-15,45,0);
glVertex3f(-72,45,0);
glEnd();

glBegin(GL_POLYGON);//Penutup_Bawah Tengah
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(-72,25,110);
glVertex3f(-13,25,110);
glVertex3f(-13,25,0);
glVertex3f(-72,25,0);
glEnd();

glBegin(GL_POLYGON);//penutup Tengah kanan
glColor4f(0.2f, 0.2f, 0.1f, 0.0f);//orange/brown
glVertex3f(-15,25,110);
glVertex3f(-15,45,110);
glVertex3f(-15,45,0);
glVertex3f(-15,25,0);
glEnd();

glBegin(GL_POLYGON);//penutup Tengah kiri
glColor4f(0.2f, 0.2f, 0.1f, 0.0f);//orange/brown
glVertex3f(-72,25,110);
glVertex3f(-72,45,110);
glVertex3f(-72,45,0);
glVertex3f(-72,25,0);
glEnd();



glBegin(GL_POLYGON);//Penutup_Atas Tengah
glColor4f(0.0f, 1.0f, 1.0f, 1.0f);//light blue
glVertex3f(-72,45.1,110);
glVertex3f(-15,45.1,110);
glVertex3f(-15,45.1,30);
glVertex3f(-72,45.1,30);
glEnd();

glBegin(GL_POLYGON);//penutup Tengah kanan
glColor4f(0.0f, 1.0f, 1.0f, 1.0f);//light blue
glVertex3f(-14.9,25.2,110);
glVertex3f(-14.9,45.1,110);
glVertex3f(-14.9,45.1,30);
glVertex3f(-14.9,25.2,30);
glEnd();

glBegin(GL_POLYGON);//penutup Tengah kanan
glColor4f(0.0f, 1.0f, 1.0f, 1.0f);//light blue
glVertex3f(-72.1,25.2,110);
glVertex3f(-72.1,45.1,110);
glVertex3f(-72.1,45.1,30);
glVertex3f(-72.1,25.2,30);
glEnd();


//Meja 

//kiri belakang
glBegin(GL_POLYGON);
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(15,15,0);
glVertex3f(15,40,0);
glVertex3f(10,40,0);
glVertex3f(10,15,0);
glEnd();

glBegin(GL_POLYGON);
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(15,15,5);
glVertex3f(15,40,5);
glVertex3f(10,40,5);
glVertex3f(10,15,5);
glEnd();

glBegin(GL_POLYGON);
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(10,15,0);
glVertex3f(10,40,0);
glVertex3f(10,40,5);
glVertex3f(10,15,5);
glEnd();

glBegin(GL_POLYGON);
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(15,15,0);
glVertex3f(15,40,0);
glVertex3f(15,40,5);
glVertex3f(15,15,5);
glEnd();


//kanan belakang
glBegin(GL_POLYGON);
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(55,15,0);
glVertex3f(55,40,0);
glVertex3f(50,40,0);
glVertex3f(50,15,0);
glEnd();

glBegin(GL_POLYGON);
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(55,15,5);
glVertex3f(55,40,5);
glVertex3f(50,40,5);
glVertex3f(50,15,5);
glEnd();

glBegin(GL_POLYGON);
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(50,15,0);
glVertex3f(50,40,0);
glVertex3f(50,40,5);
glVertex3f(50,15,5);
glEnd();
glBegin(GL_POLYGON);
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(55,15,0);
glVertex3f(55,40,0);
glVertex3f(55,40,5);
glVertex3f(55,15,5);
glEnd();

//kanan depan
glBegin(GL_POLYGON);
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(55,15,20);
glVertex3f(55,40,20);
glVertex3f(50,40,20);
glVertex3f(50,15,20);
glEnd();

glBegin(GL_POLYGON);
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(55,15,25);
glVertex3f(55,40,25);
glVertex3f(50,40,25);
glVertex3f(50,15,25);
glEnd();

glBegin(GL_POLYGON);
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(50,15,20);
glVertex3f(50,40,20);
glVertex3f(50,40,25);
glVertex3f(50,15,25);
glEnd();

glBegin(GL_POLYGON);
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(55,15,20);
glVertex3f(55,40,20);
glVertex3f(55,40,25);
glVertex3f(55,15,25);
glEnd();


//kiri depan
glBegin(GL_POLYGON);
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(15,15,20);
glVertex3f(15,40,20);
glVertex3f(10,40,20);
glVertex3f(10,15,20);
glEnd();

glBegin(GL_POLYGON);
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(15,15,25);
glVertex3f(15,40,25);
glVertex3f(10,40,25);
glVertex3f(10,15,25);
glEnd();
glBegin(GL_POLYGON);
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(10,15,20);
glVertex3f(10,40,20);
glVertex3f(10,40,25);
glVertex3f(10,15,25);
glEnd();
glBegin(GL_POLYGON);
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(15,15,20);
glVertex3f(15,40,20);
glVertex3f(15,40,25);
glVertex3f(15,15,25);
glEnd();

//penutup-tengah
glBegin(GL_POLYGON);//Penutup_Atas Tengah
glColor3f(1,1,1);
glVertex3f(55,40,25);
glVertex3f(10,40,25);
glVertex3f(10,40,0);
glVertex3f(55,40,0);
glEnd();

glBegin(GL_POLYGON);//Penutup_Atas Tengah
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(55,35,25);
glVertex3f(10,35,25);
glVertex3f(10,35,0);
glVertex3f(55,35,0);
glEnd();

glBegin(GL_POLYGON);//Depan Kanan
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(55,35,0);
glVertex3f(55,40,0);
glVertex3f(55,40,20);
glVertex3f(55,35,20);
glEnd();

glBegin(GL_POLYGON);//Depan Kiri
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(10,35,0);
glVertex3f(10,40,0);
glVertex3f(10,40,20);
glVertex3f(10,35,20);
glEnd();

glBegin(GL_POLYGON);//Depan depan
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(10,35,25);
glVertex3f(10,40,25);
glVertex3f(55,40,25);
glVertex3f(55,35,25);
glEnd();

glBegin(GL_POLYGON);//Depan belakang
glColor4f(0.329412f, 0.329412f, 0.329412f, 0.0f);//white
glVertex3f(10,35,10);
glVertex3f(10,40,10);
glVertex3f(55,40,10);
glVertex3f(55,35,10);
glEnd();

//Tikar
glBegin(GL_POLYGON);//ATAS
glColor3f(1,1,1);
glVertex3f(3,15.1,120); // kiri_bawah lebar = -80, tingginya = 15, panjang-z = 150
glVertex3f(70,15.1,120);//kanan_bawah = 80, tingginya = 15, panjang-z = 150
glVertex3f(70,15.1,7);//kanan_atas = 80, tingginya = 15 
glVertex3f(3,15.1,7);//kiri_atas = -80, tingginya = 15, panjang-z = -10
glEnd();

glBegin(GL_POLYGON);//ATAS
glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
glVertex3f(7,15.2,120); // kiri_bawah lebar = -80, tingginya = 15, panjang-z = 150
glVertex3f(65,15.2,120);//kanan_bawah = 80, tingginya = 15, panjang-z = 150
glVertex3f(65,15.2,7);//kanan_atas = 80, tingginya = 15 
glVertex3f(7,15.2,7);//kiri_atas = -80, tingginya = 15, panjang-z = -10
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
    glutCreateWindow("Kamar Tidur 3D");
    myinit();
    glutDisplayFunc(tampilan);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukur);
    glutMainLoop();
}
