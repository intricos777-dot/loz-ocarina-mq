/* LOZ OoT Master Quest - Twilight Elysium engine bridge */
#include "engine_bridge.h"
#include "../../twilight-elysium/src/renderer/renderer.h"
#include <cstdio>

namespace loz_oot_mq {
  bool EngineBridge::init(const char* title, int width, int height) {
      te::EngineConfig cfg;
      cfg.window_title = title ? title : "Zelda OoT Master Quest";
      cfg.window_width = (uint32_t)width;
      cfg.window_height = (uint32_t)height;
      cfg.base_width = 640;
      cfg.base_height = 360;
      cfg.scale_mode = 5;
      if (!te::Engine::instance().initialize(cfg)) return false;
      std::printf("[OoTMQ] Engine initialized\n");
      return true;
  }
  int EngineBridge::run() {
      std::printf("[OoTMQ] Running placeholder frame loop...\n");
      for (int i = 0; i < 8; ++i) {
        // frame stub
      }
      std::printf("[OoTMQ] Placeholder loop complete\n");
      return 0;
  }
  void EngineBridge::shutdown() {
      te::Engine::instance().shutdown();
  }
}
