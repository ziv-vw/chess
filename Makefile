CXX = g++
CXXFLAGS = -std=c++14 -MMD 
EXEC = chess 
OBJECTS = piece.o king.o queen.o rook.o bishop.o knight.o pawn.o Game.o Board.o Coordinate.o player.o human.o computer.o level1.o Display.o textDisplay.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} 

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
