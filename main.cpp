#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
void init(void);
void display(void);
void keyboard(unsigned char, int, int);
void resize(int, int);
void mouseMove(int x, int y);
void mouseButton(int button, int state, int x, int y);
using namespace std;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown = false;
int is_depth;
int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(40, 40);
    glutCreateWindow("Tugas Rancang Grafkom Kampus Inggris Imperial College");
    init();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.0, 1.0, 0.906, 0.0);
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(20.0);
    glLineWidth(6.0f);
}

void interior(void){
    glBegin(GL_QUADS);//garis depan rumah`
        glColor3f(1.0f, 0.408f, 0.0f);
        glVertex3f(-80.0, 0.0, 100.1);
        glVertex3f(-80.0, 100.0, 100.1);
        glVertex3f(80.0, 100.0, 100.1);
           glVertex3f(80.0, 0.0, 100.1);
    glEnd();

    glBegin(GL_QUADS);//garis depan rumah`transisi 1 kiri
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-50.0, 100.0, 100.1);
        glVertex3f(-50.0, 100.0, 120.1);
        glVertex3f(-50.0, 0.0, 120.1);
        glVertex3f(-50.0, 0.0, 100.1);
    glEnd();

    glBegin(GL_QUADS);//garis depan rumah`transisi 2 kiri
        glColor3f(203/255.0f, 135/255.0f, 87/255.0f);
        glVertex3f(-50.0, 100.0, 120.1);
        glVertex3f(-20.0, 100.0, 120.1);
        glVertex3f(-20.0, 0.0, 120.1);
        glVertex3f(-50.0, 0.0, 120.1);
    glEnd();

     glBegin(GL_QUADS);//garis depan rumah`transisi 3 kiri
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-20.0, 100.0, 120.1);
        glVertex3f(-20.0, 100.0, 140.1);
        glVertex3f(-20.0, 0.0, 140.1);
        glVertex3f(-20.0, 0.0, 120.1);
    glEnd();

     glBegin(GL_QUADS);//garis depan rumah`transisi 4 kiri
        glColor3f(203/255.0f, 135/255.0f, 87/255.0f);
        glVertex3f(-20.0, 100.0, 140.1);
        glVertex3f(10.0, 100.0, 140.1);
        glVertex3f(10.0, 0.0, 140.1);
        glVertex3f(-20.0, 0.0, 140.1);
    glEnd();

     glBegin(GL_QUADS);//garis depan rumah`transisi 1 kanan
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(10.0, 100.0, 120.1);
        glVertex3f(10.0, 100.0, 140.1);
        glVertex3f(10.0, 0.0, 140.1);
        glVertex3f(10.0, 0.0, 120.1);
    glEnd();

     glBegin(GL_QUADS);//garis depan rumah`transisi 2 kanan
        glColor3f(203/255.0f, 135/255.0f, 87/255.0f);
        glVertex3f(10.0, 100.0, 120.1);
        glVertex3f(40.0, 100.0, 120.1);
        glVertex3f(40.0, 0.0, 120.1);
        glVertex3f(10.0, 0.0, 120.1);
    glEnd();

    glBegin(GL_QUADS);//garis depan rumah`transisi 3 kiri
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(40.0, 100.0, 100.1);
        glVertex3f(40.0, 100.0, 120.1);
        glVertex3f(40.0, 0.0, 120.1);
        glVertex3f(40.0, 0.0, 100.1);
    glEnd();

    glBegin(GL_QUADS);//belakang
        glColor3f(1.0f, 0.408f, 0.0f);
        glVertex3f(-50.0, 0.0, -100.0);
        glVertex3f(-50.0, 50.0, -100.0);
        glVertex3f(50.0, 50.0, -100.0);
        glVertex3f(50.0, 0.0, -100.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//garis belakang
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-50.0, 0.0, -100.0);
        glVertex3f(-50.0, 50.0, -100.0);
        glVertex3f(50.0, 50.0, -100.0);
        glVertex3f(50.0, 0.0, -100.0);
    glEnd();
}

