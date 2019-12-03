#include "SphereObject.h"
#include "Ray.h"
/*
glm::ivec3 SphereObject::pointToLine(Ray ray, glm::ivec3 queryPoint)
{
  glm::ivec3 closestPoint;
  
  closestPoint = ray + (glm::dot((queryPoint - ray.origin), ray.direction) * ray.direction);
  
  returns closestPoint;
}
*/
SphereObject::SphereObject()
{
  // Default SphereObject private variables when default constructed.
  sphereCentre = glm::vec3(0, 100, 100);
  radius = 2.0f;
}

SphereObject::SphereObject(glm::vec3 _sphereCentre, float _radius)
{
  // For setting private variables of an instance of a SphereObject when constructed.
  setSphereCentre(_sphereCentre);
  setRadius(_radius);
}

SphereObject::~SphereObject()
{
  
}

intersectionResult SphereObject::intersection(Ray ray, glm::vec3 sphereCentre, float radius)
{
  glm::ivec3 closestPoint;
  glm::ivec3 calculatedVector;
  float calculatedDistance;
  
  // Finds closest point to line (X).
  closestPoint = ray.origin + (glm::dot((sphereCentre - ray.origin), ray.direction) * ray.direction);
  // ||P - X|| <= R
  //calculatedVector = glm::distance(sphereCentre, closestPoint);
  // d = ||P - a - ((P-a) . n)n||
  calculatedDistance = glm::length((sphereCentre - ray.origin - glm::dot(sphereCentre - ray.origin, ray.direction) * ray.direction));
  // sqrt(r*2 - d*2).
  float x = glm::sqrt((glm::pow(radius, 2) - glm::pow(calculatedDistance, 2)));
  
  // Allows return of two values.
  intersectionResult rtn;
  
  if(calculatedDistance <= radius)
  {
    // Ray intersects sphere.
	rtn.hit = true;
	rtn.distance = glm::dot((sphereCentre - ray.origin), ray.direction) - x;
	
	return rtn;
  }
  else
  {
    // Ray doesn't intersect sphere.
	rtn.hit = false;
	rtn.distance = 0;
  }
  
  return rtn;
}

glm::vec3 SphereObject::shade(Ray ray, glm::vec3 distance)
{
  glm::vec3 calculatedPixelColour;
  
  return calculatedPixelColour;
}

void SphereObject::setSphereCentre(glm::vec3 _sphereCentre)
{
  sphereCentre = _sphereCentre;
}

void SphereObject::setRadius(float _radius)
{
  radius = _radius;
}

glm::vec3 SphereObject::getSphereCentre()
{
  return sphereCentre;
}
float SphereObject::getRadius()
{
  return radius;
}
