#include "Camera.h"
#include "Ray.h"

Ray Camera::createRay(glm::ivec2 position)
{
	// proj = glm::perspective(  );
	Ray ray;
	ray.origin = glm::vec3(position.x,position.y, 0);
	ray.direction = glm::vec3(0, 0, -1);
	
	return ray;
};


