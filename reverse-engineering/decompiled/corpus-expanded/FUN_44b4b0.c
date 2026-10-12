/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x44b4b0; label: FUN_0044b4b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044b4b0(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float local_c;
  int local_8;
  int local_4;
  
  iVar5 = 0;
  local_c = 0.0;
  local_4 = 0;
  local_8 = -1;
  if ((((param_6 != 0) && (param_5 != 0)) && (*(int *)(param_2 + 4) != 0)) && (0 < param_5)) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"name=");
      iVar3 = local_8;
      if (iVar1 == 0) {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),&DAT_00757c4c);
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"value=");
          if (iVar1 == 0) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"increment=");
            if (iVar1 == 0) {
              iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"decrement=");
              if (iVar1 == 0) goto LAB_0044b614;
              fVar7 = (float10)FUN_005147c0(param_2,iVar1 + 10);
              local_4 = -1;
            }
            else {
              fVar7 = (float10)FUN_005147c0(param_2,iVar1 + 10);
              local_4 = 1;
            }
          }
          else {
            fVar7 = (float10)FUN_005147c0(param_2,iVar1 + 6);
          }
          local_c = (float)fVar7;
        }
        else {
          FUN_005147c0(param_2,iVar1 + 3);
          iVar3 = FUN_006e6b90();
          if (3 < iVar3) {
            local_8 = -1;
            iVar3 = local_8;
          }
        }
      }
      else {
        iVar4 = 0;
        iVar6 = 0x18;
        do {
          iVar2 = FUN_004f8b10(*(undefined4 *)(*(int *)(param_2 + 4) + iVar6),iVar1 + 5);
          iVar3 = iVar4;
          if (iVar2 == 0) break;
          iVar6 = iVar6 + 8;
          iVar4 = iVar4 + 1;
          iVar3 = local_8;
        } while (iVar6 < 0x38);
      }
LAB_0044b614:
      local_8 = iVar3;
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_5);
    if (-1 < local_8) {
      if (local_4 == -1) {
        *(float *)(param_2 + 0x14 + local_8 * 4) =
             *(float *)(param_2 + 0x14 + local_8 * 4) - local_c;
      }
      else {
        if (local_4 == 0) {
          *(float *)(param_2 + 0x14 + local_8 * 4) = local_c;
          return 1;
        }
        if (local_4 == 1) {
          *(float *)(param_2 + 0x14 + local_8 * 4) =
               *(float *)(param_2 + 0x14 + local_8 * 4) + local_c;
          return 1;
        }
      }
    }
  }
  return 1;
}

