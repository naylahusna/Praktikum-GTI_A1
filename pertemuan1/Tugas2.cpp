#include <GL/glut.h>
void hurufX(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0); 

    glBegin(GL_QUADS);
    glVertex2f(-0.5,0.5); glVertex2f(-0.4,0.5); glVertex2f(-0.4,0.4); glVertex2f(-0.5,0.4);
    glVertex2f(-0.3,0.5); glVertex2f(-0.2,0.5); glVertex2f(-0.2,0.4); glVertex2f(-0.3,0.4);

    glVertex2f(-0.4,0.4); glVertex2f(-0.3,0.4); glVertex2f(-0.3,0.3); glVertex2f(-0.4,0.3);

    glVertex2f(-0.5,0.2); glVertex2f(-0.4,0.2); glVertex2f(-0.4,0.3); glVertex2f(-0.5,0.3);
    glVertex2f(-0.3,0.2); glVertex2f(-0.2,0.2); glVertex2f(-0.2,0.3); glVertex2f(-0.3,0.3);
    glEnd();

    glFlush();
}

//int main (int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitWindowSize(400,400);  
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//	glutCreateWindow("Tugas GTI - Nayla Husna"); 
//	glutDisplayFunc(hurufX); 
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
//	glutMainLoop();
//	return 0;
//}
