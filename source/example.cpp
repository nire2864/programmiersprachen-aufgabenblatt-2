#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <vector>
#include "circle.hpp"
#include "rectangle.hpp"
#include "mat2.hpp"


int main(int argc, char* argv[])
{
  Window win{std::make_pair(700,700)};

    //DEFAULT TESTS
    Color highlighting{1.0f,0.5137f,0.0f};

    Circle circle_1{100.f,{350.0f,350.0f},{0.99f,0.0f,0.99f}};
    Circle circle_2{150.f,{350.0f,350.0f},{0.99f,0.0f,0.99f}};
    
    Rectangle rectangle_1{{200.0f,200.0f},{500.0f,500.0f},{0.2235f,1.0f,0.784f}};
    Rectangle rectangle_2{{250.0f,250.0f},{450.0f,450.0f},{0.2235f,1.0f,0.784f}};

    //Clock
    Vec2 clock_centre{350.0f,350.0f};
    Circle clock_1{300.0f,clock_centre,{0.0f,0.0f,0.0f}};
    Circle clock_knob{3.0f,clock_centre,{0.0f,0.0f,0.0f}};
    Vec2 second{0.0f,-290.0f};
    Vec2 minute{0.0f,-250.0f};
    Vec2 hour{0.0f,-200.0f};
    Vec2 pos1_start{0,-298.0f};
    Vec2 pos2_start{0,-285.0f};

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
    //TEST_CLOCK
    //drawing clock
    clock_1.draw(win, 1.5f);
    clock_knob.draw(win, 1.0f);

    Vec2 pos1_0 = pos1_start * make_rotation_mat2(M_PI/6);
    Vec2 pos2_0 = pos2_start * make_rotation_mat2(M_PI/6);
    Vec2 pos1_1 = pos1_start * make_rotation_mat2(2*M_PI/6);
    Vec2 pos2_1 = pos2_start * make_rotation_mat2(2*M_PI/6);
    Vec2 pos1_2 = pos1_start * make_rotation_mat2(3*M_PI/6);
    Vec2 pos2_2 = pos2_start * make_rotation_mat2(3*M_PI/6);
    Vec2 pos1_3 = pos1_start * make_rotation_mat2(4*M_PI/6);
    Vec2 pos2_3 = pos2_start * make_rotation_mat2(4*M_PI/6);
    Vec2 pos1_4 = pos1_start * make_rotation_mat2(5*M_PI/6);
    Vec2 pos2_4 = pos2_start * make_rotation_mat2(5*M_PI/6);
    Vec2 pos1_5 = pos1_start * make_rotation_mat2(6*M_PI/6);
    Vec2 pos2_5 = pos2_start * make_rotation_mat2(6*M_PI/6);
    Vec2 pos1_6 = pos1_start * make_rotation_mat2(7*M_PI/6);
    Vec2 pos2_6 = pos2_start * make_rotation_mat2(7*M_PI/6);
    Vec2 pos1_7 = pos1_start * make_rotation_mat2(8*M_PI/6);
    Vec2 pos2_7 = pos2_start * make_rotation_mat2(8*M_PI/6);
    Vec2 pos1_8 = pos1_start * make_rotation_mat2(9*M_PI/6);
    Vec2 pos2_8 = pos2_start * make_rotation_mat2(9*M_PI/6);
    Vec2 pos1_9 = pos1_start * make_rotation_mat2(10*M_PI/6);
    Vec2 pos2_9 = pos2_start * make_rotation_mat2(10*M_PI/6);
    Vec2 pos1_10 = pos1_start * make_rotation_mat2(11*M_PI/6);
    Vec2 pos2_10 = pos2_start * make_rotation_mat2(11*M_PI/6);

    win.draw_line(pos1_start.x+350,pos1_start.y+350,pos2_start.x+350,pos2_start.y+350,0.0f,0.0f,0.0f,2.0f);
    win.draw_line(pos1_0.x+350,pos1_0.y+350,pos2_0.x+350,pos2_0.y+350,0.0f,0.0f,0.0f,2.0f);
    win.draw_line(pos1_1.x+350,pos1_1.y+350,pos2_1.x+350,pos2_1.y+350,0.0f,0.0f,0.0f,2.0f);
    win.draw_line(pos1_2.x+350,pos1_2.y+350,pos2_2.x+350,pos2_2.y+350,0.0f,0.0f,0.0f,2.0f);
    win.draw_line(pos1_3.x+350,pos1_3.y+350,pos2_3.x+350,pos2_3.y+350,0.0f,0.0f,0.0f,2.0f);
    win.draw_line(pos1_4.x+350,pos1_4.y+350,pos2_4.x+350,pos2_4.y+350,0.0f,0.0f,0.0f,2.0f);
    win.draw_line(pos1_5.x+350,pos1_5.y+350,pos2_5.x+350,pos2_5.y+350,0.0f,0.0f,0.0f,2.0f);
    win.draw_line(pos1_6.x+350,pos1_6.y+350,pos2_6.x+350,pos2_6.y+350,0.0f,0.0f,0.0f,2.0f);
    win.draw_line(pos1_7.x+350,pos1_7.y+350,pos2_7.x+350,pos2_7.y+350,0.0f,0.0f,0.0f,2.0f);
    win.draw_line(pos1_8.x+350,pos1_8.y+350,pos2_8.x+350,pos2_8.y+350,0.0f,0.0f,0.0f,2.0f);
    win.draw_line(pos1_9.x+350,pos1_9.y+350,pos2_9.x+350,pos2_9.y+350,0.0f,0.0f,0.0f,2.0f);
    win.draw_line(pos1_10.x+350,pos1_10.y+350,pos2_10.x+350,pos2_10.y+350,0.0f,0.0f,0.0f,2.0f);
    
    

    //setting time
    float time = win.get_time();
    float s = fmod(time,60);
    float m = fmod(time/60,60);
    float h = fmod(time/3600,12);
    Mat2 rotation_mat_s = make_rotation_mat2(s*(M_PI/30));
    Mat2 rotation_mat_m = make_rotation_mat2(m*(M_PI/30));
    Mat2 rotation_mat_h = make_rotation_mat2(h*(M_PI/30));

    Vec2 s_atm = second * rotation_mat_s; 
    Vec2 m_atm = minute * rotation_mat_m;
    Vec2 h_atm = hour * rotation_mat_h;

    win.draw_line(350.0f,350.0f, s_atm.x+350.0f, s_atm.y+350.0f,1.0f,0.0f,0.0f,1.2f);
    win.draw_line(350.0f,350.0f, m_atm.x+350.0f, m_atm.y+350.0f,1.0f,1.0f,1.0f,1.4f);
    win.draw_line(350.0f,350.0f, h_atm.x+350.0f, h_atm.y+350.0f,0.0f,0.0f,0.0f,1.6f);


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
