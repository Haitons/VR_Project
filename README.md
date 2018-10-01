# VR_Project
一个简易的虚拟现实场景

## 实现功能
（1）虚拟场景中包含静态的对象。如地形、建筑物、树木等。

（2）虚拟场景中包含动态角色，角色类型可自行设计，如人、动物、车辆、飞机等。

（3）可以通过交互设备（如鼠标、键盘）控制动态角色的运动。

（4）动态角色可以具有简单的智能，可自主运动。

（5）动态角色在虚拟场景运动过程中，避免与静态环境或其他动态角色发生碰撞。

（6）实现简单物理效果模拟，如动态角色在运动中逐渐加速的过程。

（7）场景对象的几何变换和显示变换。

（8）光照

本次设计一个简易的虚拟现实场景：一个雪人，天上下着雪。旁边有棵树，天上有太阳。雪球落在地上会弹起，落在雪人和树上会消融。太阳渐渐在落山，可以通过键盘控制太阳的升起与降落。

## 设计思路及实现方法
整个系统包括了雪人和树的绘制，雪花的绘制以及降落，太阳的绘制、移动以及键盘对太阳的控制。并且有简单的光照阴影。

## 1.虚拟场景中静态的对象
### A.雪人
雪人的绘制主要运用了五个球体（身体以及眼睛），一个圆柱以及圆盘（帽子），三个圆锥（鼻子，胳膊）。

主要函数：

`glcolor3f（x,y,z）：创建RGB颜色`

`glTranslatef(x,y,z)：该函数采用浮点数，将原点移动到（x,y,z）位置，即物体向左移动x，向上移动y，向前移动z。物体之间以及与坐标原点相对的位置关系都没有改变，是平移变换。
`

`gluSphere(GLUQuadricObj *obj, GLdouble radius, GLint slices, GLint stacks);
绘制球体的函数。第一个参数是指向二次方程状态的指针，第二个参数是球体的半径。第三个参数可以理解为地球的经线的条数。最后一个参数可以理解为纬线的条数。`

`glPushMatrix();压入当前矩阵堆栈`

`glPopMatrix();弹出栈顶的矩阵。这两个是为了使平移旋转之后坐标保持不变。glRotated(angle,x,y,z)：旋转变换绕着原点指向（x,y,z）的射线，逆时针旋转angle。`

`gluCylinder(GLUquadricObj *obj, GLdouble baseRadius, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks);
绘制圆柱以及圆锥`

`gluDisk(GLUquadric quad, double inner, double outer, int slices, int loops);
绘制圆盘`

### B.树木
树木的绘制主要运用了三个圆锥，以及一个圆柱。（树叶、树干）。


## 2.虚拟场景中动态的对象
### A.太阳
太阳是一个球体，可以自主移动，也可人为控制。

绘制太阳：

太阳自主移动：定义坐标变换数xrstep、yrstep，每次自主改变数值使太阳移动。

### B.雪
做不出形象的雪花，只能用小圆球代替。雪花有不同的速度，可以自主降落。

绘制雪球：

## 3.通过键盘控制对象移动
可通过“D”、“A”控制太阳运行的方向，也可按“P”让太阳暂停。

`glutPostRedisplay();当前窗口需要重新绘制`

## 4.简单物理效果模拟
按下“Q”按键，太阳可以加速落山。

通过改变方向速度大小控制太阳落山速度。

## 5.碰撞检测
在动态对象运动过程中，与其他物体接触，这里通过判断对象是否到达指定坐标位置，是则改变运动物体方向或者改变位置，不是则继续运动。
- 雪落在地面会弹起。
- 雪落在雪人或者树上会消融。

## 6.场景的几何变换和显示变换
在绘制对象的时候运动到了一些基本的变换。

主要函数：

`glScalef(a,b,c)：缩放变换。采用浮点数，将坐标系的x轴，y轴，z轴分别缩放a,b,c倍。坐标系中的物体同步缩放。`

`glRotated(angle,x,y,z)：旋转变换。绕着原点指向（x,y,z）的射线，逆时针旋转angle。`

`Translatef(x,y,z)：该函数采用浮点数，将原点移动到（x,y,z）位置，即物体向左移动x，向上移动y，向前移动z。物体之间以及与坐标原点相对的位置关系都没有改变，是平移变换。`

## 7.简单的光照

`glEnable(GL_DEPTH_TEST): 用来开启更新深度缓冲区`

`glCullFace()参数包括GL_FRONT和GL_BACK。意义：两个参数分别表示禁用多边形正面或者背面上的光照、阴影和颜色计算及操作，消除不必要的渲染计算`

`glFrontFace(GLenum mode); 作用是控制多边形的正面是如何决定的`

`glLightfv是光源glLightModelfv是材质`

## 运行结果
