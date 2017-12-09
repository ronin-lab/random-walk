#!/bin/bash
#
#
#va creato un ciclo per le opzioni del make
#echo compilo integratore.c
make 
#echo

echo
read -p $'inserire numero per algoritmo integrazione:\n 1 = Velocity Verlet,\n 2 = Position Verlet,\n 3 = Runge-Kutta 2,\n 4 = Runge-Kutta 4\n \n ' c
echo

if [ $c -eq 1  ]
then

name="Vverlet"

elif [ $c -eq 2  ]
then

name="Pverlet"

elif [ $c -eq 3  ]
then

name="RK2"

elif [ $c -eq 4  ]
then

name="RK4"


fi

echo $name

echo
read -p $'inserire:\n 0 per inizializazione della parte 1:\n \tparametri a=0, b=0, rho=0.2\n \tCI di x(0)=1.2, y(0)=0.5, z(0)=0;\n \n 1 per inserimento manuale\n ' g
echo

if [ $g -eq 0 ]
then

let "a=0"
let "b=0"
let "rho=0.2"
let "m=1"
let "tmax=100"

elif [ $g -eq 1 ]
then

echo
let "a=0.5"
let "b=0.1"
let "x0=1.2"
let "y0=0.5"
let "z0=0.3"
read -p $'inserire: a b rho x0 y0 z0 tmax\n ' tmax rho
echo

echo $c $a $b $x0 $y0 $z0 $tmax $rho
read

fi

let "i = 1"

while [ $i -lt 5 ]
do

echo $i

echo
./SKYWALKER_gnu $c $a $b $rho $x0 $y0 $z0 $tmax $i
echo

let i++

done


## gnuplot

echo
read -p $'scegliere # iterazioni da plottare:\n 1 per 10^-1,\n 2 per 10^-2,\n 3 per 10^-3,\n 4 per 10^-4,\n 5 per 10^-5\n \n ' z
echo


echo
read -p $'scegliere grafico da plottare:\n x(t) ->1\n v(t) ->2\n v(x)->3\n E(t) ->4\n E(t)-E(0)/E(0) vs t ->5\n \n ' x
echo


if [ $x -eq 1  ]
then

var1="t"
var2="x"
x=1
y=2

elif [ $x -eq 2  ]
then

var1="t"
var2="v"
x=1
y=3


elif [ $x -eq 3  ]
then

var1="x"
var2="v"
x=2
y=3

elif [ $x -eq 4  ]
then

var1="t"
var2="E"
x=1
y=4


elif [ $x -eq 5  ]
then

var1="t"
var2="E(t)-E(0)/E(0)"
x=1
y=5

fi

echo > gnuplot.in
for FILE in *; do
echo "set term 'x11'" >> gnuplot.in
echo "plot '${name}_${z}.dat' u ${x}:${y} title '${var2}(${var1})'" >> gnuplot.in
echo "set term post color eps" >> gnuplot.in
echo "set output '${name}_${z}.eps'" >> gnuplot.in
echo "rep" >> gnuplot.in
done

gnuplot -persist gnuplot.in

echo
mkdir risultati
mv *.dat risultati/
mv *.eps risultati/
echo

echo
ls
echo

echo
rm gnuplot.in
echo


exit
