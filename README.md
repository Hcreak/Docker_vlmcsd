#Docker_vlmcsd

一个用于构建KMS服务器的Dockerfile

* 用于 64bit Linux
* 基于vlmcsd-svn818-2016-03-07-Hotbird64 

## 使用方法:
	//docker build -t vlmcsd .
	docker build -t vlmcsd git://github.com/Hcreak/Docker_vlmcsd
	docker run -d -p 1688:1688 --name myvlmcsd vlmcsd

  确保docker能够开机启动 并在rc.local中加入:

	/usr/bin/docker start $(/usr/bin/docker ps -aq)

## Thanks:
  vlmcsd author


