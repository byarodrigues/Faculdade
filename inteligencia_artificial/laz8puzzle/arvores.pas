unit Arvores;

{$mode objfpc}{$H+}

interface

uses
  AvgLvlTree, Classes, Estados, Grids, SysUtils;

type

  { TNo }

  TNo = class
  private
    // Estado que o nó representa
    FEstado: TEstado;
  public
    // Pai do nó
    Pai: TNo;
    F, G, H: integer;
    // Grid para desenhar o nó
    Grid: TStringGrid;
    // Usado para o posicionamento horizontal do nó
    X: real;
    // Lista de filhos
    Filhos: TList;
    // Indica se o nó faz parte da solução
    ParteDaSolucao: boolean;
    // Indica se o nó foi visitado
    Visitado: boolean;
    // Indica se o nó foi podado (usado apenas na busca heurística)
    Podado: boolean;
    constructor Create(Estado: TEstado);
    constructor Create(NoPai: TNo; Estado: TEstado);
    constructor CreateHeuristica(NoPai: TNo; Estado: TEstado);
    destructor Destroy();
    procedure MarcaCaminhoSolucao();
    procedure LimpaGridRecursivo();
    property Estado: TEstado read FEstado;
  end;

implementation

// Construtor de nó
constructor TNo.Create(Estado: TEstado);
begin
  inherited Create();
  Self.Pai := nil;
  Self.FEstado := Estado;
  Self.F := 0;
  Self.G := 0;
  Self.H := 0;
  Self.Filhos := TList.Create();
  Self.Visitado := False;
  Self.Podado := False;
end;

// Construtor de nó herdando de pai
constructor TNo.Create(NoPai: TNo; Estado: TEstado);
begin
  Self := TNo.Create(Estado);
  Self.Pai := NoPai;
  Self.G := NoPai.G + 1;
  Self.F := Self.G;
end;

// Construtor de nó herdando de pai com heurística
constructor TNo.CreateHeuristica(NoPai: TNo; Estado: TEstado);
begin
  Self := TNo.Create(NoPai, Estado);
  Self.H := Estado.Heuristica();
  Self.F := Self.G + Self.H;
end;

// Destrutor de nó
destructor TNo.Destroy();
var
  NoFilho: TNo;
  Cont: integer;
begin
  // Destrói os filhos do nó
  if (Self.Filhos.Count > 0) then begin
    for Cont := 0 to Self.Filhos.Count - 1 do begin
      NoFilho := TNo(Self.Filhos.Items[Cont]);
      NoFilho.Free();
    end;
  end;
  Self.FEstado.Free();
  Self.Grid := nil;
end;

// Marca nós que fazem parte da solução
procedure TNo.MarcaCaminhoSolucao();
var
  No: TNo;
begin
  No := Self;
  while (No <> nil) do begin
    No.ParteDaSolucao := True;
    No := No.Pai;
  end;
end;

// Limpa as grades que representam os nós no desenho
procedure TNo.LimpaGridRecursivo();
var
  Cont: integer;
  NoFilho: TNo;
begin
  for Cont := 0 to Self.Filhos.Count - 1 do begin
    NoFilho := TNo(Self.Filhos.Items[Cont]);
    NoFilho.LimpaGridRecursivo();
  end;
  Self.Grid := nil;
end;

end.

