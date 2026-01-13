#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace std;

// Function for need an enum (enumeration) or a simple integer to track which screen the game is currently on.
enum Game_State {
	Menu_Screen,
	Easy_level,
	Medium_level,
	Hard_level,
	Results_Screen
};

//Structure created for MCQ's
struct MCQ {
	string Question_statement;
	string Options[4];
	int Correct_option;
};
MCQ* Active_Quiz = nullptr;
int Total_Questions = 30;
int CurrentQuestionIndex = 0;
int SCORE = 0;
bool is_Answered = false;
sf::Text Level_Header_Text;

MCQ Easy_Questions[30] = {

	{"Q1. What does the 'CPU' stands for?",{"Central Power Unit","Central Processing Unit","Computer Processing Unit","Control Processing Unit"}, 1},
	{"Q2. Which device is used to input text into the computer?",{"Monitor","Printer","Keyboard","Speaker"},2},
	{"Q3. What is the brain of computer called?",{"RAM","Hard Disk","CPU","Motherboard"},2},
	{"Q4. Which language is known as the mother of \n all programming languages?",{"Java","C","Python","C++"},1},
	{"Q5. Which symbol ends a statement in C++?",{":",".",",",";"},3},
	{"Q6. Which data type stores whole numbers in C++?",{"float","double","char","int"},3},
	{"Q7. C++ source file extension is: ",{".c",".cpp",".java",".txt"},1},
	{"Q8. Which keyword is used to display output in C++?",{"cin","print","cout","display"},2},
	{"Q9. What does RAM stands for? ",{"Read Access Memory","Random Access Memory","Rapid Access Memory","Run Access Memory"},1},
	{"Q10. C++ is a: ",{"Low-level language","Assembly Language","High-level Language","Machine Language"},2},
	{"Q11. What is 15 + 89",{"104","112","124","94"},0},
	{"Q12. Which device shows the output on Screen?",{"Mouse","Monitor","Keyboard","Keyboard"},1},
	{"Q13. What does WWW stands for? ",{"World Web Wide","World Wide Web","Web World Wide","Wide World Web"},1},
	{"Q14. Which key deletes text to the leftof cursor?",{"Delete","Enter","Backspace","Shift"},2},
	{"Q15. 'True' in C++ is represented as: ",{"0","-1","2","1"},3},
	{"Q16. Which operator is used for Addition?",{"-","*","/","+"},3},
	{"Q17. National Language of Pakistan is: ",{"English","Punjabi","Sindhi","Urdu"},3},
	{"Q18. Father of C++ is: ",{"Dennis Ritchie","James Gosling","Bjarne Stroustrup","Guido van Rossum"},2},
	{"Q19. How many bits in a byte?",{"4","6","8","16"},2},
	{"Q20. 'ICT' stands for?",{"Information Control Technology","Information Communication Technology","Internet Computer Technology","Internal Communication Tool"},1},
	{"Q21. Permanent Storage device is: ",{"RAM","Cache","Hard Disk","Register"},2},
	{"Q22. Shortcut key for copy is:",{"Ctrl+X","Ctrl+V","Ctrl+C","Ctrl+z"},2},
	{"Q23. Single-line comment symbol in C++?",{"/* */","#","//","%%"},2},
	{"Q24. Keyboard is a/an: ",{"Output device","Input Device","Storage Device","Processing Device"},1},
	{"Q25. 2,4,6,_?",{"7","9","8","10"},2},
	{"Q26. Loop that runs atleast once?",{"for","while","do-while","if"},2},
	{"Q27. Blue Planet is: ",{"Mars","Earth","Venus","Neptune"},1},
	{"Q28. 'OS' stands for: ",{"Operating System","Open Software","Optical System","Online Service"},0},
	{"Q29. 'IT' stands for: ",{"Internet Technology","Internal Tool","Intelligent Tech","Information Technology"},3},
	{"Q30. Is C++ case sensitive",{"Yes","No","Sometimes","Depends"},0}

};

