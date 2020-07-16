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
int main (int argc, char **argv) {

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
void jam(void){
        glBegin(GL_QUADS);//pintu kampus kiri
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(-5, 250.0, 138);
        glVertex3f(-5, 240.0, 138);
        glVertex3f(5, 240.0, 138);
        glVertex3f(5, 250.0, 138);
    glEnd();
        glBegin(GL_LINE_LOOP);//garis pintu kiri
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-5, 250.0, 138);
        glVertex3f(-5, 240.0, 138);
        glVertex3f(5, 240.0, 138);
        glVertex3f(5, 250.0, 138);
    glEnd();

}

void init(void){
    glClearColor(1.0, 0.412, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glLineWidth(6.0f);
}

void interior(int xkiri, int xkanan, int xatas) {
    glBegin(GL_QUADS);//tembok depan kampus
        glColor3f(0.851f, 0.467f, 0.0f);
        glVertex3f(-80.0 - xkiri, 0.0, 100.1);
        glVertex3f(-80.0 - xkiri, 100.0 + xatas, 100.1);
        glVertex3f(80.0 + xkanan, 100.0 + xatas, 100.1);
           glVertex3f(80.0 + xkanan, 0.0, 100.1);
    glEnd();

    glBegin(GL_LINE_LOOP);
       glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-80.0 - xkiri, 0.0, 100.1);
        glVertex3f(-80.0 - xkiri, 100.0 + xatas, 100.1);
        glVertex3f(80.0 + xkanan, 100.0 + xatas, 100.1);
        glVertex3f(80.0 + xkanan, 0.0, 100.1);
    glEnd();

        glBegin(GL_QUADS);//garis belakang
        glColor3f(0.851f, 0.467f, 0.0f);
        glVertex3f(-80.0 - xkiri, 0.0, -100.1);
        glVertex3f(-80.0 - xkiri, 100.0 + xatas, -100.1);
        glVertex3f(80.0 + xkanan, 100.0 + xatas, -100.1);
           glVertex3f(80.0 + xkanan, 0.0, -100.1);
    glEnd();

       glBegin(GL_LINE_LOOP);
       glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-80.0 - xkiri, 0.0, -100.1);
        glVertex3f(-80.0 - xkiri, 100.0 + xatas, -100.1);
        glVertex3f(80.0 + xkanan, 100.0 + xatas, -100.1);
        glVertex3f(80.0 + xkanan, 0.0, -100.1);
    glEnd();

    glBegin(GL_QUADS);//garis depan rumah`transisi 1 kiri
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-50.0 - xkiri +20, 100.0 + xatas, 100.1);
        glVertex3f(-50.0 - xkiri +20, 100.0 + xatas, 120.1);
        glVertex3f(-50.0 - xkiri +20, 0.0, 120.1);
        glVertex3f(-50.0 - xkiri +20, 0.0, 100.1);
    glEnd();

       glBegin(GL_LINE_LOOP);
       glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-50.0 - xkiri +20, 100.0 + xatas, 100.1);
        glVertex3f(-50.0 - xkiri +20, 100.0 + xatas, 120.1);
        glVertex3f(-50.0 - xkiri +20, 0.0, 120.1);
        glVertex3f(-50.0 - xkiri +20, 0.0, 100.1);
    glEnd();

    glBegin(GL_QUADS);//garis depan rumah`transisi 2 kiri
        glColor3f(203/255.0f, 135/255.0f, 87/255.0f);
        glVertex3f(-50.0 - xkiri +20, 100.0 + xatas, 120.1);
        glVertex3f(-20.0 - xkiri +40, 100.0 + xatas, 120.1);
        glVertex3f(-20.0 - xkiri +40, 0.0, 120.1);
        glVertex3f(-50.0 - xkiri +20, 0.0, 120.1);
    glEnd();

     glBegin(GL_LINE_LOOP);
       glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-50.0 - xkiri +20, 100.0 + xatas, 120.1);
        glVertex3f(-20.0 - xkiri +40, 100.0 + xatas, 120.1);
        glVertex3f(-20.0 - xkiri +40, 0.0, 120.1);
        glVertex3f(-50.0  - xkiri +20, 0.0, 120.1);
    glEnd();

     glBegin(GL_QUADS);//garis depan rumah`transisi 3 kiri
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-20.0 - xkiri +40, 100.0 + xatas, 120.1);
        glVertex3f(-20.0 - xkiri +40, 100.0 + xatas, 140.1);
        glVertex3f(-20.0 - xkiri +40, 0.0, 140.1);
        glVertex3f(-20.0  - xkiri +40, 0.0, 120.1);
    glEnd();

glBegin(GL_LINE_LOOP);
       glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-20.0 - xkiri +40, 100.0 + xatas, 120.1);
        glVertex3f(-20.0 - xkiri +40, 100.0 + xatas, 140.1);
        glVertex3f(-20.0 - xkiri +40, 0.0, 140.1);
        glVertex3f(-20.0 - xkiri +40, 0.0, 120.1);
    glEnd();

     glBegin(GL_QUADS);//garis depan rumah`transisi 4 kiri
        glColor3f(203/255.0f, 135/255.0f, 87/255.0f);
        glVertex3f(-20.0 - xkiri +40, 100.0 + xatas, 140.1);
        glVertex3f(40.0, 100.0 + xatas, 140.1);
        glVertex3f(40.0, 0.0, 140.1);
        glVertex3f(-20.0 - xkiri +40, 0.0, 140.1);
    glEnd();

glBegin(GL_LINE_LOOP);
       glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-20.0 - xkiri +40, 100.0 + xatas, 140.1);
        glVertex3f(40.0, 100.0 + xatas, 140.1);
        glVertex3f(40.0, 0.0, 140.1);
        glVertex3f(-20.0 - xkiri +40, 0.0, 140.1);
    glEnd();

     glBegin(GL_QUADS);//garis depan rumah`transisi 1 kanan
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(40.0, 100.0 + xatas, 120.1);
        glVertex3f(40.0, 100.0 + xatas, 140.1);
        glVertex3f(40.0, 0.0, 140.1);
        glVertex3f(40.0, 0.0, 120.1);
    glEnd();

glBegin(GL_LINE_LOOP);
       glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(40.0, 100.0 + xatas, 120.1);
        glVertex3f(40.0, 100.0 + xatas, 140.1);
        glVertex3f(40.0, 0.0, 140.1);
        glVertex3f(40.0, 0.0, 120.1);
    glEnd();

     glBegin(GL_QUADS);//garis depan rumah`transisi 2 kanan
        glColor3f(203/255.0f, 135/255.0f, 87/255.0f);
        glVertex3f(40.0, 100.0 + xatas, 120.1);
        glVertex3f(40.0 + xkanan -10, 100.0 + xatas, 120.1);
        glVertex3f(40.0 + xkanan -10, 0.0, 120.1);
        glVertex3f(40.0, 0.0, 120.1);
    glEnd();

glBegin(GL_LINE_LOOP);
       glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(40.0, 100.0 + xatas, 120.1);
        glVertex3f(40.0 + xkanan -10, 100.0 + xatas, 120.1);
        glVertex3f(40.0 + xkanan -10, 0.0, 120.1);
        glVertex3f(40.0, 0.0, 120.1);
    glEnd();

    glBegin(GL_QUADS);//garis depan rumah`transisi 3 kanan
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(40.0 + xkanan -10, 100.0 + xatas, 100.1);
        glVertex3f(40.0 + xkanan -10, 100.0 + xatas, 120.1);
        glVertex3f(40.0 + xkanan -10, 0.0, 120.1);
        glVertex3f(40.0 + xkanan -10, 0.0, 100.1);
    glEnd();

