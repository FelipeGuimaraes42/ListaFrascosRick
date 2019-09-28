Para compilar este programa este programa, voce vai precisar de um sistema operacional Linux ou Windows Subsystem for Linux (WSL), com o comando bash.

1)NO LINUX
    Abra o Terminal;
    Abra o diretório onde se encontra a pasta do programa (/felipe_guimaraes/src);
    Nesta pasta, dê o comando 'make test' para rodar os testes, espere até que 29 testes sejam concluído;
    Ou, se preferir, dê o comando 'make run' para rodar seus próprios testes, para sair do loop no make run, digite i número 0 e a letra 'e' separados por espaço ou enter.
        
2)NO WINDOWS
    Abra o CMD;
    Abra o diretório onde se encontra a pasta do programa (/felipe_guimaraes/src);
    Dê o comando 'bash' para entrar no WSL;
    Nesta pasta, dê o comando 'make test' para rodar os testes, espere até que 29 testes sejam concluído;
    Ou, se preferir, dê o comando 'make run' para rodar seus próprios testes, para sair do loop no make run, digite o número 0 e a letra 'e' separados por espaço ou enter.

Após a execução, dê o comando 'make clean' para apagar os arquivos temporários com a extensão '.o'.