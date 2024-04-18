CXX ?= g++

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CXXFLAGS += -g
else
    CXXFLAGS += -O2

endif

heap: main.cpp  heap.cpp
	$(CXX) -o heap  $^ $(CXXFLAGS) 

clean:
	rm  -r heap
