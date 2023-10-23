CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lboost_unit_test_framework 

SRC = main.cpp Universe.cpp CelestialBody.cpp
TEST = test.cpp

OBJ = $(SRC:.cpp=.o)
TEST_OBJ = $(TEST:.cpp=.o)

EXEC = NBody

all: $(EXEC)

$(EXEC): $(OBJ)  
	$(CXX) $(CXXFLAGS) $(SFML_LIBS) -o $@ $^

# New test target
test: $(TEST_OBJ) $(OBJ) 
	$(CXX) $(CXXFLAGS) $(SFML_LIBS) -o $@ $^
	./$@

$(TEST_OBJ): $(TEST)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
clean:
	rm -f $(OBJ) $(EXEC) $(TEST_OBJ)

lint:
	cpplint $(SRC) $(TEST)

.PHONY: clean