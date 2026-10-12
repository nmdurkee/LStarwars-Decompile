/* Ghidra pseudocode, not original source.
 * ev_64f3679a1f1e131a29792e896f5cd05cb4870e5bb22e267d9bfafa2e72f365ab
 * Entry: 0x5ffd50; label: FUN_005ffd50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ffd50(byte *param_1)

{
  if (*(uint *)(param_1 + 0xc) != 0) {
    if (*(int *)(param_1 + 4) != 0) {
      FUN_006e49b0(4,*(uint *)(param_1 + 0xc) / 3,
                   (&DAT_02854b8c)[*param_1] + *(int *)(param_1 + 8) * 0x18);
      return;
    }
    FUN_006e5590(0,(&DAT_0280d3cc)[*param_1],0,0x18);
    FUN_006e4980(4,*(undefined4 *)(param_1 + 8),*(uint *)(param_1 + 0xc) / 3);
  }
  return;
}

