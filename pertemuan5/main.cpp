/*
 * Nama : Nayla Husna
 * NIM : 24060124140158
 * Kelas : A
 */

#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <GL/glut.h> 

double rotAngle = 10; // rotation angle (BEWARE: Global)  
double rotAngle1 = 10; // rotation angle (BEWARE: Global)  

//------------------------------------------------------------------ 
// init  
// Sets up some default OpenGL values.  
//------------------------------------------------------------------ 
void init()  
{  
    glClearColor(0, 0, 0, 0); // background color  
    glClearDepth(1.0); // background depth value  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();  
    gluPerspective(60, 1, 1, 1000); // setup a perspective projection  
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();  
    gluLookAt( // set up the camera  
        0.0, 0.0, 5.0,  // eye position  
        0.0, 0.0, 0.0,  // lookat position  
        0.0, 1.0, 0.0); // up direction  
}  

//------------------------------------------------------------------ 
// display callback function  
//------------------------------------------------------------------ 
void display()  
{  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glPushMatrix(); // save the current camera transform  
    glRotated(rotAngle, 0, 1, 0); // rotate by rotAngle about y-axis   
    glRotated(rotAngle1, 1, 0, 0); // rotate by rotAngle about x-axis  
    glEnable(GL_COLOR_MATERIAL); // specify object color  
    glColor3f(1.0, 0.1, 0.1); // redish  
    glutSolidTeapot(1); // draw the teapot  
    glPopMatrix(); // restore the modelview matrix  
    glFlush(); // force OpenGL to render now  
    glutSwapBuffers(); // make the image visible  
}  

//------------------------------------------------------------------  
// keyboard callback function  
//------------------------------------------------------------------ 
void keyboard(unsigned char k, int x, int y)  
{  
    switch (k)  
    {  
    case 'a':  
        rotAngle += 5; 
        break;  
    case 'y':  
        rotAngle1 += 5; 
        break;  
    case 'b':  
        rotAngle1 -= 5; 
        break;  
    case 'l':  
        rotAngle -= 5; 
        break;  
    case 'q':  
        exit(0); 
    }  
    glutPostRedisplay(); // redraw the image now  
}  

//-----------------------------------------------------------------  
// main program  
//------------------------------------------------------------------ 
int main(int argc, char** argv)  
{  
    glutInit(&argc, argv); // PERBAIKAN: Wajib ditambahkan agar GLUT bisa jalan
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB); 
    glutCreateWindow("GLUT Example"); 
    glutDisplayFunc(display); 
    glutKeyboardFunc(keyboard); 
    init(); 
    glutMainLoop(); 
    return 0;  
}
