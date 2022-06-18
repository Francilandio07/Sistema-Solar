//#include <stdlib.h>
//#include <GL/glut.h>
//
//
///* angulos de rotacao para os corpos celestes */
//float angleEarth = 0;
//float angleMoon = 0;
//float angleMars = 0;
//
//int zoom = 50;
//
//
//
//void reshape(GLint w, GLint h) {
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 40.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void mouseControl(int button, int state, int x, int y)
//{
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//        zoom++;
//	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) zoom--;
//	glutPostRedisplay();
//}
////==================================================================
//void drawSun() {
//
//    glColor3f(1, 1, 0);
//    glutSolidSphere(12, 16, 16);
//
//}
//
//void drawEarth() {
//
//    glColor3f(0, 0, 1);
//    glutSolidSphere(5, 16, 16);
//
//}
//
//void drawMoon() {
//
//    glColor3f(0.5, 0.5, 0.5);
//    glutSolidSphere(1, 16, 16);
//
//}
//
//void drawMars() {
//
//    glColor3f(1, 0.2, 0);
//    glutSolidSphere(4, 16, 16);
//}
//
//void display(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    glLoadIdentity();
//
//    gluLookAt(0, zoom, 0, 0, 0, 0, 0, 0, 1);
//
//    // Draw planetary system
//    glPushMatrix();
//        drawSun();
//        glPushMatrix();
//            glRotatef(angleEarth, 0, 1, 0);
//            glTranslatef(30, 0, 0);
//            drawEarth();
//            glPushMatrix();
//                glRotatef(angleMoon, 0, 1, 0);
//                glTranslatef(7, 0, 0);
//                drawMoon();
//            glPopMatrix();
//        glPopMatrix();
//        glPushMatrix();
//            glRotatef(angleMars, 0, 1, 0);
//            glTranslatef(50, 0, 0);
//            drawMars();
//        glPopMatrix();
//    glPopMatrix();
//    glFlush();
//    glutSwapBuffers();
//}
//
//
//void TimerFunction(int value) {
//
//    angleEarth += 3;
//    if (angleEarth >= 360) angleEarth = 0;
//
//    angleMoon += 6;
//    if (angleMoon >= 360) angleMoon = 0;
//
//    angleMars += 2;
//    if (angleMars >= 360) angleMars = 0;
//
//    glutPostRedisplay();
//    glutTimerFunc(33, TimerFunction, 1);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("On a Comet");
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutMouseFunc(mouseControl);
//    glutTimerFunc(100, TimerFunction, 0);
//    glEnable(GL_DEPTH_TEST);
//    glutMainLoop();
//}