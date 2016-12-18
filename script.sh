#!/bin/sh

git clone git@github.com:whatever /home/testuser/mycode
sudo chown -R testuser /home/testuser/mycode 

tar -zcvf mycode.tar.gz /home/testuser/mycode

tar -cvpf mycode.tar.gz /home/testuser/mycode/ | xargs -I '{}' sh -c "test -f '{}' && 
  md5sum '{}'" | ssh remote "( cd /home/testuser/remotecode/ ; cat > mycode.tar.gz

/sbin/init.d/node stop
mv  /home/testuser/mycode/mycode.tar.gz   /user/node/data/
tar -zxvf mycode.tar.gz
/sbin/init.d/node start
