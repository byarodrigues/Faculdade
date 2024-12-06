#criar um sistema cliente-servidor multi-thread
#o servidor deve disparar uma thread para cada cliente conectado 
#a thread deve responder ao cliente com a mesma mensagem recebida
#a thread deve parar a execuçao quando o cliente enviar a mensagem exit

import socket
import threading

def handle_client(client_socket):
    while True:
        # Recebe a mensagem do cliente
        data = client_socket.recv(1024).decode('utf-8')
        print(f'Mensagem recebida do cliente: {data}')

        # Responde ao cliente com a mesma mensagem
        client_socket.send(data.encode('utf-8'))

        # Verifica se o cliente enviou "exit" para encerrar a thread
        if data.lower() == 'exit':
            break

    # Fecha a conexão com o cliente
    client_socket.close()

def main():
    host = '0.0.0.0'
    port = 5555

    # Cria o socket do servidor
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Vincula o socket à interface e à porta
    server_socket.bind((host, port))

    # Define o servidor para aguardar conexões
    server_socket.listen(5)
    print(f"Servidor ouvindo em {host}:{port}")

    while True:
        # Aceita a conexão do cliente
        client_socket, addr = server_socket.accept()
        print(f"Conexão aceita de {addr[0]}:{addr[1]}")

        # Inicia uma nova thread para lidar com o cliente
        client_handler = threading.Thread(target=handle_client, args=(client_socket,))
        client_handler.start()

if __name__ == "__main__":
    main()

