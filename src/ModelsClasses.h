#include "GenericModel.h"

using namespace objloader;

//TARGET
class Target : private GenericModel
{
public:
	Target(float x, float y, float z, float s1, float s2, float r);
	void loadModel();
	void drawObject(bool shooting, int difficulty);

private:
	int targetId;
	float rangeLeft, rangeRight;
	bool going_left;
	bool going_right;
	Model mesh_target;
};

static Model mesh_table;
// TREE
class Table : public GenericModel
{
public:
	Table(float x, float y, float z, float s1, float s2, float r);
	void loadModel();
	void drawObject();
	void checkCollisionWithTable(float& z);
	

	Vector<3> minimumVertex;
	Vector<3> maximumVertex;

private:
	float scaleX;
	float scaleZ;
};

//AMMO BOX
static Model mesh_ammobox;
class Ammobox : public GenericModel
{
public:
	Ammobox(float x, float y, float z, float s1, float s2, float r);
	void loadModel();
	void drawObject();
};

//AMMO BOX
static Model mesh_bullet;
class Bullet : public GenericModel
{
public:
	Bullet(float x, float y, float z, float s1, float s2, float rZ, float rY);
	void loadModel();
	void drawObject();
private:
	float rotateZ;
};