/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x441890; label: FUN_00441890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441890(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
     (*(int *)(**(int **)(param_3 + 0xd0) + 0xec0) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