void jalanrumah(void){
    glBegin(GL_QUADS);//Jalan halaman Rumah
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex3f(-200.0, -3.0, -200.0);
        glColor3f(0.4f, 0.4f, 0.4f);
        glVertex3f(-200.0, -3.0, 200.0);
        glColor3f(0.6f, 0.6f, 0.6f);
        glVertex3f(200.0, -3.0, 200.0);
        glColor3f(0.8f, 0.8f, 0.8f);
        glVertex3f(200.0, -3.0, -200.0);
    glEnd();

     glBegin(GL_LINE_LOOP);//Garis Halaman rumah
       glColor3f(0.0f, 0.0f, 0.0f);
       glVertex3f(-200.0, -3.0, -200.0);
       glVertex3f(-200.0, -3.0, 200.0);
       glVertex3f(200.0, -3.0, 200.0);
       glVertex3f(200.0, -3.0, -200.0);
    glEnd();

}

void atap(void){

    glBegin(GL_TRIANGLES);//atap belakang
         glColor3f(0.165f,0.09f,0.004f);
        glVertex3f(0.0, 100.0, -100.0);
        glVertex3f(-50.0, 50.0, -100.0);
        glVertex3f(50.0, 50.0, -100.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//garis atap belakang
         glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(0.0, 100.0, -100.0);
        glVertex3f(-50.0, 50.0, -100.0);
        glVertex3f(50.0, 50.0, -100.0);
    glEnd();

}

void papantulis(void){
glBegin(GL_QUADS);//Papan Tulis
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(-30, 10.0, -98);
        glVertex3f(-30, 40.0, -98);
        glVertex3f(30, 40.0, -98);
        glVertex3f(30, 10.0, -98);
    glEnd();
        glBegin(GL_LINE_LOOP);//Garis Papan Tulis
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-30, 10.0, -98);
        glVertex3f(-30, 40.0, -98);
        glVertex3f(30, 40.0, -98);
        glVertex3f(30, 10.0, -98);
    glEnd();
}

void redcarpet(void){


glBegin(GL_QUADS);// RED CARPET
        glColor3f(0.973f,0.0f,0.0f);
        glVertex3f(-40, -1.0, -50);
       glVertex3f(-40, -1.0, 50);
       glVertex3f(40, -1.0, 50);
       glVertex3f(40, -1.0, -50);
    glEnd();
        glBegin(GL_LINE_LOOP);//GARIS RED CARPET
       glColor3f(0.0f, 0.0f, 0.0f);
       glVertex3f(-40, -1.0, -50);
       glVertex3f(-40, -1.0, 50);
       glVertex3f(40, -1.0, 50);
       glVertex3f(40, -1.0, -50);
    glEnd();
}
void pijakankaki(void){
 glBegin(GL_QUADS); //Pijakan Kaki (belakang)
        glColor3f(0.165f,0.09f,0.004f);
        glVertex3f(-30, 0.0, -98);
        glVertex3f(-30, 8.0, -98);
        glVertex3f(30, 8.0, -98);
        glVertex3f(30, 0.0, -98);
    glEnd();
    glBegin(GL_LINE_LOOP);//Garis pijakan kaki (belakang)
       glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-30, 0.0, -98);
        glVertex3f(-30, 8.0, -98);
        glVertex3f(30, 8.0, -98);
        glVertex3f(30, 0.0, -98);
    glEnd();
    glBegin(GL_QUADS); //Pijakan Kaki (atas)
        glColor3f(0.165f,0.09f,0.004f);
        glVertex3f(-30, 8.0, -98);
        glVertex3f(-30, 8.0, -90);
        glVertex3f(30, 8.0, -90);
        glVertex3f(30, 8.0, -98);
    glEnd();
    glBegin(GL_LINE_LOOP);//Garis pijakan kaki (atas)
       glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-30, 8.0, -98);
        glVertex3f(-30, 8.0, -90);
        glVertex3f(30, 8.0, -90);
        glVertex3f(30, 8.0, -98);
    glEnd();
    glBegin(GL_QUADS); //Pijakan Kaki (depan)
        glColor3f(0.165f,0.09f,0.004f);
        glVertex3f(-30, 0.0, -85);
        glVertex3f(-30, 8.0, -90);
        glVertex3f(30, 8.0, -90);
        glVertex3f(30, 0.0, -85);
    glEnd();
        glBegin(GL_LINE_LOOP);//Garis pijakan kaki (depan)
       glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-30, 0.0, -85);
        glVertex3f(-30, 8.0, -90);
        glVertex3f(30, 8.0, -90);
        glVertex3f(30, 0.0, -85);
    glEnd();
    glBegin(GL_QUADS); //Pijakan Kaki (bawah)
        glColor3f(0.165f,0.09f,0.004f);
        glVertex3f(-30, 0.0, -98);
        glVertex3f(-30, 0.0, -85);
        glVertex3f(30, 0.0, -85);
        glVertex3f(30, 0.0, -98);
    glEnd();
        glBegin(GL_LINE_LOOP);//Garis pijakan kaki (depan)
       glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-30, 0.0, -98);
        glVertex3f(-30, 0.0, -85);
        glVertex3f(30, 0.0, -85);
        glVertex3f(30, 0.0, -98);
    glEnd();

}

