/* Ghidra analysis pseudocode, not original source.
 * ev_a85358c7a67f9df9af49bd13a9e5d6f2df9e1c4faca93f034535aa61df0d1386
 * Entry: 0x5f8d60; label: FUN_005f8d60
 */

void FUN_005f8d60(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_404;
  FUN_004f90c0(local_404,param_1,&PTR_PTR_0076a6e8,0x400);
  iVar2 = FUN_004fa5f0(local_404,0);
  if (iVar2 == 0) {
    __security_check_cookie(local_4 ^ (uint)local_404);
    return;
  }
  uVar3 = FUN_004f6b40(iVar2);
  uVar4 = FUN_004eef40(uVar3,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nutex_pc.cpp",0x2f);
  FUN_004fb550(iVar2,uVar4,uVar3);
  FUN_004f99e0(iVar2);
  puVar1 = (undefined4 *)*param_2;
  *param_2 = puVar1 + 10;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[9] = 0;
  puVar1[7] = uVar4;
  puVar1[8] = uVar3;
  FUN_005e5210(puVar1);
  FUN_004ef280(uVar4,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nutex_pc.cpp",0x4d);
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}

