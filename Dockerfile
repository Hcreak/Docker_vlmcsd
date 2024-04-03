FROM alpine as builder

RUN apk add git gcc make build-base
RUN git clone https://github.com/Wind4/vlmcsd.git
WORKDIR vlmcsd
RUN make

FROM alpine
COPY --from=builder /vlmcsd/bin/vlmcsd /usr/bin/vlmcsd

RUN ln -sf /usr/share/zoneinfo/Asia/Shanghai  /etc/localtime

EXPOSE 1688/tcp
CMD [ "/usr/bin/vlmcsd", "-D", "-d", "-v", "-e" ]