glBegin(GL_LINE_LOOP);
       glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(40.0 + xkanan -10, 100.0 + xatas, 100.1);
        glVertex3f(40.0 + xkanan -10, 100.0 + xatas, 120.1);
        glVertex3f(40.0 + xkanan -10, 0.0, 120.1);
        glVertex3f(40.0 + xkanan -10, 0.0, 100.1);
    glEnd();

    glBegin(GL_QUADS); //penutup tembok depan bagian belakang
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-50.0 - xkiri +20, 100.0 + xatas, 120.0);
        glVertex3f(40.0 + xkanan -10, 100.0 + xatas, 120.0);
        glVertex3f(40.0 + xkanan -10, 0.0, 120.0);
        glVertex3f(-50.0 - xkiri +20, 0.0, 120.0);
    glEnd();

     glBegin(GL_QUADS); //penutup tembok belakang bagian belakang
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-50.0 - xkiri +20, 100.0 + xatas, 100.2);
        glVertex3f(40.0 + xkanan -10, 100.0 + xatas, 100.2);
        glVertex3f(40.0 + xkanan -10, 0.0, 100.2);
        glVertex3f(-50.0 - xkiri +20, 0.0, 100.2);
    glEnd();

     glBegin(GL_QUADS); //penutup tembok atas bagian belakang
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-50.0 - xkiri +20, 100.0 + xatas, 100.1);
        glVertex3f(40.0 + xkanan -10, 100.0 + xatas, 100.1);
        glVertex3f(40.0 + xkanan -10, 100.0 + xatas, 120.1);
       glVertex3f(-50.0 - xkiri +20, 100.0 + xatas, 120.1);
    glEnd();

     glBegin(GL_QUADS); //penutup tembok bawah bagian belakang
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-50.0 - xkiri +20, 0.0, 100.1);
        glVertex3f(40.0 + xkanan -10, 0.0, 100.1);
        glVertex3f(40.0 + xkanan -10, 0.0, 120.1);
       glVertex3f(-50.0 - xkiri +20, 0.0, 120.1);
    glEnd();

     glBegin(GL_QUADS);//penutup tembok depan bagian depan
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-20.0 - xkiri +40, 100.0 + xatas, 140.0);
        glVertex3f(40.0, 100.0 + xatas, 140.0);
        glVertex3f(40.0, 0.0, 140.0);
        glVertex3f(-20.0 - xkiri +40, 0.0, 140.0);
    glEnd();

     glBegin(GL_QUADS);//penutup tembok atas bagian depan
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-20.0 - xkiri +40, 100.0 + xatas, 120.1);
        glVertex3f(40.0, 100.0 + xatas, 120.1);
        glVertex3f(40.0, 100.0 + xatas, 140.1);
       glVertex3f(-20.0 - xkiri +40, 100.0 + xatas, 140.1);
    glEnd();

    glBegin(GL_QUADS);//penutup tembok bawah bagian depan
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-20.0 - xkiri +40, 0.0, 120.1);
        glVertex3f(40.0, 0.0, 120.1);
        glVertex3f(40.0, 0.0, 140.1);
       glVertex3f(-20.0 - xkiri +40, 0.0, 140.1);
    glEnd();

        glBegin(GL_QUADS);//tembok kanan
        glColor3f(0.851f, 0.467f, 0.0f);
        glVertex3f(140.0, 0.0, 100.0);
        glVertex3f(140.0, 180.0, 100.0);
        glVertex3f(140.0, 180.0, -100.0);
        glVertex3f(140.0, 0.0, -100.0);
    glEnd();

        glBegin(GL_LINE_LOOP);//garis tembok kanan
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(140.0, 0.0, 100.0);
        glVertex3f(140.0, 180.0, 100.0);
        glVertex3f(140.0, 180.0, -100.0);
        glVertex3f(140.0, 0.0, -100.0);
    glEnd();

        glBegin(GL_QUADS);//tembok kiri
        glColor3f(0.851f, 0.467f, 0.0f);
        glVertex3f(-140.0, 0.0, 100.0);
        glVertex3f(-140.0, 180.0, 100.0);
        glVertex3f(-140.0, 180.0, -100.0);
        glVertex3f(-140.0, 0.0, -100.0);
    glEnd();

        glBegin(GL_LINE_LOOP);//garis tembok kiri
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-140.0, 0.0, 100.0);
        glVertex3f(-140.0, 180.0, 100.0);
        glVertex3f(-140.0, 180.0, -100.0);
        glVertex3f(-140.0, 0.0, -100.0);
    glEnd();
}

void menaraKiri(int xkiri, int xkanan, int xatas) {
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-170.0 - xkiri +20, 100.0 + xatas, 150);
        glVertex3f(-160.0, 100.0 + xatas, 150);
        glVertex3f(-160.0, 0.0, 150);
        glVertex3f(-170.0 - xkiri +20, 0.0, 150);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-170.0 - xkiri +20, 100.0 + xatas, 150);
        glVertex3f(-160.0, 100.0 + xatas, 150);
        glVertex3f(-160.0, 0.0, 150);
        glVertex3f(-170.0 - xkiri +20, 0.0, 150);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-150.0 - xkiri +50, 100.0 + xatas, 150);
        glVertex3f(-140.0, 100.0 + xatas, 100);
        glVertex3f(-140.0, 0.0, 100);
        glVertex3f(-150.0 - xkiri +50, 0.0, 150);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-150.0 - xkiri +50, 100.0 + xatas, 150);
        glVertex3f(-140.0, 100.0 + xatas, 100);
        glVertex3f(-140.0, 0.0, 100);
        glVertex3f(-150.0 - xkiri +50, 0.0, 150);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-220.0 - xkiri +50, 100.0 + xatas, 100);
        glVertex3f(-210.0, 100.0 + xatas, 150);
        glVertex3f(-210, 0.0, 150);
        glVertex3f(-220.0 - xkiri +50, 0.0, 100);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-220.0 - xkiri +50, 100.0 + xatas, 100);
        glVertex3f(-210.0, 100.0 + xatas, 150);
        glVertex3f(-210, 0.0, 150);
        glVertex3f(-220.0 - xkiri +50, 0.0, 100);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-220.0 - xkiri +50, 100.0 + xatas, 100);
        glVertex3f(-210.0, 100.0 + xatas, 50);
        glVertex3f(-210.0, 0.0, 50);
        glVertex3f(-220.0 - xkiri +50, 0.0, 100);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-220.0 - xkiri +50, 100.0 + xatas, 100);
        glVertex3f(-210.0, 100.0 + xatas, 50);
        glVertex3f(-210.0, 0.0, 50);
        glVertex3f(-220.0 - xkiri +50, 0.0, 100);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-170.0 - xkiri +20, 100.0 + xatas, 50);
        glVertex3f(-160.0, 100.0 + xatas, 50);
        glVertex3f(-160.0, 0.0, 50);
        glVertex3f(-170.0 - xkiri +20, 0.0, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-170.0 - xkiri +20, 100.0 + xatas, 50);
        glVertex3f(-160.0, 100.0 + xatas, 50);
        glVertex3f(-160.0, 0.0, 50);
        glVertex3f(-170.0 - xkiri +20, 0.0, 50);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-150.0 - xkiri +50, 100.0 + xatas, 50);
        glVertex3f(-140.0, 100.0 + xatas, 100);
        glVertex3f(-140.0, 0.0, 100);
        glVertex3f(-150.0 - xkiri +50, 0.0, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-150.0 - xkiri +50, 100.0 + xatas, 50);
        glVertex3f(-140.0, 100.0 + xatas, 100);
        glVertex3f(-140.0, 0.0, 100);
        glVertex3f(-150.0 - xkiri +50, 0.0, 50);
    glEnd();
}


