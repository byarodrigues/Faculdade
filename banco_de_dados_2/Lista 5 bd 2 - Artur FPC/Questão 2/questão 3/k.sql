CREATE TEMP TABLE media AS
WITH mm as (
  SELECT vp.id_produto,
         EXTRACT(year FROM data) || '-' || DATE_PART('month', data) AS mes,
         AVG(vp.quantidade) AS media
  FROM venda AS v,
       venda_produto AS vp
  WHERE v.id_venda = vp.id_venda
  GROUP BY id_produto, EXTRACT(year FROM data) || '-' || DATE_PART('month', data)
)
SELECT id_produto,
       AVG(media) AS media
FROM mm
GROUP BY id_produto;

ALTER TABLE produto ADD estoque_minimo REAL;

UPDATE produto AS p
SET estoque_minimo = m.media * 0.5
FROM media AS m
WHERE m.id_produto = p.id_produto;