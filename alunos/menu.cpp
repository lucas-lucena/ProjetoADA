#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "prototipos.h" //
#include "prototiposEstrutura.h"

using namespace std;

//funcoes
void paginaInicial();
string centralizar(string str);
void menu();
void exibirFuncoesAlunos();
void exibirFuncoesDisciplina();
void importarDados(int opcao);
void alunos();
void disciplina();
void informacao();
int menuDiretorio(int opcao);


int main (){
    paginaInicial();
return 0;
}


void paginaInicial(){
    system("clear||cls");
    cout << "\n\n";
    cout << centralizar("    |     '||''|.       |     ") + "\n" + centralizar("   |||     ||   ||     |||    ") + "\n" +
    centralizar("  |  ||    ||    ||   |  ||  ") + "\n" + centralizar(" .''''|.   ||    ||  .''''|. ") + "\n" +
    centralizar(".|.  .||. .||...|'  .|.  .||.") + "\n";
    cout << centralizar("analise de dados academicos");
    cout << "\n\n";
    cout << "\t\t\t\t     1.menu\t\t2.info\n\n";
    string opcao;
    do{
        cout << "\t\t\t\t   opcao > ";
        cin >> opcao;
    }while(opcao != "1" && opcao != "2");
    if(opcao == "1"){
        menu();
    }else{
        informacao();
    }
}

void menu(){
    //opcao menu
    system("clear||cls");
    cout << "\n\n" << centralizar("voce deseja conhecer mais sobre");
    cout << "\n\n\t\t\t\t1.alunos    2.disciplina    3.voltar\n\n";
    string opcao;
    do{
        cout << "\t\t\t\t   opcao > ";
        cin >> opcao;
    }while(opcao != "1" && opcao != "2" && opcao != "3");
    if(opcao == "1"){
        alunos();
    }else if(opcao == "2"){
        disciplina();
    }else if(opcao == "3"){
        paginaInicial();
    }
}

void informacao(){
    system("clear||cls");
    cout << "\n\n " << centralizar("venha conhecer seus alunos ") << "\n\n";
    cout << centralizar("ADA eh uma aplicacao que visa auxiliar o professor em sala de aula de forma ")
         << "\n" << centralizar("que seja repassado para ele uma analise da turma sobre a qual ele ira ")
         << "\n" << centralizar("ministrar. O perfil da turma sera traçado baseado no historico dos alunos e ")
         << "\n" << centralizar("no historico da disciplina.");
    cout << "\n\n " << centralizar("1.voltar") << "\n\n";
    string op;
    do{
      cout << "\t\t\t\t   opcao > ";
      cin >> op;
    }while(op != "1");
    paginaInicial();
}

void alunos(){
    system("clear||cls");
    cout << "\n\n" << centralizar("voce deseja")
    << "\n\n\t\t\t1.importar dados   2.exibir funcoes     3.voltar\n\n";
    string opcao;
    do{
        cout << "\t\t\t\t   opcao > ";
        cin >> opcao;
    }while(opcao != "1" && opcao != "2" && opcao != "3");
    if(opcao == "1"){ //importar dados
        importarDados(0);
    }else if(opcao == "2"){ //exibir funcionalidades de aluno
        exibirFuncoesAlunos();
    }else if(opcao == "3"){
        menu();
    }
}

void exibirFuncoesAlunos(){
    system("clear||cls");
    cout << "\n\n" << centralizar("funcionalidades")
    << "\n\n" << centralizar("1.agrupar alunos de acordo com o intervalo de CRA passado como parametro")
    << "\n" << centralizar("2.exibir o desempenho dos alunos nos pre requisitos")
    << "\n" << centralizar("3.exibir o desempenho dos alunos nas disciplinas desejaveis")
    << "\n" << centralizar("4.exibir alunos que possuem ao menos n reprovacoes no curriculo")
    << "\n" << centralizar("5.exibir alunos que reprovaram a disciplina")
    << "\n" << centralizar("6.voltar") << "\n\n";

    string opcao;
    do{
        cout << "\t\t\t\t   opcao > ";
        cin >> opcao;
    }while(opcao != "1" && opcao != "2" && opcao != "3" && opcao != "4" && opcao != "5" && opcao != "6");
    if(opcao == "1"){
        double iniInter;
	    double fimInter;
	    cout << centralizar("digite o inicio do intervalo do CRA");
	    cout << "\n\n\t\t\t\t   inicio > ";
	    cin >> iniInter;
	    cout << centralizar("digite o fim do intervalo do CRA");
	    cout << "\n\n\t\t\t\t   fim > ";
	    cin >> fimInter;
    	cout << centralizar("os seguintes alunos tem CRA dentro do intervalo passado ") << "\n";
	    agruparAlunos(retornaAlunos(),iniInter,fimInter);
    }
    else if(opcao == "2"){
        cout << centralizar("digite, por linha, os nomes das disciplinas que sao pre requisitos. E pressione Enter");
	    vector<string> preR;
	    string preReq = ".";
	    while (preReq != "") {
		    getline(cin, preReq);
		    if (preReq == "") {
		    	break;
		    }
		else {
		    preR.push_back(preReq);
		}
	}

	desempPreRequisitos(preR,retornaAlunos());	
    }
    else if(opcao == "3"){
         cout << centralizar("digite, por linha, os nomes das disciplinas que sao desejaveis, e pressione Enter");
	    vector<string> desej;
	    string nomeDisc = ".";
	    while (nomeDisc != "") {
		    getline(cin, nomeDisc);
		    if (nomeDisc == "") {
		    	break;
		    }
		    else {
		       desej.push_back(nomeDisc);
		    }
	    }
        desempDiscDesejaveis(desej,retornaAlunos());	
    }
    else if(opcao == "4"){
        int n;
	    cout << centralizar("digite o numero de reprovacoes minimas");
	    cout << "\n\n\t\t\t\t   reprovacoes(n) > ";
	    cin >> n;
	    cout << centralizar("alunos com n+ reprovacoes: ") << "\n";
	    repetentesComuns(n,retornaAlunos());
    }
    else if(opcao == "5"){
        cout << centralizar("os seguintes alunos ja reprovaram esta disciplina: ") << "\n";
	   // repetentesDisc(retornaAlunos(),disc.nome);
    }
    else if(opcao == "6"){alunos();}
}

