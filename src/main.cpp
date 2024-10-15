#include "config.h"
#include "vec.hpp"

void update() {

}

int main(int argc, char** argv) {
  begin__();
  while (window_open()) {
    pre_render();
    update();
    render();
  }
  end__();
  return 0;
}