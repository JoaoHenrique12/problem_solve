# Login

ssh -p 13508 a180033620@chococino.naquadah.com.br
ssh -p 13508 a190015721@chococino.naquadah.com.br

## P1

prova: diferenca de cpu para gpu, escalonar processos em GPU, porque nao tem caches nos cores da gpu ?

- Tem cache em GPU ? L1, L2, L3...
- Escalonamento de GPU ?
- Imagem CPU e GPU, slide
- Stream Processor ?
- Greds Blocks threads ?

- por que nao usar muito threads ? Por conta de cache, eu acho

## Taxonomia de Flynn

### SISD (CPU um core)
- Single Instruction Single Data
- Most people will be familiar with follows the SISD model.
- Illusion of being able to perform more than a single task, time-slicing

### SIMD (GPU)
- Single Instruction Multiple Data
- Systems try to simplify this approach, in particular with the data parallelism model
- Removing this silicon real estate from the device, they can be smaller, cheaper, consume less power, and run at higher clock rates than their MIMD cousins.
- In effect, you are programming “for this range of data, perform this operation” instead of “for this data point, perform this operation.”
- All data points may have some fixed offset added.
- GPU takes a slightly different approach to SIMD. It implements a model NVIDIA calls SIMT (single instruction, multiple thread).

### MISD
- Multiple Instructions Single Data

### MIMD (CPU, multi core)
- Multiple Instructions Multiple Data
- MIMD are what we see today in dual- or quad-core desktop machines.

#### Fork-join patterns

- serial programming
- synchronization points and only certain aspects of the program are parallel
- OpenMP
- Typically implemented with static partitioning of the data
- Por que nao alocar o maximo de threads ? Tempo anonando e exaurimento de memoria
- This pattern is not natively supported on a GPU, as it uses a fixed number of blocks/threads at kernel launch time
- such algorithms on the GPU side are typically implemented as a series of GPU kernel launches, each of which needs to generate the next state. 

### Explanation

- Loop-based patterns 
- Tiling/grids
- Divide and conquer

- Speed up 
  - The ratio of the work or problem size executed by multiple processors to that accomplished by a single processor, when the execution time is fixed to the maximum limit.
  - This concept is related to the performance measurement of parallel computing systems. It refers to the ratio of the amount of work that can be completed by a system with multiple processors to the amount completed by a single processor, given a fixed execution time.

- Why gpus have no cache:
  - Muitos workloads de GPU são memória-bound, ou seja, a performance é limitada pela largura de banda da memória. Nesse caso, aumentar o tamanho do cache pode não trazer ganhos significativos.

### Message Moodle

Conteúdo da prova de 16/12

Caros alunos,

Na próxima segunda feira, 16/12, faremos nossa segunda avaliação individual. As dicas de estudo são as seguintes:

1. Estudar todo o conteúdo da prova anterior (introdução aos Sistemas Distribuídos, RPC, MPI)

2. Estudar Taxonomia de Flynn (SISD, SIMD, MISD, MIMD), conceito de speedup, modelo fork-join  - ver apostila Unicamp e slides Unipampa para acessar esses conteúdos; Programação OpenMP;
focar nos pragmas vistos em sala de aula e nas dicas de paralelização de códigos sequenciais (incluindo algoritmos de busca e ordenação)

3. Estudar GPUS: conceitos básicos; comparativo entre arquiteturas CPU e GPU; programação básica usando linguagem CUDA. 

4. Programação híbrida simples, usando combinações de MPI, OpenMP e CUDA

Obs1.: Foram disponibilizadas materiais novos, listas de exercícios OMP e códigos com GPU no Moodle

Obs2.: Códigos em GPU devem ser testados nas máquinas do cluster chococino.

Bons estudos.

## Quests

### Q1

(F) Mecanismos que provêem interoperabilidade entre sistemas distintos pressupõem o uso de um sistema de mensageria e um protocolo de comunicação.
Sem esses recursos não há como realizar a interoperabilidade citada

(F) No grpc as aplicações que usam protobuf enviam dados em formato binário.
Por isso, essas aplicações tem tempo de processamento melhor do que aplicações grpc que fazem uso de formatos como o JSON

(V) Num diálogo http/2, se o cliente fizer uma solicitação de recurso para o servidor, este último pode enviar não só o recurso
solicitado, mas vários outros associados (sem uma solicitação explícita) na mesma conexão . Essa característica difere o http/2 do
http/1.1.

### Q2

i = i + 10;
Nenhuma das opções

(F) A execução com o comando OMP_NUM_THREADS=4 t1 vai imprimir o valor 40
(F) Se a linha 9 for suprimida, o binário equivalente acionado com o comando OMP_NUM_THREADS=3 t1 imprimirá sempre o valor 30
(F) Se na linha 7 for acrescentada a declaração private(i) e houver supressão da linha 9, o binário equivalente acionado com o
comando OMP_NUM_THREADS=6 t1, o programa vai imprimir 60

### Q3

soma += omp_get_num_threads();
Todas estao erradas

(F) A execução com o comando OMP_NUM_THREADS=4 t1 vai imprimir que cada thread foi executada 25 vezes
(F) Se este programa for acionado tendo a variável OMP_NUM_THREADS um valor maior do que o número de núcleos da máquina,
apenas as threads equivalentes ao número de núcleos serão criadas
(F) Se o programa for executado numa máquina com 10 núcleos de processamento e a variável OMP_NUM_THREADS estiver com
valor igual a 20, o programa não será ativado

### Q4

apenas kafka e rabbitmq

### Q5

apenas a 3

(F) Se OMP_NUM_THREADS=6, na segunda região paralela desse código (linhas 13 a 18), serão geradas 10 threads e, portanto, 10
impressões (linha 17)

(F) Se a linha 15 for movida para ficar fora da região paralela (entre as linhas 11 e 13), esse código passa a ser não compilável, pois
não é possível saber o número de threads em uma região serial do código

(V) Esse código é mais apropriado para funcionar em arquiteturas UMA (Uniform Memory Access) ou de memória compartilhada do
que em arquiteturas NUMA (Non Uniform Memory Access)

### Q6

(F) RDDs (Resilient Distributed Datasets) são estruturas tipadas do Spark que podem ser alteradas por comandos python ou R
(V) As transformações (Transformations) são implementadas no Spark em modo lazy, ou seja, são executadas posteriormente, apenas
quando é instanciado uma ação (Action), visando melhoria de performance
(V) O Spark é mais rápido do que o Hadoop/Map-Reduce, porque os estágios de execução são implementados com uso intensivo de
memória ao invés de uso de disco (memória secundária).

### Q7
