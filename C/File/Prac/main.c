#include <stdio.h>

// int main()
// {
//     FILE *f_in = fopen("input1.txt", "r");
//     FILE *f_out = fopen("output1.txt", "w");
//     char buf[256] = {0};
//     while (fgets(buf, sizeof(buf), f_in) != NULL)
//     {
//         fputs(buf, f_out);
//     }
//     fclose(f_out);
//     fclose(f_in);
//     f_out = NULL;
//     f_in = NULL;
//     return 0;
// }

// typedef struct Student_data
// {
//     char name[20];
//     double score1;
//     double score2;
// } Stu_data;
// int main()
// {
//     FILE *f_in = fopen("input2.txt", "r");
//     FILE *f_out = fopen("output2.txt", "w");
//     Stu_data s = {0};
//     if ((f_in == NULL) || (f_out == NULL))
//     {
//         perror("fopen");
//         return 1;
//     }
//     // 打印表頭，這裡使用%-20s來確保姓名欄位至少為20個字符寬
//     fprintf(f_out, "%-20s%-10s%-10s\n", "student", "average", "grade");
//     while ((fscanf(f_in, "%s %lf %lf", s.name, &s.score1, &s.score2)) != EOF)
//     {
//         double avg = (s.score1 + s.score2) / 2.0;
//         // 使用%-20s來控制姓名欄位寬度，%.2lf控制平均成績顯示2位小數
//         fprintf(f_out, "%-20s%-10.2lf", s.name, avg);
//         if (avg < 60)
//         {
//             fprintf(f_out, "%-10s\n", "fail");
//         }
//         else
//         {
//             fprintf(f_out, "%-10s\n", "pass");
//         }
//     }
//     fclose(f_in);
//     fclose(f_out);
//     f_in = NULL;
//     f_out = NULL;
//     return 0;
// }

int main()
{
    int count[26] = {0};
    char ch;
    FILE *fp = fopen("input3.txt", "r");
    while ((ch = fgetc(fp)) != EOF)
    {
        int idx = 0;
        if ((ch >= 'A') && (ch <= 'Z'))
        {
            idx = ch - 65;
            count[idx] += 1;
        }
        if ((ch >= 'a') && (ch <= 'z'))
        {
            ch -= 32;
            idx = ch - 65;
            count[idx] += 1;
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        printf("%d ", count[i]);
    }
    fclose(fp);
    fp = NULL;
    return 0;
}
