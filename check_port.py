import socket
import sys


def check_port():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    result = sock.connect_ex(('localhost', 2247))

    if result == 0:
        sys.exit(0)
    else:
        sys.exit(1)


if __name__ == "__main__":
    check_port()
