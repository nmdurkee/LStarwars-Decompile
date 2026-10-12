/* Ghidra pseudocode, not original source.
 * ev_c772dacde58c2298bb9853679eadc775f76d2c3f9befd22496ec5bd64ba1d43a
 * Entry: 0x580950; label: FUN_00580950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined2 FUN_00580950(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = (&DAT_029899a0)[*(ushort *)(param_1 + 0x5a) >> 1];
    param_2[1] = 0;
    param_2[2] = (&DAT_029899a0)[(int)(*(ushort *)(param_1 + 0x5a) + 0x4000) >> 1 & 0x7fff];
    return *(undefined2 *)(param_1 + 0x5a);
  }
  return *(undefined2 *)(param_1 + 0x5a);
}

