## **说明<br>**
本练习采用了Ui类对String类进行使用，在终端中即可使用String的大部分功能。  
第一次自己实现String类，可能存在许多问题，但功能基本上可以完成  ~~能跑就行~~
以下附图<br>
<img src=".\pic\str1.png" width="50%" hight="50%" >  
在终端中只需输入各种大小写字母即可实现对字符串的操作,例如，我们可以输入字符A<br>
<img src=".\pic\str2.png" width="50%" hight="50%" ><br>  
此时终端会提示我们创建一个字符串，通过反复使用A的创建功能,我们可以创建多个字符串但不大于10个，
此时使用B则可以看到我们先后创建的所有字符串，并且如果需要重新开始创建，可以使用N进行清理
如下（创建了两个字符串，"Hello"和"World!"）<br>
<img src=".\pic\str3.png" width="50%" hight="50%" >
<br>在每一次输出我们都会反复提醒用户使用M打开菜单，以免忘记  

---------------------
### 本程序使用cmake，同时其结构如下<br />  

> <font face="Courier new">main.cpp
 
>namespace stu
> > String.h   
> String.cpp

> Ui : stu::String  
> >Ui.cpp  
> Ui.h

