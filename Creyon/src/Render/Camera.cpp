#include "Camera.h"

namespace Creyon {

	Camera::Camera()
	:m_pos{ 0.0f,1.0f,4.0f },
	 m_front{ 0.0f,0.0f,-1.0f },
	 m_up{ 0.0f,1.0f,0.0f },
	 m_yaw{ -90.0f },
	 m_pitch{ 0.0f },
	 m_speed{5.0f},
	 m_target{ m_pos + m_front }
	{}

	Mat44 Camera::lookAt(){
		m_target = m_pos + m_front; //Updates the camera target
		Vector3d direction = normalize(m_pos - m_target);
		Vector3d right = normalize(cross(m_up, direction));
		Vector3d up = cross(direction, right);

		//Constructing the lookAt matrix
		return Mat44{	right.m_x,		up.m_x,		direction.m_x,		0.0f,
						right.m_y,		up.m_y,		direction.m_y,		0.0f,
						right.m_z,		up.m_z,		direction.m_z,		0.0f,
					  -(right*m_pos), -(up*m_pos), -(direction*m_pos),	1.0f };
	}

	void Camera::onKey(float delta) {
		float camspeed = m_speed * delta ;

		if (isPressed(GLFW_KEY_W)) {
			m_pos = m_pos + camspeed * m_front;		//(Forward)
		}
		if (isPressed(GLFW_KEY_S)) {
			m_pos = m_pos - camspeed * m_front;		//(Backward)
		}
		if (isPressed(GLFW_KEY_A)) {
			m_pos = m_pos - camspeed * normalize(cross(m_front, m_up));		//(Left)
		}
		if (isPressed(GLFW_KEY_D)) {
			m_pos = m_pos + camspeed * normalize(cross(m_front, m_up));		//(Right)
		}
	}
	
	void Camera::onMouseMotion(float offsetX, float offsetY) {
	
		//Increase camera's yaw and pitch angles on mouse movement
		m_yaw += offsetX;
		m_pitch += offsetY;

		//Prevent camera from looking straight up or down(messes up the lookAt matrix)
		if (m_pitch > 89.0f)
			m_pitch = 89.0f;
		if (m_pitch < -89.0f)
			m_pitch = -89.0f;

		//Update camera's front
		Vector3d tempFront;
		tempFront.m_x = cos(toRad(m_yaw)) * cos(toRad(m_pitch));
		tempFront.m_y = sin(toRad(m_pitch));
		tempFront.m_z = sin(toRad(m_yaw)) * cos(toRad(m_pitch));
		m_front = normalize(tempFront);
	}
}
