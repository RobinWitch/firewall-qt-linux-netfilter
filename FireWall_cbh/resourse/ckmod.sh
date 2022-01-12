#!/resourse/sh

MOD_NAME="firewall_kernel"

if [ "$(lsmod | grep -c "$MOD_NAME")" == "1" ]
then
    echo "true"
else
    echo "false"
fi


