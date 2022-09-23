/*
    UNIVASF - UNIVERSIDADE FEDERAL DO VALE DO SÃO FRANCISCO
    COLEGIADO DE ENGENHARIA DE COMPUTAÇÃO
    DISCIPLINA: COMPUTAÇÃO GRÁFICA
    AUTOR: FILIPE ALVES RIBEIRO RODRIGUES
    DESENHO: PISTA DE OBSTÁCULOS
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>

// Declaração de variáveis globais
GLfloat tx = 0, ty = -24;
GLfloat ang1 = 0, ang2 = -90;
GLfloat win = 25;
GLfloat rrec = 1.0, grec = 0, brec = 0;
GLfloat rper = 0, gper = 0, bper = 1.0;
int lifes = 3;

void GerenciaMouse(int button, int state, int x, int y){        
    if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
			rrec = 1.0;
			grec = 1.0;
			brec = 0;
			rper = 0;
			gper = 0;
			bper = 0;
		}
	}

    glutPostRedisplay();
}
void DesenhaTexto(void *font, char *string) {
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*string++); 
}

void contadorVidas () {
	if(lifes == 3) {
		glPushMatrix();
		glColor3f(rper,gper,bper);
    	glRasterPos2f(-35,0); 
		DesenhaTexto(GLUT_BITMAP_9_BY_15, "VIDAS: 3");
	} else {
		if(lifes == 2) {
			glPushMatrix();
			glColor3f(rper,gper,bper);
    		glRasterPos2f(-35,0); 
			DesenhaTexto(GLUT_BITMAP_9_BY_15, "VIDAS: 2");
		} else {
			glPushMatrix();
			glColor3f(rper,gper,bper);
    		glRasterPos2f(-35,0); 
			DesenhaTexto(GLUT_BITMAP_9_BY_15, "VIDAS: 1");
		}
	}
}

void Colisao1() {
	if((tx > -1 && tx < 36) && (ty > -21 && ty < -10)) {
		tx = 0;
		ty = -25;
		lifes--;
		if(lifes == 0) {
			printf("[!] NUMERO DE VIDAS ESGOTADO, TENTE NOVAMENTE!\n\n");
			exit(0);
		}
		
	}
}

void Colisao2() {
	if((tx > -41 && tx < -4) && (ty > -21 && ty < -10)) {
		tx = 0;
		ty = -25;
		lifes--;
		if(lifes == 0) {
			printf("[!] NUMERO DE VIDAS ESGOTADO, TENTE NOVAMENTE!\n\n");
			exit(0);
		}
	}
}

void Colisao3() {
	if((tx > -21 && tx < 16) && (ty > -10 && ty < 1)) {
		tx = 0;
		ty = -25;
		lifes--;
		if(lifes == 0) {
			printf("[!] NUMERO DE VIDAS ESGOTADO, TENTE NOVAMENTE!\n\n");
			exit(0);
		}

	}
}

void Colisao4() {
	if((tx > -1 && tx < 36) && (ty > 1 && ty < 12)) {
		tx = 0;
		ty = -25;
		lifes--;
		if(lifes == 0) {
			printf("[!] NUMERO DE VIDAS ESGOTADO, TENTE NOVAMENTE!\n\n");
			exit(0);
		}
	}
}

void Colisao5() {
	if((tx > -43 && tx < -6) && (ty > 1 && ty < 12)) {
		tx = 0;
		ty = -25;
		lifes--;
		if(lifes == 0) {
			printf("[!] NUMERO DE VIDAS ESGOTADO, TENTE NOVAMENTE!\n\n");
			exit(0);
		}
	}
}

void Colisao6() {
	if((tx > -6 && tx < 31) && (ty > 12 && ty < 23)) {
		tx = 0;
		ty = -25;
		lifes--;
		if(lifes == 0) {
			printf("[!] NUMERO DE VIDAS ESGOTADO, TENTE NOVAMENTE!\n\n");
			exit(0);
		}
	}
}

void Colisao7() {
	if((tx > -41 && tx < -4) && (ty > 12 && ty < 23)) {
		tx = 0;
		ty = -25;
		lifes--;
		if(lifes == 0) {
			printf("[!] NUMERO DE VIDAS ESGOTADO, TENTE NOVAMENTE!\n\n");
			exit(0);
		}
	}
}

void Obstaculo() {
	glBegin(GL_POLYGON);
    	glColor3f(rrec, grec, brec);
		glVertex2f(0, 0);
		glVertex2f(0, 4);
		glVertex2f(30, 4);
		glVertex2f(30, 0);
	glEnd();
}

void DesenhaObj() {
	glBegin(GL_QUADS);
    	glColor3f(rper, gper, bper);
		glVertex2f(0, 0);
		glVertex2f(0, 5);
		glVertex2f(5, 5);
		glVertex2f(5, 0);
	glEnd();

}

           
void Desenha() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
     
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Obstáculo 1
	glPushMatrix();
	glTranslatef(5, -15, 0);
	Obstaculo();
	glPopMatrix();

	//Obstáculo 2
	glPushMatrix();
	glTranslatef(-35, -15, 0);
	Obstaculo();
	glPopMatrix();

	//Obstáculo 3
	glPushMatrix();
	glTranslatef(-15, -4, 0);
	Obstaculo();
	glPopMatrix();

	//Obstáculo 4
	glPushMatrix();
	glTranslatef(-37, 7, 0);
	Obstaculo();
	glPopMatrix();
	
	//Obstáculo 5
	glPushMatrix();
	glTranslatef(5, 7, 0);
	Obstaculo();
	glPopMatrix();

	//Obstáculo 6
	glPushMatrix();
	glColor3f(1, 0, 0);
    glutMouseFunc(GerenciaMouse);    
	glTranslatef(0, 18, 0);
	Obstaculo();
	glPopMatrix();
	
	//Obstáculo 7
	glPushMatrix();
	glTranslatef(-35, 18, 0);
	Obstaculo();
	glPopMatrix();
	
	// Personagem
	glTranslatef(tx, ty, 0);
	Colisao1();
	Colisao2();
	Colisao3();
	Colisao4();
	Colisao5();
	Colisao6();
	Colisao7();
	DesenhaObj();
	glPopMatrix();

	
	contadorVidas();

	glutSwapBuffers();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
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

void TeclasEspeciais(int key, int x, int y) {
	
	if(key == GLUT_KEY_LEFT) {
		tx-=1;
		if ( tx < -win ) {
			tx = win; 
		}
	}
	
	if(key == GLUT_KEY_RIGHT) {
		tx+=1;
		if ( tx+5 > win ) {
			tx = -win; 
		}
	}

	if(key == GLUT_KEY_UP) {
		ty+=1;
		if ( ty + 15 > win ) {
			printf(" \n\n[!] PARABÉNS, VOCÊ VENCEU !!\n\n");
			exit(0); 
		}
	}     


	if(key == GLUT_KEY_DOWN) {
		ty-=1;
		if ( ty - 12 < -win ) {
			ty = -24; 
		}
	}     
	glutPostRedisplay();

}

void Teclado (unsigned char key, int x, int y) {
	if (key == 27)
		exit(0);
}
           
void Inicializa () {   
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
	printf(" \n[!] As setas do teclado movimentam o objeto\n");

}

int main(int argc, char **argv) {
    glutInit(&argc, argv); // OBS PARA CORREÇÃO: Minha máquina necessita desse comando, caso não funcione é só retirar essa linha e os argumentos da main.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
	glutInitWindowPosition(5,5);     
	glutInitWindowSize(450,300);  
	glutCreateWindow("Pista de Obstaculos"); 
 
	glutDisplayFunc(Desenha);  
	
	glutReshapeFunc(AlteraTamanhoJanela);    

	glutSpecialFunc(TeclasEspeciais);

	glutKeyboardFunc (Teclado);

	Inicializa(); 

 
	glutMainLoop();

	return 0;
}