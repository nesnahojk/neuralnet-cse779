CXXFLAGS =
NeuralNetwork.o: NeuralNetwork.h NeuralNetwork.impl main.cpp
	$(CXX) $(CXXFLAGS)  main.cpp NeuralNetwork.h -o NeuralNetwork.o

clean:
	$(RM) NeuralNetwork.o



