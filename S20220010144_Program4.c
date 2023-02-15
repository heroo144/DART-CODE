#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *xy, *xy2;
    xy = fopen("S20220010144_InputEncrypted.txt", "r");
    xy2 = fopen("S20220010144_OutputEncrypted.txt", "w");

    if (xy == NULL || xy2 == NULL) {
        printf("Error opening file");
        exit(1);
    }

    int ans;
    printf("Enter the number to be encrypted: ");
    scanf("%d", &ans);

    char c;
    while ((c = fgetc(xy)) != EOF) {
        c = c + ans;
        fputc(c, xy2);
    }

    fclose(xy);
    fclose(xy2);

    xy2 = fopen("S20220010144_OutputEncrypted.txt", "r");
    if (xy2 == NULL) {
        printf("Error opening file");
        exit(1);
    }

    printf("Contents of the encrypted file:\n");
    while ((c = fgetc(xy2)) != EOF) {
        putchar(c);
    }

    fclose(xy2);

    return 0;
}
