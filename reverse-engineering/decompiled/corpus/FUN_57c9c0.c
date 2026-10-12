/* Ghidra analysis pseudocode, not original source.
 * ev_df641eda8072cee71ca3b2626b4685e3428f565924a572e6fdc3ba5eae4c5d68
 * Entry: 0x57c9c0; label: FUN_0057c9c0
 */

void FUN_0057c9c0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_10;
  int local_c;
  int local_8;
  
  if ((param_1 != (int *)0x0) && (local_8 = 0, 0 < param_1[1])) {
    do {
      iVar5 = 0;
      piVar1 = *(int **)(*param_1 + local_8 * 4);
      iVar2 = piVar1[1];
      if (iVar2 != 0) {
        piVar1 = *(int **)(*piVar1 + 0x18);
        piVar3 = *(int **)(iVar2 + 0xa4);
        if (((piVar1 != (int *)0x0) && (piVar3 != (int *)0x0)) &&
           (local_c = 0, (short)piVar1[1] != 0)) {
          local_10 = 0;
          do {
            iVar2 = *piVar1;
            piVar6 = (int *)(*piVar3 + local_10);
            if (*piVar6 == 1) {
              if ((*(byte *)(piVar6 + 5) & 2) == 0) {
                iVar4 = FUN_0057bf50(*(undefined4 *)(iVar2 + iVar5 + 0x40),*(byte *)(piVar6 + 5) & 2
                                     ,0);
                *piVar6 = iVar4;
              }
              else {
                *piVar6 = 0;
              }
              *(int *)(iVar2 + iVar5 + 0x50) = *piVar6;
            }
            local_10 = local_10 + 0x18;
            local_c = local_c + 1;
            iVar5 = iVar5 + 100;
          } while (local_c < (int)(uint)*(ushort *)(piVar1 + 1));
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < param_1[1]);
  }
  return;
}

