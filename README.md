# Atividade sobre Coesão em C

Projeto acadêmico desenvolvido em **C** para demonstrar, de forma prática, organizada e didática, dois tipos clássicos de coesão de módulos:

- **Coesão funcional**
- **Coesão sequencial**

O projeto foi estruturado com foco em **clareza conceitual**, **separação de responsabilidades** e **boas práticas de organização de código**, facilitando tanto a execução quanto a apresentação do trabalho.

---

## Objetivo

Implementar módulos em C que representem, de forma concreta, os conceitos de **coesão funcional** e **coesão sequencial**, com código comentado, nomes autoexplicativos e estrutura limpa.

Além de atender à proposta da atividade, o projeto também busca mostrar como princípios de **Clean Code** podem ser aplicados mesmo em programas pequenos e acadêmicos.

---

## Tipos de coesão demonstrados

### Coesão funcional

A **coesão funcional** ocorre quando todas as funções de um módulo colaboram para **um único objetivo bem definido**.

No projeto, isso foi aplicado no módulo:

- `student_performance.c`

Esse módulo concentra exclusivamente operações relacionadas à análise de desempenho de um aluno, como:

- cálculo da média
- identificação da maior nota
- identificação da menor nota
- validação da frequência
- definição da situação final
- exibição do relatório

Em outras palavras, todas as funções desse módulo existem para cumprir **uma única responsabilidade central: avaliar o desempenho acadêmico do aluno**.

### Coesão sequencial

A **coesão sequencial** ocorre quando um módulo executa uma **sequência de etapas dependentes**, em que a saída de uma etapa alimenta a próxima.

No projeto, isso foi aplicado no módulo:

- `order_pipeline.c`

Fluxo implementado:

1. inicialização do pedido processado
2. cálculo do total bruto
3. cálculo do desconto
4. cálculo do total líquido
5. definição do status final

Nesse caso, o processamento segue uma ordem lógica e encadeada, caracterizando claramente a ideia de **pipeline sequencial**.

---

## Estrutura do projeto

```text
coesao_c_project/
├── bin/
├── docs/
│   ├── Atividade_Coesao_em_C_Relatorio.docx
│   └── Atividade_Coesao_em_C_Relatorio.pdf
├── include/
│   ├── models/
│   │   ├── sales_order.h
│   │   └── student.h
│   └── modules/
│       ├── functional/
│       │   └── student_performance.h
│       └── sequential/
│           └── order_pipeline.h
├── src/
│   ├── models/
│   ├── modules/
│   │   ├── functional/
│   │   │   └── student_performance.c
│   │   └── sequential/
│   │       └── order_pipeline.c
│   └── main.c
├── Makefile
├── coesao_demo
└── README.md
```

> **Observação:** os arquivos `.h` ficam em `include/` e os arquivos `.c` ficam em `src/`, mantendo uma separação clara entre interfaces e implementações.

---

## Modelos utilizados

O projeto utiliza duas estruturas principais para representar os dados processados:

### `Student`
Representa um aluno, contendo:

- nome
- conjunto de notas
- frequência

### `SalesOrder`
Representa um pedido de venda, contendo:

- nome do cliente
- nome do produto
- quantidade
- preço unitário
- percentual de desconto

Além disso, o fluxo sequencial utiliza uma estrutura auxiliar chamada `ProcessedOrder`, responsável por armazenar os resultados intermediários e finais do processamento do pedido.

---

## Organização dos módulos

### Módulo funcional: `student_performance`

Responsável por tratar exclusivamente o contexto de desempenho acadêmico.

Exemplos de responsabilidades do módulo:

- calcular média
- buscar maior nota
- buscar menor nota
- verificar aprovação por frequência
- definir situação final do aluno
- imprimir relatório formatado

### Módulo sequencial: `order_pipeline`

Responsável por executar o processamento completo de um pedido em etapas encadeadas.

Exemplos de responsabilidades do módulo:

- preparar a estrutura de saída
- calcular valores financeiros
- aplicar desconto
- determinar total líquido
- classificar o status do pedido
- imprimir o resultado final

---

## Clean Code aplicado no projeto

Mesmo sendo um projeto acadêmico, a implementação foi organizada para seguir princípios de código limpo.

