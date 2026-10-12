/* Ghidra pseudocode, not original source.
 * ev_6293e9c45219377b80e3d0963b70152e043cc5400ac7177165af43f16814c89d
 * Entry: 0x442510; label: FUN_00442510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442510(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                    int param_5)

{
  if (-1 < param_5) {
    return (float10)*(float *)(param_2 + 0x14 + param_5 * 4);
  }
  return (float10)0;
}

