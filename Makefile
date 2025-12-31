CXX = g++
CXXFLAGS = -Iinclude -Wall

SRC = src/main.cpp \
      src/frame_reader.cpp \
      src/png_writer.cpp \
      src/filters.cpp \
      src/pipeline.cpp \
      src/hex_dump.cpp

OUT = pipeline

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
