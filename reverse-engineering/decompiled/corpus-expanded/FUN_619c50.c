/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x619c50; label: FUN_00619c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00619c50(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x160) == 0) {
    uVar3 = 0x635;
  }
  else {
    iVar1 = FUN_004f1ff0(*(int *)(param_1 + 0x160));
    iVar2 = FUN_004f1ff0(param_2);
    if (iVar2 <= iVar1) goto LAB_00619cc4;
    FUN_004ef280(*(undefined4 *)(param_1 + 0x160),
                 "d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0x630);
    uVar3 = 0x631;
  }
  iVar1 = FUN_004f1ff0(param_2,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",uVar3);
  uVar3 = FUN_004eef40(iVar1 + 1);
  *(undefined4 *)(param_1 + 0x160) = uVar3;
LAB_00619cc4:
  FUN_004f1f10(*(undefined4 *)(param_1 + 0x160),param_2);
  return;
}

