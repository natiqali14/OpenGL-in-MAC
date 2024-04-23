

#include "includes.h"
#include <iostream>
#include "WindowSystem/GWindow.h"
#include "WindowSystem/WindowSystemUtility.h"
#include "opengl_backend/playground.h"
#include <GLFW/glfw3.h>
#include "EventSystem/EventSystemHelper.h"
#include "CameraSystem/CameraSystem.h"
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings


int main()
{
    EventSystemHelper::initialise();
    CameraSystem* _cs = new CameraSystem();
    WindowSystemUtility::initialise_glfw();
    std::unique_ptr<GWindow> main_window = std::make_unique<GWindow>(SCR_WIDTH, SCR_HEIGHT, "OPENGL WINDOW");
        // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    std::vector<u32> shader_ids;
    u32 v_shader = create_shader(GL_VERTEX_SHADER, vertexShaderSource);
    u32 f_shader = create_shader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    shader_ids.push_back(v_shader);
    shader_ids.push_back(f_shader);
    u32 program = create_program(shader_ids);
   
    buffer_data data1 = initialise_triangle();
    buffer_data data2 = initialise_triangle();
    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    // -----------
    while (!main_window->should_close_window())
    {
        // input
        // -----
        EventSystemHelper::dispatch_events();
        processInput(main_window->get_window_ptr());

        // render
        // ------
        glClearColor(0.2f, 0.1f, 0.1f, 01.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // draw our first triangle
        //transformations(program);
        render_cubes(program, data1, data2);
        glUseProgram(program);
       // draw_triangle(data);
        // glBindVertexArray(0); // no need to unbind it every time 
 
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(main_window->get_window_ptr());
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
   

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}