<a name="br1"></a> 

Philosophers

I never thought philosophy would be so deadly

Summary:

In this project, you will learn the basics of threading a process.

You will see how to create threads and you will discover mutexes.

Version: 10



<a name="br2"></a> 

Contents

[I](#br3)

[Introduction](#br3)

2

3

[II](#br4)

[Common](#br4)[ ](#br4)[Instructions](#br4)

[Overview](#br6)

[III](#br6)

[IV](#br7)

[V](#br9)

5

[Global](#br7)[ ](#br7)[rules](#br7)

6

[Mandatory](#br9)[ ](#br9)[part](#br9)

[Bonus](#br10)[ ](#br10)[part](#br10)

8

[VI](#br10)

[VII](#br11)

9

[Submission](#br11)[ ](#br11)[and](#br11)[ ](#br11)[peer-evaluation](#br11)

10

1



<a name="br3"></a> 

Chapter I

Introduction

Philosophy (from Greek, philosophia, literally "love of wisdom") is the study of general

and fundamental questions about existence, knowledge, values, reason, mind, and lan-

guage. Such questions are often posed as problems to be studied or resolved. The term

was probably coined by Pythagoras (c. 570 – 495 BCE). Philosophical methods include

questioning, critical discussion, rational argument, and systematic presentation.

Classic philosophical questions include: Is it possible to know anything and to prove

it? What is most real? Philosophers also pose more practical and concrete questions such

as: Is there a best way to live? Is it better to be just or unjust (if one can get away with

it)? Do humans have free will?

Historically, "philosophy" encompassed any body of knowledge. From the time of An-

cient Greek philosopher Aristotle to the 19th century, "natural philosophy" encompassed

astronomy, medicine, and physics. For example, Newton’s 1687 Mathematical Principles

of Natural Philosophy later became classiﬁed as a book of physics.

In the 19th century, the growth of modern research universities led academic philos-

ophy and other disciplines to professionalize and specialize. In the modern era, some

investigations that were traditionally part of philosophy became separate academic dis-

ciplines, including psychology, sociology, linguistics, and economics.

Other investigations closely related to art, science, politics, or other pursuits remained

part of philosophy. For example, is beauty objective or subjective? Are there many sci-

entiﬁc methods or just one? Is political utopia a hopeful dream or hopeless fantasy?

Major sub-ﬁelds of academic philosophy include metaphysics ("concerned with the fun-

damental nature of reality and being"), epistemology (about the "nature and grounds of

knowledge [and]... its limits and validity"), ethics, aesthetics, political philosophy, logic

and philosophy of science.

2



<a name="br4"></a> 

Chapter II

Common Instructions

• Your project must be written in C.

• Your project must be written in accordance with the Norm. If you have bonus

ﬁles/functions, they are included in the norm check and you will receive a 0 if there

is a norm error inside.

• Your functions should not quit unexpectedly (segmentation fault, bus error, double

free, etc) apart from undeﬁned behaviors. If this happens, your project will be

considered non functional and will receive a 0 during the evaluation.

• All heap allocated memory space must be properly freed when necessary. No leaks

will be tolerated.

• If the subject requires it, you must submit a Makefile which will compile your

source ﬁles to the required output with the ﬂags -Wall, -Wextra and -Werror, use

cc, and your Makeﬁle must not relink.

• Your Makefile must at least contain the rules $(NAME), all, clean, fclean and

re.

• To turn in bonuses to your project, you must include a rule bonus to your Makeﬁle,

which will add all the various headers, librairies or functions that are forbidden on

the main part of the project. Bonuses must be in a diﬀerent ﬁle \_bonus.{c/h} if

the subject does not specify anything else. Mandatory and bonus part evaluation

is done separately.

• If your project allows you to use your libft, you must copy its sources and its

associated Makefile in a libft folder with its associated Makeﬁle. Your project’s

Makefile must compile the library by using its Makefile, then compile the project.

• We encourage you to create test programs for your project even though this work

won’t have to be submitted and won’t be graded. It will give you a chance

to easily test your work and your peers’ work. You will ﬁnd those tests especially

useful during your defence. Indeed, during defence, you are free to use your tests

and/or the tests of the peer you are evaluating.

• Submit your work to your assigned git repository. Only the work in the git reposi-

tory will be graded. If Deepthought is assigned to grade your work, it will be done

3



<a name="br5"></a> 

Philosophers

I never thought philosophy would be so deadly

after your peer-evaluations. If an error happens in any section of your work during

Deepthought’s grading, the evaluation will stop.

4



<a name="br6"></a> 

Chapter III

Overview

Here are the things you need to know if you want to succeed this assignment:

• One or more philosophers sit at a round table.

There is a large bowl of spaghetti in the middle of the table.

• The philosophers alternatively eat, think, or sleep.

While they are eating, they are not thinking nor sleeping;

while thinking, they are not eating nor sleeping;

and, of course, while sleeping, they are not eating nor thinking.

• There are also forks on the table. There are as many forks as philosophers.

• Because serving and eating spaghetti with only one fork is very inconvenient, a

philosopher takes their right and their left forks to eat, one in each hand.

• When a philosopher has ﬁnished eating, they put their forks back on the table and

start sleeping. Once awake, they start thinking again. The simulation stops when

a philosopher dies of starvation.

• Every philosopher needs to eat and should never starve.

• Philosophers don’t speak with each other.

• Philosophers don’t know if another philosopher is about to die.

• No need to say that philosophers should avoid dying!

5



<a name="br7"></a> 

Chapter IV

Global rules

You have to write a program for the mandatory part and another one for the bonus part

(if you decide to do the bonus part). They both have to comply with the following rules:

• Global variables are forbidden!

• Your(s) program(s) should take the following arguments:

number\_of\_philosophers time\_to\_die time\_to\_eat time\_to\_sleep

[number\_of\_times\_each\_philosopher\_must\_eat]

◦ number\_of\_philosophers: The number of philosophers and also the number

of forks.

◦ time\_to\_die (in milliseconds): If a philosopher didn’t start eating time\_to\_die

milliseconds since the beginning of their last meal or the beginning of the sim-

ulation, they die.

◦ time\_to\_eat (in milliseconds): The time it takes for a philosopher to eat.

During that time, they will need to hold two forks.

◦ time\_to\_sleep (in milliseconds): The time a philosopher will spend sleeping.

◦ number\_of\_times\_each\_philosopher\_must\_eat (optional argument): If all

philosophers have eaten at least number\_of\_times\_each\_philosopher\_must\_eat

times, the simulation stops. If not speciﬁed, the simulation stops when a

philosopher dies.

• Each philosopher has a number ranging from 1 to number\_of\_philosophers.

• Philosopher number 1 sits next to philosopher number number\_of\_philosophers.

Any other philosopher number N sits between philosopher number N - 1 and philoso-

pher number N + 1.

6



<a name="br8"></a> 

Philosophers

About the logs of your program:

I never thought philosophy would be so deadly

• Any state change of a philosopher must be formatted as follows:

◦ timestamp\_in\_ms X has taken a fork

◦ timestamp\_in\_ms X is eating

◦ timestamp\_in\_ms X is sleeping

◦ timestamp\_in\_ms X is thinking

◦ timestamp\_in\_ms X died

Replace timestamp\_in\_ms with the current timestamp in milliseconds

and X with the philosopher number.

• A displayed state message should not be mixed up with another message.

• A message announcing a philosopher died should be displayed no more than 10 ms

after the actual death of the philosopher.

• Again, philosophers should avoid dying!

Your program must not have any data races.

7



<a name="br9"></a> 

Chapter V

Mandatory part

Program name

Turn in ﬁles

Makeﬁle

philo

Makefile, \*.h, \*.c, in directory philo/

NAME, all, clean, fclean, re

number\_of\_philosophers time\_to\_die time\_to\_eat

time\_to\_sleep

~~Arguments~~

[number\_of\_times\_each\_philosopher\_must\_eat]

memset, printf, malloc, free, write,

usleep, gettimeofday, pthread\_create,

pthread\_detach, pthread\_join, pthread\_mutex\_init,

pthread\_mutex\_destroy, pthread\_mutex\_lock,

pthread\_mutex\_unlock

External functs.

Libft authorized

Description

No

Philosophers with threads and mutexes

The speciﬁc rules for the mandatory part are:

• Each philosopher should be a thread.

• There is one fork between each pair of philosophers. Therefore, if there are several

philosophers, each philosopher has a fork on their left side and a fork on their right

side. If there is only one philosopher, there should be only one fork on the table.

• To prevent philosophers from duplicating forks, you should protect the forks state

with a mutex for each of them.

8



<a name="br10"></a> 

Chapter VI

Bonus part

Program name

~~Turn in ﬁles~~

Makeﬁle

philo\_bonus

Makefile, \*.h, \*.c, in directory philo\_bonus/

NAME, all, clean, fclean, re

~~Arguments~~

number\_of\_philosophers time\_to\_die time\_to\_eat

time\_to\_sleep

[number\_of\_times\_each\_philosopher\_must\_eat]

memset, printf, malloc, free, write, fork, kill,

exit, pthread\_create, pthread\_detach, pthread\_join,

usleep, gettimeofday, waitpid, sem\_open, sem\_close,

sem\_post, sem\_wait, sem\_unlink

~~External functs.~~

Libft authorized

~~Description~~

No

Philosophers with processes and semaphores

The program of the bonus part takes the same arguments as the mandatory program.

It has to comply with the requirements of the Global rules chapter.

The speciﬁc rules for the bonus part are:

• All the forks are put in the middle of the table.

• They have no states in memory but the number of available forks is represented by

a semaphore.

• Each philosopher should be a process. But the main process should not be a

philosopher.

The bonus part will only be assessed if the mandatory part is

PERFECT. Perfect means the mandatory part has been integrally done

and works without malfunctioning. If you have not passed ALL the

mandatory requirements, your bonus part will not be evaluated at all.

9



<a name="br11"></a> 

Chapter VII

Submission and peer-evaluation

Turn in your assignment in your Git repository as usual. Only the work inside your repos-

itory will be evaluated during the defense. Don’t hesitate to double check the names of

your ﬁles to ensure they are correct.

Mandatory part directory: philo/

Bonus part directory: philo\_bonus/

10

