#pragma once

#include <GLFW/glfw3.h>
#include "Math/Vector3.h"
#include "Math/Matrix4x4.h"
#include "Window/Subscriber.h"

namespace Creyon {
	
	class Camera : public Subscriber{
	public:
		Vector3 m_position, m_target, m_worldUp, m_front;
		float m_speed, m_yaw, m_pitch, m_fieldOfView;
		
		void updateKeyboard(const std::unordered_map<int,bool>& keyStates, float deltaTime)override;
		
		void updateCursor(float offsetX, float offsetY)override;

		void updateMouseScroll(float offsetX, float offsetY)override;
		
		//returns the lookAt matrix
		Mat44 lookAt();
	};
}