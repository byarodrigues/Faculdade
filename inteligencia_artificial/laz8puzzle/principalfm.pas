unit PrincipalFm;

{$mode objfpc}{$H+}

interface

uses
  Arvores, Buscas, Buttons, Classes, Controls, Dialogs, Estados,
  ExtCtrls, FileUtil, Forms, Graphics, Grids, Solucoes, Spin,
  StdCtrls, SysUtils;

type

  { TPrincipalForm }

  TPrincipalForm = class(TForm)
    ButtonBuscar: TButton;
    ButtonGerarEstado: TButton;
    CheckTabelaTransposicao: TCheckBox;
    CheckBoxExibirArvore: TCheckBox;
    GridEstadoInicial: TStringGrid;
    GroupBox1: TGroupBox;
    GroupBox10: TGroupBox;
    GroupBox2: TGroupBox;
    GroupBox3: TGroupBox;
    GroupBox4: TGroupBox;
    GroupBox5: TGroupBox;
    GroupBox6: TGroupBox;
    GroupBox7: TGroupBox;
    GroupBox8: TGroupBox;
    GroupBox9: TGroupBox;
    Label1: TLabel;
    MemoInfo: TMemo;
    Panel2: TPanel;
    RadioGroupTipoBusca: TRadioGroup;
    ScrollBoxArvore: TScrollBox;
    SpinEditLimite: TSpinEdit;
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
    procedure ButtonBuscarClick(Sender: TObject);
    procedure ButtonGerarEstadoClick(Sender: TObject);
    procedure CheckBoxExibirArvoreChange(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    function DesenhaArvore(Xini: real; N: TNo): real;
    procedure DesenhaNo(N: TNo; X: real);
    procedure GridEstadoInicialClick(Sender: TObject);
    procedure RadioGroupTipoBuscaSelectionChanged(Sender: TObject);
    procedure ScrollBoxArvorePaint(Sender: TObject);
    procedure DesenhaLinhas(N: TNo);
    procedure GridMouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: integer);
    procedure GridMouseMove(Sender: TObject; Shift: TShiftState; X, Y: integer);
    procedure GridMouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: integer);
    procedure IniciaBusca();
    procedure ResultadoSolucao(S: TSolucao);
    procedure ParaBusca();
    procedure HabiliteDesabilitaLimiteTransposicao();
    procedure HabilitaDesabilitaComponentes(Habilitar: boolean);
  private
    { private declarations }
  public
    { public declarations }
  end;

// Constantes para desenho da árvore
const
  TAM_QUADRADO = 15;
  TAM_GRID = TAM_QUADRADO * 3 + 1;
  DISTANCIA_HORIZONTAL = 10;
  DISTANCIA_VERTICAL = 20;
var
  PrincipalForm: TPrincipalForm;

implementation

{$R *.lfm}

// Variáveis globais
var
  Raiz: TNo;  // Nó raíz da árvore
  GridMovendo: TObject; // Nó da árvore sendo arrastado
  PosicaoInicial: TPoint; // Posição inicial do nó sendo arrastado
  ArvoreDesenhada: boolean; // Indica se a ávore já foi desenhada

{ TPrincipalForm }

// Inicialização do formulário
procedure TPrincipalForm.FormCreate(Sender: TObject);
begin
  // Nenhuma busca sendo feita
  Buscando := False;
  // Inicialização para geração de aleatórios
  Randomize();
  // Inicialmente nenhuma árvore existe
  Raiz := nil;
  // Incialmente nenhum objeto sendo movido
  GridMovendo := nil;
  // Gera um estado inicial aleatório
  ButtonGerarEstadoClick(Sender);
  // Inicialmente nenhuma árvore desenhada
  ArvoreDesenhada := False;
  // Posiciona formulário
  Width := Screen.Width;
  Height:= Screen.Height;
  Top := 0;
  Left:=0;
end;

// Botão de busca
procedure TPrincipalForm.ButtonBuscarClick(Sender: TObject);
begin
  if not (Buscando) then begin
    IniciaBusca();
  end else begin
    ParaBusca();
  end;
end;

// Gera e exibe um estado aleatório
procedure TPrincipalForm.ButtonGerarEstadoClick(Sender: TObject);
var
  Estado: TEstado;
