all:
	gcc *.c *.h -o out -W -g

run:
	./out

tests:
	gcc *.c *.h -o out -W -g
	./.scripts/setupTests.sh
