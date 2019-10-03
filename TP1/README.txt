Para compilar este programa, voce vai precisar de um sistema operacional Linux ou Windows com Windows Subsystem for Linux (WSL), com o comando bash.

1)NO LINUX
    Abra o Terminal;
    Abra o diretório onde se encontra a pasta do programa:
	ex: a pasta se encontra no Desktop (cd Desktop/felipe_guimaraes/src);
    Nesta pasta, dê o comando 'make test' para rodar os testes, espere até que 29 testes sejam concluídos;
    Ou, se preferir, dê o comando 'make run' para rodar seus próprios testes. Para sair do loop no make run, digite o número 0 e a letra 'e' separados por espaço.
        
2)NO WINDOWS
    Abra o CMD;
    Abra o diretório onde se encontra a pasta do programa:
	ex: a pasta se encontra no Desktop (cd Desktop/felipe_guimaraes/src);
    Dê o comando 'bash' para entrar no WSL;
    Nesta pasta, dê o comando 'make test' para rodar os testes, espere até que 29 testes sejam concluídos;
    Ou, se preferir, dê o comando 'make run' para rodar seus próprios testes. Para sair do loop no make run, digite o número 0 e a letra 'e' separados por espaço.

Após a execução, dê o comando 'make clean' para apagar os arquivos temporários com a extensão '.o'.