begin
  Estado := TEstado.Create();
  Estado.GeraAleatorio();
  Estado.PreencheGrid(GridEstadoInicial);
  Estado.Free();
end;

// Exibe ou oculta a árvore de busca
procedure TPrincipalForm.CheckBoxExibirArvoreChange(Sender: TObject);
begin
  if CheckBoxExibirArvore.Checked then begin
    if not (ArvoreDesenhada) and (Raiz <> nil) then begin
      ArvoreDesenhada := True;
      DesenhaArvore(0,Raiz);
    end;
    ScrollBoxArvore.Repaint();
  end;
  ScrollBoxArvore.Visible := CheckBoxExibirArvore.Checked;
end;

// Desenha a árvore de busca
function TPrincipalForm.DesenhaArvore(Xini: real; N: TNo): real;
var
  Cont: integer;
  NoFilho: TNo;
  Soma: real;
  DescendenteMaisDireita: real;
begin
  // Verificase o nó é válido
  if N <> nil then begin
    // Inicialmente o descendente mais a direita é o próprio nó
    DescendenteMaisDireita := XIni;
    // Testa se o nó não tem filhos
    if (N.Filhos.Count = 0) then begin
      N.X := XIni;
      Result := XIni;
    end else begin
      Application.ProcessMessages();
      Soma := 0;
      // Soma as posições dos filhos e os desenha
      for Cont := 0 to N.Filhos.Count - 1 do begin
        NoFilho := TNo(N.Filhos.Items[Cont]);
        DescendenteMaisDireita := DesenhaArvore(DescendenteMaisDireita, NoFilho);
        DescendenteMaisDireita := DescendenteMaisDireita + 1;
        Soma := Soma + NoFilho.X;
      end;
      // Desconsidera a últa soma
      DescendenteMaisDireita := DescendenteMaisDireita - 1;
      // O posição do pai é média das posições dos filhos
      N.X := Soma / N.Filhos.Count;
      Result := DescendenteMaisDireita;
    end;
    // Desenha o nó
    DesenhaNo(N, N.X);
  end;
end;

procedure TPrincipalForm.DesenhaNo(N: TNo; X: real);
var
  Cor: TColor;
begin
  // Cria o grid para representar o nó
  N.Grid := TStringGrid.Create(ScrollBoxArvore);
  N.Grid.ColCount := 3;
  N.Grid.RowCount := 3;
  if (N.ParteDaSolucao) then begin
    Cor := clLime;
  end else if (N.Podado) then begin
    Cor := clRed;
  end else if (N.Visitado) then begin
    Cor := clYellow;
  end else begin
    Cor := clWhite;
  end;
  N.Grid.FixedColor := Cor;
  N.Estado.PreencheGrid(N.Grid);
  N.Grid.Hint:= 'F=' + IntToStr(N.F) + ', G=' + IntToStr(N.G)+ ', H=' + IntToStr(N.H);
  N.Grid.ShowHint:= True;
  N.Grid.DefaultColWidth := TAM_QUADRADO;
  N.Grid.DefaultRowHeight := TAM_QUADRADO;
  N.Grid.FixedCols := 3;
  N.Grid.FixedRows := 3;
  N.Grid.Flat := True;
  N.Grid.ScrollBars := ssNone;
  N.Grid.TabStop := False;
  N.Grid.Height := TAM_GRID;
  N.Grid.Width := TAM_GRID;
  N.Grid.Parent := ScrollBoxArvore;
  N.Grid.Left := Round(X * (TAM_GRID + DISTANCIA_HORIZONTAL));
  N.Grid.Top := Round(N.G * (TAM_GRID + DISTANCIA_VERTICAL));
  N.grid.OnMouseDown := @GridMouseDown;
  N.grid.OnMouseMove := @GridMouseMove;
  N.grid.OnMouseUp := @GridMouseUp;
end;

// Faz movimento no estado inicial
procedure TPrincipalForm.GridEstadoInicialClick(Sender: TObject);
var
  L, C, LBranco, CBranco: byte;
  Muda: Boolean;
