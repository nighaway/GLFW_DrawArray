#pragma once
#include "core.h"

class Shader {
public:
	Shader(const char* vertexPath,const char* fragmentPath);
	~Shader();
	void begin();
	void end();
	void checkShaderError(GLuint target,std::string type);
	void setFloat(const std::string& name, float value);
	void setVector3(const std::string& name, float x, float y,float z);
	void setVector3(const std::string& name, const float* values);
	void setInt(const std::string& name, int value);
	void setMatrix4x4(const std::string& name, glm::mat4 value);
private:
	GLuint mProgram{ 0 };
};