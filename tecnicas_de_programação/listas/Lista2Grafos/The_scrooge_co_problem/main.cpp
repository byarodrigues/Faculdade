#include <iostream>
/*
A empresa de entrega Scrooge Co. quer estabelecer um sistema para pagar aos seus funcionários o mínimo de dinheiro em seus viagens. A empresa tem informações sobre qual é o custo mínimo para ir de uma localidade para outra.

Eles solicitam a sua solução para calcular o valor mínimo de dinheiro que um funcionário receberá para ir de uma localidade para outra e qual é a rota que ele deve usar para chegar.

Entrada
A entrada começa com um único número inteiro 1 ≤ C ≤ 99 em uma linha por si só, indicando o número de casos de teste subsequentes, cada um deles descrito abaixo.

Para cada caso de teste, a primeira linha tem um número inteiro 1 ≤ P ≤ 99, indicando o número de localidades que consideramos para este caso. A segunda linha nos dá o nome de cada localidade separado por uma TAB, cada nome tem no máximo 20 caracteres. As próximas P linhas contêm o custo mínimo para ir de uma localidade para outra separadas por uma TAB, a primeira linha tem os custos entre a primeira localidade e o resto, a segunda linha são os custos entre a segunda localidade e o resto, e assim por diante. Um custo é um inteiro -1 ≤ W ≤ 300, onde -1 significa que é uma viagem muito cara entre as localidades, e 0 é usado para indicar o custo de uma localidade para a mesma localidade. Após as P linhas, há um número inteiro 1 ≤ R ≤ 99, indicando o número de rotas que devemos considerar. Seguem R linhas contendo o nome do funcionário, a localidade de origem e a localidade de destino. Os nomes das localidades são sensíveis a maiúsculas e minúsculas e o nome do funcionário tem no máximo 30 caracteres.

Saída
Para cada caso de teste, você deve produzir uma ou duas linhas de saída. Se existir uma rota entre as localizações, você produzirá duas linhas, uma com o custo e outra com o caminho, seguindo o seguinte formato:

"Mr <nome do funcionário> para ir de <nome orig> para <nome dest>, você receberá <custo mínimo> euros"
"Caminho: <nome orig> <locais separados por um espaço em branco> <nome dest>"

Se não houver uma rota entre as localizações, você produzirá uma linha, seguindo o seguinte formato:

"Desculpe Mr <nome do funcionário>, você não pode ir de <nome orig> para <nome loc>"

Se houver dois caminhos mínimos possíveis entre A e B e ambos tiverem vértices intermediários, a preferência é para o caminho que aparece antes na entrada, por exemplo:

Se a entrada for: A B C D E F, o caminho "A C D B" tem mais prioridade do que o caminho "A E B" (já que E aparece depois de D) e o caminho "A D E B" tem mais prioridade do que "A C F B" (porque F aparece depois de E). Essa análise é feita olhando a ordem dos vértices intermediários.
*/
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
