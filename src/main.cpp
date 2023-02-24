#include "lucerna/lucerna.h"

int main(){
    Window win("Lucerna", 1080, 720);

    if(win.init()){
        // Any OpenGL code must go in this if statement
        float positions[8] = {
            -0.5f, -0.5f,
             0.5f, -0.5f,
             0.5f,  0.5f,
            -0.5f,  0.5f
        };

        unsigned int indices[6] = {
            0, 1, 2,
            2, 3, 0
        };

        VertexArray va;
        VertexBuffer vb(positions, 4 * 2 * sizeof(float));
        BufferLayout layout;
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);

        IndexBuffer ib(indices, 6);

        Shader shader("default.glsl");
        shader.Bind();

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