MCQ Medium_Questions[30] = {

	{"Q1. A variable is: ",{"A contant value","A memory location","A function","A keyword"},1},
	{"Q2. Header file for input/output: ",{"<math.h>","<iostream>","<string>","<conio.h>"},1},
	{"Q3. Return type of main() is:",{"void","char","int","float"},2},
	{"Q4. Loop best when iterations are known: ",{"while","do-while","for","switch"},2},
	{"Q5. Output of 'cout << 10/2' ? ",{"2","4","5","10"},2},
	{"Q6. Compiler converts: ",{"Binary to source code","Source code to Machine code","Program to algorithm","Machine code to Binary code"},1},
	{"Q7. Comparison operator is: ",{"=","==","+=","!="},1},
	{"Q8. Size od int is usually: ",{"1 byte","2 bytes","4 bytes","8 bytes"},2},
	{"Q9. Algorithm is: ",{"Code","Program","Step-by-Step solution","Flowchart"},2},
	{"Q10. Debugging means: ",{"Writing Code","Finding Errors","Running Program","Designing UI"},1},
	{"Q11. Output of 'cout << 5%2' ?",{"1","2","3","0"},0},
	{"Q12. Keyword used to declare constant: ",{"var","final","const","static"},2},
	{"Q13. Pupose of 'break' statement?",{"End Program","Skip Iteration","Exit loop","Restart loop"},2},
	{"Q14. Data type for decimal values?",{"int","char","float","bool"},2},
	{"Q15. Flowchart is used for: ",{"Writing code","Debugging","Logic Representation","Memory Allocation"},2},
	{"Q16. Loop that checks condition first?",{"do-while","for","while","switch"},2},
	{"Q17. Output device is: ",{"Mouse","Keyboard","Printer","Scanner"},2},
	{"Q18. Logical AND operator is C++?",{"&","&&","||","!"},1},
	{"Q19. Result of '10>5 && 5>2' :",{"True","False","Error","0"},0},
	{"Q20. ASCII stands for: ",{"Automated Standard Code","Amercican System Control Index","Advanced System Code","American Standard Code for Information Interchange"},3},
	{"Q21. Temporary memory storage is: ",{"Hard Disk","ROM","RAM","Pen Drive"},2},
	{"Q22. Output of '(3+2)*2' is: ",{"7","10","12","8"},1},
	{"Q23. Syntax Error is detected by: ",{"User","Compiler","CPU","OS"},1},
	{"Q24. Logical OR operator is: ",{"&&","|","||","!"},2},
	{"Q25. Capital of Pakistan: ",{"Karachi","Lahore","Islamabad","Peshawar"},2},
	{"Q26. C++ was developed in: ",{"1972","1980","1983","1995"},2},
	{"Q27. Purpose of comments: ",{"Execute code","Debug program","Improve readability","Increase speed"},2},
	{"Q28. An array is:",{"Singlle value","Collection of Similar data","Function","Operator"},1},
	{"Q29. Increment Operator is: ",{"+","++","+=","--"},1},
	{"Q30. Output of 'int x=5;   cout <<x++; ' is: ",{"4","5","6","Error"},1}

};
MCQ Hard_Questions[30] = {

	{"Q1. Difference between 'x++' and '++x' is: ",{"No Difference","Post vs Pre Increment","Syntax Difference only","Both Wrong"},1},
	{"Q2. Output of: 'int x=5;   cout << ++x*2' is: ",{"10","11","12","14"},2},
	{"Q3. Logical Error means: ",{"Syntax mistake","Runtime crash","wrong output","Compiler Error"},2},
	{"Q4. Time Complexity describes: ",{"Memory use","Code Size","Execution Time","Syntax"},2},
	{"Q5. Output of: 'int a=10,b=3;  cout<<a/b; ' is: ",{"3.3","3","4","Error"},1},
	{"Q6. 'continue' ststement: ",{"Ends program","Ends loop","Skips Iteration","Repeats loop"},2},
	{"Q7. '=' VS '==' difference : ",{"Both comparison","Assignment VS Comparison","Both Assignment","No difference"},1},
	{"Q8. Nested loop means: ",{"Loop without body","Loop inside loop","Infinite loop","Conditional loop"},1},
	{"Q9. Loop Runs how many times: 'for(int i=1;i<=5;i++)': ",{"4","5","6","Infinite"},1},
	{"Q10. Output of 'cout << !(5>3)' is: ",{"1","True","0","Error"},2},
	{"Q11. Runtime Error occurs: ",{"Before Execution","During Execution","After Execution","While Compiling"},1},
	{"Q12. Output of 'int x=2;  x+=3;  cout << x;'is: ",{"2","3","5","6"},2},
	{"Q13. Function is: ",{"Variable","Loop","Block of code","Operator"},2},
	{"Q14. Recursion means: ",{"Loop","Function callingitself","Array processing","Pointer usage"},1},
	{"Q15. Output of: 'cout <<7%4;' is: ",{"1","2","3","4"},2},
	{"Q16. 'return'statement: ",{"Ends Program","Sends value back","Prints output","Calls Function"},1},
	{"Q17. Fastest Average solving Algorithm: ",{"Bubble sort","Selection sort","Quick Sort","Insertion sort"},2},
	{"Q18. Binary search works on: ",{"Random Data","Sorted data","Unsorted data","Linked list only"},1},
	{"Q19. Output of 'int a=1;  cout<< a++ + ++a' is: ",{"3","4","5","6"},2},
	{"Q20. Memory leak means: ",{"Extra Memory used","Memory not released","Syntax Error","Runtime crash"},1},
	{"Q21. 'while' VS 'do-while' :",{"Same","Condition after loop","Condition before loop","No condition"},2},
	{"Q22. Infinite loop is: ",{"Ends automatically","Never ends","Syntax Error","Logical error"},1},
	{"Q23. Pointer stores: ",{"Value","Address","Data type","Function"},1},
	{"Q24. Output of 'int x=5;  cout<<x--*2;' is: ",{"8","9","10","12"},2},
	{"Q25. Pupose of array: ",{"Store single value","Store multiple values","Store functions","Store Operators"},1},
	{"Q26. Reult of '(10>5) && (3>7)' is: ",{"True","False","1","Error"},1},
	{"Q27. LIFO data structure: ",{"Queue","Array","Atack","List"},2},
	{"Q28. Output of 'cout << sizeof(char);' is: ",{"1","2","4","8"},0},
	{"Q29. Compiler VS Interpreter: ",{"Line-by-Line VS whole","Whole VS Line-by-Line","Same","None"},1},
	{"Q30. Problem-Solving in programming is: ",{"Writing syntax","Logical Thinking","Debugging only","Memorizing code"},1}

};

