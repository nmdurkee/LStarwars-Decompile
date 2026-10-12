/* Ghidra pseudocode, not original source.
 * ev_679903358dce225aedf8e0cd6850e85c923706fd55f3fc08c48a53cda153f2a5
 * Entry: 0x713add; label: ___tzset
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

