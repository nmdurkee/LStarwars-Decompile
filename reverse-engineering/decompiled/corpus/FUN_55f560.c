/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55f560; label: FUN_0055f560
 */

void FUN_0055f560(int param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  
  *(undefined1 *)(param_1 + 0x2990) = 1;
  *(void **)(param_1 + 0x2a94) = (void *)(param_1 + 0x2991);
  _memset((void *)(param_1 + 0x2991),0,0x100);
  if (((param_2 == 0) && (iVar1 = *(int *)(param_1 + 0x13c), iVar1 != 0)) &&
     (iVar4 = *(int *)(iVar1 + 0x74), 0 < iVar4)) {
    pbVar3 = *(byte **)(param_1 + 0x2a94);
    pbVar2 = (byte *)(*(int *)(iVar1 + 0x78) + 0x10);
    do {
      *pbVar3 = *pbVar2 >> 2 & 1;
      pbVar2 = pbVar2 + 0x18;
      pbVar3 = pbVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}

