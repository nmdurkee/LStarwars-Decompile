/* Ghidra analysis pseudocode, not original source.
 * ev_4eb19e57a9d3b9beba017312b3b21652588e9c732adfcebbbddaeb757a53089f
 * Entry: 0x401900; label: FUN_00401900
 */

undefined4 * FUN_00401900(int param_1,undefined4 param_2)

{
  ushort *puVar1;
  int iVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  
  if (param_1 != 0) {
    iVar2 = 0;
    pbVar4 = (byte *)(param_1 + 0x210);
    do {
      if ((*pbVar4 & 1) == 0) {
        puVar1 = (ushort *)(iVar2 * 0x214 + 0x210 + param_1);
        *puVar1 = *puVar1 | 1;
        puVar3 = (undefined4 *)(iVar2 * 0x214 + param_1);
        *puVar3 = param_2;
        return puVar3;
      }
      iVar2 = iVar2 + 1;
      pbVar4 = pbVar4 + 0x214;
    } while (iVar2 < 0x20);
  }
  return (undefined4 *)0x0;
}

