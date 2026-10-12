/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x6559a0; label: FUN_006559a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006559a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != -1) {
    param_1 = param_1 * 0x330;
    *(undefined4 *)(param_1 + 0x1b4 + DAT_029620a4) = param_2;
    *(undefined4 *)(param_1 + 0x1b8 + DAT_029620a4) = param_3;
    *(undefined4 *)(param_1 + 0x1bc + DAT_029620a4) = param_4;
  }
  return;
}

