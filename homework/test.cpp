#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//��ӡ�˵�����
void showMenu()
{
	cout << "***************************" << endl
		<< "*****  1�������ϵ��  *****" << endl
		<< "*****  2����ʾ��ϵ��  *****" << endl
		<< "*****  3��ɾ����ϵ��  *****" << endl
		<< "*****  4����ѯ��ϵ��  *****" << endl
		<< "*****  5���޸���ϵ��  *****" << endl
		<< "*****  6�����ͨѶ¼  *****" << endl
		<< "*****  0���˳�ͨѶ¼  *****" << endl
		<< "***************************" << endl;
}

//��ϵ�˽ṹ��
struct Person
{
	string m_Name;      //����
	int m_Sex;          //�Ա�
	int m_Age;          //����
	string m_Phone;     //�绰
	string m_Add;       //סַ
};

//ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];

	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size;
};

void addPerson(struct Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size > 1000)
	{
		cout << "ͨѶ¼����!" << endl;
		return;
	}
	else
	{
		//����

		cout << "��������ϵ������:" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�

		int sex = 0;

		while (true)
		{
			cout << "��������ϵ���Ա�:" << endl
				<< "1�� �� -- 2�� Ů" << endl;
			cin >> sex;

			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "��Ч���룬����������!" << endl;
			}
		}

		//����
		int age = 0;

		while (true)
		{
			cout << "��������ϵ������:" << endl;
			cin >> age;
			if (age >= 0)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			else
			{
				cout << "��Ч���룬����������!" << endl;
			}
		}

		//�绰

		string phone;
		cout << "��������ϵ�˵绰:" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//��ͥסַ

		string add;
		cout << "��������ϵ�˵ļ�ͥסַ:" << endl;
		cin >> add;
		abs->personArray[abs->m_Size].m_Add = add;

		//����ͨѶ¼����

		abs->m_Size++;

		cout << "��ӳɹ�!" << endl;

		system("pause");
		system("cls");

	}
}

//��ʾ��ϵ��

void showPerson(struct Addressbooks* abs)
{
	if (abs->m_Size > 0)
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "����:  " << abs->personArray[i].m_Name << "\t"
				<< "�Ա�:  " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t"
				<< "����:  " << abs->personArray[i].m_Age << "\t"
				<< "��ϵ�绰:  " << abs->personArray[i].m_Phone << "\t"
				<< "��ͥסַ:  " << abs->personArray[i].m_Add << endl;
		}
	}
	else
	{
		cout << "��ϵ��Ϊ��!" << endl;
	}

	system("pause");
	system("cls");

}

//�ж�һ�����Ƿ���ͨѶ¼�У������򷵻�λ�ã��������򷵻�-1

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

//ɾ����ϵ��

void deletePerson(struct Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��:" << endl;
	string name;
	cin >> name;

	//�ж���ϵ���Ƿ����
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���!" << endl;
	}
	else
	{
		//ɾ��
		for (int i = ret; i < abs->m_Size; i++)
		{
			//����Ǩ��
			abs->personArray[i] = abs->personArray[i + 1];
		}

		//������һ
		abs->m_Size--;
		cout << "ɾ���ɹ�!" << endl;
	}

	system("pause");
	system("cls");
}

//��ѯ��ϵ��

void findPerson(struct Addressbooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ��:" << endl;
	string name;
	cin >> name;

	//�ж���ϵ���Ƿ����
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���!" << endl;
	}
	else
	{
		//��ѯ(��ӡ)
		cout << "����:  " << abs->personArray[ret].m_Name << "\t"
			<< "�Ա�:  " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t"
			<< "����:  " << abs->personArray[ret].m_Age << "\t"
			<< "��ϵ�绰:  " << abs->personArray[ret].m_Phone << "\t"
			<< "��ͥסַ:  " << abs->personArray[ret].m_Add << endl;
	}

	system("pause");
	system("cls");
}

//�޸���ϵ��

void modifyPerson(struct Addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��:" << endl;
	string name;
	cin >> name;

	//�ж���ϵ���Ƿ����
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���!" << endl;
	}
	else
	{
		//�޸�
		cout << "���޸Ĵ���ϵ��:" << endl;

		cout << "��������ϵ������:" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//�Ա�

		int sex = 0;

		while (true)
		{
			cout << "��������ϵ���Ա�:" << endl
				<< "1�� �� -- 2�� Ů" << endl;
			cin >> sex;

			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "��Ч���룬����������!" << endl;
			}
		}

		//����
		int age = 0;

		while (true)
		{
			cout << "��������ϵ������:" << endl;
			cin >> age;
			if (age >= 0)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			else
			{
				cout << "��Ч���룬����������!" << endl;
			}
		}

		//�绰

		string phone;
		cout << "��������ϵ�˵绰:" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//��ͥסַ

		string add;
		cout << "��������ϵ�˵ļ�ͥסַ:" << endl;
		cin >> add;
		abs->personArray[ret].m_Add = add;

		cout << "�޸ĳɹ�!" << endl;
	}

	system("pause");
	system("cls");
}

//�����ϵ��

void cleanPerson(struct Addressbooks* abs)
{

	cout << "�����Ҫ�����?" << endl
		<< "1����-----2����" << endl;

	int ret = 0;
	cin >> ret;

	//���
	if (ret == 1)
	{
		abs->m_Size = 0;
		cout << "�����!" << endl;
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
		//���ô�ӡ�˵�
		showMenu();

		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1:                 //1�������ϵ��

			addPerson(&abs);

			break;
		case 2:                 //2����ʾ��ϵ�� 

			showPerson(&abs);

			break;
		case 3:                 //3��ɾ����ϵ��

			deletePerson(&abs);

			break;
		case 4:                 //4����ѯ��ϵ��

			findPerson(&abs);

			break;
		case 5:                 //5���޸���ϵ��

			modifyPerson(&abs);

			break;
		case 6:                 //6�����ͨѶ¼

			cleanPerson(&abs);

			break;
		case 0:                 //0���˳�ͨѶ¼

			cout << "��ӭ�´�ʹ��!" << endl;
			system("pause");
			return 0;
			break;
		default:

			cout << "����ȷ����!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}