#include "Camera.h"

namespace Creyon {

	void Camera::updateKeyboard(const std::unordered_map<int, bool>& keyStates, float deltaTime) {
		if (isKeyPressed(keyStates,GLFW_KEY_W)) {
			m_position += m_speed * deltaTime * m_front;
		}
		if (isKeyPressed(keyStates, GLFW_KEY_S)) {
			m_position -= m_speed * deltaTime * m_front;
		}
		if (isKeyPressed(keyStates, GLFW_KEY_A)) {
			m_position -= m_speed * deltaTime * normalize(m_right);
		}
		if (isKeyPressed(keyStates, GLFW_KEY_D)) {
			m_position += m_speed * deltaTime * normalize(m_right);
		}
		
	}

	void Camera::updateCursor(float offsetX, float offsetY) {
		m_yaw += offsetX;
		m_pitch += offsetY;

		if (m_pitch > 89.0f)
			m_pitch = 89.0f;
		if (m_pitch < -89.0f)
			m_pitch = -89.0f;
	}

	void Camera::updateMouseScroll(float offsetX, float offsetY) {
		m_fieldOfView -= offsetY;
		if (m_fieldOfView < 1.0f)
			m_fieldOfView = 1.0f;
		if (m_fieldOfView > 45.0f)
			m_fieldOfView = 45.0f;
	}

	Mat44 Camera::lookAt() {
		Mat44 cameralookAt = translate(-m_position) * rotateY(m_yaw) * rotateX(-m_pitch);
		m_right = Vector3{ cameralookAt(0,0), cameralookAt(1,0), cameralookAt(2,0) };
		m_front = -Vector3{ cameralookAt(0,2), cameralookAt(1,2), cameralookAt(2,2) };
		return cameralookAt;
	}
}