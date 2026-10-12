/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5eef80; label: FUN_005eef80
 */

uint FUN_005eef80(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  
  if (param_2 != 0) {
    iVar2 = FUN_005f8fd0();
    if (param_2 != iVar2) {
      if (param_2 < 1) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(DAT_0097157c + -4 + param_2 * 4);
      }
      uVar5 = 0;
      if (param_1[1] == 0) {
        return 0xffffffff;
      }
      do {
        iVar4 = 0;
        pcVar3 = (char *)(*(int *)(param_1[2] + uVar5 * 4) + 8);
        do {
          if (*(char *)(iVar2 + 8 + iVar4) != *pcVar3) goto LAB_005eeffe;
          iVar4 = iVar4 + 1;
          pcVar3 = pcVar3 + 1;
        } while (iVar4 < 0x10);
        if (*(int *)(*param_1 + uVar5 * 4) == param_2) {
          if (*(int *)(*(int *)(param_1[2] + uVar5 * 4) + 0x18) < 0) {
            if ((0 < param_2) && (iVar2 = *(int *)(DAT_0097157c + -4 + param_2 * 4), iVar2 != 0)) {
              piVar1 = (int *)(iVar2 + 0x18);
              *piVar1 = *piVar1 + -1;
            }
            uVar5 = uVar5 | 0x4000;
          }
          return uVar5;
        }
LAB_005eeffe:
        uVar5 = uVar5 + 1;
        if (uVar5 == param_1[1]) {
          return 0xffffffff;
        }
      } while( true );
    }
    if ((0 < param_2) && (iVar2 = *(int *)(DAT_0097157c + -4 + param_2 * 4), iVar2 != 0)) {
      piVar1 = (int *)(iVar2 + 0x18);
      *piVar1 = *piVar1 + -1;
    }
  }
  return 0xffffffff;
}

