"""Smoke tests for LOZ OoT Master Quest build."""
from pathlib import Path

ROOT = Path('/home/sin/Projects/loz-ocarina-mq')
BIN = ROOT / 'build' / 'oot-mq'

def test_oot_mq_binary_exists():
    assert BIN.exists(), 'oot-mq binary missing'

if __name__ == '__main__':
    test_oot_mq_binary_exists()
    print('[OK] oot-mq smoke test passed')
