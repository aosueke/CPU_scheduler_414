# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Target Executable
TARGET = ../scheduler  # The output binary 

# Source and Header File Locations
SRCS = main.cpp \
       round_robin.cpp \
       preemptive_priority_scheduler.cpp \
       non_preemptive_priority_scheduler.cpp \
       multilevel_queue.cpp \
       MLFQ.cpp

HEADERS = processInfo.h \
          round_robin.h \
          preemptive_priority_scheduler.h \
          non_preemptive_priority_scheduler.h \
          multilevel_queue.h \
          MLFQ.h

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Default Target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS)  # <-- Indented with a TAB, not spaces

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@  # <-- Indented with a TAB, not spaces

# Phony targets
.PHONY: all clean
all: $(TARGET)

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)  # <-- Indented with a TAB, not spaces

# Run Rule
run: $(TARGET)
	./$(TARGET)  # <-- Indented with a TAB, not spaces
