all: s r

s: sender/sender.c
	gcc -o s sender/sender.c
	
r: recver/recver.c
	gcc -o r recver/recver.c
	
clean:
	rm s r