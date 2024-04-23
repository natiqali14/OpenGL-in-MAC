#include "../includes.h"
#include "../includes/GLFW/glfw3.h"



class GWindow {
    GLFWwindow* window;
    u16 width;
    u16 height;
    std::string window_name;
public:
    GWindow(u16 w, u16 h, std::string w_name);
    void make_context_current();
    bool should_close_window();
    GLFWwindow* get_window_ptr();
    static void key_input_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    ~GWindow();
};