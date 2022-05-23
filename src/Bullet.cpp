#include "ModelsClasses.h"


Bullet::Bullet(float x, float y, float z, float s1, float s2, float rZ, float rY)
{
	coordinataX = x;
	coordinataY = y;
	coordinataZ = z;
	scaleY = s1;
	scaleXZ = s2;
	rotateZ = rZ;
	rotateY = rY;

}

void Bullet::drawObject()
{
	glPushMatrix();
	glTranslatef(getCoordinataX(), getCoordinataY(), getCoordinataZ());
	glScalef(getScaleXZ(), getScaleY(), getScaleXZ());
	glRotatef(rotateY, 0, 1, 0);
	glRotatef(rotateZ, 1, 0, 0);
	mesh_bullet.render(false, false);
	glPopMatrix();

}

void Bullet::loadModel() {

	mesh_bullet.load(0, "Models/", "bullet.obj", "bullet.mtl");
}
