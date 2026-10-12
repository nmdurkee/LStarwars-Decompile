/* Ghidra analysis pseudocode, not original source.
 * ev_7906274d0bf06d109a71291565ad9b380751ea78f5df54402dc74cb176b33c5a
 * Entry: 0x559ee0; label: FUN_00559ee0
 */

int * FUN_00559ee0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
  if ((DAT_0093b268 != (int *)0x0) && (param_1 != (int *)0x0)) {
    if (param_3 != 0) {
      param_2 = FUN_00559e20(param_1,param_3);
    }
    if ((-1 < param_2) && (param_2 < *DAT_0093b268)) {
      iVar1 = *param_1 + param_2 * 0x14;
      if (*(int *)(iVar1 + 4) < *(int *)(iVar1 + 8)) {
        piVar2 = (int *)(*(int *)(iVar1 + 0xc) + *(int *)(iVar1 + 4) * 8);
        if (piVar2 != (int *)0x0) {
          if (param_4 != 0) {
            *piVar2 = param_4;
          }
          *(undefined2 *)(piVar2 + 1) = 0;
          *(char *)((int)piVar2 + 6) = (char)param_2;
          *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
          return piVar2;
        }
      }
    }
  }
  return (int *)0x0;
}

