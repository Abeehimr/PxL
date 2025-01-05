paint: main.cpp App.cpp Canvas.cpp Mouse.cpp Utility.cpp
	g++ main.cpp App.cpp Canvas.cpp Mouse.cpp Utility.cpp -o paint -lsfml-graphics -lsfml-window -lsfml-system
run:
	./paint
