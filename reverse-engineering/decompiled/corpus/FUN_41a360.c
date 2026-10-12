/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41a360; label: FUN_0041a360
 */

undefined4 FUN_0041a360(uint param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar2 = &DAT_0093d7f0;
  do {
    iVar4 = *piVar2;
    if ((iVar4 != 0) && (iVar3 = *(int *)(iVar4 + 0x54), iVar3 != 0)) {
      if (param_1 != 0) {
        if ((*(uint *)(iVar3 + 4) & param_1) == param_1) {
          if (param_4 == 0) {
            return 1;
          }
        }
        else if (param_4 != 0) goto LAB_0041a3de;
      }
      if (param_2 != -1) {
        if (*(char *)(*(int *)(iVar3 + 0x24) + 0x116) == param_2) {
          if (param_4 == 0) {
            return 1;
          }
        }
        else if (param_4 != 0) goto LAB_0041a3de;
      }
      if (param_3 == 0) {
        return 1;
      }
      if (*(byte *)(iVar4 + 0x1082) == param_3) {
        return 1;
      }
    }
LAB_0041a3de:
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0x93d810);
  if ((DAT_0093b2a4 != 0) && (iVar4 = 0, 0 < *DAT_029130e4)) {
    iVar5 = 0;
    iVar3 = 0;
    do {
      if ((((*(short *)(DAT_029130e4[7] + iVar4 * 2) != -1) && (DAT_0093b2a4 != 0)) &&
          ((*(uint *)(iVar5 + 0x90 + DAT_0093b284) & 0x80000000) != 0)) &&
         (iVar1 = FUN_0056e0f0(0x100), iVar1 != 0)) {
        if (param_1 != 0) {
          if ((*(uint *)(iVar3 + 4 + DAT_0093b274) & param_1) == param_1) {
            if (param_4 == 0) {
              return 1;
            }
          }
          else if (param_4 != 0) goto LAB_0041a4a0;
        }
        if (param_2 == -1) {
          return 1;
        }
        if (*(char *)(iVar5 + 0x116 + DAT_0093b284) == param_2) {
          return 1;
        }
      }
LAB_0041a4a0:
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x4c;
      iVar5 = iVar5 + 0x120;
    } while (iVar4 < *DAT_029130e4);
  }
  return 0;
}

