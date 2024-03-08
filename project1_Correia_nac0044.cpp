//=============================================================================
// Name        : project1_correia_nac0044.cpp
// Author      : Neil Correia
// Version     : 2/2/2024
// Description : COMP 2710 Software Construction Project 1
// Sources     : Avery Haddox (I talked with Avery Haddox about the concept of
//                             while loops and nested loops, specifically where
//                             in the loop is the best place to set variables
//                             equal to values.)
//             :
// Compile     : g++ project1_correia_nac0044.cpp -o Project1.out
// Run         : ./Project1.out
//=============================================================================

#include <iostream>

using namespace std;

int main()
{
    float loan = -1;
    float interestRate = -1;
    float monthlyPaid = -1;

    cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

    while (loan <= 0) {
		cout << "\nLoan Amount: ";
		cin >> loan;
		if (loan < 0) {
            cout << "Invalid loan" << endl;
		}
	}

	while (interestRate <= -1) {
		cout << "Interest Rate (% per year): ";
		cin >> interestRate;
		if (interestRate < 0) {
            cout << "Invalid interest rate" << endl;
		}
	}

    interestRate /= 12;
    float interestRateC = interestRate / 100;

	while (monthlyPaid <= 0 || monthlyPaid <= loan * interestRateC) {
		cout << "Monthly Payments: ";
		cin >> monthlyPaid;
		if (monthlyPaid < 0) {
            cout << "Invalid payment" << endl;
		}
	}

		cout << endl;

	cout << "*****************************************************************\n"
	     << "\tAmortization Table\n"
	     << "*****************************************************************\n"
	     << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

    int currentMonth = 0;
    int interestTotal = 0;
    float totalInterest = 0;
    float finalInterest = 0;

    while (loan > 0) {
		if (currentMonth == 0) {
			cout << currentMonth++ << "\t$" << loan;
        if (loan < 1000) cout << "\t";
			cout << "\t" <<  "N/A\tN/A\tN/A\t\tN/A\n";
		}
        else {
            float montlypaid = loan * interestRateC;
            float principal = monthlyPaid - montlypaid;
            loan -= principal;
            interestTotal += montlypaid;



            if (loan < 0) {
                principal += loan;
                monthlyPaid += loan;
                loan = 0;
            }

            cout << currentMonth++ << "\t$" << loan;
			if (loan < 1000) cout << "\t";
			cout << "  $" << monthlyPaid << "\t" << interestRateC * 100 << "\t$" << montlypaid << "\t\t$" << principal << "\n";

		}


    }

    cout << "****************************************************************\n";
	cout << "\nIt takes " << --currentMonth << " months to pay off "
	     << "the loan.\n"
	     << "Total interest paid is: $" << interestTotal;
	cout << endl << endl;
	return 0;


}
