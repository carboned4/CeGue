#ifndef CAR_H
#define CAR_H
#include "glut.h"
#include "DynamicObject.h"


class Car : public DynamicObject {
public:
	Car(){}
	~Car(){}
	void draw(){
		Vector3* vector = getPosition();
		glPushMatrix();
		glTranslatef(vector->getX(), vector->getY(), vector->getZ());

		glPushMatrix();
		glTranslatef(-0.2, 0.0, 0.1);
		glColor3f(1.0, 1.0, 0.0);
		glutSolidCube(0.8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.8, 0.0, 0.1);
		glColor3f(1.0, 1.0, 0.0);
		glutSolidCube(0.8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.1, 0.3, -0.3);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.2, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.1, -0.3, -0.3);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.2, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.9, 0.3, -0.3);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.2, 12, 12);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.9, -0.3, -0.3);
		glColor3f(0.25, 0.25, 0.25);
		glutSolidSphere(0.2, 12, 12);
		glPopMatrix();


		glPopMatrix();
	}
};

#endif