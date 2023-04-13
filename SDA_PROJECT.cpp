#include "Header.h"

int main()
{
	{
			cout << "               ------------------------------------------------------------------" << endl;
			cout << "               -                           SDA PROJECT                          -\n";
			cout << "               -                                                                -\n";
			cout << "               -                               OBE                              -\n";
			cout << "               -                             SUPPORT                            -\n";
			cout << "               -                              SYSTEM                            -\n";
			cout << "               -                                                                -\n";
			cout << "               -                                                                -\n";
			cout << "               -                                                                -\n";
			cout << "               -                                                                -\n";
			cout << "               -                                                                -\n";
			cout << "               -    NAME:MUNEEB AWAN            ROLL NO:20L-2159                -\n";
			cout << "               -    NAME:WAHAB AWAN             ROLL NO:20L-2122                -\n";
			cout << "               -                                                                -\n";
			cout << "               ------------------------------------------------------------------" << endl;
			


			int enter ;
			cout << "Enter 1 go to menu" << endl;
			cin >> enter;
			char e = 1;
			if (enter == e)
				system("cls");

		srand(time(0));
		{
			AcademicManager manager;
			manager.readData();
			int option1, option2;
			while (1)
			{
				cout << "0 for Exit" << endl;
				cout << "1 for View" << endl;
				cout << "2 for Add" << endl;
				cout << "3 for Create" << endl;
				cout << "4 for Edit" << endl;
				cout << "5 for Remove" << endl;
				cout << "6 for List of relevant courses for PLO" << endl;
				cout << "7 CLOs of a Course are tested" << endl;
				cout << "8 for Clear Screen" << endl;

				cout << "Enter any option: ";
				cin >> option1;
				if (option1 == 0)
				{
					manager.saveData();
					break;
				}
				if (option1 == 1)
				{
					cout << "1 for Topics" << endl;
					cout << "2 for CLOs" << endl;
					cout << "3 for PLOs" << endl;
					cout << "4 for Courses" << endl;
					cout << "5 for Programs" << endl;
					cout << "6 for Questions" << endl;
					cout << "7 for Evaluations" << endl;

					cout << "Enter any option: ";
					cin >> option2;

					if (option2 == 1)
					{
						manager.printAllTopics();
					}
					if (option2 == 2)
					{
						manager.printAllCLOs();
					}
					if (option2 == 3)
					{
						manager.printAllPLOs();
					}
					if (option2 == 4)
					{
						manager.printAllCourses();
					}
					if (option2 == 5)
					{
						manager.printAllPrograms();
					}
					if (option2 == 6)
					{
						manager.printAllQuestions();
					}
					if (option2 == 7)
					{
						manager.printAllEvaluations();
					}
				}
				if (option1 == 2)
				{

					cout << "1 for AddTopicToCLO" << endl;
					cout << "2 for AddCLOToPLO" << endl;
					cout << "3 for AddCLOToCourse" << endl;
					cout << "4 for AddPLOToProgram" << endl;
					cout << "5 for AddCourseToProgram" << endl;
					cout << "6 for AddQuestionToEvaluation" << endl;

					cout << "Enter any option: ";
					cin >> option2;
					if (option2 == 1)
					{
						string name;
						int id;
						cout << "Enter Topic name: ";
						cin >> name;
						cout << "Enter CLO ID: ";
						cin >> id;
						manager.addTopicToCLO(name, id);
					}
					if (option2 == 2)
					{
						int CLO_id, PLO_id;
						cout << "Enter CLO ID: ";
						cin >> CLO_id;
						cout << "Enter PLO ID: ";
						cin >> PLO_id;
						manager.addCLOToPLO(CLO_id, PLO_id);
					}
					if (option2 == 3)
					{
						int CLO_id, Course_id;
						cout << "Enter CLO ID: ";
						cin >> CLO_id;
						cout << "Enter Course ID: ";
						cin >> Course_id;
						manager.addCLOToCourse(CLO_id, Course_id);
					}
					if (option2 == 4)
					{
						int PLO_id;
						string name;
						cout << "Enter PLO ID: ";
						cin >> PLO_id;
						cout << "Enter Program Name: ";
						cin >> name;
						manager.addPLOToProgram(PLO_id, name);
					}
					if (option2 == 5)
					{
						int Course_id;
						string name;
						cout << "Enter Course ID: ";
						cin >> Course_id;
						cout << "Enter Program Name: ";
						cin >> name;
						manager.addCourseToProgram(Course_id, name);
					}
					if (option2 == 6)
					{
						int Question_id;
						string name;
						cout << "Enter Question ID: ";
						cin >> Question_id;
						cout << "Enter Evaluation Name: ";
						cin >> name;
						manager.addQuestionToEvaluation(Question_id, name);
					}
				}
				if (option1 == 3)
				{
					cout << "1 for Create Topic" << endl;
					cout << "2 for Create CLO" << endl;
					cout << "3 for Create PLO" << endl;
					cout << "4 for Create Course" << endl;
					cout << "5 for Create Program" << endl;
					cout << "6 for Create Question" << endl;
					cout << "7 for Create Assignment" << endl;
					cout << "8 for Create Quiz" << endl;
					cout << "9 for Create Exam" << endl;

					cout << "Enter any option: ";
					cin >> option2;
					if (option2 == 1)
					{
						string name;
						cout << "Enter Topic name: ";
						cin >> name;
						manager.createTopic(name);
					}
					if (option2 == 2)
					{
						string name;
						cout << "Enter CLO name: ";
						cin >> name;
						manager.createCLO(name, rand() % 100000);
					}
					if (option2 == 3)
					{
						string name;
						cout << "Enter PLO name: ";
						cin >> name;
						manager.createPLO(name, rand() % 100000);
					}
					if (option2 == 4)
					{
						string name, courseCode;
						float creditHours;
						cout << "Enter Course name: ";
						cin >> name;
						cout << "Enter Course Code: ";
						cin >> courseCode;
						cout << "Enter Credit Hours: ";
						cin >> creditHours;
						manager.createCourse(name, rand() % 100000, courseCode, creditHours);
					}
					if (option2 == 5)
					{
						string name;
						int totalCreditHour, duration;
						cout << "Enter Program name: ";
						cin >> name;
						cout << "Enter Program total credit hours: ";
						cin >> totalCreditHour;
						cout << "Enter Program duration: ";
						cin >> duration;
						manager.createProgram(name, duration, totalCreditHour);
					}
					if (option2 == 6)
					{
						string statement;
						int CLO_id;
						cout << "Enter Question statement: ";
						cin >> statement;
						cout << "Enter related CLO ID: ";
						cin >> CLO_id;
						manager.createQuestion(rand() % 100000, statement, CLO_id);
					}
					if (option2 == 7)
					{
						string name;
						int totalmarks;
						float weightage;
						cout << "Enter Name: ";
						cin >> name;
						cout << "Enter total marks: ";
						cin >> totalmarks;
						cout << "Enter weightage: ";
						cin >> weightage;
						manager.createEvaluation('A', name, totalmarks, weightage);
					}
					if (option2 == 8)
					{
						string name;
						int totalmarks;
						float weightage;
						cout << "Enter Name: ";
						cin >> name;
						cout << "Enter total marks: ";
						cin >> totalmarks;
						cout << "Enter weightage: ";
						cin >> weightage;
						manager.createEvaluation('Q', name, totalmarks, weightage);
					}
					if (option2 == 9)
					{
						string name;
						int totalmarks;
						float weightage;
						cout << "Enter Name: ";
						cin >> name;
						cout << "Enter total marks: ";
						cin >> totalmarks;
						cout << "Enter weightage: ";
						cin >> weightage;
						manager.createEvaluation('E', name, totalmarks, weightage);
					}
				}
				if (option1 == 4)
				{
					cout << "1 for Edit Topic" << endl;
					cout << "2 for Edit CLO" << endl;
					cout << "3 for Edit PLO" << endl;
					cout << "4 for Edit Course" << endl;
					cout << "5 for Edit Program" << endl;
					cout << "6 for Edit Question" << endl;
					cout << "7 for Edit Evaluation" << endl;

					cout << "Enter any option: ";
					cin >> option2;

					if (option2 == 1)
					{
						string new_name, old_name;
						cout << "Enter Name of Topic: ";
						cin >> old_name;
						cout << "Enter New Name of Topic: ";
						cin >> new_name;
						manager.editTopic(old_name, new_name);
					}
					if (option2 == 2)
					{
						int _id;
						string new_name;
						cout << "Enter Id of CLO: ";
						cin >> _id;
						cout << "Enter New Name of CLO: ";
						cin >> new_name;
						manager.editCLO(_id, new_name);
					}
					if (option2 == 3)
					{
						int _id;
						string new_name;
						cout << "Enter Id of PLO: ";
						cin >> _id;
						cout << "Enter New Name of PLO: ";
						cin >> new_name;
						manager.editPLO(_id, new_name);
					}
					if (option2 == 4)
					{
						int _id;
						string new_name, new_courseCode;
						float new_creditHour;
						cout << "Enter Id of Course: ";
						cin >> _id;
						cout << "Enter New Name of Course: ";
						cin >> new_name;
						cout << "Enter New Course code: ";
						cin >> new_courseCode;
						cout << "Enter New Credit hours: ";
						cin >> new_creditHour;
						manager.editCourse(_id, new_name, new_courseCode, new_creditHour);
					}
					if (option2 == 5)
					{
						string old_name, new_name;
						int new_duration, new_totalCreditHour;
						cout << "Enter Name of Program: ";
						cin >> old_name;
						cout << "Enter New Name of Program: ";
						cin >> new_name;
						cout << "Enter New Program duration: ";
						cin >> new_duration;
						cout << "Enter New Total Credit hours: ";
						cin >> new_totalCreditHour;
						manager.editProgram(old_name, new_name, new_duration, new_totalCreditHour);
					}
					if (option2 == 6)
					{
						int id;
						string new_statement;
						cout << "Enter Id of Question: ";
						cin >> id;
						cout << "Enter New Statement of Question: ";
						cin >> new_statement;
						manager.editQuestion(id, new_statement);
					}
					if (option2 == 7)
					{
						int new_totalMarks;
						float new_weightage;
						string name;
						cout << "Enter Name of Evaluation: ";
						cin >> name;
						cout << "Enter Updated total marks: ";
						cin >> new_totalMarks;
						cout << "Enter Updated weightage: ";
						cin >> new_weightage;
						manager.editEvaluation(name, new_totalMarks, new_weightage);
					}
				}
				if (option1 == 5)
				{

					cout << "1 for RemoveTopicFromCLO" << endl;
					cout << "2 for RemoveCLOFromPLO" << endl;
					cout << "3 for RemoveCLOFromCourse" << endl;
					cout << "4 for RemovePLOFromProgram" << endl;
					cout << "5 for RemoveCourseFromProgram" << endl;
					cout << "6 for RemoveQuestionFromEvaluation" << endl;

					cout << "Enter any option: ";
					cin >> option2;
					if (option2 == 1)
					{
						string name;
						int id;
						cout << "Enter Topic name: ";
						cin >> name;
						cout << "Enter CLO ID: ";
						cin >> id;
						manager.removeTopicFromCLO(id, name);
					}
					if (option2 == 2)
					{
						int CLO_id, PLO_id;
						cout << "Enter CLO ID: ";
						cin >> CLO_id;
						cout << "Enter PLO ID: ";
						cin >> PLO_id;
						manager.removeCLOFromPLO(CLO_id, PLO_id);
					}
					if (option2 == 3)
					{
						int CLO_id, Course_id;
						cout << "Enter CLO ID: ";
						cin >> CLO_id;
						cout << "Enter Course ID: ";
						cin >> Course_id;
						manager.removeCLOFromCourse(Course_id, CLO_id);
					}
					if (option2 == 4)
					{
						int PLO_id;
						string name;
						cout << "Enter PLO ID: ";
						cin >> PLO_id;
						cout << "Enter Program Name: ";
						cin >> name;
						manager.removePLOFromProgram(name, PLO_id);
					}
					if (option2 == 5)
					{
						int Course_id;
						string name;
						cout << "Enter Course ID: ";
						cin >> Course_id;
						cout << "Enter Program Name: ";
						cin >> name;
						manager.removeCourseFromProgram(name, Course_id);
					}
					if (option2 == 6)
					{
						int Question_id;
						string name;
						cout << "Enter Question ID: ";
						cin >> Question_id;
						cout << "Enter Evaluation Name: ";
						cin >> name;
						manager.removeQuestionFromEvaluation(Question_id, name);
					}
				}
				if (option1 == 6)
				{
					int PLO_id;
					string name;
					cout << "Enter PLO ID: ";
					cin >> PLO_id;
					cout << "Enter Program Name: ";
					cin >> name;
					manager.listOfRelevantCourses(name, PLO_id);
				}
				if (option1 == 7)
				{
					int Course_id;
					cout << "Enter Course ID: ";
					cin >> Course_id;
					if (manager.allCLOsTested(Course_id))
					{
						cout << "True" << endl;
					}
					else
					{
						cout << "False" << endl;
					}
				}
				if (option1 == 8)
				{
					system("CLS");
				}
			}
		}
	}
	return 0;
}