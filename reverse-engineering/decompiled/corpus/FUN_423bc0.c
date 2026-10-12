/* Ghidra analysis pseudocode, not original source.
 * ev_8e49f0d7b7d603436767358480d73156eb2c225a9905dada8633f81c37eed0ad
 * Entry: 0x423bc0; label: FUN_00423bc0
 */

void FUN_00423bc0(int param_1)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != 0) {
    iVar4 = param_1 + 0x70;
    psVar2 = (short *)(param_1 + 0x6c);
    iVar3 = 2;
    do {
      if ((*psVar2 != -1) && (iVar1 = *(int *)(*psVar2 * 0x4c + DAT_0093b274), iVar1 != -1)) {
        FUN_004f1f10(iVar4,*(undefined4 *)(DAT_00926c20 + iVar1 * 4));
        *(int *)(DAT_00926c20 + iVar1 * 4) = iVar4;
      }
      psVar2 = psVar2 + 1;
      iVar4 = iVar4 + 0x80;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

