#include "trackballcamera.h"
#include "trackballcamera.h"

TrackBallCamera::TrackBallCamera()
{
}

TrackBallCamera::~TrackBallCamera()
{
}

void TrackBallCamera::onCursor(double xpos, double ypos)
{
	if (mLeftMouseDown) {
		float deltaX = (xpos - mCurrentx) * mSensitivity;
		float deltaY = (ypos - mCurrenty) * mSensitivity;

		pitch(deltaY);
		yaw(deltaX);
	}
	if (mMiddleMouseDown) {
		float deltaX = (xpos - mCurrentx) * mMoveSpeed;
		float deltaY = (ypos - mCurrenty) * mMoveSpeed;

		mCamera->mPosition += mCamera->mUp * deltaY;
		mCamera->mPosition -= mCamera->mRight * deltaX;
	}
	mCurrentx = xpos;
	mCurrenty = ypos;
}

void TrackBallCamera::onScroll(float offset)
{
	mCamera->scale(mScaleSpeed * offset);
}

void TrackBallCamera::pitch(float angle)
{
	auto mat=glm::rotate(glm::mat4(1.0f),glm::radians(angle),mCamera->mRight);
	mCamera->mUp = mat * glm::vec4(mCamera->mUp, 0.0f);
	mCamera->mPosition = mat * glm::vec4(mCamera->mPosition, 1.0f);
}

void TrackBallCamera::yaw(float angle)
{
	auto mat = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
	mCamera->mUp = mat * glm::vec4(mCamera->mUp, 0.0f);
	mCamera->mRight = mat * glm::vec4(mCamera->mRight, 0.0f);
	mCamera->mPosition = mat * glm::vec4(mCamera->mPosition, 1.0f);
}
