/* Ghidra pseudocode, not original source.
 * ev_4cb705c119a92d6224ed1b3e942cece0f3f9eff485159b2837ae2ccadb058a2e
 * Entry: 0x647b00; label: FUN_00647b00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00647b00(undefined4 param_1,int param_2)

{
  if (DAT_02920970 != 0) {
    *(float *)(DAT_02920970 + 200) = *(float *)(param_2 + 0x54) + *(float *)(param_2 + 0x54);
  }
  return;
}