void Save_Score(string Name, int player_score, string difficulty) {

	ofstream outFile("Game_scores.txt", ios::app);
	if (outFile.is_open()) {
		outFile << "Name : " << Name << "  |  Score : " << player_score << " / 30  |  Level : " << difficulty << endl;
		outFile.close();
	}
	else {
		cerr << "Unable to Open File for Saving" << endl;
	}
}

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Quiz Game");
	sf::Event e;
	sf::Texture BackgroundTexture;
	sf::Sprite BackGroundSprite;
	sf::Font GameFont;
	sf::Text GameTitle;
	sf::Text GameLabel1;
	sf::Text Level_Difficulty;
	sf::Text Question_text;

	sf::RectangleShape Easy_One;
	sf::Text Easy_Lvl_Txt;

	sf::RectangleShape Medium_One;
	sf::Text Medium_Lvl_Txt;

	sf::RectangleShape Hard_One;
	sf::Text Hard_Lvl_Txt;

	//Exit Button (Menu Screen)
	sf::RectangleShape Exit_Button;
	sf::Text Exit_txt;

	//Back Button (Easy, Medium, Hard)
	sf::RectangleShape Back_Button;
	sf::Text Back_txt;

	bool Input_status = false;
	string Select_Difficulty = "";

	// Declaration of Game Status Variable
	Game_State Current_State = Menu_Screen;

	//For File Handling
	sf::Text Scoreboard_Live;
	Scoreboard_Live.setFont(GameFont);
	Scoreboard_Live.setFillColor(sf::Color::Yellow);
	Scoreboard_Live.setPosition(600.0f, 20.0f);

	// For adding Background Image
	if (!BackgroundTexture.loadFromFile("C:/assets_quizgame/background.jpg")) {
		cerr << "Error: Could not Load Background Image File...." << endl;
		return -1;
	}
	BackGroundSprite.setTexture(BackgroundTexture);

	// For fitting background to game screen window
	sf::Vector2u WindowSize = window.getSize();
	sf::Vector2u TextureSize = BackgroundTexture.getSize();
	float X_scale = (float)WindowSize.x / TextureSize.x;
	float Y_scale = (float)WindowSize.y / TextureSize.y;
	BackGroundSprite.setScale(X_scale, Y_scale);

	sf::Text Final_Score_display;
	Final_Score_display.setFont(GameFont);
	Final_Score_display.setCharacterSize(40);
	Final_Score_display.setFillColor(sf::Color::Green);

	// For adding Game Font 
	if (!GameFont.loadFromFile("C:/assets_quizgame/Oswald-Regular.ttf")) {
		cerr << "Error: Could not Load Font File...." << endl;
		return -1;
	}

	// For adding game Title on main screen
	GameTitle.setString("Level Up Quiz");
	GameTitle.setFont(GameFont);
	GameTitle.setCharacterSize(50);
	GameTitle.setFillColor(sf::Color::White);
	GameTitle.setStyle(sf::Text::Bold);

	// For setting position of game title where it will be shown on screen...
	float Text_Center_X = window.getSize().x / 2.0f;
	GameTitle.setOrigin(GameTitle.getLocalBounds().left + GameTitle.getLocalBounds().width / 2.0f, GameTitle.getLocalBounds().top);
	GameTitle.setPosition(Text_Center_X, 50.0f);

	// For adding player name title....
	GameLabel1.setFont(GameFont);
	GameLabel1.setString("Player Name : ");
	GameLabel1.setCharacterSize(35);
	GameLabel1.setFillColor(sf::Color::White);
	GameLabel1.setOrigin(GameLabel1.getLocalBounds().left + GameLabel1.getLocalBounds().width / 2.0f, GameLabel1.getLocalBounds().top);
	GameLabel1.setPosition(Text_Center_X, 150.0f);

	// For Rectangle Box.....
	sf::RectangleShape InputVal(sf::Vector2f(400.0f, 50.0f));
	InputVal.setFillColor(sf::Color::Transparent);
	InputVal.setOutlineColor(sf::Color::White);
	InputVal.setOutlineThickness(2.0f);

	//Setting Rectangle Box position
	InputVal.setOrigin(InputVal.getLocalBounds().width / 2.0f, InputVal.getLocalBounds().height / 2.0f);
	InputVal.setPosition(Text_Center_X, 220.0f);

	// For setting of player name entered in box
	sf::Text Player_Name;
	Player_Name.setFont(GameFont);
	Player_Name.setString(" ");
	Player_Name.setCharacterSize(30);
	Player_Name.setFillColor(sf::Color::White);
	Player_Name.setPosition(InputVal.getPosition().x - InputVal.getSize().x / 2.0f + 10.0f, InputVal.getPosition().y - InputVal.getSize().y / 2.0f + 5.0f);
	string Current_Name = "";

	// For adding Level Difficulty Section....
	Level_Difficulty.setFont(GameFont);
	Level_Difficulty.setString("Select Level Type:");
	Level_Difficulty.setCharacterSize(35);
	Level_Difficulty.setFillColor(sf::Color::White);
	Level_Difficulty.setOrigin(Level_Difficulty.getLocalBounds().left + Level_Difficulty.getLocalBounds().width / 2.0f, Level_Difficulty.getLocalBounds().top);
	Level_Difficulty.setPosition(Text_Center_X, 350.0f);

	Question_text.setFont(GameFont);
	Question_text.setCharacterSize(27);
	Question_text.setFillColor(sf::Color::White);
	Question_text.setStyle(sf::Text::Bold);
	Question_text.setPosition(70.0f, 100.0f);

	// For setting Level Difficulty Buttons setup....
	sf::Vector2f Button_Size(120.0f, 50.0f);
	float Start_Y = 430.0f;
	float Spacing = 50.0f;

	float total_width = (Button_Size.x * 3) + (Spacing * 2);
	float Start_X = Text_Center_X - (total_width / 2.0f);

	//---------EASY BUTTON SETUP-----------
	Easy_One.setSize(Button_Size);
	Easy_One.setFillColor(sf::Color::Transparent);
	Easy_One.setOutlineColor(sf::Color::Green);
	Easy_One.setOutlineThickness(2.0f);
	Easy_One.setPosition(Start_X, Start_Y);

	Easy_Lvl_Txt.setFont(GameFont);
	Easy_Lvl_Txt.setString("Easy");
	Easy_Lvl_Txt.setCharacterSize(25);
	Easy_Lvl_Txt.setFillColor(sf::Color::Magenta);

	Easy_Lvl_Txt.setOrigin(Easy_Lvl_Txt.getLocalBounds().left + Easy_Lvl_Txt.getLocalBounds().width / 2.0f, Easy_Lvl_Txt.getLocalBounds().top + Easy_Lvl_Txt.getLocalBounds().height / 2.0f);
	Easy_Lvl_Txt.setPosition(Easy_One.getPosition().x + (Button_Size.x / 2.0f), Easy_One.getPosition().y + (Button_Size.y / 2.0f));

	//---------MEDIUM BUTTON SETUP-----------
	Medium_One.setSize(Button_Size);
	Medium_One.setFillColor(sf::Color::Transparent);
	Medium_One.setOutlineColor(sf::Color::Green);
	Medium_One.setOutlineThickness(2.0f);
	Medium_One.setPosition(Start_X + Button_Size.x + Spacing, Start_Y);

	Medium_Lvl_Txt.setFont(GameFont);
	Medium_Lvl_Txt.setString("Medium");
	Medium_Lvl_Txt.setCharacterSize(25);
	Medium_Lvl_Txt.setFillColor(sf::Color::Magenta);

	Medium_Lvl_Txt.setOrigin(Medium_Lvl_Txt.getLocalBounds().left + Medium_Lvl_Txt.getLocalBounds().width / 2.0f, Medium_Lvl_Txt.getLocalBounds().top + Medium_Lvl_Txt.getLocalBounds().height / 2.0f);
	Medium_Lvl_Txt.setPosition(Medium_One.getPosition().x + (Button_Size.x / 2.0f), Medium_One.getPosition().y + (Button_Size.y / 2.0f));

	//---------HARD BUTTON SETUP-----------
	Hard_One.setSize(Button_Size);
	Hard_One.setFillColor(sf::Color::Transparent);
	Hard_One.setOutlineColor(sf::Color::Green);
	Hard_One.setOutlineThickness(2.0f);
	Hard_One.setPosition(Start_X + (Button_Size.x * 2) + (Spacing * 2), Start_Y);

	Hard_Lvl_Txt.setFont(GameFont);
	Hard_Lvl_Txt.setString("Hard");
	Hard_Lvl_Txt.setCharacterSize(25);
	Hard_Lvl_Txt.setFillColor(sf::Color::Magenta);

	Hard_Lvl_Txt.setOrigin(Hard_Lvl_Txt.getLocalBounds().left + Hard_Lvl_Txt.getLocalBounds().width / 2.0f, Hard_Lvl_Txt.getLocalBounds().top + Hard_Lvl_Txt.getLocalBounds().height / 2.0f);
	Hard_Lvl_Txt.setPosition(Hard_One.getPosition().x + (Button_Size.x / 2.0f), Hard_One.getPosition().y + (Button_Size.y / 2.0f));

	// Exit Button on Menu Screen
	Exit_Button.setSize(sf::Vector2f(100.0f, 40.0f));
	Exit_Button.setFillColor(sf::Color::Transparent);
	Exit_Button.setOutlineColor(sf::Color::Green);
	Exit_Button.setOutlineThickness(2.0f);
	Exit_Button.setOrigin(Exit_Button.getLocalBounds().width / 2.0f, Exit_Button.getLocalBounds().height / 2.0f);
	Exit_Button.setPosition(Text_Center_X, 600.0f);

	Exit_txt.setFont(GameFont);
	Exit_txt.setString(" Exit! ");
	Exit_txt.setCharacterSize(25);
	Exit_txt.setFillColor(sf::Color::White);

	Exit_txt.setOrigin(Exit_txt.getLocalBounds().left + Exit_txt.getLocalBounds().width / 2.0f,
		Exit_txt.getLocalBounds().top + Exit_txt.getLocalBounds().height / 2.0f);
	Exit_txt.setPosition(Exit_Button.getPosition());


	//Back Button in Easy, Medium and Hard Level
	Back_Button.setSize(sf::Vector2f(80.0f, 35.0f));
	Back_Button.setFillColor(sf::Color::Transparent);
	Back_Button.setOutlineColor(sf::Color::White);
	Back_Button.setOutlineThickness(1.0f);
	Back_Button.setPosition(20.0f, 20.0f);

	Back_txt.setFont(GameFont);
	Back_txt.setString("Back? ");
	Back_txt.setCharacterSize(20);
	Back_txt.setFillColor(sf::Color::White);
	Back_txt.setPosition(30.0f, 25.0f);


	// Four Option Boxes
	sf::RectangleShape option_boxes[4];
	sf::Text option_text[4];

	for (int i = 0; i < 4; i++) {

		option_boxes[i].setSize(sf::Vector2f(500.0f, 50.0f));
		option_boxes[i].setOutlineThickness(2.0f);
		option_boxes[i].setOutlineColor(sf::Color::White);
		option_boxes[i].setFillColor(sf::Color::Transparent);
		option_boxes[i].setOrigin(250.0f, 25.0f);

		option_boxes[i].setPosition(400.0f, 250.0f + (i * 70.0f));

		option_text[i].setFont(GameFont);
		option_text[i].setCharacterSize(20);
		option_text[i].setFillColor(sf::Color::White);

	}

	//Result Feedback box
	sf::RectangleShape Result_box(sf::Vector2f(500.0f, 60.0f));
	Result_box.setOrigin(250.0f, 30.0f);
	Result_box.setPosition(Text_Center_X, 550.0f);
	Result_box.setFillColor(sf::Color(sf::Color::Transparent));

	sf::Text Result_DisplayText;
	Result_DisplayText.setFont(GameFont);
	Result_DisplayText.setCharacterSize(22);

	//Next button for getting to next question
	sf::RectangleShape Next_button(sf::Vector2f(100.f, 40.0f));
	Next_button.setFillColor(sf::Color::Transparent);
	Next_button.setPosition(650.0f, 620.0f);

	sf::Text Next_text;
	Next_text.setFont(GameFont);
	Next_text.setString("Next");
	Next_text.setCharacterSize(18);
	Next_text.setPosition(Next_button.getPosition().x + 25, Next_button.getPosition().y + 8);


	// For showing the game window screen.....is a main loop for running game
	while (window.isOpen()) {

		while (window.pollEvent(e)) {
			//Handle Events (e.g., closing the window, input)
			if (e.type == sf::Event::Closed) {
				window.close();
			}
			// For Mouse Click Function
			if (e.type == sf::Event::MouseButtonPressed) {
				if (e.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i Mouse_Pos = sf::Mouse::getPosition(window);
					sf::Vector2f Mouse_Pos_f = window.mapPixelToCoords(Mouse_Pos);

					Easy_One.setOutlineColor(sf::Color::White);
					Medium_One.setOutlineColor(sf::Color::White);
					Hard_One.setOutlineColor(sf::Color::White);
					Exit_Button.setOutlineColor(sf::Color::White);
					Back_Button.setOutlineColor(sf::Color::White);


					if (InputVal.getGlobalBounds().contains((float)Mouse_Pos.x, (float)Mouse_Pos.y)) {
						Input_status = true;
						InputVal.setOutlineColor(sf::Color::Green);           //Color of player Name box if name is entered 

					}
					else {
						Input_status = false;
						InputVal.setOutlineColor(sf::Color::Red);             //Color of Player Name box if name is entered

					}
					if (Current_State == Menu_Screen) {
						if (Exit_Button.getGlobalBounds().contains((float)Mouse_Pos.x, (float)Mouse_Pos.y)) {

							window.close();
						}
						if (!Current_Name.empty()) {
							if (Easy_One.getGlobalBounds().contains(Mouse_Pos_f)) {
								Active_Quiz = Easy_Questions;
								Current_State = Easy_level;
								CurrentQuestionIndex = 0;
								SCORE = 0;
							}
							else if (Medium_One.getGlobalBounds().contains(Mouse_Pos_f)) {
								Active_Quiz = Medium_Questions;
								Current_State = Medium_level;
								CurrentQuestionIndex = 0;
								SCORE = 0;
							}
							else if (Hard_One.getGlobalBounds().contains(Mouse_Pos_f)) {
								Active_Quiz = Hard_Questions;
								Current_State = Hard_level;
								CurrentQuestionIndex = 0;
								SCORE = 0;
							}
						}
					}
					else if (Current_State == Easy_level || Current_State == Medium_level || Current_State == Hard_level) {

						if (Back_Button.getGlobalBounds().contains(Mouse_Pos_f)) {

							Current_State = Menu_Screen;
							continue;
						}
						if (is_Answered && Next_button.getGlobalBounds().contains(Mouse_Pos_f)) {
							if (CurrentQuestionIndex < 29) {
								CurrentQuestionIndex++;
								is_Answered = false;
								for (int i = 0; i < 4; i++) {
									option_boxes[i].setOutlineColor(sf::Color::White);
								}
							}
							else {

								string Differ_string = (Current_State == Easy_level) ? "Easy" : (Current_State == Medium_level) ? "Medium" : "Hard";
								Save_Score(Current_Name, SCORE, Differ_string);

								Final_Score_display.setString("QUIZ OVER!!\n\nPlayer: " + Current_Name + "\nFinal Score: " + to_string(SCORE) + " / 30" + "\n\nResults saved to file.");

								sf::FloatRect text_rect = Final_Score_display.getLocalBounds();
								Final_Score_display.setOrigin(text_rect.left + text_rect.width / 2.0f, text_rect.top + text_rect.height / 2.0f);
								Final_Score_display.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

								Current_State = Results_Screen;
							}
						}
						if (!is_Answered) {

							Question_text.setString(Active_Quiz[CurrentQuestionIndex].Question_statement);
							window.draw(Question_text);
							for (int i = 0; i < 4; i++) {
								if (option_boxes[i].getGlobalBounds().contains(Mouse_Pos_f)) {
									is_Answered = true;
									int Correct = Active_Quiz[CurrentQuestionIndex].Correct_option;

									if (i == Correct) {
										option_boxes[i].setOutlineColor(sf::Color::Green);
										Result_DisplayText.setString("Correct!! Now move to Next Question..");
										SCORE++;
										Scoreboard_Live.setString("Player: " + Current_Name + "\n Score: " + to_string(SCORE));
										window.draw(Scoreboard_Live);
									}
									else {
										option_boxes[i].setOutlineColor(sf::Color::Red);
										option_boxes[Correct].setOutlineColor(sf::Color::Green);
										Result_DisplayText.setString("Wrong!? The Green one was correct..");
									}
								}
							}
						}
					}
					else if (Current_State == Results_Screen) {
						sf::Text Final_Score;
						Final_Score.setFont(GameFont);
						Final_Score.setString("QUIZ OVER !! \n\n Player : " + Current_Name + "\nFinal Score : " + to_string(SCORE) + " / 30 " + "\n\nResults saved...");
						Final_Score.setCharacterSize(30);
						Final_Score.setFillColor(sf::Color::Green);

						sf::FloatRect text_rect = Final_Score.getLocalBounds();
						Final_Score.setOrigin(text_rect.left + text_rect.width / 2.0f, text_rect.top + text_rect.height / 2.0f);
						Final_Score.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
						window.draw(Final_Score);
					}
				}
			}

			// For Keyboard BACKSPACE key operation
			if (Input_status && e.type == sf::Event::TextEntered) {
				if (e.text.unicode == 8) {                          // 8 is ASCII value for BACKSPACE
					if (!Current_Name.empty()) {
						Current_Name.pop_back();
					}
				}
				else if (e.text.unicode < 128 && Current_Name.length() < 20) {           // Character limit set for 20 for player name

					if (e.text.unicode != 13 && e.text.unicode != 9) {
						Current_Name += static_cast<char>(e.text.unicode);
					}
				}
				Player_Name.setString(Current_Name);
			}
		}
		// Clear the window
		window.clear(sf::Color::Black);
		window.draw(BackGroundSprite);
		window.draw(GameTitle);

		//Event Handling
		if (Current_State == Menu_Screen) {

			window.draw(GameLabel1);
			window.draw(InputVal);
			window.draw(Player_Name);

			window.draw(Level_Difficulty);
			window.draw(Easy_One);
			window.draw(Easy_Lvl_Txt);
			window.draw(Medium_One);
			window.draw(Medium_Lvl_Txt);
			window.draw(Hard_One);
			window.draw(Hard_Lvl_Txt);

			window.draw(Exit_Button);
			window.draw(Exit_txt);

		}
		//Easy, Medium, Hard Game Screen...
		else if (Current_State == Easy_level) {

			window.draw(Back_Button);
			window.draw(Back_txt);

			Question_text.setString(Easy_Questions[CurrentQuestionIndex].Question_statement);
			window.draw(Question_text);

			for (int i = 0; i < 4; i++) {
				option_text[i].setString(Easy_Questions[CurrentQuestionIndex].Options[i]);
				option_text[i].setPosition(option_boxes[i].getPosition().x - 230, option_boxes[i].getPosition().y - 12);

				window.draw(option_boxes[i]);
				window.draw(option_text[i]);
			}

			if (is_Answered) {

				window.draw(Result_box);
				window.draw(Result_DisplayText);

				Result_DisplayText.setPosition(Result_box.getPosition().x - 100, Result_box.getPosition().y - 15);

				window.draw(Next_button);
				window.draw(Next_text);

			}

		}
		//Medium Game Screen...
		else if (Current_State == Medium_level) {

			window.draw(Back_Button);
			window.draw(Back_txt);

			Question_text.setString(Medium_Questions[CurrentQuestionIndex].Question_statement);
			window.draw(Question_text);

			for (int i = 0; i < 4; i++) {
				option_text[i].setString(Medium_Questions[CurrentQuestionIndex].Options[i]);
				option_text[i].setPosition(option_boxes[i].getPosition().x - 230, option_boxes[i].getPosition().y - 12);

				window.draw(option_boxes[i]);
				window.draw(option_text[i]);
			}

			if (is_Answered) {

				window.draw(Result_box);
				window.draw(Result_DisplayText);

				Result_DisplayText.setPosition(Result_box.getPosition().x - 100, Result_box.getPosition().y - 15);

				window.draw(Next_button);
				window.draw(Next_text);
			}

		}
		//Hard Game Screen...
		else if (Current_State == Hard_level) {

			window.draw(Back_Button);
			window.draw(Back_txt);

			Question_text.setString(Hard_Questions[CurrentQuestionIndex].Question_statement);
			window.draw(Question_text);

			for (int i = 0; i < 4; i++) {
				option_text[i].setString(Hard_Questions[CurrentQuestionIndex].Options[i]);
				option_text[i].setPosition(option_boxes[i].getPosition().x - 230, option_boxes[i].getPosition().y - 12);

				window.draw(option_boxes[i]);
				window.draw(option_text[i]);
			}

			if (is_Answered) {

				window.draw(Result_box);
				window.draw(Result_DisplayText);

				Result_DisplayText.setPosition(Result_box.getPosition().x - 100, Result_box.getPosition().y - 15);

				window.draw(Next_button);
				window.draw(Next_text);

			}
		}
		else if (Current_State == Results_Screen) {
			window.draw(Final_Score_display);
		}

		// Display the window contents
		window.display();
	}
	return 0;
}
