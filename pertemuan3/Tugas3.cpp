//Tugas Lengkap

//Lengan bergerak dengan tambahan telapak tangan dan jari

#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0;
static int wrist = 0; 
static int fingerCurl = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void drawFinger(float x_pos, float z_pos, float len, float thickness) {
    glPushMatrix();
        glTranslatef(x_pos, 0.0, z_pos);
        
        glRotatef((GLfloat) fingerCurl, 0.0, 0.0, 1.0);
        glTranslatef(len/2.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(len, thickness, thickness);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(len/2.0, 0.0, 0.0);
        glRotatef((GLfloat) fingerCurl * 1.2, 0.0, 0.0, 1.0);
        glTranslatef(len/3.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(len/1.5, thickness * 0.8, thickness * 0.8);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        
        // lengan atas
        glTranslatef(-1.0, 0.0, 0.0);
        glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();

        // lengan bawah
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();

        // -pergelangan tangan
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat) wrist, 0.0, 0.0, 1.0);

        // -telapak tangan
        glPushMatrix();
            glTranslatef(0.3, 0.0, -0.1);
            glScalef(0.6, 0.25, 0.8);    
            glutWireCube(1.0);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.2, -0.05, 0.4); 
            glScalef(0.4, 0.22, 0.3); 
            glutWireCube(1.0);
        glPopMatrix();

        // jari
        glTranslatef(0.6, 0.0, 0.0); 

        drawFinger(0.0,  0.22, 0.40, 0.13); 
        drawFinger(0.05, 0.02, 0.52, 0.15); 
        drawFinger(0.0, -0.18, 0.46, 0.14); 
        drawFinger(-0.05, -0.38, 0.32, 0.10); 

        // ibu jari
        glPushMatrix();
            glTranslatef(-0.35, 0.0, 0.45); 
            glRotatef(-35, 0.0, 1.0, 0.0);
            glRotatef(-15, 0.0, 0.0, 1.0);
            drawFinger(0.0, 0.0, 0.38, 0.20); 
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;
        case 'w': if(wrist < 45) wrist += 5; break;
        case 'W': if(wrist > -45) wrist -= 5; break;
        case 'f': if(fingerCurl < 85) fingerCurl += 5; break;
        case 'F': if(fingerCurl > 0) fingerCurl -= 5; break;

        case 27: exit(0); break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tangan Bergerak");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
