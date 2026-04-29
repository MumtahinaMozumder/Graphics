#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

// গ্লোবাল ভ্যারিয়েবল
int r, Xc, Yc;               // বৃত্তের জন্য
int rx1, ry1, rx2, ry2;      // আয়তক্ষেত্রের জন্য

// ১. তোমার দেওয়া Bresenham Line Algorithm (Generalized)
void bresenham_line(int x1, int y1, int x2, int y2) {
    int x = x1, y = y1;
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    glBegin(GL_POINTS);
    if (dx > dy) {
        int di = 2 * dy - dx;
        glVertex2i(x, y);
        for (int i = 0; i < dx; i++) {
            if (di < 0) {
                if (x1 < x2) x = x + 1; else x = x - 1;
                di = di + 2 * dy;
            } else {
                if (x1 < x2) x = x + 1; else x = x - 1;
                if (y1 < y2) y = y + 1; else y = y - 1;
                di = di + 2 * dy - 2 * dx;
            }
            glVertex2i(x, y);
        }
    } else {
        int di = 2 * dx - dy;
        glVertex2i(x, y);
        for (int i = 0; i < dy; i++) {
            if (di < 0) {
                if (y1 < y2) y = y + 1; else y = y - 1;
                di = di + 2 * dx;
            } else {
                if (y1 < y2) y = y + 1; else y = y - 1;
                if (x1 < x2) x = x + 1; else x = x - 1;
                di = di + 2 * dx - 2 * dy;
            }
            glVertex2i(x, y);
        }
    }
    glEnd();
}

// ২. আয়তক্ষেত্র আঁকার ফাংশন (৪টি বাহু)
void draw_rectangle(int x1, int y1, int x2, int y2) {
    bresenham_line(x1, y1, x2, y1); // নিচের বাহু
    bresenham_line(x2, y1, x2, y2); // ডানের বাহু
    bresenham_line(x2, y2, x1, y2); // উপরের বাহু
    bresenham_line(x1, y2, x1, y1); // বামের বাহু
}

// ৩. তোমার দেওয়া Midpoint Circle Algorithm
void draw_circle(int x_center, int y_center, int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    glBegin(GL_POINTS);
    while (x <= y) {
        glVertex2i(x_center + x, y_center + y);
        glVertex2i(x_center + y, y_center + x);
        glVertex2i(x_center - y, y_center + x);
        glVertex2i(x_center - x, y_center + y);
        glVertex2i(x_center - x, y_center - y);
        glVertex2i(x_center - y, y_center - x);
        glVertex2i(x_center + y, y_center - x);
        glVertex2i(x_center + x, y_center - y);

        if (p < 0) {
            x++;
            p = p + (2 * x) + 3;
        } else {
            x++;
            y--;
            p = p + 2 * (x - y) + 5;
        }
    }
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // সাদা রঙ

    // আয়তক্ষেত্র কল করা
    draw_rectangle(rx1, ry1, rx2, ry2);

    // বৃত্ত কল করা
    draw_circle(Xc, Yc, r);

    glFlush();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // ভিউয়িং এরিয়া বড় করা হয়েছে যাতে ইনপুট যাই হোক দেখা যায়
    gluOrtho2D(-500, 500, -500, 500); 
}

int main(int argc, char** argv) {
    // ইউজার ইনপুট
    printf("Rectangle Input:\n");
    printf("Enter bottom-left corner (x1 y1): ");
    scanf("%d %d", &rx1, &ry1);
    printf("Enter top-right corner (x2 y2): ");
    scanf("%d %d", &rx2, &ry2);

    printf("\nCircle Input:\n");
    printf("Enter Circle Center (Xc Yc): ");
    scanf("%d %d", &Xc, &Yc);
    printf("Enter Radius (r): ");
    scanf("%d", &r);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rectangle & Midpoint Circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}