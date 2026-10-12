/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x495290; label: FUN_00495290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00495290(int param_1)

{
  float fVar1;
  
  if ((*(int *)(param_1 + 100) == 0) &&
     (fVar1 = *(float *)(param_1 + 4), NAN(fVar1) || 10.0 < fVar1 == (fVar1 == 10.0))) {
    return;
  }
  FUN_0054b580(*(undefined4 *)(PTR_DAT_00802360 + *(int *)(param_1 + 0x34) * 8));
  FUN_00509ab0();
  return;
}