void rakdinding(void){
 glBegin(GL_QUADS);//Rak Dinding
    glColor3f(0.671f, 0.322f, 0.0f);
    glVertex3f(-30, 35.0, -50);
    glVertex3f(-30, 35.0, 50);
    glVertex3f(-48, 35.0, 50);
    glVertex3f(-48, 35.0, -50);
    glEnd();
    glBegin(GL_LINE_LOOP);//GARIS Rak Dinding
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-30, 35.0, -50);
    glVertex3f(-30, 35.0, 50);
    glVertex3f(-48, 35.0, 50);
    glVertex3f(-48, 35.0, -50);
    glEnd();
}

void LCD(void){
glBegin(GL_QUADS); //LCD Atas
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-10.0, 48.0, -7.0);
        glVertex3f(10.0, 48.0, -7.0);
        glVertex3f(10.0, 48.0, 7.0);
        glVertex3f(-10.0, 48.0, 7.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//GARIS Lcd Atas
    glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-10.0, 48.0, -7.0);
        glVertex3f(10.0, 48.0, -7.0);
        glVertex3f(10.0, 48.0, 7.0);
        glVertex3f(-10.0, 48.0, 7.0);
    glEnd();
    glBegin(GL_QUADS); //LCD bawah
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-10.0, 40.0, -7.0);
        glVertex3f(10.0, 40.0, -7.0);
        glVertex3f(10.0, 40.0, 7.0);
        glVertex3f(-10.0, 40.0, 7.0);
    glEnd();
  glBegin(GL_LINE_LOOP);//GARIS Lcd bawah
    glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-10.0, 40.0, -7.0);
        glVertex3f(10.0, 40.0, -7.0);
        glVertex3f(10.0, 40.0, 7.0);
        glVertex3f(-10.0, 40.0, 7.0);
    glEnd();
    glBegin(GL_QUADS); //LCD kanan
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(10.0, 40.0, -7.0);
        glVertex3f(10.0, 48.0, -7.0);
        glVertex3f(10.0, 48.0, 7.0);
        glVertex3f(10.0, 40.0, 7.0);
    glEnd();
  glBegin(GL_LINE_LOOP);//GARIS Lcd kanan
    glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(10.0, 40.0, -7.0);
        glVertex3f(10.0, 48.0, -7.0);
        glVertex3f(10.0, 48.0, 7.0);
        glVertex3f(10.0, 40.0, 7.0);
    glEnd();
    glBegin(GL_QUADS); //LCD kiri
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-10.0, 40.0, -7.0);
        glVertex3f(-10.0, 48.0, -7.0);
        glVertex3f(-10.0, 48.0, 7.0);
        glVertex3f(-10.0, 40.0, 7.0);
    glEnd();
  glBegin(GL_LINE_LOOP);//GARIS Lcd kiri
    glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-10.0, 40.0, -7.0);
        glVertex3f(-10.0, 48.0, -7.0);
        glVertex3f(-10.0, 48.0, 7.0);
        glVertex3f(-10.0, 40.0, 7.0);
    glEnd();
    glBegin(GL_QUADS); //LCD depan
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-10.0, 40.0, -7.0);
        glVertex3f(-10.0, 48.0, -7.0);
        glVertex3f(10.0, 48.0, -7.0);
        glVertex3f(10.0, 40.0, -7.0);
    glEnd();
      glBegin(GL_LINE_LOOP);//GARIS Lcd depan
    glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-10.0, 40.0, -7.0);
        glVertex3f(-10.0, 48.0, -7.0);
        glVertex3f(-10.0, 48.0, 7.0);
        glVertex3f(-10.0, 40.0, 7.0);
    glEnd();
    glBegin(GL_QUADS); //LCD belakang
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-10.0, 40.0, 7.0);
        glVertex3f(-10.0, 48.0, 7.0);
        glVertex3f(10.0, 48.0, 7.0);
        glVertex3f(10.0, 40.0, 7.0);
    glEnd();
      glBegin(GL_LINE_LOOP);//GARIS lcd belakang
    glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-10.0, 40.0, 7.0);
        glVertex3f(-10.0, 48.0, 7.0);
        glVertex3f(10.0, 48.0, 7.0);
        glVertex3f(10.0, 40.0, 7.0);
    glEnd();
}


