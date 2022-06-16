#include <string>

#include <vector>

#include <iostream>

using namespace std;

 

/*Employee abstract base class.*/

class Employee

{

    public:

        Employee( const string & );

        void setName( const string & );

        string getName() const;

		virtual void print() const;
		
		virtual double earning() const;
 

                //your code...

 

    private:   

        string Name;   

};

Employee::Employee( const string & name ): Name(name)

{}

void Employee::setName( const string &name )

{

    Name = name;

}

string Employee::getName() const

{

    return Name;

}

void Employee::print() const

{

    cout << getName();

}

double Employee::earning()const{
	return 0;
}

 

/*SalariedEmployee class derived from Employee.*/

class SalariedEmployee : public Employee

{

    public:

        SalariedEmployee( const string &, double = 0.0 );

        void setWeeklySalary( double in_salary);

        double getWeeklySalary() const;
		
		void print()const;

		double earning()const;

 

        //your code...

    private:   

        double weeklySalary;   

};

SalariedEmployee::SalariedEmployee( const string & in_name,double in_salary):Employee(in_name){
	weeklySalary = in_salary;
}

void SalariedEmployee::setWeeklySalary( double in_salary){
	weeklySalary = in_salary;
}

double SalariedEmployee::getWeeklySalary()const{
	return weeklySalary;
}

void SalariedEmployee::print()const{
	cout << "salaried employee: " << getName() << "\nweekly salary: " << weeklySalary;
}

double SalariedEmployee::earning()const{
	return weeklySalary;
}
 
/*CommissionEmployee class derived from Employee.*/

class CommissionEmployee : public Employee

{

    public:

        CommissionEmployee(const string&, double = 0.0, double = 0.0);

        void setGrossSales( double );

        double getGrossSales() const;

        void setCommissionRate( double );

        double getCommissionRate() const;

		void print()const;

		double earning()const;
 

        //your code...

    private:       

        double grossSales;

        double commissionRate;

};

CommissionEmployee::CommissionEmployee(const string& in_name, double in_gross, double in_com):Employee(in_name){
	grossSales = in_gross;
	commissionRate = in_com;
}

void CommissionEmployee::setGrossSales( double in_gross){
	grossSales = in_gross;
}

double CommissionEmployee::getGrossSales()const{
	return grossSales;
}

void CommissionEmployee::setCommissionRate( double in_com){
	commissionRate = in_com;
}

double CommissionEmployee::getCommissionRate()const{
	return commissionRate;
}
 

double CommissionEmployee::earning()const{
	double earn;
	earn = grossSales * commissionRate;
	return earn;
}

void CommissionEmployee::print()const{
	cout << "commission employee: " << getName() << "\ngross sales: " << grossSales << "; commission rate: " << commissionRate; 
}
/*BasePlusCommissionEmployee class derived from CommissionEmployee.*/

class BasePlusCommissionEmployee : public CommissionEmployee

{

    public:

        BasePlusCommissionEmployee(const string&, double = 0.0, double = 0.0, double = 0.0 );

        void setBaseSalary( double );

        double getBaseSalary() const;

		void print()const;

		double earning()const;
 

        //your code...

    private:       

        double baseSalary;

};

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& in_name, double in_gross, double in_com , double in_base ):CommissionEmployee(in_name,in_gross,in_com){
	baseSalary = in_base;
}

double BasePlusCommissionEmployee::earning()const{
	double earn;
	earn = getGrossSales() * getCommissionRate();
	earn += baseSalary;
	return earn;
}

void BasePlusCommissionEmployee::print()const{
	cout << "base-salaried commission employee: " << getName() << "\ngross sales: " << getGrossSales() << "; commission rate: " << getCommissionRate() << "; base salary: " << baseSalary;
}

void virtualViaPointer( const Employee * const baseClassPtr )

{

      baseClassPtr->print();

    cout << "\nearned $" << baseClassPtr->earning() << "\n\n";

}


int main()

{

        string name1,name2,name3;

        double salary, sales, rate, basesales, baserate, basesalary;

        while( cin >> name1 >> salary    >>

                              name2 >> sales     >> rate     >>

                              name3 >> basesales >> baserate >> basesalary)

        {

                SalariedEmployee salariedEmployee(name1,salary);

                CommissionEmployee commissionEmployee(name2,sales,rate);

                BasePlusCommissionEmployee basePlusCommissionEmployee(name3,basesales,baserate,basesalary);

 

                vector < Employee* > employee(3);

                employee[0] = &salariedEmployee;

                employee[1] = &commissionEmployee;

                employee[2] = &basePlusCommissionEmployee;

 

                for( size_t i = 0; i < employee.size(); i++ )

                        virtualViaPointer( employee[i] );

        }      

}
