/* Ghidra pseudocode, not original source.
 * ev_8263a5d3e8c49c8909e3cfceaf1282da1bb42b3174c131367c36677ef6ae0531
 * Entry: 0x63a950; label: FUN_0063a950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063a950(undefined4 param_1,int param_2)

{
  if (DAT_0291396c != 0) {
    *(undefined4 *)(DAT_0291396c + 0xf0 + *(int *)(DAT_0291396c + 0x554) * 0x24) =
         *(undefined4 *)(param_2 + 0x54);
  }
  return;
}