void disciplina(){
    system("clear||cls");
    cout << "\n\n" << centralizar("voce deseja")
    << "\n\n\t\t\t1.importar dados   2.exibir funcoes     3.voltar\n\n";
    string opcao;
    do{
        cout << "\t\t\t\t   opcao > ";
        cin >> opcao;
    }while(opcao != "1" && opcao != "2" && opcao != "3");
    if(opcao == "1"){ //importar dados
        //importarDados(); // comentei pois nao sei se funciona pq a parte de importar dados de disciplina eh do L.L
    }else if(opcao == "2"){ //exibir funcionalidades de aluno
        exibirFuncoesDisciplina();
    }else if(opcao == "3"){
        menu();
    }
}

void exibirFuncoesDisciplina(){
    system("clear||cls");
    cout << "\n\n" << centralizar("funcionalidades")
    << "\n\n" << centralizar("1.exibir perfil geral da disciplina de n periodos atras ate hoje")
    << "\n" << centralizar("2.exibir os pontos criticos da disciplina")
    << "\n" << centralizar("3.exibir as medias da disciplina nos periodos passados")
    << "\n" << centralizar("4.exibir indice de aprovacao, reprovacao por falta e nota de cada periodo")
    << "\n" << centralizar("5.voltar") << "\n\n";
    string opcao;
    do{
        cout << "\t\t\t\t   opcao > ";
        cin >> opcao;
    }while(opcao != "1" && opcao != "2" && opcao != "3" && opcao != "4" && opcao != "5");
    if(opcao == "1"){
        int n;
        cout << centralizar("Digite o numero de periodos atras voce quer exibir o perfil geral");
        cout << "\n\n\t\t\t\t   periodos > ";
	    cin >> n;
	    cout << centralizar("Desempenho passado da disciplina: ") << "\n";
	  //  exibeDesempPass(n,disc);
    }
    else if(opcao == "2"){
        cout << centralizar("pontos criticos da disciplina e informacoes importantes: ") << "\n";
	 //   pontosCriticos(disc);
    }
    else if(opcao == "3"){
         cout << centralizar("as medias passadas de cada periodo registrado dessa disciplina sao: ") << "\n";
	  //  exibeMediasPassadas(disc);
    }
    else if(opcao == "4"){
        cout << centralizar("porcentagens de aprovação e reprovação da disciplina durante todos os periodos registrados: ") << "\n";
	  //  exibeindices(disc);
    }
    else if(opcao == "5"){disciplina();}
}

int menuDiretorio(int opcao){
    int diretorioAberto = 0;
    do{
        system("clear||cls");
        cout << "\n\n" << centralizar("informe o diretorio que contem os dados");
        cout << "\n\n" << centralizar("exemplo de diretorio valido:");
        cout << "\n" << centralizar("C:/Users/usuario/caminho/ate/a/pasta");
        cout << "\n" << centralizar("1.voltar");
        cout << "\n\n\t\t\t\t   diretorio > ";
        string diretorio = "";
        cin >> diretorio;
        if(diretorio == "1" && opcao == 0){return 1;}
        else if(diretorio == "1" && opcao == 1){return 1;}
        diretorioAberto = openDirectory(diretorio.c_str());
    }while(diretorioAberto == 0);
    return 0;
}

void importarDados(int opcao){ // se aluno que chama essa funcao entao opcao = 0, se nao opcao = 1
    if(opcao == 0){
        if(menuDiretorio(0) == 1){
            alunos();
        }
    }else if(opcao == 1){
        if(menuDiretorio(1) == 1){
            disciplina();
        }
    }

}

string centralizar(string str) {
   int espacos = (int)((100 - (int)str.length())/2);
   return string(espacos, ' ') + str + string((espacos + (str.length() > espacos * 2 ? 1 : 0)), ' ');

}

