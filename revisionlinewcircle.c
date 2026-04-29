#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
int rx1,rx2,ry1,ry2;
int r,xc,yc;
void bresenham(int x1,int y1,int x2,int y2)
{ 
    int x=x1;
int y=y1;
int dx=abs(x2-x1);
int dy=abs(y2-y1);
 glBegin(GL_POINTS);
 if(dx>dy){
     int di=2*dy-dx;
     glVertex2i(x,y);
         for(int i=0;i<=dx;i++){
             if(di<0){
                 if(x1<x2)
                     x++;
                else
                x--;
                di=di+2*dy;
             
             }
             else {
                if(x1<x2)
                     x++;
                else
                x--;
              
                if(y2>y1)
                y++;
               else
                y--;
                di=di+2*dy-2*dx;
                
             }
                glVertex2i(x,y);
         }
      
         
             
         
         
         
     }
     else
     {
        int di=2*dx-dy;
        glVertex2i(x,y);
        {
            for(int i=0;i<=dy;i++){
                if(di<0){
                    if(y1<y2) y++;else y--;
                    di=di+2*dx;
                    
                }
                else {
                       if(y1<y2) y++;else y--;
                       if(x1<x2)x++;  else x--;
                       di=di+2*dx-2*dy;
                }
                glVertex2i(x,y);
            }
            
            
            
        }
         
         
         
         
     }
     
     glEnd();
     
     
 }
 void rectangle(int x1,int y1,int x2,int y2){
     bresenham(x1,y1,x2,y1);
     bresenham(x2,y1,x2,y2);
     bresenham(x2,y2,x1,y2);
     bresenham(x1,y2,x1,y1);
     
 }
 
void display(void)
{


    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    rectangle(rx1,ry1,rx2,ry2);
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
printf("Enter the value of the points");
   scanf("%d %d %d %d", &rx1,&ry1,&rx2,&ry2);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("straightline");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

return 0;
}

    
    
    
    
    
    
