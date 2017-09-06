preINN=$(stat ./*.* | grep Change)
while true
do
    sleep 1s
    nowINN=$(stat ./*.* | grep Change)
    if [ "$nowINN" != "${preINN}" ];then
        tput reset
        echo "The filed has been changed"
        rm -rf main
        g++ -std=c++14 -o main main.cpp
        #/usr/bin/time -v ./main
        ./main
    fi
    preINN=${nowINN}
done
