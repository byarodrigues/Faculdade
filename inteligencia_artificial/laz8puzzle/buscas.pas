unit Buscas;

{$mode objfpc}{$H+}

interface

uses
  Arvores, AvgLvlTree, Classes, Estados, Forms, Solucoes, SysUtils;

var
  Buscando: boolean;

function BuscaAEstrelaEstado(EstadoInicial: TEstado): TSolucao;
function BuscaLarguraTransposicao(EstadoInicial: TEstado): TSolucao;
function BuscaProfundidadeTransposicao(EstadoInicial: TEstado): TSolucao;
function BuscaProfundidadeLimitadaTransposicao(EstadoInicial: TEstado; Limite: integer): TSolucao;
function BuscaAprofundamentoIterativoTransposicao(EstadoInicial: TEstado): TSolucao;
function BuscaLargura(EstadoInicial: TEstado): TSolucao;
function BuscaProfundidade(EstadoInicial: TEstado): TSolucao;
function BuscaProfundidadeLimitada(EstadoInicial: TEstado; Limite: integer): TSolucao;
function BuscaAprofundamentoIterativo(EstadoInicial: TEstado): TSolucao;

implementation

// Busca em largura com tabela de transposicao
function BuscaLarguraTransposicao(EstadoInicial: TEstado): TSolucao;
var
  Solucao: TSolucao;
  Sucessores: TList;
  No, NoFilho: TNo;
  Estado: TEstado;
  Cont: integer;
begin
  // Inicializa a solução
  No := TNo.Create(EstadoInicial);
  Solucao := TSolucao.Create(No);
  Solucao.ContaNoGerado(1);
  // Testa se o nó inicial é meta
  if (No.Estado.TestaMeta()) then begin
    No.Visitado := True;
    Solucao.NoMeta := No;
  end else begin
    Solucao.AdicionaListaEspera(No);
    while not (Solucao.NoMeta <> nil) and not (Solucao.Falha) and (Buscando) do begin
      Application.ProcessMessages();
      // Se a lista de espera for vazia, retorna falha
      if (Solucao.NumNosGerados = 0) then begin
        Solucao.Falha := True;
        No := nil;
        Break;
      end;
      // Pega o nó mais raso
      No := Solucao.RemovePrimeiroListaEspera();
      Solucao.AdicionaListaVisitados(No);
      // Para cada sucessor do nó atual
      Sucessores := No.Estado.CreateSucessores();
      for Cont := 0 to Sucessores.Count - 1 do begin
        Estado := TEstado(Sucessores.Items[Cont]);
        NoFilho := TNo.Create(No, Estado);
        // Testa se o filho já está foi gerado antes
        if (Solucao.ProcuraListaEspera(NoFilho) = nil) and
          (Solucao.ProcuraListaVisitado(NoFilho) = nil) then begin
          No.Filhos.Add(NoFilho);
          // Testa se o filho é meta
          if (NoFilho.Estado.TestaMeta()) then begin
            No := NoFilho;
            Solucao.NoMeta := No;
            Break;
          end else begin
            // Se não for meta adiciona na lista de espera
            Solucao.AdicionaListaEspera(NoFilho);
          end;
        end else begin
          // Se o filho já está nos visitados ou na espera, ele é destruído
          NoFilho.Free();
        end;
      end; // Fim for Cont
      Sucessores.Free();
    end; // fim while not
  end;
  Result := Solucao;
end;

// Busca em largura
function BuscaLargura(EstadoInicial: TEstado): TSolucao;
var
  Solucao: TSolucao;
  Sucessores: TList;
  No, NoFilho: TNo;
  Estado: TEstado;
  Cont: integer;
