#include "ModelsClasses.h"


Ammobox::Ammobox(float x, float y, float z, float s1, float s2, float r)
{
	coordinataX = x;
	coordinataY = y;
	coordinataZ = z;
	scaleY = s1;
	scaleXZ = s2;
	rotateY = r;

}

void Ammobox::drawObject()
{

	glPushMatrix();
	glTranslatef(getCoordinataX(), getCoordinataY(), getCoordinataZ());
	glScalef(getScaleXZ(), getScaleY(), getScaleXZ());
	glRotatef(getRotateY(), 0, 1, 0);
	mesh_ammobox.render(false, false);
	glPopMatrix();

}

void Ammobox::loadModel() {

	mesh_ammobox.load(0, "Models/", "ammobox.obj", "ammobox.mtl");
}
