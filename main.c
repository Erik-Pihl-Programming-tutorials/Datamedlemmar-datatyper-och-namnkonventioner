/********************************************************************************
* main.c: Demonstration av olika datamedlemmar i C.
* 
*         Datamedlemmar utg�rs av objekt som lagrar data p� en given adress.
*         Varje datamedlem innehar en datatyp, vilket indikerar vilken typ
*         av data som lagras, exempelvis heltal, flyttal, text med mera.
* 
*         Datamedlemmar kan vara variabla eller konstanta, vilket indikerar
*         ifall inneh�llet som de lagrar kan �ndras.
* 
*         F�r variabla datamedlemmar, �ven kallas variabler, kan inneh�llet
*         �ndras under programmet. F�r konstanta datamedlemmar kan inneh�llet
*         inte �ndras efter initiering (tilldelning av startv�rde).
* 
*         Variabler deklareras och initieras enligt nedan:
*         datatyp namn = startv�rde;
* 
*         Konstanter �r samma, f�rutom att nyckelordet const (constant) l�ggs
*         till framf�r eller bakom datatypen, normalt framf�r:
*         const datatyp namn = startv�rde;
* 
*         Som en tumregel s� b�r alla datamedlemmar vars inneh�ll inte skall
*         �ndras i ett givet block s�ttas till konstanter. Detta g�ller ocks� 
*         ing�ende argument / funktionsparametrar till funktioner.
* 
*         F�r heltal anv�nds prim�rt datatypen int, vilket st�r f�r integer
*         (heltal p� svenska). Normalt upptar en int 4 byte (32-bitar) minne,
*         vilket m�jligg�r heltal mellan -2.1 miljarder - +2.1 miljarder.
* 
*         F�r flyttal anv�nds prim�rt datatyper float och double. Float st�r
*         f�r floating point number (flyttal/decimaltal) och m�jligg�r flyttal
*         med upp till 7 decimalsiffror precision. En float upptar normalt sett
*         4 byte (32-bitar minne). Double st�r f�r att denna datatyp m�jligg�r
*         ungef�r dubbelt s� h�g precision j�mf�rt float (15 decimalsiffror
*         i st�llet f�r 7). D�rmed m�jligg�r double mer ackurata matematiska
*         ber�kningar och �r d�rmed vanligare. Double upptar normalt dubbelt 
*         s� mycket minne j�mf�rt med en float (8 byte/ 64 bitar i st�llet f�r
*         4 byte / 32 bitar). Decimalpunkten i flyttal best�r av en punkt.
*         F�r flyttal av datatypen float anv�nds bokstaven f som avslut p�
*         flyttalet f�r att indikera att flyttalet skall lagras som en double,
*         annars tolkas det som default (automatiskt) som en double.
* 
*         F�r tecken anv�nds datatypen char, vilket st�r f�r character (tecken).
*         En datamedlem av datatypen char kan enbart lagra ett enda tecken,
*         som upptar en byte (8 bitar) minne. Runt tecknet skrivs apostrofer
*         '' f�r att indikera att det just r�r sig om ett tecken. Alla tecken
*         utg�r f�r datorn ett heltal, som kan hittas genom att kolla i den
*         s� kallade ASCII-tabellen. Exempelvis ett utropstecken ! utg�r heltal
*         33 i denna tabell, citattecken "" utg�r heltal 34, A utg�r heltal 65
*         och B utg�r heltal 66.
* 
*         F�r text (multipla tecken) anv�nds ocks� char, men i form av s� kallade
*         str�ngar (string), vilket i praktiken �r f�lt/arrayer/listor med
*         konsekutiva tecken. En f�ljt av tecken kallas ocks� en str�ng med
*         tecken, vilket d�rmed ger upphov till nyckelordet string. Cittattecken
*         "" anv�nds f�r att indikera f�r kompilatorn att det r�r sig om ett
*         textstycke (multipla tecken), vilket vi d�rmed placerar runt stycket.
*         
*         Ett givet textstycke i en str�ng avslutas i C med ett nolltecken \0, 
*         vilket indikerar f�r kompilatorn var textstycket avslutas. Str�ngar 
*         i C s�gs d�rf�r vara nullterminerade. Som exempel, om vi tilldelar
*         "Kalle Anka" till en str�ng s� lagras detta enligt nedan: 
*         'K', 'a', 'l', 'l', 'e', ' ', 'A', 'n', 'k', 'a', '\0'
* 
*          Vi kan ange storlek p� en str�ng (antalet tecken den rymmer) genom
*          att skriva detta i hakparentesen, exempelvis en str�ng som deklareras
*          enligt nedan rymmer 100 tecken, �ven fast vi tilldelas namnet "Bo":
* 
*          char s2[100] = "Bo";
* 
*          Inneh�llet blir d� 'B', 'o', '\0' samt 97 tommar adresser som kan
*          fyllas vid behov. Det viktiga �r alltid att nolltecknet skall
*          avsluta textstycket. Se till att alltid initiera initiera str�ngar
*          med ett nolltecken vid start. Om nolltecknet �r l�ngst fram i 
*          str�ngen s� �r str�ngen tom (sett till textinneh�ll). Detta kan
*          antingen g�ras direkt genom att skriva f�ljande:
* 
*          char s1[100] = { '\0' };
* 
*          eller f�ljande (index 0 utg�r f�rsta elementet i f�ltet, d� 
*          kompilatorn r�knar positioner/index fr�n 0, inte 1):
*          
*          char s1[100]; // Deklarerar str�ngen.
*          s1[0] = '\0'; // Initierar str�ngen till tom vid start.
* 
*          F�r sant eller falskt anv�nds datatypen bool. Denna datatyp �r inte
*          standard i C, till skillnad mot m�nga andra programspr�k, men kan
*          implementeras via biblioteket stdbool.h sedan C99:
*          #include <stdbool.h>
* 
*          Om ni anv�nder en �ldre C-version kan datatypen bool implementeras 
*          via en s� kallad enumeration:
*          typedef enum { false, true } bool;
* 
*          I C g�ller att false = 0, true = 1.          
* 
*          I C kan datamedlemmar, funktioner, makron och dylikt enbart d�pas
*          med bokst�ver, siffror och understreck _. Dock kan siffror inte
*          b�rja namnet. D�rmed �r f�ljande namn ok:
* 
*          add_number
*          num1
*          _num1
*          num_1
* 
*          F�ljande namn �r inte ok:
* 
*          1num  // Kan inte b�rja med siffra.
*          num-1 // Kan inte inneh�lla bindestreck.
*          num!  // Kan inte inneh�lla utropstecken.
*          num 1 // Kan inte inneh�lla blanksteg.
* 
*          B�de sm� och stora bokst�ver �r okej, men generellt anv�nds enbart
*          sm� bokst�ver i C f�r datamedlemmar, funktioner med mera. Stora
*          bokst�ver anv�nds f�r s� kallade makron och s� kallade enumeratorer.
* 
*          Den vanligaste namnkonventionen i C �r snake_case, vilket best�r av
*          att vi anv�nder understreck f�r att separera ord. Detta understreck
*          s�gs likna en orm, varav namnet. Alla bokst�ver skall vara sm� f�r
*          datamedlemmar, funktioner med mera, medan f�r makron och enumeratorer
*          anv�nds stora bokst�ver. P� detta s�tt undviks namnkrockar. 

*          Exempel p� snake_case:
*          int num_of_elements = 0;
*          const int size_of_string = 100;
* 
*          Ibland anv�nds ocks� camelCase, som prim�rt �r vanligt i Java,
*          Javascript, Rust med mera. H�r anv�nds inte understreck f�r att
*          separera ord, utan man s�tter ihop dem med stor f�rsta bokstav p�
*          p� varje nytt ord. Namnet beror p� att f�rsta bokstaven i varje nytt 
*          ord utg�rs av en stor bokstav, vilket liknar en puckel. Den f�rsta
*          bokstaven p� det f�rsta ordet �r dock liten.
* 
*          Exempel p� camelCase:
*          int numOfElements = 0;
*          const int sizeOfString = 100;
* 
*          En variant p� camelCase �r PascalCase, som fr�mst anv�nds i Pascal 
*          samt i C#. PascalCase �r samma som camelCase, med skillnaden att
*          den f�rsta bokstaven i namnet utg�rs av en stor bokstav, medan det
*          i camelCase best�r av en liten bokstav.
* 
*          Exempel p� PascalCase:
*          int NumOfElements = 0;
*          const int SizeOfString = 100;
********************************************************************************/
#include <stdio.h>
#include <stdbool.h>

