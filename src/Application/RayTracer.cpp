#include "RayTracer.h"
#include "Camera.h"
#include "Ray.h"
#include "SphereObject.h"
#include "Object.h"

glm::ivec3 RayTracer::trace(Ray ray)
{
  // Returned pixelColour.
  glm::vec3 pixelColour(1, 0, 0); // Red Pixels.
  glm::vec3 lightColour(1, 1, 1); // White Light.
	
  // Sphere Settings.
  // SphereObject sphere(sphereCentre, sphereColour, radius, lightColour).
  std::shared_ptr<SphereObject> sphere = std::make_shared<SphereObject>(glm::vec3(0, 0, -10), glm::vec3(0, 255, 0), 1.0f, lightColour);
  std::shared_ptr<SphereObject> sphere2 = std::make_shared<SphereObject>(glm::vec3(20, 20, -30), glm::vec3(0, 0, 255), 1.0f, lightColour);
  std::shared_ptr<SphereObject> sphere3 = std::make_shared<SphereObject>(glm::vec3(-20, -20, -50), glm::vec3(255, 0, 0), 1.0f, lightColour);
  
  // Push back into list of base objects.
  list.push_back(sphere);
  list.push_back(sphere2);
  list.push_back(sphere3);
  
  //Intersection Pass.
  intersectionResult rtn;

  float currentLowestDistance = 1000.0f;
  float currentDistance = 0.0f;
  int elementNumber;
  
  for(int i = 0; i < 2; i++)
  {
	rtn = list.at(i)->intersection(ray);
	currentDistance = rtn.distance;
	
	if(currentDistance < currentLowestDistance)
	{
      currentLowestDistance = currentDistance;
	  elementNumber = i;
	}
	else
	{
      rtn = list.at(elementNumber)->intersection(ray);
	}
  }
  
  if(rtn.hit == true)
  {
    // Replace this part with your call to the closest object's 'shade' function
    // I suggest in your shade function you stick to working in the range of 0 - 1 and then convert here (multiply by 255)
    glm::vec3 surfaceNormal = list.at(elementNumber)->getNormal(rtn.intersectionPoint);
    pixelColour = list.at(elementNumber)->shade(surfaceNormal);
	pixelColour = pixelColour * 255.0f;
  }
  else
  {
    pixelColour = glm::ivec3(0, 0, 0);
  }
  
  // Your ray tracer class needs to contain all the objects in your scene (e.g. a list of some sort)
  // Here, it needs to go through that list and find the closest object that intersects with the ray
		// (Two stages: find the closest object, the get the colour of that closest object)
  // Once you've got the closest sphere, you need to find the colour
  // I suggest you call a 'shade' function on that sphere, which returns a colour
  // This trace function then returns the colour
  // It's then in the sphere's trace function that you do the shading
/*
  //rtn = sphere.intersection(ray); 
  // Intersection result decides returned pixelColour.
   if(rtn.hit == true)
      {
	    // Replace this part with your call to the closest object's 'shade' function
	    // I suggest in your shade function you stick to working in the range of 0 - 1 and then convert here (multiply by 255)
        glm::vec3 surfaceNormal = sphere.getNormal(rtn.intersectionPoint);
        pixelColour = sphere.shade(surfaceNormal);
	    pixelColour = pixelColour * 255.0f;
	  
        //pixelColour = glm::ivec3(0, 255, 155);
      }
      else
      {
        pixelColour = glm::ivec3(0, 0, 0);
      }
*/	
  return pixelColour;
}
