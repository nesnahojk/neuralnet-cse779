CXXFLAGS = -c
NeuralNetwork.o: NeuralNetwork.h NeuralNetwork.impl
	$(CXX) $(CXXFLAGS)  NeuralNetwork.h -o NeuralNetwork.o

clean:
	$(RM) NeuralNetwork.o



