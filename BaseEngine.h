/*
 * BaseEngine.h
 *
 *  Created on: Nov 2, 2014
 *      Author: isaac
 */
#include <iostream>
#include <cstdlib>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "SmashGUI.h"

#ifndef BASEENGINE_H_
#define BASEENGINE_H_

class BaseEngine {
	GLFWwindow* window;
public:
	BaseEngine();
	smash::SmashGUI* loadGUI(std::string filename);
	virtual void preInit() = 0; /*
								 * Function ran before initialization
								 * (before window creation, resource loading, etc)
								 * must be overriden by user of SmashEngine
								 */
	virtual void postInit() = 0; /*
	 	 	 	 	 	    	  * Function ran after initialization, but before main game loop
								  * (window has been created, resources have been loaded)
								  * must be overriden by user of SmashEngine
								  */
	void run(); // insert coin
	virtual ~BaseEngine();
private:
	void init();
};

#endif /* BASEENGINE_H_ */
