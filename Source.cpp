#include <iostream>



#include <string>

#include <vector>

#include <map>



#include <algorithm>

#include <numeric>



enum Grade

{

	F = 1,

	D,

	C,

	B,

	A

};



struct Student

{

	std::string FIO;

	std::string Group;

	std::map<std::string, Grade> Grades;

};



std::vector<Student> LoadStudents()

{

	return{

		{

			"Anna", "G7",

			{

				{ "math", Grade::A },

				{ "cs", Grade::A },

				{ "english", Grade::A },

				{ "dutch", Grade::B },

			}

		},

		{

			"Petr", "G7",

			{

				{ "math", Grade::A },

				{ "cs", Grade::B },

				{ "dutch", Grade::C },

			}

		},

		{

			"Vova", "G1",

			{

				{ "math", Grade::F },

				{ "english", Grade::F },

			}

		},

		{

			"Vasya", "G3",

			{

				{ "math", Grade::F },

				{ "english", Grade::F },

				{ "cs", Grade::B },

				{ "dutch", Grade::C },

			}

		},

		{

			"Anton", "G4",

			{

				{ "math", Grade::F },

				{ "english", Grade::F },

				{ "dutch", Grade::C },

				{ "cs", Grade::C },

			}

		},

		{

			"Masha", "G2",

			{

				{ "math", Grade::A },

			}

		},

		{

			"Sasha", "G6",

			{

				{ "english", Grade::F },

				{ "russian", Grade::F },

				{ "dutch", Grade::F },

			}

		},

		{

			"Jeka", "G2",

			{

				{ "english", Grade::A },

			}

		},

		{

			"Sveta", "G3",

			{

			}

		}

	};

}





struct FindStudentGroup

{

	std::string neededGroup;

	bool operator()(const Student& s) const

	{

		return s.Group == neededGroup;

	}

};



struct PrinterStudent

{

	void operator()(const Student& s) const

	{

		std::cout << s.FIO << " studies in " << s.Group << std::endl;

	}

};





struct GradeEqual

{

	Grade grade = Grade::A;



	bool operator()(const std::pair<std::string, Grade> & el) const

	{

		return el.second == grade;

	}

};



struct Max

{

	std::string discipline = "math";

	Grade maxGrade = Grade::F;

	Student st;



	void operator()(const Student& s)

	{

		auto tmp = s.Grades.find(discipline);

		if (tmp != s.Grades.end())

		{

			if (tmp->second > maxGrade)

			{

				maxGrade = tmp->second;

				st = s;

			}

		}

	}

};



struct MinAverage

{

	Grade minGrade = Grade::A;

	Student st;



	void operator()(const Student& s)

	{

		size_t average = 0;

		for (auto &sub : s.Grades)

		{

			average += sub.second;

		}

		if (average == 0) return;

		average /= s.Grades.size();

		if (average < minGrade)

		{

			minGrade = (Grade)average;

			st = s;

		}

	}

};



struct MaxDisciplines

{

	size_t count = 0;

	Student st;



	void operator()(const Student &s)

	{

		if (s.Grades.size() > count)

		{

			count = s.Grades.size();

			st = s;

		}

	}

};



struct MinDisciplines

{

	size_t count = 9999999999999;

	Student st;



	void operator()(const Student &s)

	{

		if (s.Grades.size() < count)

		{

			count = s.Grades.size();

			st = s;

		}

	}

};



struct GetStudents

{

	std::string group;



	void operator()(const Student &s)

	{

		if (s.Group == group)

			std::cout << s.FIO << " studies in " << s.Group << std::endl;

	}

};



struct Finder1

{

	void operator()(const Student &s)

	{

		auto math = s.Grades.find("math");

		auto cs = s.Grades.find("cs");

		if (math != s.Grades.end() && cs != s.Grades.end() && math->second == Grade::B && cs->second == Grade::A)

		{

			std::cout << s.FIO << " studies in " << s.Group << std::endl;

		}

	}

};



struct Adder

{

	void operator()(Student &s)

	{

		size_t average = 0;

		for (auto &sub : s.Grades)

		{

			average += sub.second;

		}

		if (average == 0) return;

		average = average / s.Grades.size() + (average % s.Grades.size() > 0) ? 1 : 0;



		s.Grades.insert(std::pair<std::string, Grade>(" literature", (Grade)average));

	}

};



struct DutchGrade

{

	void operator()(const Student &s)

	{

		auto it = s.Grades.find("dutch");

		if (it != s.Grades.end())

			std::cout << s.FIO << " has " << it->second << std::endl;

		else std::cout << s.FIO << " don't study dutch" << std::endl;

	}

};







int main()

{

	std::vector<Student> students = LoadStudents();





	FindStudentGroup finderObj;

	finderObj.neededGroup = "G1";

	auto it = std::find_if(students.begin(), students.end(), finderObj);

	if (it != students.end())

		std::cout << it->FIO << std::endl;





	

	it = std::find_if(students.begin(), students.end(), FindStudentGroup{ "G7" });

	if (it != students.end())

		std::cout << it->FIO << std::endl;





	

	std::for_each(students.begin(), students.end(), PrinterStudent());






	auto cnt = std::count_if(it->Grades.begin(), it->Grades.end(), GradeEqual{});

	std::cout << cnt << std::endl;



	

	auto cnt2 = std::count_if(it->Grades.begin(), it->Grades.end(),



		[](const std::pair<std::string, Grade> & el)

	{

		return el.second == Grade::B;

	}

	);

	std::cout << cnt2 << std::endl;



	auto str = std::for_each(students.begin(), students.end(), Max()).st.FIO;

	std::cout << str << std::endl;



	str = std::for_each(students.begin(), students.end(), MinAverage()).st.FIO;

	std::cout << str << std::endl;



	str = std::for_each(students.begin(), students.end(), MaxDisciplines()).st.FIO;

	std::cout << str << std::endl;



	str = std::for_each(students.begin(), students.end(), MinDisciplines()).st.FIO;

	std::cout << str << std::endl;



	GetStudents getter;

	getter.group = "G1";

	std::for_each(students.begin(), students.end(), getter);



	std::for_each(students.begin(), students.end(), Finder1());



	std::for_each(students.begin(), students.end(), Adder());



	std::for_each(students.begin(), students.end(), DutchGrade());

}
