/* * * * * * * * * * * * * * * * * * * * * * * * *\
 *
 * FileName     :   Class_BasicSyntax.cpp
 * Author       :   https://github.com/tintinkung
 * CreateTime   :   10-10-2021 10:28:50
 * Organization :   #NONE#
 * Description  :   cpp class toturial file
 * FileType     :   C++ Source (.cpp)
 *
\* * * * * * * * * * * * * * * * * * * * * * * * */


/*\ ========= Readme =========
|*| --- C++ Class ---
|*| - a class object will have private variables declared as default.
|*| - Public scope of class will be accessors of all private variables.
|*| - default constructors(C++) will be used if theres no constructors
|*| - destructors will get destroy on the end of program or end of local codeblock(return 0;)
|*| 
|*| => See class syntax:
|*| <code>
|*|	keyword(class) class-name
|*| {
|*|		private:
|*|			//variables & functions
|*|
|*|		public:
|*|			
|*|
|*|			//constructor
|*|
|*|			//destructor
|*|
|*|			//public members
|*|
|*|			//public member-functions
|*|		protected:
|*|	};
|*| </code>
\*/

#include <iostream>
#include <string>

//an CLASS Object
class Person
{
#pragma region Private
	//things that cannot access outside this class
	private:
		int age;
		std::string name;
		std::string address;
		bool isFemale;
		std::string profession;
		bool std;
#pragma endregion

#pragma region Public
	//things that advalible for all reference
	public:
		// --- CONSTRUCTORS ---
		Person() //Person constructor
		{
			// on initialize
			std::cout << "I am default constructors!" << std::endl;

			//this-> name refere to this origin name from private.
			//this-> is a pointer to itself.
			this->name = "anomymous";
			this->age = -1;
			this->isFemale = false;
			this->address = "anomymous";
			this->profession = "anomymous";
			this->std = false;
		}

		Person(std::string name, int age, bool isFemale, std::string address, std::string profession, bool std)
		{
			// on initilize
			std::cout << "I am specialize constructors!" << std::endl;

			//this name(class name) is equal to name come from constructor input.
			this->name = name;

			this->age = age;
			this->isFemale = isFemale;
			this->address = address;
			this->profession = profession;
			this->std = std;
		}

		// --- DESTRUCTOR ---
		~Person() 
		{
			// this will trigger on destroy of this Person Object
			// std::cout << "Hello & Goodbye from Destructors" << std::endl;
		}

		#pragma region Getter
		// --- ACCESSORS ---
		// this example: returning const string reference
		// by returning const reference, it made more security in class
		// (No outsider can access the origin variable)

		inline const std::string& getName() const { return this->name; }
		inline const std::string& getAddress() const { return this->address; }
		inline const int& getAge() const { return this->age; }
		inline const bool& getIsFemale() const { return this->isFemale; }
		inline const std::string& getProfession() const { return this->profession; }
		inline const bool& getSTD() const { return this->std; }

		#pragma endregion

		#pragma region Setter
		// --- MODIFIER ---
		inline void setName(const std::string& name) { this->name = name; }
		inline void setAddress(const std::string& address) { this->address = address; }
		inline void setAge(const int& age) { this->age = age; }
		inline void setIsFemale(const bool& isFemale) { this->isFemale = isFemale; }
		inline void setProfession(const std::string& profession) { this->profession = profession; }
		inline void setSTD(const bool& std) { this->std = std; }

		#pragma endregion

		// -- FUNCTIONS --- 
		const std::string toString() const
		{
			std::string finalString = "";
			finalString =
				"Name: " + this->name + " | " +
				"Age:" + std::to_string(this->age) + " | " +
				"Female/Male: " + std::to_string(this->isFemale) + " | " +
				"Address: " + this->address + " | " +
				"Profession: " + this->profession + " | " +
				"STD?: " + std::to_string(this->std) + "\n";

			return finalString;
		}

		const std::string getGender() const
		{
			if(this->isFemale)
			{
				return "Female";
			}
			else
			{
				return "Male";
			}
		}
#pragma endregion
};

void PrintPersonData(Person person);

int main()
{
	// -- class usage examples: ---
	Person Me;
	Person Friend("Daniel", 15, false, "105/62 stredt st.", "Chef", true);
	
	std::cout << "Default Person Data: " << std::endl;
	PrintPersonData(Me);

	std::cout << "Friend's Data: " << std::endl;
	PrintPersonData(Friend);

	//setting example
	Me.setName("Rajdanhi");
	Me.setAddress("152/65, Germany chinese");
	Me.setIsFemale(false);
	Me.setAge(14);
	Me.setProfession("Programmer");
	Me.setSTD(false);
	std::cout << "My Re-assigned Data: " << std::endl;
	PrintPersonData(Me);



	std::cout << "Raw Data: " << std::endl;
	std::cout << Friend.toString() << Me.toString() << std::endl;

	system("pause");

	std::cout << "Hello from ends of Program" << std::endl;
	return 0;
}

void PrintPersonData(Person person)
{
	std::cout <<
		"Name: " << person.getName() << "\n" <<
		"Age: " << person.getAge() << "\n" <<
		"Gender: " << person.getGender() << "\n" <<
		"Address: " << person.getAddress() << "\n" <<
		"Profession: " << person.getProfession() << "\n" <<
		"STD: " << person.getSTD() << "\n" << std::endl;
}


/**
 * Try run it yourself!
 * you can always improve this code, I am not an expert writing this
 * theres still many missing things to cover in this topic. so please help me improve this folder
 **/
