#include<stdio.h>
#include<locale.h>
#include<string.h>
#include <stdbool.h>

bool strseg(const char *str_x, const char *str_y);
void istrue(bool func, char *word_1, char *word_2);

int main() {
    setlocale(LC_ALL, "Portuguese");
    char w1[20], w2[20];
    printf("Digite duas palavras: ");
    scanf("%s %s", w1, w2);
    istrue(strseg(w1, w2), w1,w2);
    return 0;

}

bool strseg(const char *str_x, const char *str_y){
    bool ckeck = true;
    int x = 0, y = 0;
    int len_x = strlen(str_x), len_y = strlen(str_y);

    if(len_x > len_y){
        return false;
    }
    else{
        while(y < len_y){
            if(str_x[0] == str_y[y]){
                x = 0;
                while(x < len_x && str_x[x] == str_y[y]){
                    x++;
                    y++;
                }
                if( x == len_x){
                    return true;
                }
            }
            y++;
        }
    }
    return false;
}

void istrue(bool func, char *word_1, char *word_2){
    if(func){
        printf("%s É segmento de %s", word_1, word_2);
    }
    else{
        printf("%s Não é segmento de %s", word_1, word_2);
    }

}