void menaraKanan(int xkiri, int xkanan, int xatas) {
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(160.0, 100.0 + xatas, 150);
        glVertex3f(170.0 + xkanan - 20, 100.0 + xatas, 150);
        glVertex3f(170.0 + xkanan - 20, 0.0, 150);
        glVertex3f(160.0, 0.0, 150);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(160.0, 100.0 + xatas, 150);
        glVertex3f(170.0 + xkanan - 20, 100.0 + xatas, 150);
        glVertex3f(170.0 + xkanan - 20, 0.0, 150);
        glVertex3f(160.0, 0.0, 150);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(140.0, 100.0 + xatas, 100);
        glVertex3f(150.0 + xkanan - 50, 100.0 + xatas, 150);
        glVertex3f(150.0 + xkanan - 50, 0.0, 150);
        glVertex3f(140.0, 0.0, 100);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(140.0, 100.0 + xatas, 100);
        glVertex3f(150.0 + xkanan - 50, 100.0 + xatas, 150);
        glVertex3f(150.0 + xkanan - 50, 0.0, 150);
        glVertex3f(140.0, 0.0, 100);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(210.0, 100.0 + xatas, 150);
        glVertex3f(220.0 + xkanan - 50, 100.0 + xatas, 100);
        glVertex3f(220.0 + xkanan - 50, 0.0, 100);
        glVertex3f(210.0, 0.0, 150);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(210.0, 100.0 + xatas, 150);
        glVertex3f(220.0 + xkanan - 50, 100.0 + xatas, 100);
        glVertex3f(220.0 + xkanan - 50, 0.0, 100);
        glVertex3f(210.0, 0.0, 150);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(160.0, 100.0 + xatas, 50);
        glVertex3f(170.0 + xkanan - 20, 100.0 + xatas, 50);
        glVertex3f(170.0 + xkanan - 20, 0.0, 50);
        glVertex3f(160.0, 0.0, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(160.0, 100.0 + xatas, 50);
        glVertex3f(170.0 + xkanan - 20, 100.0 + xatas, 50);
        glVertex3f(170.0 + xkanan - 20, 0.0, 50);
        glVertex3f(160.0, 0.0, 50);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(140.0, 100.0 + xatas, 100);
        glVertex3f(150.0 + xkanan - 50, 100.0 + xatas, 50);
        glVertex3f(150.0 + xkanan - 50, 0.0, 50);
        glVertex3f(140.0, 0.0, 100);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(140.0, 100.0 + xatas, 100);
        glVertex3f(150.0 + xkanan - 50, 100.0 + xatas, 50);
        glVertex3f(150.0 + xkanan - 50, 0.0, 50);
        glVertex3f(140.0, 0.0, 100);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(210.0, 100.0 + xatas, 50);
        glVertex3f(220.0 + xkanan - 50, 100.0 + xatas, 100);
        glVertex3f(220.0 + xkanan - 50, 0.0, 100);
        glVertex3f(210.0, 0.0, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(210.0, 100.0 + xatas, 50);
        glVertex3f(220.0 + xkanan - 50, 100.0 + xatas, 100);
        glVertex3f(220.0 + xkanan - 50, 0.0, 100);
        glVertex3f(210.0, 0.0, 50);
    glEnd();
}

void pembatasjendela(int x, int px, int y, int z) {
    glBegin(GL_QUADS); //belakang
    glColor3f(113/255.0f,108/255.0f,98/255.0f);
    glVertex3f(-135.0 +x,140.0 -y,100.2 +z);
    glVertex3f(-95.0 +x + px,140.0 -y,100.2 +z);
    glVertex3f(-95.0 +x + px,138.0 -y,100.2 +z);
    glVertex3f(-135.0 +x,138.0 -y,100.2 +z);
    glEnd();

    glBegin(GL_QUADS); //depan
    glColor3f(113/255.0f,108/255.0f,98/255.0f);
    glVertex3f(-135.0 +x,140.0 -y,104.2 +z);
    glVertex3f(-95.0 +x + px,140.0 -y,104.2 +z);
    glVertex3f(-95.0 +x + px,138.0 -y,104.2 +z);
    glVertex3f(-135.0 +x,138.0 -y,104.2 +z);
    glEnd();

    glBegin(GL_QUADS); //kiri
    glColor3f(113/255.0f,108/255.0f,98/255.0f);
    glVertex3f(-135.0 +x,140.0 -y,100.2 +z);
    glVertex3f(-135.0 +x,140.0 -y,104.2 +z);
    glVertex3f(-135.0 +x,138.0 -y,104.2 +z);
    glVertex3f(-135.0 +x,138.0 -y,100.2 +z);
    glEnd();

    glBegin(GL_QUADS); //kanan
    glColor3f(113/255.0f,108/255.0f,98/255.0f);
    glVertex3f(-95.0 +x + px,140.0 -y,100.2 +z);
    glVertex3f(-95.0 +x + px,140.0 -y,104.2 +z);
    glVertex3f(-95.0 +x + px,138.0 -y,104.2 +z);
    glVertex3f(-95.0 +x + px,138.0 -y,100.2 +z);
    glEnd();

    glBegin(GL_QUADS); //atas
    glColor3f(113/255.0f,108/255.0f,98/255.0f);
    glVertex3f(-135.0 +x,140.0 -y,100.2 +z);
    glVertex3f(-95.0 +x + px,140.0 -y,100.2 +z);
    glVertex3f(-95.0 +x + px,140.0 -y,104.2 +z);
    glVertex3f(-135.0 +x,140.0 -y,104.2 +z);
    glEnd();

    glBegin(GL_QUADS); //atas
    glColor3f(113/255.0f,108/255.0f,98/255.0f);
    glVertex3f(-135.0 +x,138.0 -y,100.2 +z);
    glVertex3f(-95.0 +x + px,138.0 -y,100.2 +z);
    glVertex3f(-95.0 +x + px,138.0 -y,104.2 +z);
    glVertex3f(-135.0 +x,138.0 -y,104.2 +z);
    glEnd();
}

void jendela (int x, int y, int z){
glLineWidth(2.0);


glBegin(GL_LINE_LOOP); //garis jendela luar
glColor3f(1.0,1.0,1.0);
glVertex3f(-131.0 +x, 147.5 +y, 100.9 +z);
glVertex3f(-117.0 +x, 147.5 +y, 100.9 +z);
glVertex3f(-117.0 +x, 172.5 +y, 100.9 +z);
glVertex3f(-131.0 +x, 172.5 +y, 100.9 +z);
glEnd();


glBegin(GL_POLYGON); //kotak pinggir jendela
glColor3f(1.0,1.0,1.0);
glVertex3f(-130.0 +x, 150.0 +y, 100.9 +z);
glVertex3f(-118.0 +x, 150.0 +y, 100.9 +z);
glVertex3f(-118.0 +x, 170.0 +y, 100.9 +z);
glVertex3f(-130.0 +x, 170.0 +y, 100.9 +z);
glEnd();


glBegin(GL_POLYGON); //isikotakjendela kiri
glColor3f(91/255.0f,106/255.0f,104/255.0f);
glVertex3f(-130.0 +x, 170.0 +y, 101.0 +z);
glVertex3f(-126.0 +x, 170.0 +y, 101.0 +z);
glVertex3f(-126.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-130.0 +x, 165.0 +y, 101.0 +z);
glEnd();

glBegin(GL_POLYGON); //isikotakjendela tengah
glColor3f(91/255.0f,106/255.0f,104/255.0f);
glVertex3f(-126.0 +x, 170.0 +y, 101.0 +z);
glVertex3f(-122.0 +x, 170.0 +y, 101.0 +z);
glVertex3f(-122.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-126.0 +x, 165.0 +y, 101.0 +z);
glEnd();

glBegin(GL_POLYGON); //isikotakjendela kanan
glColor3f(91/255.0f,106/255.0f,104/255.0f);
glVertex3f(-122.0 +x, 170.0 +y, 101.0 +z);
glVertex3f(-118.0 +x, 170.0 +y, 101.0 +z);
glVertex3f(-118.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-122.0 +x, 165.0 +y, 101.0 +z);
glEnd();


glBegin(GL_POLYGON); //isikotakjendela kiri
glColor3f(91/255.0f,106/255.0f,104/255.0f);
glVertex3f(-130.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-126.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-126.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-130.0 +x, 160.0 +y, 101.0 +z);
glEnd();

glBegin(GL_POLYGON); //isikotakjendela tengah
glColor3f(91/255.0f,106/255.0f,104/255.0f);
glVertex3f(-126.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-122.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-122.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-126.0 +x, 160.0 +y, 101.0 +z);
glEnd();

glBegin(GL_POLYGON); //isikotakjendela kanan
glColor3f(91/255.0f,106/255.0f,104/255.0f);
glVertex3f(-122.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-118.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-118.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-122.0 +x, 160.0 +y, 101.0 +z);
glEnd();



glBegin(GL_LINE_LOOP); //gariskotakjendela kiri
glColor3f(1.0,1.0,1.0);
glVertex3f(-130.0 +x, 170.0 +y, 101.0 +z);
glVertex3f(-126.0 +x, 170.0 +y, 101.0 +z);
glVertex3f(-126.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-130.0 +x, 165.0 +y, 101.0 +z);
glEnd();

glBegin(GL_LINE_LOOP); //gariskotakjendela tengah
glColor3f(1.0,1.0,1.0);
glVertex3f(-126.0 +x, 170.0 +y, 101.0 +z);
glVertex3f(-122.0 +x, 170.0 +y, 101.0 +z);
glVertex3f(-122.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-126.0 +x, 165.0 +y, 101.0 +z);
glEnd();

glBegin(GL_LINE_LOOP); //gariskotakjendela kanan
glColor3f(1.0,1.0,1.0);
glVertex3f(-122.0 +x, 170.0 +y, 101.0 +z);
glVertex3f(-118.0 +x, 170.0 +y, 101.0 +z);
glVertex3f(-118.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-122.0 +x, 165.0 +y, 101.0 +z);
glEnd();


glBegin(GL_LINE_LOOP); //gariskotakjendela kiri
glColor3f(1.0,1.0,1.0);
glVertex3f(-130.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-126.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-126.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-130.0 +x, 160.0 +y, 101.0 +z);
glEnd();

glBegin(GL_LINE_LOOP); //gariskotakjendela tengah
glColor3f(1.0,1.0,1.0);
glVertex3f(-126.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-122.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-122.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-126.0 +x, 160.0 +y, 101.0 +z);
glEnd();

glBegin(GL_LINE_LOOP); //gariskotakjendela kanan
glColor3f(1.0,1.0,1.0);
glVertex3f(-122.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-118.0 +x, 165.0 +y, 101.0 +z);
glVertex3f(-118.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-122.0 +x, 160.0 +y, 101.0 +z);
glEnd();


}

void jendelabawah(int x, int y, int z, int a, int b){
/*bagian bawah*/

glBegin(GL_LINES); //garis pemisah
glLineWidth(5.0);
glColor3f(1.0,1.0,1.0);
glVertex3f(-130.0 +x, 160.0 +y, 101.2 +z);
glVertex3f(-118.0 +x, 160.0 +y, 101.2 +z);
glEnd();


glBegin(GL_POLYGON); //isikotakjendela kiri
glColor3f(91/255.0f,106/255.0f,104/255.0f);
glVertex3f(-130.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-126.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-126.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-130.0 +x, 155.0 +y, 101.0 +z +a);
glEnd();

glBegin(GL_POLYGON); //isikotakjendela tengah
glColor3f(91/255.0f,106/255.0f,104/255.0f);
glVertex3f(-126.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-122.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-122.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-126.0 +x, 155.0 +y, 101.0 +z +a);
glEnd();

glBegin(GL_POLYGON); //isikotakjendela kanan
glColor3f(91/255.0f,106/255.0f,104/255.0f);
glVertex3f(-122.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-118.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-118.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-122.0 +x, 155.0 +y, 101.0 +z +a);
glEnd();


glBegin(GL_POLYGON); //isikotakjendela kiri
glColor3f(91/255.0f,106/255.0f,104/255.0f);
glVertex3f(-130.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-126.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-126.0 +x, 150.0 +y, 101.0 +z +a +b);
glVertex3f(-130.0 +x, 150.0 +y, 101.0 +z +a +b);
glEnd();

glBegin(GL_POLYGON); //isikotakjendela tengah
glColor3f(91/255.0f,106/255.0f,104/255.0f);
glVertex3f(-126.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-122.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-122.0 +x, 150.0 +y, 101.0 +z +a +b);
glVertex3f(-126.0 +x, 150.0 +y, 101.0 +z +a +b);
glEnd();

glBegin(GL_POLYGON); //isikotakjendela kanan
glColor3f(91/255.0f,106/255.0f,104/255.0f);
glVertex3f(-122.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-118.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-118.0 +x, 150.0 +y, 101.0 +z +a +b);
glVertex3f(-122.0 +x, 150.0 +y, 101.0 +z +a +b);
glEnd();



glBegin(GL_LINE_LOOP); //gariskotakjendela kiri
glColor3f(1.0,1.0,1.0);
glVertex3f(-130.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-126.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-126.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-130.0 +x, 155.0 +y, 101.0 +z +a);
glEnd();

glBegin(GL_LINE_LOOP); //gariskotakjendela tengah
glColor3f(1.0,1.0,1.0);
glVertex3f(-126.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-122.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-122.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-126.0 +x, 155.0 +y, 101.0 +z +a);
glEnd();

glBegin(GL_LINE_LOOP); //gariskotakjendela kanan
glColor3f(1.0,1.0,1.0);
glVertex3f(-122.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-118.0 +x, 160.0 +y, 101.0 +z);
glVertex3f(-118.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-122.0 +x, 155.0 +y, 101.0 +z +a);
glEnd();


glBegin(GL_LINE_LOOP); //gariskotakjendela kiri
glColor3f(1.0,1.0,1.0);
glVertex3f(-130.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-126.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-126.0 +x, 150.0 +y, 101.0 +z +a +b);
glVertex3f(-130.0 +x, 150.0 +y, 101.0 +z +a +b);
glEnd();

glBegin(GL_LINE_LOOP); //gariskotakjendela tengah
glColor3f(1.0,1.0,1.0);
glVertex3f(-126.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-122.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-122.0 +x, 150.0 +y, 101.0 +z +a +b);
glVertex3f(-126.0 +x, 150.0 +y, 101.0 +z +a +b);
glEnd();

glBegin(GL_LINE_LOOP); //gariskotakjendela kanan
glColor3f(1.0,1.0,1.0);
glVertex3f(-122.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-118.0 +x, 155.0 +y, 101.0 +z +a);
glVertex3f(-118.0 +x, 150.0 +y, 101.0 +z +a +b);
glVertex3f(-122.0 +x, 150.0 +y, 101.0 +z +a +b);
glEnd();



}

void jalanrumah(void) {
    glBegin(GL_QUADS);//Jalan Halaman kampus
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex3f(-400.0, -10.0, -400.0);
        glColor3f(0.4f, 0.4f, 0.4f);
        glVertex3f(-400.0, -10.0, 400.0);
        glColor3f(0.6f, 0.6f, 0.6f);
        glVertex3f(400.0, -10.0, 400.0);
        glColor3f(0.8f, 0.8f, 0.8f);
        glVertex3f(400.0, -10.0, -400.0);
    glEnd();
     glBegin(GL_LINE_LOOP);//Garis Halaman kampus
       glColor3f(0.0f, 0.0f, 0.0f);
       glVertex3f(-400.0, -10.0, -400.0);
       glVertex3f(-400.0, -10.0, 400.0);
       glVertex3f(400.0, -10.0, 400.0);
       glVertex3f(400.0, -10.0, -400.0);
    glEnd();

}

void atap(void) {
    glBegin(GL_TRIANGLES);//atap belakang
        glColor3f(0.5f,0.5f,0.5f);
        glVertex3f(0.0, 230.0, 0.0);
        glVertex3f(-140.0, 180.0, -100.0);
        glVertex3f(140.0, 180.0, -100.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//garis atap belakang
         glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(0.0, 230.0, 0.0);
        glVertex3f(-140.0, 180.0, -100.0);
        glVertex3f(140.0, 180.0, -100.0);
    glEnd();

    glBegin(GL_TRIANGLES);//atap depan
        glColor3f(0.5f,0.5f,0.5f);
        glVertex3f(0.0, 230.0, 0.0);
        glVertex3f(-140.0, 180.0, 100.0);
        glVertex3f(140.0, 180.0, 100.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//garis atap belakang
         glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(0.0, 230.0, 0.0);
        glVertex3f(-140.0, 180.0, 100.0);
        glVertex3f(140.0, 180.0, 100.0);
    glEnd();

    glBegin(GL_TRIANGLES);//atap kanan
        glColor3f(0.5f,0.5f,0.5f);
        glVertex3f(140.0, 180.0, -100.0);
        glVertex3f(140.0, 180.0, 100.0);
        glVertex3f(0.0, 230.0, 0.0);
    glEnd();

    glBegin(GL_LINE_LOOP); // garis atap kanan
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(140.0, 180.0, -100.0);
        glVertex3f(140.0, 180.0, 100.0);
        glVertex3f(0.0, 230.0, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);//atap kiri
        glColor3f(0.5f,0.5f,0.5f);
        glVertex3f(-140.0, 180.0, -100.0);
        glVertex3f(-140.0, 180.0, 100.0);
        glVertex3f(0.0, 230.0, 0.0);
    glEnd();

    glBegin(GL_LINE_LOOP); // garis atap kiri
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(-140.0, 180.0, -100.0);
        glVertex3f(-140.0, 180.0, 100.0);
        glVertex3f(0.0, 230.0, 0.0);
    glEnd();
}

void atapMenaraKiri(void) {
    glBegin(GL_TRIANGLES);//atap depan
        glColor3f(0.5f,0.5f,0.5f);
        glVertex3f(-190, 230.0, 100.0);
        glVertex3f(-160.0, 180.0, 150.0);
        glVertex3f(-210.0, 180.0, 150.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis atap depan
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(-190, 230.0, 100.0);
        glVertex3f(-160.0, 180.0, 150.0);
        glVertex3f(-210.0, 180.0, 150.0);
    glEnd();

    glBegin(GL_TRIANGLES);//atap belakang
        glColor3f(0.5f,0.5f,0.5f);
        glVertex3f(-190, 230.0, 100.0);
        glVertex3f(-160.0, 180.0, 50.0);
        glVertex3f(-210.0, 180.0, 50.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis atap belakang
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(-190, 230.0, 100.0);
        glVertex3f(-160.0, 180.0, 50.0);
        glVertex3f(-210.0, 180.0, 50.0);
    glEnd();

    glBegin(GL_TRIANGLES);//atap samping kanan 1
        glColor3f(0.5f,0.5f,0.5f);
        glVertex3f(-190, 230.0, 100.0);
        glVertex3f(-160.0, 180.0, 50.0);
        glVertex3f(-140.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis atap samoing kanan 1
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(-190, 230.0, 100.0);
        glVertex3f(-160.0, 180.0, 50.0);
        glVertex3f(-140.0, 180.0, 100.0);
    glEnd();

    glBegin(GL_TRIANGLES);//atap samping kanan 2
        glColor3f(0.5f,0.5f,0.5f);
        glVertex3f(-190, 230.0, 100.0);
        glVertex3f(-160.0, 180.0, 150.0);
        glVertex3f(-140.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis atap samoing kanan 2
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(-190, 230.0, 100.0);
        glVertex3f(-160.0, 180.0, 150.0);
        glVertex3f(-140.0, 180.0, 100.0);
    glEnd();

    glBegin(GL_TRIANGLES);//atap samping kiri 1
        glColor3f(0.5f,0.5f,0.5f);
        glVertex3f(-190, 230.0, 100.0);
        glVertex3f(-210.0, 180.0, 50.0);
        glVertex3f(-230.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis atap samoing kanan 2
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(-190, 230.0, 100.0);
        glVertex3f(-210.0, 180.0, 50.0);
        glVertex3f(-230.0, 180.0, 100.0);
    glEnd();

    glBegin(GL_TRIANGLES);//atap samping kiri 1
        glColor3f(0.5f,0.5f,0.5f);
        glVertex3f(-190, 230.0, 100.0);
        glVertex3f(-210.0, 180.0, 150.0);
        glVertex3f(-230.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis atap samoing kanan 2
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(-190, 230.0, 100.0);
        glVertex3f(-210.0, 180.0, 150.0);
        glVertex3f(-230.0, 180.0, 100.0);
    glEnd();
}

void atapMenaraKanan(void) {
    glBegin(GL_TRIANGLES);//atap depan
        glColor3f(0.5f,0.5f,0.5f);
        glVertex3f(190, 230.0, 100.0);
        glVertex3f(160.0, 180.0, 150.0);
        glVertex3f(210.0, 180.0, 150.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis atap depan
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(190, 230.0, 100.0);
        glVertex3f(160.0, 180.0, 150.0);
        glVertex3f(210.0, 180.0, 150.0);
    glEnd();

    glBegin(GL_TRIANGLES);//atap belakang
        glColor3f(0.5f,0.5f,0.5f);
        glVertex3f(190, 230.0, 100.0);
        glVertex3f(160.0, 180.0, 50.0);
        glVertex3f(210.0, 180.0, 50.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis atap belakang
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(190, 230.0, 100.0);
        glVertex3f(160.0, 180.0, 50.0);
        glVertex3f(210.0, 180.0, 50.0);
    glEnd();

    glBegin(GL_TRIANGLES);//atap samping kanan 1
        glColor3f(0.5f,0.5f,0.5f);
        glVertex3f(190, 230.0, 100.0);
        glVertex3f(160.0, 180.0, 50.0);
        glVertex3f(140.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis atap samoing kanan 1
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(190, 230.0, 100.0);
        glVertex3f(160.0, 180.0, 50.0);
        glVertex3f(140.0, 180.0, 100.0);
    glEnd();

    glBegin(GL_TRIANGLES);//atap samping kanan 2
        glColor3f(0.5f,0.5f,0.5f);
        glVertex3f(190, 230.0, 100.0);
        glVertex3f(160.0, 180.0, 150.0);
        glVertex3f(140.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis atap samoing kanan 2
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(190, 230.0, 100.0);
        glVertex3f(160.0, 180.0, 150.0);
        glVertex3f(140.0, 180.0, 100.0);
    glEnd();

    glBegin(GL_TRIANGLES);//atap samping kiri 1
        glColor3f(0.5f,0.5f,0.5f);
        glVertex3f(190, 230.0, 100.0);
        glVertex3f(210.0, 180.0, 50.0);
        glVertex3f(230.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis atap samoing kanan 2
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(190, 230.0, 100.0);
        glVertex3f(210.0, 180.0, 50.0);
        glVertex3f(230.0, 180.0, 100.0);
    glEnd();

    glBegin(GL_TRIANGLES);//atap samping kiri 1
        glColor3f(0.5f,0.5f,0.5f);
        glVertex3f(190, 230.0, 100.0);
        glVertex3f(210.0, 180.0, 150.0);
        glVertex3f(230.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis atap samoing kanan 2
        glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(190, 230.0, 100.0);
        glVertex3f(210.0, 180.0, 150.0);
        glVertex3f(230.0, 180.0, 100.0);
    glEnd();
}

void setengahLingkaran(void) {
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(20.0, 210.0, 140.0);
        glVertex3f(-20.0, 210.0, 140.0);
        glVertex3f(-20.0, 180.0, 140.0);
        glVertex3f(20.0, 180.0, 140.0);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(40.0, 180.0, 140.0);
        glVertex3f(20.0, 180.0, 140.0);
        glVertex3f(20.0, 210.0, 140.0);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-40.0, 180.0, 140.0);
        glVertex3f(-20.0, 180.0, 140.0);
        glVertex3f(-20.0, 210.0, 140.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-20.0, 210.0, 140.0);
        glVertex3f(20.0, 210.0, 140.0);
        glVertex3f(40.0, 180.0, 140.0);
        glVertex3f(-40.0, 180.0, 140.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-20.0, 210.0, 140.0);
        glVertex3f(-20.0, 210.0, 120.0);
        glVertex3f(-40.0, 180.0, 120.0);
        glVertex3f(-40.0, 180.0, 140.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-20.0, 210.0, 140.0);
        glVertex3f(-20.0, 210.0, 120.0);
        glVertex3f(-40.0, 180.0, 120.0);
        glVertex3f(-40.0, 180.0, 140.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(20.0, 210.0, 140.0);
        glVertex3f(20.0, 210.0, 120.0);
        glVertex3f(40.0, 180.0, 120.0);
        glVertex3f(40.0, 180.0, 140.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(20.0, 210.0, 140.0);
        glVertex3f(20.0, 210.0, 120.0);
        glVertex3f(40.0, 180.0, 120.0);
        glVertex3f(40.0, 180.0, 140.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(20.0, 210.0, 140.0);
        glVertex3f(-20.0, 210.0, 140.0);
        glVertex3f(-20.0, 210.0, 120.0);
        glVertex3f(20.0, 210.0, 120.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(20.0, 210.0, 140.0);
        glVertex3f(-20.0, 210.0, 140.0);
        glVertex3f(-20.0, 210.0, 120.0);
        glVertex3f(20.0, 210.0, 120.0);
    glEnd();
}

void menaraJam(void) {
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.851f, 0.714f);
        glVertex3f(10.0, 210.0, 137.0);
        glVertex3f(10.0, 250.0, 137.0);
        glVertex3f(10.0, 250.0, 123.0);
        glVertex3f(10.0, 210.0, 123.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(10.0, 210.0, 137.0);
        glVertex3f(10.0, 250.0, 137.0);
        glVertex3f(10.0, 250.0, 123.0);
        glVertex3f(10.0, 210.0, 123.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.851f, 0.714f);
        glVertex3f(-10.0, 210.0, 137.0);
        glVertex3f(-10.0, 250.0, 137.0);
        glVertex3f(-10.0, 250.0, 123.0);
        glVertex3f(-10.0, 210.0, 123.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-10.0, 210.0, 137.0);
        glVertex3f(-10.0, 250.0, 137.0);
        glVertex3f(-10.0, 250.0, 123.0);
        glVertex3f(-10.0, 210.0, 123.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.851f, 0.714f);
        glVertex3f(10.0, 210.0, 137.0);
        glVertex3f(-10.0, 210.0, 137.0);
        glVertex3f(-10.0, 250.0, 137.0);
        glVertex3f(10.0, 250.0, 137.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(10.0, 210.0, 137.0);
        glVertex3f(-10.0, 210.0, 137.0);
        glVertex3f(-10.0, 250.0, 137.0);
        glVertex3f(10.0, 250.0, 137.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.851f, 0.714f);
        glVertex3f(10.0, 210.0, 123.0);
        glVertex3f(-10.0, 210.0, 123.0);
        glVertex3f(-10.0, 250.0, 123.0);
        glVertex3f(10.0, 250.0, 123.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(10.0, 210.0, 123.0);
        glVertex3f(-10.0, 210.0, 123.0);
        glVertex3f(-10.0, 250.0, 123.0);
        glVertex3f(10.0, 250.0, 123.0);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.851f, 0.714f);
        glVertex3f(10.0, 250.0, 137);
        glVertex3f(0.0, 275.0, (137+123)/2);
        glVertex3f(-10.0, 250.0, 137);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(10.0, 250.0, 137);
        glVertex3f(0.0, 275.0, (137+123)/2);
        glVertex3f(-10.0, 250.0, 137);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.851f, 0.714f);
        glVertex3f(10.0, 250.0, 123);
        glVertex3f(0.0, 275.0, (137+123)/2);
        glVertex3f(-10.0, 250.0, 123);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(10.0, 250.0, 123);
        glVertex3f(0.0, 275.0, (137+123)/2);
        glVertex3f(-10.0, 250.0, 123);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.851f, 0.714f);
        glVertex3f(-10.0, 250.0, 123);
        glVertex3f(0.0, 275.0, (137+123)/2);
        glVertex3f(-10.0, 250.0, 137);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-10.0, 250.0, 123);
        glVertex3f(0.0, 275.0, (137+123)/2);
        glVertex3f(-10.0, 250.0, 137);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.851f, 0.714f);
        glVertex3f(10.0, 250.0, 123);
        glVertex3f(0.0, 275.0, (137+123)/2);
        glVertex3f(10.0, 250.0, 137);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(10.0, 250.0, 123);
        glVertex3f(0.0, 275.0, (137+123)/2);
        glVertex3f(10.0, 250.0, 137);
    glEnd();
}

void pintukampus(void) {
    glBegin(GL_QUADS);//pintu kampus kiri
        glColor3f(0.702f,0.29f,0.0f);
        glVertex3f(-18, 1.0, 141.1);
        glVertex3f(-18, 40.0, 141.1);
        glVertex3f(0, 40.0, 141.1);
        glVertex3f(0, 1.0, 141.1);
    glEnd();
        glBegin(GL_LINE_LOOP);//garis pintu kiri
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-18, 1.0, 141.1);
        glVertex3f(-18, 40.0, 141.1);
        glVertex3f(0, 40.0, 141.1);
        glVertex3f(0, 1.0, 141.1);
    glEnd();

    glBegin(GL_QUADS);//pintu kampus kanan
        glColor3f(0.702f,0.29f,0.0f);
        glVertex3f(0, 1.0, 141.1);
        glVertex3f(0, 40.0, 141.1);
        glVertex3f(18, 40.0, 141.1);
        glVertex3f(18, 1.0, 141.1);
    glEnd();
        glBegin(GL_LINE_LOOP);//garis pintu kanan
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0, 1.0, 141.1);
        glVertex3f(0, 40.0, 141.1);
        glVertex3f(18, 40.0, 141.1);
        glVertex3f(18, 1.0, 141.1);
    glEnd();
}

void papantulis(void) {
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

void redcarpet(void) {
glBegin(GL_QUADS);// RED CARPET
        glColor3f(0.973f,0.0f,0.0f);
        glVertex3f(-60, -3.0, -50);
       glVertex3f(-60, -3.0, 50);
       glVertex3f(60, -3.0, 50);
       glVertex3f(60, -3.0, -50);
    glEnd();
        glBegin(GL_LINE_LOOP);//GARIS RED CARPET
       glColor3f(0.0f, 0.0f, 0.0f);
       glVertex3f(-60, -3.0, -50);
       glVertex3f(-60, -3.0, 50);
       glVertex3f(60, -3.0, 50);
       glVertex3f(60, -3.0, -50);
    glEnd();
}

void pijakankaki(void) {
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

void rakdinding(void) {
 glBegin(GL_QUADS);//Rak Dinding
    glColor3f(0.671f, 0.322f, 0.0f);
    glVertex3f(-120, 35.0, -50);
    glVertex3f(-120, 35.0, 50);
    glVertex3f(-138, 35.0, 50);
    glVertex3f(-138, 35.0, -50);
    glEnd();
    glBegin(GL_LINE_LOOP);//GARIS Rak Dinding
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-120, 35.0, -50);
    glVertex3f(-120, 35.0, 50);
    glVertex3f(-138, 35.0, 50);
    glVertex3f(-138, 35.0, -50);
    glEnd();
}

void LCD(void) {
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

void kakikursi(int px, int py, int pz){

    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0 + px, -10.0 +py, 50.0 -pz);
	glVertex3f(1 +px, -10.0 +py, 50.0 -pz);                //kaki kursi depan
	glVertex3f(1 +px, -5.0 +py, 50.0 -pz);
	glVertex3f(0+px, -5.0 +py, 50.0 -pz);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0 +px, -10.0 +py, 49.0 -pz);
	glVertex3f(1 +px, -10.0 +py, 49.0 -pz);                //kaki kursi belakang
	glVertex3f(1 +px, -5.0 +py, 49.0 -pz);
	glVertex3f(0 +px, -5.0 +py, 49.0 -pz);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0 +px, -10.0 +py, 50.0 -pz);
	glVertex3f(0 +px, -10.0 +py, 49.0 -pz);                //kaki kursi kiri
	glVertex3f(0 +px, -5.0 +py, 49.0 -pz);
	glVertex3f(0 +px, -5.0 +py, 50.0 -pz);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(1 +px, -5.0 +py, 50.0 -pz);
	glVertex3f(1 +px, -10.0 +py, 50.0 -pz);                //kaki kursi kanan
	glVertex3f(1 +px, -10.0 +py, 49.0 -pz);
	glVertex3f(1 +px, -5.0 +py, 49.0 -pz);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0 +px, -10.0 +py, 50.0 -pz);
	glVertex3f(1 +px, -10.0 +py, 50.0 -pz);                //kaki kursi bawah
	glVertex3f(1 +px, -10.0 +py, 49.0 -pz);
	glVertex3f(0 +px, -10.0 +py, 49.0 -pz);
	glEnd();

}
void bantalkursi(void){
    glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0 , -5.0, 50.0 );
	glVertex3f(4 , -5.0, 50.0 );
	glVertex3f(4 , -5.0, 46.0 );
	glVertex3f(0 , -5.0, 46.0 );
	glEnd();

}

void kakimeja(int px, int py, int pz){
    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0 + px, -10.0 +py, 50.0 -pz);
	glVertex3f(1 +px, -10.0 +py, 50.0 -pz);                //kaki meja depan
	glVertex3f(1 +px, -5.0 +py, 50.0 -pz);
	glVertex3f(0+px, -5.0 +py, 50.0 -pz);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0 +px, -10.0 +py, 49.0 -pz);
	glVertex3f(1 +px, -10.0 +py, 49.0 -pz);                //kaki meja belakang
	glVertex3f(1 +px, -5.0 +py, 49.0 -pz);
	glVertex3f(0 +px, -5.0 +py, 49.0 -pz);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0 +px, -10.0 +py, 50.0 -pz);
	glVertex3f(0 +px, -10.0 +py, 49.0 -pz);                //kaki meja kiri
	glVertex3f(0 +px, -5.0 +py, 49.0 -pz);
	glVertex3f(0 +px, -5.0 +py, 50.0 -pz);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(1 +px, -5.0 +py, 50.0 -pz);
	glVertex3f(1 +px, -10.0 +py, 50.0 -pz);                //kaki meja kanan
	glVertex3f(1 +px, -10.0 +py, 49.0 -pz);
	glVertex3f(1 +px, -5.0 +py, 49.0 -pz);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0 +px, -10.0 +py, 50.0 -pz);
	glVertex3f(1 +px, -10.0 +py, 50.0 -pz);                //kaki meja bawah
	glVertex3f(1 +px, -10.0 +py, 49.0 -pz);
	glVertex3f(0 +px, -10.0 +py, 49.0 -pz);
	glEnd();


}

void tutupmeja(void){
    glBegin(GL_QUADS);
	glColor3f(0.5, 0.9, 0.0);
	glVertex3f(0 , -5.0, 50.0 );
	glVertex3f(4 , -5.0, 50.0 );
	glVertex3f(4 , -5.0, 43.0 );
	glVertex3f(0 , -5.0, 43.0 );
	glEnd();
}


void penutupkursi(void){
glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0 , 0.0, 50.0 );
	glVertex3f(1 , 0.0, 50.0 );
	glVertex3f(1 , 0.0, 46.0 );
	glVertex3f(0 , 0.0, 46.0 );
	glEnd();

}

void lampugantung(void){

    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(0.375, 8.25, 49.5);               //tali
    glVertex3f(0.375, 11.0, 49.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(0.375, 11.0, 49.5);               //tali
    glVertex3f(3.0, 11.0, 49.5);
    glEnd();


    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0, 8.25, 50.0);
	glVertex3f(0.75, 8.25, 50.0);                //lampu atas
	glVertex3f(0.75, 8.25, 49.0);
	glVertex3f(0, 8.25, 49.0);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0, 6.5, 50.0);
	glVertex3f(0.75, 6.5, 50.0);                //lampu depan
	glVertex3f(0.75, 8.25, 50.0);
	glVertex3f(0, 8.25, 50.0);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0, 6.5, 49.0);
	glVertex3f(0.75, 6.5, 49.0);                //lampu belakang
	glVertex3f(0.75, 8.25, 49.0);
	glVertex3f(0, 8.25, 49.0);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0, 6.5, 50.0);
	glVertex3f(0, 6.5, 49.0);                //lampu kiri
	glVertex3f(0, 8.25, 49.0);
	glVertex3f(0, 8.25, 50.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.75, 6.5, 50.0);
	glVertex3f(0.75, 6.5, 49.0);                //lampu kanan
	glVertex3f(0.75, 8.25, 49.0);
	glVertex3f(0.75, 8.25, 50.0);
	glEnd();

}

void cerobong(void) {
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-40.0, 180.0, 140.0);
        glVertex3f(-40.0, 210.0, 140.0);
        glVertex3f(-40.0, 210.0, 120.0);
        glVertex3f(-40.0, 180.0, 120.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-40.0, 180.0, 140.0);
        glVertex3f(-40.0, 210.0, 140.0);
        glVertex3f(-40.0, 210.0, 120.0);
        glVertex3f(-40.0, 180.0, 120.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-35.0, 187.5, 140.0);
        glVertex3f(-35.0, 210.0, 140.0);
        glVertex3f(-35.0, 210.0, 120.0);
        glVertex3f(-35.0, 187.5, 120.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-35.0, 187.5, 140.0);
        glVertex3f(-35.0, 210.0, 140.0);
        glVertex3f(-35.0, 210.0, 120.0);
        glVertex3f(-35.0, 187.5, 120.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-35.0, 210.0, 140.0);
        glVertex3f(-40.0, 210.0, 140.0);
        glVertex3f(-40.0, 180.0, 140.0);
        glVertex3f(-35.0, 187.5, 140.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-35.0, 210.0, 140.0);
        glVertex3f(-40.0, 210.0, 140.0);
        glVertex3f(-40.0, 180.0, 140.0);
        glVertex3f(-35.0, 187.5, 140.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-35.0, 210.0, 120.0);
        glVertex3f(-40.0, 210.0, 120.0);
        glVertex3f(-40.0, 180.0, 120.0);
        glVertex3f(-35.0, 187.5, 120.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-35.0, 210.0, 120.0);
        glVertex3f(-40.0, 210.0, 120.0);
        glVertex3f(-40.0, 180.0, 120.0);
        glVertex3f(-35.0, 187.5, 120.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(40.0, 180.0, 140.0);
        glVertex3f(40.0, 210.0, 140.0);
        glVertex3f(40.0, 210.0, 120.0);
        glVertex3f(40.0, 180.0, 120.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(40.0, 180.0, 140.0);
        glVertex3f(40.0, 210.0, 140.0);
        glVertex3f(40.0, 210.0, 120.0);
        glVertex3f(40.0, 180.0, 120.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(35.0, 187.5, 140.0);
        glVertex3f(35.0, 210.0, 140.0);
        glVertex3f(35.0, 210.0, 120.0);
        glVertex3f(35.0, 187.5, 120.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(35.0, 187.5, 140.0);
        glVertex3f(35.0, 210.0, 140.0);
        glVertex3f(35.0, 210.0, 120.0);
        glVertex3f(35.0, 187.5, 120.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(35.0, 210.0, 140.0);
        glVertex3f(40.0, 210.0, 140.0);
        glVertex3f(40.0, 180.0, 140.0);
        glVertex3f(35.0, 187.5, 140.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(35.0, 210.0, 140.0);
        glVertex3f(40.0, 210.0, 140.0);
        glVertex3f(40.0, 180.0, 140.0);
        glVertex3f(35.0, 187.5, 140.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(35.0, 210.0, 120.0);
        glVertex3f(40.0, 210.0, 120.0);
        glVertex3f(40.0, 180.0, 120.0);
        glVertex3f(35.0, 187.5, 120.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(35.0, 210.0, 120.0);
        glVertex3f(40.0, 210.0, 120.0);
        glVertex3f(40.0, 180.0, 120.0);
        glVertex3f(35.0, 187.5, 120.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-90.0, 180.0, 120.0);
        glVertex3f(-90.0, 210.0, 120.0);
        glVertex3f(-90.0, 210.0, 100.0);
        glVertex3f(-90.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-90.0, 180.0, 120.0);
        glVertex3f(-90.0, 210.0, 120.0);
        glVertex3f(-90.0, 210.0, 100.0);
        glVertex3f(-90.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-85.0, 180.0, 120.0);
        glVertex3f(-85.0, 210.0, 120.0);
        glVertex3f(-85.0, 210.0, 100.0);
        glVertex3f(-85.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-85.0, 180.0, 120.0);
        glVertex3f(-85.0, 210.0, 120.0);
        glVertex3f(-85.0, 210.0, 100.0);
        glVertex3f(-85.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-85.0, 210.0, 120.0);
        glVertex3f(-90.0, 210.0, 120.0);
        glVertex3f(-90.0, 180.0, 120.0);
        glVertex3f(-85.0, 180.0, 120.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-85.0, 210.0, 120.0);
        glVertex3f(-90.0, 210.0, 120.0);
        glVertex3f(-90.0, 180.0, 120.0);
        glVertex3f(-85.0, 180.0, 120.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-85.0, 210.0, 100.0);
        glVertex3f(-90.0, 210.0, 100.0);
        glVertex3f(-90.0, 180.0, 100.0);
        glVertex3f(-85.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-85.0, 210.0, 100.0);
        glVertex3f(-90.0, 210.0, 100.0);
        glVertex3f(-90.0, 180.0, 100.0);
        glVertex3f(-85.0, 180.0, 100.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(90.0, 180.0, 120.0);
        glVertex3f(90.0, 210.0, 120.0);
        glVertex3f(90.0, 210.0, 100.0);
        glVertex3f(90.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(90.0, 180.0, 120.0);
        glVertex3f(90.0, 210.0, 120.0);
        glVertex3f(90.0, 210.0, 100.0);
        glVertex3f(90.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(85.0, 180.0, 120.0);
        glVertex3f(85.0, 210.0, 120.0);
        glVertex3f(85.0, 210.0, 100.0);
        glVertex3f(85.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(85.0, 180.0, 120.0);
        glVertex3f(85.0, 210.0, 120.0);
        glVertex3f(85.0, 210.0, 100.0);
        glVertex3f(85.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(85.0, 210.0, 120.0);
        glVertex3f(90.0, 210.0, 120.0);
        glVertex3f(90.0, 180.0, 120.0);
        glVertex3f(85.0, 180.0, 120.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(85.0, 210.0, 120.0);
        glVertex3f(90.0, 210.0, 120.0);
        glVertex3f(90.0, 180.0, 120.0);
        glVertex3f(85.0, 180.0, 120.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(85.0, 210.0, 100.0);
        glVertex3f(90.0, 210.0, 100.0);
        glVertex3f(90.0, 180.0, 100.0);
        glVertex3f(85.0, 180.0, 100.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(85.0, 210.0, 100.0);
        glVertex3f(90.0, 210.0, 100.0);
        glVertex3f(90.0, 180.0, 100.0);
        glVertex3f(85.0, 180.0, 100.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-215.0, 180.0, 95.0);
        glVertex3f(-215.0, 220.0, 95.0);
        glVertex3f(-215.0, 220.0, 75.0);
        glVertex3f(-215.0, 180.0, 75.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-215.0, 180.0, 95.0);
        glVertex3f(-215.0, 220.0, 95.0);
        glVertex3f(-215.0, 220.0, 75.0);
        glVertex3f(-215.0, 180.0, 75.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-210.0, 180.0, 95.0);
        glVertex3f(-210.0, 220.0, 95.0);
        glVertex3f(-210.0, 220.0, 75.0);
        glVertex3f(-210.0, 180.0, 75.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-210.0, 180.0, 95.0);
        glVertex3f(-210.0, 220.0, 95.0);
        glVertex3f(-210.0, 220.0, 75.0);
        glVertex3f(-210.0, 180.0, 75.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-215.0, 220.0, 95.0);
        glVertex3f(-210.0, 220.0, 95.0);
        glVertex3f(-210.0, 180.0, 95.0);
        glVertex3f(-215.0, 180.0, 95.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-215.0, 220.0, 95.0);
        glVertex3f(-210.0, 220.0, 95.0);
        glVertex3f(-210.0, 180.0, 95.0);
        glVertex3f(-215.0, 180.0, 95.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(-215.0, 220.0, 75.0);
        glVertex3f(-210.0, 220.0, 75.0);
        glVertex3f(-210.0, 180.0, 75.0);
        glVertex3f(-215.0, 180.0, 75.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-215.0, 220.0, 75.0);
        glVertex3f(-210.0, 220.0, 75.0);
        glVertex3f(-210.0, 180.0, 75.0);
        glVertex3f(-215.0, 180.0, 75.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(215.0, 180.0, 95.0);
        glVertex3f(215.0, 220.0, 95.0);
        glVertex3f(215.0, 220.0, 75.0);
        glVertex3f(215.0, 180.0, 75.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(215.0, 180.0, 95.0);
        glVertex3f(215.0, 220.0, 95.0);
        glVertex3f(215.0, 220.0, 75.0);
        glVertex3f(215.0, 180.0, 75.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(210.0, 180.0, 95.0);
        glVertex3f(210.0, 220.0, 95.0);
        glVertex3f(210.0, 220.0, 75.0);
        glVertex3f(210.0, 180.0, 75.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(210.0, 180.0, 95.0);
        glVertex3f(210.0, 220.0, 95.0);
        glVertex3f(210.0, 220.0, 75.0);
        glVertex3f(210.0, 180.0, 75.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(215.0, 220.0, 95.0);
        glVertex3f(210.0, 220.0, 95.0);
        glVertex3f(210.0, 180.0, 95.0);
        glVertex3f(215.0, 180.0, 95.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(215.0, 220.0, 95.0);
        glVertex3f(210.0, 220.0, 95.0);
        glVertex3f(210.0, 180.0, 95.0);
        glVertex3f(215.0, 180.0, 95.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(161/255.0f, 98/255.0f, 52/255.0f);
        glVertex3f(215.0, 220.0, 75.0);
        glVertex3f(210.0, 220.0, 75.0);
        glVertex3f(210.0, 180.0, 75.0);
        glVertex3f(215.0, 180.0, 75.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(215.0, 220.0, 75.0);
        glVertex3f(210.0, 220.0, 75.0);
        glVertex3f(210.0, 180.0, 75.0);
        glVertex3f(215.0, 180.0, 75.0);
    glEnd();
}

void display(void) {
    if (is_depth)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);
    jam();
    jalanrumah();
    interior(60,60,80);
    menaraKiri(60,60,80);
    menaraKanan(60,60,80);
    atapMenaraKiri();
    atapMenaraKanan();
    menaraJam();
    cerobong();
    pembatasjendela(0,0,-5,0);
    pembatasjendela(0,0,35,0);
    pembatasjendela(0,0,80,0);

    pembatasjendela(50,0,-5,20);
    pembatasjendela(50,0,35,20);
    pembatasjendela(50,0,80,20);

    pembatasjendela(100,30,-5,40);
    pembatasjendela(100,30,35,40);
    pembatasjendela(100,30,80,40);

    pembatasjendela(180,0,-5,20);
    pembatasjendela(180,0,35,20);
    pembatasjendela(180,0,80,20);

    pembatasjendela(230,0,-5,0);
    pembatasjendela(230,0,35,0);
    pembatasjendela(230,0,80,0);

    jendela(0,0,0);
    jendela(17.5,0,0);
    jendela(0,-40,0);
    jendela(17.5,-40,0);
    jendela(0,-85,0);
    jendela(17.5,-85,0);
    jendela(0,-130,0);
    jendela(17.5,-130,0);

    jendela(50,0,20);
    jendela(50 + 17.5,0,20);
    jendela(50,-40,20);
    jendela(50 + 17.5,-40,20);
    jendela(50,-85,20);
    jendela(50 + 17.5,-85,20);
    jendela(50,-130,20);
    jendela(50 + 17.5,-130,20);

    jendela(105,0,40);
    jendela(140,0,40);
    jendela(105,-40,40);
    jendela(140,-40,40);
    jendela(105,-85,40);
    jendela(140,-85,40);

    jendela(180,0,20);
    jendela(180+17.5,0,20);
    jendela(180,-40,20);
    jendela(180+17.5,-40,20);
    jendela(180,-85,20);
    jendela(180+17.5,-85,20);
    jendela(180,-130,20);
    jendela(180+17.5,-130,20);

    jendela(230,0,0);
    jendela(230+17.5,0,0);
    jendela(230,-40,0);
    jendela(230+17.5,-40,0);
    jendela(230,-85,0);
    jendela(230+17.5,-85,0);
    jendela(230,-130,0);
    jendela(230+17.5,-130,0);

    jendelabawah(0,0,0,5,5);
    jendelabawah(17.5,0,0,3,3);
    jendelabawah(0,-40,0,2,2);
    jendelabawah(17.5,-40,0,4,4);
    jendelabawah(0,-85,0,0,0);
    jendelabawah(17.5,-85,0,0,0);
    jendelabawah(0,-130,0,0,0);
    jendelabawah(17.5,-130,0,0,0);

    jendelabawah(50,0,20,2,2);
    jendelabawah(50 + 17.5,0,20,2,2);
    jendelabawah(50,-40,20,0,0);
    jendelabawah(50 + 17.5,-40,20,0,0);
    jendelabawah(50,-85,20,3,3);
    jendelabawah(50 + 17.5,-85,20,3,3);
    jendelabawah(50,-130,20,0,0);
    jendelabawah(50 + 17.5,-130,20,0,0);

    jendelabawah(105,0,40,2,2);
    jendelabawah(140,0,40,0,0);
    jendelabawah(105,-40,40,0,0);
    jendelabawah(140,-40,40,0,0);
    jendelabawah(105,-85,40,0,0);
    jendelabawah(140,-85,40,0,0);

    jendelabawah(180,0,20,2,2);
    jendelabawah(180+17.5,0,20,2,2);
    jendelabawah(180,-40,20,0,0);
    jendelabawah(180+17.5,-40,20,0,0);
    jendelabawah(180,-85,20,0,0);
    jendelabawah(180+17.5,-85,20,0,0);
    jendelabawah(180,-130,20,0,0);
    jendelabawah(180+17.5,-130,20,0,0);

    jendelabawah(230,0,0,0,0);
    jendelabawah(230+17.5,0,0,2,2);
    jendelabawah(230,-40,0,0,0);
    jendelabawah(230+17.5,-40,0,0,0);
    jendelabawah(230,-85,0,0,0);
    jendelabawah(230+17.5,-85,0,0,0);
    jendelabawah(230,-130,0,0,0);
    jendelabawah(230+17.5,-130,0,0,0);

    jendela(-60,4,50.0); //menara kiri
    jendelabawah(-60,4,50.0,0,0);
    pembatasjendela(-68,0,-10,50);

    jendela(-60,-33,50.0); //menara kiri
    jendelabawah(-60,-33,50.0,4,4);
    pembatasjendela(-68,0,30,50);

    jendela(-60,-75,50.0); //menara kiri
    jendelabawah(-60,-75,50.0,3,3);
    pembatasjendela(-68,0,75,50);

    jendela(-60,-120,50.0); //menara kiri
    jendelabawah(-60,-120,50.0,0,0);

    jendela(310,4,50.0); //menara kanan
    jendelabawah(310,4,50.0,3,3);
    pembatasjendela(300,0,-10,50);

    jendela(310,-33,50.0); //menara kanan
    jendelabawah(310,-33,50.0,0,0);
    pembatasjendela(300,0,30,50);

    jendela(310,-75,50.0); //menara kanan
    jendelabawah(310,-75,50.0,0,0);
    pembatasjendela(300,0,75,50);

    jendela(310,-120,50.0); //menara kanan
    jendelabawah(310,-120,50.0,0,0);


    /*menara kiri bagian miring kanan*/
    glPushMatrix();
    glRotatef(67,0.0,1.0,0.0);
    glTranslatef(10,0,-240);
    jendela(-60,4,50.0); //menara kiri
    jendelabawah(-60,4,50.0,2,2);
    pembatasjendela(-68,0,-10,50);
    glPopMatrix();

    glPushMatrix();
    glRotatef(67,0.0,1.0,0.0);
    glTranslatef(10,-40,-240);
    jendela(-60,4,50.0); //menara kiri
    jendelabawah(-60,4,50.0,2,2);
    pembatasjendela(-68,0,-10,50);
    glPopMatrix();

    glPushMatrix();
    glRotatef(67,0.0,1.0,0.0);
    glTranslatef(10,-85,-240);
    jendela(-60,4,50.0); //menara kiri
    jendelabawah(-60,4,50.0,2,2);
    pembatasjendela(-68,0,-10,50);
    glPopMatrix();

    glPushMatrix();
    glRotatef(67,0.0,1.0,0.0);
    glTranslatef(10,0,-240);
    jendela(-60,-120,50.0); //menara kiri
    jendelabawah(-60,-120,50.0,1,1);
    glPopMatrix();

    /*Menara kiri bagian miring kiri*/
    glPushMatrix();
    glTranslatef(-10,0,243);
    glRotatef(-68,0.0,1.0,0.0);
    jendela(-60,4,50.0); //menara kiri
    jendelabawah(-60,4,50.0,3,3);
    pembatasjendela(-68,0,-10,50);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-10,-40,243);
    glRotatef(-68,0.0,1.0,0.0);
    jendela(-60,4,50.0); //menara kiri
    jendelabawah(-60,4,50.0,3,3);
    pembatasjendela(-68,0,-10,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,-85,243);
    glRotatef(-68,0.0,1.0,0.0);
    jendela(-60,4,50.0); //menara kiri
    jendelabawah(-60,4,50.0,1,1);
    pembatasjendela(-68,0,-10,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,0,243);
    glRotatef(-68,0.0,1.0,0.0);
    jendela(-60,-120,50.0); //menara kiri
    jendelabawah(-60,-120,50.0,0,0);
    glPopMatrix();

    /*menara kanan bagian miring kiri*/
    glPushMatrix();
    glTranslatef(221.5,0,-100);
    glRotatef(-68,0.0,1.0,0.0);
    jendela(310,4,50.0); //menara kanan
    jendelabawah(310,4,50.0,2,2);
    pembatasjendela(300,0,-10,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(221.5,-40,-100);
    glRotatef(-68,0.0,1.0,0.0);
    jendela(310,4,50.0); //menara kanan
    jendelabawah(310,4,50.0,2,2);
    pembatasjendela(300,0,-10,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(221.5,-85,-100);
    glRotatef(-68,0.0,1.0,0.0);
    jendela(310,4,50.0); //menara kanan
    jendelabawah(310,4,50.0,3,3);
    pembatasjendela(300,0,-10,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(221.5,0,-100);
    glRotatef(-68,0.0,1.0,0.0);
    jendela(310,-120,50.0); //menara kanan
    jendelabawah(310,-120,50.0,0,0);
    glPopMatrix();

    /*menara kanan bagian miring kanan*/

    glPushMatrix();
    glRotatef(68.0,0.0,1.0,0.0);
    glTranslatef(-218,0,100);
    jendela(310,4,50.0); //menara kanan
    jendelabawah(310,4,50.0,3,3);
    pembatasjendela(300,0,-10,50);
    glPopMatrix();

    glPushMatrix();
    glRotatef(68.0,0.0,1.0,0.0);
    glTranslatef(-218,-40,100);
    jendela(310,4,50.0); //menara kanan
    jendelabawah(310,4,50.0,2,2);
    pembatasjendela(300,0,-10,50);
    glPopMatrix();

    glPushMatrix();
    glRotatef(68.0,0.0,1.0,0.0);
    glTranslatef(-218,-85,100);
    jendela(310,4,50.0); //menara kanan
    jendelabawah(310,4,50.0,0,0);
    pembatasjendela(300,0,-10,50);
    glPopMatrix();

    glPushMatrix();
    glRotatef(68.0,0.0,1.0,0.0);
    glTranslatef(-218,0,100);
    jendela(310,-120,50.0); //menara kanan
    jendelabawah(310,-120,50.0,0,0);
    glPopMatrix();

     /*
        ISI KAMPUS

    */
    pintukampus();
    papantulis();
    pijakankaki();
    redcarpet();
    rakdinding();
    LCD();
    atap();
    setengahLingkaran();

    //kursi
    glPushMatrix();
	glTranslated(-240,47,-20);
	glScalef(5,5,5);
	glRotatef(90,0.0,1.0,0.0);
    kakikursi(0,0,0);
    kakikursi(3,0,0);
    kakikursi(0,0,3);
    kakikursi(3,0,3);
    bantalkursi();
    kakikursi(0,5,0);
    kakikursi(0,5,3);
    penutupkursi();
    glPopMatrix();

    //meja
    glPushMatrix();
    glTranslated(-100,47,-200);
    glScalef(5,5,5);
    kakimeja(0,0,0);
    kakimeja(3,0,0);
    kakimeja(0,0,6);
    kakimeja(3,0,6);
    tutupmeja();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-125,20,220);
    glScalef(5,5,5);
    glRotatef(180,0.0,1.0,0.0);
    lampugantung();
    glPopMatrix();


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
void keyboard(unsigned char key, int x, int y) {
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
void resize(int width, int height) {
    if (height == 0) height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, width / height, 1.0, 1000.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
