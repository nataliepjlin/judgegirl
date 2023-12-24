struct string_count {
  char seen[80];
  int count;
};
 
int compare_and_add(char *string, struct string_count strings[]);
void sort(struct string_count strings[]);
void print(struct string_count strings[]);