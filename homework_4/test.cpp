#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Persons
{
    string name;        // ����
    string sex;         // �Ա�
    unsigned int age;   // ����
    string phoneNumber; // �ֻ�����
    string address;     // סַ
};

class AddressBooks
{
public:
    vector<Persons> persons;                 // ͨѶ¼�б������ϵ������
    static constexpr int MAXSIZE = 1e3 + 10; // ͨѶ¼�������

    AddressBooks() = default;
    ~AddressBooks() = default;
};

void showMenu();

void closeSystem();

bool addPerson(AddressBooks& addressBooks);

void showPersons(const AddressBooks& addressBooks);

int findPersonByName(const AddressBooks& addressBooks, const string& name);

int findPersonBySex(const AddressBooks& addressBooks, const string& sex);

int findPersonByAge(const AddressBooks& addressBooks, const int& age);

int findPersonByPhoneNumber(const AddressBooks& addressBooks, const string& phoneNumber);

int findPersonByAddress(const AddressBooks& addressBooks, const string& address);

bool removePerson(AddressBooks& addressBooks);

bool findPerson(const AddressBooks& addressBooks);

bool modifyPerson(AddressBooks& addressBooks);

void backupAddressBooks(const AddressBooks& addressBooks);

void restoreAddressBooks(AddressBooks& addressBooks);

void clearAddressBooks(AddressBooks& addressBooks);

int main()
{
    AddressBooks addressBooks;
    while (true)
    {
        showMenu(); // �˵�����
        int select;
        cin >> select;
        system("clear");
        switch (select)
        {
        case 0: // �˳�ͨѶ¼
        {
            closeSystem();
            break;
        }
        case 1: // �����ϵ��
        {
            if (addPerson(addressBooks) == true)
            {
                cout << "��ϵ����ӳɹ�" << endl;
            }
            else
            {
                cout << "ͨѶ¼��������" << endl;
            }
            break;
        }
        case 2: // ��ʾ��ϵ��
        {
            showPersons(addressBooks);
            break;
        }
        case 3: // ɾ����ϵ��
        {
            if (removePerson(addressBooks) == true)
            {
                cout << "ɾ���ɹ�" << endl;
            }
            else
            {
                cout << "ɾ��ʧ��" << endl;
            }
            break;
        }
        case 4: // ������ϵ��
        {
            if (!findPerson(addressBooks))
            {
                cout << "���޴���" << endl;
            }
            break;
        }
        case 5: // �޸���ϵ��
            if (modifyPerson(addressBooks) == true)
            {
                cout << "�޸ĳɹ�" << endl;
            }
            else
            {
                cout << "�޸�ʧ��" << endl;
            }
            break;
        case 6: // ����ͨѶ¼
        {
            backupAddressBooks(addressBooks);
            break;
        }
        case 7: // �ָ�ͨѶ¼
        {
            restoreAddressBooks(addressBooks);
            break;
        }
        case 8: // ���ͨѶ¼
        {
            clearAddressBooks(addressBooks);
            cout << "ͨѶ¼�����" << endl;
            break;
        }
        default:
        {
            cout << "�����������������" << endl;
            cout << "�밴��������س�����" << endl; // MACϵͳ
            cin >> select;                          // MACϵͳ
            system("clear");                        // MACϵͳ
            // system("pause");WINDOWSϵͳ
            // system("cls");WINDOWSϵͳ
            continue;
        }
        }
        cout << "�밴��������س�����" << endl; // MACϵͳ
        cin >> select;                          // MACϵͳ
        system("clear");                        // MACϵͳ
        // system("pause");WINDOWSϵͳ
        // system("cls");WINDOWSϵͳ
    }
    return 0;
}

void showMenu()
{
    cout << "*********************" << endl
        << "*****1�������ϵ��*****" << endl
        << "*****2����ʾ��ϵ��*****" << endl
        << "*****3��ɾ����ϵ��*****" << endl
        << "*****4��������ϵ��*****" << endl
        << "*****5���޸���ϵ��*****" << endl
        << "*****6������ͨѶ¼*****" << endl
        << "*****7���ָ�ͨѶ¼*****" << endl
        << "*****8�����ͨѶ¼*****" << endl
        << "*****0���˳�ͨѶ¼*****" << endl
        << "*********************" << endl;
}

void closeSystem()
{
    cout << "��ӭ�´�ʹ��" << endl;
    exit(0); // �˳�����
}

