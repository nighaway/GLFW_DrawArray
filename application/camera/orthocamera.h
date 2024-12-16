#pragma once

#include "camera.h"

class OrthoCamera :public Camera {
public:
	OrthoCamera(float l,float r, float t, float b, float n, float f);
	~OrthoCamera();
	void scale(float deltaScale) override;
	glm::mat4 getProjectMatrix() override;
private:
	float mLeft{ 0 };
	float mRight{ 0 };
	float mTop{ 0 };
	float mBottom{ 0 };
	float mNear{ 0 };
	float mFar{ 0 };
	float mScale{ 0.0f };
};