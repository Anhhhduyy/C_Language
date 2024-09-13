#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


char str[] = "Hi gu. lo mu. hello anh em. doi la the!";

uint8_t sizeText(char text[]){
    uint8_t count = 0;
    while (*text != '\0')
    {
        count++; //tăng biến đếm mỗi khi gặp 1 kí tự
        text++; //Chuyển con trỏ tới vị trí tiếp theo trong chuõi
    }
}

void capital_Letter(char string[]){
    while (*string != '\0') //vòng lặp chạy qua từng kí tự trong chuỗi đến khi kết thúc
    {
        top:
        if(*string == '.'){
            string++;
            while (*string != '\0')
            {
                if(*string == ' ') string++;
                *string = *string - 32; //-32 để chuyển đổi chữ cái thường thành hoa trong bảng mã ascii
                string++;
                goto top;
            }
            return;
        }
        string++;
    }
}

void find_text(char string[], char text[]){
    printf("\nText: %s\nKet qua: %s", text);
    uint8_t count = 0;
    uint8_t i = 0;
    while (*string != '\0')
    {
        if(*string == text[i]){
            i++;
            if(text[i] == '\0') {//vị trí null của text
                uint8_t location = count + 1 - i; //lây vị trí cuối cùng của text + 1 -i để ra vị trị đầu của text
                printf("Co\nvitri: %d\n\n", location);
                return;
            }
        }else { i = 0;}
    string++;
    count++;
    }
    printf("Khong co\n\n");
}

void replace_text(char string[], char text1[], char text2[]){
    uint8_t i = 0;
    uint8_t j = 0;
    while (string[j] != '0')
    {
        if(string[j] == text1[i]){
            i++;
            if(text1[i] == '\0') break;
        }else i = 0;
        j++;
    }
    if(text1[i] != '\0') printf("Khong co\n");
    
    //lưu lại location
    uint8_t location_final = j;
    uint8_t location_first = j + 1 - i;
    uint8_t length_string = sizeText(str);
    uint8_t length_update = length_string - sizeText(text1) + sizeText(text2);

    if(length_string < length_update){
        string[length_update] = '\0';
        length_update--;
        length_string--;
        while (length_update > location_first + sizeText(text2) - 1)
        {
            string[length_update] = string[length_string];
            length_update--;
            length_string--;
        }
        while (*text2 != '\0')
        {
            string[location_first] = *text2;
            location_first++;
            text2++;
        }
    }else {
        while (*text2 != '\0')
        {
            string[location_first] = *text2;
            location_first++;
            text2++;
        }
        //khi vòng lặp kết thúc first sẽ chỉ đến vị trí ngay sau kí tự cuối đã sao chép từ text2
        //text2 sẽ chỉ đến null của text2
        //vị trí final sẽ đc tăng lên 1 
        
        location_final++;
        while (location_first < length_update)
        {
            string[location_first] = string[location_final];
            location_first++;
            location_final++;
        }
        string[length_update] = '\0';
        //vòng lặp sẽ sao chép các kí tự từ final vào first 
        //cho đến khi first = length vòng lặp sẽ kết thúc
    }
}


int main(int argc, char const *argv[])
{
    capital_Letter(str);
    
    //find_text(str, "little girl leaning");
    //replace_text(str, "little girl leaning", "hello");
    printf("\n%s\n\n", str);
    // char str[] = "abc";
    // str[0] = str[0] - 32;
    // printf("%s", str);
    return 0;
}

 