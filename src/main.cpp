#include <nan.h>
#include <unistd.h>

#include "log.h"

#include "Graphics.h"
#include "GfxTexture.h"

NAN_MODULE_INIT(Init) {
  plog("NAN_MODULE_INIT");

  Graphics::Init(target);
  GfxTexture::Init(target);
}

NODE_MODULE(Node_OpenGL, Init)