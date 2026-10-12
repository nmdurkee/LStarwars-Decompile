/* Ghidra pseudocode, not original source.
 * ev_167fb1af16662301ac7ec00e42056ea51ba92ee67c43a8d5117ba6e42cb74a01
 * Entry: 0x6f040c; label: __getptd
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __getptd
   
   Library: Visual Studio 2005 Release */

_ptiddata __cdecl __getptd(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = (_ptiddata)FUN_006f0395();
  if (p_Var1 == (_ptiddata)0x0) {
    __amsg_exit(0x10);
  }
  return p_Var1;
}

