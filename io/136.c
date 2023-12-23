#include<stdio.h>
#define LEN 81
typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;
int main(){
    char infile[LEN], outfile[LEN];
    scanf("%s%s", infile, outfile);
    FILE *fin = fopen(infile, "rb");
    FILE *fout = fopen(outfile, "w");
    Student s;
    fprintf(fout, "<table border=\"1\">\n<tbody>\n");
    while(fread(&s, sizeof(Student), 1, fin) != 0){
        fprintf(fout, "<tr>\n");
        fprintf(fout, "<td>%s</td>\n", s.name);
        fprintf(fout, "<td>%d</td>\n", s.id);
        fprintf(fout, "<td>%s</td>\n", s.phone);
        fprintf(fout, "<td>%f, %f, %f, %f</td>\n", s.grade[0], s.grade[1], s.grade[2], s.grade[3]);
        fprintf(fout, "<td>%d, %d, %d</td>\n", s.birth_year, s.birth_month, s.birth_day);
        fprintf(fout, "</tr>\n");
    }
    fclose(fin);
    fprintf(fout, "</tbody>\n</table>\n");
    fclose(fout);
}