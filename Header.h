#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <typeinfo>
#include <ctime>
using namespace std;

class Topic
{
	string name;
public:
	Topic(string _name)
	{
		this->name = _name;
	}
	void edit(string _name)
	{
		this->name = _name;
	}
	void print()
	{
		cout << "Topic : " << name << endl;
	}
	string getName()
	{
		return name;
	}
	void saveData(ofstream& fout)
	{
		fout << name << endl;
	}
	~Topic()
	{
		name = "";
	}
};
class LO
{
protected:
	int id;
	string name;
public:
	LO(string _name, int _id)
	{
		this->id = _id;
		this->name = _name;
	}
	virtual void print() = 0;
	virtual void saveData(ofstream&) = 0;
	virtual void edit(string) = 0;
	~LO() {}
};
class CLO : public LO
{
	Topic** topics;
	int size;
	int totalTopics;
public:
	CLO(string _name, int _id) :LO(_name, _id)
	{
		this->size = 10;
		this->topics = new Topic * [this->size];
		this->totalTopics = 0;
	}
	void edit(string _name)
	{
		name = _name;
	}
	void addTopic(Topic* _topic)
	{
		if (size == totalTopics)
		{
			Topic** temp = topics;
			size += 10;
			topics = new Topic * [size];
			for (int i = 0; i < totalTopics; i++)
				topics[i] = temp[i];
			delete[] temp;
		}
		topics[totalTopics++] = _topic;
	}
	void removeTopic(string _name)
	{
		for (int i = 0; i < totalTopics; i++)
		{
			if (topics[i]->getName() == _name)
			{
				for (; i < totalTopics - 1; i++)
				{
					topics[i] = topics[i + 1];
				}
				totalTopics--;
			}
		}
	}
	void setId(int _id)
	{
		id = _id;
	}
	int getID()
	{
		return id;
	}
	void print()
	{
		cout << "CLO Name : " << name << "     ID : " << id << endl;
		for (int i = 0; i < totalTopics; i++)
			topics[i]->print();
		//cout<<"__________________________________________________"<<endl;
	}
	void saveData(ofstream& fout)
	{
		fout << name << endl;
		fout << id << endl;
		fout << totalTopics << endl;
		for (int i = 0; i < totalTopics; i++)
		{
			fout << topics[i]->getName() << endl;
		}
	}
	~CLO()
	{
		if (size)
			delete[] topics;
	}
};
class PLO : public LO
{
	CLO** CLOs;
	int size;
	int totalCLOs;
public:
	PLO(string _name, int _id) :LO(_name, _id)
	{
		this->size = 10;
		this->CLOs = new CLO * [this->size];
		this->totalCLOs = 0;
	}
	void edit(string _name)
	{
		name = _name;
	}
	int getID()
	{
		return id;
	}
	void getAllCLOs(CLO**& list, int& total)
	{
		list = this->CLOs;
		total = this->totalCLOs;
	}
	string getName()
	{
		return this->name;
	}
	void addCLO(CLO* _CLO)
	{
		if (size == totalCLOs)
		{
			CLO** temp = CLOs;
			size += 10;
			CLOs = new CLO * [size];
			for (int i = 0; i < totalCLOs; i++)
				CLOs[i] = temp[i];
			delete[] temp;
		}
		CLOs[totalCLOs++] = _CLO;
	}
	void removeCLO(int _id)
	{
		for (int i = 0; i < totalCLOs; i++)
		{
			if (CLOs[i]->getID() == _id)
			{
				for (; i < totalCLOs - 1; i++)
				{
					CLOs[i] = CLOs[i + 1];
				}
				totalCLOs--;
			}
		}
	}
	void print()
	{
		cout << "PLO Name : " << name << "     ID : " << id << endl;
		cout << "Following CLOs are included in this PLO" << endl;
		for (int i = 0; i < totalCLOs; i++)
			CLOs[i]->print();
		//cout<<"__________________________________________________"<<endl;
	}
	void saveData(ofstream& fout)
	{
		fout << name << endl;
		fout << id << endl;
		fout << totalCLOs << endl;
		for (int i = 0; i < totalCLOs; i++)
		{
			fout << CLOs[i]->getID() << endl;
		}
	}
	~PLO()
	{
		if (size)
			delete[] CLOs;
	}
};
class Course
{
	string name;
	float creditHours;
	string courseCode;
	CLO** CLOs;
	int size;
	int totalCLOs;
	int id;
public:
	Course(string _name, int _id, float _creditHours, string _courseCode)
	{
		this->id = _id;
		this->creditHours = _creditHours;
		this->courseCode = _courseCode;
		this->name = _name;
		this->size = 10;
		this->CLOs = new CLO * [this->size];
		this->totalCLOs = 0;
	}
	void edit(string _name, float _creditHours, string _courseCode)
	{
		this->creditHours = _creditHours;
		this->courseCode = _courseCode;
		this->name = _name;
	}
	int getID()
	{
		return id;
	}
	void getAllCLOs(CLO**& list, int& total)
	{
		list = this->CLOs;
		total = this->totalCLOs;
	}
	void addCLO(CLO* _CLO)
	{
		if (size == totalCLOs)
		{
			CLO** temp = CLOs;
			size += 10;
			CLOs = new CLO * [size];
			for (int i = 0; i < totalCLOs; i++)
				CLOs[i] = temp[i];
			delete[] temp;
		}
		CLOs[totalCLOs++] = _CLO;
	}
	void removeCLO(int _id)
	{
		for (int i = 0; i < totalCLOs; i++)
		{
			if (CLOs[i]->getID() == _id)
			{
				for (; i < totalCLOs - 1; i++)
				{
					CLOs[i] = CLOs[i + 1];
				}
				totalCLOs--;
			}
		}
	}
	bool findCLOs(CLO** list, int total)
	{
		for (int i = 0; i < totalCLOs; i++)
		{
			for (int j = 0; j < total; j++)
			{
				if (list[j]->getID() == this->CLOs[i]->getID())
					return true;
			}
		}
		return false;
	}
	void saveData(ofstream& fout)
	{
		fout << name << endl;
		fout << id << endl;
		fout << courseCode << endl;
		fout << creditHours << endl;
		fout << totalCLOs << endl;
		for (int i = 0; i < totalCLOs; i++)
		{
			fout << CLOs[i]->getID() << endl;
		}
	}
	void print()
	{
		cout << "Course Name : " << name << "     ID : " << id << endl;
		cout << "Course Code : " << courseCode << "     Credit Hours : " << creditHours << endl;
		cout << "Following CLOs are included in this Course" << endl;
		for (int i = 0; i < totalCLOs; i++)
			CLOs[i]->print();
		//cout<<"__________________________________________________"<<endl;
	}
	~Course()
	{
		if (size)
			delete[] CLOs;
	}
};
class Program
{
	Course** courses;
	int totalCourses;
	int size1;
	PLO** PLOs;
	int totalPLOs;
	int size2;
	string name;
	int duration;
	int totalCreditHours;
public:
	string getName()
	{
		return name;
	}
	Program(string _name, int _duration, int _totalCreditHours)
	{
		this->name = _name;
		this->duration = _duration;
		this->totalCreditHours = _totalCreditHours;
		this->totalCourses = 0;
		this->totalPLOs = 0;
		this->size1 = 10;
		this->size2 = 10;
		this->courses = new Course * [size1];
		this->PLOs = new PLO * [size2];
	}
	void edit(string _name, int _duration, int _totalCreditHours)
	{
		this->name = _name;
		this->duration = _duration;
		this->totalCreditHours = _totalCreditHours;
	}
	void addPLO(PLO* _PLO)
	{
		if (size2 == totalPLOs)
		{
			PLO** temp = PLOs;
			size2 += 10;
			PLOs = new PLO * [size2];
			for (int i = 0; i < totalPLOs; i++)
				PLOs[i] = temp[i];
			delete[] temp;
		}
		PLOs[totalPLOs++] = _PLO;
	}
	void addCourse(Course* _Course)
	{
		if (size1 == totalCourses)
		{
			Course** temp = courses;
			size1 += 10;
			courses = new Course * [size1];
			for (int i = 0; i < totalCourses; i++)
				courses[i] = temp[i];
			delete[] temp;
		}
		courses[totalCourses++] = _Course;
	}
	void removePLO(int _id)
	{
		for (int i = 0; i < totalPLOs; i++)
		{
			if (PLOs[i]->getID() == _id)
			{
				for (; i < totalPLOs - 1; i++)
				{
					PLOs[i] = PLOs[i + 1];
				}
				totalPLOs--;
			}
		}
	}
	void removeCourse(int _id)
	{
		for (int i = 0; i < totalCourses; i++)
		{
			if (courses[i]->getID() == _id)
			{
				for (; i < totalCourses - 1; i++)
				{
					courses[i] = courses[i + 1];
				}
				totalCourses--;
			}
		}
	}
	void getCoursesByPLO(PLO* _plo)
	{
		cout << "Following Courses are relevent to the PLO : " << _plo->getName() << endl;
		CLO** list;
		int count;
		_plo->getAllCLOs(list, count);
		for (int i = 0; i < totalCourses; i++)
		{
			if (courses[i]->findCLOs(list, count))
				courses[i]->print();
		}
		cout << "******************************************" << endl;
	}
	void print()
	{
		//cout<<"______Program Details______\n";
		cout << "Program : " << this->name << endl;
		cout << "Duration : " << duration << " years        Total Credit Hours : " << totalCreditHours << endl;
		cout << "Courses : " << endl;
		for (int i = 0; i < totalCourses; i++)
			courses[i]->print();
		//cout<<endl;
		cout << "PLOs : " << endl;
		for (int i = 0; i < totalPLOs; i++)
			PLOs[i]->print();
		//cout<<"\n_________________________________\n\n";
		//cout<<"__________________________________________________"<<endl;
	}
	void saveData(ofstream& fout)
	{
		fout << name << endl;
		fout << totalCreditHours << endl;
		fout << duration << endl;
		fout << totalCourses << endl;
		for (int i = 0; i < totalCourses; i++)
		{
			fout << courses[i]->getID() << endl;
		}
		fout << totalPLOs << endl;
		for (int i = 0; i < totalPLOs; i++)
		{
			fout << PLOs[i]->getID() << endl;
		}
	}
	~Program()
	{
		if (size1)
			delete[] courses;
		if (size2)
			delete[] PLOs;
	}
};

