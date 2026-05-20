/* Nama : Nayla Husna
 * NIM : 24060124140158
 * Kelas : A
 */

#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float angle = 0.0, deltaAngle = 0.0, ratio;
float x = 0.0f, y = 2.5f, z = 15.0f; 
float lx = 0.0f, ly = -0.1f, lz = -1.0f;
int deltaMove = 0, h, w;


void Sisi(float lebar, float tinggi) {
    float hw = lebar / 2, hh = tinggi / 2;
    glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    glVertex3f(-hw, -hh, 0);
    glVertex3f(hw, -hh, 0);
    glVertex3f(hw, hh, 0);
    glVertex3f(-hw, hh, 0);
    glEnd();
}

void Kotak(float lebar, float tinggi, float dalam) {
    float hw = lebar / 2, hh = tinggi / 2, hd = dalam / 2;
    // depan
    glPushMatrix(); glTranslatef(0, 0, hd); Sisi(lebar, tinggi); glPopMatrix();
    // belakang
    glPushMatrix(); glTranslatef(0, 0, -hd); glRotatef(180, 0, 1, 0); Sisi(lebar, tinggi); glPopMatrix();
    // atas
    glPushMatrix(); glTranslatef(0, hh, 0); glRotatef(-90, 1, 0, 0); Sisi(lebar, dalam); glPopMatrix();
    // bawah
    glPushMatrix(); glTranslatef(0, -hh, 0); glRotatef(90, 1, 0, 0); Sisi(lebar, dalam); glPopMatrix();
    // kanan
    glPushMatrix(); glTranslatef(hw, 0, 0); glRotatef(90, 0, 1, 0); Sisi(dalam, tinggi); glPopMatrix();
    // kiri
    glPushMatrix(); glTranslatef(-hw, 0, 0); glRotatef(-90, 0, 1, 0); Sisi(dalam, tinggi); glPopMatrix();
}

void Silinder(float r, float len, int seg) {
    float hl = len / 2, step = 2 * M_PI / seg;
    glBegin(GL_QUADS);
    for (int i = 0; i < seg; i++) {
        float a0 = i * step, a1 = (i + 1) * step;
        float x0 = cos(a0), y0 = sin(a0), x1 = cos(a1), y1 = sin(a1);
        glNormal3f(x0, y0, 0); glVertex3f(x0 * r, y0 * r, -hl); glVertex3f(x0 * r, y0 * r, hl);
        glNormal3f(x1, y1, 0); glVertex3f(x1 * r, y1 * r, hl); glVertex3f(x1 * r, y1 * r, -hl);
    }
    glEnd();
    for (int side = -1; side <= 1; side += 2) {
        glNormal3f(0, 0, (float)side);
        glBegin(GL_POLYGON);
        for (int i = 0; i < seg; i++) {
            float a = (side == 1 ? i : seg - 1 - i) * step;
            glVertex3f(cos(a) * r, sin(a) * r, side * hl);
        }
        glEnd();
    }
}

void Roda() {
    glColor3f(0.1f, 0.1f, 0.1f); Silinder(0.55f, 0.4f, 24); 
    glColor3f(0.7f, 0.7f, 0.7f); Silinder(0.3f, 0.45f, 20); 
}

// =mobil 3d
// referensi dari mobil yang dibuat pada pertemuan 2

