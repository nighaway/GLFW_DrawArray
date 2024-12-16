#include<iostream>
#include"glframework/core.h"
#include<string>
#include"wrapper/checkerror.h"
#include"application/application.h"
#include"glframework/shader.h";
#include"glframework/texture.h"
#include"application/camera/perspectivecamera.h"
#include"application/camera/trackballcamera.h"
#include"application/camera/gamecameracontrol.h"
#include"glframework/geometry.h"

Geometry* geometry = nullptr;
Texture* texture = nullptr;
Shader* shader = nullptr;
glm::mat4 transform(1.0);
//glm::mat4 viewMatrix(1.0);
//glm::mat4 orthoMatrix(1.0);
//glm::mat4 perspectiveMatrix(1.0f);
PerspectiveCamera* camera = nullptr;
GameCameraControl* cameracontrol = nullptr;


void Onresize(int width,int height) {
    std::cout << "窗体最新大小：" << width << "," << height << std::endl;
}

void Onkey(int key,int action,int mods) {
    cameracontrol->onKey(key, action, mods);
}

void Onmouse(int button, int action, int mods) {
    double x, y;
    app->getCursorPosition(&x, &y);
    cameracontrol->onMouse(button, action, x, y);
}

void Oncursor(double xpos, double ypos) {
    cameracontrol->onCursor(xpos, ypos);
}

void Onscroll(double offset) {
    cameracontrol->onScroll(offset);
}

void doTransform() {
    transform = glm::rotate(glm::mat4(1.0f),glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
}

void doTranslation() {
    transform = glm::translate(glm::mat4(1.0f), glm::vec3(0.5,0.0,0.0));
}

void doScale() {
    transform = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f, 0.5f, 1.0f));
}



//void prepare() {
//	//float positions[] = {
//	//	-0.5f,-0.5f,0.0f,
//	//	0.5f,-0.5f,0.0f,
//	//	0.0f,0.5f,0.0f
//	//};
//
//	float positions[] = {
//		-1.0f,-0.0f,0.0f,
//		1.0f,0.0f,0.0f,
//		0.0f,1.0f,0.0f
//	};
//	float colors[] = {
//		1.0f,0.0f,0.0f,
//		0.0f,1.0f,0.0f,
//		0.0f,0.0f,1.0f
//	};
//
//	float uvs[] = {
//	0.0f, 0.0f,
//	1.0f, 0.0f,
//	0.5f, 1.0f,
//	};
//
//
//	unsigned int indices[] = {
//		0, 1, 2
//	};
//
//	GLuint positionvbo ,colorvbo, uvVbo;
//
//	glGenBuffers(1, &positionvbo);
//	glBindBuffer(GL_ARRAY_BUFFER, positionvbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
//
//
//	glGenBuffers(1, &colorvbo);
//	glBindBuffer(GL_ARRAY_BUFFER, colorvbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
//
//	glGenBuffers(1, &uvVbo);
//	glBindBuffer(GL_ARRAY_BUFFER, uvVbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);
//
//
//	GLuint ebo;
//	glGenBuffers(1, &ebo);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	vao = 0;
//	glGenVertexArrays(1, &vao);
//	glBindVertexArray(vao);
//
//	glBindBuffer(GL_ARRAY_BUFFER, positionvbo);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
//
//
//
//
//	glBindBuffer(GL_ARRAY_BUFFER, uvVbo);
//	glEnableVertexAttribArray(2);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);
//
//
//	glBindVertexArray(0);
//}

void prepareVao() {
    geometry = Geometry::creatBox(6.0f);
    //geometry = Geometry::creatSphere(6.0f);
}

void prepareShader() {
    shader = new Shader("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl");
}

void prepareTexture() {
    texture = new Texture("assets/textures/qtw.jpg", 0);
}


void prepareCamera() {
    camera = new PerspectiveCamera(60.0f,
                                   (float)app->getWidth() / (float)app->getHeight(),
                                   0.1f,
                                   1000.0f
    );
    cameracontrol = new GameCameraControl();
    cameracontrol->setCamera(camera);
}

void prepareState() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

//void prepareOrtho() {
//	orthoMatrix = glm::ortho(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f,2.0f);
//}
//
//void preparePerspective() {
//	perspectiveMatrix = glm::perspective(glm::radians(60.0f), (float)app->getWidth()/(float)app->getHeight(),1.0f,1000.0f);
//}

void render() {
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT));
    shader->begin();
    shader->setInt("sampler",0);
    shader->setMatrix4x4("transform", transform);
    shader->setMatrix4x4("viewMatrix", camera->getViewMatrix());
    shader->setMatrix4x4("projectionMatrix", camera->getProjectMatrix());
    GL_CALL(glBindVertexArray(geometry->getVao()));
    glDrawElements(GL_TRIANGLES, geometry->getmIndicesCount(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    shader->end();
}

int main() {
    if (!app->init(800, 600)) {
        return -1;
    }

    app->setResizeCallback(Onresize);
    app->setKeyBoardCallback(Onkey);
    app->setMouseCallback(Onmouse);
    app->setCursorCallback(Oncursor);
    app->setScrollCallback(Onscroll);


    GL_CALL(glViewport(0,0,800,600));
    GL_CALL(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));

    prepareShader();
    prepareVao();
    prepareTexture();
    prepareCamera();
    prepareState();

    while (app->update()) {
        cameracontrol->update();
        render();
    }

    app->destroy();
    delete texture;
    return 0;
}