class Question
{
	int id;
	string statement;
	CLO* clo;
public:
	Question(int _id, string _statement, CLO* _clo)
	{
		this->id = _id;
		this->statement = _statement;
		this->clo = _clo;
	}
	CLO* getCLO()
	{
		return clo;
	}
	int getID()
	{
		return id;
	}
	void edit(string new_statement)
	{
		this->statement = new_statement;
	}
	void print()
	{
		cout << "Question ID: " << id << " Statement: " << statement << " CLO: " << clo->getID() << endl;
	}
	void saveData(ofstream& fout)
	{
		fout << id << endl << statement << endl << clo->getID() << endl;
	}
	~Question()
	{
		clo = NULL;
	}
};

class Evaluation
{
protected:
	int totalMarks;
	float weightage;
public:
	Evaluation(int _totalMarks, float _weightage)
	{
		totalMarks = _totalMarks;
		weightage = _weightage;
	}
	virtual int countQuestions(int _id) = 0;
	virtual void addQuestion(Question* _Question) = 0;
	virtual string getName() = 0;
	virtual void removeQuestion(int) = 0;
	virtual void saveData(ofstream&) = 0;
	virtual void edit(int, float) = 0;
	virtual void print() = 0;
};
class Assignment : public Evaluation
{
	string name;
	char type;
	Question** ques;
	int totalQues;
	int size;
public:
	Assignment(string _name, int _totalMarks, float _weightage) :Evaluation(_totalMarks, _weightage)
	{
		this->name = _name;
		this->type = 'A';
		this->size = 10;
		this->ques = new Question * [this->size];
		this->totalQues = 0;
	}
	string getName()
	{
		return name;
	}
	void print()
	{
		cout << "Name: " << name << endl << "Total Marks: " << totalMarks << " Weightage: " << weightage << endl;
		for (int i = 0; i < totalQues; i++)
		{
			ques[i]->print();
		}
	}
	void edit(int new_totalmarks, float new_weightage)
	{
		totalMarks = new_totalmarks;
		weightage = new_weightage;
	}
	void saveData(ofstream& fout)
	{
		fout << name << endl << type << endl << totalMarks << endl << weightage << endl;
		fout << totalQues << endl;
		for (int i = 0; i < totalQues; i++)
		{
			fout << ques[i]->getID() << endl;
		}
	}
	void addQuestion(Question* _Question)
	{
		if (size == totalQues)
		{
			Question** temp = ques;
			size += 10;
			ques = new Question * [size];
			for (int i = 0; i < totalQues; i++)
				ques[i] = temp[i];
			delete[] temp;
		}
		ques[totalQues++] = _Question;
	}
	int countQuestions(int _id)
	{
		int count = 0;
		for (int i = 0; i < totalQues; i++)
		{
			if (ques[i]->getCLO()->getID() == _id)
			{
				count++;
			}
		}
		return count;
	}
	void removeQuestion(int _id)
	{
		for (int i = 0; i < totalQues; i++)
		{
			if (ques[i]->getID() == _id)
			{
				for (; i < totalQues - 1; i++)
				{
					ques[i] = ques[i + 1];
				}
				totalQues--;
			}
		}
	}
	~Assignment()
	{
		if (size)
			delete[] ques;
	}
};
class Quiz : public Evaluation
{
	string name;
	char type;
	Question** ques;
	int totalQues;
	int size;
public:
	Quiz(string _name, int _totalMarks, float _weightage) :Evaluation(_totalMarks, _weightage)
	{
		this->name = _name;
		this->type = 'Q';
		this->size = 10;
		this->ques = new Question * [this->size];
		this->totalQues = 0;
	}
	string getName()
	{
		return name;
	}
	void print()
	{
		cout << "Name: " << name << endl << "Total Marks: " << totalMarks << " Weightage: " << weightage << endl;
		for (int i = 0; i < totalQues; i++)
		{
			ques[i]->print();
		}
	}
	void saveData(ofstream& fout)
	{
		fout << name << endl << type << endl << totalMarks << endl << weightage << endl;
		fout << totalQues << endl;
		for (int i = 0; i < totalQues; i++)
		{
			fout << ques[i]->getID() << endl;
		}
	}
	void edit(int new_totalmarks, float new_weightage)
	{
		totalMarks = new_totalmarks;
		weightage = new_weightage;
	}
	void addQuestion(Question* _Question)
	{
		if (size == totalQues)
		{
			Question** temp = ques;
			size += 10;
			ques = new Question * [size];
			for (int i = 0; i < totalQues; i++)
				ques[i] = temp[i];
			delete[] temp;
		}
		ques[totalQues++] = _Question;
	}
	int countQuestions(int _id)
	{
		int count = 0;
		for (int i = 0; i < totalQues; i++)
		{
			if (ques[i]->getCLO()->getID() == _id)
			{
				count++;
			}
		}
		return count;
	}
	void removeQuestion(int _id)
	{
		for (int i = 0; i < totalQues; i++)
		{
			if (ques[i]->getID() == _id)
			{
				for (; i < totalQues - 1; i++)
				{
					ques[i] = ques[i + 1];
				}
				totalQues--;
			}
		}
	}
	~Quiz()
	{
		if (size)
			delete[] ques;
	}
};
class Exam : public Evaluation
{
	string name;
	char type;
	Question** ques;
	int totalQues;
	int size;
public:
	Exam(string _name, int _totalMarks, float _weightage) :Evaluation(_totalMarks, _weightage)
	{
		this->name = _name;
		this->type = 'E';
		this->size = 10;
		this->ques = new Question * [this->size];
		this->totalQues = 0;
	}
	string getName()
	{
		return name;
	}
	void print()
	{
		cout << "Name: " << name << endl << "Total Marks: " << totalMarks << " Weightage: " << weightage << endl;
		for (int i = 0; i < totalQues; i++)
		{
			ques[i]->print();
		}
	}
	void edit(int new_totalmarks, float new_weightage)
	{
		totalMarks = new_totalmarks;
		weightage = new_weightage;
	}
	void saveData(ofstream& fout)
	{
		fout << name << endl << type << endl << totalMarks << endl << weightage << endl;
		fout << totalQues << endl;
		for (int i = 0; i < totalQues; i++)
		{
			fout << ques[i]->getID() << endl;
		}
	}
	void addQuestion(Question* _Question)
	{
		if (size == totalQues)
		{
			Question** temp = ques;
			size += 10;
			ques = new Question * [size];
			for (int i = 0; i < totalQues; i++)
				ques[i] = temp[i];
			delete[] temp;
		}
		ques[totalQues++] = _Question;
	}
	int countQuestions(int _id)
	{
		int count = 0;
		for (int i = 0; i < totalQues; i++)
		{
			if (ques[i]->getCLO()->getID() == _id)
			{
				count++;
			}
		}
		return count;
	}
	void removeQuestion(int _id)
	{
		for (int i = 0; i < totalQues; i++)
		{
			if (ques[i]->getID() == _id)
			{
				for (; i < totalQues - 1; i++)
				{
					ques[i] = ques[i + 1];
				}
				totalQues--;
			}
		}
	}
	~Exam()
	{
		if (size)
			delete[] ques;
	}
};