begin
  // Inicializa a solução
  No := TNo.Create(EstadoInicial);
  Solucao := TSolucao.Create(No);
  // Testa se o nó inicial é meta
  if (No.Estado.TestaMeta()) then begin
    No.Visitado := True;
    Solucao.NoMeta := No;
  end else begin
    Solucao.AdicionaListaEspera(No);
    while not (Solucao.NoMeta <> nil) and not (Solucao.Falha) and (Buscando) do begin
      Application.ProcessMessages();
      // Se a lista de espera for vazia, retorna falha
      if (Solucao.NumNosGerados = 0) then begin
        Solucao.Falha := True;
        No := nil;
        Break;
      end;
      // Pega o nó mais raso
      No := Solucao.RemovePrimeiroListaEspera();
      No.Visitado := True;
      Solucao.ContaNoVisitado(1);
      // Para cada sucessor do nó atual
      Sucessores := No.Estado.CreateSucessores();
      for Cont := 0 to Sucessores.Count - 1 do begin
        Estado := TEstado(Sucessores.Items[Cont]);
        NoFilho := TNo.Create(No, Estado);
        // Testa se o filho já está foi gerado antes
        if (Solucao.ProcuraListaEspera(NoFilho) = nil) then begin
          No.Filhos.Add(NoFilho);
          Solucao.ContaNoGerado(1);
          // Testa se o filho é meta
          if (NoFilho.Estado.TestaMeta()) then begin
            No := NoFilho;
            Solucao.NoMeta := No;
            Break;
          end else begin
            // Se não for meta adiciona na lista de espera
            Solucao.AdicionaListaEspera(NoFilho);
          end;
        end;
      end; // Fim for Cont
      Sucessores.Free();
    end; // fim while not
  end;
  Result := Solucao;
end;


// Busca em profundidade limitada recursiva com tabela de transposição
procedure BuscaProfundidadeLimitadaRecursivaTransposicao(var No: TNo; var Solucao: TSolucao;
  Limite: integer);
var
  Sucessores: TList;
  NoFilho, NoFilhoAnt: TNo;
  Estado: TEstado;
  Cont: integer;
  NoBuscado: TNo;
begin
  Solucao.AdicionaListaVisitados(No);
  Application.ProcessMessages();
  if (Buscando) then begin
    // Testa se o nó é meta
    if (No.Estado.TestaMeta()) then begin
      Solucao.NoMeta := No;
    // Testa se o nó atingiu o limite de profundidade
    end else if (No.G = Limite) then begin
      Solucao.Corte := True;
    end else begin
      // Para cada sucessor do nó
      Sucessores := No.Estado.CreateSucessores();
      NoFilhoAnt := nil;
      for Cont := 0 to Sucessores.Count - 1 do begin
        Estado := TEstado(Sucessores.Items[Cont]);
        NoFilho := TNo.Create(No, Estado);
        NoBuscado := Solucao.ProcuraListaVisitado(NoFilho);
        // Testa se o filho não foi gerando ou se está em uma profundidade menor
        if (NoBuscado = nil) or (NoBuscado.G > NoFilho.G) then begin
          // Se o irmão anterior não encontrou a solução, o mesmo é podado
          if (NoFilhoAnt <> nil) then begin
            Solucao.Poda(NoFilhoAnt);
          end;
          NoFilhoAnt := NoFilho;
          No.Filhos.Add(NoFilho);
          BuscaProfundidadeLimitadaRecursivaTransposicao(NoFilho, Solucao, Limite);
          // Se a solução foi encontrada então para
          if (Solucao.NoMeta <> nil) then begin
            Break;
          end;
        end else begin
          NoFilho.Free();
        end;
      end;
      Sucessores.Free();
    end;
  end;
end;

// Busca em profundidade limitada recursiva
procedure BuscaProfundidadeLimitadaRecursiva(var No: TNo; var Solucao: TSolucao;
  Limite: integer);
var
  Sucessores: TList;
  NoFilho, NoFilhoAnt: TNo;
  Estado: TEstado;
  Cont: integer;
  NoBuscado: TNo;
begin
  Application.ProcessMessages();
  No.Visitado := True;
  Solucao.ContaNoVisitado(1);
  if (Buscando) then begin
    // Testa se o nó é meta
    if (No.Estado.TestaMeta()) then begin
      Solucao.NoMeta := No;
    // Testa se o nó atingiu o limite de profundidade
    end else if (No.G = Limite) then begin
      Solucao.Corte := True;
    end else begin
      // Para cada sucessor do nó
      Sucessores := No.Estado.CreateSucessores();
      NoFilhoAnt := nil;
      for Cont := 0 to Sucessores.Count - 1 do begin
        Estado := TEstado(Sucessores.Items[Cont]);
        NoFilho := TNo.Create(No, Estado);
        NoBuscado := Solucao.ProcuraListaVisitado(NoFilho);
        // Se o irmão anterior não encontrou a solução, o mesmo é podado
        if (NoFilhoAnt <> nil) then begin
          Solucao.Poda(NoFilhoAnt);
        end;
        NoFilhoAnt := NoFilho;
        No.Filhos.Add(NoFilho);
        Solucao.ContaNoGerado(1);
        BuscaProfundidadeLimitadaRecursiva(NoFilho, Solucao, Limite);
        // Se a solução foi encontrada então para
        if (Solucao.NoMeta <> nil) then begin
          Break;
        end;
      end;
      Sucessores.Free();
    end;
  end;
