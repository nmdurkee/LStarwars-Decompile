/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x464f40; label: FUN_00464f40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00464f40(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_8;
  int local_4;
  
  local_8 = 0.0;
  iVar4 = 0;
  iVar3 = 0;
  local_4 = 0;
  if (0 < param_4) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),&DAT_00758a60);
      if (iVar1 == 0) {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),&DAT_00758a5c);
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),"increment=");
          if (iVar1 == 0) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),"decrement=");
            if (iVar1 == 0) goto LAB_00465014;
            fVar5 = (float10)FUN_004f28e0(iVar1 + 10);
            iVar3 = -1;
          }
          else {
            fVar5 = (float10)FUN_004f28e0(iVar1 + 10);
            iVar3 = 1;
          }
        }
        else {
          iVar2 = FUN_004f1ff0(&DAT_00758a5c);
          fVar5 = (float10)FUN_004f28e0(iVar1 + 1 + iVar2);
        }
        local_8 = (float)fVar5;
      }
      else {
        iVar2 = FUN_004f1ff0(&DAT_00758a60);
        local_4 = iVar2 + 1 + iVar1;
      }
LAB_00465014:
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_4);
  }
  iVar4 = FUN_005aac00(DAT_0095df4c,local_4,0);
  if (iVar3 == -1) {
    *(float *)(iVar4 + 0x28) = *(float *)(iVar4 + 0x28) - local_8;
  }
  else {
    if (iVar3 == 0) {
      *(float *)(iVar4 + 0x28) = local_8;
      return;
    }
    if (iVar3 == 1) {
      *(float *)(iVar4 + 0x28) = local_8 + *(float *)(iVar4 + 0x28);
      return;
    }
  }
  return;
}

