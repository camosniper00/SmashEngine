/*
 * SmashGUI.cpp
 *
 *  Created on: Nov 3, 2014
 *      Author: isaac
 */

#include "SmashGUI.h"

namespace smash {

SmashGUI::SmashGUI() {}

SmashGUI::~SmashGUI() {}


SmashGUIComponent::SmashGUIComponent() {
	vboID = 0;
	vaoID = 0;
	position = glm::vec2(0,0);

}

SmashGUIComponent::~SmashGUIComponent() {}

void SmashGUIComponent::setupModel(SmashShaderProgram* shaderProgram) {
	/*
	 * Purpose:
	 * Load the GUI component's geometry to the GPU so we can render it to the screen
	 */

	glGenVertexArrays(1, &vaoID); // generate a Vertex Array Object for our model
	glGenBuffers(1, &vboID);      // generate a Vertex Buffer Object for our model

	glBindVertexArray(vaoID); // bind our created Vertex Array Object so we can use it
	glBindBuffer(GL_ARRAY_BUFFER, vboID); // bind our created Vertex Buffer Object so we can use it

	const GLfloat verts[] = { // create the geometry data for our GUI component
		0,0,0,
		0,1,0,
		1,1,0
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts),verts,GL_STATIC_DRAW); // load the model data to the GPU

	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,12,(void*)0); // tell OpenGL how to use our data

	glBindBuffer(GL_ARRAY_BUFFER, 0); // unbind our Vertex Buffer Object
	glBindVertexArray(0); // unbind our Vertex Array Object
}




} /* namespace smash */
