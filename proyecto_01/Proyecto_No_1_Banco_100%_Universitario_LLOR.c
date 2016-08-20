/*
 * POR RECOMENDACION Y PARA VISUALIZAR LOS DETALLES DEL DISEÑO DE ESTE SOFTWARE,
 * USE 'KONSOLE' MAXIMIZADA EN TODA LA PANTALLA
 * 														ATTE: LOANA LEON Y OSVAL REYES
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MX 5000
#define M 100
#define MM 200
#define CB "\e[m"
#define CR "\e[38;4m\e[5m"
#define CV "\e[32;1m"
#define CAM "\e[33;1m"
#define CAZ "\e[34;1m"
#define RES "\e[40;1m"
#define LC "\n\t\t«-------------------------------------------------------------------------------------------»\n"
#define ST "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"

#if defined(__linux__) || defined(__linux)
#define CLEAR_CMD "clear"
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__)
#define CLEAR_CMD "cls"
#endif
#define LimpiarPantalla() system(CLEAR_CMD)

typedef struct{
	int dia,mes,ano;
}tipo_fecha;
typedef struct{
	char cedula[11];
	char nombre[51];
	char apellido[51];
	char sexo;
	char edo_civil;
	char direccion[151];
	char telfh[13];
	char ref[11];
	char csuc[6];
}cliente;
typedef struct{
	char ccta[M];
	char ccli[M];
	char tcta;
	tipo_fecha faper;
	tipo_fecha fupi;	
	char csuc[M];
	float saldo;
}cuenta;
typedef struct{
	char csuc[M];
	char nsuc[MM];
	char dsuc[MM];
	char gsuc[M];
	int ccajeros;
}rsucursal;
typedef struct{
	char ref[M];
	char ccta[M];
	tipo_fecha ftrans;
	float mtrans;
	int topera;
	char csuc[M];
}transaccion;
///----------------------> VARIABLES GLOBALES
	cliente vCliente[MX];
	cuenta vCuenta[MX];
	rsucursal vSucursal[MX];
	transaccion vTransaccion[MX];
	int cantidad_clientes;
	int cantidad_cuentas;
	int cantidad_sucursales;
	int cantidad_transacciones;
///----------------------> FIN VARIABLES GLOBALES
interfaz(){
	char *p[3]={">","> >","> > >"};
	char *q[3]={"    <","  < <","< < <"};
	int i,j;
	float k;
	system("clear");
	for(i=0;i<5;i++){
		for(j=0;j<3;j++){
			printf("\n\n\n\n"CAM"\t\t\t\t\t%s"CB"Cargando Interfaz del Banco 100% Universitario"CAM"%s"CB"\n\n\n\n",q[j],p[j]);
			system("sleep 0.3");
			system("clear");
		}
	}
}
pres(){
	do{
		printf(ST CV"\t\t\t\t\t                                      .,      .,\n");
		printf(CV"\t\t\t\t\t                                   .@@@@@@;  h@@\n");
		printf(CV"\t\t\t\t\t ;X#@@@@:    i@@@@H:     r#@@@#r   @@@2 @@@ s@#\n");
		printf(CV"\t\t\t\t\ts@@@@@@@&   :@@@@@@@@@   @@@@@@@@@, 9@@@;@@Mi@3\n");
		printf(CV"\t\t\t\t\t  @@@@@    @@@@i 9@@@@ #@@@H r@@@@  ;3B@A.r@r  .\n");
		printf(CV"\t\t\t\t\t  @@@@@    @@@@S  @@@@ A@@@M  @@@@;      ;@Xr@@@@@;\n");
		printf(CV"\t\t\t\t\t  @@@@@    2@@@@  @@@@ :@@@@  @@@@      h@rX@@9 @@@\n");
		printf(CV"\t\t\t\t\t&G@@@@@#X.  H@@@@@@@@   2@@@@@@@@;     @@X s@@@;@@@\n");
		printf(CV"\t\t\t\t\tr#H33hAM@@;   .ShMMX,      shB#h;      i@9   :3B@H;\n\n\n");
		printf(CAZ"\t\t\t.@@@@@@@@@#h:\n");                                                                                 
		printf(CAZ"\t\t\t B@@@@@A@@@@@B"); 
		printf(CB"                                                             .r9@@@@A;\n");               
		printf(CAZ"\t\t\t #@@@@  @@@@@   ,5@@@Bs    :SH@,;#@Mr    .iH@@Mi     sA@@#2.");
		printf(CB"          .,r9@@@@@@@@@@@@@@Ms,\n");          
		printf(CAZ"\t\t\t #@@@@iB@@@M   @@@AX@@@@  @@@@@@@@@@@@  M@@@@@@@@r M@@@@@@@@#");
		printf(CB"        &@@@@@@@@@@@@@@@@@@@@@X\n");      
		printf(CAZ"\t\t\t @@@@@BH@@@@@  rHr :@@@@; ;@@@@2 G@@@@ 9@@@@  @@@sA@@@@ .@@@@M");
		printf(CB"        5@"CB"   ,@@@@@@@@@@@@@:\n");             
		printf(CAZ"\t\t\t @@@@@  S@@@@@ G@@@3@@@@.  @@@@. s@@@@ X@@@@      @@@@@  M@@@@");
		printf(CB"        s@"CB"   @@@@@@@@@@@@@\n");              
		printf(CAZ"\t\t\t @@@@@, @@@@@:&@@@2 @@@@@ ;@@@@i M@@@@  @@@@@  @@ ,@@@@# @@@@.");
		printf(CB"        h@"CB"  @@@@@@@@@@@@@@\n");              
		printf(CAZ"\t\t\t @@##@@@@@@@G  @@@@@9@@@@.@@@@@@.@@@@@@  2@@@@@@i  .A@@@@@M;");
		printf(CB"         @@"CB" ;@@@@@@@@@@@@@@.\n");             
		printf(CB"\t\t\t                                                                      .,  @@@@@@@@@@@@@.\n");              
		printf(CB"\t\t\t                                                                         H@@@@@@@@@@@@3\n");              
		printf(CB"\t\t\t                     ,rSi                                                 .r@@@@@@@@B\n");               
		printf(CB"\t\t\t                   ;SB"CAZ"##"CB"@5                                                  @@@@@@M\n");                 
		printf(CAZ"\t\t\t                  ,i"CAZ"i3X;"CB";"CAZ"rrr&#"CB "H,     ,;i:                               ,  &@@@@@X ,@@,\n");             
		printf(CB"\t\t\t               .r"CAZ"9MGhX2"CB";"CAZ"rGHMAAMH, :5A###"CB"#5                        ,@@@@@@  @@@@@s i@@@@@@3:,.\n");       
		printf(CB"\t\t\t               r5"CAZ"SA9XXX5"CB"i3"CAZ"GXX3GAHB#MAG99&#;"CB"                      s@@@@@@G r@@@@. H@@@@@@@@@@@i\n");      
		printf(CB"\t\t\t                i:"CAZ"sXir;;,"CB";X"CAZ"2Ss;,SA9X22223AB,"CB"                    5@@@@@@@: @@@@  @@@@@@@@@@@@@@G\n");     
		printf(CB"\t\t\t                 r;"CAZ";::,"CB",,"CAZ",::;sr,"CB"r2"CAZ"5522X2X"CB"Xi                   X@@@@@@@@  @@@  @@@@@@@rA@@@@@@@r\n");   
		printf(CB"\t\t\t                        ;i"CAZ"i5X3"CB"Xhs,5X"CAZ"2Ss;;;;"CB";                  r@@@@@@@@@ s@@  @@@@@@S   @@@@@@@ \n");    
		printf(CB"\t\t\t                     ;9HAh"CAZ"3X2222XX5r;"CB"::,.                   ,&@@@@@@@@@@ @@  @@@@@B;  #@@@@@@@@;\n");    
		printf(CB"\t\t\t                    ri"CAZ"XAX222552223r"CB"..                     ;@@@@@@@@@@@@i @  @@A;    i@@@@@@@@@@@\n");    
		printf(CB"\t\t\t                    ,s"CAZ":2X555552XX2"CB"S,                      @@@@@@@@@@@@@:  .2    . ;@@@@@@@@@@@@@\n");    
		printf(CB"\t\t\t                     :;"CAZ":XX22X2ir;"CB";r:                    ;@@@@@@@@@@@@@@: 2        s@@@@@@@@@@@@@\n");    
		printf(CB"\t\t\t                      ;;;"CAZ"25ir;::"CB",.                     r@@@@@@@@@@@@@@@r@          i@@@@@@@@@@@@\n");    
		printf(CB"\t\t\t                       ;;:;:,.                         2@@@@@@@@@@@@@@M@@#2r,i@@3@@@@@@@@@@@@@@@\n");    
		printf(CAM"            Realizado por:"CB "\t\t\t                             G@@@@@@@@@@@@@@@@@r r@@@@@@@@@@@@@@@@@@@@@@\n");  
		printf(CAM"                        Leon, Loana"CB"\t\t\t                      @@@@@@@@@@@@@@@:  2@@@@@@@@@@@@@@@@@@@@@@@\n");   
		printf(CAM"                        Reyes, Osval"CB"\t\t\t     	               @@@@@@@@@@@@@@2  @@@@@@@@@@@@@@@@@@@@@@@@\n");
		printf(CAM"               Algoritmos y Programacion - FACYT"CB"\t\t\t        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
		printf("\t\t\t\t\t\t"CR"PRESIONE ESCAPE Y ENTER PARA CONTINUAR"CB"\n\n\n\n");
	}while(getchar()!='\x1B');
}
menu(int *opc){
	char n[10];
	do{
		do{
			system("clear");
			printf(CAZ"\n\n\n\n\n\n\n\n");
			printf(CB"                     ,rSi\t\tMENU PRINCIPAL - 100% BANCO UNIVERSITARIO\n");
			printf(CB"                   ;SB"CAZ"##"CB"@\n");
			printf(CAZ"                  ,i"CAZ"i3X;"CB";"CAZ"rrr&#"CB "H,     ,;i:\n");
			printf(CB"               .r"CAZ"9MGhX2"CB";"CAZ"rGHMAAMH, :5A###"CB"#5\t\t\t"CB"\tOPCIONES:\n"CAZ);
			printf(CB"               r5"CAZ"SA9XXX5"CB"i3"CAZ"GXX3GAHB#MAG99&#;\t\t\t\t""===================\n");
			printf(CB"                i:"CAZ"sXir;;,"CB";X"CAZ"2Ss;,SA9X22223AB,"CB"\n");     
			printf(CB"                 r;"CAZ";::,"CB",,"CAZ",::;sr,"CB"r2"CAZ"5522X2X"CB"Xi\t\t\t\t\t"CB"1.- CARGAR ARCHIVOS\n"CAZ);
			printf(CB"                        ;i"CAZ"i5X3"CB"Xhs,5X"CAZ"2Ss"CB";;;;;\t\t\t\t\t2.- CARGAR DATOS\n");    
			printf(CB"                     ;9HAh"CAZ"3X2222XX5r;"CB"::,.\t\t\t\t\t"CB"3.- MODIFICAR DATOS\n");
			printf(CB"                    ri"CAZ"XAX222552223r"CB"..\t\t\t\t\t\t4.- CONSULTAR DATOS\n");
			printf(CB"                    ,s"CAZ":2X555552XX2"CB"S,\t\t\t\t\t\t5.- CALCULAR INTERESES\n");
			printf(CB"                     :;"CAZ":XX22X2ir"CB";;r:\t\t\t\t\t\t6.- BONO AMIGO REFERIDO\n");
			printf(CB"                      ;;;"CAZ"25ir"CB";::,.\t\t\t\t\t\t7.- MOSTRAR TRANSACCIONES\n");
			printf(CB"                       ;;:;:,.\t\t\t\t\t\t\t8.- ACERCA DE...\n");
			printf(CB"\t\t\t\t\t\t\t\t\t\t9.- SALIR\n");
			printf(CB"\n\n\n\n\t\t\t\t\t\t\t\t\t ->");
					scanf(" %[^\n]", n);
			if(strlen(n)!=1){
				printf(CR"\v\t\t\t\t\t\t\t\t\t\t<< Opcion Incorrecta >>"CB"\n\n");
				sleep(3);
			}
		}while(strlen(n)!=1);
		*opc=atoi(n);
	}while(*opc<1||*opc>9);
}
menu_arc(int *opc){
	char n[10];
	do{
		do{
			system("clear");
			printf("\n\n\n\t\t\tMENU DE ARCHIVOS - 100% BANCO UNIVERSITARIO\n");
			printf(CB"\n\n\n\t\t\t\t\tOPCIONES PARA CARGAR:\n");
			printf(CAZ"\t\t\t\t\t===================\n\n"CB);
			printf("\t\t\t\t\t\t1.- CARGAR SUCURSALES\t\t\"Sucursales.in\"\n");
			printf("\t\t\t\t\t\t2.- CARGAR CLIENTES\t\t\"Clientes.in\"\n");
			printf("\t\t\t\t\t\t3.- CARGAR CUENTAS\t\t\"Cuentas.in\"\n");
			printf("\t\t\t\t\t\t4.- CARGAR TRANSACCIONES\t\"Transacciones.in\"\n");
			printf("\t\t\t\t\t\t5.- VOLVER AL MENU PRINCIPAL\n");
			printf("\n\n\t\t\t\t\t -> ");
					scanf(" %[^\n]", n);
			if(strlen(n)!=1){
				printf(CR"\v\t\t\t\t\t\t\t\t\t\t<< Opcion Incorrecta >>"CB"\n\n");
			sleep(2);
			}
		}while(strlen(n)!=1);
		*opc=atoi(n);
	}while(*opc<1||*opc>5||*opc==0);
}
menu_dat(int *opc){
	char n[10];
	do{
		do{
			system("clear");
			printf("\n\n\n\t\t\tMENU DE INGRESO POR TECLADO - 100% BANCO UNIVERSITARIO\n");
			printf(CB"\n\n\n\t\t\t\t\tOPCIONES PARA CARGAR:\n");
			printf(CAZ"\t\t\t\t\t===================\n\n"CB);
			printf("\t\t\t\t\t\t1.- INGRESAR NUEVAS SUCURSALES\n");
			printf("\t\t\t\t\t\t2.- INGRESAR NUEVOS CLIENTES\n");
			printf("\t\t\t\t\t\t3.- INGRESAR NUEVAS CUENTAS\n");
			printf("\t\t\t\t\t\t4.- INGRESAR NUEVAS TRANSACCIONES\n");
			printf("\t\t\t\t\t\t5.- VOLVER AL MENU PRINCIPAL\n");
			printf("\n\n\t\t\t\t\t -> ");
					scanf(" %[^\n]", n);
			if(strlen(n)!=1){
				printf(CR"\v\t\t\t\t\t\t\t\t\t\t<< Opcion Incorrecta >>"CB"\n\n");
				sleep(2);
			}
		}while(strlen(n)!=1);
		*opc=atoi(n);
	}while(*opc<1||*opc>5);
}
menu_mod(int *opc){
	char n[10];
	do{
		do{
			system("clear");
			printf("\n\n\n\t\t\tMENU DE MODIFICACION DE DATOS - 100% BANCO UNIVERSITARIO\n");
			printf(CB"\n\n\n\t\t\t\t\tOPCIONES PARA MODIFICAR:\n");
			printf(CAZ"\t\t\t\t\t===================\n\n"CB);
			printf("\t\t\t\t\t\t1.- MODIFICAR SUCURSALES\n");
			printf("\t\t\t\t\t\t2.- MODIFICAR CLIENTES\n");
			printf("\t\t\t\t\t\t3.- MODIFICAR CUENTAS\n");
			printf("\t\t\t\t\t\t4.- VOLVER AL MENU PRINCIPAL\n");
			printf("\n\n\t\t\t\t\t -> ");
					scanf(" %[^\n]", n);
			if(strlen(n)!=1){
				printf(CR"\v\t\t\t\t\t\t\t\t\t\t<< Opcion Incorrecta >>"CB"\n\n");
				sleep(2);
			}
		}while(strlen(n)!=1);
		*opc=atoi(n);
	}while(*opc<1||*opc>4);
}
menu_con(int *opc){
	char n[10];
	do{
		do{
			system("clear");
			printf("\n\n\n\t\t\tMENU CONSULTA DE REGISTRO - 100% BANCO UNIVERSITARIO\n");
			printf(CB"\n\n\n\t\t\t\t\tOPCIONES PARA CONSULTA:\n");
			printf(CAZ"\t\t\t\t\t===================\n\n"CB);
			printf("\t\t\t\t\t\t1.- CONSULTAR SUCURSALES\n");
			printf("\t\t\t\t\t\t2.- CONSULTAR CLIENTES\n");
			printf("\t\t\t\t\t\t3.- CONSULTAR CUENTAS\n");
			printf("\t\t\t\t\t\t4.- CONSULTAR TRANSACCIONES\n");
			printf("\t\t\t\t\t\t5.- VOLVER AL MENU PRINCIPAL\n");
			printf("\n\n\t\t\t\t\t -> ");
				scanf(" %[^\n]", n);
			if(strlen(n)!=1){
				printf(CR"\v\t\t\t\t\t\t\t\t\t\t<< Opcion Incorrecta >>"CB"\n\n");
				sleep(2);
			}
		}while(strlen(n)!=1);
		*opc=atoi(n);
	}while(*opc<1||*opc>5);
}

monto(float *m){
	char v[M],n;
	int b,p,i,bb,pp;
		do{
			do{
				do{
					printf("Introduzca la Monto de la Transaccion:\n\n\tNOTA: Para la separacion entre Enteros y Decimales se usará \".\"\n\t\tEjem:Bs 215478.58\n\nBs ");
						scanf(" %[^\n]", v);
				}while(strlen(v)>13);
					b=0;
					p=0;
					bb=0;
					pp=0;
				for(i=0;i<strlen(v);i++){
					strncpy(&n, &v[i],1);
					if(n!='.'&&!isdigit(n)){
						b+=1;
					}
					if(n=='.'){
						p+=1;
						pp=i;
					}
				}
				for(i=pp+1;i<strlen(v);i++){
					strncpy(&n, &v[i],1);
					if(isdigit(n)){
						bb+=1;
					}
				}
				if(p>1){
					printf(ST CR"\t\t\tNo puede haber mas de un Punto Decimal en una cantidad de dinero, Intente de Nuevo"CB"\n\n\n");
				}
				if(p==1&&bb!=1&&bb!=2){
					printf(ST CR"\t\t\tNo pueden existir haber más de dos decimales en la Cantidad de dinero, Intente de Nuevo");
					printf("\n\t\t\t\t\t Ejem: 128000.00"CB"\n\n\n");
				}
				if(p==0&&strlen(v)>10){
					printf(ST CR"\t\t\tEl Monto Maximo permitido no puede exceder de 10 Digitos, Intente de Nuevo");
					printf("\n\t\t\t\t\t Ejem: 1000000000"CB"\n\n\n");
				}
			}while((p==1&&bb!=1&&bb!=2)||(p==0&&strlen(v)>10)||pp==0||p>1);
		}while(b>0);
		*m=atof(v);
}
ref(char ref[]){
int j,b;
char n;
	do{
		do{
			printf("\t\t\tIntroduzca la Referencia de Cuenta:\v\tEjem: 2345612A\n\n\t\t\t\t-> ");
				scanf(" %[^\n]", ref);
			if(strlen(ref)>8){
				printf(ST CR"\t\t\tIngresó un Codigo de Referencia muy largo, Intente de Nuevo"CB"\n\n\n");
			}
			if(strlen(ref)<8){
				printf(ST CR"\t\t\tIngresó un Codigo de Referencia muy corto, Intente de Nuevo"CB"\n\n\n");
			}
		}while(strlen(ref)!=8);
		b=0;
		for(j=0;j<7;j++){
			strncpy(&n, &ref[j],1);
			if(isdigit(n)){
				b+=1;
			}
		}
		if(b!=7){
				printf(ST CR"\t\t\tLos Primeros Siete Digitos del Codigo de Referencia deben ser números, Intente de Nuevo"CB"\n\n\n");
		}
		else{	
			strncpy(&n, &ref[7],1);
			if(isalpha(n)){
				b+=1;
				n=toupper(n);
				strncpy(&ref[j],&n,1);
			}
			if(b!=8){
				printf(ST CR"\t\t\tEl 8vo Digito del Codigo de Referencia debe ser una letra, Intente de Nuevo"CB"\n\n\n");
			}
		}
	}while(b!=8);
}
FechaSistema(int *d, int *m, int *a){
	FILE *fs;
	system("date +%d/%m/%Y > factual");
	fs = fopen("factual", "r");
	fscanf(fs, "%d/%d/%d", &*d,&*m,&*a);
	fclose(fs);
	system("rm factual");
}
fecha(int *di, int *me, int *an, int t){
    char dm[M],a[M],f[M];
    int x,y,z;
    int b,c;
	do{
		do{
			do{
				do{
					do{
						if(t==1){
							printf("\t\tIntroduzca la Fecha de la Transaccion:\t\vEjem: 01-01-2000\n\n\t\t-> ");
						}
						if(t==2){
							printf("\t\tIntroduzca la Fecha de Apertura:\t\vEjem: 01-01-2000\n\n\t\t-> ");
						}
						if(t==3){
							printf("\t\tIntroduzca la Fecha del Última Pago de Interes:\t\vEjem: 01-01-2000\n\n\t\t-> ");
						}
						if(t==4){
							printf("\t\tIntroduzca la Fecha Inicio Para Mostrar Transacciones:\t\vEjem: 01-01-2000\n\n\t\t-> ");
						}
						if(t==5){
							printf("\t\tIntroduzca la Fecha Fin Para Mostrar Transacciones:\t\vEjem: 01-01-2000\n\n\t\t-> ");
						}
						if(t==6){
							printf("\t\tIntroduzca la Fecha Limite para Calcular el Bono Amigo Referido de todos los Clientes Existentes:\n\t\t\t\t\vEjem: 01-01-2000\n\n\t\t-> ");
						}
						if(t==7){
							printf("\t\tIntroduzca la Fecha Inicial para el Calculo de Dias de los Intereses Bancarios:\n\t\t\t\t\vEjem: 01-01-2000\n\n\t\t-> ");
						}
						if(t==8){
							printf("\t\tIntroduzca la Fecha Final para el Calculo de Dias de los Intereses Bancarios:\n\t\t\t\t\vEjem: 01-01-2000\n\n\t\t-> ");
						}
								scanf(" %[^\n]",f);
					}while(strlen(f)!=10);
				}while(strncmp(&f[2],"\x2F",1)!=0&&strncmp(&f[5],"\x2F",1)!=0&&strncmp(&f[2],"\x2D",1)!=0&&strncmp(&f[5],"\x2D",1)!=0);
			}while(strncmp(&f[2],"\x2F",1)!=0&&strncmp(&f[5],"\x2D",1)!=0);
		}while(strncmp(&f[2],"\x2D",1)!=0&&strncmp(&f[5],"\x2F",1)!=0);
		FechaSistema(&x,&y,&z);
		strcpy(a, &f[6]);
			*an=atoi(a);
		strncpy(dm, &f[3],2);
		strcpy(&dm[2]," ");
			*me=atoi(dm);
		strncpy(dm, f,2);
		strcpy(&dm[2]," ");
			*di=atoi(dm);
        b=0;
        if(*an>=1994&&*an<=z){
			if(*me==2&&*di>=30&&(*an==1996||*an==2000||*an==2004||*an==2008)){
				printf(ST CR"\t\t\t%d es Bisiesto, por lo tanto el mes de Febrero solo tiene 29 Dias, Intente de Nuevo"CB"\n\n\n", *an);
			}
			if(*me==2&&*di>=1&&*di<=29&&(*an==1996||*an==2000||*an==2004||*an==2008)){
				b+=1;
			}	
			if(*me==2&&*di>=29&&(*an!=1996&&*an!=2000&&*an!=2004&&*an!=2008)){
				printf(ST CR"\t\t\t%d no es Bisiesto, por lo tanto el mes de Febrero solo tiene 28 Dias, Intente de Nuevo"CB"\n\n\n", *an);
			}
			if(*me==2&&*di>=1&&*di<=28&&(*an!=1996&&*an!=2000&&*an!=2004&&*an!=2008)){
				b+=1;
			}			
        }
        if(*me>=1&&*me<=12){
			if((*me==4||*me==6||*me==9||*me==11)&&*me!=2&&*di>=31){
				printf(ST CR"\t\t\tEste mes no tiene mas de 31 Dias, Intente de Nuevo"CB"\n\n\n");
			}
			if((*me==4||*me==6||*me==9||*me==11)&&*me!=2&&*di>=1&&*di<=30){
				b+=1;
			}
			if((*me!=4&&*me!=6&&*me!=9&&*me!=11)&&*me!=2&&(*di<1||*di>31)){
				printf(ST CR"\t\t\tAbril, Junio, Septiembre, Noviembre tienen de 1 a 31 Dias, Intente de Nuevo"CB"\n\n\n");
			}
			if((*me!=4&&*me!=6&&*me!=9&&*me!=11)&&*me!=2&&*di>=1&&*di<=31){
				b+=1;
			}
        }
        c=0;
        if(*an==z&&*me==y&&*di>x){
        	c+=1;
			printf(ST CR"\t\t\tEl Dia no puede ser mayor que el Dia Actual, Intente de Nuevo"CB"\n\n\n");
        }
        else if(*an==z&&*me>y){
        	c+=1;
        	printf(ST CR"\t\t\tEl Mes no puede ser mayor que el Mes Actual, Intente de Nuevo"CB"\n\n\n");
        }
        else if(*an<1994||*an>z){
        	c+=1;
        	if(*an>z){
				printf(ST CR"\t\t\tEl Año no puede ser mayor que el Año Actual, Intente de Nuevo"CB"\n\n\n");
        	}
        	else{
				printf(ST CR"\t\t\tEl Año no puede ser menor que 1994, Intente de Nuevo"CB"\n\n\n");	
        	}
        }
	}while(b!=1||c!=0);
}
CD(int di, int mi, int ai, int df, int mf, int af, int *aux){
	int dxm;
	*aux=0;
 	if(ai==af && mi==mf && di<=df){ 
		*aux=df-di; 
	} 
	else{ 	 
		while(mi<13) { 
			switch(mi) { 
				case 2:{
					if(ai%4!=0){ 
						dxm=28-di;
					} 
					else if(ai%100!=0){
						dxm=29-di;
					} 
					else if(ai%400!=0){
						dxm=28-di;
					}
					else{
						dxm=29-di;
					}
				}break; 
				case 4: case 6: case 9: case 11:{ 
					dxm=30-di; 
				}break; 
				default:{
					dxm=31-di; 
				}
			}
			if(ai==af){
				if(mi==mf) { 
					*aux+=df; 
					break; 
				} 
			}
			*aux+=dxm; 
			if(mi==12) { 
				ai++; 
				mi=1; 
			}
			else{
				mi++; 
				di=0; 
			}
		}
	}
}
Saldo(cuenta cu[],transaccion tr[], int ctr, int ccu){
	int i,j;
	for(i=0;i<ccu;i++){
		cu[i].saldo=0;
		for(j=0;j<ctr;j++){
			if(strcmp(cu[i].ccta,tr[j].ccta)==0){
				switch(tr[j].topera){
					case 1:{
						if(cu[i].saldo>=0&&cu[i].saldo-tr[j].mtrans>=0){
							cu[i].saldo-=tr[j].mtrans;
						}
						else{
							cu[i].saldo=-1;
						}
							
					}break;
					case 2:{
						cu[i].saldo+=tr[j].mtrans;
					}break;
					case 3:{
						if(cu[i].saldo>=0&&cu[i].saldo-tr[j].mtrans>=0){
							cu[i].saldo-=tr[j].mtrans;
						}
						else{
							cu[i].saldo=-1;
						}
					}break; 
					case 4:{
						cu[i].saldo+=tr[j].mtrans;
					}break;
				}
			}
		}
	}
}	
Pregunta(char *n, int i){
//----------------------> FIN DEL REGISTRO DE CUENTAS SII EL USUARIO ASI LO DESEA
	char resp[M];
			do{
				do{

					if(i==1){
						printf(CAM"\t\t¿ Desea Continuar Nuevos Clientes?  [S/N]"CB"\n\n\t\t-> ");
					}
					if(i==2){
						printf(CAM"\t\t¿ Desea Continuar Nuevas Cuentas?  [S/N]"CB"\n\n\t\t-> ");
					}
					if(i==3){
						printf(CAM"\t\t¿ Desea Continuar Nuevas Sucursales?  [S/N]"CB"\n\n\t\t-> ");
					}
					if(i==4){
						printf(CAM"\t\t¿ Desea Continuar Nuevas Transacciones?  [S/N]"CB"\n\n\t\t-> ");
					}
					if(i==5){
						printf(CAM"\t\tIngrese: \"S\", para Modificarlo, \"N\" para volver al Menu Principal"CB"\n\n\t\t-> ");
					}
					if(i==6){
						printf(CAM"\t\tIngrese: \"S\", para Modificarla, \"N\" para volver al Menu Principal"CB"\n\n\t\t-> ");
					}
					if(i==7){
						printf(CAM"\t\tDesea Volver al Menu Principal? [S.- Si / N.- No]"CB"\n\n\t\t-> ");
					}

						scanf(" %[^\n]", resp);
				}while(strlen(resp)!=1);
				strncpy(&*n, resp,1);
				*n=toupper(*n);
			}while(*n!='S'&&*n!='N');
}//----------------------> FIN DEL REGISTRO DE CUENTAS SII EL USUARIO ASI LO DESEA
nocta(char ccta[]){
	int t,i;
	char n;
	do{
		do{
			do{
				printf("\t\tIntroduzca el Codigo de la Cuenta:\n\t\t\t\t\t\tEjem: 0102-0506-80-0000040546\n\n\t\t-> ");
					scanf(" %[^\n]", ccta);
				if(strlen(ccta)!=23){
				printf(ST CR"\t\t\tEl numero de la Cuenta debe de tener 23 Caracteres en total, Intente de Nuevo"CB"\n\n\n");
			}
			}while(strlen(ccta)!=23);
			if(strncmp(&ccta[4], "\x2D",1)==0&&strncmp(&ccta[9], "\x2D",1)==0&&strncmp(&ccta[12], "\x2D",1)==0){
				t=1;
			}
			if(t!=1){
				printf(ST CR"\t\tEl numero de la Cuenta debe tener 3 Guiones '\x2D' en las posiciones 5, 10 y 13, Intente de Nuevo"CB"\n\n\n");
			}
		}while(t!=1);
		t=0;
		for(i=0;i<23;i++){
			strncpy(&n,&ccta[i],1);
			if(i!=4&&i!=9&&i!=12&&isdigit(n)){
				t+=1;
			}
		}
		if(t!=20){
				printf(ST CR"\t\t\tEl numero de la Cuenta debe tener 20 Caracteres Numericos, Intente de Nuevo"CB"\n\n\n");
		}
	}while(t!=20);
}
sucursal(char aux[],int t){
	char cod[M],n;
	int i,b;
	b=0;
	do{
		do{
			do{
				if(t==1){
					printf("\t\tIntroduzca el Codigo de la Sucursal:\t\vEjem: BU001\n\n\t\t-> ");
				}
				if(t==2){
					printf("\t\tIntroduzca el Codigo de la Nueva Sucursal:\t\vEjem: BU001\n\n\t\t-> ");
				}
				if(t==3){
					printf("\t\tIntroduzca el Codigo de la Sucursal a Consultar:\t\vEjem: BU001\n\n\t\t-> ");
				}
				if(t==4){
				printf("\t\tIntroduzca el Codigo de la Sucursal a Modificar:\n\tEjem: BU001, BU: Son letras y 001:Numeros\n\n\t\t-> ");
				}
					scanf(" %[^\n]",cod);
				if(strlen(cod)!=5){
					printf(ST CR"\t\t\tEl Codigo de Sucursal que ingresó es incorrecto,\n");
					printf("\t\tYa que esta contiene las iniciales del Banco y 3 Caracteres Numericos, Intente de Nuevo"CB"\n\n\n");
			}
			}while(strlen(cod)!=5);		
			for(i=0;i<2;i++){
				strncpy(&n,&cod[i],1);
				n=toupper(n);
				if(n=='B'&&i==0){
					b=1;
				strcpy(&aux[i],&n);
				}
				if(n=='U'&&i==1){
					b+=1;
				strcpy(&aux[i],&n);
				}			
			}
			if(b!=2){
				printf(ST CR"\t\t\tLos Dos Primeros Caracteres del Codigo de la Sucursal son 'BU', Intente de Nuevo"CB"\n\n\n");
			}
		}while(b!=2);
		strcpy(&aux[2], "");
		for(i=2;i<5;i++){
			strncpy(&n,&cod[i],1);
			if(isdigit(n)){
				b+=1;
				strncpy(&aux[i],&n,1);
			}
		}
		strcpy(&aux[5], "");
	}while(b!=5);
}
cedula(char ci[],int t){
	char aux[M];
	char n,m;
	int i,b;
		do{
			do{
				do{
					if(t==1){
						printf("\t\tIntroduzca la Cedula del Cliente:\n\t\t\tEjem: X-81256253, X puede ser V: Venezolana ó E: Extranjero\n\n\t\t-> ");
					}
					if(t==2){
						printf("\t\tIntroduzca la Referencia del Cliente:\n\t\t\t Ejem: X-81256253, X puede ser V: Venezolana ó E: Extranjero\n\n\t\t-> "); 
					}		
					if(t==3){
						printf("\t\tIntroduzca la Cedula del Cliente a Consultar:\n\t\t\tEjem: X-81256253, X puede ser V: Venezolana ó E: Extranjero\n\n\t\t-> "); 
					}
					if(t==4){
						printf("Introduzca la Cedula del Cliente a Modificar:\n Ejem: X-81256253, X puede ser V: Venezolana ó E: Extranjero\n\n-> "); 
					}
						scanf(" %[^\n]", ci);
					if(strlen(ci)!=10){
						printf(ST CR"\t\t\tIngresó la Cedula Incorrectamente, Intente de Nuevo"CB"\n\n\n");
					}
				}while(strlen(ci)!=10);
				strcpy(&n, ci);
				n=toupper(n);
				m=n;
				if(n!='V'&&n!='E'||strncmp(&ci[1], "-",1)!=0){
					printf(ST CR"\t\t\tIngresó La Nacionalidad Incorrecta, Intente de Nuevo"CB"\n\n\n");
				}
			}while(n!='V'&&n!='E'||strncmp(&ci[1], "-",1)!=0);
				strcpy(&n, ci);
				strcpy(ci,&ci[2]);
				b=0;
				for(i=0;i<8;i++){
					strncpy(&n, &ci[i],1);
					if(isdigit(n)){
						b+=1;
					}
				}
				strcpy(ci,"");
				strncat(ci, &m,1);
				strcat(ci, aux);
				if(b!=8){
					printf(ST CR"\t\tNo puede haber caracteres que no sean numericos luego del '\x2D', Intente de Nuevo"CB"\n\n\n");
				}
		}while(b!=8||strlen(ci)!=10);
}

Archivo_Cuentas(cuenta v[], int *c){
	int cant;
	FILE *cuentas;
	if((cuentas =fopen("Cuentas.in","r"))==NULL){
		printf(ST LC RES"\t\t\tNo Encuentro el archivo solicitado para trabajar \"Cuentas.in\""CB LC"\n\n\n");
	}
	else{
		*c=0;
		while(feof(cuentas)==0){
			fscanf(cuentas, " %s", v[*c].ccli);
			fscanf(cuentas, " %s", v[*c].ccta);
			fscanf(cuentas, " %c", &v[*c].tcta);
			fscanf(cuentas, "%d\x2F%d\x2F%d", &v[*c].faper.dia,&v[*c].faper.mes,&v[*c].faper.ano);
			fscanf(cuentas, "%d\x2F%d\x2F%d", &v[*c].fupi.dia,&v[*c].fupi.mes,&v[*c].fupi.ano);
			fscanf(cuentas, " %s", v[*c].csuc);
			CD(v[*c].faper.dia,v[*c].faper.mes,v[*c].faper.ano,v[*c].fupi.dia,v[*c].fupi.mes,v[*c].fupi.ano,&cant);
			if(cant>15){
				*c-=1;
			}
			*c+=1;
		}
		fclose(cuentas);
		*c-=1;
	}
}
Archivo_Sucursal(rsucursal v[], int *c){
	FILE *sucursales;

	if((sucursales =fopen("Sucursales.in","r"))==NULL){
		printf(ST LC RES"\t\t\tNo Encuentro el archivo solicitado para trabajar \"Sucursales.in\""CB LC"\n\n\n");
	}
	else{
		*c=0;
		while(!feof(sucursales)){
			fscanf(sucursales, " %s", v[*c].csuc);
			fscanf(sucursales, " %[^\n]", v[*c].nsuc);
			fscanf(sucursales, " %[^\n]", v[*c].dsuc);
			fscanf(sucursales, " %[^\n]", v[*c].gsuc);
			fscanf(sucursales, "%d", &v[*c].ccajeros);
		*c+=1;
		}
		fclose(sucursales);
		*c-=1;
	}
}
Archivo_Clientes(cliente v[], int *c){
	int b,i,o[MX],j,k;
	FILE *clientes;
	FILE *out;
	if((clientes =fopen("Clientes.in","r"))==NULL){
		printf(ST LC RES"\t\t\tNo Encuentro el archivo solicitado para trabajar \"Clientes.in\""CB LC"\n\n\n");
	}
	else{
		while(!feof(clientes)){
			fscanf(clientes, " %s", v[*c].cedula);
			fscanf(clientes, " %[^\n]", v[*c].nombre);
			fscanf(clientes, " %[^\n]", v[*c].apellido);
			fscanf(clientes, " %c", &v[*c].sexo);
			fscanf(clientes, " %c", &v[*c].edo_civil);
			fscanf(clientes, " %[^\n]", v[*c].direccion);
			fscanf(clientes, " %s", v[*c].telfh);
			fscanf(clientes, " %s", v[*c].ref);
			fscanf(clientes, " %s", v[*c].csuc);
			*c+=1;
		}
		fclose(clientes);
		*c-=1;
	}
}
Archivo_Transaccion(transaccion v[], int *c){
	FILE *transacciones;
	if((transacciones =fopen("Transacciones.in","r"))==NULL){
		printf(ST LC RES"\t\t\tNo Encuentro el archivo solicitado para trabajar \"Transacciones.in\""CB LC"\n\n\n");
	}
	else{
		*c=0;
		while(!feof(transacciones)){
			fscanf(transacciones, " %s", v[*c].ref);
			fscanf(transacciones, " %s", v[*c].ccta);
			fscanf(transacciones, "%d\x2F%d\x2F%d", &v[*c].ftrans.dia,&v[*c].ftrans.mes,&v[*c].ftrans.ano);
			fscanf(transacciones, " %f", &v[*c].mtrans);
			fscanf(transacciones, " %d", &v[*c].topera);
			fscanf(transacciones, " %s", v[*c].csuc);
		*c+=1;
		}
		fclose(transacciones);
		*c-=1;
	}
}

OPERACIONES(cuenta v[], int c, rsucursal w[], int b, cliente y[], int a,transaccion x[], int d){
		FILE *out;
		int i,j,k,l,m,o[MX],q[MX],r[MX];
		for(i=0;i<MX;i++){
			o[i]=0;
			r[i]=0;
			q[i]=0;
		}
		k=0;
		out = fopen("Cuentas.out","w");
		for(i=0;i<c;i++){
			for(j=0;j<b;j++){
				if(strcmp(v[i].csuc,w[j].csuc)==0){
					for(l=0;l<a;l++){
						if(strcmp(v[i].ccli,y[l].cedula)==0){
							fprintf(out, "OPERACION EXITOSA\n\n");
							o[k]=1;
						}
					}
				}
			}
			if(o[k]!=1){
				fprintf(out,"OPERACION FALLIDA\n\n");
			}
			k+=1;
		}
		fclose(out);
		k=0;
		out = fopen("Clientes.out","w");
		for(i=0;i<a;i++){
			for(j=0;j<a;j++){
				if(q[k]==0&&i!=j&&strcmp(y[i].cedula,y[j].ref)==0){
					fprintf(out, "OPERACION EXITOSA\n\n");
					q[k]=1;
				}
			}
			if(q[k]!=1){
				fprintf(out,"OPERACION FALLIDA\n\n");
			}
			k+=1;
		}
		fclose(out);
		k=0;
		out = fopen("Transacciones.out","w");
		for(i=0;i<c;i++){///RECORRE EL VECTOR DE REGISTROS DE CUENTAS
			for(j=0;j<b;j++){///RECORRE EL VECTOR DE REGISTROS DE SUCURSALES
				if(strcmp(v[i].csuc,w[j].csuc)==0){ ///CONDICION QUE SE CUMPLE SII EXISTE UNA CUENTA INSCRITA EN UNA SUCURSAL
					for(l=0;l<a;l++){///RECORRE EL VECTOR DE REGISTROS DE CLIENTES
						if(strcmp(v[i].ccli,y[l].cedula)==0){ ///CONDICION QUE SE CUMPLE SII EXISTE UNA CUENTA QUE ESTA ASOCIADA A UN CLIENTE
							for(m=0;m<d;m++){///RECORRE EL VECTOR DE REGISTRO DE LAS TRANSACCIONES 
								if(strcmp(v[i].ccta,x[m].ccta)==0){///CONDICION QUE SE CUMPLE SII EXISTE UN ELEMENTO QUE PERTENECE AL 
																   ///VECTOR DE REGISTRO DE LAS TRANSACCIONES QUE TAMBIEN PERTENECE AL
																   ///VECTOR DE REGISTRO DE LAS CUENTAS
									fprintf(out, "OPERACION EXITOSA\n\n");
									r[k]=1;
								}
							}
						}
					}
				}
			}
			if(r[k]!=1){
				fprintf(out,"OPERACION FALLIDA\n\n");
			}
			k+=1;
		}
		fclose(out);
}

Busca_Cedula(cliente v[], int c, int *b, char ci[]){
	int j;
	*b=0;
	for(j=0;j<c+1;j++){
		if(strcmp(v[j].cedula, ci)==0){
			*b+=1;
		}
	}
	if(*b>1){
		printf(ST LC RES"\t\t\t\tLa Cedula Introducida \"%s\", ya existe para otro Cliente\n",ci);
		printf("\t\t\t\tIntente de Nuevo con una Cedula de Identidad Distinta"CB LC"\n\n\n\n");
	}
}
Busca_Sucursal(rsucursal v[], int c, int *b, char cod[]){
	int j;
	*b=0;
	for(j=0;j<c+1;j++){
		if(strcmp(v[j].csuc, cod)==0){
			*b+=1;
		}
	}
	if(*b>1){
		printf(ST LC RES"\t\t\t\tIntente de Nuevo con un Codigo de Sucursal Distinto");
		printf("\n\t\t  El Codigo de la Sucursal: \"%s\", ya existe para el Banco 100\x25 Universitario"CB LC"\n\n\n\n",cod);
	}
}
Busca_Cuenta(cuenta v[], int c,int *b, char cod[]){
	int j;
	*b=0;
	for(j=0;j<c+1;j++){
		if(strcmp(v[j].ccta, cod)==0){
			*b+=1;
		}
	}
	if(*b>1){
		printf(ST LC RES"\t\t\t\tEl Codigo de Cuenta que ha ingresado ya existe\n");
		printf("\t\t\t\"%s\", es una cuenta existente en el Sistema Bancario"CB LC"\n\n\n\n",cod);
	}
}
Busca_Referencia(transaccion v[], int c,int *b, char ref[]){
	int j;
	*b=0;
	for(j=0;j<c+1;j++){
		if(strcmp(v[j].ref, ref)==0){
			*b+=1;
		}
	}
	if(*b>1){
		printf(ST LC RES"\t\t\t    Intente de Nuevo con un Codigo de Referencia de Transaccion\n");
		printf("\t\t\t\t \"%s\", ya que existe como otra Transaccion"CB LC"\n\n\n\n",ref);
	}
}

Carga_Clientes(cliente v[], int *i, int mod, int *c){
	int l,j;
	int b;
	char n,m,t[M];
	do{
		if(mod==0){
			system("clear");	
//-------------------->CEDULA
			do{
				cedula(v[*i].cedula,1);
				Busca_Cedula(vCliente, cantidad_clientes, &l, v[*i].cedula);
			}while(l>1);
//-------------------->FIN CEDULA
//-------------------->NOMBRE DEL CLIENTE
			do{
				printf("\t\tIntroduzca el Nombre del Cliente:\v\tEjem: Jose Angel, Max 50 Caracteres\n\n\t\t-> ");
					scanf(" %[^\n]", v[*i].nombre);
				if(strlen(v[*i].nombre)>50){
					printf(ST CR "\t\t\tIngreso de Nombre del Cliente Incorrecto, Intente de Nuevo"CB"\n\n\n");
				}
			}while(strlen(v[*i].nombre)>50);
//-------------------->FIN NOMBRE DEL CLIENTE
//-------------------->APELLIDO
			do{
				printf("\t\tIntroduzca el Apellido del Cliente:\v\tEjem: Perez Rojas, Max 50 Caracteres\n\n\t\t-> ");
					scanf(" %[^\n]", v[*i].apellido);
				if(strlen(v[*i].apellido)>50){
					printf(ST CR"\t\t\tIngreso de Apellido del Cliente Incorrecto, Intente de Nuevo"CB"\n\n\n");
				}
			}while(strlen(v[*i].apellido)>50);
//-------------------->FIN APELLIDO
//-------------------->SEXO 
			do{
				do{
					printf("\t\tIntroduzca el Sexo del Cliente:\v\tEjem: M: Masculino, F:Femenino\n\n\t\t-> ");
							scanf(" %[^\n]", t);
					if(strlen(t)!=1){
						printf(ST CR"\t\tPara Indicar el Sexo Solo se necesita de un caractér, Intente de Nuevo"CB"\n\n\n");
					}
				}while(strlen(t)!=1);
				strncpy(&v[*i].sexo,&t[0],1);
				v[*i].sexo=toupper(v[*i].sexo);
				n=v[*i].sexo;
				if(v[*i].sexo!='M'&&v[*i].sexo!='F'){
					printf(ST CR"\t\t\tOpcion Incorrecta, Intente de Nuevo"CB"\n\n\n");
				}
			}while(v[*i].sexo!='M'&&v[*i].sexo!='F');
//-------------------->FIN SEXO
//-------------------->ESTADO CIVIL
			do{
				do{
					printf("\t\tIntroduzca el Estado Civil del Cliente:\n\t\t\t\t\vEjem: S: Soltero, D: Divorciado, V: Viudo, O: Otro\n\n\t\t-> ");
						scanf(" %[^\n]", t);
				if(strlen(t)!=1){
					printf(ST CR"\t\tPara indicar el Estado Civil Solo se necesita de un caractér, Intente de Nuevo"CB"\n\n\n");
				}
				}while(strlen(t)!=1);
				strncpy(&v[*i].edo_civil,&t[0],1);
				v[*i].edo_civil=toupper(v[*i].edo_civil);
				if(v[*i].edo_civil!='S'&&v[*i].edo_civil!='D'&&v[*i].edo_civil!='V'&&v[*i].edo_civil!='O'){
					printf(ST CR"\t\t\tOpcion Incorrecta, Intente de Nuevo"CB"\n\n\n");
				}
			}while(v[*i].edo_civil!='S'&&v[*i].edo_civil!='D'&&v[*i].edo_civil!='V'&&v[*i].edo_civil!='O');
//-------------------->FIN ESTADO CIVIL
//-------------------->DIRECCION
			do{
				printf("\t\tIntroduzca la Direccion del Cliente:\v\t Max 150 Caracteres\n\n\t\t-> ");
						scanf(" %[^\n]", v[*i].direccion);
				if(strlen(v[*i].direccion)>150){
					printf(ST CR"\t\t\tLa Longitud de la Direccion Excede en lo permitido, Intente de Nuevo"CB"\n\n\n");
				}
			}while(strlen(v[*i].direccion)>150);
//-------------------->FIN DIRECCION
//-------------------->TELEFONO
			do{
				do{
					printf("\t\tIntroduzca el Telefono de la Habitacion:\v\t Ejem: 0241-8555212\n\n\t\t-> ");
						scanf(" %[^\n]",v[*i].telfh);
				}while(strlen(v[*i].telfh)!=12);
				b=0;
				for(j=0;j<13;j++){
					strncpy(&n, &v[*i].telfh[j],1);
					if(isdigit(n)){
						b+=1;
					}
					else if(j==4&&v[*i].telfh[4]=='\x2D'){
						b+=1;
					}
				}
				if(b!=12){
					printf(ST CR"\t\t\tNumero Telefónico de Habitacion está mal ingresado, Intente de Nuevo"CB"\n\n\n");
				}
			}while(b!=12);
//-------------------->FIN TELEFONO
//-------------------->REFERENCIA DEL CLIENTE
			cedula(v[*i].ref,2);
//-------------------->FIN REFERENCIA DEL CLIENTE
//-------------------->CODIGO DE LA SUCURSAL
			do{
				sucursal(v[*i].csuc,1);
				Busca_Sucursal(vSucursal,*i,&b,v[*i].csuc);
				if(b==0){
					printf(ST CR"\t\tLa Sucursal Que desea Ingresar, Aun no existe"CB"\n\n\n");
				}
			}while(b==0);
//-------------------->FIN CODIGO DE LA SUCURSAL
//-------------------->CARGA CREA UNA CUENTA OBLIGATORIAMENTE PARA TODO CLIENTE NUEVO
			Carga_Cuenta(vCuenta, &*c, 0);
//-------------------->FIN CREA UNA CUENTA OBLIGATORIAMENTE PARA TODO CLIENTE NUEVO
		}
		else{
			printf(ST RES"\t\tNOTA: SOLO SE PUEDEN MODIFICAR EL NOMBRE, APELLIDO, DIRECCION, ESTADO CIVIL y TELEFONO"CB"\n\n\n");
//-------------------->NOMBRE DEL CLIENTE
			do{
				printf("\t\tIntroduzca el Nombre del Cliente:\v\tEjem: Jose Angel, Max 50 Caracteres\n\n\t\t-> ");
					scanf(" %[^\n]", v[*i].nombre);
				if(strlen(v[*i].nombre)>50){
					printf(ST CR "\t\t\tIngreso de Nombre del Cliente Incorrecto, Intente de Nuevo"CB"\n\n\n");
				}
			}while(strlen(v[*i].nombre)>50);
//-------------------->FIN NOMBRE DEL CLIENTE
//-------------------->APELLIDO
			do{
				printf("\t\tIntroduzca el Apellido del Cliente:\v\tEjem: Perez Rojas, Max 50 Caracteres\n\n\t\t-> ");
					scanf(" %[^\n]", v[*i].apellido);
				if(strlen(v[*i].apellido)>50){
					printf(ST CR"\t\t\tIngreso de Apellido del Cliente Incorrecto, Intente de Nuevo"CB"\n\n\n");
				}
			}while(strlen(v[*i].apellido)>50);
//-------------------->FIN APELLIDO
//-------------------->ESTADO CIVIL
			do{
				do{
					printf("\t\tIntroduzca el Estado Civil del Cliente:\n\t\t\t\t\vEjem: S: Soltero, D: Divorciado, V: Viudo, O: Otro\n\n\t\t-> ");
						scanf(" %[^\n]", t);
				if(strlen(t)!=1){
					printf(ST CR"\t\tPara indicar el Estado Civil Solo se necesita de un caractér, Intente de Nuevo"CB"\n\n\n");
				}
				}while(strlen(t)!=1);
				strncpy(&v[*i].edo_civil,&t[0],1);
				v[*i].edo_civil=toupper(v[*i].edo_civil);
				if(v[*i].edo_civil!='S'&&v[*i].edo_civil!='D'&&v[*i].edo_civil!='V'&&v[*i].edo_civil!='O'){
					printf(ST CR"\t\t\tOpcion Incorrecta, Intente de Nuevo"CB"\n\n\n");
				}
			}while(v[*i].edo_civil!='S'&&v[*i].edo_civil!='D'&&v[*i].edo_civil!='V'&&v[*i].edo_civil!='O');
//-------------------->FIN ESTADO CIVIL
//-------------------->DIRECCION
			do{
				printf("\t\tIntroduzca la Direccion del Cliente:\v\t Max 150 Caracteres\n\n\t\t-> ");
						scanf(" %[^\n]", v[*i].direccion);
				if(strlen(v[*i].direccion)>150){
					printf(ST CR"\t\t\tLa Longitud de la Direccion Excede en lo permitido, Intente de Nuevo"CB"\n\n\n");
				}
			}while(strlen(v[*i].direccion)>150);
//-------------------->FIN DIRECCION
//-------------------->TELEFONO
			do{
				do{
					printf("\t\tIntroduzca el Telefono de la Habitacion:\v\t Ejem: 0241-8555212\n\n\t\t-> ");
						scanf(" %[^\n]",v[*i].telfh);
				}while(strlen(v[*i].telfh)!=12);
				b=0;
				for(j=0;j<13;j++){
					strncpy(&n, &v[*i].telfh[j],1);
					if(isdigit(n)){
						b+=1;
					}
					else if(j==4&&v[*i].telfh[4]=='\x2D'){
						b+=1;
					}
				}
				if(b!=12){
					printf(ST CR"\t\t\tNumero Telefónico de Habitacion está mal ingresado, Intente de Nuevo"CB"\n\n\n");
				}
			}while(b!=12);
//-------------------->FIN TELEFONO
		}
		if(mod==0){
			Pregunta(&n,1);
			*i+=1; //Incrementa el Acumulador de Clientes
		}
	}while(n=='S'&&mod!=1);
}
Carga_Sucursal(rsucursal v[], int *i, int mod){
	int b,j;
	char n,t[M],cc;
	do{
		system("clear");
		if(mod==0){
//-------------------->CODIGO DE LA SUCURSAL
			do{
				sucursal(v[*i].csuc,1);
				Busca_Sucursal(v, *i,&j,v[*i].csuc);
			}while(j>1);
//-------------------->FIN DEL CODIGO DE LA SUCURSAL
//-------------------->NOMBRE DE LA SUCURSAL
			do{
				printf("\t\tIntroduzca el Nombre de la Sucursal\n\t\t\tEjem: Banco 100% Universitario Mañongo Sambil\n\n\t\t-> ");
					scanf(" %[^\n]", v[*i].nsuc);
				if(strlen(v[*i].nsuc)<1||strlen(v[*i].nsuc)>100){
					printf(ST CR"\t\tCantidad de Caracteres no valida para el Nombre de la Sucursal , Intente de Nuevo"CB"\n\n\n");
				}
			}while(strlen(v[*i].nsuc)<1||strlen(v[*i].nsuc)>100);
//-------------------->FIN NOMBRE DE LA SUCURSAL
//-------------------->DIRECCION DE LA SUCURSAL
			do{
				printf("\t\tIntroduzca la Direccion de la Sucursal:\v Max 150 Caracteres\n\n\t\t-> ");
						scanf(" %[^\n]", v[*i].dsuc);
				if(strlen(v[*i].dsuc)<1||strlen(v[*i].dsuc)>150){
					printf(ST CR"\t\t\tDireccion de la Sucursal Incorrecta, Intente de Nuevo"CB"\n\n\n");
				}
			}while(strlen(v[*i].dsuc)<1||strlen(v[*i].dsuc)>150);
//-------------------->FIN DIRECCION DE LA SUCURSAL
//-------------------->NOMBRE DEL GERENTE
			do{
				printf("\t\tIntroduzca el Nombre del Gerente de la Sucursal:\t\vEjem: Osval Reyes\n\n\t\t-> ");
					scanf(" %[^\n]", v[*i].gsuc);
				if(strlen(v[*i].gsuc)<1||strlen(v[*i].gsuc)>50){
					printf(ST CR"\t\t\tCantidad de Caracteres no valida para el Gerente de la Sucursal, Intente de Nuevo"CB"\n\n\n");
				}
			}while(strlen(v[*i].gsuc)<1||strlen(v[*i].gsuc)>50);
//-------------------->FIN NOMBRE DEL GERENTE
//-------------------->CANTIDAD DE CAJEROS
			do{
				do{			
					printf("\t\tIntroduzca el Numero de Cajeros de la Sucursal:\n\n\t\t-> ");
						scanf(" %[^\n]", t);
					b=0;
					for(j=0;j<3;j++){
						strncpy(&n, &t[j],1);
						if(isdigit(n)){
							b+=1;
						}
					}
					if(strlen(t)>3){
						printf(ST CR"\t\t\tLa Cantidad de Cajeros no debe Exceder de 3 Dígitos, Intente de Nuevo"CB"\n\n\n");
					}
				}while(b!=strlen(t)||strlen(t)<1||strlen(t)>3);
				v[*i].ccajeros=atoi(t);
				if(v[*i].ccajeros<1){
					printf(ST CR"\t\t\tLa cantidad de Cajeros debe de ser positiva, Intente de Nuevo"CB"\n\n\n");
				}
				if(v[*i].ccajeros>100){
					printf(ST CR"\t\t\tLa cantidad de Cajeros por Sucursal no debe exceder de 100, Intente de Nuevo"CB"\n\n\n");
				}
			}while(v[*i].ccajeros<1||v[*i].ccajeros>100); 
//-------------------->FIN CANTIDAD DE CAJEROS
		}
		else{
			printf(ST RES"\t\tNOTA: SOLO SE PUEDEN MODIFICAR LA CANTIDAD DE CAJEROS Y EL NOMBRE DEL GERENTE DE LA SUCURSAL"CB"\n\n\n");
//-------------------->NOMBRE DEL GERENTE
			do{
				printf("\t\tIntroduzca el nombre del gerente de la sucursal:\t\vEjem: Osval Reyes\n\n\t\t-> ");
					scanf(" %[^\n]", v[*i].gsuc);
				if(strlen(v[*i].gsuc)<1||strlen(v[*i].gsuc)>50){
					printf(ST CR"\t\tIngreso de Nombre del Gerente Incorrecto, Intente de Nuevo"CB"\n\n\n");
				}
			}while(strlen(v[*i].gsuc)<1||strlen(v[*i].gsuc)>50);
//-------------------->FIN NOMBRE DEL GERENTE
//-------------------->CANTIDAD DE CAJEROS
			do{
				do{			
					printf("\t\tIntroduzca el Numero de Cajeros de la Sucursal:\n\n\t\t-> ");
						scanf(" %[^\n]", t);
					b=0;
					for(j=0;j<3;j++){
						strncpy(&n, &t[j],1);
						if(isdigit(n)){
							b+=1;
						}
					}
					if(strlen(t)>3){
						printf(ST CR"\t\t\tLa Cantidad de Cajeros no debe Exceder de 3 Dígitos, Intente de Nuevo"CB"\n\n\n");
					}
				}while(b!=strlen(t)||strlen(t)<1||strlen(t)>3);
				v[*i].ccajeros=atoi(t);
				if(v[*i].ccajeros<1){
					printf(ST CR"\t\t\tLa Cantidad de Cajeros debe de ser positiva, Intente de Nuevo"CB"\n\n\n");
				}
				if(v[*i].ccajeros>100){
					printf(ST CR"\t\t\tLa Cantidad de Cajeros por Sucursal no debe exceder de 100, Intente de Nuevo"CB"\n\n\n");
				}
			}while(v[*i].ccajeros<1||v[*i].ccajeros>100); 
//-------------------->FIN CANTIDAD DE CAJEROS
		}
		if(mod==0){
			Pregunta(&n,3);
			*i+=1; //INCREMENTA EL ACUMULADOR
		}
	}while(n=='S'&&mod!=1);
}
Carga_Cuenta(cuenta v[], int *i, int mod){
	int b,cant;
	char n,m,tcta[M];
	do{
		if(mod==0){
		system("clear");
//-------------------->
//-------------------->CODIGO DE LA CUENTA
			do{
				nocta(v[*i].ccta);
				Busca_Cuenta(v, *i,&b,v[*i].ccta);
			}while(b>1);
//-------------------->FIN CODIGO DE LA CUENTA
//-------------------->CEDULA DEL CLIENTE DE LA CUENTA
			cedula(v[*i].ccli,1);
//-------------------->FIN CEDULA DEL CLIENTE DE LA CUENTA
//-------------------->TIPO DE CUENTA
			do{
				do{
					printf("Introduzca el Tipo de Cuenta:\n\n\tA-Cuenta de Ahorro\n\tI-Corriente Sin Intereses,\n\tC-Cuenta Corriente\n\n-> ");
						scanf(" %[^\n]", tcta);
					if(strlen(tcta)!=1){
						printf(ST CR"\t\t\tPara el Tipo de Cuenta sólo se necesita de una Letra, Intente de Nuevo"CB"\n\n\n");
					}
				}while(strlen(tcta)!=1);
				strncpy(&v[*i].tcta, &tcta[0],1);
				v[*i].tcta=toupper(v[*i].tcta);
				if(v[*i].tcta!='\x41'&&v[*i].tcta!='\x43'&&v[*i].tcta!='\x49'){
						printf(ST CR"\t\t\tOpcion de Tipo de Cuenta Incorrecta, Intente de Nuevo"CB"\n\n\n");
					}
			}while(v[*i].tcta!='\x41'&&v[*i].tcta!='\x43'&&v[*i].tcta!='\x49');
//-------------------->FIN TIPO DE CUENTA
			do{
				do{
					do{
//-------------------->FECHA DE APERTURA
						fecha(&v[*i].faper.dia, &v[*i].faper.mes, &v[*i].faper.ano,2);
//-------------------->FIN FECHA DE APERTURA
//-------------------->FECHA ULTIMO PAGO DE INTERESES
						fecha(&v[*i].fupi.dia,&v[*i].fupi.mes,&v[*i].fupi.ano,1);
//-------------------->FIN FECHA ULTIMO PAGO DE INTERESES
					}while(v[*i].faper.dia>v[*i].fupi.dia&&v[*i].faper.mes==v[*i].fupi.mes&&v[*i].faper.ano==v[*i].fupi.ano);
				}while(v[*i].faper.mes>v[*i].fupi.mes&&v[*i].faper.ano==v[*i].fupi.ano);
			}while(v[*i].faper.ano>v[*i].fupi.ano);
//-------------------->CODIGO DE LA SUCURSAL
			do{
				sucursal(v[*i].csuc, 1);
				Busca_Sucursal(vSucursal,*i,&b,v[*i].csuc);
				if(b==0){
					printf(ST CR"\t\tLa Sucursal Que desea Ingresar, Aun no existe"CB"\n\n\n");
				}
			}while(b==0);
//-------------------->FIN CODIGO DE LA SUCURSAL
///-------------------->CONDICION ESENCIAL PARA LA ELIMINACION DE LA CUENTA SI EL CLIENTE NO PAGA SUS INTERESES EN UN 
///                              LAPSO NO MAYOR A QUINCE <<15>> DIAS HÁBILES, LA CUENTA SERÁ SOBREESCRITA
			CD(v[*i].faper.dia,v[*i].faper.mes,v[*i].faper.ano,v[*i].fupi.dia,v[*i].fupi.mes,v[*i].fupi.ano,&cant);
			if(cant>15){
				*i-=1;
			}
///-------------------->FIN CONDICION ESENCIAL
		}
		else{
//-------------------->FECHA ULTIMO PAGO DE INTERESES
			printf(ST RES"\t\tNOTA: SOLO SE MODIFICARÁ LA ULTIMA FECHA DEL PAGO DE INTERESES"CB"\n\n\n");
			fecha(&v[*i].fupi.dia,&v[*i].fupi.mes,&v[*i].fupi.ano,1);
//-------------------->FIN FECHA ULTIMO PAGO DE INTERESES
		}
		if(mod==0){
			Pregunta(&n,2);
			*i+=1; //Incrementa el Acumulador de Cuentas
		}
	}while(n=='S'&&mod!=1);
}
Carga_Transaccion(transaccion v[], int *i){
	int j,b;
	char n,to[2];
	float m;
	do{
		system("clear");
//-------------------->REFERENCIA DE LA CUENTA
		do{
			ref(v[*i].ref);
			Busca_Referencia(v,*i,&j,v[*i].ref);
		}while(j>1);
//-------------------->FIN REFERENCIA DE LA CUENTA
//-------------------->NUMERO DE LA CUENTA
		nocta(v[*i].ccta);
//-------------------->FIN NUMERO DE LA CUENTA
//-------------------->FECHA DE LA TRANSACCION
		fecha(&v[*i].ftrans.dia,&v[*i].ftrans.mes,&v[*i].ftrans.ano, 1);
//-------------------->FIN FECHA DE LA TRANSACCION 
//-------------------->MONTO DE LA TRANSACCION
		monto(&v[*i].mtrans);
//-------------------->FIN MONTO DE LA TRANSACCION
//-------------------->TIPO DE OPERACION
		do{
			do{
				printf("\t\tIntroduzca el Tipo de Operacion:\n\n\t1.- Retiro\n\t2.- Deposito\n\t3.- Notas de Debito\n\t4.- Notas de Credito\n\n\t\t-> ");
					scanf(" %[^\n]", to);
				if(strlen(to)!=1){
					printf(ST CR"\t\t\tOpcion de Tipo de Operacion Incorrecta, Intente de Nuevo"CB"\n\n\n");
				}
			}while(strlen(to)!=1);
			v[*i].topera=atoi(to);
			if(v[*i].topera==0){
				printf(ST CR"\t\t\tSolo Existen 4 Opciones para el Tipo de Operacion, Intente de Nuevo"CB"\n\n\n");
			}
			if(v[*i].topera>4){
				printf(ST CR"\t\t\tSolo Existen 4 Opciones para el Tipo de Operacion, Intente de Nuevo"CB"\n\n\n");
			}
		}while(v[*i].topera<1||v[*i].topera>4);
//-------------------->FIN TIPO DE OPERACION
//-------------------->CODIGO DE LA SUCURSAL
		sucursal(v[*i].csuc, 0);
//-------------------->FIN CODIGO DE LA SUCURSAL
		Pregunta(&n,4);
		*i+=1; //Incrementa el Acumulador de Transacciones
	}while(n=='S');
}
Tipo_Cuenta(char *cta){
	char tcta[M];
	do{
		do{
			printf("Introduzca el Tipo de Cuenta:\n\n\tA-Cuenta de Ahorro\n\tI-Corriente Sin Intereses,\n\tC-Cuenta Corriente\n\n-> ");
				scanf(" %[^\n]", tcta);
			if(strlen(tcta)!=1){
				printf(ST CR"\t\t\tPara el Tipo de Cuenta sólo se necesita de una Letra, Intente de Nuevo"CB"\n\n\n");
			}
		}while(strlen(tcta)!=1);
		strncpy(&*cta, &tcta[0],1);
		*cta=toupper(*cta);
		if(*cta!='\x41'&&*cta!='\x43'&&*cta!='\x49'){
				printf(ST CR"\t\t\tOpcion de Tipo de Cuenta Incorrecta, Intente de Nuevo"CB"\n\n\n");
			}
	}while(*cta!='\x41'&&*cta!='\x43'&&*cta!='\x49');
}

Modifica_Sucursales(rsucursal v[], int *i){
	int j,p,mod,b;
	char ccod[M],n;
	do{
		sucursal(ccod, 4);
		p=-1;
		for(j=0;j<*i;j++){
			if(strcmp(ccod, v[j].csuc)==0){
				p=j;
				printf("\t\tCodigo de la Sucursal: %s\n", v[j].csuc);
				printf("\t\tNombre de la Sucursal: %s\n", v[j].nsuc);
				printf("\t\tDireccion de la Sucursal: %s\n", v[j].dsuc);
				printf("\t\tGerente de la Sucursal: %s\n", v[j].gsuc);
				printf("\t\tCantidad de Cajeros de la Sucursal: %d\n\n\n", v[j].ccajeros);
			}		
		}
		if(p==-1){
				printf(ST CR"\t\t\tEl Codigo de Cuenta Introducido \"%s\", No Existe en el registro registro\n\n\n\n",ccod);
		}
		else{
			Pregunta(&n, 6);
			if(n=='S'){
				Carga_Sucursal(vSucursal, &p, 1);
				p=0;
			}
		}
	}while(p==-1);
}
Modifica_Cliente(cliente v[], int *i, int *c){
	int j,p,mod,b;
	char ci[M],n;
	do{
		cedula(ci,4);
		p=-1;
		for(j=0;j<*i;j++){
			if(strcmp(ci, v[j].cedula)==0){
				p=j;
				printf("\t\tCedula del Cliente: %s\n", v[j].cedula);
				printf("\t\tNombre: %s\n", v[j].nombre);
				printf("\t\tApellido: %s\n", v[j].apellido);
				printf("\t\tSexo: %c\n", v[j].sexo);
				printf("\t\tEstado Civil: %c\n", v[j].edo_civil);
				printf("\t\tDireccion: %s\n", v[j].direccion);
				printf("\t\tTelefono Hab.%s\n", v[j].telfh);
				printf("\t\tReferencia: %s\n", v[j].ref);
				printf("\t\tCodigo de la Sucursal: %s\n", v[j].csuc);
			}		
		}
		if(p==-1){
				printf("\n\n\t\t\tCedula Introducida \"%s\", No Existe en el Registro\n\n\n\n",ci);
		}
		else{
			Pregunta(&n, 5);
			if(n=='S'){
				Carga_Clientes(vCliente, &p,1,&*c);
				p=0;
			}
		}
	}while(p==-1);
}
Modifica_Cuenta(cuenta v[], int *i){
	int j,p,mod,b;
	char ccod[M],n;
	do{
		nocta(ccod);
		p=-1;
		for(j=0;j<*i;j++){
			if(strcmp(ccod, v[j].ccta)==0){
				p=j;
				printf("Cedula del Cliente: %s\n", v[j].ccli);
				printf("Codigo de la Cuenta: %s\n", v[j].ccta);
				printf("Tipo de Cuenta: %c\n", v[j].tcta);
				printf("Fecha de Apertura: %.2d\x2F%.2d\x2F%d\n", v[j].faper.dia,v[j].faper.mes,v[j].faper.ano);
				printf("Fecha del Ultimo Pago de Intereses: %.2d\x2F%.2d\x2F%d\n", v[j].fupi.dia,v[j].fupi.mes,v[j].fupi.ano);
				printf("Codigo de la Sucursal: %s\n", v[j].csuc);
			}		
		}
		if(p==-1){
				printf("\n\n\t\t\tEl Codigo de Cuenta Introducido \"%s\", No está Registrada\n\n\n\n",ccod);
		}
		else{
			Pregunta(&n, 6);
			if(n=='S'){
				Carga_Cuenta(vCuenta, &p, 1);
				p=0;
			}
		}
	}while(p==-1);
}

Consulta_Cliente(cliente v[], int i){
char ci[M];
int j;
	system("clear");
	cedula(ci,3);
	for(j=0;j<i;j++){
		if(strcmp(ci, v[j].cedula)==0){
			printf("\t\tCedula del Cliente: %s\n", v[j].cedula);
			printf("\t\tNombres del Cliente: %s\n", v[j].nombre);
			printf("\t\tApellidos del Cliente: %s\n", v[j].apellido);
			printf("\t\tSexo: %c\n", v[j].sexo);
			printf("\t\tEstado Civil: %c\n", v[j].edo_civil);
			printf("\t\tDireccion del Cliente: %s\n", v[j].direccion);
			printf("\t\tTelefono de Habitacion: %s\n", v[j].telfh);
			printf("\t\tReferencia del Cliente: %s\n", v[j].ref);
			printf("\t\tCodigo de la Sucursal del Cliente: %s\n", v[j].csuc);
		}
	}
}
Consulta_Cuenta(cuenta v[], int i){
char ccta[M];
int j;
	system("clear");
	nocta(ccta);
	for(j=0;j<i;j++){
		if(strcmp(ccta, v[j].ccta)==0){
			printf("\t\tCodigo de la Cuenta: %s\n", v[j].ccta);
			printf("\t\tCliente de la Cuenta: %s\n", v[j].ccli);
			printf("\t\tTipo de Cuenta: %s\n", v[j].tcta);
			printf("\t\tFecha de Apertura de la Cuenta: %.2d\x2F%.2d\x2F%d\n", v[j].faper.dia,v[j].faper.mes,v[j].faper.ano);
			printf("\t\tFecha de Ultimo Pago de Intereses: %.2d\x2F%.2d\x2F%d\n", v[j].fupi.dia,v[j].fupi.mes,v[j].fupi.ano);
			printf("\t\tCodigo de la Sucursal donde se encuentra esta Cuenta: %s\n", v[j].csuc);
		}
	}
}
Consulta_Sucursal(rsucursal v[], int i){
char cod[M];
int j;
	system("clear");
	sucursal(cod,2);
	for(j=0;j<i;j++){
		if(strcmp(cod, v[j].csuc)==0){
			printf("\t\tCodigo de la Sucursal: %s\n", v[j].csuc);
			printf("\t\tNombre de la Sucursal: %s\n", v[j].nsuc);
			printf("\t\tDireccion de la Sucursal: %s\n", v[j].dsuc);
			printf("\t\tNombre del Gerente de la Sucursal: %s\n", v[j].gsuc);
			printf("\t\tCantidad de Cajeros Activos de la Sucursal: %d\n", v[j].ccajeros);
		}
	}
}
Consulta_Transaccion(transaccion v[], int i){
char cref[M];
int j;
	system("clear");
	ref(cref);
	for(j=0;j<i;j++){
		if(strcmp(cref, v[j].ref)==0){
			printf("\t\tCodigo de Referencia de la Transaccion: %s\n", v[j].ref);
			printf("\t\tCodigo de la Cuenta: %s\n", v[j].ccta);
			printf("\t\tFecha de la Transaccion: %.2d\x2F%.2d\x2F%d\n", v[j].ftrans.dia,v[j].ftrans.mes,v[j].ftrans.ano);
			printf("\t\tMonto de la Transaccion: Bs. %.2f\n", v[j].mtrans);
			printf("\t\tTipo de Operacion: %s\n", v[j].topera);
			printf("\t\tCodigo de la Sucursal donde se generó la Transaccion: %s\n\n", v[j].csuc);
		}
	}
}

Mostrar_Transacciones(cliente cl[], cuenta cu[], transaccion tr[], rsucursal su[], int ccl, int ccu, int ctr, int csu){
int di,mi,ai; //VARIABLES PARA LA FECHA INICIAL
int df,mf,af; //VARIABLES PARA LA FECHA FINAL
int i,j,k,l; //INDICES PARA LOS FOR
int b,q,y,w; //BANDERAS PARA LAS CONDICIONES
int bandera;
	do{
		fecha(&di,&mi,&ai,4);
		fecha(&df,&mf,&af,5);
		if(ai>af){
			printf("\n\n\n\t\tLA FECHA INICIAL NO PUEDE SER MAYOR QUE LA FECHA FINAL, Intente de nuevo\n\n\n\n");
		}
		if(di==df&&mi==mf&&ai==af){
			printf("\n\n\n\t\tLAS FECHAS INICIALES Y FINALES NO PUEDEN SER IGUALES, Intente de nuevo\n\n\n\n");
		}
	}while(ai>af||di==df&&mi==mf&&ai==af);
	for(i=0;i<70;i++){
		printf("_");
	}
	printf("\n\t\t:: TRANSACCIONES DEL BANCO 100% UNIVERSITARIO\n\t\tDESDE [[%.2d-%.2d-%d]] HASTA [[%.2d-%.2d-%d]]\n",di,mi,ai,df,mf,af);
	for(i=0;i<70;i++){
		printf("_");
	}
	printf("\n\n\n");
	for(i=0;i<csu;i++){
		b=0;
		q=0;
		for(l=0;l<ctr;l++){
			for(j=0;j<ccl;j++){
				for(k=0;k<ccu;k++){
					if(strcmp(su[i].csuc,tr[l].csuc)==0&&strcmp(cl[j].cedula,cu[k].ccli)==0&&strcmp(cu[k].ccta,tr[l].ccta)==0){
						if(ai==tr[l].ftrans.ano&&mi==tr[l].ftrans.mes&&di<=tr[l].ftrans.dia&&df>=tr[l].ftrans.dia){
							if(b==0){
								b=1;
								printf("\n\n----------------------------------------------------------------");
								printf("\n\tSucursal: %s \n", su[i].csuc);
								printf("----------------------------------------------------------------\n");
								printf("\n\n\t\t| Cedula: %s \n\t\t| Nombre: %s\n\t\t| Apellido: %s", cl[j].cedula,cl[j].nombre,cl[j].apellido);
								y=j;
								bandera=6;
							}
							if(strcmp(cl[j].cedula,cl[y].cedula)!=0){
								b=0;
							}
							if(q==0){
								q=1;
								printf("\n\t\t|\n\t\t|---------> Numero de Cuenta: %s\n", tr[l].ccta);
								w=l;
							}
							if(strcmp(tr[w].ccta,tr[l].ccta)!=0){
								q=0;
							}
							printf("\n\t\t\t\t\tCodigo de Referencia: %s\n", tr[l].ref);
							printf("\n\t\t\t\t\tMonto de la Transaccion: Bs. %.2f", tr[l].mtrans);
							printf("\n\t\t\t\t\tFecha de la Transaccion: %.2d\x2F%.2d\x2F%d\n\n", tr[l].ftrans.dia,tr[l].ftrans.mes,tr[l].ftrans.ano);
						}
						if(ai==tr[l].ftrans.ano&&mi<tr[l].ftrans.mes&&mf>tr[l].ftrans.mes){
							if(b==0){
								b=1;
								printf("\n\n----------------------------------------------------------------");
								printf("\n\tSucursal: %s \n", su[i].csuc);
								printf("----------------------------------------------------------------\n");
								printf("\n\n\t\t| Cedula: %s \n\t\t| Nombre: %s\n\t\t| Apellido: %s", cl[j].cedula,cl[j].nombre,cl[j].apellido);
								y=j;
								bandera=6;
							}
							if(strcmp(cl[j].cedula,cl[y].cedula)!=0){
								b=0;
							}
							if(q==0){
								q=1;
								printf("\n\t\t|\n\t\t|---------> Numero de Cuenta: %s\n", tr[l].ccta);
								w=l;
							}
							if(strcmp(tr[w].ccta,tr[l].ccta)!=0){
								q=0;
							}
							printf("\n\t\t\t\t\tCodigo de Referencia: %s", tr[l].ref);
							printf("\n\t\t\t\t\tMonto de la Transaccion: Bs. %.2f", tr[l].mtrans);
							printf("\n\t\t\t\t\tFecha de la Transaccion: %.2d\x2F%.2d\x2F%d\n\n", tr[l].ftrans.dia,tr[l].ftrans.mes,tr[l].ftrans.ano);
						}
						if(ai<tr[l].ftrans.ano&&af>tr[l].ftrans.ano){
							if(b==0){
								b=1;
								printf("\n\n----------------------------------------------------------------");
								printf("\n\tSucursal: %s \n", su[i].csuc);
								printf("----------------------------------------------------------------\n");
								printf("\n\n\t\t| Cedula: %s \n\t\t| Nombre: %s\n\t\t| Apellido: %s", cl[j].cedula,cl[j].nombre,cl[j].apellido);
								y=j;
								bandera=6;
							}
							if(strcmp(cl[j].cedula,cl[y].cedula)!=0){
								b=0;
							}
							if(q==0){
								q=1;
								printf("\n\t\t|\n\t\t|---------> Numero de Cuenta: %s\n", tr[l].ccta);
								w=l;
							}
							if(strcmp(tr[w].ccta,tr[l].ccta)!=0){
								q=0;
							}
							printf("\n\t\t\t\t\tCodigo de Referencia: %s", tr[l].ref);
							printf("\n\t\t\t\t\tMonto de la Transaccion: Bs. %.2f", tr[l].mtrans);
							printf("\n\t\t\t\t\tFecha de la Transaccion: %.2d\x2F%.2d\x2F%d\n\n", tr[l].ftrans.dia,tr[l].ftrans.mes,tr[l].ftrans.ano);
						}
						if(af==tr[l].ftrans.ano&&mf>tr[l].ftrans.ano){
							if(b==0){
								b=1;
								printf("\n\n----------------------------------------------------------------");
								printf("\n\tSucursal: %s \n", su[i].csuc);
								printf("----------------------------------------------------------------\n");
								printf("\n\n\t\t| Cedula: %s \n\t\t| Nombre: %s\n\t\t| Apellido: %s", cl[j].cedula,cl[j].nombre,cl[j].apellido);
								y=j;
								bandera=6;
							}
							if(strcmp(cl[j].cedula,cl[y].cedula)!=0){
								b=0;
							}
							if(q==0){
								q=1;
								printf("\n\t\t|\n\t\t|---------> Numero de Cuenta: %s\n", tr[l].ccta);
								w=l;
							}
							if(strcmp(tr[w].ccta,tr[l].ccta)!=0){
								q=0;
							}
							printf("\n\t\t\t\t\tCodigo de Referencia: %s", tr[l].ref);
							printf("\n\t\t\t\t\tMonto de la Transaccion: Bs. %.2f", tr[l].mtrans);
							printf("\n\t\t\t\t\tFecha de la Transaccion: %.2d\x2F%.2d\x2F%d\n\n", tr[l].ftrans.dia,tr[l].ftrans.mes,tr[l].ftrans.ano);
						}
						if(af==tr[l].ftrans.ano&&mf==tr[l].ftrans.mes&&df<=tr[l].ftrans.dia){
							if(b==0){
								b=1;
								printf("\n\n----------------------------------------------------------------");
								printf("\n\tSucursal: %s \n", su[i].csuc);
								printf("----------------------------------------------------------------\n");
								printf("\n\n\t\t| Cedula: %s \n\t\t| Nombre: %s\n\t\t| Apellido: %s", cl[j].cedula,cl[j].nombre,cl[j].apellido);
								y=j;
								bandera=6;
							}
							if(strcmp(cl[j].cedula,cl[y].cedula)!=0){
								b=0;
							}
							if(q==0){
								q=1;
								printf("\n\t\t|\n\t\t|---------> Numero de Cuenta: %s\n", tr[l].ccta);
								w=l;
							}
							if(strcmp(tr[w].ccta,tr[l].ccta)!=0){
								q=0;
							}
							printf("\n\t\t\t\t\tCodigo de Referencia: %s", tr[l].ref);
							printf("\n\t\t\t\t\tMonto de la Transaccion: Bs. %.2f", tr[l].mtrans);
							printf("\n\t\t\t\t\tFecha de la Transaccion: %.2d\x2F%.2d\x2F%d\n\n", tr[l].ftrans.dia,tr[l].ftrans.mes,tr[l].ftrans.ano);
						}
					}
				}
			}
		}
	}
	if(bandera!=6){
		printf(ST LC CAM"\t\t\t\tNO SE ENCONTRARON TRANSACCIONES REALIZADAS EN NINGUNA\n");
		printf("\t\t\t\t\tDE LAS SUCURSALES PARA ESE RANGO DE FECHA\n");
		printf("\t\t\t\t\tDESDE [[%.2d-%.2d-%d]] HASTA [[%.2d-%.2d-%d]]"CB LC"\n\n\n",di,mi,ai,df,mf,af);
	}
}

Intereses(cliente cl[], cuenta cu[], transaccion tr[], int ccl, int ccu, int ctr){
	int i,j,k;
	int d,m,a;
	int di,mi,ai,df,mf,af,dias;
	float Int;
	printf("\n\n\n\tA Continuacion, Ingrese Un Rango de Fechas para calcular las Intereses Bancarios..\n\n");
	do{
		fecha(&di,&mi,&ai,7);
		fecha(&df,&mf,&af,8);
		if(af==ai&&mf==mi&&di>=df){
			printf(ST LC CR"\t\tEl Dia Inicial no puede ser <<MAYOR>> que el Final, si los meses y años son iguales"CB LC"\n\n\n");
		}
		if(af==ai&&mi>mf){
			printf(ST LC CR"\t\tEl Mes Inicial no puede ser <<MAYOR>> que el Final"CB LC"\n\n\n");	
		}
		if(ai>af){
			printf(ST LC CR"\t\tEl Año Inicial no puede ser <<MAYOR>> que el Final"CB LC"\n\n\n");	
		}
	}while((af==ai&&mf==mi&&di>=df)||(af==ai&&mi>mf)||(ai>af));
	system("clear");
	for(j=0;j<ccu;j++){
		if((ai==cu[j].fupi.ano&&mi==cu[j].fupi.mes&&di<=cu[j].fupi.dia)||(af==cu[j].fupi.ano&&mf==cu[j].fupi.mes&&df>=cu[j].fupi.dia)){
			CD(cu[j].fupi.dia,cu[j].fupi.mes,cu[j].fupi.ano,df,mf,af,&dias);
			if(cu[j].tcta=='A'||cu[j].tcta=='C'){
				if(cu[j].saldo>=0){
					Int = ((cu[j].saldo*0.13)/365)*dias;
						printf(LC CB"\t\t+"CV"\t - Dias: %d\t", dias);
						printf("Codigo cuenta: %s \n"CB"\t\t+\n",cu[j].ccta);
						printf("\t\t+"CV"\t - Ultima de Pago de Intereses: %.2d\x2F%.2d\x2F%d\n"CB"\t\t+", cu[j].fupi.dia,cu[j].fupi.mes,cu[j].fupi.ano);
						printf("\n\t\t+"CV"\t - Saldo Actual: Bs. %.2f\n\t\t"CB"+",cu[j].saldo);
						printf(LC"\t\t+"CAM"\t - Total de Intereses: %.2f"CB LC,Int);
						printf("\n\n\n");
				}
			}
		}
		else if((ai==cu[j].fupi.ano&&mi<cu[j].fupi.mes)&&(af==cu[j].fupi.ano&&mf>cu[j].fupi.mes)){	
			CD(cu[j].fupi.dia,cu[j].fupi.mes,cu[j].fupi.ano,df,mf,af,&dias);
			if(cu[j].tcta=='A'||cu[j].tcta=='C'){
				if(cu[j].saldo>=0){
					Int = ((cu[j].saldo*0.13)/365)*dias;
						printf(LC CB"\t\t+"CV"\t - Dias: %d\t", dias);
						printf("Codigo cuenta: %s \n"CB"\t\t+\n",cu[j].ccta);
						printf("\t\t+"CV"\t - Ultima de Pago de Intereses: %.2d\x2F%.2d\x2F%d\n"CB"\t\t+", cu[j].fupi.dia,cu[j].fupi.mes,cu[j].fupi.ano);
						printf("\n\t\t+"CV"\t - Saldo Actual: Bs. %.2f\n\t\t"CB"+",cu[j].saldo);
						printf(LC"\t\t+"CAM"\t - Total de Intereses: %.2f"CB LC,Int);
						printf("\n\n\n");
				}
			}
		}
		else if(ai<cu[j].fupi.ano&&af>cu[j].fupi.ano){
			CD(cu[j].fupi.dia,cu[j].fupi.mes,cu[j].fupi.ano,df,mf,af,&dias);
			if(cu[j].tcta=='A'||cu[j].tcta=='C'){
				if(cu[j].saldo>=0){
					Int = ((cu[j].saldo*0.13)/365)*dias;
						printf(LC CB"\t\t+"CV"\t - Dias: %d\t", dias);
						printf("Codigo cuenta: %s \n"CB"\t\t+\n",cu[j].ccta);
						printf("\t\t+"CV"\t - Ultima de Pago de Intereses: %.2d\x2F%.2d\x2F%d\n"CB"\t\t+", cu[j].fupi.dia,cu[j].fupi.mes,cu[j].fupi.ano);
						printf("\n\t\t+"CV"\t - Saldo Actual: Bs. %.2f\n\t\t"CB"+",cu[j].saldo);
						printf(LC"\t\t+"CAM"\t - Total de Intereses: %.2f"CB LC,Int);
						printf("\n\n\n");
				}
			}
		}
		dias=0;
	}
}	

ES_Clientes(cliente v[], int c){
	int i;
	FILE *arch;
	arch = fopen("Clientes.in","w");
	for(i=0;i<c;i++){	
		fprintf(arch, "%s\n", v[i].cedula);
		fprintf(arch, "%s\n", v[i].nombre);
		fprintf(arch, "%s\n", v[i].apellido);
		fprintf(arch, "%c\n", v[i].sexo);
		fprintf(arch, "%c\n", v[i].edo_civil);
		fprintf(arch, "%s\n", v[i].direccion);
		fprintf(arch, "%s\n", v[i].telfh);
		fprintf(arch, "%s\n", v[i].ref);
		fprintf(arch, "%s\n\n", v[i].csuc);
	}
	close(arch);
}
ES_Cuentas(cuenta v[], int c){
	int i;
	FILE *arch;
	arch = fopen("Cuentas.in","w");
	for(i=0;i<c;i++){
		fprintf(arch, "%s\n", v[i].ccli);
		fprintf(arch, "%s\n", v[i].ccta);
		fprintf(arch, "%c\n", v[i].tcta);
		fprintf(arch, "%.2d\x2F%.2d\x2F%d\n", v[i].faper.dia,v[i].faper.mes,v[i].faper.ano);
		fprintf(arch, "%.2d\x2F%.2d\x2F%d\n", v[i].fupi.dia,v[i].fupi.mes,v[i].fupi.ano);
		fprintf(arch, "%s\n\n", v[i].csuc);	
	}
	close(arch);
}
ES_Sucursal(rsucursal v[], int c){
	int i;
	FILE *arch;
	arch = fopen("Sucursales.in","w");
	for(i=0;i<c;i++){
		fprintf(arch, "%s\n", v[i].csuc);
		fprintf(arch, "%s\n", v[i].nsuc);
		fprintf(arch, "%s\n", v[i].dsuc);
		fprintf(arch, "%s\n", v[i].gsuc);
		fprintf(arch, "%d\n\n", v[i].ccajeros);
	}
	close(arch);
}
ES_Transacciones(transaccion v[], int c){
	int i;
	FILE *arch;
	arch = fopen("Transacciones.in","w");
	for(i=0;i<c;i++){
		fprintf(arch, "%s\n", v[i].ref);
		fprintf(arch, "%s\n", v[i].ccta);
		fprintf(arch, "%.2d\x2F%.2d\x2F%d\n", v[i].ftrans.dia,v[i].ftrans.mes,v[i].ftrans.ano);
		fprintf(arch, "%.2f\n", v[i].mtrans);
		fprintf(arch, "%d\n", v[i].topera);
		fprintf(arch, "%s\n\n", v[i].csuc);
	}
	close(arch);
}

BAR(cliente cl[], cuenta cu[], transaccion tr[], int ccl, int ccu, int *ctr){
	typedef struct db{
		char ccta[M];
		char ccli[M];
		int topera;
		char csuc[M];
		float mtrans;
	}db;
	db vDB[MX];
	int i,j,k,p; //INDICES PARA LOS CICLOS REPETITIVOS
	int band,ex; //BANDERA
	int d,m,a; //DIA, MES, AÑO
	int cbar[MX];/*RETORNA UN VECTOR QUE SE RELACIONA CON LOS CLIENTES POR MEDIO DE LAS POSICIONES, LA CANTIDAD ENTERA QUE CONTIENE CADA POSICION SE MULTIPLICARAN POR LA SUMA DE Bs. 50000 Y SE MOSTRARAN A CADA CLIENTE PARA UNA FECHA DADA */
	system("clear");
	fecha(&d,&m,&a,6);
	system("clear");
	for(i=0;i<ccl;i++){
		cbar[i]=0;
		for(j=0;j<ccl;j++){
			for(k=0;k<ccu;k++){
				band=0;
				if(i!=j&&strcmp(cl[i].cedula,cl[j].ref)==0){
					if(strcmp(cl[j].cedula,cu[k].ccli)==0&&band==0){//COMPARA LA CEDULA DEL CLIENTE REFERIDO CON SUS CUENTA
						if(a==cu[k].faper.ano&&m==cu[k].faper.mes&&d>=cu[k].faper.dia){
							cbar[i]+=1;
						}
						else if(a==cu[k].faper.ano&&m>cu[k].faper.mes){
							cbar[i]+=1;
						}
						else if(a>cu[k].faper.ano){
							cbar[i]+=1;
						}
						band=1;
					}
				}
			}
		}
	}
	for(i=0;i<ccl;i++){
		if(cbar[i]!=0){
			ex=2;
		}
		if(i==ccl-1&&ex!=2){
			system("clear");
			printf(LC CR"\t\t\t\tNo se encontraron Clientes que cumplan con las Condiciones Establecidas");
			printf("\n\t\t\t\t\tpara la recompensa del B.A.R. (Bono Amigo Referido)"CB LC);
		}
	}
	if(ex==2){
	printf("\n\n\n\t\t\t- Posibles Depositos de los Bonos Amigos Referidos -\n\n\n");
	p=0;
	for(i=0;i<ccl;i++){
		band=0;
		k=0;
		for(j=0;j<ccu;j++){
			if(strcmp(cl[i].cedula,cu[j].ccli)==0&&cbar[i]>0){
				k=1;
				band=1;
				if(cbar[i]/1!=0){
					strcpy(vDB[p].ccta,cu[j].ccta);
					strcpy(vDB[p].ccli,cu[j].ccli);
					strcpy(vDB[p].csuc,cu[j].csuc);
					vDB[p].topera=1;
					vDB[p].mtrans=cbar[i]/1*50000;
					if(p==0){
						p=k;
					}
					else{
						p+=1;
					}
					k+=1;
				}
			}
		}
			if(band==0&&cbar[i]!=0){
				printf(LC RES "\t\t\tSE HA DETECTADO QUE LA PERSONA CON C.I: %s, NO TIENE CUENTA Y,\n\t\t\t\tES POSIBLE BENEFICIARIO DEL B.A.R. (Bono Amigo Referido)",cl[i].cedula);
				printf("\n\t\t\t\t->    Esto se verá reflejado en 'Clientes.out'    <-"CB LC"\n\n");
			}
		
	}
		printf("\n");
		j=0;
	printf("\n\nA Continuacion, \n\tIntroduzca los Codigos de Referencia para las Siguientes Transferencias por Motivo del B.A.R. (Bono Amigo Referido)\n");
	for(i=*ctr;i<*ctr+p;i++){
		do{
		printf(CAZ"\n\n\tNumero de Cuenta: %s\n",vDB[j].ccta);
		printf("\t\tMonto de la Transaccion: %.2f\n",vDB[j].mtrans);
		printf("\t\tTipo de Operacion: %d \v(Nota de Credito por B.A.R.)\n",vDB[j].topera);
		printf("\t\tSucursal donde pertenece la Cuenta del Cliente: %s\n\n"CB,vDB[j].csuc);
			ref(tr[i].ref);
			Busca_Referencia(tr,i,&k,tr[i].ref);
		}while(k>1);
		strcpy(tr[i].ccta, vDB[j].ccta);
		tr[i].ftrans.dia=d;
		tr[i].ftrans.mes=m;
		tr[i].ftrans.ano=a;
		tr[i].mtrans=vDB[j].mtrans;
		tr[i].topera=vDB[j].topera;
		strcpy(tr[i].csuc, vDB[j].csuc);
			j+=1;
	}
	printf(CAM"\t\t\tTRANSACCIONES REALIZADAS CON EXITO, BONOS TRANSFERIDOS CORRECTAMENTE\n\n\n\n"CB);
	*ctr+=p;
	}
}

