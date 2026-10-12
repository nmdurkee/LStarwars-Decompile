/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x505e10; label: FUN_00505e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00505e10(int param_1)

{
  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xffffeff9;
  if (*(int *)(param_1 + 0xa4) != 0) {
    FUN_00502d60();
  }
  if ((*(int *)(param_1 + 0x9c) != 0) && (-1 < *(char *)(*(int *)(param_1 + 0x9c) + 9))) {
    DAT_00921359 = 0;
  }
  return;
}

