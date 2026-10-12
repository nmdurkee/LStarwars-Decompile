/* Ghidra pseudocode, not original source.
 * ev_c772dacde58c2298bb9853679eadc775f76d2c3f9befd22496ec5bd64ba1d43a
 * Entry: 0x5809a0; label: FUN_005809a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005809a0(int param_1)

{
  float fVar1;
  int iVar2;
  
  fVar1 = *(float *)(param_1 + 0xb0);
  iVar2 = FUN_0054fa60();
  return (float10)(((fVar1 + fVar1) / 65535.0) * (float)iVar2 - fVar1);
}

