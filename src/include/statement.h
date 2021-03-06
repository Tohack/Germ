/* Copyright (c) 2017 Tohack<tohack@foxmail.com>. All Rights Reserved. */

#ifndef _ToHack_CL_STATEMENT_H
#define _ToHack_CL_STATEMENT_H

typedef struct _statement Statement;
struct _statement{
	int                 stmtType;
	union{
	    Symbol*         declSymbol; // DeclareStmt
	    String*         labelString;// LabelStmt/GotoStmt
	    Expression*     expression;	// ExprsssionStmt/ReturnStmt/ThrowStmt
	    struct{			// ifStmt
	        Vector      elseStmt;
	        Vector      ifCondElements;
	    };
	    struct{			// switchStmt
	        Expression* switchExpr;
	        Vector      defaultStmt;
	        Vector      switchCondElement;
	        String*     switchBreakLabel;
	    };
	    struct{			// forStmt
	        Expression* forExpr1;
	        Expression* forExpr2;
	        Expression* forExpr3;
	        Vector      forStmt;
	        String*     forContinueLabel;
	        String*     forBreakLabel;
	    };
	    struct{			// whileStmt
	        Expression* whileExpr;
	        Vector      whileStmt;
	        String*     whileContinueLable;
	        String*     whileBreakLabel;
	    };
	};
};

// Child Element of ifStmt and switchStmt.
typedef struct _condElement{
	Expression* expression;
	Vector      statement;
} CondElement;

/* values of stmtType */
enum{
	Stmt_declare,
	Stmt_lable,
	Stmt_expression,
	Stmt_if,
	Stmt_switch,
	Stmt_for,
	Stmt_while,
	Stmt_break,
	Stmt_continue,
	Stmt_goto,
	Stmt_return,
	Stmt_throw
};

Statement* ParseImportStmt(ParseState*);
Statement* ParseLabelStmt(ParseState*, String*);
Statement* ParseExpressionStmt(ParseState*);
void ParseInternalStmt(ParseState*, Symbol*);
void ParseExternalStmt(ParseState*, Symbol*);

#endif