#include<iostream>
#include<stdio.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<GL/glut.h>
#define pi 3.14159
int r1, r2;

class point
{
public:
    float x;
    float y;
    point(){}
    point(float x1, float y1)
    {
        x=x1, y=y1;
    }
};

point o1(-300, 0);
point o2(150, 0);

point p1(200, 0);
point p2(-100,173.2051);
point p3(-100, -173.2051);

point p4(200, 0);
point p5(-100,173.2051);
point p6(-100, -173.2051);

point myRotate(point p, float dtheta)
{
    float rtheta= pi/180 * dtheta;
    point p1;
    p1.x= p.x * cos(rtheta) - p.y * sin(rtheta);
    p1.y= p.y * cos(rtheta) + p.x * sin(rtheta);
    return p1;
}

void my_initialization(void)
{
    glClearColor(1,1,0,1);
    glPointSize(2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-800,800,-700,700);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    float i, x1, y1;
    int rad1= 200, rad2= 60;
    glBegin(GL_POINTS);
    glColor3d(1,0,0);
    for(i=0;i<=2*pi;i+=0.01)
    {
        x1 = rad1 * cos(i);
        y1 = rad1 * sin(i);
            glVertex2f(x1+o1.x,y1+o1.y);

        x1 = rad2 * cos(i);
        y1 = rad2 * sin(i);
            glVertex2f(x1+o1.x,y1+o1.y);
    }
    glEnd();

    glBegin(GL_LINES);
        glVertex2d(o1.x, o1.y);
        glVertex2d(p1.x+o1.x, p1.y);
    glEnd();
    glFlush();

    glBegin(GL_LINES);
        glVertex2d(o1.x, o1.y);
        glVertex2d(p2.x+o1.x, p2.y);
    glEnd();
    glFlush();

    glBegin(GL_LINES);
        glVertex2d(o1.x, o1.y);
        glVertex2d(p3.x+o1.x, p3.y);
    glEnd();
    glFlush();

    glBegin(GL_POINTS);
    glColor3d(0,0,1);
    for(i=0;i<=2*pi;i+=0.01)
    {
        x1 = rad1 * cos(i);
        y1 = rad1 * sin(i);
            glVertex2f(x1+o2.x,y1+o2.y);

        x1 = rad2 * cos(i);
        y1 = rad2 * sin(i);
            glVertex2f(x1+o2.x,y1+o2.y);
    }
    glEnd();

    glBegin(GL_LINES);
        glVertex2d(o2.x, o2.y);
        glVertex2d(p4.x+o2.x, p4.y);
    glEnd();
    glFlush();

    glBegin(GL_LINES);
        glVertex2d(o2.x, o2.y);
        glVertex2d(p5.x+o2.x, p5.y);
    glEnd();
    glFlush();

    glBegin(GL_LINES);
        glVertex2d(o2.x, o2.y);
        glVertex2d(p6.x+o2.x, p6.y);
    glEnd();
    glFlush();

    glutSwapBuffers();
}

void rotate_lines();

void initialize_rotate(int x)
{
    rotate_lines();
    glutPostRedisplay();
}

void rotate_lines()
{
    p1=myRotate(p1, r1);
    p2=myRotate(p2, r1);
    p3=myRotate(p3, r1);

    p4=myRotate(p4, -r2);
    p5=myRotate(p5, -r2);
    p6=myRotate(p6, -r2);

    glutTimerFunc(100, initialize_rotate, 10);
}

int main(int argc, char *argv[])
{
    srand(time(0));
    r1= rand() % 500;
    r2= rand() % 500;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(220, 50);
    glutCreateWindow("Rotating circles");
    glutTimerFunc(100, initialize_rotate, 10);
    my_initialization();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
