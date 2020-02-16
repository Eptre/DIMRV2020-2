#include <GL/glut.h>
#include <stdio.h>

GLfloat anguloCuboX = 0.0f;
GLfloat anguloCuboY = 0.0f;
GLfloat variable_color_rojo = 1.0f;
GLfloat variable_color_azul = 1.0f;
GLfloat variable_color_verde = 1.0f;
GLfloat camaraZ = 0.0f;
int ancho, alto;

void reshape(int width, int height){
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(height == 0){
        height = 1;
    }

    glMatrixMode(GL_PROJECTION);
    glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawCube(void){
    glColor3f(variable_color_rojo,variable_color_verde,variable_color_azul);
    glBegin(GL_QUADS);
    glVertex3f(-1.0f,-1.0f,1.0f);
    glVertex3f(1.0f,-1.0f,1.0f);
    glVertex3f(1.0f,1.0f,1.0f);
    glVertex3f(-1.0f,1.0f,1.0f);
    glEnd();

    glColor3f(variable_color_rojo,variable_color_verde,variable_color_azul);
    glBegin(GL_QUADS);
    glVertex3f(1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,1.0f,-1.0f);
    glVertex3f(1.0f,-1.0f,-1.0f);
    glEnd();

    glColor3f(variable_color_rojo,variable_color_verde,variable_color_azul);
    glBegin(GL_QUADS);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,1.0f);
    glVertex3f(-1.0f,1.0f,1.0f);
    glVertex3f(-1.0f,1.0f,-1.0f);
    glEnd();

    glColor3f(variable_color_rojo,variable_color_verde,variable_color_azul);
    glBegin(GL_QUADS);
    glVertex3f(1.0f,-1.0f,1.0f);
    glVertex3f(1.0f,-1.0f,-1.0f);
    glVertex3f(1.0f,1.0f,-1.0f);
    glVertex3f(1.0f,1.0f,1.0f);
    glEnd();

    glColor3f(variable_color_rojo,variable_color_verde,variable_color_azul);
    glBegin(GL_QUADS);
    glVertex3f(-1.0f,1.0f,1.0f);
    glVertex3f(1.0f,1.0f,1.0f);
    glVertex3f(1.0f,1.0f,-1.0f);
    glVertex3f(-1.0f,1.0f,-1.0f);
    glEnd();

    glColor3f(variable_color_rojo,variable_color_verde,variable_color_azul);
    glBegin(GL_QUADS);
    glVertex3f(1.0f,-1.0f,-1.0f);
    glVertex3f(1.0f,-1.0f,1.0f);
    glVertex3f(-1.0f,-1.0f,1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-5.0f+camaraZ);
    glRotatef(anguloCuboX,1.0f,0.0f,0.0f);
    glRotatef(anguloCuboY,0.0f,1.0f,0.0f);
    drawCube();

    glFlush();
    glutSwapBuffers();

    anguloCuboX += 0.1f;
    anguloCuboY += 0.1f;
}

void init(){
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    ancho = 600;
    alto = 600;
}

void idle(){
    display();
}


void tecla_especial(int key, int x, int y){
    _Bool tecla_ctrl = 0;
    int mod_key = glutGetModifiers();
    switch(key){
        case GLUT_KEY_F1:
            variable_color_rojo = 1.0f;
            variable_color_azul = 0.0f;
            variable_color_verde = 0.0f;
            break;

        case GLUT_KEY_F2:
            variable_color_rojo = 0.0f;
            variable_color_azul = 0.0f;
            variable_color_verde = 1.0f;
            break;

        case GLUT_KEY_F3:
            variable_color_rojo = 0.0f;
            variable_color_azul = 1.0f;
            variable_color_verde = 0.0f;
            break;

        case 27:
            exit(0);
            break;
    }
}



void keyboard(unsigned char key, int x, int y){

int mod = glutGetModifiers();

    if (mod != 0){
          switch(mod){
             case 2 :
                camaraZ += 0.5;
                 mod = 0;
                 break;
             }

    }


    switch(key){
        case 'p':
        case 'P':
            anguloCuboX -= 3.0f;
            break;

        case 'o':
        case 'O':
            anguloCuboY -= 3.0f;
            break;

        case 'r':
        case 'R':
            variable_color_rojo = 1.0f;
            variable_color_azul = 0.0f;
            variable_color_verde = 0.0f;
            break;

        case 'g':
        case 'G':
            variable_color_verde = 1.0f;
            variable_color_rojo = 0.0f;
            variable_color_azul = 0.0f;
            break;

        case 'b':
        case 'B':
            variable_color_azul = 1.0f;
            variable_color_rojo = 0.0f;
            variable_color_verde = 0.0f;
            break;

        case 'l':
        case 'L':
            camaraZ -= 0.5;
            break;

        case 27:
            exit(0);
            break;
    }
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(ancho,alto);
    glutCreateWindow("Programa 1");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(tecla_especial);
    glutMainLoop();
    return 0;
}
