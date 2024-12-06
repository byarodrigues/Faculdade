unit Solucoes;

{$mode objfpc}{$H+}

interface

uses
  Arvores, AvgLvlTree, Classes, SysUtils;

type
  { TSolucao }

  TSolucao = class
  private
    FListaVisitados: TList; // Lista de estados visitados
    FListaEspera: TList; // Lista de estados gerados (busca cega)
    FFilaEspera: TAvgLvlTree; // Árvore de estados gerados (busca heurística)
    FNumNosGerados: integer;
    FNumNosVisitados: integer;
    FNumNosPodados: integer;
    function ProcuraLista(L: TList; No: TNo): TNo;
    function ProcuraListaPosicao(L: TList; No: TNo): integer;
  public
    Falha: boolean;
    Corte: boolean;
    NoMeta: TNo; // Nó com estado da solução
    NoInicial: TNo; // Nó com estado inicial
    InicioBusca: TDateTime;
    TerminoBusca: TDateTime;
    constructor Create();
    constructor Create(NoIni: TNo);
    destructor Destroy(); override;
    function NoMenorCusto(): TNo;
    function PrimeiroNoAvg(): TAvgLvlTreeNode;
    function ProcuraFilaEspera(No: TNo): TAvgLvlTreeNode;
    function ProcuraListaVisitado(No: TNo): TNo;
    function ProcuraListaEspera(No: TNo): TNo;
    procedure LimpaListasFila();
    procedure AdicionaListaVisitados(No: TNo);
    procedure AdicionaListaEspera(No: TNo);
    procedure ContaNoGerado(Incremento: integer);
    procedure ContaNoVisitado(Incremento: integer);
    procedure ContaNoPodado(Incremento: integer);
    procedure Poda(No: TNo);
    function RemovePrimeiroListaEspera(): TNo;
    function RemoveUltimoListaEspera(): TNo;
    procedure AdicionaFilaEspera(No: TNo);
    function QuantidadeFilaEspera(): integer;
    procedure RemoveFilaEspera(NoAvg: TAvgLvlTreeNode);
    procedure RemoveVisitado(No: TNo);
    property NumNosGerados: integer read FNumNosGerados;
    property NumNosVisitados: integer read FNumNosVisitados;
    property NumNosPodados: integer read FNumNosPodados;
  end;

implementation

{ TNo }

function ComparaNos(No1, No2: Pointer): integer;
begin
  Result := TNo(No1).F - TNo(No2).F;
end;

{ TSolucao }

constructor TSolucao.Create(NoIni: TNo);
begin
  Self := TSolucao.Create();
  NoInicial := NoIni;
end;

destructor TSolucao.Destroy();
begin
  LimpaListasFila();
  FListaVisitados.Free();
  FListaEspera.Free();
  FFilaEspera.Free();
  NoInicial := nil;
  NoMeta := nil;
  inherited Destroy;
end;

function TSolucao.NoMenorCusto(): TNo;
var
  N: TAvgLvlTreeNode;
begin
  // Pega o nó com menor custo
  N := Self.FFilaEspera.FindLowest();
  // Retorna o dado do nó
  Result := TNo(N.Data);
  // Remove o nó
  Self.FFilaEspera.Delete(N);
end;

function TSolucao.PrimeiroNoAvg: TAvgLvlTreeNode;
begin
  Result := Self.FFilaEspera.FindLowest();
end;

function TSolucao.ProcuraFilaEspera(No: TNo): TAvgLvlTreeNode;
var
  N: TAvgLvlTreeNode;
  NoAtual: TNo;
  Encontra: boolean;
begin
  // Pega o nó com menor custo
  N := Self.FFilaEspera.FindLowest();
  Encontra := False;
  while (N <> nil) and not (Encontra) do begin
    NoAtual := TNo(N.Data);
    if (NoAtual.Estado.Igual(No.Estado)) then begin
      Encontra := True;
    end else begin
      // Próximo nó (com próximo custo)
      N := N.Successor();
    end;
  end;
  Result := N;
end;

function TSolucao.ProcuraListaVisitado(No: TNo): TNo;
begin
  Result := ProcuraLista(FListaVisitados, No);
end;

