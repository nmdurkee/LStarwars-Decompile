/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d0e80; label: FUN_005d0e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005d0e80(int param_1)

{
  if ((param_1 == 0) && (param_1 = DAT_009738b8, DAT_009738b8 == 0)) {
    return (float10)0;
  }
  return (float10)(**(float **)(param_1 + 0x30) * *(float *)(param_1 + 0x14) * _DAT_0080b60c);
}

