all: soru1 soru2

soru1 : soru1.c
	gcc --std=c99 -o soru1 soru1.c

soru2 : soru2.c
	gcc --std=c99 -o soru2 soru2.c

clean :
	rm soru1 soru2