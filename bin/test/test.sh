#!bin/bash

rm -f ___echo.txt
rm -f ft_echo.txt
rm -f __tests.txt

argv=""
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
echo ""
sleep 0.25

argv="-a"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-x"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25


argv="-j"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-y"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-k"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="- -"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="- - -"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="- - - -"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n -n test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n -n -n test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-nn test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-nn -nn test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-nn -nn -nn test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="- test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="- -n test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="- -n -n test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="- -n -n -n test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="- -nn test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="- -nn -nn test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="- -nn -nn -nn test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n- test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n- -n test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n- -n -n test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n- -n -n -n test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n- -nn test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n- -nn -nn test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n- -nn -nn -nn test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n- test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n test -n"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-nn test -nn"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n -n test -n -n"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-nnnn test -nnnn"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-nnnnn - -n test -nnnn - -n"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-nn -n --n test -nn - --n"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n- -nn -nn test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n- -nn -nn -nn test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n- test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n test -n"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-nn test -nn"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n -n test -n -n"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-nnnn test -nnnn"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-nnnnn - -n test -nnnn - -n"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-nn -n --n test -nn - --n"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n- -nn -nn test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n- -nn -nn -nn test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n- test"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n test -n"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-nn test -nn"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n -n test -n -n"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-nnnn test -nnnn"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-nnnnn - -n test -nnnn - -n"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-nn -n --n test -nn - --n"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="The person you were before is still not very coherent."
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="A flailing monkey is running away."
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="A sickingly prodigous profile shot the sheriff."
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="An old apple takes the world for granted."
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-nnn Rock music lies ahead, what with the future yet to come."
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n Ring Any Bells?"
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25

argv="-n The snow-covered path was no help in finding his way out of the back-country."
printf '%s\n' "$argv" >> __tests.txt
echo "___echo:  [ $argv ]"
echo "$argv" >> ___echo.txt
/home/mde-rosa/Documents/minishell/bin/ft_echo "ft_echo:  [ $argv ]"
/home/mde-rosa/Documents/minishell/bin/ft_echo "$argv" >> ft_echo.txt
 echo ""
sleep 0.25
 echo ""
sleep 0.25
 echo ""
sleep 0.25
 echo ""
sleep 0.25
 echo ""
sleep 0.25
 echo ""
