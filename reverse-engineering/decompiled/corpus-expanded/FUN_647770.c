/* Ghidra pseudocode, not original source.
 * ev_4cb705c119a92d6224ed1b3e942cece0f3f9eff485159b2837ae2ccadb058a2e
 * Entry: 0x647770; label: FUN_00647770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00647770(undefined4 param_1,int param_2)

{
  if (DAT_02920970 != 0) {
    *(undefined4 *)(DAT_02920970 + 0xf8) = *(undefined4 *)(param_2 + 0x54);
  }
  return;
}

