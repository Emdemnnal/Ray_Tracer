#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <utility>
#include "Object.h"

class Ray;

class SphereObject : public Object
{
private:
  glm::vec3 sphereCentre;
  float radius;	

public:
  //glm::ivec3 pointToLine(Ray ray, glm::ivec3 queryPoint);
  // Default Constructor.
  SphereObject();
  // Parameterized Constructor.
  SphereObject(glm::vec3 _sphereCentre, float _radius);
  // Destructor.
  ~SphereObject();
  
  // Calculation Functions.
  intersectionResult intersection(Ray ray, glm::vec3 sphereCentre, float radius);
  glm::vec3 shade(Ray ray, glm::vec3 intersectionPoint);
  
  // Setters.
  void setSphereCentre(glm::vec3 _sphereCentre);
  void setRadius(float _radius);
  
  // Getters.
  glm::vec3 getSphereCentre();
  float getRadius();
};