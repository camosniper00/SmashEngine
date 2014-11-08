/*
 * BaseEngine.cpp
 *
 *  Created on: Nov 2, 2014
 *      Author: isaac
 */
#include "BaseEngine.h"

BaseEngine::BaseEngine() {
	BaseEngine::window = nullptr; // we'll initialize the window later
}
BaseEngine::~BaseEngine() {}

GLFWwindow* setupDisplay(int window_width, int window_height, const char* window_title) {
	if (!glfwInit()) { // initialize GLFW
		std::cerr << "Failed to initialize GLFW3!" << std::endl;
		exit(-1);
	}
	glfwWindowHint(GLFW_SAMPLES, 1); // No multisampling (no antialiasing)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  //  OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);  //    version 3.2
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // stops Macs from complaining
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // we want the OpenGL core profile

	GLFWwindow* window = glfwCreateWindow(window_width, window_height, window_title, nullptr, nullptr); // create the window we'll draw stuff in

	if (!window) { // checking that the window was successfully created
		std::cerr << "Failed to create GLFW3 window!" << std::endl;
		exit(-1);
	}
	glfwMakeContextCurrent(window); // GLEW will not work without this
	glewExperimental = true; // needed for OpenGL core profile
	if (glewInit() != GLEW_OK) { // initialize GLEW
		std::cerr << "Failed to initialize GLEW!" << std::endl;
		exit(-1);
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE); // ensure that pressed keys are detected

	return window;
}
void BaseEngine::init() {
	std::clog << "Initializing SmashEngine..." << std::endl;
	BaseEngine::window = setupDisplay(800, 600, "SmashEngine");
}
void cleanup() {
	glfwTerminate(); // clean up after our window system
}
void BaseEngine::run() { // insert coin
	preInit(); // override me
	BaseEngine::init();
	postInit(); // override me
	glClearColor(1,1,1,1); // set background to white
	while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	cleanup();
}
