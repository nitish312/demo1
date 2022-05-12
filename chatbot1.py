def greet(bot_name, me):
    print("Hello! My name is {0}.".format(bot_name))
    print("I just got created by {0}.".format(me))


def remind_name():
    print('Please, remind me your name.')
    name = input()
    print("What a great name you have, {0}!".format(name))
    print("Nice to meet you...")


def guess_age():
    print('Let me guess your age.')
    print('Enter remainders of dividing your age by 3, 5 and 7.')

    rem3 = int(input())
    rem5 = int(input())
    rem7 = int(input())
    age = (rem3 * 70 + rem5 * 21 + rem7 * 15) % 105

    print("Your age is {0}; that's a good time to start programming!".format(age))


def count():
    print('Now I will prove to you that I can count to any number you want.')
    num = int(input())

    counter = 0
    while counter <= num:
        print("{0} !".format(counter))
        counter += 1


def test():
    print("Let's test your AI knowledge.")
    print("Who is the father of Artificial Intelligence?")
    print("1. Alan Turing")
    print("2. John McCarthy")
    print("3. Bill Gates")
    print("4. Tony Stark")

    answer = 2
    guess = int(input())
    while guess != answer:
        print("Please, try again.")
        guess = int(input())

    print('Congrats, Its a correct answer!')
    print('.................................')
    print('.................................')


def end():
    print('Thank You!')
    input()
    
greet('Chitti', 'Nitish Chintakindi')  
remind_name()
guess_age()
count()
test()
end()
