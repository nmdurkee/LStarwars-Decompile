/* Ghidra analysis pseudocode, not original source.
 * ev_736d016f9ed2fadbfa7f3950efe555b6c19e61f5838dfc9040f9274543b1106f
 * Entry: 0x5159a0; label: FUN_005159a0
 */

undefined4
FUN_005159a0(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_c;
  float local_8;
  int local_4;
  
  iVar4 = 0;
  local_8 = 0.0;
  local_c = 0.0;
  local_4 = 0;
  if (param_6 == 0) {
    if (*(char *)(param_2 + 0x68) == '\0') {
      if (0.0 < *(float *)(param_2 + 0x9c)) {
        param_7 = *(float *)(param_2 + 0x9c) - param_7;
        *(float *)(param_2 + 0x9c) = param_7;
        if (param_7 < 0.0 != (param_7 == 0.0)) {
          *(undefined4 *)(param_2 + 0x9c) = 0;
          return 1;
        }
      }
    }
    else {
      cVar1 = *(char *)(param_2 + 0x68) + -1;
      *(char *)(param_2 + 0x68) = cVar1;
      if (cVar1 == '\0') {
        return 1;
      }
    }
    return 0;
  }
  if (0 < param_5) {
    do {
      iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"mintime");
      if (iVar2 == 0) {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"maxtime");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"frames");
          if (iVar2 == 0) {
            fVar5 = (float10)FUN_00514920(param_3,param_2,*(undefined4 *)(param_4 + iVar4 * 4));
            *(float *)(param_2 + 0x9c) = (float)fVar5;
          }
          else {
            iVar3 = FUN_004f1ff0("frames");
            FUN_00514920(param_3,param_2,iVar2 + 1 + iVar3);
            local_4 = FUN_006e6b90();
          }
        }
        else {
          iVar3 = FUN_004f1ff0("maxtime");
          fVar5 = (float10)FUN_00514920(param_3,param_2,iVar2 + 1 + iVar3);
          local_c = (float)fVar5;
        }
      }
      else {
        iVar3 = FUN_004f1ff0("mintime");
        fVar5 = (float10)FUN_00514920(param_3,param_2,iVar2 + 1 + iVar3);
        local_8 = (float)fVar5;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_5);
    if (local_4 != 0) {
      if (-1 < local_4) {
        if (0xff < local_4) {
          local_4 = 0xff;
        }
        *(char *)(param_2 + 0x68) = (char)local_4;
        return 0;
      }
      *(undefined1 *)(param_2 + 0x68) = 0;
      return 0;
    }
  }
  if ((*(float *)(param_2 + 0x9c) == 0.0) && (local_8 < local_c)) {
    fVar5 = (float10)FUN_005b9dd0();
    *(float *)(param_2 + 0x9c) =
         (float)(fVar5 * ((float10)local_c - (float10)local_8) + (float10)local_8);
    return 0;
  }
  return 0;
}

