CXX = g++
CXXFLAGS = -std=c++17
CPP_FILES := $(shell find . -name "*.cpp")
BINARIES := $(CPP_FILES:.cpp=)

all: $(BINARIES)

%: %.cpp
	@echo "Building $@..."
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(BINARIES)
	rm -rf *.dSYM */*.dSYM
