/* Ghidra pseudocode, not original source.
 * ev_312b56a8c21479f8c96fd7dc1d322c1a4486fb258981ae7e1dc00f07a4c49ce9
 * Entry: 0x56cea0; label: FUN_0056cea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056cea0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x50a0) != 0)) &&
     (iVar3 = 0, 0 < *(int *)(param_1 + 0x50a4))) {
    pbVar5 = (byte *)(*(int *)(param_1 + 0x50a0) + 0x20);
    do {
      bVar2 = *pbVar5 | 3;
      *pbVar5 = bVar2;
      if ((param_3 != 0) && (iVar3 < 0x20)) {
        iVar1 = (int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5;
        uVar4 = 1 << ((byte)iVar3 & 0x1f);
        bVar2 = (((*(uint *)(param_3 + 4 + iVar1 * 4) & uVar4) != 0) * '\x02' ^ bVar2) & 2 ^ bVar2;
        *pbVar5 = bVar2;
        *pbVar5 = ((*(uint *)(param_3 + iVar1 * 4) & uVar4) != 0 ^ bVar2) & 1 ^ bVar2;
      }
      iVar3 = iVar3 + 1;
      pbVar5 = pbVar5 + 0x24;
    } while (iVar3 < *(int *)(param_1 + 0x50a4));
  }
  return;
}

