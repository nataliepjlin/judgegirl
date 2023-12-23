// #include<stdio.h>
int gcd(int a, int b){
    return (a % b) ? (gcd(b, a % b)) : (b);
}
int value(int type, int width, int height, int length){
    int val, unit;

    if(type == 79) unit = 30;
    else if(type == 47) unit = 10;
    else if(type == 29) unit = 4;
    else if(type == 82) unit = 5;
    else if(type == 26) unit = 3;
    else if(type == 22) unit = 9;
    else{
        val = -1;
        return val; 
    }

    if(width <= 0 || height <= 0 || length <= 0){
        val = -2;
        return val;
    }

    int g = gcd(gcd(width, height), length);
    int vol = g * g * g;
    val = (vol * vol * unit) * (width * height * length / vol);
    return val;
}
// int main(){
//     int type, width, height, length;
//     scanf("%d%d%d%d", &type, &width, &height, &length);
//     int val = value(type, width, height, length);
//     printf("%d\n", val);
//     return 0;
// }