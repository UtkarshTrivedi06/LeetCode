#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize == 0) {
        char *result = (char *)malloc(1 * sizeof(char));
        if (result) {
            result[0] = '\0';
        }
        return result;
    }

    char *ref_str = strs[0];
    int len_ref = strlen(ref_str);
    
    for (int i = 0; i < len_ref; i++) {
        char current_char = ref_str[i];

        for (int j = 1; j < strsSize; j++) {
            
            if (i == strlen(strs[j]) || strs[j][i] != current_char) {
                
                char *result = (char *)malloc((i + 1) * sizeof(char));
                if (result) {
                    strncpy(result, ref_str, i);
                    result[i] = '\0';
                }
                return result;
            }
        }
    }
    
    char *result = (char *)malloc((len_ref + 1) * sizeof(char));
    if (result) {
        strcpy(result, ref_str);
    }
    return result;
}