end;

// Busca em profundidade com tabela de transposicao
function BuscaProfundidadeTransposicao(EstadoInicial: TEstado): TSolucao;
var
  Solucao: TSolucao;
  No: TNo;
  Limite: integer;
begin
  // MaxInt é maior do que o número de estados do problema
  Limite := MaxInt;
  No := TNo.Create(EstadoInicial);
  Solucao := TSolucao.Create(No);
  BuscaProfundidadeLimitadaRecursivaTransposicao(No, Solucao, Limite);
  if (Solucao.NoMeta = nil) and not (Solucao.Corte) then begin
    Solucao.Falha := True;
  end;
  Solucao.ContaNoGerado(Solucao.NumNosVisitados);
  Result := Solucao;
end;

// Busca em profundidade
function BuscaProfundidade(EstadoInicial: TEstado): TSolucao;
var
  Solucao: TSolucao;
  No: TNo;
  Limite: integer;
begin
  // MaxInt é maior do que o número de estados do problema
  Limite := MaxInt;
  No := TNo.Create(EstadoInicial);
  Solucao := TSolucao.Create(No);
  Solucao.ContaNoGerado(1);
  BuscaProfundidadeLimitadaRecursiva(No, Solucao, Limite);
  if (Solucao.NoMeta = nil) and not (Solucao.Corte) then begin
    Solucao.Falha := True;
  end;
  Result := Solucao;
end;

// Busca em profundidade limitada com tabela de transposição
function BuscaProfundidadeLimitadaTransposicao(EstadoInicial: TEstado; Limite: integer): TSolucao;
var
  Solucao: TSolucao;
  No: TNo;
begin
  No := TNo.Create(EstadoInicial);
  Solucao := TSolucao.Create(No);
  BuscaProfundidadeLimitadaRecursivaTransposicao(No, Solucao, Limite);
  if (Solucao.NoMeta = nil) and not (Solucao.Corte) then begin
    Solucao.Falha := True;
  end;
  // Número de nós gerados é sempre igual áo número de nós visitados
  Solucao.ContaNoGerado(Solucao.NumNosVisitados);
  Result := Solucao;
end;

// Busca em profundidade limitada
function BuscaProfundidadeLimitada(EstadoInicial: TEstado; Limite: integer): TSolucao;
var
  Solucao: TSolucao;
  No: TNo;
begin
  No := TNo.Create(EstadoInicial);
  Solucao := TSolucao.Create(No);
  Solucao.ContaNoGerado(1);
  BuscaProfundidadeLimitadaRecursiva(No, Solucao, Limite);
  if (Solucao.NoMeta = nil) and not (Solucao.Corte) then begin
    Solucao.Falha := True;
  end;
  // Número de nós gerados é sempre igual áo número de nós visitados
  Result := Solucao;
end;


// Busca com aprofundamento iterativo com tabela de transposição
function BuscaAprofundamentoIterativoTransposicao(EstadoInicial: TEstado): TSolucao;
var
  SolucaoTentativa, Solucao: TSolucao;
  Limite: integer;
begin
  Solucao := TSolucao.Create();
  for Limite := 0 to MaxInt do begin
    SolucaoTentativa := BuscaProfundidadeLimitadaTransposicao(EstadoInicial, Limite);
    Solucao.ContaNoGerado(SolucaoTentativa.NumNosGerados);
    Solucao.ContaNoVisitado(SolucaoTentativa.NumNosVisitados);
    Solucao.ContaNoPodado(SolucaoTentativa.NumNosPodados);
    if (SolucaoTentativa.NoMeta <> nil) or not (Buscando) then begin
      Solucao.NoMeta := SolucaoTentativa.NoMeta;
      Break;
    end else begin
      SolucaoTentativa.Free();
      SolucaoTentativa.NoInicial.Free();
    end;
  end;
  Solucao.NoInicial := SolucaoTentativa.NoInicial;
  Result := Solucao;
