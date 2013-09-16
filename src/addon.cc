#include <node.h>
#include "erbium.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
  Erbium::Init(exports);
}

NODE_MODULE(erbium, InitAll)
