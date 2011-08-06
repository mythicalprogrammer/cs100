#!/bin/bash
#
#GROUP: DEVIANT PROGRAMMERS
#
#NAMES:
#QUOC ANH DOAN 860759993
#NGUYEN DO 860734448
#JAY NOVILLA 860802932
#KEITH 860816418
#
#-----------------------------------

#GLOBAL DECLARATIONS
declare -rx PATH="./cs-100/personal/jnovilla"


#SANITY CHECKS




#MAIN SCRIPT
/usr/bin/svn co https://svn1.cs.ucr.edu/kailshie/cs-100 
cd $PATH/
/usr/bin/make clean
/usr/bin/make
RESULT="$?"
if [ "$RESULT" != "0" ]; then
  /bin/touch a
  /bin/mail -s "CS100 - Circuit Sim : BUILD FAIL" ndo@cs.ucr.edu < a
  /bin/mail -s "CS100 - Circuit Sim : BUILD FAIL" jnovilla@cs.ucr.edu < a
  /bin/mail -s "CS100 - Circuit Sim : BUILD FAIL" qdoan@cs.ucr.edu < a
  /bin/mail -s "CS100 - Circuit Sim : BUILD FAIL" kailshie@cs.ucr.edu < a
else
  cd $PATH
  /bin/echo "log `date`" >> tempt.txt
  /bin/echo "**********\n" >> tempt.txt
  ./cs input.txt >> tempt.txt
  /bin/echo "**********\n" >> tempt.txt
  ./cs input2.txt >> tempt.txt
  /bin/echo "**********\n" >> tempt.txt
  ./cs input3.txt >> tempt.txt
  /bin/echo "**********\n" >> tempt.txt
  ./cs input4.txt >> tempt.txt
  /bin/echo "**********\n" >> tempt.txt
  ./cs input5.txt >> tempt.txt
  /bin/echo "**********\n" >> tempt.txt
  ./cs input6.txt >> tempt.txt
  /bin/echo "**********\n" >> tempt.txt
  ./cs input7.txt >> tempt.txt
  /bin/echo "**********\n" >> tempt.txt
  ./csinput8.txt >> tempt.txt
  /bin/echo "**********\n" >> tempt.txt
  ./cs input9.txt >> tempt.txt
  /bin/echo "**********\n" >> tempt.txt
  ./cs input10.txt >> tempt.txt
  /bin/echo "**********\n" >> tempt.txt
  ./cs input11.txt >> tempt.txt
  /bin/echo "**********\n" >> tempt.txt
  ./cs input12.txt >> tempt.txt
  /bin/echo "**********\n" >> tempt.txt
  ./cs input13.txt >> tempt.txt
  /bin/echo "**********\n" >> tempt.txt
  ./cs input14.txt >> tempt.txt
  /bin/echo "**********\n" >> tempt.txt
  ./cs input15.txt >> tempt.txt
  /bin/echo "============\n\n" >> tempt.txt
  /bin/mail -s "CS100 - Circuit Sim : BUILD SUCCESS" ndo@cs.ucr.edu < tempt.txt
  /bin/mail -s "CS100 - Circuit Sim : BUILD SUCCESS" jnovilla@cs.ucr.edu < tempt.txt
  /bin/mail -s "CS100 - Circuit Sim : BUILD SUCCESS" qdoan@cs.ucr.edu < tempt.txt
  /bin/mail -s "CS100 - Circuit Sim : BUILD SUCCESS" kailshie@cs.ucr.edu < tempt.txt
fi
