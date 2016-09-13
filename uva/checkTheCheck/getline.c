#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <malloc.h>

bool trim(char **line) 
{
    char *temp = *line;
    char *read = NULL, *write = NULL;
    bool firstchar = false;
    size_t length = strlen(*line);
    int i = 0;

    i = length-1;
    while(i>=0 && isspace(temp[i])) { i--; }
    temp[i+1] = '\0'; 

    read = write = *line;
    while(read != NULL && isspace(*read)) {
        read++;
    }

    while(*write++ = *read++);

    return true;
}

bool GetNextToken(char **lineptr, char **token)
{
    char *temp = *lineptr;
    char *temptoken = NULL;
    int length = 0;
    bool rval = false;

    printf("token out : ");
    // eat space
    while(*temp != '\0' && isspace(*temp)) { length++; temp += 1; }

    // here we handle operator vs string
    if(*temp == '<' || *temp == '>' || *temp == '|' || *temp == ';') {
        if((*temp == '<' && *(temp+1) == '<') || 
            (*temp == '>' && *(temp+1) == '>') || 
            (*temp == '|' && *(temp+1) == '|')) 
            length += 2;
        else 
            length +=1;
    }
    else {
        while (*temp != ' ' && *temp != '\0' && *temp != '\n') {
            putchar(*temp);
            length++;
            temp++;
        }
    }

    if(length == 0)
        return rval;

    temptoken = (char*)malloc(sizeof(char) * (length+1)); 
    if(NULL == temptoken) {
        return rval;
    }

    temp = *lineptr;
    strncpy(temptoken, temp, length);

    temptoken[length] = '\0';
    *lineptr += length;
    *token = temptoken;
    rval = true;

    return rval;    
}

int main(int argc, char *argv[])
{
    char *line = NULL;
    size_t length;
    char *token = NULL;

    while (-1 != getline(&line, &length, stdin)) {
        trim(&line);
        while (false != GetNextToken(&line, &token)) {
            printf("\ntoken(%s) line(%s); ", token, line);
            free(token);
            token = NULL;
        }
    }
     
    return 0;
}
