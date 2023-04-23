#pragma once

#include "MathEngine/vector3d.h"

namespace Creyon {

	class DirectionalLight {
	public:
		Vector3d m_direction, m_ambient, m_diffuse, m_specular;
		
		DirectionalLight(const Vector3d& direction, const Vector3d& ambient,
						 const Vector3d& diffuse, const Vector3d& specular);
	};
		
}