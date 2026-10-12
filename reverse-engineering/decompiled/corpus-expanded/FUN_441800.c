/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x441800; label: FUN_00441800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441800(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  if ((param_5 == 0) &&
     (((param_3 == 0 || (*(int **)(param_3 + 0xd0) == (int *)0x0)) ||
      (param_5 = **(int **)(param_3 + 0xd0), param_5 == 0)))) {
    return (float10)0;
  }
  return (float10)*(float *)(param_5 + 0xf10);
}

