/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x40ee00; label: FUN_0040ee00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

