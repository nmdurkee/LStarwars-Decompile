/* Ghidra pseudocode, not original source.
 * ev_e04dcb01310c2b6a71419ceaaf6429f586bcd28525a19be66005014cd18274f1
 * Entry: 0x74b770; label: FUN_0074b770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074b770(void)

{
  int *in_ECX;
  
  if (*in_ECX == 0) {
    FUN_006e9fe6();
  }
  if (*(uint *)(*in_ECX + 8) <= (uint)in_ECX[1]) {
    FUN_006e9fe6();
  }
  in_ECX[1] = in_ECX[1] + 4;
  return;
}

