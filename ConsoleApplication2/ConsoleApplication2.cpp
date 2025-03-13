

#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*问题：
    
    Unicode 模式：const wchar_t* (宽字符)
    多字节字符集 (MBCS)：const char* (单字节)

    两者不兼容，

    涉及强制转换

    不知道怎么办

*/

#define MAX_USERS 100//最多用户数量

typedef struct {//用户信息结构体
    char username[50];
    char password[50];
    int score;
    
} User;


//全局变量定义区
IMAGE img;
IMAGE img_a;

ExMessage m;
char ch;
        
char typein_username[21];//用户输入的用户名和密码
char typein_password[10];

int username_count = 0;//用户已输入用户名、密码字数
int password_count = 0;



int textboxlength;//登陆界面文字框大小
int textboxheight;

int textbox1_x;//登陆界面文字框位置
int textbox1_y;

int textbox2_x;
int textbox2_y;

int status_type=0;


void startupLoginPage() {
    loadimage(&img, L"..\\..\\pic\\loginpage.png");//加载登陆背景
    loadimage(&img_a, L"..\\..\\pic\\loginpage_title.png");
    initgraph(800, 600);
    setbkcolor(TRANSPARENT);

    textboxlength = 200;//登陆界面文字框大小
    textboxheight = 30;
    
    textbox1_x = 550;//登陆界面文字框位置
    textbox1_y = 150;
    
    textbox2_x = 550;
    textbox2_y = 200;


}

void showLoginPage() {
    
    putimage(0, 0, &img);//登陆界面背景
    //setbkcolor(TRANSPARENT);
    putimage(550, 37, &img_a);

    setfillstyle(BS_SOLID, WHITE);
    bar(textbox1_x, textbox1_y, textbox1_x + textboxlength, textbox1_y + textboxheight);
    bar(textbox2_x, textbox2_y, textbox2_x + textboxlength, textbox2_y + textboxheight);
}

void updateString(char* str,char ch,int charCount,int status) {
    switch (ch)
        {            
    case '\r': 
        str[charCount] = '\0';//若接收到enter则为字符串结尾
        charCount = 0;
        status = 0;
        break;
    case'\b':
        if(charCount!=0)
            str[charCount--] = '\0';
        break;
    default:
        str[charCount] = ch;//将接收到的字符加到输入的字符串结尾
        charCount++;
        break;
            }
}

void updateWithinputLoginpage() {
    
    //m = getmessage(EX_MOUSE | EX_KEY);//捕捉到鼠标信息时//获取一条鼠标信息
    
    
    int username_charCount = 0;
    int password_charCount = 0;

    while (peekmessage(&m, EX_MOUSE | EX_KEY)) {
            if (m.message == WM_LBUTTONDOWN) {
                settextcolor(BLACK);

            if ((m.x >= textbox1_x && m.x <= textbox1_x + textboxlength
                && m.y >= textbox1_y && m.y <= textbox1_y + textboxheight)) {
                status_type = 1;
                outtextxy(m.x, m.y, L"|");
            }else if ((m.x >= textbox2_x && m.x <= textbox2_x + textboxlength)
                && (m.y >= textbox2_y && m.y <= textbox2_y + textboxheight)) {
                status_type = 2;
            }
            else {
                status_type = 0;
            }
        }
        
        if (m.message == WM_CHAR && status_type != 0) {

            char ch = (char)m.vkcode;

            if (status_type == 1) {
                updateString(typein_username, ch, username_charCount, status_type);
                outtextxy(textbox1_x, textbox1_y, typein_username[20]);
            }
            else if (status_type == 2) {
                updateString(typein_password, ch, password_charCount, status_type);
            
                int i;
                for (i = 0; i < password_charCount; i++) {
                    outtextxy(textbox2_x+10*i, textbox2_y, L"*");
                }
            
            }

        }

    }
    
    

}

void updateWithoutinputLoginpage() {
    system("cls");
}

int loadUserFile(User *user) {
    FILE* fp;
    int i=0;
    errno_t err;
    
    err=fopen_s(&fp, "..\\..\\userinfo\\userinfo.txt", "r");
    if (err != 0) {
        printf("无法打开文件\n");
    }
    else {char line[256];
        while (fgets(line, sizeof(line), fp) != NULL) {//这样行吗？我不知道。。。
            char* ptr=NULL;
            
            line[strcspn(line, "\n\r")] = '\0';//换掉换行符
            char* token = strtok_s(line, ",",&ptr);//使用strtok分割字段，提取用户名
            strcpy_s(user[i].username, sizeof(user[i].username), token);
            
            if (!token) continue;  // 跳过空行或无效行
            //继续分割同一行的后续内容（strtok传入NULL）
            token = strtok_s(NULL, ",", &ptr);
            
            if (!token) continue;  // 密码字段缺失时跳过该用户
            strcpy_s(user[i].password, sizeof(user[i].password), token);
            token = strtok_s(NULL, ",", &ptr);
            
            if (!token) continue;  // 密码字段缺失时跳过该用户
            user[i].score = atoi(token);
            /* 解析成绩部分：
              初始化当前用户的成绩计数器 */
            
            i++;
        }
        fclose(fp);
        //测试代码printf("%s\n%s\n历史最好成绩：%d分", user[0].username, user[1].password,user[0].score);
        //妈妈他终于对了。。。
    }
    

    
        return i;

}

void entry(int userCount) {

}



void loginPage() {//登录页面函数
    User userptr[MAX_USERS];
    int userCount;
    
    startupLoginPage();
    
    userCount=loadUserFile(userptr);
    //测试代码printf("%d", userCount);
    
    while (1) {
        showLoginPage();
        updateWithinputLoginpage();
        updateWithoutinputLoginpage();
    }
}

void startup() {//游戏初始化相关函数

}

void show() {

}

void  updateWithoutInput() {//无输入更新

}

void updateWithInput() {//有输入更新

}


int main()
{
    loginPage();
    startup();
    while (1) {
        show();
        updateWithoutInput();
        updateWithInput();
    }
}

