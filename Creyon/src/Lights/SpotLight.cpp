#include "SpotLight.h"

namespace Creyon {

	SpotLight::SpotLight(const Vector3d& position, const Vector3d& direction, const Vector3d& ambient,
						 const Vector3d& diffuse, const Vector3d& specular,
						 float constant, float linear, float quadratic,
						 float cutoff, float outerCutoff)
	:m_position{position},
	 m_direction{direction},
	 m_ambient{ambient},
	 m_diffuse{diffuse},
	 m_specular{specular},
	 m_constant{constant},
	 m_linear{linear},
	 m_quadratic{quadratic},
	 m_cutoff{cos(toRad(cutoff))},
	 m_outerCutoff{cos(toRad(outerCutoff))}
	{}
}