begin
  C := GridEstadoInicial.Selection.Left;
  L := GridEstadoInicial.Selection.Top;
  Muda := False;
  if (L <= 1) and (GridEstadoInicial.Cells[C, L + 1] = '') then begin
    CBranco := C;
    LBranco := L + 1;
    Muda := True;
  end else if (L >= 1) and (GridEstadoInicial.Cells[C, L - 1] = '') then begin
    CBranco := C;
    LBranco := L - 1;
    Muda := True;
  end else if (C <= 1) and (GridEstadoInicial.Cells[C + 1, L] = '') then begin
    CBranco := C + 1;
    LBranco := L;
    Muda := True;
  end else if (C >= 1) and (GridEstadoInicial.Cells[C - 1, L] = '') then begin
    CBranco := C - 1;
    LBranco := L;
    Muda := True;
  end;
  if (Muda) then begin
    GridEstadoInicial.Cells[CBranco, LBranco] := GridEstadoInicial.Cells[C, L];
    GridEstadoInicial.Cells[C, L] := '';
  end;
end;

procedure TPrincipalForm.RadioGroupTipoBuscaSelectionChanged(Sender: TObject);
begin
  HabiliteDesabilitaLimiteTransposicao();
end;

// Redesenha a árvore se ela existir
procedure TPrincipalForm.ScrollBoxArvorePaint(Sender: TObject);
begin
  if (Raiz <> nil) then begin
    DesenhaLinhas(Raiz);
  end;
end;

// Desenha linhas que ligam os nós da árvore
procedure TPrincipalForm.DesenhaLinhas(N: TNo);
var
  Cont: integer;
  NoFilho: TNo;
  XPai, YPai, XFilho, YFilho: integer;
  Grid: TStringGrid;
begin
  // Testa se o nó tem filhos
  if (N.Filhos.Count > 0) then begin
    Application.ProcessMessages();
    for Cont := 0 to N.Filhos.Count - 1 do begin
      NoFilho := TNo(N.Filhos.Items[Cont]);
      if (N.Grid <> nil) and (NoFilho.Grid <> nil) then begin
        Grid := N.Grid;
        XPai := round(Grid.Left + TAM_GRID / 2);
        YPai := round(Grid.Top + TAM_GRID / 2);
        Grid := NoFilho.Grid;
        XFilho := round(Grid.Left + TAM_GRID / 2);
        YFilho := Grid.Top;
        ScrollBoxArvore.Canvas.Line(XPai, YPai, XFilho, YFilho);
      end;
      DesenhaLinhas(NoFilho);
    end;
  end;
end;

// Início de movimento de nó da árvore desenhada
procedure TPrincipalForm.GridMouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: integer);
begin
  GridMovendo := Sender;
  PosicaoInicial.X := X;
  PosicaoInicial.Y := Y;
end;

// Movimento de nó da árvore desenhada
procedure TPrincipalForm.GridMouseMove(Sender: TObject; Shift: TShiftState;
  X, Y: integer);
begin
  if (GridMovendo <> nil) then begin
    TStringGrid(GridMovendo).Left := TStringGrid(GridMovendo).Left + (X - PosicaoInicial.X);
    TStringGrid(GridMovendo).Top := TStringGrid(GridMovendo).Top + (Y - PosicaoInicial.Y);
  end;
end;

// Fim de movimento de nó da árvore desenhada
procedure TPrincipalForm.GridMouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: integer);
begin
  GridMovendo := nil;
  ScrollBoxArvore.Repaint();
end;

// Inicia busca
procedure TPrincipalForm.IniciaBusca;
var
  Estado: TEstado; // Estado inicial para a busca
  Solucao: TSolucao; // Solução da busca
