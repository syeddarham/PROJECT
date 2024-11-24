#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define DEFAULT "\033[39m"
#define LIGHT_GRAY "\033[90m"
#define LIGHT_RED "\033[91m"
#define LIGHT_GREEN "\033[92m"
#define LIGHT_YELLOW "\033[93m"
#define LIGHT_BLUE "\033[94m"
#define LIGHT_MAGENTA "\033[95m"
#define LIGHT_CYAN "\033[96m"
#define LIGHT_WHITE "\033[97m"
#define RESET "\033[0m"


int main()
{
	int n;
	do
	{
		system("cls");
		printf(LIGHT_CYAN);
		printf(GREEN "============================================" RED "Welcome to Quiz Games" GREEN "=======================================================\n" LIGHT_RED);
		printf("Press\n" WHITE);
		printf(" '1' for Maths Quiz\n '2' for General Knowledge Quiz \n '3' for English Quiz\n '4' for Physics Quiz\n '0' to exit\n  =  ");
		scanf("%d", &n);
		printf(RESET);
		system("cls");
		if (n == 1)
		{
			printf(LIGHT_CYAN);
			math();
			printf(RESET);
		}
		else if (n == 2)
		{
			printf(LIGHT_CYAN);
			GK();
			printf(RESET);
		}
		else if (n == 3)
		{
			printf(LIGHT_CYAN);
			Eng();
			printf(RESET);
		}
		else if (n == 4)
		{
			printf(LIGHT_CYAN);
			Physics();
			printf(RESET);
		}
		else
		{
			if (n == 0)
			{
				break;
			}
			else
			{
				printf("Please Enter valid Input(1,2,3,4 or 0 to exit)\n\n");
			}
		}
	} while (n != 0);
	printf("Thank you for Playing, Come back soon Please");
	printf("\n\n");
}

void math()
{
	int score = 0;
	int p;
	int wrong = 0;
	int correct = 0;
	printf(GREEN "============================================" RED "Maths Quiz Starts!" GREEN "==========================================================\n" RED);

	printf("Instruction:\n" WHITE);
	printf(" 1)Each Question = 4 marks\n 2)For each wrong answer your score will be deducted by 1\n 3)50 percent score for passing the quiz\n\n\n" LIGHT_CYAN);
	printf("Q1 : x^2-8x+15=0\n");
	printf(" 1)(x-3)(x+5)\n 2)(x+3)(x-5)\n 3)(x-3)(x-5)\n 4)(x+3)(x+5)\n\n");
	scanf("%d", &p);
	if (p == 3)
	{
		score += 4;
		correct += 1;

		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q2 : x^2-6x+8=0\n\n");
	printf(" 1)(x-2)(x-4)\n 2)(x+2)(x-4)\n 3)(x-2)(x+4)\n 4)(x+2)(x+4)\n\n");
	scanf("%d", &p);
	if (p == 1)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q3 : cube root of unity\n");
	printf(" 1)1\n 2)5\n 3)6\n 4)7\n");
	scanf("%d", &p);
	if (p == 1)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q4 : What is the slope of the line passing through the points (2,3) and (5,11)? \n");
	printf(" 1)8/3\n 2)7/3\n 3)8/5\n 4)9/4\n");
	scanf("%d", &p);
	if (p == 1)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q5 : What is the value of x in the equation 3(x-2)+4=10 \n");
	printf(" 1)x=6\n 2)x=8\n 3)x=5\n 4)x=4\n");
	scanf("%d", &p);
	if (p == 4)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q6 : (9+9)+8*10/2\n");
	printf(" 1)98\n 2)58\n 3)48\n 4)none\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q7 : x^2-5x+6\n");
	printf(" 1)(x+2)(x-3)\n 2)(x-2)(x+3)\n 3)(x-2)(x-3)\n 4)(x+2)(x+3)\n");
	scanf("%d", &p);
	if (p == 3)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}

	printf("Q8 : If g(x) = 2x - 7, find g(-3)\n");
	printf(" 1)13\n 2)-13\n 3)-15\n 4)14\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q9 : What is the value of (3/4) + (1/2)?\n\n");
	printf(" 1)5/3\n 2)5/4\n 3)5/2\n 4)7/4\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q10 : Solve for y in the equation: 4y + 2 = 18\n\n");
	printf(" 1)y=4\n 2)y=3\n 3)y=1\n 4)y=5\n");
	scanf("%d", &p);
	if (p == 1)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf("wrong Answer!\n\n");
	}
	if (score >= 20)
	{
		printf(GREEN "Congratulations you 've passed\n\n" RESET);
	}
	else
	{
		printf(RED "Sorry, You didn't passed\n\n\n" RESET);
	}
	printf("Score = %d\n\n", score);
	printf("Wrong Answers = %d\n\n", wrong);
	printf("Correct Answers = %d\n\n", correct);
	printf(RESET);
	system("pause");
	system("cls");
	printf("\n\n");
}

