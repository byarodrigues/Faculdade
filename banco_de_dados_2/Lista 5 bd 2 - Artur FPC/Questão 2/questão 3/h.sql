select * from((select c.id_cliente, 
    SUM(cr.valor) as valor
from cliente as c,
    conta_receber as cr
where (c.id_cliente = cr.id_cliente)
    and (cr.pago = 'N')
GROUP BY (c.id_cliente)
ORDER BY (c.id_cliente))
UNION ALL
((select id_cliente, 0 
from cliente)
EXCEPT ALL
(select c.id_cliente, 0
from cliente as c,
    conta_receber as cr
where (c.id_cliente = cr.id_cliente)
    and (cr.pago = 'N')
GROUP BY (c.id_cliente))))
as consulta 
ORDER BY (consulta.id_cliente);
