select f.id_fornecedor,
    f.den_fornecedor,
    count(*) as contas_a_pagar
from fornecedor as f,
    conta_pagar as cp
where f.id_fornecedor = cp.id_fornecedor
GROUP BY f.id_fornecedor
HAVING count(*)>10;