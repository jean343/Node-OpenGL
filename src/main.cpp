#include <nan.h>
#include <unistd.h>

#include "log.h"

using v8::FunctionTemplate;

void Method(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  info.GetReturnValue().Set(Nan::New("world").ToLocalChecked());
}

NAN_MODULE_INIT(Init) {
  plog("NAN_MODULE_INIT");

  Nan::Set(target, Nan::New("hello").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(Method)).ToLocalChecked());
}

NODE_MODULE(Node_OpenGL, Init)