#include "Camera.h"

namespace Creyon {

	Camera::Camera() {
		//Set camera to these default vectors
		vector3d camPos{ 0.0f,0.0f,3.0f }, camFront{ 0.0f,0.0f,-1.0f }, camUp{ 0.0f,1.0f,0.0f };
		setCamera(camPos, camFront, camUp, 3.0f);
	}

	void Camera::setCamera(const vector3d& pos, const vector3d& front, const vector3d& up, const float speed)
	{
		m_pos = pos; m_front = front; m_target = m_pos + m_front;
		m_up = up; m_speed = speed;
		m_yaw = -90.0f; m_pitch = 0.0f;
	}

	void Camera::UpdateTarget() {
		m_target = m_pos + m_front;
	}

	matrix_4x4 Camera::lookAt(){
		UpdateTarget();
		vector3d direction = normalize(m_pos - m_target);
		vector3d right = normalize(cross(m_up, direction));
		vector3d up = cross(direction, right);

		//Constructing the lookAt matrix
		matrix_4x4 LookAt{	right.m_x,		up.m_x,		direction.m_x,		0.0f,
							right.m_y,		up.m_y,		direction.m_y,		0.0f,
							right.m_z,		up.m_z,		direction.m_z,		0.0f,
						   -(right*m_pos),	-(up*m_pos), -(direction*m_pos),1.0f };
		
		return LookAt;
	}

	void Camera::moveForward(const float camSpeed) {
		m_pos = m_pos + camSpeed * m_front;
	}

	void Camera::moveBackward(const float camSpeed) {
		m_pos = m_pos - camSpeed * m_front;
	}

	void Camera::moveRight(const float camSpeed) {
		m_pos = m_pos + camSpeed * normalize(cross(m_front, m_up));
	}

	void Camera::moveLeft(const float camSpeed) {
		m_pos = m_pos - camSpeed * normalize(cross(m_front, m_up));
	}

	void Camera::increaseAngle(const float x, const float y) {
		//Increase camera's yaw and pitch angles on mouse movement
		m_yaw += x ;
		m_pitch += y;

		//Prevent camera from looking straight up or down(messes up the lookAt matrix)
		if (m_pitch > 89.0f)
			m_pitch = 89.0f;
		if(m_pitch<-89.0f)
			m_pitch = -89.0f;
	}

	void Camera::rotateCamera() {
		//Update camera's front
		vector3d tempFront;
		tempFront.m_x = cos(degToRad(m_yaw)) * cos(degToRad(m_pitch));
		tempFront.m_y = sin(degToRad(m_pitch));
		tempFront.m_z = sin(degToRad(m_yaw)) * cos(degToRad(m_pitch));

		m_front = normalize(tempFront);
	}
}
