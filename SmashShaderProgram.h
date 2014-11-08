/*
 * SmashShaderProgram.h
 *
 *  Created on: Nov 5, 2014
 *      Author: isaac
 */

#ifndef SMASHSHADERPROGRAM_H_
#define SMASHSHADERPROGRAM_H_

namespace smash {

class SmashShaderProgram {
	int programID;
	int vertexShaderID;
	int fragmentShaderID;
public:
	SmashShaderProgram();
	virtual ~SmashShaderProgram();
};

} /* namespace smash */

#endif /* SMASHSHADERPROGRAM_H_ */
