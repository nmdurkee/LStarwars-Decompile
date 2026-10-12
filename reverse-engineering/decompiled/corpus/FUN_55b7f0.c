/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55b7f0; label: FUN_0055b7f0
 */

void FUN_0055b7f0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((DAT_0093b270 != 0) && (iVar3 = 0, iVar2 = DAT_0093b270, 0 < DAT_0093b278)) {
    do {
      iVar1 = *(int *)(iVar2 + iVar3 * 4);
      if (iVar1 != 0) {
        FUN_005ef880(iVar1);
        iVar2 = DAT_0093b270;
        *(undefined4 *)(DAT_0093b270 + iVar3 * 4) = 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_0093b278);
  }
  return;
}

