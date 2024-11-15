#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//打印菜单函数
void showMenu()
{
	cout << "***************************" << endl
		<< "*****  1、添加联系人  *****" << endl
		<< "*****  2、显示联系人  *****" << endl
		<< "*****  3、删除联系人  *****" << endl
		<< "*****  4、查询联系人  *****" << endl
		<< "*****  5、修改联系人  *****" << endl
		<< "*****  6、清空通讯录  *****" << endl
		<< "*****  0、退出通讯录  *****" << endl
		<< "***************************" << endl;
}

//联系人结构体
struct Person
{
	string m_Name;      //姓名
	int m_Sex;          //性别
	int m_Age;          //年龄
	string m_Phone;     //电话
	string m_Add;       //住址
};

//通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];

	//通讯录中当前记录联系人个数
	int m_Size;
};

void addPerson(struct Addressbooks* abs)
{
	//判断通讯录是否已满
	if (abs->m_Size > 1000)
	{
		cout << "通讯录已满!" << endl;
		return;
	}
	else
	{
		//姓名

		cout << "请输入联系人姓名:" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别

		int sex = 0;

		while (true)
		{
			cout << "请输入联系人性别:" << endl
				<< "1、 男 -- 2、 女" << endl;
			cin >> sex;

			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "无效输入，请重新输入!" << endl;
			}
		}

		//年龄
		int age = 0;

		while (true)
		{
			cout << "请输入联系人年龄:" << endl;
			cin >> age;
			if (age >= 0)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			else
			{
				cout << "无效输入，请重新输入!" << endl;
			}
		}

		//电话

		string phone;
		cout << "请输入联系人电话:" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//家庭住址

		string add;
		cout << "请输入联系人的家庭住址:" << endl;
		cin >> add;
		abs->personArray[abs->m_Size].m_Add = add;

		//更新通讯录人数

		abs->m_Size++;

		cout << "添加成功!" << endl;

		system("pause");
		system("cls");

	}
}

//显示联系人

void showPerson(struct Addressbooks* abs)
{
	if (abs->m_Size > 0)
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名:  " << abs->personArray[i].m_Name << "\t"
				<< "性别:  " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t"
				<< "年龄:  " << abs->personArray[i].m_Age << "\t"
				<< "联系电话:  " << abs->personArray[i].m_Phone << "\t"
				<< "家庭住址:  " << abs->personArray[i].m_Add << endl;
		}
	}
	else
	{
		cout << "联系人为空!" << endl;
	}

	system("pause");
	system("cls");

}

//判断一个人是否在通讯录中，若在则返回位置，若不在则返回-1

int isExist(struct Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}

	return -1;

}

//删除联系人

void deletePerson(struct Addressbooks* abs)
{
	cout << "请输入您要删除的联系人:" << endl;
	string name;
	cin >> name;

	//判读联系人是否存在
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人!" << endl;
	}
	else
	{
		//删除
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数组迁移
			abs->personArray[i] = abs->personArray[i + 1];
		}

		//人数减一
		abs->m_Size--;
		cout << "删除成功!" << endl;
	}

	system("pause");
	system("cls");
}

//查询联系人

void findPerson(struct Addressbooks* abs)
{
	cout << "请输入要查找的联系人:" << endl;
	string name;
	cin >> name;

	//判断联系人是否存在
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人!" << endl;
	}
	else
	{
		//查询(打印)
		cout << "姓名:  " << abs->personArray[ret].m_Name << "\t"
			<< "性别:  " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t"
			<< "年龄:  " << abs->personArray[ret].m_Age << "\t"
			<< "联系电话:  " << abs->personArray[ret].m_Phone << "\t"
			<< "家庭住址:  " << abs->personArray[ret].m_Add << endl;
	}

	system("pause");
	system("cls");
}

//修改联系人

void modifyPerson(struct Addressbooks* abs)
{
	cout << "请输入要修改的联系人:" << endl;
	string name;
	cin >> name;

	//判断联系人是否存在
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人!" << endl;
	}
	else
	{
		//修改
		cout << "请修改此联系人:" << endl;

		cout << "请输入联系人姓名:" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//性别

		int sex = 0;

		while (true)
		{
			cout << "请输入联系人性别:" << endl
				<< "1、 男 -- 2、 女" << endl;
			cin >> sex;

			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "无效输入，请重新输入!" << endl;
			}
		}

		//年龄
		int age = 0;

		while (true)
		{
			cout << "请输入联系人年龄:" << endl;
			cin >> age;
			if (age >= 0)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			else
			{
				cout << "无效输入，请重新输入!" << endl;
			}
		}

		//电话

		string phone;
		cout << "请输入联系人电话:" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//家庭住址

		string add;
		cout << "请输入联系人的家庭住址:" << endl;
		cin >> add;
		abs->personArray[ret].m_Add = add;

		cout << "修改成功!" << endl;
	}

	system("pause");
	system("cls");
}

//清空联系人

void cleanPerson(struct Addressbooks* abs)
{

	cout << "您真的要清空吗?" << endl
		<< "1、是-----2、否" << endl;

	int ret = 0;
	cin >> ret;

	//清空
	if (ret == 1)
	{
		abs->m_Size = 0;
		cout << "已清空!" << endl;
	}

	system("pause");
	system("cls");
}

int main()
{
	struct Addressbooks abs;
	abs.m_Size = 0;
	while (true)
	{
		//调用打印菜单
		showMenu();

		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1:                 //1、添加联系人

			addPerson(&abs);

			break;
		case 2:                 //2、显示联系人 

			showPerson(&abs);

			break;
		case 3:                 //3、删除联系人

			deletePerson(&abs);

			break;
		case 4:                 //4、查询联系人

			findPerson(&abs);

			break;
		case 5:                 //5、修改联系人

			modifyPerson(&abs);

			break;
		case 6:                 //6、清空通讯录

			cleanPerson(&abs);

			break;
		case 0:                 //0、退出通讯录

			cout << "欢迎下次使用!" << endl;
			system("pause");
			return 0;
			break;
		default:

			cout << "请正确操作!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}