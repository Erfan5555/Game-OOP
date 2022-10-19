monarch: main.cpp power.cpp person.cpp
	g++ -std=c++11 main.cpp -o monarch
	clear
	@./monarch
play:
	@./monarch
test: powertest.cpp persontest.cpp
	g++ -std=c++11 powertest.cpp -o powertest
	g++ -std=c++11 persontest.cpp -o persontest
	clear