/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x61a2a0; label: FUN_0061a2a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061a2a0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x50) == 0) {
    uVar3 = 0x886;
  }
  else {
    iVar1 = FUN_004f1ff0(*(int *)(param_1 + 0x50));
    iVar2 = FUN_004f1ff0(param_2);
    if (iVar2 <= iVar1) goto LAB_0061a30b;
    FUN_004ef280(*(undefined4 *)(param_1 + 0x50),
                 "d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0x881);
    uVar3 = 0x882;
  }
  iVar1 = FUN_004f1ff0(param_2,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",uVar3);
  uVar3 = FUN_004eef40(iVar1 + 1);
  *(undefined4 *)(param_1 + 0x50) = uVar3;
LAB_0061a30b:
  FUN_004f1f10(*(undefined4 *)(param_1 + 0x50),param_2);
  return;
}

