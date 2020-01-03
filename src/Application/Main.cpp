#include <cmath>
#include <mutex>
#include <thread>
#include <vector>
#include <iostream>
#include <memory>

// MCG library from Level 4 by Leigh McLoughlin
#include "../MCG/MCG_GFX_Lib.h"

#include "Ray.h"
#include "Camera.h"
#include "RayTracer.h"
#include "SphereObject.h"

// Function Prototyping.
void rayTracer();
void threadedRayTracer(int _startXPos, int _endXPos);

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

	// Sets every pixel to the same colour
	// parameters are RGBA, numbers are from 0 to 255
	MCG::SetBackground( glm::ivec3(0,0,0) );

	// Preparing a position to draw a pixel
	//glm::ivec2 pixelPosition = windowSize / 2;
	
	// Preparing a colour to draw
	// Colours are RGB, each value ranges between 0 and 255
	//glm::ivec3 pixelColour( 255, 0, 0 );


	// Draws a single pixel at the specified coordinates in the specified colour!
	//MCG::DrawPixel( pixelPosition, pixelColour );

	// Do any other DrawPixel calls here
	// ...
	
	int numberOfThreads = 2;
	
	int startXPos = 0;
	int endXPos = 640;
	  
	int offset = 640 / numberOfThreads;
	
	// Vector of threads.
	//std::vector<std::thread> threads;
	
	// Vector of threads.
	//std::vector<std::shared_ptr<std::thread>> threads;
	
	/*
	// Array of threads.
	std::thread threads[8];
	
	// Filling up the vector/array of threads.
	for(int i = 0; i < 8; i++)
	{
	  endXPos = startXPos + offset;
	  threads[i] = std::thread(threadedRayTracer, startXPos, endXPos);
	  startXPos = startXPos + offset;
	}
	*/
	
	
	// Vector of threads.
	std::vector<std::thread> threads;
	
	// Filling up the vector/array of threads.
	for(int i = 0; i < numberOfThreads; i++)
	{
	  endXPos = startXPos + offset;
	  
	  //std::thread thd(threadedRayTracer, startXPos, endXPos);
	  
	  //threads.push_back(thd);

	  threads.push_back(std::thread(threadedRayTracer, startXPos, endXPos));
	  
	  startXPos = startXPos + offset;
	}
	
	
	/*
	// Filling up the vector/array of threads.
	for(int i = 0; i < threads.size(); i++)
	{
	  endXPos = startXPos + offset;
	  
	  // Shared pointer thread.
	  std::shared_ptr<std::thread> thd;
	  
	  // Call the function.
	  thd = std::make_shared<std::thread>(threadedRayTracer, startXPos, endXPos);
	  
	  // Push back onto vector of threads.
	  threads.push_back(thd);
	  
	  startXPos = startXPos + offset;
	}
	*/
	
	// Synchronize threads.
	for(int i = 0; i < numberOfThreads; i++)
	{
	  threads[i].join();
	}
	
	//rayTracer();
	
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

void threadedRayTracer(int _startXPos, int _endXPos)
{
  int startXPos = _startXPos;
  int endXPos = _endXPos;
	
  Camera myCamera;
  RayTracer myTracer;
	
  for(int h = 0; h < 480; ++h)
  {
	for(int w = startXPos; w < endXPos; ++w)
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