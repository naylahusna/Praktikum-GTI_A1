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

//#include <GL/glut.h> 
//void Jendela(void)
//{
//	//membersihkan layar dan men-set dalam format warna
//	glClear(GL_COLOR_BUFFER_BIT);
//	
//	//memastikan seluruh perintah tereksekusi
//	glFlush();
//} 
//
//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//	glutInitWindowSize(640,480);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//	glutCreateWindow("biru");
//	glutDisplayFunc(Jendela);
//	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
//	glutMainLoop();
//	
//	return 0;
//}



//Titik
//#include <GL/glut.h>
//void point(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glPointSize(5.0f);  //mengatur besar titik
//	glBegin(GL_POINTS);
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glVertex3f(0.25, 0.25, 0.0);
//	glEnd();
//	glFlush();
//}
//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//	glutInitWindowSize(640,480);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//	glutCreateWindow("titik");
//	glutDisplayFunc(point);
//	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
//	glutMainLoop();
//	
//	return 0;
//}







//Garis
//#include <GL/glut.h>
//void garis(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glLineWidth(2.0f);  
//	glBegin(GL_LINES);
//	glColor3f(1.0f, 1.0f, 1.0f);  //merah, hijau, biru
//	glVertex3f(0.00, 0.20, 0.0);
//	glVertex3f(0.00, -0.20, 0.0);
//	glEnd();
//	glFlush();
//}
//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//	glutInitWindowSize(640,480);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//	glutCreateWindow("Membuat Garis");
//	glutDisplayFunc(garis);
//	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); //klo putih 1.0 semua, kalo hitam 0.0 semua
//	glutMainLoop();
//	
//	return 0;
//}






//Membuat Segitiga
//#include <GL/glut.h>
//void Segitiga(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glBegin(GL_TRIANGLES);
//	glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-0.10, -0.10, 0.00);
//	glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.10, -0.10, 0.00);
//	glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(0.00, 0.10, 0.00);
//	glEnd();
//	glFlush();
//}
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitWindowSize(640, 480);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//	glutCreateWindow("Membuat Segitiga");
//	glutDisplayFunc(Segitiga);
//	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
//	glutMainLoop();
//	return 0;
//}



//Menggambar Segiempat Penuh
#include <GL/glut.h>
void SegiEmpat(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(-0.18, 0.18, 0.18, -0.18);
	glFlush();
}
int main (int argc, char* argv[])
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

