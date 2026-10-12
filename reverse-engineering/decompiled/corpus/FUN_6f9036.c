/* Ghidra analysis pseudocode, not original source.
 * ev_ad38b5b12c7b5b6be74e46159191c12aead9520624245f9f1862d693e1fa9ce5
 * Entry: 0x6f9036; label: ___CxxExceptionFilter
 */

/* Library Function - Single Match
    ___CxxExceptionFilter
   
   Library: Visual Studio 2005 Release */

int __cdecl ___CxxExceptionFilter(void *param_1,void *param_2,int param_3,void *param_4)

{
  int iVar1;
  _ptiddata p_Var2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint local_14;
  void *local_10;
  
  if (param_1 == (void *)0x0) {
    return 0;
  }
  piVar5 = *(int **)param_1;
  if (((param_2 == (void *)0x0) || (*(char *)((int)param_2 + 8) == '\0')) &&
     ((*piVar5 == -0x1fbcb0b3 || ((param_3 & 0x40U) == 0)))) {
    if (((((*piVar5 != -0x1f928c9d) || (piVar5[4] != 3)) ||
         ((iVar6 = piVar5[5], iVar6 != 0x19930520 &&
          ((iVar6 != 0x19930521 && (iVar6 != 0x19930522)))))) || (piVar5[7] != 0)) ||
       (p_Var2 = __getptd(), p_Var2->_curexception != (void *)0x0)) {
      p_Var2 = __getptd();
      p_Var2->_ProcessingThrow = p_Var2->_ProcessingThrow + 1;
      return 1;
    }
  }
  else if (((*piVar5 == -0x1f928c9d) && (piVar5[4] == 3)) &&
          ((iVar6 = piVar5[5], iVar6 == 0x19930520 ||
           ((iVar6 == 0x19930521 || (iVar6 == 0x19930522)))))) {
    if (piVar5[7] == 0) {
      p_Var2 = __getptd();
      if (p_Var2->_curexception == (void *)0x0) {
        return 0;
      }
      p_Var2 = __getptd();
      piVar5 = p_Var2->_curexception;
    }
    piVar4 = *(int **)(piVar5[7] + 0xc);
    local_14 = param_3 | 0x80000000;
    local_10 = param_2;
    for (iVar6 = *piVar4; piVar4 = piVar4 + 1, 0 < iVar6; iVar6 = iVar6 + -1) {
      iVar1 = *piVar4;
      iVar3 = ___TypeMatch(&local_14,iVar1,piVar5[7]);
      if (iVar3 != 0) {
        p_Var2 = __getptd();
        p_Var2->_ProcessingThrow = p_Var2->_ProcessingThrow + 1;
        if (param_4 == (void *)0x0) {
          return 1;
        }
        ___BuildCatchObject(piVar5,param_4,&local_14,iVar1);
        return 1;
      }
    }
  }
  return 0;
}

