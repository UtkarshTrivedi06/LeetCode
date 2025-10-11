
bool isValid(char *s) {
    int n = strlen(s);
    if (n == 0) {
        return true;
    }

    char *stack = (char *)malloc(n * sizeof(char));
    if (stack == NULL) {
        return false;
    }
    
    int top = -1;

    for (int i = 0; i < n; i++) {
        char current_char = s[i];

        if (current_char == '(' || current_char == '{' || current_char == '[') {
            top++;
            stack[top] = current_char;
        } 
        else {
            if (top == -1) {
                free(stack);
                return false;
            }

            char open_bracket = stack[top];

            if ((current_char == ')' && open_bracket != '(') ||
                (current_char == '}' && open_bracket != '{') ||
                (current_char == ']' && open_bracket != '[')) {
                
                free(stack);
                return false;
            }

            top--;
        }
    }

    bool result = (top == -1);

    free(stack); 

    return result;
}