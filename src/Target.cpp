#include "ModelsClasses.h"

static int globalTargetId = 0;

Target::Target(float x, float y, float z, float s1, float s2, float r)
{
	coordinataX = x;
	coordinataY = y;
	coordinataZ = z;
	scaleY = s1;
	scaleXZ = s2;
	rotateY = r;
	
	//give an unique id to every initialized target
	this->targetId = globalTargetId++;

	//define boolean variables to set the movement
	int range = 2;
	rangeLeft = coordinataX - range;
	rangeRight = coordinataX + range;

	//the starting movement direction is choosen randomly
	if ((1 + std::rand() % (100)) > 50) {
		going_left = true;
		going_right = false;
	}
	else {
		going_left = false;
		going_right = true;
	}
}

void Target::drawObject(bool shooting, int difficulty)
{

	// MOVE TARGETS
	if (going_left) {
		if (getCoordinataX() > rangeLeft) {
			this->coordinataX -= (0.05 + (0.04 * difficulty));
		}
		else {
			going_left = false;
			going_right = true;
		}
	}
	else if (going_right) {
		if (getCoordinataX() < rangeRight) {
			this->coordinataX += (0.05 + (0.04 * difficulty));
		}
		else {
			going_left = true;
			going_right = false;
		}
	}
	//END MOVIING


	glPushMatrix();
		glTranslatef(getCoordinataX(), getCoordinataY(), getCoordinataZ());
		glScalef(getScaleXZ(), getScaleY(), getScaleXZ());
		glRotatef(getRotateY(), 0, 1, 0);
		mesh_target.render(shooting, false);
	glPopMatrix();

}

void Target::loadModel() {

	mesh_target.load(this->targetId, "Models/", "RobotLowPoly.obj", "RobotLowPoly.mtl");
}
