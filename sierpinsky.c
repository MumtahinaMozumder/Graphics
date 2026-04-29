#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
float init_x1, init_y1, init_x2, init_y2, init_x3, init_y3;
int order;

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}
void SG(float x1, float y1, float x2, float y2, float x3, float y3, int n) {
    float x12, y12, x13, y13, x23, y23;
    
    if (n > 0) {
        
        x12 = (x1 + x2) / 2.0;
        y12 = (y1 + y2) / 2.0; 
        x13 = (x1 + x3) / 2.0;
        y13 = (y1 + y3) / 2.0; 
        x23 = (x2 + x3) / 2.0;
        y23 = (y2 + y3) / 2.0;
        
        SG(x1, y1, x12, y12, x13, y13, n - 1);
        SG(x12, y12, x2, y2, x23, y23, n - 1);
        SG(x13, y13, x23, y23, x3, y3, n - 1);
    } else {
    
        drawTriangle(x1, y1, x2, y2, x3, y3);
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 1.0, 1.0);
    
    SG(init_x1, init_y1, init_x2, init_y2, init_x3, init_y3, order);
    
    glFlush();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100); 
}

int main(int argc, char** argv) {
    
    printf("Enter the vertices of the triangle (x1 y1 x2 y2 x3 y3):\n");
   
    scanf("%f %f %f %f %f %f", &init_x1, &init_y1, &init_x2, &init_y2, &init_x3, &init_y3);
    
    printf("Enter the order n:\n");
    scanf("%d", &order);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sierpinski Gasket");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}