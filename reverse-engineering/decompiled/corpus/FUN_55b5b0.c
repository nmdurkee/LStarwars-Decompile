/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55b5b0; label: FUN_0055b5b0
 */

void FUN_0055b5b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0x2980) != 0) && (iVar3 = 0, 0 < DAT_0093b278)) {
    iVar2 = 0;
    do {
      iVar1 = *(int *)(iVar2 + *(int *)(param_1 + 0x2980));
      if (iVar1 != 0) {
        FUN_005ef880(iVar1);
      }
      *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x2980)) = 0;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x10;
    } while (iVar3 < DAT_0093b278);
  }
  return;
}

