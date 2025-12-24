#include<string>
#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;
#define delimeter "\n----------------------------------\n"

class Human
{
	static const int LAST_NAME_WIDTH = 12;
	static const int FIRST_NAME_WIDTH = 12;
	static const int AGE_WIDTH = 3;
	static int count;
	std::string last_name;
	std::string first_name;
	int age;
public:
	static int get_count()
	{
		return count;
	}
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}
	// constructors
	Human(const std::string& last_name, const std::string& first_name, int age)
	{
		count++;
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human() // ~ + tab
	{
		count--;
		cout << "HDestructor:\t" << this << endl;
	}	
	virtual std::ostream& info(std::ostream& os)const
	{
		os.width(11);
		os << std::left;
		os << std::string(typeid(*this).name() + 6) << ":";
		//return os << last_name << " " << first_name << " " << age;
		os.width(LAST_NAME_WIDTH);
		os << std::left;
		os << last_name;
		os.width(FIRST_NAME_WIDTH);
		os << first_name;
		os.width(AGE_WIDTH);
		os << age;
		return os;
	}
	virtual std::ofstream& write(std::ofstream& ofs)const
	{
		ofs << typeid(*this).name() + 6 << ":";
		ofs << last_name << " " << first_name << " " << age;
		return ofs;
	}
};
int Human::count = 0;

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	//obj.info();
	//return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age();
	return obj.info(os);
}
//std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
//{
//	obj.write(ofs);
//	return ofs;
//}

class AcademyMember:public Human
{
	// ctrl + R + R
	static const int SPECIALITY_WIDTH = 16;
	std::string speciality;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	//constructors
	AcademyMember
	(	
		const std::string& last_name, 
		const std::string& first_name, 
		int age, 
		const std::string& speciality
	):Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		cout << "AMconstructor" << endl;
	}
	~AcademyMember()
	{
		cout << "AMDestructor:\t" << this << endl;
	}
	// methods
	std::ostream& info(std::ostream& os)const override  
	{
		//return Human::info(os) << " " << speciallity;
		Human::info(os);
		os.width(SPECIALITY_WIDTH);
		os << speciality;
		return os;
		//Human::info(os);
		//return os << speciallity << endl;
	}
	std::ofstream& write(std::ofstream& ofs)const override
	{
		Human::write(ofs);
		ofs << " " << speciality;
		return ofs;
	}
};

class Student :public AcademyMember
{
	static const int GROUP_WIDTH = 8;
	static const int RATING_WIDTH = 8;
	static const int ATTENDANCE_WIDTH = 8;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	// constructors
	Student
	(
		const std::string last_name, const std::string first_name, int age,
		const std::string& speciallity,
		const std::string& group, double rating, double attendance
	) :AcademyMember(last_name, first_name, age, speciallity)
	{
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	// methods
	std::ostream& info(std::ostream& os)const override
	{
		AcademyMember::info(os);
		os.width(GROUP_WIDTH);
		os << group;
		os.width(RATING_WIDTH);
		os << rating;
		os.width(ATTENDANCE_WIDTH);
		os << attendance;
		return os;
		//return AcademyMember::info(os) << " " << group << " " << rating << " " << attendance;
		//AcademyMember::info(os);
		//return os << group << " " << rating << " " << attendance << endl;
	}
	std::ofstream& write(std::ofstream& ofs)const override
	{
		AcademyMember::write(ofs);
		ofs << " " << group << " " << rating << " " << attendance;
		return ofs;
	}
};

class Teacher :public AcademyMember
{
	int experience;
public:
	int get_experience()const
	{
		return experience;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}
	// constructors
	Teacher
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciallity,
		int experience
	) :AcademyMember(last_name, first_name, age, speciallity)
	{
		set_experience(experience);
		cout << "TConstructor: " << "\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor: " << "\t" << this << endl;
	}

	// methods
	std::ostream& info(std::ostream& os)const override
	{
		return AcademyMember::info(os) << experience;
		//AcademyMember::info(os);
		//return os << experience << endl;
	}
	std::ofstream& write(std::ofstream& ofs)const override
	{
		AcademyMember::write(ofs);
		ofs << " " << experience;
		return ofs;
	}
};

