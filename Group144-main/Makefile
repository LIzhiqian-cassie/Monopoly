flags = -pedantic-errors -std=c++11
Game1.o : Game1.cpp Game1.h
	g++ $(flags) -c $< -o $@
Game2.o : Game2.cpp Game2.h
	g++ $(flags) -c $< -o $@
Game3.o : Game3.cpp Game3.h
	g++ $(flags) -c $< -o $@
Game4.o : Game4.cpp Game4.h
	g++ $(flags) -c $< -o $@
Game5.o : Game5.cpp Game5.h
	g++ $(flags) -c $< -o $@
printSaving.o: printSaving.cpp printSaving.h
	g++ $(flags) -c $< -o $@
checkName.o: checkName.cpp checkName.h
	g++ $(flags) -c $< -o $@
Map.o : Map.cpp Map.h
	g++ $(flags) -c $< -o $@
Player_info.o : Player_info.cpp Player_info.h
	g++ $(flags) -c $< -o $@
Save.o : Save.cpp Save.h Map.h Player_info.h printSaving.h checkName.h
	g++ $(flags) -c $< -o $@
Load.o : Load.cpp Load.h Map.h Player_info.h printSaving.h checkName.h
	g++ $(flags) -c $< -o $@
Maingame.o : Maingame.cpp Maingame.h Game1.h Game2.h Game3.h Game4.h Game5.h Save.h Map.h Player_info.h
	g++ $(flags) -c $< -o $@
Minipoly.o : Minipoly.cpp Load.h Maingame.h
	g++ $(flags) -c $< -o $@
Minipoly : Minipoly.o Maingame.o Load.o Save.o Player_info.o Map.o Game1.o Game2.o Game3.o Game4.o Game5.o printSaving.o checkName.o
	g++ $(flags) $^ -o Minipoly
clean :
	rm -f *.o Main
.PHONY : clean
