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
Camera::Camera()
{
  // View Matrix.
  viewMat = glm::mat4(1.0f);
  // Projection Matrix.
  projMat = glm::perspective(glm::radians(45.0f), screenWidth / screenHeight, 0.1f, 100.0f);
  // Inverse Projection Matrix.
  invProjMat = glm::inverse(projMat);
  // Inverse View Matrix.
  invViewMat = glm::inverse(viewMat);

}

Camera::~Camera()
{
  
}

Ray Camera::createRay(glm::ivec2 position)
{
  // Pixel Co-ordinates to map to NDC (Normalised Device Co-ordinates).
  //glm::vec2 pixelCoords = glm::vec2(0, 0);

  // Initialize Near and Far Plane.
  glm::vec4 nearPlane;
  glm::vec4 farPlane;
	
  // Near Plane (z = -1).
  nearPlane.x = farPlane.x = (2.0f * (float)position.x / (float)screenWidth) - 1.0f;
  nearPlane.y = farPlane.y = (2.0f * (float)position.y / (float)screenHeight) - 1.0f;
  
  nearPlane.z = -1.0f;
  nearPlane.w = 1.0f;
  // Far Plane (z = 1).
  farPlane.z = 1.0f;
  farPlane.w = 1.0f;

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
  ray.origin = glm::vec4(nearPlane);
  ray.direction = glm::normalize(glm::vec4(farPlane) - nearPlane);

  return ray;
};