class Evaluator
{
	Evaluation** evaluations;
	int totalEvaluations;
	int size1;
	Question** questions;
	int totalQuestions;
	int size2;
public:
	Evaluator()
	{
		size1 = 10;
		totalEvaluations = 0;
		evaluations = new Evaluation * [size1];
		size2 = 10;
		totalQuestions = 0;
		questions = new Question * [size2];
	}
	void createEvaluation(char type, string _name, int _totalMarks, float _weightage)
	{
		Evaluation* _Evaluation=NULL;
		if (type == 'A')
			_Evaluation = new Assignment(_name, _totalMarks, _weightage);
		if (type == 'Q')
			_Evaluation = new Quiz(_name, _totalMarks, _weightage);
		if (type == 'E')
			_Evaluation = new Exam(_name, _totalMarks, _weightage);
		if (size1 == totalEvaluations)
		{
			Evaluation** temp = evaluations;
			size1 += 10;
			evaluations = new Evaluation * [size1];
			for (int i = 0; i < totalEvaluations; i++)
				evaluations[i] = temp[i];
			delete[] temp;
		}
		evaluations[totalEvaluations++] = _Evaluation;
	}
	void createQuestion(int _id, string _statement, CLO* _CLO)
	{
		Question* _Question = new Question(_id, _statement, _CLO);
		if (size1 == totalQuestions)
		{
			Question** temp = questions;
			size1 += 10;
			questions = new Question * [size1];
			for (int i = 0; i < totalQuestions; i++)
				questions[i] = temp[i];
			delete[] temp;
		}
		questions[totalQuestions++] = _Question;
	}
	bool checkCLOHasTested(int _id)
	{
		int totalCount = 0;
		for (int i = 0; i < totalEvaluations; i++)
			totalCount += evaluations[i]->countQuestions(_id);
		if (totalCount > 2)
			return true;
		return false;
	}
	void printAllQuestions()
	{
		for (int i = 0; i < totalQuestions; i++)
			questions[i]->print();
	}
	void printAllEvaluations()
	{
		for (int i = 0; i < totalEvaluations; i++)
			evaluations[i]->print();
	}
	void saveQuestions(ofstream& fout)
	{
		fout << totalQuestions << endl;
		for (int i = 0; i < totalQuestions; i++)
			questions[i]->saveData(fout);
	}
	void saveEvaluations(ofstream& fout)
	{
		fout << totalEvaluations << endl;
		for (int i = 0; i < totalEvaluations; i++)
			evaluations[i]->saveData(fout);
	}
	Question* findQuestion(int _id)
	{
		for (int i = 0; i < totalQuestions; i++)
		{
			if (questions[i]->getID() == _id)
				return questions[i];
		}
		return NULL;
	}
	Evaluation* findEvaluation(string _name)
	{
		for (int i = 0; i < totalEvaluations; i++)
		{
			if (evaluations[i]->getName() == _name)
				return evaluations[i];
		}
		return NULL;
	}
	void addQuestionToEvaluation(int _id, string _name)
	{
		Question* _Question = this->findQuestion(_id);
		if (_Question)
		{
			Evaluation* _Evaluation = this->findEvaluation(_name);
			if (_Evaluation)
			{
				_Evaluation->addQuestion(_Question);
			}
			else
			{
				cout << "Evaluation not Found" << endl;
			}
		}
		else
		{
			cout << "Question not Found" << endl;
		}
	}
	void editQuestion(int _id, string new_Statement)
	{
		Question* _Question = findQuestion(_id);
		if (_Question)
		{
			_Question->edit(new_Statement);
		}
		else
		{
			cout << "Question not Found" << endl;
		}
	}
	void editEvaluation(string name, int new_totalMarks, float new_weightage)
	{
		Evaluation* _Evaluation = findEvaluation(name);
		if (_Evaluation)
		{
			_Evaluation->edit(new_totalMarks, new_weightage);
		}
		else
		{
			cout << "Question not Found" << endl;
		}
	}
	void removeQuestionFromEvaluation(int Question_id, string Evaluation_name)
	{
		Evaluation* _Evaluation = this->findEvaluation(Evaluation_name);
		if (_Evaluation)
		{
			_Evaluation->removeQuestion(Question_id);
		}
		else
		{
			cout << "Evaluation not found" << endl;
		}
	}
	~Evaluator()
	{
		if (evaluations)
			delete[] evaluations;
	}
};
class AcademicManager
{
	Topic** topics;
	int totalTopics;
	int size1;
	CLO** CLOs;
	int totalCLOs;
	int size2;
	PLO** PLOs;
	int totalPLOs;
	int size3;
	Course** courses;
	int totalCourses;
	int size4;
	Program** programs;
	int totalPrograms;
	int size5;
	Evaluator* evaluator;

public:
	AcademicManager()
	{
		totalTopics = 0;
		size1 = 10;
		topics = new Topic * [size1];
		totalCLOs = 0;
		size2 = 10;
		CLOs = new CLO * [size2];
		totalPLOs = 0;
		size3 = 10;
		PLOs = new PLO * [size3];
		totalCourses = 0;
		size4 = 10;
		courses = new Course * [size4];
		totalPrograms = 0;
		size5 = 10;
		programs = new Program * [size5];
		evaluator = new Evaluator();
	}
	void printAllTopics()
	{
		cout << "\nAll Topics\n";
		for (int i = 0; i < totalTopics; i++)
			topics[i]->print();
		cout << "__________________________________________" << endl;
	}
	void printAllCLOs()
	{
		cout << "\nAll CLOs\n";
		for (int i = 0; i < totalCLOs; i++)
			CLOs[i]->print();
		cout << "__________________________________________" << endl;
	}
	void printAllPLOs()
	{
		cout << "\nAll PLOs\n";
		for (int i = 0; i < totalPLOs; i++)
			PLOs[i]->print();
		cout << "__________________________________________" << endl;
	}
	void printAllCourses()
	{
		cout << "\nAll Courses\n";
		for (int i = 0; i < totalCourses; i++)
			courses[i]->print();
		cout << "__________________________________________" << endl;
	}
	void printAllPrograms()
	{
		cout << "\nAll Programs\n";
		for (int i = 0; i < totalPrograms; i++)
			programs[i]->print();
		//cout<<"__________________________________________"<<endl;
	}
	void printAllQuestions()
	{
		evaluator->printAllQuestions();
	}
	void printAllEvaluations()
	{
		evaluator->printAllEvaluations();
	}
	void createTopic(string _name)
	{
		Topic* _topic = new Topic(_name);
		if (size1 == totalTopics)
		{
			Topic** temp = topics;
			size1 += 10;
			topics = new Topic * [size1];
			for (int i = 0; i < totalTopics; i++)
				topics[i] = temp[i];
			delete[] temp;
		}
		topics[totalTopics++] = _topic;
	}
	void createCLO(string _name, int _id)
	{
		CLO* _CLO = new CLO(_name, _id);
		if (size2 == totalCLOs)
		{
			CLO** temp = CLOs;
			size2 += 10;
			CLOs = new CLO * [size2];
			for (int i = 0; i < totalCLOs; i++)
				CLOs[i] = temp[i];
			delete[] temp;
		}
		CLOs[totalCLOs++] = _CLO;
	}
	void createPLO(string _name, int _id)
	{
		PLO* _PLO = new PLO(_name, _id);
		if (size3 == totalCLOs)
		{
			PLO** temp = PLOs;
			size3 += 10;
			PLOs = new PLO * [size3];
			for (int i = 0; i < totalPLOs; i++)
				PLOs[i] = temp[i];
			delete[] temp;
		}
		PLOs[totalPLOs++] = _PLO;
	}
	void createCourse(string _name, int _id, string _courseCode, float _creditHours)
	{
		Course* _Course = new Course(_name, _id, _creditHours, _courseCode);
		if (size4 == totalCourses)
		{
			Course** temp = courses;
			size4 += 10;
			courses = new Course * [size4];
			for (int i = 0; i < totalCourses; i++)
				courses[i] = temp[i];
			delete[] temp;
		}
		courses[totalCourses++] = _Course;
	}
	void createProgram(string _name, int _duration, int _totalCreditHours)
	{
		Program* _Program = new Program(_name, _duration, _totalCreditHours);
		if (size5 == totalPrograms)
		{
			Program** temp = programs;
			size5 += 10;
			programs = new Program * [size5];
			for (int i = 0; i < totalPrograms; i++)
				programs[i] = temp[i];
			delete[] temp;
		}
		programs[totalPrograms++] = _Program;
	}
	void createQuestion(int _id, string _statement, int CLO_id)
	{
		CLO* _CLO = this->findCLO(CLO_id);
		if (!_CLO)
			cout << "CLO not found" << endl;
		evaluator->createQuestion(_id, _statement, _CLO);
	}
	void createEvaluation(char _type, string _name, int _totalMarks, float _weightage)
	{
		evaluator->createEvaluation(_type, _name, _totalMarks, _weightage);
	}
	Topic* findTopic(string _name)
	{
		for (int i = 0; i < totalTopics; i++)
		{
			if (topics[i]->getName() == _name)
				return topics[i];
		}
		return NULL;
	}
	CLO* findCLO(int _id)
	{
		for (int i = 0; i < totalCLOs; i++)
		{
			if (CLOs[i]->getID() == _id)
				return CLOs[i];
		}
		return NULL;
	}
	PLO* findPLO(int _id)
	{
		for (int i = 0; i < totalPLOs; i++)
		{
			if (PLOs[i]->getID() == _id)
				return PLOs[i];
		}
		return NULL;
	}
	Course* findCourse(int _id)
	{
		for (int i = 0; i < totalCourses; i++)
		{
			if (courses[i]->getID() == _id)
				return courses[i];
		}
		return NULL;
	}
	Program* findProgram(string _name)
	{
		for (int i = 0; i < totalPrograms; i++)
		{
			if (programs[i]->getName() == _name)
				return programs[i];
		}
		return NULL;
	}
	void addTopicToCLO(string topicName, int _id)
	{
		Topic* _topic = this->findTopic(topicName);
		if (_topic)
		{
			CLO* _CLO = this->findCLO(_id);
			if (_CLO)
			{
				_CLO->addTopic(_topic);
			}
			else
			{
				cout << "CLO not Found" << endl;
			}
		}
		else
		{
			cout << "Topic not Found" << endl;
		}
	}
	void addCLOToPLO(int CLO_id, int PLO_id)
	{
		CLO* _CLO = this->findCLO(CLO_id);
		if (_CLO)
		{
			PLO* _PLO = this->findPLO(PLO_id);
			if (_PLO)
			{
				_PLO->addCLO(_CLO);
			}
			else
			{
				cout << "PLO not Found" << endl;
			}
		}
		else
		{
			cout << "CLO not Found" << endl;
		}
	}
	void addCLOToCourse(int CLO_id, int Course_id)
	{
		CLO* _CLO = this->findCLO(CLO_id);
		if (_CLO)
		{
			Course* _Course = this->findCourse(Course_id);
			if (_Course)
			{
				_Course->addCLO(_CLO);
			}
			else
			{
				cout << "Course not Found" << endl;
			}
		}
		else
		{
			cout << "CLO not Found" << endl;
		}
	}
	void addCourseToProgram(int Course_id, string name)
	{
		Course* _Course = this->findCourse(Course_id);
		if (_Course)
		{
			Program* _Program = this->findProgram(name);
			if (_Program)
			{
				_Program->addCourse(_Course);
			}
			else
			{
				cout << "Program not Found" << endl;
			}
		}
		else
		{
			cout << "Course not Found" << endl;
		}
	}
	void addPLOToProgram(int PLO_id, string name)
	{
		PLO* _PLO = this->findPLO(PLO_id);
		if (_PLO)
		{
			Program* _Program = this->findProgram(name);
			if (_Program)
			{
				_Program->addPLO(_PLO);
			}
			else
			{
				cout << "Program not Found" << endl;
			}
		}
		else
		{
			cout << "PLO not Found" << endl;
		}
	}
	void addQuestionToEvaluation(int Question_id, string _name)
	{
		evaluator->addQuestionToEvaluation(Question_id, _name);
	}
	void editTopic(string old_name, string new_name)
	{
		Topic* _topic = findTopic(old_name);
		if (_topic)
		{
			_topic->edit(new_name);
		}
		else
		{
			cout << "Topic not Found" << endl;
		}
	}
	void editCLO(int _id, string new_name)
	{
		CLO* _CLO = findCLO(_id);
		if (_CLO)
		{
			_CLO->edit(new_name);
		}
		else
		{
			cout << "CLO not Found" << endl;
		}
	}
	void editPLO(int _id, string new_name)
	{
		PLO* _PLO = findPLO(_id);
		if (_PLO)
		{
			_PLO->edit(new_name);
		}
		else
		{
			cout << "PLO not Found" << endl;
		}
	}
	void editCourse(int _id, string new_name, string new_courseCode, float new_creditHours)
	{
		Course* _Course = findCourse(_id);
		if (_Course)
		{
			_Course->edit(new_name, new_creditHours, new_courseCode);
		}
		else
		{
			cout << "Course not Found" << endl;
		}
	}
	void editProgram(string old_name, string new_name, int new_duration, int new_totalCreditHours)
	{
		Program* _Program = findProgram(old_name);
		if (_Program)
		{
			_Program->edit(new_name, new_duration, new_totalCreditHours);
		}
		else
		{
			cout << "Program not Found" << endl;
		}
	}
	void editQuestion(int _id, string new_Statement)
	{
		evaluator->editQuestion(_id, new_Statement);
	}
	void editEvaluation(string name, int new_totalMarks, float new_weightage)
	{
		evaluator->editEvaluation(name, new_totalMarks, new_weightage);
	}
	void removeTopicFromCLO(int _id, string _name)
	{
		CLO* _CLO = this->findCLO(_id);
		if (_CLO)
		{
			_CLO->removeTopic(_name);
		}
		else
		{
			cout << "CLO not found" << endl;
		}
	}
	void removeCLOFromPLO(int CLO_id, int PLO_id)
	{
		PLO* _PLO = this->findPLO(PLO_id);
		if (_PLO)
		{
			_PLO->removeCLO(CLO_id);
		}
		else
		{
			cout << "PLO not found" << endl;
		}
	}
	void removeCLOFromCourse(int Course_id, int CLO_id)
	{
		Course* _Course = this->findCourse(Course_id);
		if (_Course)
		{
			_Course->removeCLO(CLO_id);
		}
		else
		{
			cout << "Course not found" << endl;
		}
	}
	void removePLOFromProgram(string _name, int PLO_id)
	{
		Program* _Program = this->findProgram(_name);
		if (_Program)
		{
			_Program->removePLO(PLO_id);
		}
		else
		{
			cout << "Program not found" << endl;
		}
	}
	void removeCourseFromProgram(string _name, int Course_id)
	{
		Program* _Program = this->findProgram(_name);
		if (_Program)
		{
			_Program->removeCourse(Course_id);
		}
		else
		{
			cout << "Program not found" << endl;
		}
	}
	void removeQuestionFromEvaluation(int Question_id, string Evaluation_name)
	{
		evaluator->removeQuestionFromEvaluation(Question_id, Evaluation_name);
	}
	void listOfRelevantCourses(string _name, int PLO_id)
	{
		PLO* _PLO = this->findPLO(PLO_id);
		if (_PLO)
		{
			Program* _Program = this->findProgram(_name);
			if (_Program)
			{
				_Program->getCoursesByPLO(_PLO);
			}
			else
			{
				cout << "Program not Found" << endl;
			}
		}
		else
		{
			cout << "PLO not Found" << endl;
		}
	}
	bool allCLOsTested(int Course_id)
	{
		bool check = true;
		Course* _Course = this->findCourse(Course_id);
		CLO** _CLOs;
		int total;
		_Course->getAllCLOs(_CLOs, total);
		for (int i = 0; i < total && check; i++)
			if (!evaluator->checkCLOHasTested(_CLOs[i]->getID()))
				check = false;
		return check;
	}
	void saveData()
	{
		char option;
		cout << "Save Data? (y/n) : ";
		cin >> option;
		if (option == 'y')
		{
			ofstream fout;
			fout.open("topics.txt");
			fout << totalTopics << endl;
			for (int i = 0; i < totalTopics; i++)
				topics[i]->saveData(fout);
			fout.close();
			fout.open("CLOs.txt");
			fout << totalCLOs << endl;
			for (int i = 0; i < totalCLOs; i++)
				CLOs[i]->saveData(fout);
			fout.close();
			fout.open("PLOs.txt");
			fout << totalPLOs << endl;
			for (int i = 0; i < totalPLOs; i++)
				PLOs[i]->saveData(fout);
			fout.close();
			fout.open("Courses.txt");
			fout << totalCourses << endl;
			for (int i = 0; i < totalCourses; i++)
				courses[i]->saveData(fout);
			fout.close();
			fout.open("Programs.txt");
			fout << totalPrograms << endl;
			for (int i = 0; i < totalPrograms; i++)
				programs[i]->saveData(fout);
			fout.close();
			fout.open("Questions.txt");
			evaluator->saveQuestions(fout);
			fout.close();
			fout.open("Evaluations.txt");
			evaluator->saveEvaluations(fout);
			fout.close();

		}
		else
		{
			cout << "***Data not Saved***" << endl;
		}
	}
	void readData()
	{
		ifstream fin;
		fin.open("topics.txt");
		if (fin)
		{
			string _name;
			int total;
			fin >> total;
			for (int i = 0; i < total; i++)
			{
				fin >> _name;
				this->createTopic(_name);
			}
		}
		fin.close();
		fin.open("CLOs.txt");
		if (fin)
		{
			int total;
			string _name;
			int _id;
			int count;
			fin >> total;
			for (int i = 0; i < total; i++)
			{
				fin >> _name >> _id;
				this->createCLO(_name, _id);
				fin >> count;
				for (int j = 0; j < count; j++)
				{
					fin >> _name;
					addTopicToCLO(_name, _id);
				}
			}
		}
		fin.close();
		fin.open("PLOs.txt");
		if (fin)
		{
			int total;
			string _name;
			int _id;
			int count;
			fin >> total;
			for (int i = 0; i < total; i++)
			{
				fin >> _name >> _id;
				this->createPLO(_name, _id);
				fin >> count;
				int CLO_id;
				for (int j = 0; j < count; j++)
				{
					fin >> CLO_id;
					addCLOToPLO(CLO_id, _id);
				}
			}
		}
		fin.close();
		fin.open("Courses.txt");
		if (fin)
		{
			int total;
			string _name;
			int _id;
			float creditHour;
			string courseCode;
			int count;
			fin >> total;
			for (int i = 0; i < total; i++)
			{
				fin >> _name >> _id >> courseCode >> creditHour;
				this->createCourse(_name, _id, courseCode, creditHour);
				fin >> count;
				int CLO_id;
				for (int j = 0; j < count; j++)
				{
					fin >> CLO_id;
					addCLOToCourse(CLO_id, _id);
				}
			}
		}
		fin.close();
		fin.open("Programs.txt");
		if (fin)
		{
			int total;
			string _name;
			int totalCreditHour;
			int duration;
			int count;
			fin >> total;
			for (int i = 0; i < total; i++)
			{
				fin >> _name >> totalCreditHour >> duration;
				this->createProgram(_name, duration, totalCreditHour);
				fin >> count;
				int Course_id;
				for (int j = 0; j < count; j++)
				{
					fin >> Course_id;
					addCourseToProgram(Course_id, _name);
				}
				fin >> count;
				int PLO_id;
				for (int j = 0; j < count; j++)
				{
					fin >> PLO_id;
					addPLOToProgram(PLO_id, _name);
				}
			}
		}
		fin.close();
		fin.open("Questions.txt");
		if (fin)
		{
			int total;
			string _name;
			int Question_id, CLO_id;
			fin >> total;
			for (int i = 0; i < total; i++)
			{
				fin >> Question_id >> _name >> CLO_id;
				this->createQuestion(Question_id, _name, CLO_id);
			}
		}
		fin.close();
		fin.open("Evaluations.txt");
		if (fin)
		{
			int total;
			string _name;
			char type;
			int totalMarks;
			float weightage;
			int count, _id;
			fin >> total;
			for (int i = 0; i < total; i++)
			{
				fin >> _name >> type >> totalMarks >> weightage;
				this->createEvaluation(type, _name, totalMarks, weightage);
				fin >> count;
				for (int j = 0; j < count; j++)
				{
					fin >> _id;
					addQuestionToEvaluation(_id, _name);
				}
			}
		}
		fin.close();
	}
	~AcademicManager()
	{
		if (size1)
			delete[] topics;
		if (size2)
			delete[] CLOs;
		if (size3)
			delete[] PLOs;
		if (size4)
			delete[] courses;
		if (size5)
			delete[] programs;
		if (evaluator)
			delete evaluator;
	}
};
