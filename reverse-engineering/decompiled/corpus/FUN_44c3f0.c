/* Ghidra analysis pseudocode, not original source.
 * ev_85221e19b589e64a8fe755bb04b61125e19a0862eea90b9888a564ab90d68d8b
 * Entry: 0x44c3f0; label: FUN_0044c3f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0044c3f0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float local_8;
  
  local_8 = 0.0;
  iVar6 = 0;
  bVar2 = false;
  iVar5 = 1;
  if (param_6 == 0) {
    return 1;
  }
  if (0 < param_5) {
    do {
      iVar3 = FUN_004f8b10("Default",*(undefined4 *)(param_4 + iVar6 * 4));
      if (iVar3 == 0) {
        fVar7 = (float10)_DAT_00855f74;
LAB_0044c485:
        local_8 = (float)fVar7;
      }
      else {
        iVar3 = FUN_004f8b10("All_Non_Party",*(undefined4 *)(param_4 + iVar6 * 4));
        if (iVar3 == 0) {
          bVar2 = true;
        }
        else {
          iVar3 = FUN_004f8b10("Locator",*(undefined4 *)(param_4 + iVar6 * 4));
          if (iVar3 != 0) {
            fVar7 = (float10)FUN_005147c0(param_2,*(undefined4 *)(param_4 + iVar6 * 4));
            goto LAB_0044c485;
          }
          iVar5 = 2;
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_5);
    if (bVar2) {
      iVar5 = 0;
      if (DAT_0093d500 < 1) {
        return 1;
      }
      puVar4 = (uint *)(DAT_0093d504 + 0x4b0);
      do {
        if ((((puVar4[-0xad] & 1) != 0) && ((puVar4[-0xad] & 0x1000) != 0)) &&
           ((puVar4[-0xae] & 0x400) != 0)) {
          puVar4[2] = (uint)local_8;
          if (local_8 <= 0.0) {
            *puVar4 = *puVar4 & 0xf3ffffff;
          }
          else {
            *puVar4 = *puVar4 & 0xf7ffffff | 0x4000000;
          }
        }
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 0x436;
      } while (iVar5 < DAT_0093d500);
      return 1;
    }
  }
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    iVar6 = *piVar1;
    *(float *)(iVar6 + 0x4b8) = local_8;
    if (0.0 < local_8) {
      *(uint *)(iVar6 + 0x4b0) =
           *(uint *)(iVar6 + 0x4b0) ^ (iVar5 << 0x1a ^ *(uint *)(iVar6 + 0x4b0)) & 0xc000000;
      return 1;
    }
    *(uint *)(iVar6 + 0x4b0) = *(uint *)(iVar6 + 0x4b0) & 0xf3ffffff;
    return 1;
  }
  return 1;
}

