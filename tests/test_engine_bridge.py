"""Tests for LOZ OoT Master Quest engine bridge."""
import unittest
from pathlib import Path

REPO = Path("/home/sin/Projects/loz-ocarina-mq")


class TestOoTMQEngineBridge(unittest.TestCase):
    def test_header_declares_namespace_and_class(self):
        text = (REPO / "src/engine_bridge.h").read_text()
        self.assertIn("namespace loz_oot_mq", text)
        self.assertIn("class EngineBridge", text)

    def test_cpp_implements_bridge_methods(self):
        text = (REPO / "src/engine_bridge.cpp").read_text()
        self.assertIn("namespace loz_oot_mq", text)
        self.assertIn("EngineBridge::init", text)
        self.assertIn("EngineBridge::run", text)
        self.assertIn("te::Engine::instance().initialize", text)

    def test_cmake_lists_references_sources(self):
        text = (REPO / "CMakeLists.txt").read_text()
        self.assertIn("loz-ocarina-mq", text)
        self.assertIn("src/main.cpp", text)

    def test_readme_exists(self):
        self.assertTrue((REPO / "README.md").exists())

    def test_self_heal_script_executable(self):
        import os
        path = REPO / "scripts/self-heal.sh"
        self.assertTrue(path.exists())
        self.assertTrue(os.access(path, os.X_OK))


if __name__ == "__main__":
    unittest.main()
