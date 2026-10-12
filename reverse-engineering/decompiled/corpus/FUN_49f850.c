/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x49f850; label: FUN_0049f850
 */

void FUN_0049f850(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18 [12];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  if (*(char *)(param_1 + 0xe43) == -1) {
    param_1 = -1;
  }
  else {
    param_1 = (int)*(short *)(&DAT_007fb0ec + *(char *)(param_1 + 0xe43) * 0x10);
  }
  if (*(short *)(iVar1 + 0x1064) == DAT_007f1968) {
    local_2c = 4;
  }
  else {
    local_2c = (*(short *)(iVar1 + 0x1064) == DAT_007f1880) + 1;
  }
  local_28 = 0;
  if (local_2c != 0) {
    do {
      if ((*(short *)(iVar1 + 0x1064) == DAT_007f1968) &&
         ((*(char *)(iVar1 + 0x280) == -1 ||
          ((iVar2 = FUN_0056e160(0x19), iVar2 == 0 &&
           ((*(char *)(iVar1 + 0x280) == -1 || (iVar2 = FUN_0041af30(iVar1), iVar2 == 0)))))))) {
        if ((local_28 == 0) || (local_28 == 3)) {
          iVar2 = 3;
        }
        else {
          iVar2 = 2;
        }
LAB_0049f92f:
        if ((*(char *)(iVar1 + 0x28c) != '\0') && ((*(uint *)(iVar1 + 0xe20) & 0x8000000) != 0)) {
          iVar3 = *(int *)(*(int *)(iVar1 + 0x54) + 0x24);
          iVar4 = (int)*(char *)(iVar3 + 0x100 + local_28 * 2);
          if ((iVar4 != -1) &&
             (((*(int *)(*(int *)(iVar1 + 0x50) + 0x14 + iVar4 * 4) != 0 &&
               (iVar3 = (int)*(char *)(iVar3 + 0x101 + local_28 * 2), iVar3 != -1)) &&
              (*(int *)(*(int *)(iVar1 + 0x50) + 0x14 + iVar3 * 4) != 0)))) {
            local_24 = *(undefined4 *)(iVar4 * 0x40 + 0x834 + iVar1);
            iVar4 = iVar4 * 0x40 + 0x834 + iVar1;
            local_20 = *(undefined4 *)(iVar4 + 4);
            local_1c = *(undefined4 *)(iVar4 + 8);
            puVar5 = (undefined4 *)(iVar3 * 0x40 + 0x834 + iVar1);
            local_c = *puVar5;
            local_8 = puVar5[1];
            local_4 = puVar5[2];
            FUN_005b37d0(local_18,&local_24,&local_c);
            FUN_005b3830(local_18,local_18,0x3f000000);
            puVar5 = &local_24;
            iVar3 = 3;
            do {
              FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),iVar2,puVar5);
              puVar5 = puVar5 + 3;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
        }
      }
      else {
        iVar2 = param_1;
        if (param_1 != -1) goto LAB_0049f92f;
      }
      local_28 = local_28 + 1;
    } while (local_28 < local_2c);
  }
  return;
}

