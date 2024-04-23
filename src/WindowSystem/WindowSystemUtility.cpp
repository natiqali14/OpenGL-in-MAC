#include "WindowSystemUtility.h"
void WindowSystemUtility::initialise_glfw() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

// setting error callback msg for GLFW errors
glfwSetErrorCallback(&WindowSystemUtility::glfw_error_callback);

}

void WindowSystemUtility::glfw_error_callback(int error_code, const char* error_msg) {
    std::cerr << "GLFW ERROR : code:" << error_code << " " << "Msg:" << error_msg << "\n";
}

void WindowSystemUtility::frame_buffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}