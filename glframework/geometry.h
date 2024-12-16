#pragma once
#include "core.h"

class Geometry {
public:
	Geometry();
	~Geometry();
	static Geometry* creatBox(float size);
	static Geometry* creatSphere(float radius);
	static Geometry* creatPlane(float width,float height);

	GLuint getVao() const { return mVao; }
	uint32_t getmIndicesCount() const { return mIndicesCount; }
private:
	GLuint mVao{ 0 };
	GLuint mPosVbo{ 0 };
	GLuint mUvVbo{ 0 };
	GLuint mEbo{ 0 }; 
	GLuint mNormalVbo{ 0 };
	uint32_t mIndicesCount{ 0 };
};