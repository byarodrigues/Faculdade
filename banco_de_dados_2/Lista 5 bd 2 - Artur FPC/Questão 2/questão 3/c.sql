select ci.den_cidade, 
    p.den_produto, 
    SUM(vp.quantidade * vp.valor) 
from cidade as ci, 
    venda_produto as vp, 
    cliente as c, 
    venda as v, 
    produto as p 
where (vp.id_produto = p.id_produto) 
    and (vp.id_venda = v.id_venda) 
    and (v.id_cliente = c.id_cliente) 
    and (c.id_cidade = ci.id_cidade) 
GROUP BY(ci.id_cidade, p.id_produto) 
ORDER BY (ci.id_cidade);