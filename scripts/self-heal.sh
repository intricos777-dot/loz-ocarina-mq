#!/bin/bash
# Self-heal wrapper for LOZ OoT MQ
set -uo pipefail
LOG="logs/self-heal.log"
mkdir -p "$(dirname "$LOG")"
ts() { date '+%Y-%m-%d %H:%M:%S'; }

echo "[$(ts)] self-heal start" >> "$LOG"
if [ ! -d build ]; then
  echo "[$(ts)] missing build dir, running cmake" >> "$LOG"
  cmake -B build -S . >> "$LOG" 2>&1 || true
fi
if [ ! -x build/oot-mq ]; then
  echo "[$(ts)] missing binary, building" >> "$LOG"
  cmake --build build --target oot-mq >> "$LOG" 2>&1 || true
fi
if [ -x build/oot-mq ]; then
  echo "[$(ts)] running oot-mq" >> "$LOG"
  ./build/oot-mq >> "$LOG" 2>&1 || true
else
  echo "[$(ts)] build artifacts missing" >> "$LOG"
fi
echo "[$(ts)] self-heal end" >> "$LOG"