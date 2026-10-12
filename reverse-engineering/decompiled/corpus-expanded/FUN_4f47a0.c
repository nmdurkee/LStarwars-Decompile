/* Ghidra pseudocode, not original source.
 * ev_621a163f2f4eeffab67db0a5a6d80d4261cbfd10193b5f3a01bc1d3544017af8
 * Entry: 0x4f47a0; label: FUN_004f47a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f47a0(int param_1,int param_2)

{
  if (-1 < (int)(&DAT_0297e044)[param_1 * 3]) {
    (&DAT_00917004)[(&DAT_0297e044)[param_1 * 3] * 0x21] = 0xffffffff;
  }
  (&DAT_0297e044)[param_1 * 3] = param_2;
  (&DAT_00917004)[param_2 * 0x21] = param_1;
  (&DAT_00917014)[param_2 * 0x21] = 0;
  return;
}

