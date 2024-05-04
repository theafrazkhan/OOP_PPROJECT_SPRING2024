# include<iostream>
# include<string.h>
# include<stdlib.h>
# include<conio.h>
# include<iomanip>
# include<fstream>
# include"cinema.h"
# include"customer.h"
void w(char *name ,char *add);
int identify_pass(char * f);
int identify_password(char *f);
void vip_mem();              //��Ʊvip
void con_mem();               //��Ʊ-------��ͨ�û�
void adm();                  //����Ա���
void book();                 //��Ʊ
void films();               //ӰƬ��Ϣ�鿴
void cinm();                //ӰԺ��Ϣ�鿴
void c_worker();
void m_worker1();
void m_worker();
int main()
{   
        cout<<endl<<endl<<endl<<endl<<endl; 
        cout<<"             ����������������������            "<<endl;
		cout<<"            �� ��                                     ��           "<<endl;
		cout<<"           ��   ��            C++ �γ���ƣ�           ��          "<<endl;
		cout<<"          ��     ��                                     ��         "<<endl;
		cout<<"         ��       ��        ��ӰԺ��Ϣ����ϵͳ           ��        "<<endl;
		cout<<"        ��         ��                                     ��       "<<endl;
		cout<<"       ��           ����������������������     "<<endl;
		cout<<"       ��           �����                          �����     "<<endl;
        cout<<"       ��           �����  ��������ˣ�������      �����     "<<endl;
        cout<<"       ��           �����                          �����     "<<endl;
	    cout<<"       ��           �����                          �����     "<<endl;
	    cout<<"       ��           �����   ѧ�ţ�161110112        �����     "<<endl;
	    cout<<"       ��           �����                          �����     "<<endl;
        cout<<"       ��           �����                          �����     "<<endl;
        cout<<"       ��           ����������������������     "<<endl;
		cout<<endl<<endl;
		cout<<"                                �����������ϵͳ                   "<<endl;
        getch();
        system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                            ��ӭ����ӰԺ����ϵͳ                     "<<endl<<endl<<endl;
		cout<<"                �������Ա���룬���������룬�뵽�ĵ��ĸ�¼��Ѱ��     "<<endl;
		getch();
		int a,i;
	for(i=0;;i++)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl;
		cout<<"                                   ************                                "<<endl;
		cout<<"              *********************<��ѡ��˵�>*********************           "<<endl;
		cout<<"              **                *********************              **           "<<endl;
		cout<<"              **               �� 1.������Ա����    ��             **           "<<endl;
		cout<<"              **             ��   2.Ԥ(��)��ӰƱ����   ��          **           "<<endl;
		cout<<"              **           ��     3.ӰƬ��Ϣ�鿴����     ��        **           "<<endl;
		cout<<"              **             ��   4.ӰԺ��Ϣ�鿴����   ��          **           "<<endl;
		cout<<"              **               �� 0.�˳�ϵͳ����    ��             **           "<<endl;
		cout<<"              ******************************************************            "<<endl;
		      
		cin>>a;
		switch(a)
		{
		case 1: 
		   adm();                   
			break;
		case 2:
			book();
			break;
		case 3:
			films();
			break;
		case 4:
			cinm();
			break;
		case 0:
			{
			  system("cls");
			  cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			  cout<<setw(40)<<"ллʹ�ñ�ϵͳ"<<endl<<endl;
			  cout<<setw(40)<<"�����κν��飬������(#����) :";
			  char a;
			  fstream file("advice.txt",ios::app);
			  cin>>a;
			  while(a!='#')
			  {
				  file.put(a);
				  cin>>a;
			  }
			  file.put('\n');
			  file.close();
			  exit(0);
			}

		}
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////ӰԺ��Ϣ�鿴
void cinm()
{
	
	cinema a;
	a.file_open();
	cout<<endl<<endl<<endl;
	cout<<"                          �������������һ��"<<endl;
	getch();
}
void adm()
{
	int i,a=0;
	for(i=0;a!=3;)
	{
        system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************��ѡ��***********"<<endl;
		cout<<"                       **    1.������Ա           **"<<endl;
		cout<<"                       **    2.��ͨ������Ա       **"<<endl;
		cout<<"                       **   3.������һ���˵�      **"<<endl;
		cout<<"                       *****************************"<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
			{
				int a=0,i,b=0;
				for(i=0;;i++)
				{
					a=identify_password("administrator.dat");
					//a=1;
					if(a==1)
					{                      
						m_worker();
						break;
					}
					else
					{
						system("cls");
		                cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
						cout<<"             *******************************************************"<<endl;
                        cout<<"             *���������벻������������,����������󽫷�����һ���˵�*"<<endl;
						cout<<"             *******************************************************"<<endl;
						b++;
						if(b==3)
						break;
					}
				}
				break;
			}
			
		case 2:
			{
				int a=0,i,b=0;
				for(i=0;;i++)
				{
					a=identify_password("worker.dat");
					if(a==1)
					{                      
						c_worker();
						break;
					}
					else
					{
						system("cls");
		                cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
						cout<<"             *******************************************************"<<endl;
                        cout<<"             *���������벻������������,����������󽫷�����һ���˵�*"<<endl;
						cout<<"             *******************************************************"<<endl;
						b++;
						if(b==3)
						break;
					}
				}
				break;
			}
		case 3: 
			break;
		}
	}
}
///////////////////////////////////////////////////////////////////////////��ͨ������Ա

