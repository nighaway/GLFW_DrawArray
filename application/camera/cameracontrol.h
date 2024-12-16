#pragma once 
#include "../../glframework/core.h"
#include "camera.h"
#include <map>
class CameraControl {
public:
	CameraControl();
	~CameraControl();

	virtual void onMouse(int button,int action,double xpos,double ypos);
	virtual void onCursor(double xpos, double ypos);
	virtual void onKey(int key, int action, int mods);
	virtual void update();
	virtual void onScroll(float offset);
	void setCamera(Camera* camera) { mCamera = camera; }
	void setSensitivity(float s) { mSensitivity = s; }
	void setScaleSpeed(float s) { mScaleSpeed = s; }

protected:
	bool mLeftMouseDown = false;
	bool mRightMouseDown = false;
	bool mMiddleMouseDown = false;
	float mCurrentx = 0.0f, mCurrenty = 0.0f;

	std::map<int, bool> mKeyMap;
	Camera* mCamera{ nullptr };
	float mSensitivity = 0.1f;
	float mScaleSpeed = 0.2f;
};