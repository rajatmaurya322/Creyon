#pragma once

#include <GLFW/glfw3.h>
#include "Math/Vector3.h"
#include "Math/Matrix4x4.h"
#include "Window/Subscriber.h"
#include "Math/Transforms.h"

namespace Creyon {
	
	class Camera : public Subscriber{
	public:
		Vector3 m_position, m_front, m_right;
		float m_speed, m_yaw, m_pitch, m_fieldOfView;
		
		void updateKeyboard(const std::unordered_map<int,bool>& keyStates, float deltaTime)override;
		
		void updateCursor(float offsetX, float offsetY)override;

		void updateMouseScroll(float offsetX, float offsetY)override;
		
		// Reference : https://stannum.io/blog/0UaG8R
		
		//returns the lookAt matrix
		Mat44 lookAt();
	};
}