void c_worker()
{
	int i,a=0;
	for(i=0;a!=7;)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************��ѡ��***********    "<<endl;
		cout<<"                       **       1.�����Լ���Ϣ    **    "<<endl;
		cout<<"                       **       2.�޸��Լ���Ϣ    **    "<<endl;
		cout<<"                       **       3.����ӰƬ��Ϣ    **    "<<endl;
		cout<<"                       **       4.�޸�ӰƬ��Ϣ    **    "<<endl;
		cout<<"                       **       5.����ӰԺ��Ϣ    **    "<<endl;
		cout<<"                       **       6.�鿴�Ѷ�Ʊ��Ա  **    "<<endl;                 
		cout<<"                       **       7.������һ���˵�  **    "<<endl;
		cout<<"                       *****************************    "<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
			{
			worker worker1;
			worker1.set_my_information();                           //�����Լ���Ϣ
   		    break;
			}
		case 2:
			{
			worker worker1;
			worker1.change_my_information();                          //�޸��Լ���Ϣ
			break;
			}
		case 3:
			{
			film film1;
			film1.set_film();                                     //����ӰƬ��Ϣ
			break;
			}
		case 4:
			{
				film film2;
				film2.change_film();    
				break;
			}
		case 5:
			{
				worker worker1;
				worker1.set_cinema();                                //����ӰԺ��Ϣ
			break;
			}
		case 6:
			{
				customer customer1;
				customer1.look_all();
			break;
			}
		case 7:
			break;
		}

	}

}
////////////////////////////////////////////////////////////������Ա
void m_worker1()
{    
	int a; 
	for(;a!=4;)
	{ 
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************��ѡ��***********    "<<endl;
		cout<<"                       **     1.���������Լ���Ϣ  **    "<<endl;
		cout<<"                       **     2.�޸��Լ���Ϣ      **    "<<endl;
		cout<<"                       **     3.��ʾ�Լ���Ϣ      **    "<<endl;
		cout<<"                       **     4.������һ���˵�    **    "<<endl;
		cout<<"                       *****************************    "<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
				{
				administrator administrator1;
				administrator1.set_my_information();                           //�����Լ���Ϣ
   				break;
				}
		case 2:
				{
				administrator administrator1;
				administrator1.set_my_information();                          //�޸��Լ���Ϣ
				break;
				}
		case 3:
				{
					administrator administrator1;
					administrator1.show_admion();
					break;
				}
		case 4:
			break;
			}
	}
}
void m_worker()
{
    int i,a;
	for(i=0;a!=6;i++)
	{   
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************��ѡ��***********    "<<endl;
		cout<<"                       **    1.�����Լ���Ϣ       **    "<<endl;
		cout<<"                       **    2.����ӰƬ��Ϣ       **    "<<endl;
		cout<<"                       **    3.����ӰԺ��Ϣ       **    "<<endl;
		cout<<"                       **    4.Ա����Ϣ����       **    "<<endl;
		cout<<"                       **    5.���ӹ���Ա         **    "<<endl;
		cout<<"                       **    6.������һ���˵�     **    "<<endl;
	    cout<<"                       *****************************    "<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
			{
                m_worker1();
				break;
			}
		
		case 2:
			{
			film film1;
			film1.set_film();                                     //����ӰƬ��Ϣ
			break;
			}
		case 3:
			{
			administrator administrator1;
			administrator1.set_cinema();                                //����ӰԺ��Ϣ
			break;
			}
		case 4:
			{
				administrator administrator1;
				administrator1.ad_staff();
				break;
			}
		case 5:
			{
				administrator administrator1;
                administrator1.add_administrator();
				break;
			}
		case 6:
			break;
		
		}

	}
}
////////////////////////////////////////////////////////////ӰƬ��Ϣ�鿴
void films()
{
	int i,a;
	for(i=0;a!=3;i++)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************��ѡ��*************  "<<endl;
		cout<<"                       **    1.��Ƭ����ѯ           **  "<<endl;
		cout<<"                       **    2.ӰԺȫ����ӳӰƬ��ѯ **  "<<endl;
		cout<<"                       **    3.������һ���˵�       **  "<<endl;
		cout<<"                       *******************************  "<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
			{
				film film1;
				film1.find_film();
				break;
			}
		case 2:
			{
				film film1;
				film1.find_films();
				break;
			}

		case 3:
			break;
		}
	}

}
////////////////////////////////////////////////////////////////////////////////////��Ʊ����
void book()
{
	int a,i;
	for(i=0;a!=4;i++)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************��ѡ��*************     "<<endl;
		cout<<"                       **      1.��Ա  ��Ʊ����     **     "<<endl;
		cout<<"                       **      2.�ǻ�Ա��Ʊ����     **     "<<endl;
		cout<<"                       **      3.��Ʊ����           **     "<<endl;
		cout<<"                       **      4.������һ���˵�     **     "<<endl;
		cout<<"                       *******************************     "<<endl;
		cin>>a;
		switch(a)
		{
		case 1: 
			vip_mem();
			break;
		case 2:
			con_mem();
			break;
		case 3:
			{
			customer customer1;
			customer1.vip_unbook();
			break;
			}
		case 4:
			break;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////��Ʊ�йغ���
void vip_mem()
{
     int a=0,i,b=0;
	 for(i=0;;i++)
	 {
		a=identify_pass("vip_customer.dat");
		if(a==1)
		{                      
			customer vip;
			vip.vip_mem();
			break;
		}
		else
		{
			system("cls");
		    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<"             *******************************************************"<<endl;
            cout<<"             *���������벻������������,����������󽫷�����һ���˵�*"<<endl;
			cout<<"             *******************************************************"<<endl;
			b++;
			if(b==3)
			break;
		}
	}
}
void con_mem()
{
	int i,a;
	for(i=0;a!=3;i++)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************��ѡ��*************       "<<endl;
		cout<<"                       **        1.ע���Ա         **       "<<endl;
		cout<<"                       **        2.ֱ�Ӷ�Ʊ         **       "<<endl;
		cout<<"                       **        3.������һ���˵�   **       "<<endl;
		cout<<"                       *******************************       "<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
			{
				customer customer1;
				customer1.regist();
				break;
			}
		case 2:
			{
			customer customer1;
            customer1.order();
		    break;
			}
		case 3:
			break;
		}
	}

}


