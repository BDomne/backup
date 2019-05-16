
int maxArea(int* height, int heightSize) 
{
    int i, j, index1, index2, max=0, tmp, min;
    
    for(i=heightSize-1; i>0; --i)
    {
        index1=0;
        while(1)
        {
           index2=index1+i;
           min=height[index1]<height[index2]?height[index1]:height[index2];
           tmp=min*i;
           if(tmp > max){
               max=tmp;
           }
           index1++;
           if(index1+i > heightSize-1){
               break;
           }
        }
    }
    
    return max;
}
