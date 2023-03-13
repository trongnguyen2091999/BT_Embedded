#include <stdio.h>

char arr[] = "The Grammy award-winning singer. who has been less active on digital platforms in recent weeks. explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien Needs a Friend podcast, alongside her brother Finneas";
// char arr[] = "The Grammy award-winning singer";
//  Cau 1: Viet mot chuyen dao nguoc VD: "Finneas brother her alongside .... Grammy The"
//  cau 2: In Hoa chu cai dau tien sau dau cham
//  Cau 3: Chuyen doi tat ca doan van thanh chu thuong
//  Cau 4: Chuyen doi tat ca doan van thanh chu hoa
/*
    Su dung bang ascII
*/


// Cau 1: Viet mot chuyen dao nguoc.
//        char arr[] = "The Grammy award-winning singer";
// chuoi sau khi dao : "singer award-winning Grammy The"
void reverse()
{
    int count = 0;              // khai bao bien dem count
    int length = sizeof(arr);   // gan length = chieu dai mang
    int i = length;             // khai bao bien i gan bang length
    while (i >= 0)       // Chay vong lap while xet dieu kien i>=0
    {
        i--;            // Giam "i" 1 don vi de xet phan tu cuoi cung
        if (arr[i] == ' ')      // Dat dieu kien mang "arr" tai vi tri "i" co phai la khoang trong (' ') ko?
                                // Muc dich de phan biet moi tu de dao lai vi tri
        {
            for (int j = i + 1; j < i + count; j++)     // Chay vong lap de in cac ki tu 
            {
                printf("%c", arr[j]);
            }
            printf("%c", ' ');          // in khoang trong (' ') sau khi het vong lap
            count = 0;          // Set lai gia tri count = 0
        }
        if (i == 0)         // TH vong lap chay toi phan tu dau tien cua mang
        {
            for (int c = i; c <= length; c++)   
            {
                if (arr[c] == ' ')
                {
                    for (int c1 = i; c1 < c; c1++)
                    {
                        printf("%c", arr[c1]);
                    }
                    break;
                }
            }
        }
        count++;            // tang gia tri count 
    }
    printf("\n \n");
}
// cau 2: in hoa chu cai dau tien sau dau cham
// char arr[] = "...weeks. explained..."; 
void upcaseAfterDot()
{
    int length = sizeof(arr);
    int i = length;
    while (i >= 0)
    {
        i--;
        if (arr[i] == '.')      
        {
            arr[i + 2] -= 32;   // cong them 2 de toi vi tri can in hoa
        }
    }
    printf("%s", arr);
    printf("\n \n");
}
// cau 2: in hoa tat ca chu trong chuoi
void upcaseAll()
{
    int length = sizeof(arr);
    int i = length;
    for (int i = 0; i < length; i++)
    {
        if 
        (
            (arr[i] >= 97) && (arr[i] <= 122)   // he thap phan cua ki tu thuong trong khoang 97 -> 122
        )        
        {
            arr[i] -= 32;   // he thap phan cua ki tu thuong -32 se thanh ki tu in hoa
        }
    }
    printf("%s", arr);
    printf("\n \n");
}
// cau 2: in thuong tat ca chu trong chuoi
void lowcaseAll()
{
    int length = sizeof(arr);
    int i = length;
    for (int i = 0; i < length; i++)
    {
        if 
        (
            (arr[i] >= 60) && (arr[i] <= 90)    // he thap phan cua ki tu in hoa trong khoang 60 -> 90
        )
        {
            arr[ i ] += 32;    // he thap phan cua ki in hoa +32 se thanh ki tu thuong
        }
    }
    printf("%s", arr);
    printf("\n \n");
}

int main(int argc, char const *argv[])
{
    printf("REVERSE THE STRING:\n");
    reverse();
    printf("UPCASE THE FIRST LETTER AFTER A DOT:\n");
    upcaseAfterDot();
    printf("UPCASE ALL WORDS OF THE STRING:\n");
    upcaseAll();
    printf("LOWCASE ALL WORDS OF THE STRING\n");
    lowcaseAll();
    return 0;
}
