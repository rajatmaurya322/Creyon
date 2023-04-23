#include "PointLight.h"

namespace Creyon {

	PointLight::PointLight(const Vector3d& position, const Vector3d& ambient,
						   const Vector3d& diffuse, const Vector3d& specular,
						   float constant, float linear, float quadratic)
	:m_position{position},
	 m_ambient{ambient},
	 m_diffuse{diffuse},
	 m_specular{specular},
	 m_constant{constant},
	 m_linear{linear},
	 m_quadratic{quadratic}
	{}
}