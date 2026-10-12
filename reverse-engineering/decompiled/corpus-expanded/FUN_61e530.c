/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61e530; label: FUN_0061e530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0061e530(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 100) != 0) {
    iVar1 = FUN_004f1ff0(*(int *)(param_1 + 100));
    iVar2 = FUN_004f1ff0(param_2);
    if (iVar1 < iVar2) {
      FUN_004ef280(*(undefined4 *)(param_1 + 100),
                   "d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0x1108);
      *(undefined4 *)(param_1 + 100) = 0;
    }
  }
  if (*(int *)(param_1 + 100) == 0) {
    iVar1 = FUN_004f1ff0(param_2,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0x110d)
    ;
    uVar3 = FUN_004eef40(iVar1 + 1);
    *(undefined4 *)(param_1 + 100) = uVar3;
  }
  if (*(int *)(param_1 + 100) != 0) {
    FUN_004f1f10(*(int *)(param_1 + 100),param_2);
    return 1;
  }
  return 0;
}

