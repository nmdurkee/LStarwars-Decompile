/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e0b60; label: FUN_005e0b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e0b60(int param_1)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x4c)) {
    do {
      iVar1 = iVar3 * 4;
      iVar3 = iVar3 + 1;
      *(undefined1 *)(*(int *)(*(int *)(*(int *)(param_1 + 0x54) + iVar1) + 0xc) + 1) = 0;
    } while (iVar3 < *(int *)(param_1 + 0x4c));
  }
  uVar5 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      pbVar2 = (byte *)(*(int *)(param_1 + 0x30 + (*(uint *)(param_1 + 0x74) >> 0xf & 1) * 4) +
                       ((int)uVar5 >> 2));
      uVar4 = uVar5 & 0x80000003;
      if ((int)uVar4 < 0) {
        uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
      }
      uVar5 = uVar5 + 1;
      *pbVar2 = *pbVar2 | '\x01' << ((char)uVar4 * '\x02' & 0x1fU);
    } while ((int)uVar5 < *(int *)(param_1 + 0x10));
  }
  return;
}