begin
  Buscando := True;
  // Desabilita componentes
  HabilitaDesabilitaComponentes(False);

  // Cria o estado inicial
  Estado := TEstado.Create();
  Estado.LeGrid(GridEstadoInicial);

  // Destrói árvore de busca anterior se existir
  if (Raiz <> nil) then begin
    Raiz.LimpaGridRecursivo();
    ScrollBoxArvore.DestroyComponents();
    Raiz.Free();
    Raiz := nil;
    ArvoreDesenhada := False;
  end;
  MemoInfo.Clear();
  MemoInfo.Lines.Add('Buscando...');

  // Realiza a busca
  case RadioGroupTipoBusca.ItemIndex of
    0: begin
      Solucao := BuscaAEstrelaEstado(Estado);
    end;
    1: begin
      if (CheckTabelaTransposicao.Checked) then begin
        Solucao := BuscaLarguraTransposicao(Estado);
      end else begin
        Solucao := BuscaLargura(Estado);
      end;
    end;
    2: begin
      if (CheckTabelaTransposicao.Checked) then begin
        Solucao := BuscaProfundidadeTransposicao(Estado);
      end else begin
        Solucao := BuscaProfundidade(Estado);
      end;
    end;
    3: begin
      if (CheckTabelaTransposicao.Checked) then begin
        Solucao := BuscaProfundidadeLimitadaTransposicao(Estado, SpinEditLimite.Value);
      end else begin
        Solucao := BuscaProfundidadeLimitada(Estado, SpinEditLimite.Value);
      end;
    end;
    4: begin
      if (CheckTabelaTransposicao.Checked) then begin
        Solucao := BuscaAprofundamentoIterativoTransposicao(Estado);
      end else begin
        Solucao := BuscaAprofundamentoIterativo(Estado);
      end;
    end;
  end;
  Solucao.TerminoBusca := Now();
  if (Solucao.NoMeta <> nil) then begin
    Solucao.NoMeta.MarcaCaminhoSolucao();
  end;
  // Exibe a árvore se selecionado
  Raiz := Solucao.NoInicial;
  ResultadoSolucao(Solucao);
  // Destrói a solução
  Solucao.Free();
  // Desenha a árvore se selecionado
  CheckBoxExibirArvoreChange(Self);

  Buscando := False;
  // Habilita componentes
  HabilitaDesabilitaComponentes(True);
end;

procedure TPrincipalForm.ResultadoSolucao(S: TSolucao);
begin
  MemoInfo.Clear();
  if (S.NoMeta <> nil) then begin
    MemoInfo.Lines.Add('Solucação Encontrada');
  end else if (S.Falha) then begin
    MemoInfo.Lines.Add('Solução não encontrada');
  end else if (S.Corte) then begin
    MemoInfo.Lines.Add('Solução não encontrada no limite informado');
  end else begin
    MemoInfo.Lines.Add('Busca interrompida');
  end;
  MemoInfo.Lines.Add('Nós gerados: ' + IntToStr(S.NumNosGerados));
  MemoInfo.Lines.Add('Nós visitados: ' + IntToStr(S.NumNosVisitados));
  MemoInfo.Lines.Add('Nós podados: ' + IntToStr(S.NumNosPodados));
  if (S.NoMeta <> nil) then begin
    MemoInfo.Lines.Add('Profundidade da solução: ' + IntToStr(S.NoMeta.G));
  end;
  MemoInfo.Lines.Add('Tempo gasto: ' + TimeToStr(S.TerminoBusca - S.InicioBusca));
end;

procedure TPrincipalForm.ParaBusca;
begin
  Buscando := False;
end;

procedure TPrincipalForm.HabiliteDesabilitaLimiteTransposicao;
begin
  if (RadioGroupTipoBusca.ItemIndex = 3) then begin
    SpinEditLimite.Enabled := True;
  end else begin
    SpinEditLimite.Enabled := False;
  end;
  if (RadioGroupTipoBusca.ItemIndex = 0) then begin
    CheckTabelaTransposicao.Enabled:= False;
    CheckTabelaTransposicao.Checked:= True;
  end else begin
    CheckTabelaTransposicao.Enabled:= True;
  end;
end;

procedure TPrincipalForm.HabilitaDesabilitaComponentes(Habilitar: boolean);
begin
  GridEstadoInicial.Enabled := Habilitar;
  ButtonGerarEstado.Enabled := Habilitar;
  RadioGroupTipoBusca.Enabled := Habilitar;
  CheckBoxExibirArvore.Enabled := Habilitar;
  if (Habilitar) then begin
    ButtonBuscar.Caption := '&Buscar';
  end else begin
    ButtonBuscar.Caption := '&Parar';
  end;
  HabiliteDesabilitaLimiteTransposicao();
end;

end.