void GK()
{
	int score = 0;
	int p;
	int wrong = 0;
	int correct = 0;
	printf(GREEN "========================================" RED "General Knowledge Quiz Starts!" GREEN "===================================================\n" LIGHT_RED);

	printf("Instruction:\n" WHITE);
	printf(" 1)Each Question = 4 marks\n 2)For each wrong answer your score will be deducted by 1\n 3)50 percent score for passing the quiz\n\n\n" LIGHT_CYAN);
	printf("Q1 : What is the only country that is also a continent?\n");
	printf(" 1)Australia\n 2)New Zealand\n 3)Africa\n 4)Japan\n\n");
	scanf("%d", &p);
	if (p == 1)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q2 : Army Cheif of Pakistan\n");
	printf(" 1)Imran Khan\n 2)Nawaz Sharif\n 3)Gen Asim Munir\n 4)none\n");
	scanf("%d", &p);
	if (p == 3)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q3 : Which planet in our solar system is known for its rings?\n");
	printf(" 1)Saturn\n 2)Jupiter\n 3)Mars\n 4)Venus\n");
	scanf("%d", &p);
	if (p == 1)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q4 : What is the most spoken language in the world? \n");
	printf(" 1)English\n 2)China\n 3)Urdu\n 4)Siraiki\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q5 : Which mathematician is known for the Fundamental Theorem of Algebra?\n");
	printf(" 1)Pythagoras\n 2)Albert Einstein\n 3)Carl Friedrich Gauss\n 4)none\n");
	scanf("%d", &p);
	if (p == 3)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q6 : What is the rarest blood type in humans?\n");
	printf(" 1)AB+\n 2)AB-\n 3)O+\n 4)O-\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q7 : Which ancient city was known for its hanging gardens, one of the Seven Wonders of the Ancient World?\n");
	printf(" 1)Babylon\n 2)Tehran\n 3)Cairo\n 4)Paris\n");
	scanf("%d", &p);
	if (p == 1)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}

	printf("Q8 : Which ancient civilization is known for creating a written language called cuneiform?\n");
	printf(" 1)Akaidians\n 2)Sumerian\n 3)Mesopotamia\n 4)Egypt\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q9 : What is the largest ocean on Earth?\n\n");
	printf(" 1)Pacific Ocean\n 2)Indian Ocean\n 3)Atlantic Ocean\n 4)Artic Ocean\n");
	scanf("%d", &p);
	if (p == 1)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q10 : Longest River in the world?\n\n");
	printf(" 1)Amazon River\n 2)Nile River\n 3)Mississippi River\n 4)Yangtze River\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	if (score >= 20)
	{
		printf(GREEN "Congratulations you 've passed\n\n" RESET);
	}
	else
	{
		printf(RED "Sorry, You didn't passed\n\n\n" RESET);
	}
	printf("Score = %d\n\n", score);
	printf("Wrong Answers = %d\n\n", wrong);
	printf("Correct Answers = %d\n\n", correct);
	printf(RESET);
	system("pause");
	system("cls");
	printf("\n\n");
}

