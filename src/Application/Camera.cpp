#include "Camera.h"
#include "Ray.h"
/*
Ray Camera::createRay(glm::ivec2 position)
{
  // proj = glm::perspective(  );
  Ray ray;
  ray.origin = glm::vec3(position.x,position.y, 0);
  ray.direction = glm::vec3(0, 0, -1);
	
  return ray;
};
*/
Ray Camera::createRay(glm::ivec2 position)
{
	// Pixel Co-ordinates to map to NDC (Normalised Device Co-ordinates).
	glm::vec2 pixelCoords = glm::vec2(0, 0);

	// Near Plane (z = -1).
	glm::vec4 nearPlane = glm:vec4(pixelCoords, -1, 1);
	// Far Plane (z = 1).
	glm::vec4 farPlane = glm::vec4(pixelCoords, 1, 1);

	// Inverse Projection Matrix.
	invProjMat = glm::inverse(projMat);
	// Inverse View Matrix.
	invViewMat = glm::inverse(viewMat);

	// Multiply co-ordinates by Inverse Projection Matrix (Convert to Eye Space).
	nearPlane = invProjMat * nearPlane;
	farPlane = invProjMat * farPlane;

	// Divide co-ordinates by w. (Convert from Left-Handed to Right-Handed system).
	nearPlane = nearPlane / nearPlane.w;
	farPlane = farPlane / farPlane.w;

	// Multiply co-ordinates by Inverse View Matrix (Convert from Eye Space to World Space).
	nearPlane = invViewMat * nearPlane;
	farPlane = invViewMat * farPlane;

	// Returned ray.
	Ray ray;
	ray.origin = glm::vec3(nearPlane);
	ray.direction = glm::vec3(0, 0, -1);

	return ray;
};


