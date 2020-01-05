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
  sphereColour = glm::vec3(255, 0, 0);
  radius = 2.0f;
  lightColour = glm::vec3(255, 255, 255);
}

SphereObject::SphereObject(glm::vec3 _sphereCentre, glm::vec3 _sphereColour, float _radius, glm::vec3 _lightColour)
{
  // For setting private variables of an instance of a SphereObject when constructed.
  sphereCentre = _sphereCentre;
  sphereColour = _sphereColour;
  radius = _radius;
  lightColour = _lightColour;
}

SphereObject::~SphereObject()
{
  
}

intersectionResult SphereObject::intersection(Ray ray)
{
  /*
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
  */

  // Ray's origin.
  glm::vec3 a = ray.origin;
  // Ray's direction.
  glm::vec3 n = ray.direction;
  // Centre of sphere.
  glm::vec3 P = sphereCentre;
  // Radius of sphere.
  float r = radius;
  // Calculated distance.
  float d;
  // Closest point X on the line to a query point P.
  glm::vec3 X; // X = a + ((P - a) . n)n
  glm::vec3 X2; // ((P - a) . n)n
  float X3; // ((P - a) . n)
  
  // X = a + ((P - a) . n)n
  X = a + (glm::dot((P - a), n) * n);
  // ((P - a) . n)n
  X2 = (glm::dot((P - a), n) * n);
  // ((P - a) . n)
  X3 = glm::dot((P - a), n);
  // d = ||P - a - ((P-a) . n)n||
  d = glm::length(P - a - X2);
  
  // Calculated value x.
  // x = sqrt(r*2 - d*2)
  float x = glm::sqrt(glm::pow(r, 2) - glm::pow(d, 2));
  
  // First intersection point. 
  // a + (((P - a) . n) - x)n
  glm::vec3 iPoint =  a + (X3 - x) * n;
  
  // Allows return of two values.
  intersectionResult rtn;
  
  if(d <= r)
  {
    // Ray intersects sphere.
	rtn.hit = true;
	rtn.distance = (X3 - x);
	rtn.intersectionPoint = iPoint;
	return rtn;
  }
  else
  {
    // Ray doesn't intersect sphere.
	rtn.hit = false;
  }
  
  return rtn;
}

glm::vec3 SphereObject::shade(glm::vec3 surfaceNormal)
{
  // L = (wi . N)LiKd
  // L
  glm::vec3 calculatedPixelColour = sphereColour;
  
  // Vector pointing towards the light source.
  glm::vec3 wi = glm::vec3(100, 100, -10);
  // Normalize as it is a unit vector.
  glm::normalize(wi);
  // Light Colour (Li).
  glm::vec3 Li = lightColour;
  // Material/Sphere Colour (Kd).
  glm::vec3 Kd = sphereColour;
  // Make sure dot product is always >= 0.
  float dotProductCheck = glm::dot(wi, surfaceNormal);
  // Do the full calculation.
  calculatedPixelColour = glm::max(dotProductCheck, 0.0f) * Li * Kd;
  
  return calculatedPixelColour;
}

glm::vec3 SphereObject::getNormal(glm::vec3 intersectionPoint)
{
  // Get the normal of a point on the sphere object.
  glm::vec3 normal = intersectionPoint - sphereCentre;
  // Normalize this calculated vector.
  normal = glm::normalize(normal);
  
  return normal;
}

