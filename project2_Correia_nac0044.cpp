//=============================================================================
// Name        : project2_correia_nac0044.cpp
// Author      : Neil Correia
// Version     : 2/13/2024
// Description : COMP 2710 Software Construction Project 2
// Compile     : g++ project2_correia_nac0044.cpp -o Project2.out
// Run         : ./Project2.out
//=============================================================================


#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;

const double aaron_probabiity = 33.333;
const double bob_probabiity = 50;
const double charlie_probabiity = 100;
const double duels = 10000;

bool A_alive;
bool B_alive;
bool C_alive;

int A_win = 0;
int A_win2 = 0;
int B_win = 0;
int C_win = 0;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
void Strategy_1(bool& A_alive, bool& B_alive, bool& C_alive);
void Strategy_2(bool& A_alive, bool& B_alive, bool& C_alive);
void press_any_key(void);

void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);




int main()
{
    cout << "*** Welcome to Neil's Duel Simulator ***\n";

    srand(time(0));

    test_at_least_two_alive();
    press_any_key();
    test_Aaron_shoots1();
    press_any_key();
    test_Bob_shoots();
    press_any_key();
    test_Charlie_shoots();
    press_any_key();
    test_Aaron_shoots2();
    press_any_key();

    cout << "\nReady to test strategy 1 (run 10000 times):\n";
    press_any_key();

    for (int i = 0; i < duels; i++) {
        Strategy_1(A_alive, B_alive, C_alive);
        A_alive = true;
        B_alive = true;
        C_alive = true;
    }

    int strategy;
    strategy = A_win;

    cout << "Aaron won " << strategy << "/" << duels
         << " duels or " << (strategy / 100.0) << "%"
         << endl;

    cout << "Bob won " << B_win << "/" << duels
         << " duels or " << (B_win / 100.0) << "%"
         << endl;

    cout << "Charlie won " << C_win << "/" << duels
         << " duels or " << (C_win / 100.0) << "%"
         << endl;

    A_win = 0;
    B_win = 0;
    C_win = 0;

    cout <<"\nReady to test strategy 2 (run 10000 times):\n";
    press_any_key();

    for (int i = 0; i < duels; i++) {
        Strategy_2(A_alive, B_alive, C_alive);
        A_alive = true;
        B_alive = true;
        C_alive = true;
    }

    int strategy2;
    strategy2 = A_win2;

    cout << "Aaron won " << strategy2 << "/" << duels
         << " duels or " << (strategy2 / 100.0) << "%"
         << endl;

    cout << "Bob won " << B_win << "/" << duels
         << " duels or " << (B_win / 100.0) << "%"
         << endl;

    cout << "Charlie won " << C_win << "/" << duels
         << " duels or " << (C_win / 100.0) << "%"
         << endl;

    if (strategy > strategy2) cout << "\nStrategy 1 is better than strategy 2.";
    else cout << "\nStrategy 2 is better than strategy 1.";

}

void press_any_key(void) {
    cout << "Press any key to continue...\n";
    cin.get();
}


bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
        if (( A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive) ) {
            return true;
        }
        else {
            return false;
        }
}

void test_at_least_two_alive(void) {
    cout << "Unit Testing 1: Function - at_least_two_alive()\n";

    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));
    cout << "\tCase passed ...\n";

    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(false, true, true));
    cout << "\tCase passed ...\n";

    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == at_least_two_alive(true, false, true));
    cout << "\tCase passed ...\n";

    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == at_least_two_alive(true, true, false));
    cout << "\tCase passed ...\n";

    cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(false == at_least_two_alive(false, false, true));
    cout << "\tCase passed ...\n";

    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == at_least_two_alive(false, true, false));
    cout << "\tCase passed ...\n";

    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(true, false, false));
    cout << "\tCase passed ...\n";

    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(false, false, false));
    cout << "\tCase passed ...\n";
}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
    int shoot_target_result = rand()%100;
    if (shoot_target_result <= aaron_probabiity) {
        if (C_alive) C_alive = false;
        else B_alive = false;
    }
}

void Bob_shoots(bool& A_alive, bool& C_alive) {
    int shoot_target_result = rand()%100;
    if (shoot_target_result <= bob_probabiity) {
        if (C_alive) C_alive = false;
        else A_alive = false;
    }
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
     if (B_alive) B_alive = false;
     else A_alive = false;
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
    if (!B_alive || !C_alive) {
        int shoot_target_result = rand() % 100;
        if (shoot_target_result <= aaron_probabiity) {
            if (C_alive) C_alive = false;
            else B_alive = false;
        }
    }
}

