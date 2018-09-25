all: launch

launch: main.cpp
	g++ main.cpp -o launch

clean:
	rm trajectory.dab launch
