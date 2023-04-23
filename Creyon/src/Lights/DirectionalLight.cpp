#include "DirectionalLight.h"

namespace Creyon {

	DirectionalLight::DirectionalLight(const Vector3d& direction, const Vector3d& ambient,
									   const Vector3d& diffuse, const Vector3d& specular)
	:m_direction{ direction },
	 m_ambient{ ambient },
	 m_diffuse{ diffuse },
	 m_specular{ specular }
	{}
}