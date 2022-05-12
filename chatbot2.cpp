// terminal : run them
// g++ chatbot.cpp -o chatbot
// ./chatbot


#include<bits/stdc++.h>
using namespace std;

void greet(string bot, string me){
	cout<<"Hello! My name is "<<bot;
    cout<<"I just got created by "<<me<<endl;
}

void remind_name(){

    cout<<"Please, remind me your name : ";
    string name;
	cin>>name;
    cout<<"What a great name you have, "<<name<<"!"<<endl;
    cout<<"Nice to meet you..."<<endl;
}

void guess_age(){
	cout<<"Let me guess your age..."<<endl;
	cout<<"Enter remainders after dividing your age by 3, 5 and 7 : "<<endl;
	int rem3, rem5, rem7;
	cin>>rem3>>rem5>>rem7;
	int age = (rem3 * 70 + rem5 * 21 + rem7 * 15) % 105;

	cout<<"Your age is "<<age<<". Its a good time to start programming"<<endl;
}

void count(){
	cout<<"Now I will prove to you that I can count to any number you want : ";
	int num;
	cin>>num;
	int counter = 0;
	while(counter <= num){
		cout<<counter<<endl;
		counter++;
	}
}

void test(){

	cout<<"Let's test your AI knowledge."<<endl;
	cout<<"Who is the father of Artificial Intelligence?"<<endl;
	cout<<"1. Alan Turing"<<endl;
	cout<<"2. John McCarthy"<<endl;
	cout<<"3. Bill Gates"<<endl;
	cout<<"4. Tony Stark"<<endl;
	int ans = 2;
	int guess;
	cin>>guess;
	while(guess != ans){
		cout<<"Please, try again..."<<endl;
		cin>>guess;
	}
	cout<<"Congrats, Its a correct answer!"<<endl;
	cout<<"................................."<<endl;
	cout<<"................................."<<endl;
}

void end(){
	cout<<"Thank You..."<<endl;
}

int main(){

	greet("Chitti", "Nitish Chintakindi");
	remind_name();
	guess_age();
	count();
	test();
	end();

	return 0;
}