### Nomes autoexplicativos

Os nomes das funções, estruturas e arquivos foram definidos para deixar clara sua finalidade, por exemplo:

- `print_student_report`
- `process_order`
- `print_processed_order`
- `Student`
- `SalesOrder`
- `ProcessedOrder`

### Responsabilidade bem definida

Cada módulo tem um propósito claro e separado:

- o módulo funcional cuida apenas da análise do aluno
- o módulo sequencial cuida apenas do processamento do pedido

### Baixo acoplamento

Os módulos se comunicam por meio de contratos definidos nos arquivos `.h`, reduzindo dependências desnecessárias.

### Código principal simples

O `main.c` apenas organiza a demonstração dos dois módulos. Ele não concentra regras de negócio complexas, o que melhora a leitura e a manutenção.

### Estrutura modular

A divisão entre `include/` e `src/` reforça a separação entre definição e implementação, aproximando o projeto de uma organização mais profissional.

---

## Como compilar

### Opção 1 — usando GCC no PowerShell

Na raiz do projeto, execute:

```powershell
mkdir bin -ErrorAction SilentlyContinue
gcc -I./include ./src/main.c ./src/modules/functional/student_performance.c ./src/modules/sequential/order_pipeline.c -o ./bin/coesao.exe
```

### Opção 2 — usando Makefile

Se o ambiente estiver configurado com `make` ou `mingw32-make`, execute:

```bash
make
```

ou:

```bash
mingw32-make
```

---

## Como executar

Após a compilação, rode:

```powershell
./bin/coesao.exe
```

Se estiver usando Makefile com alvo de execução:

```bash
make run
```

---

## Como limpar arquivos gerados

```bash
make clean
```

---

## Compatibilidade com terminal Windows

Durante os testes no Windows/PowerShell, caracteres acentuados podem aparecer incorretamente dependendo do terminal, da fonte utilizada ou da codificação em uso.

Por esse motivo, pode ser interessante manter as mensagens exibidas no console sem acentuação, por exemplo:

- `Modulo` em vez de `Módulo`
- `Media` em vez de `Média`
- `Frequencia` em vez de `Frequência`
- `Situacao` em vez de `Situação`

Isso não altera a lógica do programa, apenas melhora a compatibilidade visual da saída no ambiente de execução.

---

## Exemplo de saída

```text
Projeto demonstrativo sobre coesao em C
- Modulo 1: coesao funcional
- Modulo 2: coesao sequencial

=== RELATORIO DE DESEMPENHO DO ALUNO ===
Nome: Ana Carolina
Notas: 8.5 | 7.0 | 9.0 | 6.5
Media: 7.75
Maior nota: 9.0
Menor nota: 6.5
Frequencia: 92.0%
Situacao final: Aprovado

=== RESULTADO DO PROCESSAMENTO SEQUENCIAL ===
Cliente: Carlos Henrique
Produto: Notebook para estudo
Quantidade: 2
Preco unitario: R$ 350.00
Total bruto: R$ 700.00
Desconto: R$ 70.00
Total liquido: R$ 630.00
Status: Aprovado com prioridade
```

---

## Relação entre teoria e prática

| Tipo de coesão | Arquivo principal | Aplicação prática |
|---|---|---|
| Funcional | `student_performance.c` | Todas as funções do módulo trabalham para o mesmo objetivo: avaliar o desempenho do aluno |
| Sequencial | `order_pipeline.c` | O processamento ocorre em etapas encadeadas, em que uma depende do resultado da anterior |

---

## Possíveis evoluções

Como extensão futura, o projeto poderia receber melhorias como:

- leitura de dados pelo teclado
- cadastro de múltiplos alunos
- processamento de múltiplos pedidos
- separação de testes automatizados
- gravação de relatórios em arquivo
- menu interativo no terminal

---
<<<<<<< HEAD

## Conclusão

O projeto atende à proposta da atividade ao demonstrar, de forma objetiva e prática, dois tipos importantes de coesão em C.

Além de ilustrar os conceitos teóricos, a implementação também evidencia a importância de organizar o código em módulos bem definidos, com responsabilidades claras e fluxo de execução fácil de entender.

---
=======
>>>>>>> ec79e5dc5c6317c7979f1094e7c007a8c71b9513
