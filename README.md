# FEUP HotelAEDA

This project corresponds to part 1 of the project done in the course **Algoritmos e Estrutura de Dados**, a **2nd year course** in the **Integrated Master's Degree in Informatics and Computing Engineering @ FEUP**

## Project Specification

### Tema 9 – Gestão Hoteleira (Parte 1)
Um conceituado hotel pretende usar uma aplicação que lhe permita gerir a informação relativa à reserva de
espaços. Os espaços são reservados por um período a especificar pelo cliente e os preços da reserva dependem
da época do ano, do dia da semana, entre outros fatores específicos do espaço.
Os espaços passíveis de reserva podem ser quartos ou salas de reuniões. Os quartos podem ser simples ou
duplos, localizados na frente ou nas traseiras, o que influencia o seu preço de reserva diário. As salas de reunião
têm uma capacidade, equipamento de vídeo ou não, equipamento de áudio ou não, o que influencia o seu preço
de reserva diário.
Os funcionários podem ser supervisores ou não. Os funcionários supervisores são responsáveis por um conjunto
de espaços. Deve-se manter uma repartição equitativa de responsabilidade de espaços a supervisores.
O sistema deve conter e gerir informação sobre os espaços (quartos e salas de reunião) e sua ocupação, clientes e
funcionários.
O sistema deve permitir a consulta do conjunto de espaços existentes, sua ocupação e respetivo supervisor, do
conjunto de funcionários (supervisores e não supervisores), conjunto de clientes e respetiva frequência de
reserva de espaços. (nota: esta enumeração de listagens a implementar não é exaustiva).
Implemente outras funcionalidades que considere relevantes, para além dos requisitos globais enunciados.

### Tema 9 – Gestão Hoteleira (Parte 2)
Complemente o sistema já implementado com as seguintes funcionalidades:

* Para apoio aos seus clientes, o hotel disponibiliza informação sobre os restaurantes nas redondezas. Os
restaurantes são guardados numa. árvore binária de pesquisa ordenados por po de cozinha
(portuguesa, tapas, italiana, …) e, em caso de empate, por distância ao hotel.
* O hotel disponibiliza aos seus clientes um serviço de excursões a pontos turíscos da localidade. Para uma
gestão eficiente das carrinhas a alugar, a alocação dos lugares das carrinhas aos clientes é realizado com o
auxílio de uma fila de prioridade. As carrinhas são guardadas numa fila de prioridade, ordenadas por
número de lugares vagos (no topo da fila está a carrinha com menos lugares vagos). Os clientes do hotel
podem querer efetuar a viagem na carrinha em grupo (são amigos ou familiares) ou sozinhos. Para
determinado grupo, deve ser alocada a carrinha com menos lugares vagos suficientes para o número de
elementos do grupo.
* O hotel mantém um registo de todos os seus clientes (atuais e angos) numa tabela de dispersão. A
manutenção do registo de clientes angos do hotel jusfica-se pela políca de markeng do hotel: envio
de felicitações no seu aniversário, envio de informação sobre eventos a decorrer no hotel.

Implemente também outras funcionalidades que considere relevantes, para além dos requisitos globais
enunciados.


## Authors

* **Gonçalo Marantes** - [Marantesss](https://github.com/Marantesss)
* **João Fransisco Santos** - [ExSchYte](https://github.com/ExSchYte)
* **Luís Gonçalves** - [lalex92](https://github.com/lalex92)

## UML Diagrams

All diagrams were made using [Lucid Chart](https://www.lucidchart.com/)

<img src="https://github.com/Marantesss/feup-HotelAEDA/blob/master/AEDAHotel-part1/doc/Images/Class%20Diagram%20for%20Hotel%20Management.png" width="500"><br>
**Fig. 1: Class Diagram For Hotel Management** <br><br>

<img src="https://github.com/Marantesss/feup-HotelAEDA/blob/master/AEDAHotel-part1/doc/Images/Class%20Diagram%20for%20Hotel%20Management%20Simplified.png" width="500"><br>
**Fig. 1: Class Diagram For Hotel Management - Simplified** <br><br>


## License

This project is not licensed under any license.
