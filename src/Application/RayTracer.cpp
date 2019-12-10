#include "RayTracer.h"
#include "Camera.h"
#include "Ray.h"
#include "SphereObject.h"

glm::ivec3 RayTracer::trace(Ray ray)
{
  // Returned pixelColour.
  glm::ivec3 pixelColour(255, 0, 0); // Red Pixels.
	
  // Sphere Settings.
  SphereObject sphere(glm::vec3(300, 300, 300), 100.0f);
  
  //Intersection Pass.
  intersectionResult rtn;
  rtn = sphere.intersection(ray, sphere.getSphereCentre(), sphere.getRadius());
  
  // Intersection result decides returned pixelColour.
  if(rtn.hit == true)
  {
    pixelColour = glm::ivec3(0, 255, 155);
  }
  else
  {
    pixelColour = glm::ivec3(0, 0, 0);
  }
	
  return pixelColour;
}
