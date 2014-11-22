#ifndef ROADSIDE_H
#define ROADSIDE_H

#include "glut.h"
#include "StaticObject.h"

class Roadside : public StaticObject {

public:

	Roadside() :StaticObject(Box(-6.0,6.0,-0.5,0.2)){}

	~Roadside(){}

	int answerToColision(){ return 4; }			// 4 = ground

	void draw(){
		Vector3 vector = getPosition();
		GLfloat mat_specular[] = { 0.0, 0.01, 0.0, 1.0 };
		GLfloat mat_ambient[] = { 0.2, 0.5, 0.0, 1.0 };
		GLfloat mat_diffuse[] = { 0.2, 0.5, 0.0, 1.0 };
		GLfloat shininess = 10;

		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient);
		glTranslatef(vector.getX(), vector.getY(), vector.getZ());

		for (double y = -0.25; y <= 0.25; y += 0.5){
			for (double x = -5.25; x <= 5.25; x += 0.5){
				glPushMatrix();
				glTranslatef(x, y, 0.0);
				glColor3f(0.0, 0.25, 0.0);
				glBegin(GL_QUADS);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(0, 0);
				glVertex3f(-0.25, -0.25, 0.5);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(1, 0);
				glVertex3f(0.25, -0.25, 0.5);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(1, 1);
				glVertex3f(0.25, 0.25, 0.5);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(0, 1);
				glVertex3f(-0.25, 0.25, 0.5);
				glEnd();
				glPopMatrix();
			}
		}
		for (double z = -0.25; z <= 0.25; z += 0.5){
			for (double x = -5.25; x <= 5.25; x += 0.5){
				glPushMatrix();
				glTranslatef(x, 0.0, z);
				glColor3f(0.0, 0.25, 0.0);
				glBegin(GL_QUADS);
				glNormal3f(0.0, -1.0, 1.0);
				glTexCoord2f(0, 0);
				glVertex3f(-0.25, -0.5, -0.25);
				glNormal3f(0.0, -1.0, 1.0);
				glTexCoord2f(1, 0);
				glVertex3f(0.25, -0.5, -0.25);
				glNormal3f(0.0, -1.0, 1.0);
				glTexCoord2f(1, 1);
				glVertex3f(0.25, -0.5, 0.25);
				glNormal3f(0.0, -1.0, 1.0);
				glTexCoord2f(0, 1);
				glVertex3f(-0.25, -0.5, 0.25);
				glEnd();
				glPopMatrix();
			}
		}
		for (double z = -0.25; z <= 0.25; z += 0.5){
			for (double x = -5.25; x <= 5.25; x += 0.5){
				glPushMatrix();
				glTranslatef(x, 0.0, z);
				glColor3f(0.0, 0.25, 0.0);
				glBegin(GL_QUADS);
				glNormal3f(0.0, 1.0, 1.0);
				glTexCoord2f(0, 0);
				glVertex3f(0.25, 0.5, -0.25);
				glNormal3f(0.0, 1.0, 1.0);
				glTexCoord2f(1, 0);
				glVertex3f(-0.25, 0.5, -0.25);
				glNormal3f(0.0, 1.0, 1.0);
				glTexCoord2f(1, 1);
				glVertex3f(-0.25, 0.5, 0.25);
				glNormal3f(0.0, 1.0, 1.0);
				glTexCoord2f(0, 1);
				glVertex3f(0.25, 0.5, 0.25);
				glEnd();
				glPopMatrix();
			}
		}

		glPopMatrix();
	}

};

#endif