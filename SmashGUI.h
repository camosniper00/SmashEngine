/*
 * SmashGUI.h
 *
 *  Created on: Nov 3, 2014
 *      Author: isaac
 */
#include <vector>
#include <glm/glm.hpp>
#include "SmashShaderProgram.h"
#include <GL/glew.h>

#ifndef SMASHGUI_H_
#define SMASHGUI_H_

namespace smash {

enum SmashComponentType {SE_SQUARE_BUTTON};

class SmashGUIComponent {

	GLuint vboID;
	GLuint vaoID;
	glm::vec2 position;
	std::vector<float> dimensions;
public:
	SmashGUIComponent();
	void setupModel(SmashShaderProgram* shaderProgram); // load the GUI component's geometry to the GPU
	virtual ~SmashGUIComponent();
};

class SmashGUI {
	SmashShaderProgram guiShaderProgram; // shader program to render our GUI
	std::vector<SmashGUIComponent> nodes; // buttons, drop-down menus, etc
public:
	SmashGUI();
	virtual ~SmashGUI();
};

} /* namespace smash */

#endif /* SMASHGUI_H_ */
