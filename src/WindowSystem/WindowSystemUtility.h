#include "../includes.h"
#include "../includes/GLFW/glfw3.h"
namespace WindowSystemUtility {
    void initialise_glfw();
    void glfw_error_callback(int error_code, const char* error_msg);
    void frame_buffer_size_callback(GLFWwindow* window, int width, int height);
}