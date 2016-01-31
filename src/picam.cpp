#include <stdio.h>
#include <unistd.h>
#include "graphics.h"

bool running = true;

void clean_up_func(int signum) {
  printf("Clean up in progress\n");

  running = false;
}

//entry point

int main(int argc, const char **argv) {
  // install the signal handler
  signal(SIGINT, clean_up_func);

  unsigned int width;
  unsigned int height;

  width = 320;
  width = 240;

  printf("setup %dx%d\n", width, height);

  //init graphics and the camera
  InitGraphics();

  GfxTexture texture;
  texture.Create(width, height, NULL, false);

  printf("Running frame loop\n");
  while (running) {

    char* data = new char[width * height];

    texture.SetPixels(data, false);


    //begin frame, draw the texture then end frame (the bit of maths just fits the image to the screen while maintaining aspect ratio)
    BeginFrame();
    float aspect_ratio = float(width) / float(height);
    float screen_aspect_ratio = 1920.f / 1080.f;
    //DrawTextureRect(&texture,-aspect_ratio/screen_aspect_ratio,-1.f,aspect_ratio/screen_aspect_ratio,1.f);
    DrawTextureRect(&texture, -1, -1.f, 1, 1.f);
    EndFrame();
  }
  return 0;
}
