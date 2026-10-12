/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c9af0; label: FUN_005c9af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c9af0(int param_1,int param_2)

{
  while( true ) {
    if (*(int *)(param_1 + 0x24) != 0) {
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + param_2;
    }
    if (*(int *)(param_1 + 0x28) != 0) {
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + param_2;
    }
    if (*(int *)(param_1 + 0x2c) != 0) {
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + param_2;
    }
    if (*(int *)(param_1 + 0x30) != 0) {
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + param_2;
    }
    if (*(int *)(param_1 + 0x34) != 0) {
      *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + param_2;
    }
    if (*(int *)(param_1 + 0x38) != 0) {
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + param_2;
    }
    if (*(ushort *)(param_1 + 0x14) == 0) break;
    param_1 = param_1 + (uint)*(ushort *)(param_1 + 0x14);
  }
  return;
}