main(){
	char opc; ///OPCION DE PREGUNTA
	int opc_men,opc_arc, opc_dat, opc_mod,opc_con; ///OPCION DE CADA MENU EN PARTICULAR
	int band[5]={0,0,0,0,0};///INICIALIZA EL VECTOR DE BANDERAS
	///INICIALIZACION DE LOS ACUMULADORES GENERALES
	cantidad_clientes=0;
	cantidad_cuentas=0;
	cantidad_sucursales=0;
	cantidad_transacciones=0;
	///PRESENTACION
	interfaz();
	pres();
	do{
		menu(&opc_men);
		switch(opc_men){
			case 1:{///CARGA DE DATOS POR ARCHIVO
				do{
					menu_arc(&opc_arc);
					switch(opc_arc){
						case 1:{
							if(band[0]==0){
								Archivo_Sucursal(vSucursal, &cantidad_sucursales);
								band[0]+=1;
								printf(CV"\t\t\t\t\t\t\t\tSucursales.in > Cargado..."CB"\n\n\n");
								opc='N';

							}
							else if(band[0]>=1){
								printf(LC CR"\t\tEl Archivo \"Sucursales.in\" se puede cargar solo una sola vez en la Ejecucion del Programa"CB LC"\n\n\n");
								sleep(2);
								opc='N';
							}
						}break;
						case 2:{
							if(band[0]==1){
								Archivo_Clientes(vCliente, &cantidad_clientes);
								band[0]+=1;
								printf(CV"\t\t\t\t\t\t\t\tClientes.in > Cargado..."CB"\n\n\n");
								opc='N';

							}
							else if(band[0]>=2){
								printf(LC CR"\t\tEl Archivo \"Clientes.in\" se puede cargar solo una sola vez en la Ejecucion del Programa"CB LC"\n\n\n");
								sleep(2);
								opc='N';
							}
							else if(band[0]<1){
								printf(CV"\t\t\tPara Cargar \"Clientes.in\", se debe cargar el archivo:\n\n"CB"\t\t\t\tSucursales.in\n\n\n");
								sleep(2);
								opc='N';
							}
						}break;
						case 3:{
							if(band[0]==2){
								Archivo_Cuentas(vCuenta, &cantidad_cuentas);
								band[0]+=1;
								printf(CV"\t\t\t\t\t\t\t\tCuentas.in > Cargado..."CB"\n\n\n");
								opc='N';
							}
							else if(band[0]>=3){
								printf(LC CR"\t\tEl Archivo \"Cuentas.in\" se puede cargar solo una sola vez en la Ejecucion del Programa"CB LC"\n\n\n");
								sleep(2);
								opc='N';
							}
							else if(band[0]<2){
								printf(CV"\t\t\tPara Cargar \"Cuentas.in\", se deben cargar los archivos:\n\n"CB"\t\t\t\tSucursales.in\n\t\t\t\tClientes.in\n\n\n");
								sleep(2);
								opc='N';
							}
						}break;
						case 4:{
							if(band[0]==3){
								Archivo_Transaccion(vTransaccion, &cantidad_transacciones);
								band[0]+=1;
								printf(CV"\t\t\t\t\t\t\t\tTransacciones.in > Cargado..."CB"\n\n\n");
								opc='N';
							}
							else if(band[0]==4){
								printf(LC CR"\t\tEl Archivo \"Transacciones.in\" se puede cargar solo una sola vez en la Ejecucion del Programa"CB LC"\n\n\n");
								sleep(2);
								opc='N';
							}
							else if(band[0]<3){
								printf(CV"\t\t\tPara Cargar \"Transacciones.in\", se deben cargar los archivos:\n\n"CB"\t\t\t\tSucursales.in\n\t\t\t\tClientes.in\n\t\t\t\tCuentas.in""\n\n\n");
								sleep(2);
								opc='N';
							}
						}break;
						default:{
							opc='S';
						}break;
					}
					if(opc=='N'){
						sleep(1);
					}
				}while(opc=='N');
			}break;
			case 2:{///CARGA DE DATOS POR TECLADO
				do{
					menu_dat(&opc_dat);
					switch(opc_dat){
						case 1:{
							if(band[0]>=1){
								Carga_Sucursal(vSucursal, &cantidad_sucursales, 0);
								opc='N';
							}
							else{
								printf(LC CR"\t\t\tSolo podrá hacer uso de esta funcion si y solo si ha cargado \"Sucursales.in\""CB LC"\n\n\n");
								sleep(2);
							}
						}break;
						case 2:{
							if(band[0]>=2){
								Carga_Clientes(vCliente, &cantidad_clientes,0,&cantidad_cuentas);
								opc='N';
							}
							else{
								printf(LC CR"\t\t\tSolo podrá hacer uso de esta funcion si y solo si ha cargado \"Clientes.in\""CB LC"\n\n\n");
								sleep(2);
							}
						}break;
						case 3:{
							if(band[0]>=3){
								Carga_Cuenta(vCuenta, &cantidad_cuentas,0);
								opc='N';
							}
							else{
								printf(LC CR"\t\t\tSolo podrá hacer uso de esta funcion si y solo si ha cargado \"Cuentas.in\""CB LC"\n\n\n");
								sleep(2);
							}
						}break;
						case 4:{
							if(band[0]>=4){
								Carga_Transaccion(vTransaccion, &cantidad_transacciones);
								opc='N';
							}
							else{
								printf(LC CR"\t\t\tSolo podrá hacer uso de esta funcion si y solo si ha cargado \"Transacciones.in\""CB LC"\n\n\n");
								sleep(2);
							}
						}break;
						default:{
							opc='S';
						}break;
					}
					if(opc!='S'){
						Pregunta(&opc,7);
					}
				}while(opc=='N');
			}break;
			case 3:{///MODIFICACION DE DATOS (OBLIGATORIAMENTE POR TECLADO)
				do{
					menu_mod(&opc_mod);
					switch(opc_mod){
						case 1:{
							if(band[0]>=1){
								Modifica_Sucursales(vSucursal, &cantidad_sucursales);
							}
							else{
								opc='N';
							}
						}break;
						case 2:{
							if(band[0]>=2){
								Modifica_Cliente(vCliente, &cantidad_clientes, &cantidad_cuentas);
							}
							else{
								opc='N';
							}
						}break;
						case 3:{
							if(band[0]>=3){
								Modifica_Cuenta(vCuenta, &cantidad_cuentas);
							}
							else{
								opc='N';
							}
						}break;
						default:{
							opc='S';
						}break;
					}
				}while(opc=='N');
			}break;
			case 4:{///CONSULTA DE DATOS (OBLIGATORIAMENTE POR TECLADO)
				do{
					menu_con(&opc_con);
					switch(opc_con){
						case 1:{
							if(band[0]>=1){
								Consulta_Sucursal(vSucursal, cantidad_sucursales);
							}
							else{
								printf(LC CR"\t\t\t\tNo Puede Consultar Sucursales sin haber cargado los datos en memoria"CB LC"\n\n\n");
							}
						}break;
						case 2:{
							if(band[0]>=2){
								Consulta_Cliente(vCliente, cantidad_clientes);
							}
							else{
								printf(LC CR"\t\t\t\tNo Puede Consultar Clientes sin haber cargado los datos en memoria"CB LC"\n\n\n");
							}
						}break;
						case 3:{
							if(band[0]>=3){
								Consulta_Cuenta(vCuenta, cantidad_cuentas);
							}
							else{
								printf(LC CR"\t\t\t\tNo Puede Consultar Cuentas sin haber cargado los datos en memoria"CB LC"\n\n\n");
							}
						}break;
						case 4:{
							if(band[0]>=4){
								Consulta_Transaccion(vTransaccion, cantidad_transacciones);
							}
							else{
								printf(LC CR"\t\t\t\tNo Puede Consultar Transacciones sin haber cargado los datos en memoria"CB LC"\n\n\n");
							}
						}break;
						case 5:{
							opc='S';
						}break;
					}
					Pregunta(&opc,7);
				}while(opc=='N');
			}break;
			case 5:{///CALCULAR INTERESES 
				do{
					if(band[0]==4){
							Saldo( vCuenta, vTransaccion, cantidad_cuentas, cantidad_transacciones);
						Intereses(vCliente, vCuenta, vTransaccion,cantidad_clientes,cantidad_cuentas,cantidad_transacciones);
					}
					else{
						printf(LC CR"\t\t\t\tPara Calcular los Intereses, debe de haber cargado anteriormente\n");
						printf(CB"\t\t\t\t\t\"Clientes.in\" , \"Cuentas.in\" , \"Transacciones.in\""LC"\n\n\n");
					}
					Pregunta(&opc,7);
				}while(opc=='N');
			}break;
			case 6:{///BONO AMIGO REFERIDO
				do{
					if(band[0]==4&&band[1]==0){
						BAR(vCliente, vCuenta, vTransaccion,cantidad_clientes,cantidad_cuentas,&cantidad_transacciones);
						band[1]=1;
						Pregunta(&opc,7);
					}
					else if(band[1]==1){
						printf(LC CR"\t\tLa Opcion BONO AMIGO REFERIDO se utiliza Solo una sola vez en la Ejecucion del Programa"CB LC"\n\n\n");
						opc='S';
						sleep(5);
					}
					else if(band[0]!=4){
						printf(LC CR"\t\t\t\tPara el BONO AMIGO REFERIDO, debe de haber cargado anteriormente\n");
						printf(CB"\t\t\t\t\t\"Clientes.in\" , \"Cuentas.in\" , \"Transacciones.in\""LC"\n\n\n");
						opc='S';
						sleep(5);
					}
				}while(opc=='N');
			}break;
			case 7:{///MOSTRAR TRANSACCION
				do{
					Mostrar_Transacciones(vCliente, vCuenta,vTransaccion,vSucursal,cantidad_clientes,cantidad_cuentas,cantidad_transacciones,cantidad_sucursales); 
					Pregunta(&opc,7);
				}while(opc=='N');
			}break;
			case 8:{///ACERCA DE..
				system("clear");
					printf("\n\n\n\n\n\n\n\t\t\t\t\t\x50\x72\x6f\x79\x65\x63\x74\x6f\x20\x52\x65\x61\x6c\x69\x7a\x61\x64\x6f\x20\x70\x6f\x72\x3a");
					printf("\x0d\x0a\t\t\t\t\t\x4c\x6f\x61\x6e\x61\x20\x4c\x65\x6f\x6e\x20\x79\x20\x4f\x73\x76\x61\x6c\x20\x52\x65\x79\x65\x73");
					printf("\x0d\x0a\t\t\t\t\t\x46\x41\x43\x59\x54\x20\x2d\x20\x43\x6f\x6d\x70\x75\x74\x61\x63\x69\x6f\x6e");
					printf("\x0d\x0a\t\t\t\t\t\x4d\x61\x79\x6f\x2f\x32\x30\x30\x38\x0d\x0a\x0d\x0a");
					sleep(5);
					opc='S';
			}break;
			case 9:{///SALIR
				OPERACIONES(vCuenta, cantidad_cuentas,vSucursal, cantidad_sucursales,vCliente, cantidad_clientes, vTransaccion, cantidad_transacciones );
				ES_Clientes(vCliente, cantidad_clientes);
				ES_Cuentas(vCuenta, cantidad_cuentas);
				ES_Sucursal(vSucursal, cantidad_sucursales);
				ES_Transacciones(vTransaccion, cantidad_transacciones);
				system("clear");
				exit(0);
			}break;
		}
	}while(opc=='S');
}
