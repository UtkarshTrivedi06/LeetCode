int v(char x){
    switch(x){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}
int romanToInt(char* r) {
    int s=0,p=0,v1;
    char c;
    while(*r!='\0'){
        c=*r;
        v1=v(c);
        if(v1==5*p || v1==10*p){
            s+= v1-2*p;
        }else{
            s+=v1;
        }
        p=v1;
        r++;
    }
    return s;
}