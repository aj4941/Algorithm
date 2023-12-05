int main(){
    
    int num;
    int count=0;
    int a[3];
    
    scanf("%d",&num);
    
    if(num<100) printf("%d",num);
    else{ // 100부터 시작이다.
        count=99;

        if(num==1000) num=999;
        
        for(int i=100 ; i<=num ; i++){
            
            a[2]=i/100;
            a[1]=(i-a[2]*100)/10;
            a[0]=i-a[2]*100-a[1]*10;
            
            if(a[2]-a[1]==a[1]-a[0]) count++;
            
        }
        
        printf("%d",count);
    } 
}