FROM centos

RUN yum -y upgrade
ADD vlmcsd-svn818-2016-03-07-Hotbird64 /vlmcsd-svn818-2016-03-07-Hotbird64
EXPOSE 1688
CMD ["/vlmcsd-svn818-2016-03-07-Hotbird64/vlmcsd","-f"]
