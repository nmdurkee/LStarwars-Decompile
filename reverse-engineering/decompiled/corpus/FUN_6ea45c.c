/* Ghidra analysis pseudocode, not original source.
 * ev_7c1f0ecd29c800f910a33bdaa344f8ed50b7b31113b7bd43cf044ecf7b83bf10
 * Entry: 0x6ea45c; label: __IsExceptionObjectToBeDestroyed
 */

/* Library Function - Single Match
    __IsExceptionObjectToBeDestroyed
   
   Library: Visual Studio 2005 Release */

undefined4 __IsExceptionObjectToBeDestroyed(int param_1)

{
  _ptiddata p_Var1;
  int *piVar2;
  
  p_Var1 = __getptd();
  piVar2 = p_Var1->_pFrameInfoChain;
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return 1;
    }
    if (*piVar2 == param_1) break;
    piVar2 = (int *)piVar2[1];
  }
  return 0;
}

