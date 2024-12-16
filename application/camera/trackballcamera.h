#pragma once

#include "cameracontrol.h"

class TrackBallCamera :public CameraControl {
public:
	TrackBallCamera();
	~TrackBallCamera();

	void onCursor(double xpos, double ypos) override;
	void onScroll(float offset) override;
private:
	void pitch(float angle);
	void yaw(float angle);
	float mMoveSpeed=0.01f;
};