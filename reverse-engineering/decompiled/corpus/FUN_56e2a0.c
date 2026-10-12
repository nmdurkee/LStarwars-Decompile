/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x56e2a0; label: FUN_0056e2a0
 */

int FUN_0056e2a0(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(PTR_DAT_008032c4 + 8);
  if ((uVar1 & 4) != 0) {
    param_1 = param_1 * 2;
  }
  if ((uVar1 & 8) != 0) {
    param_1 = param_1 * 4;
  }
  if ((uVar1 & 0x10) != 0) {
    param_1 = param_1 * 6;
  }
  if ((uVar1 & 0x20) != 0) {
    param_1 = param_1 * 8;
  }
  if ((uVar1 & 0x40) != 0) {
    param_1 = param_1 * 10;
  }
  return param_1;
}

