/* Ghidra pseudocode, not original source.
 * ev_2eacd74f46b42f047692015e667debd6c21dbe0f18f3288a1bcbfaeff2ef0d47
 * Entry: 0x4f01f0; label: FUN_004f01f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f01f0(int param_1)

{
  int iVar1;
  
  while ((param_1 < 0x400 && (0x7ff < param_1))) {
    iVar1 = (param_1 * 3 + -0x1800) * 0x10;
    param_1 = *(int *)((*(int *)(&DAT_0297dc80 + iVar1) + 3) * 0x10 +
                      *(int *)(&DAT_0297dc60 + iVar1));
  }
  return 0;
}

