CC=g++
CFLAGS=-Wall -g -std=c++11 -fprofile-arcs -ftest-coverage

TEST_SRC=tests

OBJ_DIR=obj
OBJS= Square.o Game.o Board.o  Piece.o Chess.o KingMovement.o RookMovement.o PawnMovement.o QueenMovement.o BishopMovement.o ChessBoard.o
TEST_OBJS= $(TEST_SRC)/RunTests.o $(TEST_SRC)/TestPawn.o $(TEST_SRC)/TestKing.o $(TEST_SRC)/TestQueen.o  $(TEST_SRC)/TestBishop.o $(TEST_SRC)/TestRook.o $(TEST_SRC)/TestGame.o $(TEST_SRC)/TestBoard.o

INCLUDE= -I .

GCOV = gcov11
COVERAGE_RESULTS = result.coverage

PROGRAM=Chess2720
PROGRAM_TEST=testChess

.PHONY: all
all: $(PROGRAM) $(PROGRAM_TEST)

$(PROGRAM): $(OBJS) Chess2720.o
	$(CC) $(CFLAGS) -o $@ $^

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $(patsubst %.cpp,%.o,$<) ${INCLUDE}

## generate the prerequistes and append to the desired file
.prereq : $(OBJS:.o=.cpp) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cpp) >> ./.prereq

     ## include the generated prerequisite file
     include .prereq

.PHONY: clean
clean:
	rm -rf *~ *.o $(TEST_SRC)/*.o *.gcov $(TEST_SRC)/*.gcov *.gcda $(TEST_SRC)/*.gcda *.gcno $(TEST_SRC)/*.gcno $(COVERAGE_RESULTS)


.PHONY: clean-all
clean-all: clean
	rm -rf $(PROGRAM) $(PROGRAM_TEST)

run:
	$(PROGRAM)

memcheck: $(PROGRAM)
	valgrind --leak-check=yes $(PROGRAM)

$(PROGRAM_TEST): $(TEST_OBJS) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lcppunit $(INCLUDE)

test: $(PROGRAM_TEST)
	$(PROGRAM_TEST)

test-memcheck: $(PROGRAM_TEST)
	rm -f results
	valgrind --leak-check=yes $(PROGRAM_TEST) &> results
	more results

coverage: test
	$(GCOV) *.cpp
	cd $(TEST_SRC)
	$(GCOV) *.cpp
	cd ..
	grep -r "####" *.cpp.gcov > $(COVERAGE_RESULTS)
	more $(COVERAGE_RESULTS)
