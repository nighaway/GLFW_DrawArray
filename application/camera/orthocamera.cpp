#include "orthocamera.h"

OrthoCamera::OrthoCamera(float l, float r, float t, float b, float n, float f)
{
	mLeft=l,mRight=r,mTop=t,mBottom=b,mNear=n,mFar=f;
}

OrthoCamera::~OrthoCamera()
{
}

void OrthoCamera::scale(float deltaScale)
{
	mScale += deltaScale;
}

glm::mat4 OrthoCamera::getProjectMatrix()
{
	float scale = std::pow(2.0, mScale);
	return glm::ortho(mLeft * scale, mRight*scale, mTop * scale, mBottom * scale, mNear, mFar);
}
