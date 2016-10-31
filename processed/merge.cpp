#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

//const int NUMPROG = 9;

#define merge MERGE

void merge(const char* path, const char* ext, int start, int end, const char* fname) {
	int token = 0;
	FILE* output = fopen(fname, "w");
	char buf[1000000];
	for (int i = start; i <= end; ++i) {
		char pname[100];
		sprintf(pname, "%s%d%s", path, i, ext);
		FILE* input = fopen(pname, "r");
		fread(buf, 1, 1000000, input);
		int l = strlen(buf);
		token += l;
		for (int j = 0; j < l; ++j) {
			if (j) {
				fprintf(output, " ");
			}
			if (buf[j] == ' ') {
				fprintf(output, "_SPACE_");
			} else if (buf[j] == '\n') {
				fprintf(output, "_EOLN_");
			} else {
				fprintf(output, "%c", buf[j]);
			}
			buf[j] = '\0';
		}
		fprintf(output, "\n");
	}
	fclose(output);
	printf("%s #token: %d\n", fname, token);
}

const char *input[3] = {
	"processed/train_input.txt", "processed/val_input.txt", "processed/eval_input.txt"
};

const char *output[3] = {
	"processed/train_output.txt", "processed/val_output.txt", "processed/eval_output.txt"
};

int main(int num, char* args[]) {
	int start = 1;
	for (int i = 1; i <= 3; ++i) {
		int n;
		sscanf(args[i], "%d", &n);
		if (n) {
			int end = start + n - 1;
			merge("dataset/", ".coffee", start, end, input[i - 1]);
			merge("dataset/", ".js", start, end, output[i - 1]);
			start = end + 1;
		}
	}
	return 0;
}
