#!/resourse/sh

CUR_DIR=$(cd "$(dirname "${BASH_SOURCE-$0}")"; pwd)
MOD_NAME="firewall_kernel.ko"
DEV_PATH="/dev/controlInfo"

if [ "$(bash $CUR_DIR/ckmod.sh)" == "true" ]
then
    echo "success"
else
    insmod $CUR_DIR/$MOD_NAME
    if [ "$?" == "0" ]
    then
        mknod ${DEV_PATH} c 817 0
        chmod 0666 ${DEV_PATH}
        echo "success"
    else
        echo "failure"
    fi
fi
