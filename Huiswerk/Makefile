libs := -lsfml-graphics -lsfml-window -lsfml-system
gcc := g++ -std=c++17 -c
ln := g++ -std=c++17
rm := rm -rf

main.exe: main.o ball.o command.o paddle.o power_up.o
	$(ln) main.o ball.o command.o paddle.o power_up.o -o main.exe $(libs)

main.o: main.cpp game.hpp
	$(gcc) main.cpp -o main.o

ball.o: ball.cpp ball.hpp paddle.hpp
	$(gcc) ball.cpp -o ball.o

command.o: command.cpp command.hpp player.hpp
	$(gcc) command.cpp -o command.o

paddle.o: paddle.cpp paddle.hpp colored_object.hpp
	$(gcc) paddle.cpp -o paddle.o

power_up.o: power_up.cpp power_up.hpp ball.hpp
	$(gcc) power_up.cpp -o power_up.o

clean: 
	$(rm) *.o *.exe

run: main.exe
	sudo ./main.exe
