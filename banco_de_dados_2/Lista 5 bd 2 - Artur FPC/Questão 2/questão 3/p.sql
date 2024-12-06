create temporary table qtd_p_ano_mes as 
select EXTRACT (month from v.data) as mes, 
    EXTRACT(year from v.data) as ano, 
    SUM(vp.quantidade) as quant
from venda as v,
    venda_produto as vp
where (v.id_venda = vp.id_venda)
GROUP BY (EXTRACT(year from v.data),
    EXTRACT (month from v.data));
select *
from qtd_p_ano_mes
where (quant = (select MAX(quant) from qtd_p_ano_mes));