/* Makrodefinitioner: */
#define SIZE 100 /* Storlek p� str�ngar. */

int main(void)
{
   /* F�r heltal anv�nds prim�rt datatypen int: */
   int x = 3;
   int const y = 7;

   /* F�r flyttal anv�nds prim�rt datatyper float och double: */
   float f1 = 3.4f;
   const double d1 = 8.65;

   /* F�r tecken anv�nds prim�rt datatypen char: */
   char c1 = '!';
   const char c2 = '3';

   /* F�r text (multipla tecken) anv�nds str�ngar, vilket p praktiken �r charf�lt: */
   char name[SIZE] = { '\0' }; /* Tom str�ng, rymmer 100 tecken. */
   const char s1[] = "Kalle Anka"; /* Str�ng d�r storleken s�tts efter antalet tecken. */
   const char* s2 = "Kajsa Anka"; /* Pekare till icke d�pt str�ng. */

   /* F�r sant eller falskt anv�nds datatypen bool: */
   const bool c_programming_is_fun = true; 
   bool python_is_more_fun_than_c = false;

   /* Ovanst�ende namnkonvention kallas snake_case, vilket �r vanligast i C.
    * Dock �r det okej att anv�nda nedanst�ende namnkonventioner ocks�. */

   /* camelCase (vanligast i Java): */
   const bool cProgrammingIsFun = true;
   bool pythonIsMoreFunThanC = false;

   /* PascalCase (vanligast i C#): */
   const bool CProgrammingIsFun = true;
   bool PythonIsMoreFunThanC = false;

   return 0;
}