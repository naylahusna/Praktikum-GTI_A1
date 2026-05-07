// Nama : Nayla Husna
// NIM : 24060124140158
// Kelas : A/ A1


//Proyeksi
#include <GL/glut.h>

void Display(void) {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
   
   glBegin(GL_POLYGON);
       glColor3f(0.0, 0.0, 0.0);
       glVertex3f(-0.5, -0.5, -3.0);
       
       glColor3f(1.0, 0.0, 0.0);
       glVertex3f(0.5, -0.5, -3.0);
       
       glColor3f(0.0, 0.0, 1.0);
       glVertex3f(0.5, 0.5, -3.0);
   glEnd();

   glFlush(); // Selesai rendering
}

void Reshape(int x, int y) {
   if (y == 0 || x == 0) return; // Jika tak ada lagi yang muncul, maka berhenti
   
   // Mengatur proyeksi matrix baru
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity(); 
   
   // Sudut: 40 derajat
   // Jarak potongan dataran terdekat: 0.5 
   // Jarak potongan dataran terjauh: 20.0
   gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
   
   glMatrixMode(GL_MODELVIEW);
   glViewport(0, 0, x, y); // Gunakan seluruh window untuk rendering
}

int main(int argc, char **argv) {
   // Inisialisasi GLUT
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(300, 300);
   glutCreateWindow("Intro");
   
   glClearColor(0.0, 0.0, 0.0, 0.0);
   
   glutDisplayFunc(Display);
   glutReshapeFunc(Reshape); // Mengatur kembali bentuk objek
   
   glutMainLoop();
   return 0;
}


#include <GL/glut.h>

GLfloat xRotated, yRotated, zRotated;

void Display(void) {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
   
   // Transformasi objek
   glTranslatef(0.0, 0.0, -4.0);
   glRotatef(xRotated, 1.0, 0.0, 0.0);
   glRotatef(yRotated, 0.0, 1.0, 0.0);
   glRotatef(zRotated, 0.0, 0.0, 1.0);
   glScalef(2.0, 1.0, 1.0); // Membuat kubus jadi agak lebar (balok)
   
   glutWireCube(1.0); 
   glFlush();
   glutSwapBuffers();
}

void Reshape(int x, int y) {
   if (y == 0 || x == 0) return;
   
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   
   gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
   
   glMatrixMode(GL_MODELVIEW);
   glViewport(0, 0, x, y);
}

void Idle(void) {
   // Kecepatan rotasi pada masing-masing sumbu
   xRotated += 0.03; //makin kecil makin pelan rotasinya, awalnya ini 0.3
   yRotated += 0.01;
   zRotated += -0.04;
   
   Display();
}

int main(int argc, char **argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(300, 300);
   glutCreateWindow("Cube example");
   
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   xRotated = yRotated = zRotated = 0.0;
   
   glClearColor(0.0, 0.0, 0.0, 0.0);
   
   glutDisplayFunc(Display);
   glutReshapeFunc(Reshape);
   glutIdleFunc(Idle); // Fungsi untuk animasi berkelanjutan
   
   glutMainLoop();
   return 0;
}




// Lengan Bergerak
#include <GL/glut.h>

//variabel sudut
static int shoulder = 0, elbow = 0;

//inisiaslisi
void init(void) {
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}

void display(void) {
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
       // Menggerakkan sendi bahu
       glTranslatef(-1.0, 0.0, 0.0);
       glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
       glTranslatef(1.0, 0.0, 0.0);
       
       glPushMatrix();
           glScalef(2.0, 0.4, 1.0);
           glutWireCube(1.0); // Gambar lengan atas
       glPopMatrix();

       // Menggerakkan sendi siku
       glTranslatef(1.0, 0.0, 0.0);
       glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
       glTranslatef(1.0, 0.0, 0.0);
       
       glPushMatrix();
           glScalef(2.0, 0.4, 1.0);
           glutWireCube(1.0); // Gambar lengan bawah
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
       case 's': // Bahu ke atas
           shoulder = (shoulder + 5) % 360;
           glutPostRedisplay();
           break;
       case 'S': // Bahu ke bawah
           shoulder = (shoulder - 5) % 360;
           glutPostRedisplay();
           break;
       case 'e': // Siku ke atas
           elbow = (elbow + 5) % 360;
           glutPostRedisplay();
           break;
       case 'E': // Siku ke bawah
           elbow = (elbow - 5) % 360;
           glutPostRedisplay();
           break;
       case 27: // Tombol ESC untuk keluar
           exit(0);
           break;
       default:
           break;
   }
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(700, 600);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Lengan Bergerak");
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
