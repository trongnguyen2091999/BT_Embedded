#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*-------------------Đổi từ số ra chữ----------------------*/
//VD: 1354765 => MOT TRIEU BA TRAM NAM MUOI TU NGHIN BAY TRAM SAU MUOI LAM DONG
//Ý tưởng: Chia số làm 3 Phần, xử lý từng Phần & In 
//VD: 1354765 => |"1"|"354"|"765"|
//            => |"1"| hàng Triệu
//            => |"354"| hàng Nghìn
//            => |"765"| hàng Đồng
//Phần hàng "Nghìn" + hàng "Đồng"  được xử lý ra từng TH => Nhảy đến hàm printCase() để in.


typedef struct{
    uint8_t size;
    uint8_t *firstAdd;
} typeArray;

/*---------------------Hàm đổi ra đơn vị------------------------*/
void readUnit(uint8_t num){
    switch (num)
    {
    case 0:
        printf("KHONG ");
        break;
    case 1:
        printf("MOT ");
        break;
    case 2:
        printf("HAI ");
        break;
    case 3:
        printf("BA ");
        break;
    case 4:
        printf("BON ");
        break;
    case 5:
        printf("NAM ");
        break;
    case 6:
        printf("SAU ");
        break;
    case 7:
        printf("BAY ");
        break;
    case 8:
        printf("TAM ");
        break;
    case 9:
        printf("CHIN ");
        break;
    default:
        printf("ERROR!! KHONG HOP LE\n");
        break;
    }
}

/*---------------------Hàm đổi ra thập phân------------------------*/
void readDecimal(uint8_t dec){
    switch (dec)
    {
    case 0:
        printf("DONG\n");
        break;
    case 1:
    case 4:
        printf("MUOI ");
        break;
    case 3:
        printf("NGHIN  ");
        break;
    case 2:
    case 5:
        printf("TRAM ");
        break;
    case 6:
        printf("TRIEU  ");
        break;
    default:
        printf("ERROR!! KHONG HOP LE\n");
        break;
    }
}

/*---------------------Hàm nhập số------------------------*/
void inputNumber(uint32_t *number, typeArray *array){
    do
    {
        printf("\nEnter Number: ");
        scanf("%d",number);
    } while (*number < 0 || *number > 10000000);

    array->size = 7;
    array->firstAdd = (uint8_t*)calloc(array->size,sizeof(uint8_t));

    //Tách từng chữ số và nhập ngược vào mảng
    // 1234567
    //arr[] = {7, 6, 5, 4, 3, 2, 1}
    uint32_t reNum = *number;
    uint32_t last;
    for(int i = 0; i < array->size; i++){
        last = reNum % 10;
        array->firstAdd[i] = last;
        reNum /=10;
    }
}

/*---------------------Hàm in phần "Nghìn" & phần "Đồng"------------------------*/
void printCase(uint8_t value, typeArray array, uint8_t from){

    //Kiểm tra & in ra chữ số đầu tiên hàng "Nghìn" or hàng "Đồng"
    int check = 0;
    for (int i = from+2; i < array.size; i++)
    {
        if(array.firstAdd[i] > 0)
            check = 1;
    }
    if(check){
        readUnit(array.firstAdd[(from+2)]);
        readDecimal(from+2);
        if(array.firstAdd[(from)] > 0 && array.firstAdd[(from+1)] == 0)
            printf("LINH ");
    }
    
    //Kiểm tra & in ra chữ số tiếp theo hàng "Nghìn" or hàng "Đồng"
    switch (value)
    {
    case 0:
    case 1:
        readDecimal(from);
        break;
    case 2:
    case 3:
        if(array.firstAdd[(from+1)] > 1){
            readUnit(array.firstAdd[(from+1)]);
            readDecimal(from+1);
        }else{
            readDecimal(from+1);
        }
        readDecimal(from);
        break;
    case 4:
    case 5:
        readUnit(array.firstAdd[(from)]);
        readDecimal(from);
        break;
    case 6:
    case 7:
        if(array.firstAdd[(from+1)] > 1){
            readUnit(array.firstAdd[(from+1)]);
            readDecimal(from+1);
        }else{
            readDecimal(from+1);
        }
        if(array.firstAdd[(from)] == 5){
            printf("LAM ");
            readDecimal(from); 
        }else{
            readUnit(array.firstAdd[(from)]);
            readDecimal(from);
        }
        break;
    default:
        printf("ERROR!! KHONG HOP LE\n");
        break;
    }
}

/*---------------------Hàm thực hiện đọc số------------------------*/
void readNumber(typeArray array){

    //Đọc phần "Triệu"
    if(array.firstAdd[array.size-1] > 0){
        readUnit(array.firstAdd[array.size-1]);
        readDecimal(array.size-1);
    }

    //Tính toán phần "Nghìn"
    uint8_t x = 0;
    for(int i = array.size-4; i < array.size-1; i++){
        uint8_t a = (array.firstAdd[i] > 0) ? 1 : 0;
        x = x*2 + a;
    }
    
    //Tính toán phần "Đồng"
    uint8_t y = 0;
    for(int i = array.size-7; i < array.size-4; i++){
        uint8_t a = (array.firstAdd[i] > 0) ? 1 : 0;
        y = y*2 + a;
    }
    
    //Tính toán các TH phần "Nghìn" + phần "Đồng"
    if(x + y == 0){ 
        printf("DONG\n"); 
    }
    else{
        if(x > 0){
            printCase(x,array,array.size-4);
            if(y > 0)
                printCase(y,array,array.size-7);
            else
                printf("DONG\n");
        }else{
            printCase(y,array,array.size-7);
        }
    }
}

int main(int argc, char const *argv[])
{
    uint32_t num;
    typeArray arr;

    inputNumber(&num, &arr);
    readNumber(arr);
    return 0;
}
