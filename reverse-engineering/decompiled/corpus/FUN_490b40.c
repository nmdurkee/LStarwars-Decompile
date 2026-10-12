/* Ghidra analysis pseudocode, not original source.
 * ev_966db37b3c76367cdd19664fe0d1b84c77d56b151d5f2c268a183ca8a07fabfc
 * Entry: 0x490b40; label: FUN_00490b40
 */

undefined4 FUN_00490b40(int param_1)

{
  float fVar1;
  
  if ((((*(ushort *)(param_1 + 0x94) & 0x10) != 0) && ((*(ushort *)(param_1 + 0x94) & 2) != 0)) &&
     (fVar1 = *(float *)(param_1 + 0x78), !NAN(fVar1) && 1.0 < fVar1 != (fVar1 == 1.0))) {
    return 1;
  }
  return 0;
}

