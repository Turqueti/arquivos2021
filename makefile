all:
	gcc *.c *.h -o out -W -g

run:
	./out

tests:
	gcc *.c *.h -o out -W
	./.scripts/resetTestCases.sh ./.testes
	./.scripts/tester.sh out ./.testes -c
