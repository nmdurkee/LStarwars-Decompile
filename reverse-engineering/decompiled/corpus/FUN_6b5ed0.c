/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b5ed0; label: FUN_006b5ed0
 */

int FUN_006b5ed0(undefined4 param_1,int param_2,int param_3,uint *param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_2 + 0x504);
  iVar1 = 0;
  if (((param_3 != 0) && (param_4 != (uint *)0x0)) &&
     (iVar1 = FUN_006a1550(param_1,iVar3 * 4), 0 < iVar3)) {
    param_3 = param_3 - (int)param_4;
    iVar4 = iVar1 - (int)param_4;
    do {
      uVar2 = (int)((*param_4 & 0x7fff) * param_5 + 0x8000 +
                   (*(uint *)(param_3 + (int)param_4) & 0x7fff) * (0x10000 - param_5)) >> 0x10;
      *(uint *)(iVar4 + (int)param_4) = uVar2;
      if (((*(uint *)(param_3 + (int)param_4) & 0x8000) != 0) && ((*param_4 & 0x8000) != 0)) {
        *(uint *)(iVar4 + (int)param_4) = uVar2 | 0x8000;
      }
      param_4 = param_4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar1;
}

