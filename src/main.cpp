#include "lucerna/lucerna.h"

int main(){
    Window win("Lucerna", 1080, 720);

    if(win.init()){
        // Any OpenGL code must go in this if statement
        float positions[16] = {
            -0.5f, -0.5f, 0.0f, 0.0f,
             0.5f, -0.5f, 1.0f, 0.0f,
             0.5f,  0.5f, 1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f, 1.0f
        };

        unsigned int indices[6] = {
            0, 1, 2,
            2, 3, 0
        };

        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

        VertexArray va;
        VertexBuffer vb(positions, 4 * 4 * sizeof(float));
        BufferLayout layout;
        layout.Push<float>(2);
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);

        IndexBuffer ib(indices, 6);

        Shader shader("shaders/default.glsl");
        shader.Bind();

        Texture tex("assets/textures/lamp.jpg");
        tex.Bind();
        shader.SetUniform1i("u_Texture", 0);

        va.Unbind();
        vb.Unbind();
        ib.Unbind();
        shader.Unbind();

        Renderer renderer;
        
        while(win.closed()){
            renderer.Clear();
            // Draw everything here

            renderer.Draw(va, ib, shader);
            
            win.update();
        }
    }
}