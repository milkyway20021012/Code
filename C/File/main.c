#include <stdio.h>
#include <string.h>

// int main(){
// 開啟文件
//     FILE* pf = fopen("test.txt","r");
//     if(pf == NULL){
//         perror("fopen fail");
//         return 1;
//     }
//     // 讀取文件...
//     // 關閉文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// int main()
// {
//        // Open file
//        FILE *fp = fopen("data.txt", "r");
//        if (fp == NULL)
//        {
//               perror("fopen");
//               return 1;
//        }
//        // Read / Write
//        // for (int i = 'a'; i < 'z'; ++i)
//        // {
//        //        fputc(i, fp); // int fputc ( int character, FILE * stream );
//        // }
//        char ch;
//        while ((ch = fgetc(fp)) != EOF)
//        {
//               printf("%c", ch);
//               // printf(" ");
//        }
//        // Close File
//        fclose(fp);
//        return 0;
// }

// int main()
// {
//        char buf[256];
//        // open file
//        FILE *fp = fopen("data.txt", "r");
//        // read / write
//        // strcpy(buf, "Hello I am cmx");
//        fputs("Hello World\n", fp);
//        fputs("Hello Bit\n", fp);
//        // printf("%s", fgets(buf, sizeof(buf), fp));
//        // char ch;
//        // while ((ch = fgetc(fp)) != EOF)
//        // {
//        //        printf("%c", ch);
//        // }
//        while (fgets(buf, sizeof(buf), fp) != NULL) // If read EOF or occur error, fgets will return NULL
//        {
//               printf("%s", buf);
//        }
//        // close file
//        fclose(fp);
//        return 0;
// }

// int main()
// {
//        FILE *fp = fopen("data.txt", "r");
//        if (fp == NULL)
//        {
//               perror("fopen");
//               return 1;
//        }
//        char arr[20];
//        int i_1 = 20;
//        double f = 3.14;
//        int i_2;
//        double f_2;
//        // strcpy(arr, "Hello World");
//        // fprintf(fp, "%s\n%d\n%f", arr, i_1, f);
//        fscanf(fp, "%s %d %lf", arr, &i_2, &f_2);
//        printf("%s\n%d\n%.2f", arr, i_2, f_2);
//        return 0;
// }

// struct s
// {
//        char arr[20];
//        int data;
//        float f;
// };
// int main()
// {
//        /*
//        sprintf sscanf : 有些數據在記憶體中存儲的時候可能沒有辦法精確存儲
//        這個函數可以將數據轉換成字符串的形式，就可以解決沒有辦法精確存儲的問題
//        */
//        // int sprintf ( char * str, const char * format, ... );
//        // int sscanf ( const char * s, const char * format, ...);
//        struct s S = {"Eee", 20, 3.14};
//        char buf[256] = {0};
//        sprintf(buf, "%s %d %.5f", S.arr, S.data, S.f);
//        printf("數據字符串形式：%s\n", buf);
//        struct s T = {0};
//        sscanf(buf, "%s %d %f", T.arr, &(T.data), &(T.f));
//        printf("數據格式化形式：%s %d %.5f\n", T.arr, T.data, T.f);
//        return 0;
// }

// int main()
// {
//        FILE *fp = fopen("bin.txt", "rb");
//        if (fp == NULL)
//        {
//               perror("fopen");
//               return 1;
//        }
//        int arr[] = {1, 2, 3, 4, 5};
//        // fwrite(arr, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), fp);
//        int arr2[5] = {0};
//        fread(arr2, sizeof(int), 5, fp);
//        for (int i = 0; i < 5; ++i)
//        {
//               printf("%d ", arr2[i]);
//        }
//        fclose(fp);
//        return 0;
// }

// fseek : int fseek ( FILE * stream, long int offset, int origin ); // origin : SEEK_SET SEEK_CUR SEEK_END
// ftell :  返回文件指针相对于起始位置的偏移量
// rewind : 让文件指针的位置回到文件的起始位置
int main()
{
       FILE *fp = fopen("data.txt", "r");

       // fputs("abcdefg", fp);

       char ch;
       ch = fgetc(fp);
       printf("%c", ch);
       fseek(fp, 3, SEEK_SET);
       ch = fgetc(fp);
       printf("%c", ch);
       return 0;
}
