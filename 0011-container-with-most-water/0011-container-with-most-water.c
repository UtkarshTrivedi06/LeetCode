int maxArea(int* height, int heightSize) {
    int m=0,h=0;
    /*for(int i=0;i<heightSize-1;i++){
        for(int j=i+1;j<heightSize;j++){
            h=pow(pow(height[i]-height[j],2),0.5);
            if((height[i]-h)*(j-i)>m&&height[j]<=height[i]){
                m=(height[i]-h)*(j-i);
            }else if((height[j]-h)*(j-i)>m&&height[i]<height[j]){
                m=(height[j]-h)*(j-i);
            }
        }
    }*/
    int left = 0, right = heightSize - 1;

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int area = h * (right - left);
        if (area > m) {
            m = area;
        }
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return m;
}