void display(void)
{

    if (is_depth)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);

    jalanrumah();
    interior();

     /*
        ISI KAMPUS

    */

    papantulis();
    pijakankaki();
    redcarpet();
    rakdinding();
    LCD();

    glPopMatrix();
    glutSwapBuffers();
}
void mouseMove(int x, int y) {
    if (mousedown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mousedown = false;
    }
    glutPostRedisplay();
}
/*
Cara penggunaan :
+++++++++++++++++++++----------------------------------------------------+++++++++++++
untuk penggunaan mouse langsung klik rumah dan arahkan
+++++++++++++++++++++----------------------------------------------------+++++++++++++
tombol pada keyboard:
"a": ke kiri
"d": ke kanan
"w": ke depan
"s": ke belakang
"z" : ke atas
"x" : ke bawah
"i" : rotasi ke bawah terhadap sumbu X
"k" : rotasi ke atas terhadap sumbu X
"j" : rotasi ke kiri terhadap sumbu Y
"l" : rotasi ke kanan terhadap sumbu Y
"m" : rotasi ke kiri terhadap sumbu Z
"n" : rotasi ke kanan terhadap sumbu Z
"5" : transparankan rumah
*/
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
    case 'A':
        glTranslatef(5.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(-5.0, 0.0, 0.0);
        break;
    case 'z' :
    case 'Z' :
        glTranslatef(0.0,5.0,0.0);
        break;
    case 'x' :
    case 'X' :
        glTranslatef(0.0,-5.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 5.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -5.0);
        break;
    case 'i':
    case 'I':
        glRotatef(3.0,1.0,0.0,0.0);
        break;
    case 'k':
    case 'K':
        glRotatef(-3.0,1.0,0.0,0.0);
        break;
    case 'j':
    case 'J':
        glRotatef(3.0,0.0,1.0,0.0);
        break;
    case 'l':
    case 'L':
        glRotatef(-3.0,0.0,1.0,0.0);
        break;
    case 'm':
    case 'M':
        glRotatef(3.0,0.0,0.0,1.0);
        break;
    case 'n':
    case 'N':
        glRotatef(-3.0,0.0,0.0,1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth=0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth=1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    display();
}
void resize(int width, int height)
{
    if (height == 0) height = 1;
    //glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, width / height, 1.0, 400.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
