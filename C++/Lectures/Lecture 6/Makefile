OBJECTS = shapes.o square.o triangle.o
CXX = g++
CXXflags = -std=c++17

shapes : $(OBJECTS)
	$(CXX) $(OBJECTS) -o shapes

shapes.o : shapes.cpp
	@$(CXX) $(CXXflags) shapes.cpp -c

square.o : square.cpp
	@$(CXX) $(CXXflags) square.cpp -c

triangle.o : triangle.cpp
	@$(CXX) $(CXXflags) triangle.cpp -c

clean : 
	@echo "Removing all object files and executables..."
	rm *.o shapes
