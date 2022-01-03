Jishnu V K IMT2018033
Bharath Sai IMT2018022
Hemanth C IMT2018028 

Testing strategy: control flow graph

The code is mainly divided into a database and a server-client part.
So testing was done by dividing the 2.

The main directory contains:
1) a directory “src” that contains the source code. 
2) documentation.txt
3) testing that contains all the testing work.

Testing contains:
1) A directory “database” that contains testing for database
2) A directory “server_client” that contains testing for server-client system.

Database contains:
1)Cfg diagram
2)Testcases.txt
3)Screenshot of testcases
4)Code: testing code for running the test cases

Server_client contains:
1) “cfg visualization” for cfgs
2) “Prime path Screenshots” for screenshots of prime paths and test paths obtained from the testing tool.
3) “Execution Screenshots” for screenshots of executed test cases.



Tools used:
1) Gcc -fdump-cfg-graph to get cfg for the functions
2) Graphvis to visualize the cfg output from gcc
3) https://cs.gmu.edu:8443/offutt/coverage/GraphCoverage forcoverage criterion and test paths.
4) Ctest to automate testing of database.

Since the client code is mainly UI based, we tested it manually. We tried to find a way to automate it but there was no efficient way.

Division of work
Bharath Sai: full database testing

server-client
Hemanth Chitti: designed and executed test cases.
Jishnu V K:making graphs, finding test paths.

