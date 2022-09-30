/*
 * lexer_test.c: program to test lexer functions
 * Usage: lexer_test [input]
 *      [input]: <input_fname>.monkey
 *      [output]: <input_fname>.expected
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_replace(char *in, char **out, char *in_substr, char *out_substr) {
  int name_nchars = strstr((const char *)in, (const char *)in_substr) - in;
  printf("nchars: %d\n", name_nchars);

  int out_nchars = name_nchars + strlen(out_substr) + 1;
  printf("outnchars: %d\n", out_nchars);
  *out = (char *)calloc(out_nchars, sizeof(char));
  if (out == NULL) {
    fprintf(stderr, "Could not allocate memory\n");
    return -1;
  }
  strncpy(*out, in, name_nchars);
  strcat(*out, out_substr);
  printf("outsize: %lu\n", strlen(*out));
  return 0;
}

char *read_file(char *fname) {
  char *str = NULL;
  FILE *fp = fopen(fname, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Could not open file %s\n", fname);
    return NULL;
  }

  fseek(fp, 0, SEEK_END);
  int f_length = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  str = (char *)malloc(f_length * sizeof(char));
  if (str == NULL) {
    fprintf(stderr, "Could not allocate memory\n");
    fclose(fp);
    return NULL;
  }
  int ret = fread(str, sizeof(char), f_length, fp);
  if (ret != f_length) {
    fprintf(stderr,
            "Could not read complete file: %s. Read %d out of %d chars\n",
            fname, ret, f_length);
    free(str);
    str = NULL;
  }

  fclose(fp);
  return str;
}

int main(int argc, char *argv[]) {
  printf("Lexer test\n");

  if (argc < 2) {
    printf("Usage: lexer_test [input]\n");
    return EXIT_SUCCESS;
  }

  char *input_fname = argv[1];
  char *output_fname = NULL;
  str_replace(input_fname, &output_fname, ".monkey", ".expected");
  printf("input: %s\n", input_fname);
  printf("Output: %s\n", output_fname);

  char *input = read_file(input_fname);
  printf("Input: %s\n", input);

  // free memory
  free(output_fname);
  free(input);

  return EXIT_SUCCESS;
}
