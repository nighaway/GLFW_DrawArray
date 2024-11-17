#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include<assert.h>
#include"wrapper/checkError.h"
#include"application/Application.h"

GLuint vao = 0,program=0;

void frameBufferSizeCallback(GLFWwindow* window,int width,int height) {
	std::cout << "窗体最新大小：" << width << "," << height << std::endl; 
}

void keyCallback(GLFWwindow* window,int key,int scancode,int action,int mods) {
	std::cout << "按下了：" << key<<std::endl;
	std::cout << "action：" << action<<std::endl;
	std::cout << "mods：" << mods<<std::endl;
}

void Onresize(int width,int height) {
    GL_CALL(glViewport(0,0,width,height));
    std::cout<<"Onresize"<<std::endl;
}

void Onkey(int key,int action,int mods) {
    std::cout<<key<<std::endl;
}
	

void preparesingleBuffer() {
	float positions[] = {
		-0.5f,-0.5f,0.0f,
		0.5,-0.5f,0.0f,
		0.0f,0.5f,0.0f
	};
	float colors[] = {
		1.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,
		0.0f,0.0f,1.0f
	};
	GLuint posvbo = 0, colorvbo = 0; 
	GL_CALL(glGenBuffers(1, &posvbo));
	GL_CALL(glGenBuffers(1, &colorvbo));

	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, posvbo));
	GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW));

	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, colorvbo));
	GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW));

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, posvbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, colorvbo);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glBindVertexArray(0);
}

void prepareInterleavedBuffer() {
	float vertices[]{
		-0.5f,-0.5f,0.0f,1.0f,0.0f,0.0f,
		0.5f,-0.5f,0.0f,0.0f,1.0f,0.0f,
		0.0f,0.5f,0.0f,0.0f,0.0f,1.0f
	};
	GLuint vbo = 0;
	GL_CALL(glGenBuffers(1, &vbo));
	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, vbo));
	GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW));


	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	 
    glBindVertexArray(0);
}

void prepareShader()  {
    const char* vertexShaderSource=
            "#version 460 core\n"
            "layout (location=0) in vec3 aPos;\n"
            "void main()\n"
            "{\n"
            "  gl_Position=vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";
    const char* fragmentShaderSource=
            "#version 330 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
            "  FragColor=vec4(1.0f,0.5f,0.2f,1.0f);\n"
            "}\n\0";

    GLuint vertex,fragment;
    vertex=glCreateShader(GL_VERTEX_SHADER);
    fragment=glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertex,1,&vertexShaderSource,NULL);
    glShaderSource(fragment,1,&fragmentShaderSource,NULL);

    int success=0;
    char infoLog[1024];
    glCompileShader(vertex);
    glGetShaderiv(vertex,GL_COMPILE_STATUS,&success);
    if(!success) {
         glGetShaderInfoLog(vertex,1024,NULL,infoLog);
         std::cout<<"Error:SHADER COMPILE ERROR --VERTEX"<<"\n"<<infoLog<<std::endl;
    }

    glCompileShader(fragment);
    glGetShaderiv(fragment,GL_COMPILE_STATUS,&success);
    if(!success) {
        glGetShaderInfoLog(fragment,1024,NULL,infoLog);
        std::cout<<"Error:SHADER COMPILE ERROR --FRAGMENT"<<"\n"<<infoLog<<std::endl;
    }

    program=glCreateProgram();

    glAttachShader(program,vertex);
    glAttachShader(program,fragment);

    glLinkProgram(program);
    glGetProgramiv(program,GL_LINK_STATUS,&success);
    if(!success) {
        glGetProgramInfoLog(program,1024,NULL,infoLog);
        std::cout<<"Error:SHADER LINK ERROR "<<"\n"<<infoLog<<std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

}

void render() {
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
    glUseProgram(program);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES,0,3);

}

int main() {

    app->setResizeCallback(Onresize);
    app->setKeyBoardCallback(Onkey);
    if(!app->init(800,600)) {
        return -1;
    }
	GL_CALL(glViewport(0, 0, 800, 600));
	GL_CALL(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));

    prepareShader();
    prepareInterleavedBuffer();
	while (app->update()) {
        render();
	}

    app->destroy();
	return 0;
}