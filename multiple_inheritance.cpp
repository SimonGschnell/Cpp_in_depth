#include <iostream>
#include <string>
#include <string_view>

//? C++ allows multiple inheritance

class Employee{
    private:
        int m_salary{};
    public:
        Employee(int salary): m_salary{salary}{}
};

class Person{
    private:
        std::string m_name{};
    public:
        Person(std::string_view name): m_name{name}{}
};

//? we use simple inheritance, by inheriting multiple classes separated by commas
class Teacher: public Person, public Employee{
    public:
        Teacher(int salary, std::string_view name):Person{name}, Employee{salary}{}
};

//! Mixins
//* Mixins are classes that add properties to a derived class and are not intended to be instantiated on their own 
//* (They also don't have a constructor)

class Label 
{
public:
	void setText(const std::string_view str) { m_text = str; }
	void setFontSize(int fontSize) { m_fontSize = fontSize; }
private:
	std::string m_text{};
	int m_fontSize{};
};

class Color 
{
public:
    enum Colors{ blue, red, green };
	void setColor(Colors c) { m_color = c; }
private:
	Colors m_color{};
};

//? adding all the properties from the mixins Label and Color to the Button class using multiple inheritance
class Button : public Label, public Color{};

int main(){
    Teacher t{100,"Simon"};

    Button b{};
    //? we use the scope resolution prefixes of the mixins to make the code easier to read and clearer
    //! if two mixins were to have to same property name, without the prefix, a ambiguous function call would occur
    b.Color::setColor(Color::blue);
    b.Label::setFontSize(10);
    b.Label::setText("test");
    

}