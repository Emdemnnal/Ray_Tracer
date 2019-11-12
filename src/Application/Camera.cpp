#include "Camera.h"
#include "Ray.h"

Ray Camera::createRay(glm::ivec2 position)
{
	Ray ray;
	ray.origin(position, 0);
	ray.direction(0, 0, -1);
	
	return ray;
};