void test_Aaron_shoots1(void) {

    bool bob;
    bool charlie;

    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";

    cout << "\tCase 1: Bob alive, Charlie alive\n"
         << "\t\tAaron is shooting at Charlie\n";
    bob = true;
    charlie = true;
    Aaron_shoots1(bob, charlie);
    assert(true == bob);

    cout << "\tCase 2: Bob dead, Charlie alive\n"
         << "\t\tAaron is shooting at Charlie\n";
    bob = false;
    charlie = true;
    Aaron_shoots1(bob, charlie);
    assert(false == bob);

    cout << "\tCase 3: Bob alive, Charlie dead\n"
         << "\t\tAaron is shooting at Bob\n";
    bob = true;
    charlie = false;
    Aaron_shoots1(bob, charlie);
    assert(false == charlie);
}

void test_Bob_shoots(void) {
    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

    bool aaron;
    bool charlie;

    cout << "\tCase 1: Aaron alive, Charlie alive\n"
         << "\t\tBob is shooting at Charlie\n";
    aaron = true;
    charlie = true;
    assert(true == aaron);
    Bob_shoots(aaron, charlie);

    cout << "\tCase 2: Aaron dead, Charlie alive\n"
         << "\t\tBob is shooting at Charlie\n";
    aaron = false;
    charlie = true;
    assert(false == aaron);
    Bob_shoots(aaron, charlie);

    cout << "\tCase 3: Aaron alive, Charlie dead\n"
         << "\t\tBob is shooting at Aaron\n";
    aaron = true;
    charlie = false;
    assert(false == charlie);
    Bob_shoots(aaron, charlie);
}

void test_Charlie_shoots(void) {

    bool aaron;
    bool bob;

    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

    cout << "\tCase 1: Aaron alive, Bob alive\n"
         << "\t\tCharlie is shooting at Bob\n";
    aaron = true;
    bob = true;
    assert(true == bob);
    Charlie_shoots(aaron, bob);

    A_alive = false;
    B_alive = true;
    cout << "\tCase 2: Aaron dead, Bob alive\n"
         << "\t\tCharlie is shooting at Bob\n";
    aaron = false;
    bob = true;
    assert(false == aaron);
    Charlie_shoots(aaron, bob);

    A_alive = true;
    B_alive = false;
    cout << "\tCase 3: Aaron alive, Bob dead\n"
         << "\t\tCharlie is shooting at Aaron\n";
    aaron = true;
    bob = false;
    assert(false == bob);
    Charlie_shoots(aaron, bob);
}

void test_Aaron_shoots2(void) {
    cout<< "Unit Testing 5: Function - Aaron_shoots2(Bob_alive, Charlie_alive)\n";

    cout << "\tCase 1: Bob alive, Charlie alive\n"
         << "\t\tAaron intentionally misses misses his first shot\n"
         << "\t\tBoth Bob and Charlie are alive\n";
    Aaron_shoots2(B_alive, C_alive);

    B_alive = false;
    C_alive = true;
    cout << "\tCase 2: Bob dead, Charlie alive\n"
         << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots2(B_alive, C_alive);

    B_alive = true;
    C_alive = false;
    cout << "\tCase 3: Bob alive, Charlie dead\n"
         << "\t\tAaron is shooting at Bob\n";
    Aaron_shoots2(B_alive, C_alive);
}

void Strategy_1(bool& A_alive, bool& B_alive, bool& C_alive) {
    A_alive = true;
    B_alive = true;
    C_alive = true;
    while(at_least_two_alive(A_alive, B_alive, C_alive)) {
        if (A_alive) Aaron_shoots1(B_alive, C_alive);

        if (B_alive) Bob_shoots(A_alive, C_alive);

        if (C_alive) Charlie_shoots(A_alive, B_alive);
    }

    if (A_alive) A_win++;
    if (B_alive) B_win++;
    if (C_alive) C_win++;

}

void Strategy_2(bool& A_alive, bool& B_alive, bool& C_alive) {
    A_alive = true;
    B_alive = true;
    C_alive = true;
    while(at_least_two_alive(A_alive, B_alive, C_alive)) {
        if (A_alive) Aaron_shoots2(B_alive, C_alive);

        if (B_alive) Bob_shoots(A_alive, C_alive);

        if (C_alive) Charlie_shoots(A_alive, B_alive);
    }

    if (A_alive) A_win2++;
    if (B_alive) B_win++;
    if (C_alive) C_win++;
}

