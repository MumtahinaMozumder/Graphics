#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
void bresenham(int x1,int y1,int x2,int y2)
{ int x=x1;
int y=y1;
int dx=abs(x2-x1);
int dy=abs(y2-y1);
glBegin(GL_POINTS);
if(dx>dy)
{ int di=2*dy-dx;
glVertex2i(x,y);
for(int i=0;i<dx;i++)
{if(di<0)
{if(x1<x2)
    {x=x+1;
    }
    else {x=x-1;
    }
    di=di+2*dy;
}
else
 {if(x1<x2)
    {x=x+1;
    }
    else{x=x-1;
    }
    if(y1<y2)
    {y=y+1;
    }
    else{y=y-1;
    }
    di=di+2*dy-2*dx;
    
}
glVertex2i(x,y);

}}
else{
    int di=2*dx-dy;
    glVertex2i(x,y);
    for (int i=0;i<dy;i++){
if(di<0)
{if(y1<y2)
{y=y+1;
}
else{y=y-1;
}
di=di+2*dx;
}
else
{if(y1<y2)
{y=y+1;
}
else{y=y-1;
}
if(x1<x2)
{x=x+1;
}
else{x=x-1;   
}
di=di+2*dx-2*dy; }
glVertex2i(x,y);
}

}
glEnd();
}


void rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    bresenham(x1, y1, x2, y2);
    bresenham(x2, y2, x3, y3);
    bresenham(x3, y3, x4, y4);
    bresenham(x4, y4, x1, y1);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    rectangle(0, 0, 50, 0, 50, 50, 0, 50);

    glFlush();
}

void init(void) {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Rectangle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
