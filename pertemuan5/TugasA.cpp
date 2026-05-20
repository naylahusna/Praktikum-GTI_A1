// Nayla Husna - 24060124140158
// Tugas Pertemuan 5 - A
// Mengubah sudut geser

// untuk mengubah sudut geser, pada fungsi keyboard, bagian rotAngle nya diganti menjadi 15
// artinya posisi teko berubah sejauh 45 (biar keliatan bedanya) derajat. opsional anhka berapa aja

#include <stdlib.h>  
#include <stdio.h>  
#include <math.h>     
#include <GL/glut.h>  

double rotAngle = 10; 
double rotAngle1 = 10; 

void init()  
{  
    glClearColor(0, 0, 0, 0); 
    glClearDepth(1.0); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();  
    gluPerspective(60, 1, 1, 1000); 
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();  
    gluLookAt(  
        0.0, 0.0, 5.0,  
        0.0, 0.0, 0.0,  
        0.0, 1.0, 0.0); 
}  

void display()  
{  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glPushMatrix(); 
    glRotated(rotAngle, 0, 1, 0);   
    glRotated(rotAngle1, 1, 0, 0); 
    glEnable(GL_COLOR_MATERIAL); 
    glColor3f(1.0, 0.1, 0.1); 
    glutSolidTeapot(1); 
    glPopMatrix(); 
    glFlush(); 
    glutSwapBuffers(); 
}  

void keyboard(unsigned char k, int x, int y)  
{  
    switch (k)  
    {  
    case 'a':  
        rotAngle += 45; 
        break;  
    case 'y':  
        rotAngle1 += 45; 
        break;  
    case 'b':  
        rotAngle1 -= 45; 
        break;  
    case 'l':  
        rotAngle -= 45; 
        break;  
    case 'q':  
        exit(0); 
    }  
    glutPostRedisplay(); 
}  

int main(int argc, char** argv)  
{  
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB); 
    glutCreateWindow("GLUT Example - Sudut Geser 15 Derajat"); 
    glutDisplayFunc(display); 
    glutKeyboardFunc(keyboard); 
    init(); 
    glutMainLoop(); 
    return 0;  
}
