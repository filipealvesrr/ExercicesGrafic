/*
    UNIVASF - UNIVERSIDADE FEDERAL DO VALE DO SÃO FRANCISCO
    COLEGIADO DE ENGENHARIA DE COMPUTAÇÃO
    DISCIPLINA: COMPUTAÇÃO GRÁFICA
    AUTOR: FILIPE ALVES RIBEIRO RODRIGUES
    DESENHO: LUMINÁRIA COM PONTOS ARTICULADOS
*/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

GLfloat ang1 = -30, ang2 = -60, ang3 = 90;
GLfloat win = 25;


void base() {
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(-15, -15);
    glVertex2f(-5, -15);
    glVertex2f(-5, -16);
    glVertex2f(-15, -16);
    glEnd();
}

void suporte() {
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(-9, -15);
    glVertex2f(-9, -12);
    glVertex2f(-11, -12);
    glVertex2f(-11, -15);
    glEnd();
}

void braco() {
    glLineWidth(2);
	glBegin(GL_LINE_LOOP);
    glVertex2f(0,0);
    glVertex2f(0,15);
    glVertex2f(2,15);
    glVertex2f(2,0);
	glEnd();
	
	glPointSize(4);
	glBegin(GL_POINTS);
		glVertex2i(1,1);              
	glEnd();
    
}

void triangulo() {
	glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2f(0, 0);
    glVertex2f(4, 4);
    glVertex2f(8, 0);
    glEnd();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	GLsizei largura, altura;
                   
	if(h == 0) h = 1;

	largura = w;
	altura = h;
                                              
	glViewport(0, 0, largura, altura);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	if (largura <= altura) 
	{ 
		gluOrtho2D (-25.0f, 25.0f, -25.0f*altura/largura, 25.0f*altura/largura);
		win = 25.0f;
	}              
	else 
	{ 
		gluOrtho2D (-25.0f*largura/altura, 25.0f*largura/altura, -25.0f, 25.0f);
		win = 25.0f*largura/altura;           
	}             
}


void iniciar(void) {
	
	
	printf("[!] Setas para esquerda e para direita movimentam o soquete\n");
    printf("[!] Home e End rotacionam o braco 1\n");
    printf("[!] PageUP e PageDn rotacionam o braco 2\n\n\n");
}
void teclasEspeciais(int key, int x, int y) {
    
    if(key == GLUT_KEY_LEFT) {
        if(ang3 > 95) {
            ang3 = 95;
        }
        ang3 += 1;
    }
	
    if(key == GLUT_KEY_RIGHT) {
        if(ang3 < 85) {
            ang3 = 85;
        }
        ang3 -= 1;
    }


    
    if (key == GLUT_KEY_HOME) {
	    if(ang1 < -15) {
            ang1 = -15;
        }
        ang1 -= 1;
	}
	
    if (key == GLUT_KEY_END) {
	    if(ang1 > -35) {
            ang1 = -35;
        }
        ang1 += 1;
	}

    if(key == GLUT_KEY_PAGE_UP) {
		if(ang2 < -50) {
            ang2 = -50;
        }
        ang2 -= 1;
    }
	if(key == GLUT_KEY_PAGE_DOWN) {
        if(ang2 > -70) {
            ang2 = -70;
        }
		ang2 += 1;              
    }
    
    

    glutPostRedisplay();

}


void desenha() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    base();
    suporte();
    
    glPushMatrix();
    
    glTranslatef(-11, -13, 0);
    glRotatef(ang1, 0, 0, 1);
    glColor3f(0, 0, 0);
    braco();

    glTranslatef(0, 14, 0);
    glRotatef(ang2, 0, 0, 1);
    braco();
    
    glTranslatef(5, 10, 0);
    glRotatef(ang3, 0, 0, 1);
    triangulo();

	glPopMatrix();
    
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Luminaria com Pontos Articulados");
    iniciar();
    glutInitWindowPosition(5,5);
    glutInitWindowSize(800, 800);
    glutSpecialFunc(teclasEspeciais);
    glutDisplayFunc(desenha);
	glutReshapeFunc(AlteraTamanhoJanela);    
    glutMainLoop();
	return 0;
}
