# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Target Executable
TARGET = scheduler

# Source and Header File Locations
SRC_DIR = sourceCode
SRCS = $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/round_robin.cpp \
       $(SRC_DIR)/priority_scheduler.cpp \
       $(SRC_DIR)/multilevel_queue.cpp \
       $(SRC_DIR)/multilevel_feedback_queue.cpp

HEADERS = $(SRC_DIR)/processInfo.h \
          $(SRC_DIR)/round_robin.h \
          $(SRC_DIR)/priority_scheduler.h \
          $(SRC_DIR)/multilevel_queue.h \
          $(SRC_DIR)/MLFQ.h

# Object Files
OBJS = $(SRCS:.cpp=.o)
