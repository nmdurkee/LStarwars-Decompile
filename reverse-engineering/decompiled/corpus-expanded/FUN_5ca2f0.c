/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5ca2f0; label: FUN_005ca2f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ca2f0(int param_1)

{
  if (param_1 != 0) {
    FUN_006de960();
    FUN_006de960();
    *(undefined2 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}

