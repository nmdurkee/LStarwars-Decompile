/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55c980; label: FUN_0055c980
 */

void FUN_0055c980(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 2;
  DAT_0093d500 = 0;
  pbVar1 = (byte *)(DAT_0093d504 + 0x12d4);
  iVar3 = 0x10;
  do {
    if ((pbVar1[-0x10d8] & 1) != 0) {
      DAT_0093d500 = iVar2 + -1;
    }
    if ((*pbVar1 & 1) != 0) {
      DAT_0093d500 = iVar2;
    }
    if ((pbVar1[0x10d8] & 1) != 0) {
      DAT_0093d500 = iVar2 + 1;
    }
    if ((pbVar1[0x21b0] & 1) != 0) {
      DAT_0093d500 = iVar2 + 2;
    }
    iVar2 = iVar2 + 4;
    pbVar1 = pbVar1 + 0x4360;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