class Graduate : public Student
{
	// тема диплома
	std::string work_theme;
	// дата защиты диплома
	std::string defense_date;
public:
	// get
	std::string get_work_theme()const
	{
		return work_theme;
	}
	std::string get_defense_date()const
	{
		return defense_date;
	}
	// set
	void set_work_theme(std::string work_theme)
	{
		this->work_theme = work_theme;
	}
	void set_defense_date(std::string defense_date)
	{
		this->defense_date = defense_date;
	}
	// constructors
	Graduate
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciallity,
		const std::string& group, double rating, double attendance,
		const std::string& work_theme, const std::string& defense_date
		) : Student(last_name, first_name, age, speciallity, group, rating, attendance)
	{
		set_work_theme(work_theme);
		set_defense_date(defense_date);
		cout << "GConstructor" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor" << this << endl;
	}
	// methods
	std::ostream& info(std::ostream& os)const override
	{
		return Student::info(os) << " " << work_theme << " " << defense_date;
		//Student::info(os);
		//return os << work_theme << endl;
		//return os << defense_date << endl;
	}
	std::ofstream& write(std::ofstream& ofs)const override
	{
		Student::write(ofs);
		ofs << " " << work_theme << " " << defense_date;
		return ofs;
	}


};

void Print(Human* group[], const int n)
{
	cout << delimeter << endl;
	for (int i = 0; i < n; i++)
	{
		//group[i]->info();
		cout << *group[i] << endl;
	}
	cout << delimeter << endl;
}
void Save(Human* group[], const int n, const std::string& filename)
{
	std::ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	std::string cmd = "notepad ";
	cmd += filename;
	system(cmd.c_str());
}
Human* Factory(const char type[])
{
	Human* human = nullptr;
	if (strstr(type, "Student"))human = new Student("", "", 0, "", "", 0, 0);
	if (strstr(type, "Graduate"))human = new Graduate("", "", 0, "", "", 0, 0, "", "");
	if (strstr(type, "Teacher"))human = new Teacher("", "", 0, "", 0);
	return human;
}
Human** Load(const std::string& filename, int& n)
{
	Human** group = nullptr;
	std::ifstream fin(filename);
	if(fin.is_open())
	{
		n = 0;
		std::string buffer;
		while(!fin.eof())
		{
			std::getline(fin, buffer);
			if (buffer.size() == 0)continue;
			n++;
		}
		cout << n << endl;
		group = new Human* [n] {};
		cout << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << fin.tellg() << endl;

		for (int i = 0; !fin.eof(); i++)
		{
			std::getline(fin, buffer, ':');
			if (buffer.size() == 0)continue;
			group[i] = Factory(buffer.c_str());
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	fin.close();
	return group;
}

//#define INHERITANCE
//#define POLYMORPHISM

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE

	/*Human human("Einstein", "Albert", 146);
	human.info();*/

	AcademyMember albert("Einstein", "Albert", 146, "Astronomy");
	albert.info();

	Student student("Щербаков", "Илья", 15, "Разработка ПО", "P_418", 100, 99.9);
	student.info();

	Teacher teacher("Einstein", "Albert", 146, "Astronomy", 120);
	teacher.info();
#endif // INHERITANCE	

#ifdef POLYMORPHISM
	Human* group[] =
	{
		new Student("Кондратенко", "Георгий", 18, "РПО", "Р_418", 97, 98),
		new Teacher("Stanne", "Michael", 55, "Vocals", 40),
		new Student("Щербаков", "Илья", 15, "РПО", "P_418", 100, 99.9),
		new Teacher("Henriksson", "Matrin", 50, "Bass guitar", 40),
		new Student("Татевосян", "Элеонора", 17, "РПО", "Р_418", 98, 48)
	};

	Print(group, sizeof(group) / sizeof(group[0]));

	//Graduate graduate("Фамилия", "Имя", 15, "Разработка ПО", "P_418", 90, 80, "Тема диплома", "12.12.2025");
	//cout << delimeter << endl;
	//graduate.info();
	//cout << delimeter << endl;

	std::ofstream fout("group.txt");

	Save(group, sizeof(group) / sizeof(group[0]), "P_418.txt");

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
	cout << "Количество участников группы: " << Human::get_count() << endl;
#endif // POLYMORPHISM

	int n = 0;
	Human** group = Load("P_418.txt", n);
	Print(group, n);

}