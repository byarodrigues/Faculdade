unit Estados;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Grids;

type
  // Possíveis ações
  TAcao = (ESQUERDA, DIREITA, BAIXO, CIMA);
  { TEstado }
  // Estados do quebra-cabeça
  TEstado = class
    private
      FTabuleiro: array[0..8] of Byte;
      FBranco: Byte;
      procedure SetBranco(NovoBranco: Byte);
    public
      function Copia(): TEstado;
      function AcaoValida(Acao: TAcao): Boolean;
      procedure AplicaAcao(Acao: TAcao);
      function CreateSucessores(): TList;
      function TestaMeta(): Boolean;
      function Igual(Estado: TEstado): Boolean;
      procedure PreencheGrid(Grid: TStringGrid);
      procedure LeGrid(Grid: TStringGrid);
      procedure GeraAleatorio();
      function Heuristica: Byte;
      property Branco: Byte read FBranco write SetBranco;
  end;

const
  // Estado meta
  META: array[0..8] of byte = (1, 2, 3, 4, 5, 6, 7, 8, 0);
  // Número de movimentos para gerar estado aleatório
  NUM_MOVIMENTOS_ALEATORIOS = 50;

implementation

// Muda posição do espaço em branco
procedure TEstado.SetBranco(NovoBranco: Byte);
begin
  if (NovoBranco >=0) and (NovoBranco <= 8) then begin
    Self.FTabuleiro[FBranco]:=Self.FTabuleiro[NovoBranco];
    Self.FBranco:= NovoBranco;
    Self.FTabuleiro[FBranco]:= 0;
  end;
end;

// Copia um estado
function TEstado.Copia(): TEstado;
var
  NovoEstado: TEstado;
  i: Integer;
begin
  NovoEstado:=TEstado.Create();
  NovoEstado.FBranco:= Self.FBranco;
  for i:=0 to 8 do begin
    NovoEstado.FTabuleiro[i] := Self.FTabuleiro[i];
  end;
  Result:= NovoEstado;
end;

// Verifica se uma ação é válida para um estado
function TEstado.AcaoValida(Acao: TAcao): Boolean;
begin
  Result:= False;
  case Acao of
  BAIXO: begin
    if (Self.FBranco < 6) then begin
      Result:= True;
    end;
  end;
  CIMA: begin
    if (Self.FBranco > 2) then begin
      Result:= True;
    end;
  end;
  DIREITA: begin
    if not (Self.FBranco in [2,5,8]) then begin
      Result:= True;
    end;
  end;
  ESQUERDA: begin
    if not (Self.FBranco in [0,3,6]) then begin
      Result:= True;
    end;
  end;
  end;
end;

// Aplica uma ação sobre o estado e retora estado com a modificação
procedure TEstado.AplicaAcao(Acao: TAcao);
var
  BrancoAntigo: Byte;
begin
  BrancoAntigo := Self.FBranco;
  case Acao of
    BAIXO: Self.SetBranco(Branco + 3);
    CIMA: Self.SetBranco(Branco - 3);
    ESQUERDA: Self.SetBranco(Branco - 1);
    DIREITA: Self.SetBranco(Branco + 1);
  end;
end;

// Gera uma lista de sucessores para oestado atual
function TEstado.CreateSucessores(): TList;
var
  Sucessores: TList;
  Acao: TAcao;
  NovoEstado: TEstado;
begin
  Sucessores:=TList.Create();
  for Acao in TAcao do begin
    if (Self.AcaoValida(Acao)) then begin
      NovoEstado := Self.Copia();
      NovoEstado.AplicaAcao(Acao);
      Sucessores.Add(NovoEstado);
    end;
  end;
  Result:=Sucessores;
end;

// Testa se o estado é meta
function TEstado.TestaMeta(): Boolean;
var
  Cont: Byte;
begin
  Result := True;
  for Cont:=0 to 8 do begin
    if (Self.FTabuleiro[Cont] <> META[Cont]) then begin
      Result := False
    end;
  end;
end;

// Testa se o estado é igual a outro
function TEstado.Igual(Estado: TEstado): Boolean;
var
  i: Integer;
begin
  Result:=True;
  if (Self.FBranco <> Estado.FBranco) then begin
    Result:=False;
  end else begin
    for i:=0 to 8 do begin
      if (Self.FTabuleiro[i] <> Estado.FTabuleiro[i]) then begin
        Result:= False;
        Break;
      end;
    end;
  end;
end;

// Preenche um StringGrid com o estado
procedure TEstado.PreencheGrid(Grid: TStringGrid);
var
  L, C, Cont: Byte;
begin
  for Cont:=0 to 8 do begin
    L:= Cont div 3;
    C:= Cont mod 3;
    Grid.Cells[C,L]:=IntToStr(Self.FTabuleiro[Cont]);
  end;
  L:= Self.FBranco div 3;
  C:= Self.FBranco mod 3;
  Grid.Cells[C,L]:='';
end;

// Preenche o estado com um StringGrid
procedure TEstado.LeGrid(Grid: TStringGrid);
var
  L, C, Posicao: Byte;
begin
  for C:=0 to 2 do begin
    for L:=0 to 2 do begin
      Posicao:=L*3 + C;
      if (Grid.Cells[C,L] = '') then begin
        Self.FBranco:= Posicao;
      end else begin
        Self.FTabuleiro[Posicao]:=StrToInt(Grid.Cells[C,L]);
      end;
    end;
  end;
end;

// Gera um estado aleatório
procedure TEstado.GeraAleatorio();
var
  Acao: TAcao;
  Cont: Integer;
begin
  Self.FTabuleiro := META;
  Self.FBranco:=8;
  For Cont:= 1 to NUM_MOVIMENTOS_ALEATORIOS do begin
    Acao := TAcao(Random(Ord(High(TAcao)) + 1));
    if (Self.AcaoValida(Acao)) then begin
      Self.AplicaAcao(Acao);
    end;
  end;
end;

function TEstado.Heuristica(): Byte;
var
  Cont, Num, C, L, CCorreta, LCorreta, Soma: Byte;
begin
  // Soma o número de movimentos para colocar cada peça no lugar
  Soma := 0;
  for Cont:=0 to 8 do begin
    Num := FTabuleiro[Cont];
    C:= Cont mod 3;
    L:= Cont div 3;
    CCorreta:= (Num -1) mod 3;
    LCorreta:= (Num -1) div 3;
    if (Num <> 0) then begin
      Soma := Soma + Abs(C - CCorreta) + Abs(L- LCorreta);
    end;
  end;
  Result:= Soma;
end;


end.

