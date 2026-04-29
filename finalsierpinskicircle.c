#include <windows.h>
#include <GL/glut.h>
#include <math.h> // math.h যোগ করতে হবে sin/cos এর জন্য
#include <stdio.h>

int r, Xc, Yc, order;

// ১. মিডপয়েন্ট সার্কেল ফাংশন
void drawCircle(int r, int Xc, int Yc) {
    int x = 0, y = r;
    int p = 1 - r;
    glBegin(GL_POINTS);
    while (x <= y) {
        glVertex2f(Xc + x, Yc + y); glVertex2f(Xc + y, Yc + x);
        glVertex2f(Xc - y, Yc + x); glVertex2f(Xc - x, Yc + y);
        glVertex2f(Xc - x, Yc - y); glVertex2f(Xc - y, Yc - x);
        glVertex2f(Xc + y, Yc - x); glVertex2f(Xc + x, Yc - y);
        if (p < 0) p += 2 * (++x) + 3;
        else p += 2 * ((++x) - (--y)) + 5;
    }
    glEnd();
}

// ২. সিয়েরপিনস্কি ফাংশন (আগের মতোই)
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_LINE_LOOP); // ভরাট না করে শুধু বর্ডার দিতে চাইলে LINE_LOOP
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void SG(float x1, float y1, float x2, float y2, float x3, float y3, int n) {
    if (n > 0) {
        float x12 = (x1 + x2) / 2.0, y12 = (y1 + y2) / 2.0;
        float x13 = (x1 + x3) / 2.0, y13 = (y1 + y3) / 2.0;
        float x23 = (x2 + x3) / 2.0, y23 = (y2 + y3) / 2.0;
        SG(x1, y1, x12, y12, x13, y13, n - 1);
        SG(x12, y12, x2, y2, x23, y23, n - 1);
        SG(x13, y13, x23, y23, x3, y3, n - 1);
    } else {
        drawTriangle(x1, y1, x2, y2, x3, y3);
    }
}

// ৩. মেইন ডিসপ্লে ফাংশন
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // বৃত্ত আঁকা
    glColor3f(1.0, 0.0, 0.0); // লাল রঙের বৃত্ত
    drawCircle(r, Xc, Yc);

    // ত্রিভুজের ৩টি বিন্দু ক্যালকুলেট করা (বৃত্তের পরিধিতে)
    float x1 = Xc, y1 = Yc + r;
    float x2 = Xc - (r * 0.866), y2 = Yc - (r * 0.5); // 0.866 = sin(60)
    float x3 = Xc + (r * 0.866), y3 = Yc - (r * 0.5);

    // সিয়েরপিনস্কি ত্রিভুজ আঁকা
    glColor3f(1.0, 1.0, 1.0); // সাদা রঙের ত্রিভুজ
    SG(x1, y1, x2, y2, x3, y3, order);

    glFlush();
}