////////////////////////////////////////////////////////////////////////////////////������֤����
int identify_password(char * f)
{
	int i,a=0;
    char name[20];
	char password[15];
	cin.ignore();
	cout<<setw(35)<<"����������:";
	cin.getline(name,20);
	cout<<setw(35)<<"����������:";
	cin.getline(password,15);
	fstream file;
	file.open(f,ios::in|ios::binary);
	if(file.fail())
	{
		cout<<"worker�ļ���ʧ��";
		exit(0);
	}
	worker workers;
	for(i=0;!file.eof();i++)
	{
		  file.read((char*)&workers,sizeof(worker));
		  if(strcmp(workers.show_name(),name)==0)                   //�˴�����name�ĳ�id��
		  {
			  if(strcmp(workers.show_password(),password)==0)
			  {
				  file.close();
				  a=1;
			  }
		  }
	}
	if(a==1)
	  return 1;
	else
	{
		file.close();
	    return 0;
	}
	
}
/////////////////////////////////////////////////////////
int identify_pass(char * f)
{
	int i,a=0;
    char name[20];
	char password[15];
	cin.ignore();
	cout<<setw(35)<<"����������:";
	cin.getline(name,20);
	cout<<setw(35)<<"����������:";
	cin.getline(password,15);
	fstream file;
	file.open(f,ios::in|ios::binary);
	if(file.fail())
	{
		cout<<"worker�ļ���ʧ��";
		exit(0);
	}
	customer customers;
	for(i=0;!file.eof();i++)
	{
		  file.read((char*)&customers,sizeof(customer));
		  if(strcmp(customers.showname(),name)==0)                   //�˴�����name�ĳ�id��
		  {
			  if(strcmp(customers.showpassword(),password)==0)
			  {
				  file.close();
				  a=1;
			  }
		  }
	}
	if(a==1)
	  return 1;
	else
	{
		file.close();
	    return 0;
	}
	
}
