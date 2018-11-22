//
//  main.c
//  thiagomoraes-ord-uri
//
//  Created by Thiago Moraes on 19/11/18.
//  Copyright © 2018 Thiago Moraes. All rights reserved.
//

#include <stdio.h>
#include <string.h>

struct crianca{
    char nome[21];
    char *temp;
    int tend;
};

void bubblesort(struct crianca v[], int n){
    int i, j, cmp;
    struct crianca temp[n];
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1; j++){
            cmp = strcmp(v[j].nome, v[j + 1].nome);
            
            if (cmp > 0){
                strcpy(temp[0].nome, v[j + 1].nome);
                strcpy(v[j + 1].nome, v[j].nome);
                strcpy(v[j].nome, temp[0].nome);
            }
        }
}

int main() {
    
    int num = 0;
    char nome[21];
    scanf("%d",&num);
    struct crianca nomes[num];
    char *t;
    char bom[4] = "+";
    char mau[4] = "-";
    int bons = 0;
    int maus = 0;
    
    for (int i = 0; i<num; i++) {
        scanf("%s",nome);
        t = strtok(nome," ");
        while (t != NULL) {
            if (strcmp(t, bom) == 0) {
                bons += 1;
            } else if(strcmp(t, mau) == 0){
                maus += 1;
            } else {
                strcpy(nomes[i].nome, t);
            }
            t = strtok (NULL," ");
        }
    }
    
    bubblesort(nomes, num);
    
    for (int i=0; i<num; i++){
        printf("%s\n",nomes[i].nome);
    }
    printf("\nSe comportaram: %d | Nao se comportaram: %d", bons, maus);
    
    
    return 0;
}
