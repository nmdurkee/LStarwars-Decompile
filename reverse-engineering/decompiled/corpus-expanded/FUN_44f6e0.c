/* Ghidra pseudocode, not original source.
 * ev_4aa7baba24777c7cef62b6758f8d176321ddee5c4eaac4ea92e033f295beb802
 * Entry: 0x44f6e0; label: FUN_0044f6e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0044f6e0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = 1.0;
  local_4 = 0.0;
  local_8 = 1e+09;
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) && ((iVar2 = *piVar1, param_5 != 0 && (iVar4 = 0, 0 < param_5)))) {
    do {
      iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"value=");
      if (iVar3 == 0) {
        iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"multiply_by=");
        if (iVar3 == 0) {
          iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757be8);
          if (iVar3 == 0) {
            iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757be0);
            if (iVar3 != 0) {
              fVar5 = (float10)FUN_005147c0(param_2,iVar3 + 4);
              local_4 = (float)fVar5;
            }
          }
          else {
            fVar5 = (float10)FUN_005147c0(param_2,iVar3 + 4);
            local_8 = (float)fVar5;
          }
        }
        else {
          fVar5 = (float10)FUN_005147c0(param_2,iVar3 + 0xc);
          local_c = (float)fVar5;
        }
      }
      else {
        fVar5 = (float10)FUN_005147c0(param_2,iVar3 + 6);
        *(float *)(iVar2 + 0x1034) = (float)fVar5;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_5);
    if (local_c != 1.0) {
      local_c = local_c * *(float *)(iVar2 + 0x1034);
      *(float *)(iVar2 + 0x1034) = local_c;
      if ((local_8 < local_c) || (local_8 = local_4, local_c < local_4)) {
        *(float *)(iVar2 + 0x1034) = local_8;
        return 1;
      }
    }
  }
  return 1;
}

