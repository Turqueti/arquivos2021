all:
	gcc *.c *.h -o out -W

tests:
	gcc *.c *.h -o out -W
	./.scripts/resetTestCases.sh ./.testes
	./.scripts/tester.sh out ./.testes -c
