/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x44c5f0; label: FUN_0044c5f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044c5f0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_8;
  float local_4;
  
  local_8 = 1e+09;
  local_4 = 1e+09;
  if (((param_3 == 0) || (piVar1 = *(int **)(param_3 + 0xd0), piVar1 == (int *)0x0)) ||
     (*piVar1 == 0)) {
    return 1;
  }
  iVar2 = *piVar1;
  if (param_6 != 0) {
    *(uint *)(iVar2 + 0xeec) = *(uint *)(iVar2 + 0xeec) & 0x7fffffff;
    *(undefined4 *)(iVar2 + 0x1028) = 0x4e6e6b28;
    iVar4 = 0;
    if (0 < param_5) {
      do {
        iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"reset");
        if (iVar3 != 0) {
          iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757be0);
          if (iVar3 == 0) {
            iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757be8);
            if (iVar3 == 0) {
              fVar5 = (float10)FUN_005147c0(param_2,*(undefined4 *)(param_4 + iVar4 * 4));
              *(float *)(iVar2 + 0x1028) = (float)fVar5;
            }
            else {
              fVar5 = (float10)FUN_005147c0(param_2,iVar3 + 4);
              local_4 = (float)fVar5;
            }
          }
          else {
            fVar5 = (float10)FUN_005147c0(param_2,iVar3 + 4);
            local_8 = (float)fVar5;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
    if ((local_8 != 1e+09) && (local_4 != 1e+09)) {
      fVar5 = (float10)FUN_005b9dd0();
      *(float *)(iVar2 + 0x1028) = (1.0 - (float)fVar5) * local_8 + local_4 * (float)fVar5;
      return 1;
    }
  }
  return 1;
}

