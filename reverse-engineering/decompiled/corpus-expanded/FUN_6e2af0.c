/* Ghidra pseudocode, not original source.
 * ev_bed396bb9d0ac343cc12a945b22dca9b47e381958104004b469ab6f75949f391
 * Entry: 0x6e2af0; label: FUN_006e2af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e2af0(void)

{
  int in_ECX;
  
  *(bool *)(in_ECX + 0x66e) = *(int *)(in_ECX + 0x158) == 1;
  *(undefined4 *)(in_ECX + 0x670) = *(undefined4 *)(in_ECX + 0x620);
  *(undefined1 *)(in_ECX + 0x674) = *(undefined1 *)(in_ECX + 0x634);
  *(undefined4 *)(in_ECX + 0x678) = *(undefined4 *)(in_ECX + 0x638);
  *(undefined2 *)(in_ECX + 0x67c) = *(undefined2 *)(in_ECX + 0x6e4);
  *(undefined4 *)(in_ECX + 0x680) = DAT_00826494;
  return;
}

