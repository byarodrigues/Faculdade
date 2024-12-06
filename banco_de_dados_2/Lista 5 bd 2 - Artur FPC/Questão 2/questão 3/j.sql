SELECT EXTRACT(year FROM data) || '-' || DATE_PART('month', data) AS mes,
         SUM(vp.quantidade) AS Faturamento_mensal
  FROM venda AS v,
       venda_produto AS vp
  WHERE v.id_venda = vp.id_venda
  GROUP BY EXTRACT(year FROM data) || '-' || DATE_PART('month', data);