#include "RayTracer.h"
#include "Camera.h"
#include "Ray.h"
#include "SphereObject.h"

glm::ivec3 RayTracer::trace(Ray ray)
{
  // Returned pixelColour.
  glm::ivec3 pixelColour(255, 0, 0); // Red Pixels.
	
  // Sphere Settings.
  SphereObject sphere(glm::vec3(0, 0, -10), 1.0f);
  

  // Your ray tracer class needs to contain all the objects in your scene (e.g. a list of some sort)
  // Here, it needs to go through that list and find the closest object that intersects with the ray
		// (Two stages: find the closest object, the get the colour of that closest object)
  // Once you've got the closest sphere, you need to find the colour
  // I suggest you call a 'shade' function on that sphere, which returns a colour
  // This trace function then returns the colour
  // It's then in the sphere's trace function that you do the shading

  //Intersection Pass.
  intersectionResult rtn;
  rtn = sphere.intersection(ray, sphere.getSphereCentre(), sphere.getRadius());
  
  // Intersection result decides returned pixelColour.
  if(rtn.hit == true)
  {
	  // Replace this part with your call to the closest object's 'shade' function
	  // I suggest in your shade function you stick to working in the range of 0 - 1 and then convert here (multiply by 255)
    pixelColour = glm::ivec3(0, 255, 155);
  }
  else
  {
    pixelColour = glm::ivec3(0, 0, 0);
  }
	
  return pixelColour;
}
