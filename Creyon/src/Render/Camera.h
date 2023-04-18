#pragma once

#include "MathEngine/vector3d.h"
#include "MathEngine/matrix4x4.h"
#include "MathEngine/transforms.h"
#include "Utilities/Utility.h"
#include "Core/Entity.h"

//Namespace is Creyon
namespace Creyon {

	class Camera:public Entity {
	private:
		Vector3d m_pos, m_target, m_up, m_front;
		float m_speed, m_yaw, m_pitch;

	public:
		Camera();

		//Generates the lookAt matrix
		Mat44 lookAt();

		//Handles Keyboard Inputs
		void onKey(float delta) override;

		//Handles Mouse Inputs
		void onMouseMotion(float offsetX , float offsetY) override;

	};
	//Reference: LearnOpengl.com
}

