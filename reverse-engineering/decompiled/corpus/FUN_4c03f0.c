/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4c03f0; label: FUN_004c03f0
 */

void FUN_004c03f0(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x5094)) {
    iVar3 = 0;
    do {
      pbVar1 = (byte *)(*(int *)(param_1 + 0x5090) + 0x3c + iVar3);
      *pbVar1 = *pbVar1 & 0xdf;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x54;
    } while (iVar2 < *(int *)(param_1 + 0x5094));
  }
  return;
}

