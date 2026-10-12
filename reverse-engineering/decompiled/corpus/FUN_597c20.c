/* Ghidra analysis pseudocode, not original source.
 * ev_7cebcd231b4f420658515fe731eecd90e8f898d61da81d56368ea9915da5e025
 * Entry: 0x597c20; label: FUN_00597c20
 */

undefined4 FUN_00597c20(undefined4 *param_1,undefined4 param_2,undefined2 param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar2 = param_2;
  puVar1 = param_1;
  param_1[0x25] = param_1[0x25] | 0x804000;
  FUN_00566c20(param_1);
  puVar1[0x25] = puVar1[0x25] | 0x10000;
  iVar3 = FUN_005afbb0(*(undefined4 *)(PTR_DAT_00802c54 + 0x516c),uVar2,&param_1,1);
  if ((iVar3 != 0) && ((float)param_1 < 0.5625)) {
    FUN_005afc50(iVar3,puVar1);
    *(byte *)(iVar3 + 0x23) = *(byte *)(iVar3 + 0x23) | 4;
    puVar1[0x25] = puVar1[0x25] & 0xff7fffff | 0x10000000;
    return 1;
  }
  if (param_4 == 0) {
    if (DAT_008051d0 != 0) {
      FUN_005b4670(puVar1,param_3);
      FUN_005b4900(puVar1,uVar2);
      return 0;
    }
    puVar4 = &DAT_00806680;
    puVar5 = puVar1;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    FUN_005b4900(puVar1,uVar2);
  }
  return 0;
}

