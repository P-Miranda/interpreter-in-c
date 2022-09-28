#ifndef H_TOKEN_H
#define H_TOKEN_H

#define TOKEN_STR_SIZE (100)

typedef struct {
    char Type[TOKEN_STR_SIZE];
    char Literal[TOKEN_STR_SIZE];
} TokenType;

#define ILLEGAL ("ILLEGAL")
#define EOF_ ("EOF")
#define IDENT ("IDENT")
#define INT ("INT")
#define ASSIGN ("ASSIGN")
#define PLUS ("PLUS")
#define COMMA ("COMMA")
#define SEMICOLON ("SEMICOLON")
#define LPAREN ("LPAREN")
#define RPAREN ("RPAREN")
#define LBRACE ("LBRACE")
#define RBRACE ("RBRACE")
#define FUNCTION ("FUNCTION")
#define LET ("LET")

#endif // H_TOKEN_H
