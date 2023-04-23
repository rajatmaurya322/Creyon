#pragma once

#include "MathEngine/vector3d.h"

namespace Creyon {

	class PointLight {
	public:
		Vector3d m_position, m_ambient, m_diffuse, m_specular;
		float m_constant, m_linear, m_quadratic;

		PointLight(const Vector3d& position, const Vector3d& ambient,
				   const Vector3d& diffuse, const Vector3d& specular,
				   float constant, float linear, float quadratic);
	};
}