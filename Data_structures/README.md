Fluxo do programa:

INSTRUÇÕES:
O executável que está junto com o código fonte funciona apenas no MacOS, para executar nos sistemas operacionais Windos ou Linux você deve compilar o programa usando o comando: gcc Artemis.c -o artemis.

1 - Início:
O programa inicia com a inserção do nome do usuário e o ID fictício. 

2 - Loop:
O menu exibe 4 opções. 1 - Inserir dados; 2 - Visualizar Status da cápsula; 3 - Exibir análise dos dados da cápsula;
4 - encerrar o programa. 
O loop apenas encerra quando o usuário escolhe a opção 4.

3 - As Opções:

Opção 1. Inserção de dados: O programa pede para o usuário digitar os dados de temperatura da cápsula, energia e pede uma confirmação da comunicação com Houston, com isso o programa guarda na variável dadosInseridos que o usuário digitou os dados. O programa guarda os inputs em variáveis que ele usará quando o usuário selecionar outras opções no menu. Se por um acaso algum dos dados estiver na zona de alerta pré-definida uma mensagem rápida de alerta é exibida ao usuário.Por fim a opção 1 retorna ao loop e o menu é exibido novamente. 

Opção 2: Visualizar Status: O programa puxa a variável dadosInseridos, se dadosInseridos for = 0, o programa exibe erro que os dados não foram inseridos e retorna ao menu. Se dadosInseridos for = 1 o programa exibe o status da cápsula com corres que correspondem com o nível de urgência, verde = sem urgência, amarelo = alerta, vermelho = urgência. Após exibir os dados o programa retorna ao menu.

Opção 3. Exibir análise dos dados: O programa puxa a variável dadosInseridos como na opção 4, ou seja, se dadosInseridos for = 0 ele exibe erro que os dados não foram inseridos e retorna ao menu. Se dadosInseridos for = 1 o programa exibe a análise dos dados com ordem pela urgência, ou seja, se houver urgência em apenas um dos dados, o programa exibe em primeiro lugar o dado urgênte com uma mensagem de alerta, quando houver duas emergências, o programa exibe as duas com mensagem de alerta para cada uma das duas acima da terceira que não tem urgência, quando não houver urgiencia os três dados serão exibidos na ordem Temperatura, Energia e Conexão. Quando exibido o programa retorna ao menu. 