OBJECTS = HW2main.o pi_approx.o approximations.o
CXX = g++
CXXflags = -std=c++11

EXECUTABLE = HW2main

$(EXECUTABLE) : $(OBJECTS)
	$(CXX) $(CXXflags) -o $@ $^

%.o : %.cpp
	$(CXX) $(CXXflags) -c $< -o $@


clean : 
	@echo "Removing all object files and executables..."
	rm -f $(EXECUTABLE) $(OBJECTS)