USE OF CHECKER
-------------------------------------------------------------
In shell or bash, run

	ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
to check the number of movements (6)

    ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
to check if the program has sorted the list (OK) or not (KO)

USE OF TESTER.SH
-------------------------------------------------------------
Open the script and set the amount of numbers to be sorted
Run ./tester.sh
It will print the array of numbers to sort and the amount of
movements the program needed to sort it.
Run it several times to calculate the average of movements 
needed.
