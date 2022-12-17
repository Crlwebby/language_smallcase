char* reverseLeftWords(char* s, int n){
    int length = strlen(s);
    char *result = malloc(sizeof(char) * (length + 1));
    strcpy(result,s + n);
    for(int i = 0; i < n; i++){
        result[length - n + i] = s[i];
    }
    result[length] = '\0';
    return result;
}

//好简单的题……做个玩一玩~