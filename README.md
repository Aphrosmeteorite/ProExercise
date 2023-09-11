
单向链表设计
----------

### 程序说明

**1. 程序结构**
实验主要由<font face ="Courier New"> **Visual Studio code** </font>进行编辑和调试.链表主体为结构体<font face ="Courier New"> **Node** </font>,通过<font face ="Courier New"> **List** </font>类封装的方法实现对<font face ="Courier New"> **Node** </font>链表的创建、增删改查.<br />
```cpp
 Node-List-Project———————
|struct Node             |
| |data                  |
| |*next                 |
|class List              | 
| |Create()              |
| |NumNodes()            |
| |ShowList()            |
| |Insert()              |
| |operate<<             |
| |Append()              |
| |FreeList()            |
| |Locate()              |
| |Save()                |
| |Load()                |
 ————————————————————————
```

**2. 程序运行示例**  

* 如下图,创建了10个节点并输入测试数据`12,50,2,50,334,50,12,50,90,0`,并把文件写入同目录的`list.txt`中  
<img src=".\Node-List-pic\Node-List-1.png" title="Node-List-debug" /> <br />
<img src=".\Node-List-pic\Node-List-2.png" title="Node-List-debug" /> <br />
* **说明**  
* * 我在输入的测试数据的头插入了数据为0的节点并更新为头节点,在尾插入了数据为100的的节点并更新为尾节点.
* * 我实现对数据50的查找,并输出其在整个链表中的位置,同样,我也查找了数据0和数据100的位置并输出.
* * 在释放整个链表之前,程序在插入了新节点之后,将数据写入到同一目录下的`list.txt`文件中,在文件中我们可以看见各节点的数据.  
  
**3. 程序源码部分说明**  
* 下例中定义`List::Create()`函数,进行用户指定的节点数进行链表的创建,并使用了`class List`中的另一个方法`List::Append()`将新元素放置在尾部
```cpp
void List::Create() //创建链表
{ 
    int n; //节点数
    cout << "请输入节点数：";
    cin >> n;
    for (int i = 0; i < n; i++) //循环输入节点值
    {
        int data; //节点值
        cout << "请输入第" << i + 1 << "个节点的值：";   
        cin >> data; //输入节点值
        Append(data); //将节点值插入链表尾部
    }
}
```  
* 以下定义`List::Append(int )`函数,该函数将传入的`data`放置在链表的尾部,如果链表还未被创建,则会创建一个只有一个节点的链表
```cpp
void List::Append(int data)
{
    Node *p = new Node; //创建新节点
    p->data = data;   //新节点的数据域为data
    p->next = NULL; //新节点的指针域为空
    if (head == NULL) //如果链表为空
    {
        head = p; //新节点成为首节点
        tail = p; //新节点成为尾节点
    }
    else
    {
        tail->next = p; //新节点成为尾节点
        tail = p; //新节点成为尾节点
    }
    numNodes++; //节点数加1
}
```
* 以下定义`List::FreeList()`函数和析构函数`List::~List()`,析构函数直接调用了`List::FreeList()`函数,也可以主动调用`List::FreeList()`清空链表.这里的链表在堆空间中,直接使用`delete`进行删除每一个节点的指针即可.
```cpp
  void List::FreeList()
{
    Node *p = head; //创建指针p指向首节点
    while (p != NULL) //循环释放链表中的所有节点
    {
        Node *q = p; //创建指针q指向p指向的节点
        p = p->next; //指针p指向下一个节点
        delete q; //释放q指向的节点
    }
    head = NULL; //头指针置空
    tail = NULL; //尾指针置空
    numNodes = 0; //节点数置0
}

List::~List()
{
    FreeList(); //析构函数中调用FreeList函数释放链表中的所有节点
}
```
* 以下定义`operater<<`的重载,本质上是遍历整个链表然后输出每一个节点的数据.
```cpp
  ostream &operator<<(ostream &out, List &list) //重载operate<< 以输出链表各节点的值
{
    Node *p = list.head; //创建指针p指向首节点
    while (p != NULL) //循环输出链表各节点的值
    {
        out << p->data << " "; //输出节点值
        p = p->next; //指针p指向下一个节点
    }
    return out; //返回输出流
}
```
* 以下定义`List::Locate(int )`函数,函数同样是从头遍历整个链表,找到相应数据后使计数器`count`加一,通过`count`不仅能够反应第几个节点找到了相应的数据,还能在未找到相应数据时开启`if(!count )`提示用户未找到数据.
```cpp
void List::Locate(int data)  //通过输入值查找链表中的某个节点，并支持继续查找
{
    Node *p = head; //创建指针p指向首节点
    int count = 0; //计数器
    while (p != NULL) //循环查找
    {
        if (p->data == data) //如果找到
        {
            cout << "第" << count + 1 << "个节点的值为" << data << endl; //输出节点值
        }
        p = p->next; //指针p指向下一个节点
        count++; //计数器加1
    }
    if(!count)
        cout << "未找到" << data << endl; //如果未找到，输出未找到
}
```
* 以下讨论关于文件读写的相关函数和操作,`List::Save(string )`和`List::Load(string )`.这里用到了<font face ="Courier New"> **C++ STL** </font>库中的`string`容器进行文件名的传递.写入文件的操作`List::Save()`主要还是通过遍历链表然后写入文件中.读取文件的操作`List::Load()`则通过`List::Append(int )`将读取到的数据增至链表尾部.
```cpp
void List::Save(string filename) //将链表所有数据域的数据写入指定文件名的文件中
{
    ofstream fout(filename); //创建输出流
    Node *p = head; //创建指针p指向首节点
    while (p != NULL) //循环输出链表各节点的值
    {
        fout << p->data << " "; //输出节点值
        p = p->next; //指针p指向下一个节点
    }
    fout.close(); //关闭输出流
}

void List::Load(string filename) //从指定文件名的文件中读取数据并创建链表
{
    FreeList(); //释放链表中的所有节点
    ifstream fin(filename); //创建输入流
    int data; //节点值
    while (fin >> data) //循环读取数据
    {
        Append(data); //将节点值插入链表尾部
    }
    fin.close(); //关闭输入流
}
```

* 以下定义`List::Insert(int )`函数.由于该函数仅实现了在头节点前插入一个值并更新头节点,故并不复杂且原理简单.若要使其在任意指定位置前插入一个节点,可以参考第二个`List::Insert1(int , int )`函数.
```cpp
void List::Insert(int data) //在链表中插入一个新节点至首节点前，成为新的首节点
{
    Node *p = new Node; //创建新节点
    p->data = data;    //新节点的数据域为data
    p->next = head;   //新节点的指针域指向原首节点
    head = p;        //新节点成为新的首节点
    numNodes++;     //节点数加1
}
```
```cpp
void List::Insert1(int data , int pos)
{
        Node *p = new Node; //创建新节点
        p->data = data;    //新节点的数据域为data
        p->next = NULL;   //新节点的指针域为空
        if (pos == 1) //如果插入位置为1
        {
            p->next = head;   //新节点的指针域指向原首节点
            head = p;        //新节点成为新的首节点
        }
        else
        {
            Node *q = head; //创建指针q指向首节点
            for (int i = 1; i < pos - 1; i++) //循环找到插入位置的前一个节点
            {
                q = q->next; //指针q指向下一个节点
            }
            p->next = q->next; //新节点的指针域指向原插入位置的节点
            q->next = p; //原插入位置的前一个节点的指针域指向新节点
        }
        numNodes++; //节点数加1
}
```