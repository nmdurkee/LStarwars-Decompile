/* Ghidra pseudocode, not original source.
 * ev_82e843d85b8a15ad0c2712a3dca0d893aca885ca51044f6184084df2488405d8
 * Entry: 0x475020; label: FUN_00475020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00475020(void)

{
  uint uVar1;
  
  uVar1 = (uint)*(char *)(DAT_00879588 * 0x130 + 0xa3 + DAT_00951b78);
  if ((((DAT_0087b02c != 0) && (*(byte *)(DAT_0087b02c + 0x7c) == uVar1)) ||
      ((*(ushort *)(uVar1 * 0x9c + 0x7a + DAT_00951354) & 0x1000) != 0)) ||
     (DAT_0087951c = 1, (&DAT_0086e0f5)[uVar1 * 0xc] == '\0')) {
    DAT_0087951c = 0;
  }
  DAT_00879514 = 0;
  return;
}

