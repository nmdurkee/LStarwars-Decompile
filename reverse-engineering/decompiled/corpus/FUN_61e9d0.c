/* Ghidra analysis pseudocode, not original source.
 * ev_6eb3c0e5a4192d504e77ca733851733d52b37eecab747dc6ff26bd5be7535327
 * Entry: 0x61e9d0; label: FUN_0061e9d0
 */

void FUN_0061e9d0(undefined4 *param_1,int param_2)

{
  if (*(int *)(param_2 + 0x24) != 0) {
    FUN_004ef280(*(int *)(param_2 + 0x24),
                 "d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0x1313);
    *(undefined4 *)(param_2 + 0x24) = 0;
  }
  if (*(int *)(param_2 + 100) != 0) {
    FUN_004ef280(*(int *)(param_2 + 100),"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp"
                 ,0x1318);
    *(undefined4 *)(param_2 + 100) = 0;
  }
  FUN_004ef280(param_2,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0x131c);
  param_1[3] = *param_1;
  return;
}

