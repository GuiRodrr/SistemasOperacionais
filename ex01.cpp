#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 128

int main() {
    // Nome do arquivo de entrada
    const char *arquivo_entrada = "lab2_ex1.txt";

    // Descritores de arquivos
    int fd_in;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Abrindo o arquivo de entrada no modo de leitura
    fd_in = open(arquivo_entrada, O_RDONLY);
    if (fd_in == -1) {
        perror("Não foi possível abrir o arquivo de entrada");
        return EXIT_FAILURE;
    }

    // Lendo do arquivo de entrada e escrevendo no arquivo de saída
    while ((bytes_read = read(fd_in, buffer, sizeof(buffer) - 1)) > 0) {
        printf(buffer, "%s");
    }

    // Verifica se ocorreu erro na leitura
    if (bytes_read == -1) {
        perror("Erro ao ler o arquivo de entrada");
    }

    // Fechando os arquivos
    close(fd_in);

    return EXIT_SUCCESS;
}
