#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

// 漏洞 1：缓冲区溢出（最经典高危）
void buffer_overflow() {
  char buf[16];
  cout << "输入内容：";
  // 危险：无长度限制
  gets(buf); // ❌ 已废弃函数，必溢出
  cout << "你输入了：" << buf << endl;
}

// 漏洞 2：格式化字符串漏洞
void format_string() {
  char user_input[100];
  cin >> user_input;
  printf(user_input); // ❌ 直接把用户输入当格式化字符串
}

// 漏洞 3：命令注入
void command_injection() {
  char filename[100];
  cout << "输入文件名：";
  cin >> filename;

  // ❌ 直接拼接用户输入执行系统命令
  char cmd[200];
  sprintf(cmd, "ls -l %s", filename); // Linux
  // sprintf(cmd, "dir %s", filename); // Windows
  system(cmd);
}

// 漏洞 4：内存越界读写
void out_of_bounds() {
  int arr[5] = {1, 2, 3, 4, 5};
  int idx;
  cin >> idx;
  cout << arr[idx] << endl; // ❌ 不检查下标范围
}

// 漏洞 5：空指针解引用
void null_pointer() {
  int *p = nullptr;
  *p = 10; // ❌ 直接写空指针
}

// 漏洞 6：使用 strcpy 无边界拷贝
void unsafe_strcpy() {
  char dst[10];
  char src[100];
  cin >> src;
  strcpy(dst, src); // ❌ 无边界，必溢出
}

// 漏洞 7：硬编码密码（严重）
void hardcode_secret() {
  // ❌ 密码直接写在代码里，逆向可轻易提取
  char password[] = "Admin@123456";
  char input[100];
  cin >> input;
  if (strcmp(input, password) == 0) {
    cout << "登录成功\n";
  }
}

// 漏洞 8：释放后使用（UAF）
void use_after_free() {
  int *data = (int *)malloc(4);
  // free(data);
  *data = 100; // ❌ 内存已释放仍使用
}

// 漏洞 9：栈内存地址泄露
void stack_leak() {
  int x = 10;
  printf("%p\n", &x); // ❌ 泄露栈地址，辅助攻击
}

// 漏洞 10：整数溢出
void integer_overflow() {
  unsigned char a = 255;
  a += 1; // ❌ 溢出变成 0
  cout << a << endl;
}

int main() {
  cout << "=== 危险测试程序 ===" << endl;
  buffer_overflow();
  // format_string();
  // command_injection();
  // out_of_bounds();
  // null_pointer();
  // unsafe_strcpy();
  // hardcode_secret();
  // use_after_free();
  // stack_leak();
  // integer_overflow();
  return 0;
}
