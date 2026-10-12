/* Ghidra analysis pseudocode, not original source.
 * ev_85221e19b589e64a8fe755bb04b61125e19a0862eea90b9888a564ab90d68d8b
 * Entry: 0x44c750; label: FUN_0044c750
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0044c750(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_10 = 1e+09;
  local_c = 1e+09;
  local_4 = 0.0;
  local_8 = 1e+09;
  if (((param_3 == 0) || (piVar1 = *(int **)(param_3 + 0xd0), piVar1 == (int *)0x0)) ||
     (*piVar1 == 0)) {
    return 1;
  }
  iVar2 = *piVar1;
  if (param_6 == 0) {
LAB_0044c908:
    if (*(float *)(param_2 + 0x70) <= 0.0) {
      return 1;
    }
    if (*(float *)(param_2 + 0x70) <= _DAT_00925018) {
      *(float *)(iVar2 + 0x102c) =
           *(float *)(param_2 + 0x74) * *(float *)(param_2 + 0x70) + *(float *)(iVar2 + 0x102c);
      *(undefined4 *)(param_2 + 0x70) = 0;
      return 1;
    }
    *(float *)(iVar2 + 0x102c) =
         _DAT_00925018 * *(float *)(param_2 + 0x74) + *(float *)(iVar2 + 0x102c);
    *(float *)(param_2 + 0x70) = *(float *)(param_2 + 0x70) - _DAT_00925018;
    return 0;
  }
  iVar5 = 0;
  if (0 < param_5) {
    do {
      iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"reset");
      if (iVar3 == 0) {
        fVar6 = (float10)(float)0x4e6e6b28;
LAB_0044c87a:
        local_8 = (float)fVar6;
      }
      else {
        iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),&DAT_00757be0);
        if (iVar3 == 0) {
          iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),&DAT_00757be8);
          if (iVar3 == 0) {
            iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),&DAT_00757ca8);
            if (iVar3 == 0) {
              fVar6 = (float10)FUN_005147c0(param_2,*(undefined4 *)(param_4 + iVar5 * 4));
              goto LAB_0044c87a;
            }
            iVar4 = FUN_004f1ff0(&DAT_00757ca8);
            fVar6 = (float10)FUN_005147c0(param_2,iVar3 + 1 + iVar4);
            local_4 = (float)fVar6;
          }
          else {
            fVar6 = (float10)FUN_005147c0(param_2,iVar3 + 4);
            local_c = (float)fVar6;
          }
        }
        else {
          fVar6 = (float10)FUN_005147c0(param_2,iVar3 + 4);
          local_10 = (float)fVar6;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_5);
    if (local_4 != 0.0) {
      if ((local_10 != 1e+09) && (local_c != 1e+09)) {
        fVar6 = (float10)FUN_005b9dd0();
        local_8 = (1.0 - (float)fVar6) * local_10 + local_c * (float)fVar6;
      }
      *(float *)(param_2 + 0x70) = local_4;
      *(float *)(param_2 + 0x74) = (local_8 - *(float *)(iVar2 + 0x102c)) / local_4;
      goto LAB_0044c908;
    }
  }
  if ((local_10 != 1e+09) && (local_c != 1e+09)) {
    fVar6 = (float10)FUN_005b9dd0();
    *(float *)(iVar2 + 0x102c) = (1.0 - (float)fVar6) * local_10 + local_c * (float)fVar6;
    return 1;
  }
  *(float *)(iVar2 + 0x102c) = local_8;
  return 1;
}