void Eng()
{
	int score = 0;
	int p;
	int wrong = 0;
	int correct = 0;
	printf(GREEN "============================================" RED "English Quiz Starts!" GREEN "========================================================\n" LIGHT_RED);

	printf("Instruction:\n" WHITE);
	printf(" 1)Each Question = 4 marks\n 2)For each wrong answer your score will be deducted by 1\n 3)50 percent score for passing the quiz\n\n\n" LIGHT_CYAN);
	printf("Q1 : What is the meaning of the word ubiquitous?\n");
	printf(" 1)Rare\n 2)Existing everywhere\n 3)Uncertain\n 4)Difficult to find\n\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q2 : Identify the sentence with the correct use of the subjunctive mood\n");
	printf(" 1)If she was here, we would start.\n 2)I wish he were more responsible.\n 3)If he is happy, I am happy\n 4)She acts as if she is the boss\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q3 : Which of the following sentences uses an ellipsis correctly?\n");
	printf(" 1)I was thinking... maybe we should go.\n 2)She said she would come but... she didn’t\n 3) I want to go... to the store\n 4)All of the above.\n");
	scanf("%d", &p);
	if (p == 4)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q4 : What is the term for a figure of speech in which apparently contradictory terms appear in conjunction? \n");
	printf(" 1)Hyperbole\n 2)Oxymoron\n 3)Paradox\n 4)Metaphor\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q5 : Choose the sentence that demonstrates parallel structure\n");
	printf(" 1)She likes reading, writing, and to jog.\n 2)He enjoys swimming, biking, and running.\n 3)They are excited to travel, exploring new places, and to learn.\n 4)I prefer tea, coffee, and to drink soda.\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q6 : Which of the following words is a homophone for to ?\n");
	printf(" 1)Too\n 2)Two\n 3)Both a and b\n 4)None of the above\n");
	scanf("%d", &p);
	if (p == 3)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q7 : What is the correct form of the adjective in this sentence: She is the ____ student in the class\n");
	printf(" 1)More intelligent\n 2)Most intelligent\n 3)Intelligentest\n 4)Intelligence\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}

	printf("Q8 : In which of the following sentences is the word 'however' used incorrectly?\n");
	printf(" 1)I wanted to go; however, I had to work.\n 2)The movie was good; however it was too long\n 3)I love chocolate; however, I try to limit my intake.\n 4)She is talented; however, she needs more practice.\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q9 : What is the meaning of the idiom 'to let the cat out of the bag'?\n\n");
	printf(" 1)To reveal a secret\n 2)To be careless\n 3)To cause trouble\n 4)To get lost\n");
	scanf("%d", &p);
	if (p == 1)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q10 : Which of the following sentences contains a dangling modifier?\n\n");
	printf(" 1)After reading the book, the movie was disappointing\n 2)Running quickly, the finish line was finally in sight\n 3)To improve his health, exercise is essential.\n 4)All of the above\n");
	scanf("%d", &p);
	if (p == 4)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	if (score >= 20)
	{
		printf(GREEN "Congratulations you 've passed\n\n" RESET);
	}
	else
	{
		printf(RED "Sorry, You didn't passed\n\n\n" RESET);
	}
	printf("Score = %d\n\n", score);
	printf("Wrong Answers = %d\n\n", wrong);
	printf("Correct Answers = %d\n\n", correct);
	printf(RESET);
	system("pause");
	system("cls");
	printf("\n\n");
}

void Physics()
{
	int score = 0;
	int p;
	int wrong = 0;
	int correct = 0;
	printf(GREEN "============================================" RED "Physics Quiz Starts!" GREEN "========================================================\n" LIGHT_RED);

	printf("Instruction:\n" WHITE);
	printf(" 1)Each Question = 4 marks\n 2)For each wrong answer your score will be deducted by 1\n 3)50 percent score for passing the quiz\n\n\n" LIGHT_CYAN);
	printf("Q1 : What is the unit of force in the International System of Units (SI)?\n");
	printf(" 1)Joule\n 2)Newton\n 3)Pascal\n 4)Watt\n\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q2 : What is the principle behind a hydraulic lift?\n");
	printf(" 1)Conservation of energy\n 2)Pascal's principle\n 3)Bernoulli's principle\n 4)Archimedes' principle\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q3 : Which of the following statements about Newton's Third Law of Motion is true?\n");
	printf(" 1)An object at rest will stay at rest unless acted upon\n 2)For every action, there is an equal and opposite reaction.\n 3)Force is equal to mass times acceleration\n 4)Energy cannot be created or destroyed\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
		;
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q4 : Which of the following is a scalar quantity? \n");
	printf(" 1)Velocity\n 2)Force\n 3)Acceleration\n 4)Mass\n");
	scanf("%d", &p);
	if (p == 4)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q5 : What is the frequency of a wave with a wavelength of 2 meters traveling at a speed of 340 m/s?\n");
	printf(" 1)170 Hz\n 2)340 Hz\n 3)1700 Hz\n 4)680 Hz\n");
	scanf("%d", &p);
	if (p == 1)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q6 : Which law states that the total energy of an isolated system remains constant?\n");
	printf(" 1)Newton's first law\n 2)Law of conservation of mass\n 3)Law of conservation of energy\n 4)Hooke's law\n");
	scanf("%d", &p);
	if (p == 3)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q7 : What is the approximate value of gravitational acceleration on Earth's surface?\n");
	printf(" 1)9.81^-2\n 2)6.81^-2\n 3)9.8^-2\n 4)9.89^-2\n");
	scanf("%d", &p);
	if (p == 1)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
		;
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}

	printf("Q8 : Which phenomenon explains why a pencil appears broken when placed in water?\n");
	printf(" 1)Reflection\n 2)Refraction\n 3)Diffraction\n 4)Dispersion\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q9 : What is the main function of a transformer?\n\n");
	printf(" 1)To store energy\n 2)To convert AC to DC\n 3)To change the voltage level of alternating current\n 4)To amplify sound\n");
	scanf("%d", &p);
	if (p == 3)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	printf("Q10 : Which particle is considered to have no electric charge?\n\n");
	printf(" 1)Proton\n 2)Neutron\n 3)Electron\n 4)Positron\n");
	scanf("%d", &p);
	if (p == 2)
	{
		score += 4;
		correct += 1;
		printf(GREEN "Correct Answer!\n\n" LIGHT_CYAN);
	}
	else
	{
		score += -1;
		wrong += 1;
		printf(RED "wrong Answer!\n\n" LIGHT_CYAN);
	}
	if (score >= 20)
	{
		printf(GREEN "Congratulations you 've passed\n\n" RESET);
	}
	else
	{
		printf(RED "Sorry, You didn't passed\n\n\n" RESET);
	}
	printf("Score = %d\n\n", score);
	printf("Wrong Answers = %d\n\n", wrong);
	printf("Correct Answers = %d\n\n", correct);
	printf(RESET);
	system("pause");
	system("cls");
	printf("\n\n");

	printf("\n\n");
}
