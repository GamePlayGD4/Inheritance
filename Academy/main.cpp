#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#define delimeter "\n----------------------------------\n"

class Human
{
	std::string last_name;
	std::string first_name;
	int age;
public:
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
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human() // ~ + tab
	{
		cout << "HDestructor:\t" << this << endl;
	}	
	virtual void info()const
	{
		cout << last_name << " " << first_name << " " << age << endl;
	}
};

class AcademyMember:public Human
{
	std::string speciallity;
public:
	const std::string& get_speciallity()const
	{
		return speciallity;
	}
	void set_speciallity(const std::string& speciallity)
	{
		this->speciallity = speciallity;
	}
	//constructors
	AcademyMember
	(	
		const std::string& last_name, 
		const std::string& first_name, 
		int age, 
		const std::string& speciallity
	):Human(last_name, first_name, age)
	{
		set_speciallity(speciallity);
		cout << "AMconstructor" << endl;
	}
	~AcademyMember()
	{
		cout << "AMDestructor:\t" << this << endl;
	}
	// methods
	void info()const
	{
		Human::info();
		cout << speciallity << endl;
	}
};

class Student :public AcademyMember
{
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
	void info()const
	{
		AcademyMember::info();
		cout << group << " " << rating << " " << attendance << endl;
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
		cout << "TConstructor" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor" << this << endl;
	}

	// methods
	void info()const
	{
		AcademyMember::info();
		cout << experience << endl;
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
	void info()const
	{
		Student::info();
		cout << work_theme << endl;
		cout << defense_date << endl;
	}


};

//#define INHERITANCE

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

	Human* group[] =
	{
		new Student("Кондратенко", "Георгий", 18, "РПО", "Р_418", 97, 98),
		new Teacher("Stanne", "Michael", 55, "Vocals", 40),
		new Student("Щербаков", "Илья", 15, "РПО", "P_418", 100, 99.9),
		new Teacher("Henriksson", "Matrin", 50, "Bass", 40),
		new Student("Татевосян", "Элеонора", 17, "РПО", "Р_418", 98, 48)
	};

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->info();
	}

	Graduate graduate("Фамилия", "Имя", 15, "Разработка ПО", "P_418", 90, 80, "Тема диплома", "12.12.2025");
	cout << delimeter << endl;
	graduate.info();
	cout << delimeter << endl;
}