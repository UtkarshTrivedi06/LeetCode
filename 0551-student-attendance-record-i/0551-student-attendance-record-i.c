bool checkRecord(char* s) {
    int a=0,l=0;
    while(*s!='\0'){
        if(*s=='A'){
            a++;
        }
        if(*s=='L'){
            l++;
        }else{
            l=0;
        }
        if(l>=3){
            return false;
        }
        if(a>=2){
            return false;
        }
        s++;
    }
    return true;
}