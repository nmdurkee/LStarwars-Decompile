/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x528010; label: FUN_00528010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00528010(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = DAT_00921f50 >> 8;
  for (iVar1 = FUN_004f1440(DAT_009238e4 + 0x43814); iVar1 != 0;
      iVar1 = FUN_004f1460(DAT_009238e4 + 0x43814,iVar1)) {
    if ((DAT_009220ee == DAT_00801cac) && (*(int *)(DAT_009238e4 + 0x4381c) == iVar1)) {
      if (*(int *)(DAT_009238e4 + 0x4381c) == *(int *)(DAT_009238e4 + 0x43820)) {
        FUN_005cfac0(iVar1 + 0x20);
      }
      else {
        FUN_005cfac0(iVar1 + 0x20);
      }
    }
    FUN_00527e80(uVar2 & 1);
  }
  return;
}

