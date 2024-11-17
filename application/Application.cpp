#include "Application.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>

Application* Application::mInstance= nullptr;
Application* Application::getInstance() {
    if(mInstance== nullptr) {
        mInstance=new Application();
    }

    return mInstance;
}

Application::Application() {

}

Application::~Application() {

}

bool Application::init(const int& width,const int& height) {
    mWidth=width,mHeight=height;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    mWindows = glfwCreateWindow(mWidth, mHeight, "OpenGL", NULL, NULL);
    if(mWindows==NULL) {
        return false;
    }
    glfwMakeContextCurrent(mWindows);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout<<"Failed to initialize GLAD"<<std::endl;
        return false;
    }

    glfwSetFramebufferSizeCallback(mWindows,frameBufferSizeCallback);
    glfwSetKeyCallback(mWindows, keyCallback);
    return true;
}

bool Application::update() {
    if(glfwWindowShouldClose(mWindows)) {
        return false;
    }
    glfwPollEvents();
    glfwSwapBuffers(mWindows);
    return 1;
}

void Application::destroy() {
    glfwTerminate();
}

void Application::frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
    std::cout<<"Risize"<<std::endl;
    if(Application::getInstance()->mResizeCallback!= nullptr) {
        Application::getInstance()->mResizeCallback(width,height);
    }
}

void Application::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if(Application::getInstance()->mKeyBoardCallback!= nullptr) {
        Application::getInstance()->mKeyBoardCallback(key, action, mods);
    }
}