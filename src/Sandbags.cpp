#include "ModelsClasses.h"


Sandbags::Sandbags(float x, float y, float z, float s1, float s2, float r)
{
	coordinataX = x;
	coordinataY = y;
	coordinataZ = z;
	scaleY = s1;
	scaleXZ = s2;
	rotateY = r;

}

void Sandbags::drawObject()
{

	glPushMatrix();
	glTranslatef(getCoordinataX(), getCoordinataY(), getCoordinataZ());
	glScalef(getScaleXZ(), getScaleY(), getScaleXZ());
	glRotatef(getRotateY(), 0, 1, 0);
	mesh_sandbags.render(false, false);
	glPopMatrix();

}

void Sandbags::loadModel() {

	mesh_sandbags.load(0, "Models/", "trincea.obj", "trincea.mtl");
}
