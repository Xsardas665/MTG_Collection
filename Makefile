CXX=g++
CXXFLAGS=`pkg-config gtkmm-3.0 --cflags --libs` -std=c++17 -Iinclude
SRCDIR=src
INCDIR=include
BUILDDIR=build
TARGET=$(BUILDDIR)/mtg-catalog

SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS=$(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -rf $(BUILDDIR)/*.o $(TARGET)
