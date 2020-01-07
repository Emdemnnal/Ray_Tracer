#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <utility>
#include "Object.h"

class Ray;

class SphereObject : public Object
{
private:
  glm::vec3 sphereCentre;
  glm::vec3 sphereColour;
  float radius;	
  
  glm::vec3 lightColour;

public:
  // Default Constructor.
  SphereObject();
  // Parameterized Constructor.
  SphereObject(glm::vec3 _sphereCentre, glm::vec3 sphereColour, float _radius, glm::vec3 lightColour);
  // Destructor.
  ~SphereObject();
  
  // Calculation Functions.
  intersectionResult intersection(Ray ray);
  glm::vec3 shade(glm::vec3 sphereNormal);
  glm::vec3 getNormal(glm::vec3 intersectionPoint);
};