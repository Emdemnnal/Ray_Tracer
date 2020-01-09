#include <cmath>
#include <mutex>
#include <thread>
#include <vector>
#include <iostream>
#include <memory>
#include <ctime>

// MCG library from Level 4 by Leigh McLoughlin
#include "../MCG/MCG_GFX_Lib.h"

#include "Ray.h"
#include "Camera.h"
#include "RayTracer.h"
#include "SphereObject.h"

// Function Prototyping.
void rayTracer();
void threadedRayTracer(int _startXPos, int _endXPos, Camera &myCamera, RayTracer &myTracer);

// Mutex.
std::mutex mtx;

int main( int argc, char *argv[] )
{
	// Variable for storing window dimensions
	glm::ivec2 windowSize( 640, 480 );

	// Call MCG::Init to initialise and create your window
	// Tell it what size you want the window to be
	if( !MCG::Init( windowSize ) )
	{
		// We must check if something went wrong
		// (this is very unlikely)
		return -1;
	}
	
	// Do any other DrawPixel calls here
	// ...
	
	// Parameters.
	int numberOfThreads = 8;
	std::cout << "The number of threads: " << numberOfThreads << std::endl;
	
	int startXPos = 0;
	int endXPos = 640;
	  
	int offset = 640 / numberOfThreads;
	
	// Vector of threads.
	std::vector<std::thread> threads;
	
	// Start.
	clock_t startTime = clock();
	
	// Scene.
	Camera myCamera;
    RayTracer myTracer;
	
	// Filling up the vector/array of threads.
	for(int i = 0; i < numberOfThreads; i++)
	{
	  endXPos = startXPos + offset;

	  // Pass in the scene as a parameter, so the threads are sharing the same scene
	  // THis means you can initialise locations to random values for example

	  // This method works because std::thread is an rvalue, so the push_back uses a std::move rather than a copy (can't copy a thread object).
	  threads.push_back(std::thread(threadedRayTracer, startXPos, endXPos, myCamera, myTracer));
	  
	  startXPos = startXPos + offset;
	}
	
	// Synchronize threads.
	for(int i = 0; i < numberOfThreads; i++)
	{
	  threads[i].join();
	}
	
	// End.
	clock_t finishTime = clock();
	double timeTaken = double(finishTime - startTime);
	std::cout << "Time taken to finish rendering (ms): " << timeTaken << std::endl;
	
	// Displays drawing to screen and holds until user closes window
	// You must call this after all your drawing calls
	// Program will exit after this line
	return MCG::ShowAndHold();
}

void rayTracer()
{
  Camera myCamera;
  RayTracer myTracer;
	
  for(int h = 0; h < 480; ++h)
    {
	  for(int w = 0; w < 640; ++w)
	  {
			glm::ivec2 currentPixelPosition = glm::ivec2(w, h);
			Ray currentRay = myCamera.createRay(currentPixelPosition);
			glm::ivec3 pixelColour = myTracer.trace(currentRay);
			MCG::DrawPixel(currentPixelPosition, pixelColour);
	  }
	}
}

void threadedRayTracer(int _startXPos, int _endXPos, Camera &myCamera, RayTracer &myTracer)
{
  for(int h = 0; h < 480; ++h)
  {
	for(int w = _startXPos; w < _endXPos; ++w)
	{
	  glm::ivec2 currentPixelPosition = glm::ivec2(w, h);
	  Ray currentRay = myCamera.createRay(currentPixelPosition);
	  glm::ivec3 pixelColour = myTracer.trace(currentRay);
			
	  mtx.lock();
	  MCG::DrawPixel(currentPixelPosition, pixelColour);
	  mtx.unlock();
	}
  }
  
  
}