export HISTSIZE=1000000
export HISTFILESIZE=1000000

export JAVA_HOME=/opt/graalvm

export PATH=.:$PATH
export PATH=$PATH:/usr/local/bin
export PATH=$PATH:$JAVA_HOME/bin
export PATH=$PATH:/opt/apache-maven-3.9.6/bin

alias stow='cd /home/rootshell/Code/Projects/workspace'
alias less='less -x4'
alias py='python3.11'
alias pip='pip3.11'
alias cls='clear'
alias wd='pwd'
alias push='pushd .'
alias pop='popd'
alias freq='cat /sys/devices/system/cpu/cpu*/cpufreq/scaling_cur_freq'
alias boost='echo performance | sudo tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor'
alias tooladd='append /home/rootshell/Notes/utils'
alias gets='echo ATBBrJ4p9XaAgVxjJGcP24qGz4Ln47F30338'

#PS1='[\u@localhost.localdomain]$ '
#PS1='\[\e]0;\w\a\][\u@localhost.localdomain]$ '