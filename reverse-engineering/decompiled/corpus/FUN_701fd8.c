/* Ghidra analysis pseudocode, not original source.
 * ev_8dba402bb7d22455a765fa1be408776d0f2383442396bc16910bcc92f9a08d40
 * Entry: 0x701fd8; label: __frnd
 */

/* Library Function - Single Match
    __frnd
   
   Library: Visual Studio 2005 Release */

float10 __frnd(double param_1)

{
  return (float10)ROUND(param_1);
}

