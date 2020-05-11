FROM arm32v7/centos

RUN yum -y --nogpgcheck upgrade
RUN yum -y --nogpgcheck install git gcc make
RUN git clone https://github.com/Wind4/vlmcsd.git
WORKDIR vlmcsd
RUN make

ADD start.sh start.sh
RUN chmod +x start.sh

RUN ln -sf /usr/share/zoneinfo/Asia/Shanghai  /etc/localtime

EXPOSE 1688
CMD ["./start.sh"]
