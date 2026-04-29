#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void draw_line(int x1, int y1, int x2, int y2) {
    int x = x1;
    int y = y1;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    glBegin(GL_POINTS);
    // first will check the line is more horizontal or vertical 
    //shallow or steep line

    if (dx > dy) {
        int di = 2 * dy - dx; //initial decision parameter
        glVertex2i(x, y); //plot the first point
        for (int i = 0; i < dx; i++) {
            //decision parameter negative means we are not depart from the main line so we will only change the x coordinate and keep the y coordinate same
            if (di < 0)  {
                //if x2 is greater than x1 then we will move right so we will increase x by 1 
                if (x1 < x2)
                  {
                      x = x + 1;
                }
                //if x1 is greater or equal than x2 then we will move left so we will decrease x by 1
                else
                  {
                     x = x - 1;
                }
                di = di + 2 * dy; //update the decision parameter for the next point
            }
            //if the decision parameter is positive or zero then we are depart from the main line so we will change both x and y coordinate
            else {
                if (x1 < x2)
                  { x = x + 1;
                }
                else
                  { x = x - 1;
                }
                if (y1 < y2)
                  {
                      y = y + 1;
                } else
                {
                    y = y - 1;
                     }
                di = di + 2 * dy - 2 * dx;//update the decision parameter for the next point when we depart from the main line means di is positive or zero
            }
            glVertex2i(x, y);
        }
    }
    //if the line is steep line 
    else {
        int di = 2 * dx - dy;//initial decision parameter
        glVertex2i(x, y);
        for (int i = 0; i < dy; i++) {
            if (di < 0) {
                if (y1 < y2) 
                { y = y + 1; } 
                else 
                { y = y - 1; }
                di = di + 2 * dx;
            }
            else
             {
                if (y1 < y2)
                 { y = y + 1; }
                  else
                   { y = y - 1; }
                if (x1 < x2) 
                { x = x + 1; 
                } 
                else 
                { x = x - 1;
                 }

                di = di + 2 * dx - 2 * dy;
            }
            glVertex2i(x, y);
        }
    }
    glEnd();
}


void rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    draw_line(x1, y1, x2, y2);
    draw_line(x2, y2, x3, y3);
    draw_line(x3, y3, x4, y4);
    draw_line(x4, y4, x1, y1);
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
