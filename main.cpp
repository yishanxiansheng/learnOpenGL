#include <glew.h>
#include <glfw3.h>
#include <iostream>

using namespace std;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    //如果按下ESC，把windowShouldClose设置为True，外面的循环会关闭应用
    if(key==GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);//GL_TRUE == true
    std::cout<<"ESC"<<mode;
}

//Mac Clion OpenGL开发环境配置 https://zhuanlan.zhihu.com/p/263665409 记得CMakeLists的版本号需要修改
int main(void)
{
    //初始化GLFW库
    if(!glfwInit())
        return -1;
    //创建窗口以及上下文
    GLFWwindow* window = glfwCreateWindow(640, 480, "hello world", NULL, NULL);
    if(!window)
    {
        //创建失败会返回NULL
        glfwTerminate();
    }
    //建立当前窗口的上下文
    glfwMakeContextCurrent(window);

    ////注册按键回调函数，需要在渲染循环初始化之前注册
    glfwSetKeyCallback(window, key_callback);

    //渲染循环，直到用户关闭窗口，否则渲染一次就退出
    while(!glfwWindowShouldClose(window))
    {
        /*******轮询事件*******/
        glfwPollEvents();

        /*******渲染*******/
        //选择清空的颜色RGBA  每次渲染的时候清空上一次的渲染结果，清空后的颜色就是这里设置的颜色（深蓝）
        glClearColor(0.2, 0.3, 0.3, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        //开始画一个三角形 图元：也就是绘制成什么图形
        glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0); //Red
        glVertex3f(0, 1, 1);

        glColor3f(0, 1, 0); //Green
        glVertex3f(-1, -1, 0);

        glColor3f(0, 0, 1); //Blue
        glVertex3f(1, -1, 0);
        //结束一个画图步骤
        glEnd();

        /******交换缓冲区，更新window上的内容，双缓冲机制，防止屏幕闪烁******/
        glfwSwapBuffers(window);
    }
    // 释放分配的所有的资源
    glfwTerminate();
    return 0;
}
