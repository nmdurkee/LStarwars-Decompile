/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59a620; label: FUN_0059a620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_0059a620(int param_1,int *param_2,uint *param_3,int param_4)

{
  size_t _Size;
  int *piVar1;
  void *_Dst;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  _Dst = (void *)(*param_2 + 0xfU & 0xfffffff0);
  _Size = param_4 * 0x40 + 0x18;
  *param_2 = (int)_Dst;
  if ((param_4 != 0) && ((int)_Dst + _Size <= *param_3)) {
    _memset(_Dst,0,_Size);
    piVar1 = (int *)*param_2;
    *param_2 = (int)(piVar1 + 6);
    *piVar1 = (int)(piVar1 + 6);
    piVar1[4] = param_4;
    iVar4 = 1;
    piVar1[3] = param_1;
    piVar1[2] = *piVar1;
    if (1 < param_4 + -1) {
      iVar5 = 0x40;
      iVar3 = *piVar1;
      do {
        iVar2 = *piVar1 + iVar5;
        *(int *)(iVar3 + 0x38) = iVar2;
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0x40;
        iVar3 = iVar2;
      } while (iVar4 < piVar1[4] + -1);
    }
    *param_2 = *param_2 + param_4 * 0x40;
    return piVar1;
  }
  return (int *)0x0;
}

