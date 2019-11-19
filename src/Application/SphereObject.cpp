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
intersectionResult SphereObjectObject::intersection(Ray ray, glm::ivec3 sphereCentre, float _radius)
{
  glm::ivec3 closestPoint;
  glm::ivec3 calculatedVector;
  float calculatedDistance;
  
  // Finds closest point to line (X).
  closestPoint = ray + (glm::dot((sphereCentre - ray.origin), ray.direction) * ray.direction);
  // ||P - X|| <= R
  calculatedVector = glm::distance(sphereCentre, calculatedVector);
  // d = ||P - a - ((P-a) . n)n||
  calculatedDistance = glm::length((sphereCentre - ray.origin - (glm::dot((sphereCentre - ray.origin, ray.direction))) * ray.direction));
  // sqrt(r*2 - d*2).
  float x = glm::sqrt((glm::pow(_radius, 2) - glm::pow(calculatedDistance, 2)));
  
  // Allows return of two values.
  intersectionResult rtn;
  
  if(calculatedVector <= _radius)
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
  
  return result;
}

void SphereObject::shade(Ray ray, glm::vec3 distance)
{
  glm::ivec3 calculatedPixelColour;
  
  return calculatedPixelColour;
}
