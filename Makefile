CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = main
OBJECTS = main.o academicbuilding.o collectosap.o computer.o coop.o goosenesting.o gototims.o gym.o human.o mblock.o needleshall.o nonproperty.o player.o property.o res.o slc.o square.o theboard.o timsline.o tuition.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
