int lengthOfLastWord(char* s) {
    int l=0;
    char*p=s;
    while(*s!='\0'){
        s++;
    }
    s--; 
    while(s>=p&&*s==' '){
        s--;
    }
    while(s>=p&&*s!=' '){
        s--;
        l++;
    }

    return l;

}