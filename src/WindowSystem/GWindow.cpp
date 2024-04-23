#include "GWindow.h"
#include "WindowSystemUtility.h"
#include "../EventSystem/EventSystemHelper.h"
GWindow::GWindow(u16 w, u16 h, std::string w_name)
: width(w)
, height(h)
, window_name(std::move(w_name))
{
    // window creation
    window = glfwCreateWindow(width, height, window_name.c_str(), nullptr, nullptr);
    // error on failure
    if(window == NULL) throw std::runtime_error("GLFW window creation failed");
    // for now when create a new GLFW window, this window will be current context for opneGL.
    glfwMakeContextCurrent(window); 
    // frame buffer size callback
    glfwSetFramebufferSizeCallback(window, &WindowSystemUtility::frame_buffer_size_callback);

    // For now following settings are for all windows
    glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE,1);
    glfwSetKeyCallback(window, GWindow::key_input_callback);

}

void GWindow::make_context_current()
{
    glfwMakeContextCurrent(window);
}

bool GWindow::should_close_window()
{
    return glfwWindowShouldClose(window);
}

GLFWwindow *GWindow::get_window_ptr()
{
    return window;
}

void GWindow::key_input_callback(GLFWwindow *w, int key, int scancode, int action, int mods)
{
    switch (action)
    {
    case GLFW_PRESS: {
        EventSystemHelper::queue_events(EVENTTYPE_KEY_PRESSED, new KeyPressedEvent(key));
        break;
    }
        
    case GLFW_RELEASE:
        EventSystemHelper::queue_events(EVENTTYPE_KEY_RELEASED, new KeyReleasedEvent(key));
    }
}

GWindow::~GWindow()
{
    glfwSetWindowShouldClose(window, 1);
    glfwDestroyWindow(window);
}
