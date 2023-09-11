//用struct Node作为一个单向链表
//使用Create 创建链表
//使用NumNodes 计算并返回链表中的节点数
//使用ShowList 输出链表各节点的值
//使用Insert 在链表中插入一个新节点至首节点前，成为新的首节点
//使用Append 在链表中插入一个新节点至尾节点后，成为新的尾节点
//使用FreeList 释放链表中的所有节点
//重载operate<< 以输出链表各节点的值
//使用Locate 通过输入值查找链表中的某个节点，并支持继续查找
//使用Save 将链表所有数据域的数据写入指定文件名的文件中
//使用Load 从指定文件名的文件中读取数据并创建链表
//使用Insert1 在链表任意位置前插入一个新节点
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node   //定义节点结构体
{
    int data; //数据域
    Node *next; //指针域
};

class List //定义链表类
{
private:
    Node *head; //头指针
    Node *tail; //尾指针
    int numNodes; //节点数

public:
    List(); //构造函数
    ~List(); //析构函数
    void Create(); //创建链表
    int NumNodes(); //计算并返回链表中的节点数
    void ShowList(); //输出链表各节点的值
    void Insert(int); //在链表中插入一个新节点至首节点前，成为新的首节点
    void Append(int); //在链表中插入一个新节点至尾节点后，成为新的尾节点
    void FreeList(); //释放链表中的所有节点
    friend ostream &operator<<(ostream &, List &); //重载operate<< 以输出链表各节点的值
    void Locate(int);   //通过输入值查找链表中的某个节点，并支持继续查找
    void Save(string); //将链表所有数据域的数据写入指定文件名的文件中
    void Load(string); //从指定文件名的文件中读取数据并创建链表
    //使用Insert1 在链表任意位置前插入一个新节点
    void Insert1(int,int); //在链表任意位置前插入一个新节点
    
};

List::List()
{
    head = NULL; //头指针初始化为空
    tail = NULL; //尾指针初始化为空
    numNodes = 0; //节点数初始化为0
}

List::~List()
{
    FreeList(); //析构函数中调用FreeList函数释放链表中的所有节点
}

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

int List::NumNodes()
{
    return numNodes; //返回节点数
}

void List::ShowList()
{
    Node *p = head; //创建指针p指向首节点
    while (p != NULL) //循环输出链表各节点的值
    {
        cout << p->data << " "; //输出节点值
        p = p->next; //指针p指向下一个节点
    }
}


void List::Insert(int data) //在链表中插入一个新节点至首节点前，成为新的首节点
{
    Node *p = new Node; //创建新节点
    p->data = data;    //新节点的数据域为data
    p->next = head;   //新节点的指针域指向原首节点
    head = p;        //新节点成为新的首节点
    numNodes++;     //节点数加1
}

void List::Insert1(int data, int pos)
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

int main() //主函数
{
    List list; //创建链表对象
    string filename = "D:\\CPPcodeField\\list.txt"; //文件名
    list.Create(); //创建链表
    cout << "链表中的节点数为：" << list.NumNodes() << endl; //输出链表中的节点数
    cout << "链表中的节点值为：";  
    list.ShowList(); //输出链表各节点的值
    cout << endl; 
    list.Insert(0); //在链表中插入一个新节点至首节点前，成为新的首节点
    cout << "在链表首节点前插入0后，链表中的节点值为："; 
    list.ShowList(); //输出链表各节点的值
    cout << endl;
    list.Insert1(50, 3); //在链表任意位置前插入一个新节点
    list.ShowList(); //输出链表各节点的值
    cout << endl;
    list.Append(100); //在链表中插入一个新节点至尾节点后，成为新的尾节点
    cout << "在链表尾节点后插入100后，链表中的节点值为：";
    list.ShowList(); //输出链表各节点的值
    cout << endl;
    cout << "重载<<后，链表中的节点值为：" << list << endl; //重载operate<< 以输出链表各节点的值
    list.Locate(0); //通过输入值查找链表中的某个节点，并支持继续查找
    list.Locate(100); //通过输入值查找链表中的某个节点，并支持继续查找
    list.Locate(50); //通过输入值查找链表中的某个节点，并支持继续查找
    list.Save(filename); //将链表所有数据域的数据写入指定文件名的文件中
    list.FreeList(); //释放链表中的所有节点
    cout << "释放链表后，链表中的节点数为：" << list.NumNodes() << endl; //输出链表中的节点数
    list.Load(filename); //从指定文件名的文件中读取数据并创建链表
    cout << "从文件中读取数据后，链表中的节点数为：" << list.NumNodes() << endl; //输出链表中的节点数
    cout << "从文件中读取数据后，链表中的节点值为：";  
    list.ShowList(); //输出链表各节点的值
    cout << endl;
    return 0;
}
