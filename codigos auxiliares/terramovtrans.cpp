//#include <GL/glut.h>
//#include "imageloader.h"
//
//int bigOrbitActive = 1;//Órbitas maiores
//int changeCamera = 0;//Mudança de câmera
//int zoom = 50;//Proximidade da câmera
//static float factor = 1;//Fator de velocidade
//
//float lightPos[] = { 0.0, 10.0, 0.0, 0.0 }; // Posição do ponto de luz
//static float spotAngle = 180; // Spotlight cone half-angle.
//float spotDirection[] = { 0.0, -1.0, 0.0 }; // Direção do ponto de luz
//static float spotExponent = 5.0; // Fator de atenuação
//
//class Planet {
//public:
//    float radius, distance, orbit, orbitSpeed, axisTilt, axisAni;
//    Planet(float _radius, float _distance, float _orbit, float _orbitSpeed, float _axisTilt, float _axisAni) {
//        radius = _radius;
//        distance = _distance;
//        orbit = _orbit;
//        orbitSpeed = _orbitSpeed;
//        axisTilt = _axisTilt;
//        axisAni = _axisAni;
//    }
//    //Linhas da órbita
//    void drawSmallOrbit(void) {
//        glPushMatrix();
//        glColor3ub(255, 255, 255);
//        glRotatef(90.0, 1.0, 0.0, 0.0);
//        glutWireTorus(0.001, distance, 100.0, 100.0);
//        glPopMatrix();
//    }
//    //Gera o satélite natural do planeta
//    void drawMoon(void) {
//        GLUquadricObj* quadric;
//        quadric = gluNewQuadric();
//        glPushMatrix();
//        glColor3ub(255, 255, 255);
//        glRotatef(orbit, 0.0, 1.0, 0.0);
//        glTranslatef(distance, 0.0, 0.0);
//        gluSphere(quadric, radius, 20.0, 20.0);
//        glPopMatrix();
//    }
//
//};
//
//Planet ear(2.0, 16, 0, 2.98, 23.44, 0);		//Earth
//
//GLuint loadTexture(Image* image) {
//    GLuint textureId;
//    glGenTextures(1, &textureId);
//    glBindTexture(GL_TEXTURE_2D, textureId);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
//    return textureId;
//}
//
//GLuint earTexture;
//
//void setup(void) {
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glEnable(GL_DEPTH_TEST);
//
//    //Geração de texturas
//    glEnable(GL_NORMALIZE);
//    glEnable(GL_COLOR_MATERIAL);
//    Image* ear = loadBMP("earth.bmp");		earTexture = loadTexture(ear);		delete ear;
//
//    //Configurando iluminação da cena
//    glEnable(GL_LIGHTING);
//    float lightAmb[] = { 0.0, 0.0, 0.0, 1.0 };
//    float lightDifAndSpec[] = { 1.0, 1.0, 1.0, 1.0 };
//    float globAmb[] = { 0.5, 0.5, 0.5, 1.0 };
//    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
//    glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);
//    glEnable(GL_LIGHT0);
//    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);
//    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
//    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
//    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, spotAngle);
//    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDirection);
//    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, spotExponent);
//}
//
////Redimensionamento de janela
//void reshape(GLint w, GLint h) {
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 200.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void keyInput(unsigned char key, int x, int y) {
//    switch (key) {
//    case 27: exit(0); break;//Pressionar esc para fechar a janela
//    case 'o': if (bigOrbitActive) bigOrbitActive = 0; else bigOrbitActive = 1; glutPostRedisplay(); break; //'o' ativa as órbitas 
//    case '1': changeCamera = 0; glutPostRedisplay(); break;//'1' câmera em perspectiva
//    case '2': changeCamera = 1; glutPostRedisplay(); break;//'2' câmera lateral
//    case '3': changeCamera = 2; glutPostRedisplay(); break;//'3' câmera superior
//    case 'f': factor *= 2; glutPostRedisplay; break;//'f' dobra a velocidade de translação dos planetas
//    case 's': factor /= 2; glutPostRedisplay; break;//'s' divide por 2 a velocidade de translação dos planetas
//    }
//}
//
//void mouseControl(int button, int state, int x, int y)
//{
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)//Botão esquerdo do mouse aumenta o zoom
//        zoom += 10;
//    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)//Botão direito do mouse diminui o zoom
//        zoom -= 10;
//    glutPostRedisplay();
//}
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//
//	//Diferentes posições da câmera
//	if (changeCamera == 0)gluLookAt(0.0, zoom, 50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//	if (changeCamera == 1)gluLookAt(0.0, 0.0, zoom, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//	if (changeCamera == 2)gluLookAt(0.0, zoom, 2, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//
//	GLUquadric* quadric;
//	quadric = gluNewQuadric();
//
//	//Planeta Terra e órbita
//	glPushMatrix();
//	    glRotatef(ear.orbit,0.0, 1.0, 0.0);
//	    glTranslatef(ear.distance,0.0, 0.0);
//	    glPushMatrix();
//	        glRotatef(ear.axisTilt, 1.0, 0.0, 0.0);
//	        glRotatef(ear.axisAni, 0.0, 1.0, 0.0);
//	        glRotatef(90.0, 1.0, 0.0, 0.0);
//	        glEnable(GL_TEXTURE_2D);
//	        glBindTexture(GL_TEXTURE_2D, earTexture);
//	        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	        gluQuadricTexture(quadric, 1);
//	        gluSphere(quadric, ear.radius, 20.0, 20.0);
//	        glDisable(GL_TEXTURE_2D);
//	    glPopMatrix();
//	glPopMatrix();
//
//	glutSwapBuffers();
//}
//
//void TimerFunction(int value) {
//    ear.orbit += ear.orbitSpeed * factor;
//    if (ear.orbit >= 360) ear.orbit = 0;
//
//    ear.axisAni += 10.0;
//    if (ear.axisAni > 360.0) ear.axisAni -= 360.0;
//
//    glutPostRedisplay();
//    glutTimerFunc(33, TimerFunction, 1);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Sistema Solar");
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutMouseFunc(mouseControl);
//    glutKeyboardFunc(keyInput);
//    glutTimerFunc(100, TimerFunction, 0);
//    glEnable(GL_DEPTH_TEST);
//    setup();
//    glutMainLoop();
//}