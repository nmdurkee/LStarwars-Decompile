/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55bd00; label: FUN_0055bd00
 */

void FUN_0055bd00(uint param_1,uint param_2,uint param_3,uint param_4,int param_5,int param_6,
                 int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < DAT_0093b278) {
    iVar1 = 0;
    iVar3 = 0;
    iVar2 = DAT_0093b274;
    do {
      if ((((param_1 == 0) || ((*(uint *)(iVar1 + 4 + iVar2) & param_1) == param_2)) &&
          ((param_3 == 0 || ((*(uint *)(iVar3 + 0x90 + DAT_0093b284) & param_3) == param_4)))) &&
         ((param_5 == -1 || (*(char *)(iVar3 + 0x116 + DAT_0093b284) == param_5)))) {
        if (param_6 != 0) {
          *(int *)(iVar1 + 0x18 + iVar2) = param_6;
          iVar2 = DAT_0093b274;
        }
        if (param_7 != 0) {
          *(int *)(iVar1 + 0x1c + iVar2) = param_7;
          iVar2 = DAT_0093b274;
        }
        if (param_8 != 0) {
          *(int *)(iVar1 + 0x20 + iVar2) = param_8;
          iVar2 = DAT_0093b274;
        }
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x120;
      iVar1 = iVar1 + 0x4c;
    } while (iVar4 < DAT_0093b278);
  }
  return;
}

