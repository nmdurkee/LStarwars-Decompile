/* Ghidra analysis pseudocode, not original source.
 * ev_7cebcd231b4f420658515fe731eecd90e8f898d61da81d56368ea9915da5e025
 * Entry: 0x597dd0; label: FUN_00597dd0
 */

void FUN_00597dd0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined1 local_4c [12];
  undefined4 local_40 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if (((*(uint *)(param_1 + 0xe20) & 0x800000) != 0) ||
     (((DAT_00802878 != -1 && (*(char *)(param_1 + 0x7b5) == DAT_00802878)) &&
      ((((cVar1 = *(char *)(param_1 + 0x7b3), cVar1 == '\0' &&
         ((*(byte *)(param_1 + 0x7bc) & 0x40) != 0)) ||
        ((((cVar1 == '\x01' && ((*(byte *)(param_1 + 0x7bc) & 0x40) == 0)) || (cVar1 == '\x02')) ||
         ((cVar1 == '\x03' || (cVar1 == '\x06')))))) ||
       ((cVar1 == '\a' ||
        (((cVar1 == '\x04' && ((*(byte *)(param_1 + 0x7bc) & 0x40) == 0)) ||
         ((cVar1 == '\x05' && ((*(byte *)(param_1 + 0x7bc) & 0x40) == 0)))))))))))) {
    puVar5 = (undefined1 *)0x0;
    if (DAT_008051d0 == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x74c);
      uVar3 = *(undefined4 *)(param_1 + 0x750);
      puVar6 = &DAT_00806680;
      puVar7 = local_40;
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      local_40[0] = *(undefined4 *)(param_1 + 0x748);
      local_30 = *(undefined4 *)(param_1 + 0x754);
      local_2c = *(undefined4 *)(param_1 + 0x758);
      local_28 = *(undefined4 *)(param_1 + 0x75c);
      local_20 = *(undefined4 *)(param_1 + 0x760);
      local_1c = *(undefined4 *)(param_1 + 0x764);
      local_18 = *(undefined4 *)(param_1 + 0x768);
      local_40[1] = uVar2;
      local_40[2] = uVar3;
    }
    else {
      FUN_005b3620(local_4c,param_1 + 0x748,*(undefined2 *)(param_1 + 0x27a));
      puVar5 = local_4c;
      FUN_005b4670(local_40,*(undefined2 *)(param_1 + 0x7a6));
    }
    if (DAT_008051cc != 0) {
      FUN_005b4f70(local_40,*(undefined2 *)(param_1 + 0x27a));
      DAT_0093b0fc = 1;
    }
    iVar4 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
    FUN_00552e90(PTR_DAT_00802c54,param_1,0xffffffff,
                 *(int *)(*(int *)(param_1 + 0x798) + 0xa4) + 0x30,(int)*(char *)(iVar4 + 0x108),
                 (int)*(char *)(iVar4 + 0x109),param_1 + 0x804,*(undefined1 *)(param_1 + 0x107c),
                 *(undefined4 *)(param_1 + 0x1048),local_40,puVar5,0x3f800000,0x3f800000);
  }
  return;
}

