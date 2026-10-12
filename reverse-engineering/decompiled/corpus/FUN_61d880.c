/* Ghidra analysis pseudocode, not original source.
 * ev_6eb3c0e5a4192d504e77ca733851733d52b37eecab747dc6ff26bd5be7535327
 * Entry: 0x61d880; label: FUN_0061d880
 */

void FUN_0061d880(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 100) == 0) {
    uVar3 = 0xfab;
  }
  else {
    iVar1 = FUN_004f1ff0(*(int *)(param_1 + 100));
    iVar2 = FUN_004f1ff0(param_2);
    if (iVar2 <= iVar1) goto LAB_0061d8eb;
    FUN_004ef280(*(undefined4 *)(param_1 + 100),
                 "d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0xfa6);
    uVar3 = 0xfa7;
  }
  iVar1 = FUN_004f1ff0(param_2,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",uVar3);
  uVar3 = FUN_004eef40(iVar1 + 1);
  *(undefined4 *)(param_1 + 100) = uVar3;
LAB_0061d8eb:
  FUN_004f1f10(*(undefined4 *)(param_1 + 100),param_2);
  return;
}

