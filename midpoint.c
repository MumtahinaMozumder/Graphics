#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
int r,Xc,Yc;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
 int x=0;
 int y=r;
 int p=1-r;


    glBegin(GL_POINTS);
    while(x<=y){
    glVertex2f(Xc+x,Yc+y);
    glVertex2f(Xc+y,Yc+x);
    glVertex2f(Xc-y,Yc+x);
    glVertex2f(Xc-x,Yc+y);
    glVertex2f(Xc-x,Yc-y);
    glVertex2f(Xc-y,Yc-x);
    glVertex2f(Xc+y,Yc-x);
    glVertex2f(Xc+x,Yc-y);
    if(p<0){
      x++;
      p=p+(2*x)+3;
    }
    else{
    x++;
    y--;
    p=p+2*(x-y)+5;
    }
    }
    glEnd();
    glFlush();
}

void init(void)
{

    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv)
{
printf("Enter the value of the points : ");
   scanf("%d %d %d", &r,&Xc,&Yc);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("mIDPOINT CIRCLE ALGORITHM");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

return 0;
}