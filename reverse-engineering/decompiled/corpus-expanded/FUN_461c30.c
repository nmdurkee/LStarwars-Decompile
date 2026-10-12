/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x461c30; label: FUN_00461c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00461c30(int param_1,int param_2)

{
  if ((*(int *)(param_1 + 0xc) == 0x1a) && (*(char *)(param_2 + 0xa7) == '\x02')) {
    **(undefined4 **)(param_2 + 0x1c) = *(undefined4 *)(param_2 + 0x78);
  }
  if ((*(int *)(param_1 + 0xc) == 0x17) && (*(char *)(param_2 + 0xa6) == '\x02')) {
    **(undefined4 **)(param_2 + 0x1c) = *(undefined4 *)(param_2 + 0x78);
  }
  FUN_004838f0(param_2);
  return;
}

