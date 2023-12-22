# Docker_vlmcsd

一个用于构建KMS服务器的Dockerfile

* 用于 64bit Linux

2019-02-20 update:
* 基于vlmcsd源码 镜像构建时编译
* 可以使用 `docker logs` 查看vlmcsd日志输出
* 时区为 UTC +8

2019-05-11 update:
* 为raspberrypi修改的Dockerfile 切换分支raspberrypi

## 使用方法:
	//docker build -t vlmcsd .
	//docker build -t vlmcsd git://github.com/Hcreak/Docker_vlmcsd
	//docker run -d -p 1688:1688 --name myvlmcsd vlmcsd
	docker run -d -p 1688:1688 --name myvlmcsd ghcr.io/hcreak/docker_vlmcsd:latest


## Thanks:
  [github.com/Wind4/vlmcsd](https://github.com/Wind4/vlmcsd)


