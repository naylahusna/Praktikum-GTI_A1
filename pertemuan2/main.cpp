/*
 * FreeGLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone 
 * and torus shapes in FreeGLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

//Translasi Objek
#include <gl/glut.h>
void SegiEmpat(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glTranslatef(-0.50, 0.50, 0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(-0.18, 0.18, 0.18, -0.18);
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Segi Empat");
    glutDisplayFunc(SegiEmpat);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}


//Rotasi Objek
#include <gl/glut.h>
void Segitiga(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
    glTranslatef(0.25, -0.25, 0);
    glRotated(60.0, 0.0, 0.0, 1.0);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-0.05, -0.05, 0.00);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.15, -0.05, 0.00);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-0.05, 0.05, 0.00);
    glEnd();
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Segitiga");
    glutDisplayFunc(Segitiga);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}


//Stack Object
#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glLineWidth(2.0f);
        glBegin(GL_LINES);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex3f(0.00, 0.20, 0.0);
            glVertex3f(0.00, -0.20, 0.0);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glPointSize(5.0f);
        glTranslatef(0.35, 0.35, 0.0);
        glBegin(GL_POINTS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex3f(0.25, 0.25, 0.0);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.50, 0.50, 0.00);
        glBegin(GL_TRIANGLE_STRIP);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(-0.05, -0.05, 0.00);

            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(0.15, -0.05, 0.00);

            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex3f(-0.05, 0.05, 0.00);
            
            glColor3f(1.0f, 1.0f, 0.0f);
            glVertex3f(0.15, 0.05, 0.00);
        glEnd();
    glPopMatrix();
    
    glPushMatrix();
    	#define PI 3.1415926535898
    	glBegin(GL_LINE_LOOP);
    		GLint circle_points = 100; 
			int i;
    		float angle;
    		for (i = 0; i < circle_points; i++){
    			angle = 2*PI*i/circle_points;
    			glVertex2f(cos(angle), sin(angle));
    		}
    	glEnd();
    glPopMatrix();

    glFlush();
}
int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutCreateWindow("Simple");
	glutDisplayFunc(RenderScene);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glutMainLoop();
	return 0;
}

//Tugas 2, mobil 2D
#include <GL/glut.h>
#include <math.h>

void Circle(float x, float y, float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 100; i++) {
        float angle = i * 2.0f * 3.14159f / 100;
        glVertex2f(x + (radius * cos(angle)), y + (radius * sin(angle)));
    }
    glEnd();
}

void mobil() {
    glClear(GL_COLOR_BUFFER_BIT);

    // badan mobilnya
    glColor3f(0.2f, 0.3f, 0.6f); 
    glBegin(GL_QUADS);
        glVertex2f(-0.6f, -0.2f); 
        glVertex2f( 0.6f, -0.2f); 
        glVertex2f( 0.6f,  0.2f); 
        glVertex2f(-0.6f,  0.2f);
    glEnd();
    
    // garis pintu
    glColor3f(0.1f, 0.2f, 0.4f); 
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(-0.07f, -0.2f);
        glVertex2f(-0.07f,  0.2f);
    glEnd();

    // gagang pintu
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        // mobil satu pintu aja
        glVertex2f(0.0f, 0.05f); 
		glVertex2f(0.1f, 0.05f);
        glVertex2f(0.1f, 0.08f); 
		glVertex2f(0.0f, 0.08f);
    glEnd();

    // lampu sein 
    glColor3f(1.0f, 0.4f, 0.0f); 
    glBegin(GL_QUADS);
        // sein depan
        glVertex2f(0.53f, 0.05f);
        glVertex2f(0.58f, 0.05f);
        glVertex2f(0.58f, 0.12f);
        glVertex2f(0.53f, 0.12f);

        // sein belakang 
        glVertex2f(-0.58f, 0.05f);
        glVertex2f(-0.53f, 0.05f);
        glVertex2f(-0.53f, 0.12f);
        glVertex2f(-0.58f, 0.12f);
    glEnd();

    // bagian atas mobil
    glPushMatrix();
        glTranslatef(0.0f, 0.2f, 0.0f); 
        
        // atap
        glColor3f(0.4f, 0.5f, 0.8f); 
        glBegin(GL_POLYGON);
            glVertex2f(-0.4f, 0.0f);
            glVertex2f( 0.3f, 0.0f);
            glVertex2f( 0.2f, 0.25f);
            glVertex2f(-0.3f, 0.25f);
        glEnd();
        
        // jendela belakang
        glColor3f(0.98f, 0.98f, 0.98f); 
        glBegin(GL_POLYGON);
            glVertex2f(-0.35f, 0.03f); // ki. b
            glVertex2f(-0.08f, 0.03f); // ka. b
            glVertex2f(-0.08f, 0.22f); // ka. a
            glVertex2f(-0.28f, 0.22f); // ki. a
        glEnd();
        
        // jendela depan
        glBegin(GL_POLYGON);
            glVertex2f( -0.06f, 0.03f); // ki. b
            glVertex2f( 0.25f, 0.03f); // ka. b
            glVertex2f( 0.18f, 0.22f); // ka. a
            glVertex2f( -0.06f, 0.22f); // ki. a
        glEnd();
    glPopMatrix();

    // roda belakang
    glPushMatrix();
        glTranslatef(-0.35f, -0.2f, 0.0f); 
        // ban
        glColor3f(0.2f, 0.2f, 0.2f);      
        Circle(0, 0, 0.15f);
        // velg
        glColor3f(0.8f, 0.8f, 0.8f);      
        Circle(0, 0, 0.07f);
    glPopMatrix();

    // roda depan
    glPushMatrix();
        glTranslatef(0.35f, -0.2f, 0.0f);  
        // ban
        glColor3f(0.2f, 0.2f, 0.2f);
        Circle(0, 0, 0.15f);
        // velg
        glColor3f(0.8f, 0.8f, 0.8f);
        Circle(0, 0, 0.07f);
    glPopMatrix();
    
    // kaca spion
    glPushMatrix();
        glTranslatef(0.28f, 0.22f, 0.0f); 
        // Gagang spion
        glColor3f(0.2f, 0.3f, 0.6f);
        glBegin(GL_QUADS);
            glVertex2f(0.0f, 0.0f); 
			glVertex2f(0.04f, 0.0f);
            glVertex2f(0.04f, 0.02f); 
			glVertex2f(0.0f, 0.02f);
        glEnd();
        // Cermin spion
        glColor3f(0.5f, 0.5f, 0.5f);
        Circle(0.06f, 0.02f, 0.035f);
    glPopMatrix();

    glFlush();
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitWindowSize(640, 640);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutCreateWindow("Tugas 2 Mobil 2D - Nayla Husna - 24060124140158");
	glutDisplayFunc(mobil);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glutMainLoop();
	return 0;
}