void Mobil() {
    glColor3f(0.25f, 0.50f, 1.0f); 
    glPushMatrix();
        glTranslatef(0, 0.75f, 0);
        Kotak(3.2f, 1.1f, 6.0f); 
    glPopMatrix();

    glColor3f(0.30f, 0.55f, 1.0f);
    glPushMatrix();
        glTranslatef(0, 1.75f, 0.5f);
        Kotak(2.9f, 1.0f, 3.2f); 
    glPopMatrix();

    // kaca
    glColor3f(0.85f, 0.95f, 1.0f);
    glPushMatrix();
        glTranslatef(0, 1.75f, -1.11f); 
        Kotak(2.5f, 0.75f, 0.05f); 
    glPopMatrix();

    glPushMatrix(); // Kanan
        glTranslatef(1.46f, 1.75f, 0.5f);
        Kotak(0.02f, 0.75f, 2.6f); 
    glPopMatrix();
    glPushMatrix(); // Kiri
        glTranslatef(-1.46f, 1.75f, 0.5f);
        Kotak(0.02f, 0.75f, 2.6f); 
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, 1.75f, 2.11f);
        Kotak(2.5f, 0.75f, 0.05f);
    glPopMatrix();

    // lampu mobil
    glColor3f(1.0f, 1.0f, 0.9f);
    glPushMatrix(); glTranslatef(-0.95f, 0.9f, -3.01f); Kotak(0.6f, 0.4f, 0.1f); glPopMatrix();
    glPushMatrix(); glTranslatef( 0.95f, 0.9f, -3.01f); Kotak(0.6f, 0.4f, 0.1f); glPopMatrix();

    glColor3f(1.0f, 0.6f, 0.0f);
    glPushMatrix(); glTranslatef(-1.35f, 0.9f, -3.01f); Kotak(0.2f, 0.3f, 0.1f); glPopMatrix();
    glPushMatrix(); glTranslatef( 1.35f, 0.9f, -3.01f); Kotak(0.2f, 0.3f, 0.1f); glPopMatrix();

    glColor3f(0.8f, 0.0f, 0.0f);
    glPushMatrix(); glTranslatef(-1.1f, 0.9f, 3.01f); Kotak(0.7f, 0.4f, 0.1f); glPopMatrix();
    glPushMatrix(); glTranslatef( 1.1f, 0.9f, 3.01f); Kotak(0.7f, 0.4f, 0.1f); glPopMatrix();

    // spion
    glColor3f(0.15f, 0.15f, 0.15f);
    glPushMatrix(); glTranslatef(0, 0.45f, -2.85f); Kotak(3.3f, 0.45f, 0.35f); glPopMatrix();
    glColor3f(0.25f, 0.50f, 1.0f);
    glPushMatrix(); glTranslatef(-1.6f, 1.55f, -0.6f); Kotak(0.3f, 0.2f, 0.4f); glPopMatrix();
    glPushMatrix(); glTranslatef( 1.6f, 1.55f, -0.6f); Kotak(0.3f, 0.2f, 0.4f); glPopMatrix();

    // roda
    float ry = 0.55f, rz = 1.8f, rx = 1.65f;
    glPushMatrix(); glTranslatef(-rx, ry, -rz); glRotatef(90,0,1,0); Roda(); glPopMatrix();
    glPushMatrix(); glTranslatef( rx, ry, -rz); glRotatef(90,0,1,0); Roda(); glPopMatrix();
    glPushMatrix(); glTranslatef(-rx, ry,  rz); glRotatef(90,0,1,0); Roda(); glPopMatrix();
    glPushMatrix(); glTranslatef( rx, ry,  rz); glRotatef(90,0,1,0); Roda(); glPopMatrix();
}

void Reshape(int w1, int h1) {
    if (h1 == 0) h1 = 1;
    w = w1; h = h1;
    ratio = 1.0f * w / h;
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void orientMe(float ang) {
    lx = sin(ang); lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void moveMeFlat(int i) {
    x = x + i * (lx) * 0.15;
    z = z + i * (lz) * 0.15;
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void Grid() {
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    for(float i=-50; i<=50; i+=1.5) {
        glVertex3f(i, 0, -50); glVertex3f(i, 0, 50);
        glVertex3f(-50, 0, i); glVertex3f(50, 0, i);
    }
    glEnd();
}

void display() {
    if (deltaMove) moveMeFlat(deltaMove);
    if (deltaAngle) { angle += deltaAngle; orientMe(angle); }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    Grid();
    Mobil(); // fungsi mobil

    glutSwapBuffers();
}

void pressKey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT: deltaAngle = -0.015f; break;
        case GLUT_KEY_RIGHT: deltaAngle = 0.015f; break;
        case GLUT_KEY_UP: deltaMove = 1; break;
        case GLUT_KEY_DOWN: deltaMove = -1; break;
    }
}

void releaseKey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT: if (deltaAngle < 0.0f) deltaAngle = 0.0f; break;
        case GLUT_KEY_RIGHT: if (deltaAngle > 0.0f) deltaAngle = 0.0f; break;
        case GLUT_KEY_UP: if (deltaMove > 0) deltaMove = 0; break;
        case GLUT_KEY_DOWN: if (deltaMove < 0) deltaMove = 0; break;
    }
}

const GLfloat light_ambient[]  = { 0.4f, 0.4f, 0.4f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 10.0f, 20.0f, 10.0f, 1.0f };

void lighting() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    GLfloat mat_specular[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, 50.0f);
}

void init(void) {
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f); 
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil 3D - Lighting & Depth");
    glutIgnoreKeyRepeat(1);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(Reshape);
    lighting();
    init();
    glutMainLoop();
    return(0);
}
