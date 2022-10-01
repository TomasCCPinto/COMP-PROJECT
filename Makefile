CC = clang-14
LEX = flex
OBJS = lex.yy.c
EXE = lexico
COMP = jucompiler.l


prog:		run

run:		${OBJS}
		${CC} ${OBJS} -o ${EXE}
		./${EXE}


clean:		${LEXFILE}
		rm ${OBJS} ${EXE}



${OBJS}:	
		flex ${COMP}
