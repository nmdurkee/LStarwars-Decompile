/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x441bd0; label: FUN_00441bd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441bd0(undefined4 param_1,undefined4 param_2,int param_3)

{
  float10 fVar1;
  
  if (param_3 == 0) {
    fVar1 = (float10)0;
  }
  else {
    fVar1 = (float10)*(int *)(param_3 + 0x1fc);
    if (*(int *)(param_3 + 0x1fc) < 0) {
      return fVar1 + (float10)4.2949673e+09;
    }
  }
  return fVar1;
}

