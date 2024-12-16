#pragma once

#include "camera.h"

class PerspectiveCamera :public Camera {
public:
	PerspectiveCamera(float mFovy ,float mAspect ,float mNear,float mFar );
	~PerspectiveCamera();

	glm::mat4 getProjectMatrix() override;
	void scale(float deltaScale) override;
private:
	float mFovy = 0.0f;
	float mAspect = 0.0f;
	float mNear = 0.0f;
	float mFar = 0.0f;
	
};