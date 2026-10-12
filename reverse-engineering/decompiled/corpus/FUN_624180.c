/* Ghidra analysis pseudocode, not original source.
 * ev_0d221f2c9357ed308f9b597510bd130964f67481868d3ff45e1443ef5eb3d7b9
 * Entry: 0x624180; label: FUN_00624180
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

