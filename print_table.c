// code that prints the table on which game will be played

void print_table() {
  for (int i = 0; i < 5; i++) {
    for (int n = 0; n < 11; n++) {
      printf("%c", pattern[i][n]);
    }
  printf("\n");
  }
}
