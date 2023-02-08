#include "window.h"
#include "shape.h"

int main(){
    Window win("Hello Triangle!",1080, 720);

    win.Init();
    Triangle triangle(0,0,5,5);

    while(!win.Closed()){
        win.Clear(0.0f, 0.0f, 0.0f);
        triangle.Draw(win.getShader());
        win.Update();
    }

    win.~Window();
    return 0;
}