bool addPerson(AddressBooks& addressBooks)
{
    if (addressBooks.persons.size() < AddressBooks::MAXSIZE)
    {
        Persons person;
        int sex;
        cout << "������������";
        cin >> person.name;
        cout << "�������Ա�(�У�1 Ů��0��";
        cin >> sex;
        person.sex = sex == 1 ? "��" : "Ů";
        cout << "���������䣺";
        cin >> person.age;
        cout << "�������ֻ����룺";
        cin >> person.phoneNumber;
        cout << "������סַ��";
        cin >> person.address;
        addressBooks.persons.emplace_back(person);
        return true;
    }
    else
    {
        return false;
    }
}

void showPersons(const AddressBooks& addressBooks)
{
    if (!addressBooks.persons.empty())
    {
        for (auto& person : addressBooks.persons)
        {
            cout << "������" << person.name
                << "\t�Ա�" << person.sex
                << "\t���䣺" << person.age
                << "\t�ֻ����룺" << person.phoneNumber
                << "\tסַ��" << person.address
                << endl;
        }
    }
    else
    {
        cout << "ͨѶ¼Ϊ��" << endl;
    }
}

int findPersonByName(const AddressBooks& addressBooks, const string& name)
{
    for (int i = 0; i < addressBooks.persons.size(); ++i)
    {
        if (addressBooks.persons[i].name == name)
        {
            return i;
        }
    }
    return -1;
}

int findPersonBySex(const AddressBooks& addressBooks, const string& sex)
{
    for (int i = 0; i < addressBooks.persons.size(); ++i)
    {
        if (addressBooks.persons[i].sex == sex)
        {
            return i;
        }
    }
    return -1;
}

int findPersonByAge(const AddressBooks& addressBooks, const int& age)
{
    for (int i = 0; i < addressBooks.persons.size(); ++i)
    {
        if (addressBooks.persons[i].age == age)
        {
            return i;
        }
    }
    return -1;
}

int findPersonByPhoneNumber(const AddressBooks& addressBooks, const string& phoneNumber)
{
    for (int i = 0; i < addressBooks.persons.size(); ++i)
    {
        if (addressBooks.persons[i].phoneNumber == phoneNumber)
        {
            return i;
        }
    }
    return -1;
}

int findPersonByAddress(const AddressBooks& addressBooks, const string& address)
{
    for (int i = 0; i < addressBooks.persons.size(); ++i)
    {
        if (addressBooks.persons[i].address == address)
        {
            return i;
        }
    }
    return -1;
}

bool removePerson(AddressBooks& addressBooks)
{
    int select, index;
    cout << "�������ѯ��ʽ\n1.����\n2.�Ա�\n3.����\n4.�ֻ�����\n5.סַ" << endl;
    cin >> select;
    switch (select) // ѡ���ѯ��ʽ
    {
    case 1:
    {
        cout << "������������";
        string name;
        cin >> name;
        index = findPersonByName(addressBooks, name);
        break;
    }
    case 2:
    {
        cout << "�������Ա�(�У�1 Ů��0��";
        int s;
        cin >> s;
        string sex = s == 1 ? "��" : "Ů";
        index = findPersonBySex(addressBooks, sex);
        break;
    }
    case 3:
    {
        cout << "���������䣺";
        int age;
        cin >> age;
        index = findPersonByAge(addressBooks, age);
        break;
    }
    case 4:
    {
        cout << "�������ֻ����룺";
        string phoneNumber;
        cin >> phoneNumber;
        index = findPersonByPhoneNumber(addressBooks, phoneNumber);
        break;
    }
    case 5:
    {
        cout << "������סַ��";
        string address;
        cin >> address;
        index = findPersonByAddress(addressBooks, address);
        break;
    }
    default:
    {
        index = -1;
        cout << "����������" << endl;
    }
    }
    if (index != -1)
    {
        addressBooks.persons.erase(addressBooks.persons.begin() + index);
        return true;
    }
    return false;
}

