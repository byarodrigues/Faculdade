select v.id_venda
from produto as p, 
    venda_produto as vp, 
    venda as v, 
    conta_receber as cr
where (v.id_venda = vp.id_venda)
    and (vp.id_produto = p.id_produto)
    and (v.data >= '2011-01-01')
    and (v.data <= '2011-12-31')
    and (cr.id_venda = v.id_venda)
GROUP BY (v.id_venda)
HAVING (count(*)>=5);