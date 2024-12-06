select ci.id_cidade, 
    ci.den_cidade, 
    SUM(v.valor_total) 
from cliente as c, 
    venda as v, 
    cidade as ci 
where (v.id_cliente = c.id_cliente) 
    and (c.id_cidade = ci.id_cidade) 
GROUP BY(ci.id_cidade);