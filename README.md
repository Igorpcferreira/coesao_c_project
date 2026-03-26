# Atividade sobre Coesão em C

Projeto acadêmico desenvolvido em **C** para demonstrar, de forma clara e bem estruturada, dois tipos de coesão de módulos:

- **Coesão funcional**
- **Coesão sequencial**

O objetivo deste projeto é apresentar uma implementação prática, comentada e organizada segundo princípios de **Clean Code**, com nomes descritivos, responsabilidades bem definidas, separação por módulos e fluxo de execução fácil de entender.

---

## Estrutura do projeto

```text
coesao_c_project/
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
│   ├── main.c
│   └── modules/
│       ├── functional/
│       │   └── student_performance.c
│       └── sequential/
│           └── order_pipeline.c
├── docs/
├── Makefile
└── README.md
```

---

## Conceitos aplicados

### 1. Coesão funcional
A coesão funcional acontece quando todas as funções de um módulo contribuem para **um único objetivo bem definido**.

Neste projeto, isso aparece no módulo:

- `student_performance.c`

Esse módulo existe exclusivamente para analisar o desempenho de um aluno. Todas as funções estão ligadas ao mesmo domínio:

- calcular média
- identificar maior nota
- identificar menor nota
- validar frequência
- definir situação final
- imprimir relatório

Ou seja, o módulo tem **uma responsabilidade central: avaliar o desempenho acadêmico do aluno**.

### 2. Coesão sequencial
A coesão sequencial acontece quando as etapas de um módulo seguem uma **sequência lógica**, em que o resultado de uma função serve de base para a próxima.

Neste projeto, isso aparece no módulo:

- `order_pipeline.c`

Fluxo implementado:

1. inicializar o pedido processado
2. calcular total bruto
3. calcular desconto
4. calcular total líquido
5. definir status final

Cada etapa depende da anterior. Por isso, o módulo representa claramente a ideia de **pipeline sequencial**.

---

## Como compilar

Na raiz do projeto, execute:

```bash
make
```

## Como rodar

```bash
make run
```

## Como limpar os arquivos gerados

```bash
make clean
```

---

## Exemplo de saída esperada

```text
Projeto demonstrativo sobre coesão em C
- Módulo 1: coesão funcional
- Módulo 2: coesão sequencial

=== RELATÓRIO DE DESEMPENHO DO ALUNO ===
Nome: Ana Carolina
Notas: 8.5 | 7.0 | 9.0 | 6.5
Média: 7.75
Maior nota: 9.0
Menor nota: 6.5
Frequência: 92.0%
Situação final: Aprovado

=== RESULTADO DO PROCESSAMENTO SEQUENCIAL ===
Cliente: Carlos Henrique
Produto: Notebook para estudo
Quantidade: 2
Preço unitário: R$ 350.00
Total bruto: R$ 700.00
Desconto: R$ 70.00
Total líquido: R$ 630.00
Status: Aprovado com prioridade
```

---

## Decisões de Clean Code aplicadas

Este projeto foi estruturado para ficar didático e fácil de manter.

### Nomes autoexplicativos
Foram usados nomes que deixam claro o papel de cada item:

- `calculate_average`
- `find_highest_score`
- `process_order`
- `define_order_status`

### Pequenas responsabilidades
Cada função executa uma tarefa específica.

### Separação por domínio
Os modelos foram separados em arquivos próprios:

- `student.h`
- `sales_order.h`

### Baixo acoplamento
Os módulos interagem por meio de structs e contratos definidos em arquivos `.h`.

### Leitura simples
O `main.c` não contém regra de negócio complexa. Ele apenas orquestra a demonstração dos dois tipos de coesão.

---

## Resumo da relação entre teoria e prática

| Tipo de coesão | Arquivo principal | Como foi aplicado |
|---|---|---|
| Funcional | `student_performance.c` | Todas as funções servem ao mesmo objetivo: avaliar o desempenho do aluno |
| Sequencial | `order_pipeline.c` | As funções seguem uma cadeia de processamento, onde uma etapa alimenta a próxima |

---

## Possíveis melhorias futuras

Caso o professor ou a dupla queira evoluir o projeto, algumas extensões possíveis são:

- leitura de dados pelo teclado
- cadastro de vários alunos
- processamento de múltiplos pedidos
- testes automatizados em C
- geração de relatórios em arquivo

---

## Autor

Projeto preparado para fins acadêmicos, com foco em clareza conceitual, boa organização e facilidade de apresentação.