bool findPerson(const AddressBooks& addressBooks)
{
    int select, index;
    cout << "�������ѯ��ʽ\n1.����\n2.�Ա�\n3.����\n4.�ֻ�����\n5.סַ" << endl;
    cin >> select;
    switch (select) // ѡ���ѯ��ʽ
    {
    case 1:
    {
        cout << "������������";
        string name;
        cin >> name;
        index = findPersonByName(addressBooks, name);
        break;
    }
    case 2:
    {
        cout << "�������Ա�(�У�1 Ů��0��";
        int s;
        cin >> s;
        string sex = s == 1 ? "��" : "Ů";
        index = findPersonBySex(addressBooks, sex);
        break;
    }
    case 3:
    {
        cout << "���������䣺";
        int age;
        cin >> age;
        index = findPersonByAge(addressBooks, age);
        break;
    }
    case 4:
    {
        cout << "�������ֻ����룺";
        string phoneNumber;
        cin >> phoneNumber;
        index = findPersonByPhoneNumber(addressBooks, phoneNumber);
        break;
    }
    case 5:
    {
        cout << "������סַ��";
        string address;
        cin >> address;
        index = findPersonByAddress(addressBooks, address);
        break;
    }
    default:
    {
        index = -1;
        cout << "����������" << endl;
    }
    }
    if (index != -1)
    {
        Persons person = addressBooks.persons[index];
        cout << "������" << person.name
            << "\t�Ա�" << person.sex
            << "\t���䣺" << person.age
            << "\t�ֻ����룺" << person.phoneNumber
            << "\tסַ��" << person.address
            << endl;
        return true;
    }
    return false;
}

bool modifyPerson(AddressBooks& addressBooks)
{
    int select, index;
    cout << "�������ѯ��ʽ\n1.����\n2.�Ա�\n3.����\n4.�ֻ�����\n5.סַ" << endl;
    cin >> select;
    switch (select) // ѡ���ѯ��ʽ
    {
    case 1:
    {
        cout << "������������";
        string name;
        cin >> name;
        index = findPersonByName(addressBooks, name);
        break;
    }
    case 2:
    {
        cout << "�������Ա�(�У�1 Ů��0��";
        int s;
        cin >> s;
        string sex = s == 1 ? "��" : "Ů";
        index = findPersonBySex(addressBooks, sex);
        break;
    }
    case 3:
    {
        cout << "���������䣺";
        int age;
        cin >> age;
        index = findPersonByAge(addressBooks, age);
        break;
    }
    case 4:
    {
        cout << "�������ֻ����룺";
        string phoneNumber;
        cin >> phoneNumber;
        index = findPersonByPhoneNumber(addressBooks, phoneNumber);
        break;
    }
    case 5:
    {
        cout << "������סַ��";
        string address;
        cin >> address;
        index = findPersonByAddress(addressBooks, address);
        break;
    }
    default:
    {
        index = -1;
        cout << "����������" << endl;
    }
    }
    if (index != -1)
    {
        Persons person;
        cout << "�������޸ĺ��������";
        cin >> person.name;
        cout << "�������޸ĺ���Ա�(�У�1 Ů��0��";
        int s;
        cin >> s;
        person.sex = s == 1 ? "��" : "Ů";
        cout << "�������޸ĺ�����䣺";
        cin >> person.age;
        cout << "�������޸ĺ���ֻ����룺";
        cin >> person.phoneNumber;
        cout << "�������޸ĺ��סַ��";
        cin >> person.address;
        addressBooks.persons[index] = person;
        return true;
    }
    return false;
}

void backupAddressBooks(const AddressBooks& addressBooks)
{
    ofstream ofs;
    ofs.open("addressbook.txt", ios::out); // ���ļ�
    ofs << "����\t\t�Ա�\t\t����\t\t�ֻ�����\t\tסַ" << endl;
    for (auto& person : addressBooks.persons)
    {
        ofs << person.name
            << "\t\t" << person.sex
            << "\t\t" << person.age
            << "\t\t" << person.phoneNumber
            << "\t\t" << person.address
            << endl;
    }
    ofs.close(); // �ر��ļ�
    cout << "���ݳɹ�" << endl;
}

void restoreAddressBooks(AddressBooks& addressBooks)
{
    ifstream ifs;
    ifs.open("addressbook.txt", ios::in); // ���ļ�
    if (ifs.is_open())
    {
        string temp;
        getline(ifs, temp); // ���ļ��Ϸ��ı�ǩ���뵽��ʱ�ַ���
        cout << temp;
        Persons person;
        clearAddressBooks(addressBooks);
        while (ifs >> person.name >> person.sex >> person.age >> person.phoneNumber >> person.address)
        {
            addressBooks.persons.emplace_back(person);
        }
        ifs.close(); // �ر��ļ�
        cout << "�ָ��ɹ�" << endl;
    }
    else
    {
        cout << "�ļ���ʧ��" << endl;
    }
}

void clearAddressBooks(AddressBooks& addressBooks)
{
    addressBooks.persons.clear();
}