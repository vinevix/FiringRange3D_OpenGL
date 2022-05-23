#include "ModelsClasses.h"

using namespace std;
Table::Table(float x, float y, float z, float s1, float s2, float s3)
{
	coordinataX = x;
	coordinataY = y;
	coordinataZ = z;
	scaleY = s1;
	scaleZ = s2;
	scaleX= s3;
	setRotateY(-40.5);
}

void Table::drawObject()
{
	glPushMatrix();
	glTranslatef(getCoordinataX(), getCoordinataY(), getCoordinataZ());
	glScalef(scaleX, getScaleY(), scaleZ);
	glRotatef(getRotateY(), 0, 1, 0);
	mesh_table.render(false, false);
	glPopMatrix();
}

void Table::loadModel() {
	mesh_table.load(100, "Models/", "table.obj", "table.mtl");

	//get min e max vertices

	minimumVertex = mesh_table.minimumVertex();
	maximumVertex = mesh_table.maximumVertex();
}

// -Z -coordinataZ - (coordinataZ*scaleZ) IN AVANTI
// Z -coordinataZ + (coordinataZ*scaleZ) VERSO DI NOI

void Table::checkCollisionWithTable(float& camZ) {
	//we just need to check the collision with the front side of the table
	//because the model is as large as the room and it's the only side 
	//where the player can collide
	
	float z_min_table = coordinataZ + ((maximumVertex.z * scaleZ)/2);

	if (camZ <= z_min_table + 1)
		camZ = z_min_table + 1;
}