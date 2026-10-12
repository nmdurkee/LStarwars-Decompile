/* Ghidra pseudocode, not original source.
 * ev_fbd0714d29abf1967b7a59c1140afabe8eda1c53d580ba604e59c833adf58051
 * Entry: 0x619430; label: FUN_00619430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00619430(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x24) != 0) {
    iVar1 = FUN_004f1ff0(*(int *)(param_1 + 0x24));
    iVar2 = FUN_004f1ff0(param_2);
    if (iVar1 < iVar2) {
      FUN_004ef280(*(undefined4 *)(param_1 + 0x24),
                   "d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0x516);
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    iVar1 = FUN_004f1ff0(param_2,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0x51b);
    uVar3 = FUN_004eef40(iVar1 + 1);
    *(undefined4 *)(param_1 + 0x24) = uVar3;
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    FUN_004f1f10(*(int *)(param_1 + 0x24),param_2);
    return 1;
  }
  return 0;
}