function TSolucao.ProcuraListaEspera(No: TNo): TNo;
begin
  Result := ProcuraLista(FListaEspera, No);
end;

procedure TSolucao.LimpaListasFila;
begin
  FListaEspera.Clear();
  FListaVisitados.Clear();
  FFilaEspera.Clear();
end;

procedure TSolucao.AdicionaListaVisitados(No: TNo);
begin
  No.Visitado := True;
  FListaVisitados.Add(No);
  Inc(FNumNosVisitados);
end;

procedure TSolucao.AdicionaListaEspera(No: TNo);
begin
  FListaEspera.Add(No);
  Inc(FNumNosGerados);
end;

procedure TSolucao.ContaNoGerado(Incremento: integer);
begin
  FNumNosGerados += Incremento;
end;

procedure TSolucao.ContaNoVisitado(Incremento: integer);
begin
  FNumNosVisitados += Incremento;
end;

procedure TSolucao.ContaNoPodado(Incremento: integer);
begin
  FNumNosPodados += Incremento;
end;

procedure TSolucao.Poda(No: TNo);
var
  NoFilho: TNo;
  Cont: integer;
begin
  if (No.Filhos.Count > 0) then begin
    for Cont := 0 to No.Filhos.Count - 1 do begin
      NoFilho := TNo(No.Filhos.Items[Cont]);
      if not (NoFilho.Podado) then begin
        Poda(NoFilho);
      end;
    end;
  end;
  Inc(FNumNosPodados);
  No.Podado := True;
end;

function TSolucao.RemovePrimeiroListaEspera: TNo;
var
  No: TNo;
begin
  No := TNo(FListaEspera.Items[0]);
  No.F := No.F + 0;
  FListaEspera.Delete(0);
  Result := No;
end;

function TSolucao.RemoveUltimoListaEspera(): TNo;
var
  No: TNo;
  Posicao: integer;
begin
  No := TNo(FListaEspera.Last());
  FListaEspera.Delete(FListaEspera.Count - 1);
  Result := No;
end;

procedure TSolucao.AdicionaFilaEspera(No: TNo);
begin
  FFilaEspera.Add(No);
  Inc(FNumNosGerados);
end;

function TSolucao.QuantidadeFilaEspera: integer;
begin
  Result := FFilaEspera.Count;
end;

procedure TSolucao.RemoveFilaEspera(NoAvg: TAvgLvlTreeNode);
begin
  FFilaEspera.Delete(NoAvg);
end;

procedure TSolucao.RemoveVisitado(No: TNo);
var
  Posicao: integer;
begin
  Posicao := ProcuraListaPosicao(FListaVisitados, No);
  if (Posicao <> -1) then begin
    Self.Poda(No);
    FListaVisitados.Delete(Posicao);
  end;
end;

function TSolucao.ProcuraLista(L: TList; No: TNo): TNo;
var
  Cont: integer;
  NoAtual: TNo;
begin
  Result := nil;
  // Procura do final para o início da lista
  // Se um nó estiver duas vezes na lista, o de menor profundidade está no final
  if (L.Count >= 1) then begin
    for Cont := L.Count - 1 downto 0 do begin
      NoAtual := TNo(L.Items[Cont]);
      if (NoAtual.Estado.Igual(No.Estado)) then begin
        Result := NoAtual;
        Break;
      end;
    end;
  end;
end;

function TSolucao.ProcuraListaPosicao(L: TList; No: TNo): integer;
var
  Cont: integer;
  NoAtual: TNo;
begin
  Result := -1;
  for Cont := 0 to L.Count - 1 do begin
    NoAtual := TNo(L.Items[Cont]);
    if (NoAtual.Estado.Igual(No.Estado)) then begin
      Result := Cont;
      Break;
    end;
  end;
end;

constructor TSolucao.Create();
begin
  Falha := False;
  Corte := False;
  NoMeta := nil;
  FListaVisitados := TList.Create();
  FListaEspera := TList.Create();
  FFilaEspera := TAvgLvlTree.Create(@ComparaNos);
  FNumNosGerados := 0;
  FNumNosVisitados := 0;
  FNumNosPodados := 0;
  InicioBusca := Now();
end;

end.

