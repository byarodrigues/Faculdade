

import socket

def main():
    host = '127.0.0.1'
    port = 5555

    # Cria o socket do cliente
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Conecta ao servidor
    client_socket.connect((host, port))

    while True:
        # Envia a mensagem para o servidor
        message = input("Digite uma mensagem para o servidor (ou 'exit' para sair): ")
        client_socket.send(message.encode('utf-8'))

        # Recebe a resposta do servidor
        data = client_socket.recv(1024).decode('utf-8')
        print(f'Resposta do servidor: {data}')

        # Verifica se o cliente deseja sair
        if message.lower() == 'exit':
            break

    # Fecha o socket do cliente
    client_socket.close()

if __name__ == "__main__":
    main()
