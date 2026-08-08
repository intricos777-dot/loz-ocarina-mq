/* LOZ OoT Master Quest - Twilight Elysium entry */
#include "engine_bridge.h"
#include <cstdlib>

int main(int /*argc*/, char** /*argv*/) {
    loz_oot_mq::EngineBridge bridge;
    if (!bridge.init("Zelda OoT Master Quest", 1280, 720)) {
        std::fprintf(stderr, "[OoTMQ] Failed to initialize engine\n");
        return EXIT_FAILURE;
    }
    int rc = bridge.run();
    bridge.shutdown();
    return rc == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
