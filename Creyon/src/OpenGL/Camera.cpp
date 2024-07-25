#include "Camera.h"

namespace Creyon {

	void Camera::updateKeyboard(const std::unordered_map<int, bool>& keyStates, float deltaTime) {
		if (isKeyPressed(keyStates,GLFW_KEY_W)) {
			m_position = m_position + m_speed * deltaTime * m_front;
		}
		if (isKeyPressed(keyStates, GLFW_KEY_S)) {
			m_position = m_position - m_speed * deltaTime * m_front;
		}
		if (isKeyPressed(keyStates, GLFW_KEY_A)) {
			m_position = m_position - m_speed * deltaTime * normalize(cross(m_front, m_worldUp));
		}
		if (isKeyPressed(keyStates, GLFW_KEY_D)) {
			m_position = m_position + m_speed * deltaTime * normalize(cross(m_front, m_worldUp));
		}
		
	}

	void Camera::updateCursor(float offsetX, float offsetY) {
		m_yaw += offsetX;
		m_pitch += offsetY;

		if (m_pitch > 89.0f)
			m_pitch = 89.0f;
		if (m_pitch < -89.0f)
			m_pitch = -89.0f;

		Vector3 cameraDirection;
		cameraDirection.m_x = cosf(toRadian(m_yaw)) * cosf(toRadian(m_pitch));
		cameraDirection.m_y = sinf(toRadian(m_pitch));
		cameraDirection.m_z = sinf(toRadian(m_yaw)) * cosf(toRadian(m_pitch));
		m_front = normalize(cameraDirection);
	}

	void Camera::updateMouseScroll(float offsetX, float offsetY) {
		m_fieldOfView -= offsetY;
		if (m_fieldOfView < 1.0f)
			m_fieldOfView = 1.0f;
		if (m_fieldOfView > 45.0f)
			m_fieldOfView = 45.0f;
	}

	Mat44 Camera::lookAt() {
		Vector3 cameraDirection = normalize(m_position - m_target);
		Vector3 cameraRight = normalize(cross(m_worldUp, cameraDirection));
		Vector3 cameraUp = cross(cameraDirection, cameraRight);
		Mat44 cameralookAt;
		cameralookAt[0] = cameraRight.m_x;
		cameralookAt[1] = cameraUp.m_x;
		cameralookAt[2] = cameraDirection.m_x;
		cameralookAt[4] = cameraRight.m_y;
		cameralookAt[5] = cameraUp.m_y;
		cameralookAt[6] = cameraDirection.m_y;
		cameralookAt[8] = cameraRight.m_z;
		cameralookAt[9] = cameraUp.m_z;
		cameralookAt[10] = cameraDirection.m_z;
		cameralookAt[12] = -(cameraRight * m_position);
		cameralookAt[13] = -(cameraUp * m_position);
		cameralookAt[14] = -(cameraDirection * m_position);
		return cameralookAt;
	}
}