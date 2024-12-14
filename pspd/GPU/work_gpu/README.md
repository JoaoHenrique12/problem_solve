# Arquitetura de GPUs 

time_video: 26:32
            45:00

pat. 45
pag. 62

- Neste tópico, abordar os tópicos de interesse, mas incluir, na apresentação, pelo menos os seguintes pontos:

a. Comparação entre arquiteturas de CPUs e GPUs - deixar claro quais as diferenças
essenciais entre uma arquitetura convencional de CPU e de uma GPU genérica.

b. Evolução das arquiteturas 
- explicar principais características desde primeira geração até a mais recente
- enfoque nos mecanismos disponíveis para o paralelismo tais como 
  - pipeline gráfico e 
  - outras caracterísHcas do hardware que sejam relevantes para a compreensão sobre como GPUs produzem melhorias de performance

## ANS

- ao inves da quantidade de transistors traduzir em um processador mais rapido ele traduz em mais processadores;
- parede de memoria, energia, pipeline;
- toda computacao grafica acontece seguindo o mesmo conjunto de passos;
  - qualquer poligono pode ser composto por uma coleção de triangulos; processo chamado de triangulação
- CPU
  - Large cache and sophisticated flow control minimize latency for arbitrary memory access for serial process

- GPU
  - Simple flow control and limited cache, more transistors for computing in parallel
  - high arithmetic intensity hides memory latency
  -> Nao tem que gastar espaco com controle e com cache
  - FODEU: float, if, double, int, operacao boleana
- GPU-friendly problems
  - High arithmetic intensity
    - computation must offset memory latency
  - Coherent data access (e.g. structured grids)
    - maximize memory band width
  - Data parallel processing
    - same computation over large datasets
      - jacobi updates
- GPGPU
  - Dealing with graphics API
    - working with the corner cases of the graphics API
  - Addressing modes
    - limited texture size/dimension
  - Shader capabilities
    - limited outputs
  - instruction sets
    - lack of integer & bit operations
  - limited communication
    - between pixels
- NVIDIA G80
- Unified Shader processor architecture

- nao tem custo de escalonamento, isso e feito pelo hardware internamente

- highly parallel coprocessor
  - has its own dram memory
  - communicate with host cpu through bus (PCIx)
  - runs many threads in parallel
  - GPU threads are extremely lightweight
  - GPU needs at least thousands threads for full efficiency

a.

As GPUs surgiram com um objetivo principal: acelerar a renderização de gráficos em computadores. No início, essa necessidade era
impulsionada principalmente pelo crescente mercado de jogos eletrônicos, que demandava cada vez mais realismo e complexidade visual.
Embora os jogos tenham sido um dos principais motivadores para o desenvolvimento das GPUs, suas capacidades de processamento paralelo
e alta performance as tornaram ferramentas indispensáveis em diversas outras áreas.

As principais áreas de aplicação delas, fora jogos eletrônicos são: computação científica, que são utilizadas para acelerar simulações
complexas, como modelagem molecular, análise de dados e aprendizado de máquina; inteligência artificial, onde são fundamentais para o
treinamento de redes neurais e o desenvolvimento de algoritmos de aprendizado profundo; visualização de dados, sendo utilizadas para criar
visualizações interativas de grandes conjuntos de dados, facilitando a análise e a compreensão de informações complexas; edição de vídeo,
aceleram o processamento de vídeos, permitindo a aplicação de efeitos especiais e a renderização de vídeos em alta resolução.

A principal diferença entre a arquitetura de GPUs e CPUs reside na forma como elas processam informações.
As CPUs são projetadas para executar uma variedade de tarefas de forma sequencial, sendo versáteis que podendo lidar com diversas instruções
complexas; possuindo poucos núcleos, mas cada núcleo é poderoso e capaz de executar tarefas de forma independente.
Enquanto que GPUs são especializadas em tarefas paralelas, possuindo milhares de núcleos menores, cada um responsável por executar
uma parte de uma tarefa maior. Essa arquitetura paralela as torna extremamente eficientes em cálculos repetitivos e tarefas que podem ser
divididas em pequenos pedaços, como renderização gráfica e cálculos de matriz.
Diante disso, tem-se que GPUs atuam como coprocessadores para as CPUS, dada a sua natureza de execução para tarefas especializadas.

imagem_cpu_gpu

- cpus tem cache, poucas ulas, executam fora de ordem, previsao de devio, logica de controle complicada, so uma porcao pequena e usada para fazer contas
- a memoria da gpu e pouca, dado que é lido um grande conjunto de dados de uma vez e existe um barramento grande para disponibilização para ula, e não
há calculos de controle, sobrando muita área para as ULAS;
- O ponto é que não é qualquer problema que pode ser executado por uma gpu, e.g. acesso randomico a memória, controle, IF, int, double, &&.
- SIMD (single instruction multiple data), computação com grande paralelismo de dados;

As GPUs possuem milhares de núcleos de processamento menores e mais simples. Portanto, para que uma GPU funcione de forma eficiente, é necessário
que o problema a ser resolvido possa ser dividido em muitos cálculos simples e independentes. Além disso, o acesso à memória deve ser eficiente,
pois a comunicação entre a CPU e a GPU pode ser um gargalo. Problemas que envolvem grandes quantidades de dados e cálculos repetitivos, como a
atualização de matrizes em simulações científicas, como o calculo de jacobiano são ideais para serem executados em GPUs.

As GPUs possuem algumas limitações em comparação com as CPUs. Elas são menos eficientes em tarefas sequenciais e complexas, e possuem um conjunto
de instruções mais limitado. Além disso, a programação de GPUs pode ser mais complexa do que a programação de CPUs, pois exige entendimento de como
paralelizar as tarefas e como otimizar o uso da memória.


