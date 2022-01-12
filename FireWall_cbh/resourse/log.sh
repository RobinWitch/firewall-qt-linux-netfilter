#!/resourse/sh
LOG=$(echo 'change' | sudo -p '' -S dmesg -c | grep '<CBH>')
echo "$LOG"

