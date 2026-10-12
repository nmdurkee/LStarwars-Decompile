/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40ee00; label: FUN_0040ee00
 */

void FUN_0040ee00(void)

{
  uint *in_ECX;
  uint uVar1;
  uint uVar2;
  
  if ((in_ECX != (uint *)0x0) && (in_ECX[1] != 0)) {
    uVar1 = *in_ECX;
    uVar2 = in_ECX[1] * 0x60 + uVar1;
    for (; uVar1 < uVar2; uVar1 = uVar1 + 0x60) {
      if (*(float *)(uVar1 + 0x50) != 0.0) {
        FUN_00552bc0(PTR_DAT_00802c54,*(undefined4 *)(&DAT_007f1710 + *(int *)(uVar1 + 0x58) * 4),
                     uVar1);
        FUN_00552bc0(PTR_DAT_00802c54,*(undefined4 *)(&DAT_007f1700 + *(int *)(uVar1 + 0x58) * 4),
                     uVar1);
      }
    }
  }
  return;
}

