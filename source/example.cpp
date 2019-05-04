#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <vector>
#include "circle.hpp"
#include "rectangle.hpp"


int main(int argc, char* argv[])
{
  Window win{std::make_pair(700,700)};
    //DEFAULT TESTS
    Color highlighting{1.0f,0.5137f,0.0f};

    Circle circle_1{100.f,{200.0f,200.0f},{0.99f,0.0f,0.99f}};
    Circle circle_2{150.f,{200.0f,200.0f},{0.99f,0.0f,0.99f}};
    
    Rectangle rectangle_1{{50.0f,50.0f},{200.0f,200.0f},{0.2235f,1.0f,0.784f}};
    Rectangle rectangle_2{{200.0f,200.0f},{450.0f,450.0f},{0.2235f,1.0f,0.784f}};

    //Container
    std::vector<Circle> circles;
    std::vector<Rectangle> rectangles;

    circles.push_back(circle_1);
    circles.push_back(circle_2);

    rectangles.push_back(rectangle_1);
    rectangles.push_back(rectangle_2);
    
  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);
    
    //DEFAULT TESTS
    circle_1.draw(win);
    circle_2.draw(win, 5.0f);
    rectangle_1.draw(win);
    rectangle_2.draw(win, 3.0f);

    //if(is_inside) highlight
    for(Circle const& cir: circles)
    {
      if(cir.is_inside({(float) std::get<0>(win.mouse_position()),(float) std::get<1>(win.mouse_position())}))
      {
        cir.draw(win, highlighting);
      }
      else
      {
        cir.draw(win);
      }
    }

    for(Rectangle const& rec: rectangles)
    {
      if(rec.is_inside({(float) std::get<0>(win.mouse_position()),(float) std::get<1>(win.mouse_position())}))
      {
        rec.draw(win, highlighting);
      }
      else
      {
        rec.draw(win);
      }
    }

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    win.update();

  }

  return 0;
}
