#include "engine_bridge.h"
int main() {
  loz_oot_mq::EngineBridge bridge;
  if (!bridge.init("Zelda OoT Master Quest", 1280, 720)) return 1;
  bridge.run();
  return 0;
}
