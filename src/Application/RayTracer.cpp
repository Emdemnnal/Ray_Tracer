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
  std::shared_ptr<SphereObject> sphere = std::make_shared<SphereObject>(glm::vec3(0.0f, 0.0f, -5.0f), glm::vec3(0.0f, 1.0f, 0.0f), 1.0f, lightColour);
  std::shared_ptr<SphereObject> sphere2 = std::make_shared<SphereObject>(glm::vec3(2.0f, 2.0f, -5.0f), glm::vec3(0.0f, 1.0f, 1.0f), 1.0f, lightColour);
  std::shared_ptr<SphereObject> sphere3 = std::make_shared<SphereObject>(glm::vec3(-1.0f, -1.0f, -7.0f), glm::vec3(1.0f, 0.0f, 0.0f), 1.0f, lightColour);
  std::shared_ptr<SphereObject> sphere4 = std::make_shared<SphereObject>(glm::vec3(1.0f, -1.0f, -2.0f), glm::vec3(1.0f, 0.0f, 1.0f), 1.0f, lightColour);
  std::shared_ptr<SphereObject> sphere5 = std::make_shared<SphereObject>(glm::vec3(-3.0f, 3.0f, -11.0f), glm::vec3(1.0f, 1.0f, 0.0f), 1.0f, lightColour);
  std::shared_ptr<SphereObject> sphere6 = std::make_shared<SphereObject>(glm::vec3(-3.7f, 0.0f, -9.0f), glm::vec3(0.0f, 0.0f, 1.0f), 1.0f, lightColour);
  
  // Push back into list of base objects.
  list.push_back(sphere);
  list.push_back(sphere2);
  list.push_back(sphere3);
  list.push_back(sphere4);
  list.push_back(sphere5);
  list.push_back(sphere6);
  
  //Intersection Pass.
  intersectionResult rtn;

  // Iterator parameters based on hit and distance.
  float currentLowestDistance = 1000.0f;
  float currentDistance = 0.0f;
  int numberOfElements = 6;
  int elementNumber;
  bool foundSomething = false;
  glm::vec3 intersectPoint;
  
  for(int i = 0; i < numberOfElements; i++)
  {
	rtn = list.at(i)->intersection(ray);
	currentDistance = rtn.distance;
	
	if(rtn.hit && currentDistance < currentLowestDistance)
	{
      currentLowestDistance = currentDistance;
	  elementNumber = i;
	  foundSomething = true;
	  intersectPoint = rtn.intersectionPoint;
	}
  }
  
  if(foundSomething == true)
  {
    // Replace this part with your call to the closest object's 'shade' function
    // I suggest in your shade function you stick to working in the range of 0 - 1 and then convert here (multiply by 255)
    glm::vec3 surfaceNormal = list.at(elementNumber)->getNormal(intersectPoint);
    pixelColour = list.at(elementNumber)->shade(surfaceNormal);
	pixelColour = pixelColour * 255.0f;
  }
  else
  {
    pixelColour = glm::ivec3(50, 50, 50);
  }
  
  return pixelColour;
}
