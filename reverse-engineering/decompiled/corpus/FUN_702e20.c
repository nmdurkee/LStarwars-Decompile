/* Ghidra analysis pseudocode, not original source.
 * ev_8dba402bb7d22455a765fa1be408776d0f2383442396bc16910bcc92f9a08d40
 * Entry: 0x702e20; label: UnDecorator::UScore
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

