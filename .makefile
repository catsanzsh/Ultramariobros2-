ROM_REGION ?= us
# Default region is US

ifeq ($(ROM_REGION), us)
ROM = baserom.us.z64
NONMATCHING = 1
TARGET = sm64.us
endif

ifeq ($(ROM_REGION), jp)
ROM = baserom.jp.z64
NONMATCHING = 1
TARGET = sm64.jp
endif

ifeq ($(ROM_REGION), eu)
ROM = baserom.eu.z64
NONMATCHING = 1
TARGET = sm64.eu
endif