end;

// Busca com aprofundamento iterativo
function BuscaAprofundamentoIterativo(EstadoInicial: TEstado): TSolucao;
var
  SolucaoTentativa, Solucao: TSolucao;
  Limite: integer;
begin
  Solucao := TSolucao.Create();
  for Limite := 0 to MaxInt do begin
    SolucaoTentativa := BuscaProfundidadeLimitada(EstadoInicial, Limite);
    Solucao.ContaNoGerado(SolucaoTentativa.NumNosGerados);
    Solucao.ContaNoVisitado(SolucaoTentativa.NumNosVisitados);
    Solucao.ContaNoPodado(SolucaoTentativa.NumNosPodados);
    if (SolucaoTentativa.NoMeta <> nil) or not (Buscando) then begin
      Solucao.NoMeta := SolucaoTentativa.NoMeta;
      Break;
    end else begin
      SolucaoTentativa.Free();
      SolucaoTentativa.NoInicial.Free();
    end;
  end;
  Solucao.NoInicial := SolucaoTentativa.NoInicial;
  Result := Solucao;
end;

// Busca A*
function BuscaAEstrelaEstado(EstadoInicial: TEstado): TSolucao;
var
  Solucao: TSolucao;
  Sucessores: TList;
  No, NoFilho, NoVisitado, NoBuscado: TNo;
  NoAvgEspera: TAvgLvlTreeNode;
  Estado: TEstado;
  Cont: integer;
  NoUsado: boolean;
begin
  // Inicializa a solução
  No := TNo.Create(EstadoInicial);
  Solucao := TSolucao.Create(No);
  Solucao.AdicionaFilaEspera(No);
  while not (Solucao.NoMeta <> nil) and not (Solucao.Falha) do begin
    Application.ProcessMessages();
    if (Solucao.QuantidadeFilaEspera() = 0) then begin
      Solucao.Falha := True;
      No := nil;
      Break;
    end;
    // Pega o com menor custo
    No := Solucao.NoMenorCusto();
    Solucao.AdicionaListaVisitados(No);
    if (No.Pai <> nil) then begin
      No.Pai.Filhos.Add(No);
    end;
    if (No.Estado.TestaMeta()) then begin
      Solucao.NoMeta := No;
      Break;
    end else begin
      // Para cada filho do nó
      Sucessores := No.Estado.CreateSucessores();
      for Cont := 0 to Sucessores.Count - 1 do begin
        Estado := TEstado(Sucessores.Items[Cont]);
        NoFilho := TNo.CreateHeuristica(No, Estado);
        NoUsado := True;
        NoAvgEspera := Solucao.ProcuraFilaEspera(NoFilho);
        NoBuscado := Solucao.ProcuraListaVisitado(NoFilho);
        // Testa se nó foi gerado pela primeira vez
        if (NoAvgEspera = nil) and (NoBuscado = nil) then begin
          Solucao.AdicionaFilaEspera(NoFilho);
          NoUsado := True;
        end else begin
          // Testa se o nó atual possui custo menor do que outro na lista de espera
          if (NoAvgEspera <> nil) and (NoFilho.F < TNo(NoAvgEspera.Data).F) then begin
            Solucao.RemoveFilaEspera(NoAvgEspera);
            Solucao.AdicionaFilaEspera(NoFilho);
            NoUsado := True;
          end;
          // Testa se existe nó visitado com custo menor que filho atual
          if (NoBuscado <> nil) then begin
            NoVisitado := NoBuscado;
            if (NoFilho.F < NoVisitado.F) then begin
              Solucao.RemoveVisitado(NoBuscado);
              Solucao.AdicionaFilaEspera(NoFilho);
              NoUsado := True;
            end;
          end;
          if not (NoUsado) then begin
            NoFilho.Free();
          end;
        end;
      end;
      Sucessores.Free();
    end;
  end;

  // Adiciona os filhos em espera restantes na lista do pai
  // Necessário apenas para desenhar a árvore
  NoAvgEspera := Solucao.PrimeiroNoAvg();
  while (NoAvgEspera <> nil) do begin
    NoFilho := TNo(NoAvgEspera.Data);
    NoFilho.Pai.Filhos.Add(NoFilho);
    NoAvgEspera := NoAvgEspera.Successor();
  end;
  Result := Solucao;
end;

end.
