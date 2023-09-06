//Ui.cpp

#include "Ui.h"
//通过String[]数组来增加创建的string
//String* str = new String[10] 其实直接在栈上也行
//switch 做开关
//while 死循环

void Ui::PrintUI()
{
    std::cout << "\n*************************************\n"
              << "*         choose a method           *\n"
              << "*  A.create a string(less than 10)  *\n" //记录已经创建了几个
              << "*  B.show all the strings           *\n"
              << "*  C.connect two strings            *\n"
              << "*  D.length of which string         *\n"
              << "*  E.copy a string to another       *\n"
              << "*  F.compare two strings            *\n"
              << "*  M.open the Menu                  *\n"
              << "*  N.clear the string made before   *\n"
              << "*  Q.escape                         *\n"
              << "*************************************"
              << '\n';
}

void Ui::Start()
{
    char choose{'\0'};
    bool flag{false};
    int StrNum{0};
    String str[10];
    while(!flag)
    {
        std::cout << "Wait for choosing......\n";
        std::cin >> choose;
        switch (choose)
        {
            case 'A':
            {
                std::cout << "\nCreate String:";
                std::cin >> str[StrNum];
                StrNum++;
                std::cout <<"\n[you can choose M to open the Menu]\n";
                break;
            }
            case 'B':
            {
                if(!StrNum) std::cout << "\nThere is no string!\n";
                for(int i=0; i <StrNum ;i++)
                {
                    std::cout << "\nThe " << i+1 << " string " << "is " << str[i];
                }
                std::cout <<"\n[you can choose M to open the Menu]\n";
                break;
            }
            case 'C':
            {
                std::cout << "\nplease choose two strings to connect :" ;
                int Fst{0} , Snd{0};
                std::cin >> Fst >> Snd;
                if(Fst<StrNum && Snd<=StrNum)
                {
                    String AfterCon;
                    AfterCon = str[Fst-1]+str[Snd-1];
                    std::cout << "\nAfter connect:" << AfterCon;
                }
                else
                {
                    std::cout << "\nNO Such a string! Maybe Your Choice too Big! Please choose again!";
                }
                std::cout <<"\n[you can choose M to open the Menu]\n";
                break;
            }
            case 'D':
            {
                int ChoPi{0};
                std::cout << "\nplease choose a string :";
                std::cin >> ChoPi;
                std::cout << "\nThe length is: ";
                std::cout << str[ChoPi-1].Getlen();
                std::cout <<"\n[you can choose M to open the Menu]\n";
                break;
            }
            case 'E':
            {
                int Fst{0} , Snd{0};
                std::cout << "\nplease choose two strings\n(The one to be copied should be in the back): ";
                std::cin >> Fst >> Snd;
                StrCpy(str[Fst - 1],str[Snd-1]);
                std::cout << "\nThe copied one is: " << str[Fst-1] << '\n';
                std::cout <<"\n[you can choose M to open the Menu]\n";
                break;
            }
            case 'F':
            {
                int Fst{0} , Snd{0};
                std::cout << "\nplease choose two strings to compare: ";
                std::cin >> Fst >> Snd;
                int Comp = StrCmp(str[Fst-1],str[Snd-1]);
                if( Comp > 0) {std::cout << "\nThe bigger one is: " << str[Fst-1] << '\n';}
                else if(Comp < 0){std::cout << "\nThe smaller one is: " << str[Fst-1] << '\n';}
                else {std::cout << "\nThe two are equal!\n";}
                std::cout <<"\n[you can choose M to open the Menu]\n";
                break;
            }
            case 'N':
            {
                if(StrNum)
                {
                    for (int i = 0; i < StrNum; i++)
                    {
                        str[i] = "\0";
                    }
                    StrNum = 0;
                    std::cout <<"\nThe strings already clear!\n";
                }
                else std::cout << "\nThere is no string you made!\n";
                std::cout <<"\n[you can choose M to open the Menu]\n";
                break;
            }
            case 'M':
            {
                Ui::PrintUI();
                break;
            }
            case 'Q':
            {
                std::cout << "[EXIT]\n";
                flag = true;
                break;
            }
            default:
            {
                std::cout << "[ERROR INPUT!!!] Please choose right one!!!\n";
                break;
            }
        }
    }
}