/* Ghidra analysis pseudocode, not original source.
 * ev_95f339e64e03912db0b4337524e50c5f1fa1cc6c36f27950d42195022949d97c
 * Entry: 0x594a00; label: FUN_00594a00
 */

undefined4 FUN_00594a00(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_0095587c == 0) {
    return 0;
  }
  iVar2 = 0;
  if (0 < DAT_00955878) {
    iVar3 = 0;
    do {
      iVar1 = (int)*(short *)(iVar3 + DAT_0095587c);
      if (((param_1 == -1) || (*(char *)(iVar1 * 0x120 + 0x116 + DAT_0093b284) == param_1)) &&
         ((param_2 == 0 || ((*(uint *)(iVar1 * 0x4c + 4 + DAT_0093b274) & param_2) == param_2)))) {
        iVar1 = FUN_00594960(iVar1);
        if (iVar1 != 0) {
          return 1;
        }
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x1c;
    } while (iVar2 < DAT_00955878);
  }
  return 0;
}

