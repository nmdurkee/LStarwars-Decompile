/* Ghidra pseudocode, not original source.
 * ev_dafa2233724afb43ee4ce5fb75a2fdf73c0a8c82e75434708f3b2ad0dea6bad5
 * Entry: 0x702e20; label: UnDecorator::UScore
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    public: static char const * __cdecl UnDecorator::UScore(enum Tokens)
   
   Library: Visual Studio 2005 Release */

char * __cdecl UnDecorator::UScore(Tokens param_1)

{
  char *pcVar1;
  
  pcVar1 = (&PTR_s___based__00780d28)[param_1];
  if ((~DAT_0297cb88 & 1) == 0) {
    pcVar1 = pcVar1 + 2;
  }
  return pcVar1;
}

