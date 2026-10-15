//实验内容 2：编写一个程序，对于给定的正整数 n，求 1 ~n 的素数个数
//给出这两种解法，对于相同的 n，给出这两种解法的结果和求解时间，并用相同数据进行测试。（设计性实验）
#include <iostream>
#include <cmath>//计算平方根
#include <vector>
#include <ctime>
using namespace std;

//判断一个数是否为素数
bool isPrime(int n){
    if (n<2){
        return false;//小于2的不是素数
    }
    else{
        for(int i=2;i<=sqrt(n);i++){//找因子只需要循环到根号下n，有一个因子大于根号N，那么另一个因子必然小于根号N
            if (n%i==0){
                return false;
            }
        }
        return true;
    }
}            
//方法一：试除法——一次次试能不能被因子整除
int PrimebyDivision(int n){
    int count=0;
    for(int i=2;i<=n;i++){
        if (isPrime(i)){
            count++;
        }
    }
    return count;
}

//埃氏筛选法——素数的整数倍一定是合数，找出合数，剩下的就是素数
int PrimebySieve(int n){
    if (n < 2) {
		return 0;
	}
    std::vector<bool> isPrime(n+1,true);//创建一个布尔动态数组来标记素数，数组的长度为n+1，假设初始所有数都是素数（true)
    for(int i=2;i<=sqrt(n);i++){//遍历到根号下n
        if(isPrime[i]==true){//如果i是素数
            for(int j=i*i;j<=n;j+=i){//标记i的所有倍数为非素数
                isPrime[j]=false;
            }

        }
    }
    //统计素数的个数
    int count=0;
    for(int i=2;i<=n;i++){
        if(isPrime[i]==true){
            count++;
        }
    }
    return count;
}

//主函数测试
int main(){
    int n;
    cin>>n;
    if (n<=0){
        cout<<"请输入一个正整数"<<endl;
    }
    else{
        //方法一
        clock_t start1=clock();
        int count1=PrimebyDivision(n);
        clock_t end1=clock();
        double time1=(double)(end1-start1)/CLOCKS_PER_SEC;
        cout<<"方法一：试除法"<<endl;
        cout<<"素数个数为："<<count1<<endl;
        cout<<"求解时间为："<<time1<<"秒"<<endl;

        //方法二
        clock_t start2=clock();
        int count2=PrimebySieve(n);
        clock_t end2=clock();
        double time2=(double)(end2-start2)/CLOCKS_PER_SEC;
        cout<<"方法二：埃氏筛选法"<<endl;
        cout<<"素数个数为："<<count2<<endl;
        cout<<"求解时间为："<<time2<<"秒"<<endl;
    }
    return 0;
}