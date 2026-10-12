/* Ghidra analysis pseudocode, not original source.
 * ev_7b35a8fafa232ee0b9a0913c200a618a9d6b1b7e21f700964d68a0258798e3f5
 * Entry: 0x713add; label: ___tzset
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___tzset
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl ___tzset(void)

{
  if (DAT_0297cc5c == 0) {
    __lock(6);
    if (DAT_0297cc5c == 0) {
      FUN_007133f1();
      DAT_0297cc5c = DAT_0297cc5c + 1;
    }
    FUN_00713b23();
  }
  return;
}

