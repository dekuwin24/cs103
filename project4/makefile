objects = triangles.o trianglesMain.o main.o triangles_ans.o

src = triangles.cpp
CC = g++
CFLAGS = -Wall -Wno-narrowing

# some aliases:

test : trianglesTest
.PHONY : test

main : triangles
.PHONY : main

trianglesTest : triangles.o trianglesMain.o
	$(CC) -o $@ triangles.o trianglesMain.o

triangles : triangles.o main.o
	$(CC) -o $@ triangles.o main.o

ans : triangles_ans.o trianglesMain.o
	$(CC) -o trianglesTest triangles_ans.o trianglesMain.o

ansni : triangles_ans.o main.o
	$(CC) -o triangles triangles_ans.o main.o

$(objects) : %.o : %.cpp triangles.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean :
	rm -f $(objects) triangles trianglesTest output
