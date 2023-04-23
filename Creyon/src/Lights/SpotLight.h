#pragma once

#include "MathEngine/vector3d.h"
#include "Utilities/Utility.h"

namespace Creyon {

	class SpotLight {
	public:
		Vector3d m_position, m_direction, m_ambient, m_diffuse, m_specular;
		float m_constant, m_linear, m_quadratic;
		float m_cutoff, m_outerCutoff;

		SpotLight(const Vector3d& position, const Vector3d& direction, const Vector3d& ambient,
				  const Vector3d& diffuse, const Vector3d& specular,
				  float constant, float linear, float quadratic,
				  float cutoff, float outerCutoff);
	};
}