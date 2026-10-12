/* Ghidra analysis pseudocode, not original source.
 * ev_ec07135468de31ab5fb92b99d3a0e31a017920018520f35a1e7400fac21801d6
 * Entry: 0x54e890; label: FUN_0054e890
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

