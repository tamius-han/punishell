# Punishell

Find bash boring? Do you want to make your use of command line more exciting but find [Suicide Linux](http://qntm.org/suicide) a bit too risky? If that's the case, then Punishell is probably the thing for you. It's a "shell" that punishes you for messing your commands (and 'awards' you for getting it right) in a less strict fashion than Suicide Linux.

--

## What this thing does:

This is nothing more than a glorified Bash shell. You type commands, commands get executed. If you make a mistake when writing command (determined by exit status and contents of STDERR), you lose points. Lose too many points and your computer will power off. 

Typing commands correctly will increase your score, the goal is to get the score as high as you can before you lose. If you manage to reach certain amount of points, the game will award you with 50 extra hp.

## The mistakes part

There's two kinds of mistakes and errors: 
 * 'permission' issues (If stderr contains the word 'permission', then permission error is assumed). They net you -10 hp
 * Everything else (which gives you -20 hp)
 
 Once the hp runs out, the computer will power off (assuming you are nice, play fair and allow 'poweroff' to execute without providing your password). 
 
## The scoring part

Each correct command will increase your xp. Commands shorter than 15 characters (whitespaces included) will award no points. After 15 characters, the score depends on command length (1 character - 1 point), the amount of commands you chained together (each command increases multiplier by 1. pipes don't count) and a lenght-based multiplier.


## Installation

Run install.sh. It should install punishell just fine.

Manual installation/what install.sh is supposed to do:

1. Everything in the 'script' folder goes to `~/.scripts/punishell`
2. Everything in the 'config' folder goes to `~/.config/punishell`
3. Adds these two lines to the end `.bashrc` and `.profile`: 
```
PATH=$PATH:~/.scripts:~/.scripts/punishell
punishell
```
(The last one is optional).

4. You should add this line to the sudoers file:
```
(your username) ALL=(ALL) NOPASSWD:/bin/poweroff,/usr/bin/poweroff,/sbin/poweroff
```

## Usage

You can, for the most part, just enter commands in approximately the same manner you'd enter in a bash shell.

There's few built-in commands:

 * `exit` - end punishell
 * `achievements` - print achievements
 * `isof` - prints current score and HP

# Uninstall

Same as installation, except you remove that stuff instead of adding it. 
 
## What works:

 * So far it looks like any command that gets executed in bash also gets executed with punishell, with exception of one-line loops
 * Ctrl-c will cancel your current command but won't terminate shell
 * Autocomplete
 
## What doesn't

 * ... one-line loops. I had to choose between in-line loops and 'cd' command working properly.
 * History

## Bugs

It seems there's a bug in notify-send which limits icon filepath to something ridiculously short. If your username is long (or if your home folder is in a directory significantly longer than /home/$username), you could have some minor issues.

Other than that, there are likely some more. Hope you brought some bugspray.

## What can you do with this project?

Anything you want, I don't really care. As long as you don't replace the ascii-dragon logo in the code files with a wyvern or anything else that ordinary folk (e.g. Peter Jackson in Hobbit) keeps mistaking for dragons even though they're not really.


## Disclaimer

This was mostly written up during [2015 Dragonhack](http://dragonhack.si/). I've polished it a bit further and added some comments. Other than that, this project was made because it's fun, not because it's particularly useful. And because we didn't have any other particularly decent ideas we had time to pull off. It was also mildly inspired by [gnu-pricing](https://github.com/diafygi/gnu-pricing/blob/master/README.md) project.