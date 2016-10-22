#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const char* PATH = "dataset/";

const int NUMP = 9, //Number of programs to generate
	  	  MAXPL = 5, //Max number of lines for a program
		  SEED = 1, //RNG seed
		  MAXIL = 10, //Max number of characters for an identifier
		  ASSI = 50, //Percentage of assignment statements
		  MAXD = 3, //Max depth of conditions
		  RELA = 50, //Percentage of relational operators for expression,
		  MINT = 10000, //Max int
		  RINT = 80; //Percentage of integeral values

FILE *out;

void genInteger() {
	int val = rand() % MINT;
	if (rand() % 2) {
		val = -val;
	}
	fprintf(out, "%d", val);
}

const char* CH = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_$0123456789";
const int FIRST = 54, ALL = 64;

void genIdentifier() {
	int len = rand() % MAXIL + 1;	
	for (int i = 0; i < len; ++i) {
		fprintf(out, "%c", CH[rand() % (i ? ALL : FIRST)]);
	}
}

const char* REOP[] = {
	"==",
	"!=",
	">",
	">=",
	"<",
	"<="
};

void genRelationalOperator() {
	fprintf(out, " %s ", REOP[rand() % 6]);
}

void genValue() {
	if (rand() % 100 > RINT) {
		fprintf(out, "%s", rand() % 2 ? "true" : "false");
	} else {
		genInteger();
	}
}

void genExpression() {
	if (rand() % 100 > RELA) {
		genIdentifier();
	} else {
		genIdentifier();
		genRelationalOperator();
		genInteger();
	}
}

void genAssignment() {
	genIdentifier();
	fprintf(out, " = ");
	genValue();
}

void genStatement(int);

void genCondition(int dep) {
	genStatement(dep);	
	fprintf(out, " if ");
	genExpression();
}

void genStatement(int dep) {
	if (dep && rand() % 100 > ASSI) {
		genCondition(dep - 1);
	} else {
		genAssignment();
	}
}

void genLinebreak() {
	fprintf(out, "\n");
}

void genProgram() {
	int len = rand() % MAXPL + 1;
	for (int i = 0; i < len; ++i) {
		genStatement(MAXD);
		genLinebreak();
	}
}

int main(int narg, char* args[]) {
	int n;
	sscanf(args[1], "%d", &n);
	srand(SEED);
	for (int i = 1; i <= n; ++i) {
		char filename[30];
		sprintf(filename, "%s%d.coffee", PATH, i);
		printf("%d of %d : %s\n", i, NUMP, filename);
		out = fopen(filename, "w");
		genProgram();
		fclose(out);
	}
	return 0;
}
