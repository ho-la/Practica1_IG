/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   practica1.cpp
 * Author: chen
 *
 * Created on 10 de octubre de 2016, 11:02
 */
//-lopengl32 -lglu32 -lglew32 -lfreeglut
//https://github.com/ho-la/prueba.git
//https://github.com/aherrang/ig1617.git
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

void initFunc();
void funReshape(int w, int h);
void funDisplay();
void drawTriangulo(char color);
void funKeyboard(int key, int x, int y);
void destroyFunc();

void drawOurNumber();
void glDrawSphere(char color,float radio);
void tarea1();
void tarea2();
void tarea3();
void drawPieza();
// Variables globales
int w = 500;
int h = 500;
GLfloat desZ = -5.0f;
GLfloat rotY =  0.0f;

GLfloat radioT = 0.5f;

int main(int argc, char** argv) {
    
 // Inicializamos GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(w,h);
    glutInitWindowPosition(50,50);
    glutCreateWindow("QiaoLang Chen y Alexey Sorokin");
    
 // Inicializamos GLEW
    GLenum err = glewInit();
    if(GLEW_OK != err) printf("Error: %s\n", glewGetErrorString(err));
    printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    const GLubyte *oglVersion = glGetString(GL_VERSION);
    printf("This system supports OpenGL Version: %s\n", oglVersion);
    
 // Inicializaciones específicas
    initFunc();
    
 // Configuración CallBacks
    glutReshapeFunc(funReshape);
    glutDisplayFunc(funDisplay);
    glutSpecialFunc(funKeyboard);
      
 // Bucle principal
    glutMainLoop();
    
 // Destrucción de objetos
    destroyFunc();
    
    return(0);
}


void initFunc() {
    
 // Configuracion de etapas del cauce
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_FLAT);
    
}

void destroyFunc() {
    
}

void funReshape(int wnew, int hnew) {
    
 // Configuración del Viewport
    glViewport(0, 0, wnew, hnew);

 // Captura de w y h
    
    w = wnew;
    h = hnew;
}

void funDisplay() {
    
 // Borramos el buffer de color
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
 // Para configurar la matriz matriz P
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  
    // Proyeccion Ortogonal: 
    //GLfloat left=-2.0, right=2.0, bottom=-2.0, top=2.0, nplane=3.0, fplane=10.0;
    //glOrtho(left, right, bottom, top, nplane, fplane);
  
    //Proyeccion en Frustum
    //GLfloat left=-2.0, right=2.0, bottom=-2.0, top=2.0, nplane=3.0, fplane=10.0;
    //glFrustum(left, right, bottom, top, nplane, fplane);
  

    //En perspectiva
    /**/
    GLfloat aspectRatio = (GLfloat)w/(GLfloat)h;    
    GLfloat fovy = 50.0f, nplane = 0.1f, fplane = 20.0f;
    gluPerspective(fovy,aspectRatio,nplane,fplane);
    /**/ 
 // Para configurar las matrices M y V
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();
    
 // Matriz de Vista V (Cámara)
    // Aquí cargaremos la matriz V
    
 // Dibujamos los objetos (M)
    glTranslatef(0.0f, 0.0f, desZ);
    
    tarea1();
 // Intercambiamos los buffers
    glutSwapBuffers();
}

void drawTriangulo(char color) {  
    switch(color) {
        case 'r':
            glColor3f(1.0f, 0.0f, 0.0f);
            break;
        case 'g':
            glColor3f(0.0f, 1.0f, 0.0f);
            break;
        case 'b':
            glColor3f(0.0f, 0.0f, 1.0f);
            break;
        default:
            glColor3f(1.0f, 1.0f, 1.0f);            
    }
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.5f, -0.5f, 0.0f); // v1
        glVertex3f( 0.5f, -0.5f, 0.0f); // v2
        glVertex3f( 0.0f,  0.5f, 0.0f); // v3
    glEnd();
    
}

void funKeyboard(int key, int x, int y) {

    switch(key) {
        case GLUT_KEY_UP:
            desZ -= 0.1f;
            break;
        case GLUT_KEY_DOWN:
            desZ += 0.1f;
            break;
        case GLUT_KEY_RIGHT:
            rotY -= 5.0f;
            break;
        case GLUT_KEY_LEFT:
            rotY += 5.0f;
            break;
        default:
            desZ = -5.0f;  
            rotY =  0.0f;
    }
    
    glutPostRedisplay();
    
}
/****************************************************************************************************/
//Our number is 9
void drawOurNumber() { 
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.0f, 3.0f, 0.0f); // v1
        glVertex3f( 3.0f, 3.0f, 0.0f); // v2
        glVertex3f(3.0f, -2.0f, 0.0f); // v12
        glVertex3f(0.0f, -2.0f, 0.0f); // v11
        glVertex3f(0.0f, -1.0f, 0.0f); // v9
        glVertex3f(2.0f, -1.0f, 0.0f); // v10
        glVertex3f(2.0f, 0.0f, 0.0f); // v8
        glVertex3f(0.0f, 0.0f, 0.0f); // v7   
    glEnd();
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f( 1.0f,  2.0f, 0.0f); // v3
        glVertex3f(2.0f, 2.0f, 0.0f); // v4
        glVertex3f(2.0f, 1.0f, 0.0f); // v6
        glVertex3f(1.0f, 1.0f, 0.0f); // v5
    glEnd();
}
void glDrawSphere(char color,float radio){
    switch(color) {
        case 'w':
            glColor3f(1.0f, 1.0f, 1.0f);
            break;
        case 'y':
            glColor3f(1.0f, 1.0f, 0.0f);
            break;
        case 'r':
            glColor3f(1.0f, 0.0f, 0.0f);
            break;
        case 'g':
            glColor3f(0.0f, 1.0f, 0.0f);
            break;
        case 'b':
            glColor3f(0.0f, 0.0f, 1.0f);
            break;
        default:
            glColor3f(1.0f, 1.0f, 1.0f);            
    }
    glutWireSphere(radio,20,20); 
    //(GLdouble radius,GLint slices, GLint stacks);
  
}
void tarea1(){
    //Dibuja nuestro número
    glPushMatrix(); 
        glLineWidth(5.0);
        glScalef(0.3f, 0.3f, 0.3f);
        glTranslatef( -1.5f, -0.5f, 0.0f);
        drawOurNumber();
    glPopMatrix();
    //Dibuja esfera amarilla
    glPushMatrix();
        glLineWidth(1.0);
        glRotatef(rotY,0.0f,1.0f,0.0f);
        glDrawSphere('y',2.0f);
    glPopMatrix();    
}
void tarea2(){
    //Dbujamos el sol y el número
    tarea1();
    //Dibujamos la Tierra
    glPushMatrix(); 
        glLineWidth(1.0);
        glTranslatef( 5.0f, 0.0f, 0.0f);
        glDrawSphere('b',0.5f);
    glPopMatrix();
    //Dibujamos la luna
    glPushMatrix(); 
        glLineWidth(1.0);
        glTranslatef(6.5f, 0.0f, 0.0f);
        glDrawSphere('w',0.1f);
    glPopMatrix();

}
void tarea3(){
    
}
void drawPieza(){
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
        glVertex3f( 0.0f,  3.0f, 0.0f);
        glVertex3f( 1.0f,  3.0f, 0.0f);
        glVertex3f( 0.0f,  0.0f, 0.0f);
        glVertex3f( 1.0f,  0.0f, 0.0f);
    glEnd();
}