//Gambar yang memanfaatkan fungsi baru, digabung biar jadi objek, disini saya menggunakan gambar Robot
#include <GL/glut.h>
void Robot(void) {
    glClear(GL_COLOR_BUFFER_BIT); 
    glLineWidth(2.5f);

    // 1. MAHKOTA menggunakan GL_TRIANGLE_FAN 
    
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.9f, 0.0f); 
        glVertex2f(0.0f, 0.5f);     
        glVertex2f(-0.35f, 0.5f);  
        glVertex2f(-0.3f, 0.65f);   
        glVertex2f(-0.15f, 0.55f);  
        glVertex2f(0.0f, 0.7f);     
        glVertex2f(0.15f, 0.55f);   
        glVertex2f(0.3f, 0.65f);    
        glVertex2f(0.35f, 0.5f);    
        
    glEnd();

    // Outlinenya
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 0.0f); 
        glVertex2f(-0.35f, 0.5f);   
        glVertex2f(-0.3f, 0.65f);   
        glVertex2f(-0.14f, 0.57f);  
        glVertex2f(0.0f, 0.7f);      
        glVertex2f(0.14f, 0.57f);  
        glVertex2f(0.3f, 0.65f);   
        glVertex2f(0.35f, 0.5f);    
    glEnd();

    // 2. KEPALA (MUKA) -> GL_QUAD_STRIP + Outline

    glBegin(GL_QUAD_STRIP);
        glColor3f(1.0f, 0.9f, 0.8f); 
        glVertex2f(-0.3f, 0.15f); 
        glVertex2f( 0.3f, 0.15f); 
        glVertex2f(-0.3f, 0.5f);  
        glVertex2f( 0.3f, 0.5f);  
    glEnd();
    
    // Outlinenya 
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.3f, 0.15f);
        glVertex2f( 0.3f, 0.15f);
        glVertex2f( 0.3f, 0.5f);
        glVertex2f(-0.3f, 0.5f);
    glEnd();

    // 3. MATA(GL_QUADS) & MULUT(GL_LINE_LOOP) 
    
    glColor3f(0.0f, 0.0f, 0.0f); 
    glBegin(GL_QUADS); // Mata Kiri
        glVertex2f(-0.2f, 0.35f); glVertex2f(-0.1f, 0.35f);
        glVertex2f(-0.1f, 0.43f); glVertex2f(-0.2f, 0.43f);
    glEnd();
    glBegin(GL_QUADS); // Mata Kanan 
        glVertex2f(0.1f, 0.35f);  glVertex2f(0.2f, 0.35f);
        glVertex2f(0.2f, 0.43f);  glVertex2f(0.1f, 0.43f);
    glEnd();

    glBegin(GL_LINE_LOOP);     // Mulut 
        glVertex2f(-0.1f, 0.22f); glVertex2f( 0.1f, 0.22f);
        glVertex2f( 0.1f, 0.26f); glVertex2f(-0.1f, 0.26f);
    glEnd();

    // 4. LEHER menggunakan GL_QUADS dan Outline
    
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.8f, 0.6f); //lehernya belang dulu yaa 
        glVertex2f(-0.05f, 0.05f); 
        glVertex2f( 0.05f, 0.05f); 
        glVertex2f( 0.05f, 0.15f); 
        glVertex2f(-0.05f, 0.15f); 
    glEnd();
    
    // Outlinenya 
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f); 
        glVertex2f(-0.05f, 0.05f);
        glVertex2f( 0.05f, 0.05f);
        glVertex2f( 0.05f, 0.15f);
        glVertex2f(-0.05f, 0.15f);
    glEnd();

    // 5. BADAN  menggunakan GL_QUADS + Outline
    glBegin(GL_QUADS);
        glColor3f(0.8f, 0.2f, 0.2f); 
        glVertex2f(-0.4f, -0.6f); 
        glVertex2f( 0.4f, -0.6f); 
        glVertex2f( 0.4f,  0.05f); 
        glVertex2f(-0.4f,  0.05f); 
    glEnd();
    
    // Outlinenya
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.4f, -0.6f);
        glVertex2f( 0.4f, -0.6f);
        glVertex2f( 0.4f,  0.05f);
        glVertex2f(-0.4f,  0.05f);
    glEnd();

    // 6. LENGAN menggunakan GL_LINE_STRIP 

    glColor3f(0.0f, 0.0f, 0.0f); 
    glBegin(GL_LINE_STRIP); // Lengan Kiri
        glVertex2f(-0.4f, -0.1f); glVertex2f(-0.55f,-0.1f);
        glVertex2f(-0.55f,-0.3f); glVertex2f(-0.4f, -0.3f);
    glEnd();
    glBegin(GL_LINE_STRIP); // Lengan Kanan 
        glVertex2f( 0.4f, -0.1f); glVertex2f( 0.55f,-0.1f);
        glVertex2f( 0.55f,-0.3f); glVertex2f( 0.4f, -0.3f);
    glEnd();
    
    // 7. Hiasan biar lengkap fungsinya GL_TRIANGLE_STRIP
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.5f, 0.0f, 0.5f); 
        glVertex2f(-0.4f, -0.6f);  
        glVertex2f(-0.3f, -0.67f); 
        glVertex2f(-0.2f, -0.6f);  
        glVertex2f(-0.1f, -0.67f); 
        glVertex2f( 0.0f, -0.6f);  
        glVertex2f( 0.1f, -0.67f); 
        glVertex2f( 0.2f, -0.6f);  
        glVertex2f( 0.3f, -0.67f); 
        glVertex2f( 0.4f, -0.6f);  
    glEnd();

    glFlush(); 
}
int main (int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);  
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Tugas GTI - Nayla Husna"); 
	glutDisplayFunc(Robot); 
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
	glutMainLoop();
	return 0;
}
