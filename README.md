# Docker_vlmcsd

一个用于构建KMS服务器的Dockerfile

## 使用方法:
	//docker build -t vlmcsd .
	//docker build -t vlmcsd git://github.com/Hcreak/Docker_vlmcsd
	//docker run -d -p 1688:1688 --name myvlmcsd vlmcsd
	docker run -d -p 1688:1688 --name myvlmcsd ghcr.io/hcreak/docker_vlmcsd:latest

 * 添加一个绘制统计地图的脚本
 `python make_kms_connect_map.py`


## Thanks:
  [github.com/Wind4/vlmcsd](https://github.com/Wind4/vlmcsd)