O pipeline gráfico é o coração de uma GPU, e é responsável por transformar dados geométricos em imagens visíveis na tela.

Para compreende-lo, tem-se que observar que o modelo geométrico renderizado é decomposto em um conjunto de véritces; que formam superfícies de
triângulos, com eles formados, são feitos cálculos da sua normal, como eles interagem com a luz, os seus ângulos de reflexão, etc; em seguida
é calculada a cor de cada pixel; por conseguinte são juntos os diversos triângulos para formar a imagem, considerando a posição de cada elemento
no modelo, e.g. se uma boneca está atrás de uma caixa, deve-se renderizar apenas a caixa; e, por fim joga-se estas informações pocessadas na memória.

imagem_pipeline

Os triângulos são usados para compor as outras figuras geométricas convexas que formam o modelo. A explicação do uso de triângulos é dada pelo
teorema de triangulação, que diz que qualquer figura convexa pode ser decomposta por uma coleção de triangulos. Ademais estas operações descritas
necessitam apenas de cálculos de multiplicação e soma, por isto as arquiteturas iniciais tinham ULAS que cingiam apenas operações (and, or) em dados
inteiros.

Arquitetura geforce 6800

geforce_6800_arch

A GeForce 6800 foi um marco na história das placas de vídeo, introduzindo diversas inovações que moldaram o futuro da computação gráfica. Essa GPU, baseada
na arquitetura NV40, foi a primeira a oferecer suporte ao DirectX 9.0c, trazendo recursos como pixel shaders 3.0 e vertex shaders 3.0, que permitiam efeitos
visuais mais realistas e complexos nos jogos. A NV40 introduziu um conjunto de unidades de processamento escaláveis, permitindo que a NVIDIA criasse diferentes
variantes da GeForce 6800 com diferentes níveis de desempenho. Ela utilizava memória GDDR3, oferecendo maior largura de banda em comparação com as gerações
anteriores. Ela estabeleceu um novo padrão de desempenho para placas de vídeo, popularizando recursos como anti-aliasing, anisotropia e efeitos de pós-processamento.
Seu sucesso impulsionou a adoção de placas de vídeo de alta performance em PCs para jogos e aplicações profissionais.

Design unificado

imagem_unified

O design unificado da NVIDIA, introduzido com a arquitetura G80, representou um marco na evolução das placas de vídeo. Essa abordagem inovadora trouxe uma série de benefícios
para o desempenho e a flexibilidade das GPUs. Tradicionalmente, as GPUs possuíam unidades de processamento separadas para diferentes tarefas, como vértices, pixels e geometria.
No design unificado, esses diferentes tipos de unidades são combinados em um único tipo de núcleo, chamado de shader unificado. Os shaders unificados podem ser configurados
dinamicamente para executar diferentes tipos de tarefas, permitindo que a GPU adapte-se a diferentes cargas de trabalho de forma mais eficiente. A unificação dos shaders permite
um melhor balanceamento de carga, otimizando o uso dos recursos da GPU. Além disso, a ausência de unidades especializadas simplifica a arquitetura e reduz o consumo de energia.
O modelo de programação unificado facilita o desenvolvimento de novos algoritmos e aplicações, permitindo que os desenvolvedores aproveitem ao máximo o potencial da GPU.

imagem_g80

A G80 foi a primeira arquitetura a suportar o Shader Model 4.0, que trouxe uma série de novos recursos, como unificação dos shader vertex shaders e pixel shaders passaram a compartilhar os mesmos
recursos de hardware, aumentando a flexibilidade e o desempenho; geometry shaders: permitiram a manipulação da geometria em tempo real, abrindo novas possibilidades para efeitos visuais complexos;
compute shaders: tornaram as gpus mais versáteis, permitindo a execução de cálculos gerais, além das tarefas gráficas tradicionais. 

A G80 foi a primeira GPU a utilizar a arquitetura Tesla, que proporcionou um aumento significativo no desempenho e eficiência energética. Além de formecer suporte ao DirectX 10, que
permitiu a criação de jogos com gráficos mais realistas e detalhados, com efeitos como HDR (High Dynamic Range) e anti-aliasing adaptativo. Por fim, ela também introduziu o CUDA,
que é a plataforma de programação paralela que permitiu o desenvolvimento de aplicações científicas e de alto desempenho; e o physx, tecnologia de física em tempo real que tornou os jogos mais 
realistas e interativos.





### Referencias

ESCOLA DE VERÃO - CIÊNCIA DA COMPUTAÇÃO - UFMG. Programação em GPU parte 1/2. 2014. Disponível em: https://www.youtube.com/watch?v=va5BQaPTO9U&ab_channel=EscoladeVer%C3%A3o-Ci%C3%AAnciadaComputa%C3%A7%C3%A3o-UFMG. Acesso em: 10/12/2024.
COOK, S. CUDA Programming: A Developer’s Guide to Parallel Computing with GPUs. 2013. Elsevier Inc.
Hague, James (September 10, 2013). "Why Do Dedicated Game Consoles Exist?". Programming in the 21st Century. Archived from the original on May 4, 2015. Retrieved November 11, 2015.
CASELLA, George, e BERGER, Roger L. Inferência estatística - tradução da segunda edição norte-americana. São Paulo: Centage Learning, 2010. ISBN 978-85-221-0894-7. Página 142 e 192.
FERNANDES, C. G. Geometria Computacional. Apresentação realizada no Departamento de Ciência da Computação, IME-USP, São Paulo, 2º sem. 2009. Slides. Disponível em https://www.ime.usp.br/~cris/aulas/09_2_331/slides/aula3.pdf
