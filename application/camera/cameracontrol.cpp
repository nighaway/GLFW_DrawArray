#include "cameracontrol.h"
#include "cameracontrol.h"
#include "iostream"

CameraControl::CameraControl()
{
}

CameraControl::~CameraControl()
{
}

void CameraControl::onMouse(int button, int action, double xpos, double ypos)
{
	bool pressed = action == GLFW_PRESS ? true : false;
	if (pressed) {
		mCurrentx = xpos;
		mCurrenty = ypos;
	}
	switch (button) {
	case GLFW_MOUSE_BUTTON_LEFT:
		mLeftMouseDown = pressed;
		break;
	case GLFW_MOUSE_BUTTON_RIGHT:
		mRightMouseDown = pressed;
		break;
	case GLFW_MOUSE_BUTTON_MIDDLE:
		mMiddleMouseDown = pressed;
		break;
	}
}

void CameraControl::onCursor(double xpos, double ypos)
{
}

void CameraControl::onKey(int key, int action, int mods)
{
	bool pressed = action == GLFW_PRESS ? true : false;
	mKeyMap[key] = pressed;
}

void CameraControl::update()
{
}

void CameraControl::onScroll(float offset)
{
}
