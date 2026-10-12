/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55c0a0; label: FUN_0055c0a0
 */

int FUN_0055c0a0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  if ((DAT_0093b290 != 0) && (iVar2 = 0, 0 < DAT_0093b294)) {
    do {
      iVar1 = FUN_004f8b10(*(undefined4 *)(DAT_0093b290 + iVar2 * 4),param_1);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_0093b294);
  }
  return -1;
}

