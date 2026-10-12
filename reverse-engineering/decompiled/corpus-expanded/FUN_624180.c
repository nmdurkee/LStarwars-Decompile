/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x624180; label: FUN_00624180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00624180(undefined4 *param_1,int param_2)

{
  FUN_0061f3d0();
  if (*(int *)(param_2 + 0x24) != 0) {
    FUN_004ef280(*(int *)(param_2 + 0x24),
                 "d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0x29e);
    *(undefined4 *)(param_2 + 0x24) = 0;
  }
  FUN_004ef280(param_2,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0x2a2);
  param_1[3] = *param_1;
  return;
}

