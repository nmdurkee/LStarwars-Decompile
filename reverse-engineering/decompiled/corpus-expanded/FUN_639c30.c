/* Ghidra pseudocode, not original source.
 * ev_0952b0bbf23c1bfc131ce83756decc1784d73ed65e88e3a7d77cb66c992cfe6b
 * Entry: 0x639c30; label: FUN_00639c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00639c30(int param_1)

{
  if ((DAT_0291396c != 0) && (*(int *)(DAT_0291396c + 0xd0 + param_1 * 0x24) != 0)) {
    *(undefined4 *)(DAT_0291396c + 0xd0 + param_1 * 0x24) = 0;
    *(int *)(DAT_0291396c + 0x550) = *(int *)(DAT_0291396c + 0x550) + -1;
    *(undefined4 *)(DAT_0291396c + 0x554) = 0xffffffff;
  }
  return;
}

