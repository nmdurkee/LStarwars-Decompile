/* Ghidra pseudocode, not original source.
 * ev_5bb5b933382fccff1624478c543279b7c4a11e7bde078056255cfa1f5dfacd26
 * Entry: 0x54e890; label: FUN_0054e890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0054e890(void)

{
  uint uVar1;
  int unaff_ESI;
  
  uVar1 = FUN_00550040();
  if ((int)((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f)) < 0x4001) {
    return *(ushort *)(unaff_ESI + 0x20) + 0x4000;
  }
  return *(ushort *)(unaff_ESI + 0x20) - 0x4000;
}

