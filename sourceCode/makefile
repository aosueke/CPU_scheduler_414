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
       $(SRC_DIR)/preemptive_priority_scheduler.cpp \
       $(SRC_DIR)/non_preemptive_priority_scheduler.cpp \
       $(SRC_DIR)/multilevel_queue.cpp \
       $(SRC_DIR)/MLFQ.cpp

HEADERS = $(SRC_DIR)/processInfo.h \
          $(SRC_DIR)/round_robin.h \
          $(SRC_DIR)/priority_scheduler.h \
          $(SRC_DIR)/preemptive_priority_scheduler.h \
          $(SRC_DIR)/non_preemptive_priority_scheduler.h \
          $(SRC_DIR)/multilevel_queue.h \
          $(SRC_DIR)/MLFQ.h

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
    $(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Phony targets
.PHONY: all clean
all: $(TARGET)

# Clean up build files
clean:
    rm -f $(OBJS) $(TARGET)

# Run Rule
run: $(TARGET)
	./$(TARGET)
