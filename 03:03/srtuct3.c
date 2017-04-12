struct Name {
  char first[20];
  char last[20];
};

struct Grade {
  char id[10];
  struct Name name;
  int grade;
};

struct Grade c2510[120];
strcpy(c2510[0].id, "a666666666");
strcpy(c2510[0].name.first, "monty");
strcpy(c2510[0].name.last, "burns");
c2510[0].grade = 15;

int read_grade(FILE *fp, struct Grade *g) {
  fscanf(fp, "%ds %s %s %d", g->id, g->name.first, g->name.last, &g->grade) == 4;
}

/* Note: no validation */