sleep 0.15
echo "                  ▄▄▄▀▀▀▀▀▀▀▄▄"
sleep 0.15
echo "              ▄▄▀▀    ▀▀▀▀▄   ▀█"
sleep 0.15
echo "           ▄▀▀  ▀▀▀▀▀▀▄   ▀▄    █"
sleep 0.15
echo "          █▄▄▄▄▄▄▄▄     ▀▄  ▀▄   █"
sleep 0.15
echo "        ▄█         ▀▄      █  █  █"
sleep 0.15
echo "      ▄█             ▀▄     ▐ ▐  ▌"
sleep 0.15
echo "      ██               ▀▌   ▐ ▄▀▀▀▄▄"
sleep 0.15
echo "      █        ██       ▌   ▄▀      ▐"
sleep 0.15
echo "      █         █       ▌  ▐         █"
sleep 0.15
echo "     ▐          ▌     ▄▀    ▌       ▐             ▄▄▄▄▄▄"
sleep 0.15
echo "      ▌          ▀▀▀▀        ▀▀▄▄▄▀▀▀    ▄▄████▓▓▓▓▓▓▓███▄"
sleep 0.15
echo "      ▌                            ▄▀  ▄▄█▓▓▓▓▓▓▓         ▓▓▄"
sleep 0.15
echo "      ▐                          ▄▀ ▄█▓▓▓▓▓▓▓▓▓▓  ██   ███  ▓▓█▄"
sleep 0.15
echo "       ▌                      ▄▀ ▄█▓▓▓▓▓▓▓▓▓▓▓  ██ █  ██ ██  ▓▓█"
sleep 0.15
echo "     ▄▀▄                 ▄▀▀▌██▓▓▓▓▓▓▓▓▓▓▓▓    ██   ███  ██  ▓▓█"
sleep 0.15
echo "    ▌    ▀▀▀▄▄▄▄▄▄▄▄▀▀   ▌█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    ██     █   ██  ▓▓█"
sleep 0.15
echo "     ▀▄                 ▄▀▀▓▓▓▓▓▓▓▓████████              ██ ▓▓█"
sleep 0.15
echo "       █▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▄▄██████▄   ▄█"
sleep 0.15
echo "       █▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█▓▓███▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓█▓▓▓▓▓▓▓▓█"
sleep 0.15
echo "        █▓▓▓▓▓▓▓▓▓▓▓▓▓▓█▓█▓▓██░░███████░██▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓█"
sleep 0.15
echo "        █▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓░░░░░█░░░░░██░░░░██▓▓▓▓▓▓▓▓▓██▓▓▓▓▌"
sleep 0.15
echo "        █▓▓▓▓▓▓▓▓▓▓▓▓▓▓███░░░░░░░░    ░██░░░░░░░██▓▓▓▓▓▓▓██▓▓▌"
sleep 0.15
echo "        ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░░░        ░░░░░░░░░██████▓▓▓▓▓█▓▌"
sleep 0.15
echo "        ▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░░   ▓▓▓▓▓░░░░░░░███░░███▓▓▓▓▓█▓▌"
sleep 0.15
echo "         █▓▓▓▓▓▓▓▓▓▓▓▓▓██░░░░░   ▓▓█▄▄▓░░░░░░░░   ░░░░█▓▓▓▓▓█▓▌"
sleep 0.15
echo "         █▓▓▓▓▓▓▓▓▓▓▓▓▓█░░█░░░   ▓▓██░░░░░░░░▓▓▓▓  ░░░░█▓▓▓▓██"
sleep 0.15
echo "         █▓▓▓▓▓▓▓▓▓▓▓▓▓█░███░░    ▓░░░░░░░░░░░█▄█▓  ░░░░█▓▓█▓█"
sleep 0.15
echo "         ▐▓▓▓▓▓▓▓▓▓▓▓▓▓█░█████░░░░░░░░░░░░░░░░░█▓  ░░░░███▓█"
sleep 0.15
echo "          █▓▓▓▓▓▓▓▓▓▓▓▓█░░███████░░░░░░░░░░░░░░░▓ ░░░░░██▓█"
sleep 0.15
echo "          █▓▓▓▓▓▓▓▓▓▓▓▓█░░░███████░░░░░░░░░░░░░░ ░░░░░██▓█"
sleep 0.15
echo "          █▓▓▓▓▓▓▓▓▓▓▓▓█░░░███████░░░░░░░░░░░░░░░░░░░██▓█"
sleep 0.20
echo "           █▓▓▓▓▓▓▓▓▓▓▓▓█░░░░███████░░░░░░░░░░░█████░██░"
sleep 0.20
echo "           █▓▓▓▓▓▓▓▓▓▓▓▓█░░░░░░  ███████░░░░░███████░░█░░"
sleep 0.25
echo "           █▓▓▓▓▓▓▓▓▓▓▓▓▓█░░░░░░█▄▄▄▀▀▀▀████████████░░█░"
sleep 0.35
echo "           ▐▓▓▓▓▓▓▓▓▓▓▓▓█░░░░░░██████▄  ▀▀░░░███░░░░░█"
sleep 0.35
echo "           ▐▓▓▓▓▓▓▓▓▓▓▓█▒█░░░░░░▓▓▓▓▓███▄░░░░░░░░░░░            ▄▄▄"
sleep 0.35
echo "           █▓▓▓▓▓▓▓▓▓█▒▒▒▒█░░░░░░▓▓▓▓▓█░░░░░░░░░░░      ▄▄▄ ▄▀▀▀   ▀▄"
sleep 0.35
echo "          █▓▓▓▓▓▓▓▓▓█▒▒▒▒█▓▓░░░░░░░░░░░░░░░░░░░░░    ▄▀▀   ▀▄         ▀▄"
sleep 0.30
echo "         █▓▓▓▓▓▓▓▓▓█▒▒▒▒█▓▓▓▓░░░░░░░░░░░░░░░░░      ▐▄        █▄▄▀▀▀▄  █"
sleep 0.30
echo "        █▓▓▓▓▓▓▓▓█▒▒▒▒▒▒█▓▓▓▓▓▓▓░░░░░░░░░            █  █    ▐         ▀▄▌"
sleep 0.30
echo "       █▓▓▓▓▓▓▓▓█▒▒▒▒▒▒███▓▓▓▓▓▓▓▓▓▓▓█▒▒▄            █  ▀▄   █    ▄▄▄    ▐"
sleep 0.30
echo "      █▓▓▓▓▓▓▓█       ▒▒█▒▒██▓▓▓▓▓▓▓▓▓▓█▒▒▒▄          █   ▀▀█▀▄▀▀▀   ▀▀▄▄▐"
sleep 0.30
echo "     █▓▓▓▓▓██▒         ▒█▒▒▒▒▒███▓▓▓▓▓▓█▒▒▒██         ▐      ▀█           █"
sleep 0.30
echo "    █▓▓████▒█▒         ▒█▒▒▒▒▒▒▒▒███████▒▒▒▒██        █       ▐     ▄▄▄   █"
sleep 0.25
echo "  █▒██▒▒▒▒▒▒█▒▒    ▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒    ▒█▓█  ▄█▀▀█         ▀▄▄▀▀ ▀▀▄▄█"
sleep 0.25
echo "  █▒▒▒▒▒▒▒▒▒▒█▒▒▒████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█       █▓▓█▓▓▌ ▐          ▐        ▐"
sleep 0.25
echo "  █▒▒▒▒▒▒▒▒▒▒▒███▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒       █▓▓▓█▓▌  ▌          ▐    ▄▄ ▐"
sleep 0.25
echo " █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒     █▓▓▓█▓▓▌  ▌           ▀▄▄▀   ▐"
sleep 0.25
echo " █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒███████▓▓█▓▓▓▌  ▀▄               ▄▀▀▀"
sleep 0.25
echo " █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒███▒▒▒▒▒▒▒██▓▓▓▓▓▌   ▀▄        ▄▄▀▀▀"
sleep 0.20
echo "█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒█▓▓▓▓▓▀▄  ▀▄▄█▀▀▀▀▀"
sleep 0.20
echo "█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▓▓▓▓██▄▄▄▀"
sleep 0.20
echo "█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████"
sleep 0.20
echo "█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█"
sleep 0.20
echo " █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▄▄▄▄▄"
sleep 0.20
echo " █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒███▒▒▒▒▒▒██▄▄"
sleep 0.15
echo "  █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒███▒▒▒▒▒▒▒▒▒▒▒▒▒█▄"
sleep 0.15
echo "  █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█"
sleep 0.15
echo "  █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒█▒▒▒▒▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█"
sleep 0.15
echo "   █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒█▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒▒▒▒▒▌"
sleep 0.15
echo "    █▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒▒▒█▒▒▒▒█▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░▒▒▌"
sleep 0.15
echo "    █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█████████████▒▒▒▒▒█▒▒▒▒▒▒▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒░▒▌"
sleep 0.10
echo "     █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█       ▐▒▒▒▒█▒▒▒▒▒▒▒░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▌"
sleep 0.10
echo "      █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█        █▒▒█▒▒▒▒▒▒░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌"
sleep 0.10
echo "       █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█        █▒█▒▒▒▒▒▒░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌"
sleep 0.10
echo "        █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█        █▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█"
sleep 0.10
echo "         █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█        █▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█"
sleep 0.10
echo "         █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█        █▒▒▒░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▀"
sleep 0.05
echo "          █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█       █▒░░░▒▒▒▒▒░░░░░░░░▒▒▒█▀▀▀"
sleep 0.05
echo "           █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█       █░▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░█▀"
sleep 0.05
echo "            █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█       █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▀"
sleep 0.05
echo "             █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█       █▒▒▒▒▒▒▒▒▒▒▒▒█▀"
sleep 0.05
echo "             █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█       ▀▀▀███████▀▀"
sleep 0.05
echo "              █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█"
sleep 0.05
echo "               █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█"
sleep 0.05
echo "                █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█"
sleep 0.05
echo "                 █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█"
sleep 0.05
echo "                  █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒█"
sleep 0.05
echo "                   █▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒█"
sleep 0.03
echo "                   █▒▒▒▒▒▒▒▒████▒▒▒▒▒▒▒█"
sleep 0.03
echo "                   █████████▒▒▒▒▒▒▒▒▒▒▒█"
sleep 0.03
echo "                    █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█"
sleep 0.05
echo "                    █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█"
sleep 0.08
echo "                     █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▌"
sleep 0.08
echo "                     █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▌"
sleep 0.08
echo "                      █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▌"
sleep 0.08
echo "                       █▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░█"
sleep 0.08
echo "                          ██▒▒▒▒▒▒░░░█▀"
sleep 0.08
echo "                             █░░░░░█▀"
sleep 0.08
echo "                               ▀▀▀▀"
sleep 0.08
 echo ""
sleep 0.08
 echo ""
echo "The tests are in      __tests.txt"
echo "Echo output are is    ___echo.txt"
echo "Ft_echo output is     ft_echo.txt"
echo "The difference between [___echo.txt] & [ft_echo.txt]:"
diff ___echo.txt ft_echo.txt
echo "The test is over! (launch ~$ bash /test/clean.sh)"

