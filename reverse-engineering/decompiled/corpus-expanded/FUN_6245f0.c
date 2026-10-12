/* Ghidra pseudocode, not original source.
 * ev_d2141175d7fdb31f80696454dffb563fb6f914ee7c013e44c78745164b884694
 * Entry: 0x6245f0; label: FUN_006245f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006245f0(undefined4 *param_1,int param_2)

{
  if (*(int *)(param_2 + 0x160) != 0) {
    FUN_004ef280(*(int *)(param_2 + 0x160),
                 "d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0x623);
    *(undefined4 *)(param_2 + 0x160) = 0;
  }
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

