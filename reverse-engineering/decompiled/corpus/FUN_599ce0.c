/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x599ce0; label: FUN_00599ce0
 */

void FUN_00599ce0(int param_1,undefined4 param_2,int param_3,float param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_84;
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  iVar3 = 0;
  if (((DAT_00956048 != 0) && (iVar1 = *(int *)(DAT_00956048 + param_1 * 4), iVar1 != 0)) &&
     (local_84 = 0, *(char *)(iVar1 + 8) != '\0')) {
    do {
      iVar2 = FUN_005cfac0(*(int *)(iVar1 + 4) + iVar3);
      if (iVar2 != 0) {
        puVar4 = (undefined4 *)(*(int *)(iVar1 + 4) + 0xc + iVar3);
        puVar5 = local_80;
        for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        FUN_005b5430(local_80,local_80,param_2);
        FUN_005f33b0(*(int *)(iVar1 + 4) + iVar3,local_80);
        if (((param_3 != 0) && (param_4 != 2e+06)) &&
           (iVar2 = FUN_00550490(local_80,param_3,param_4,param_5,local_40), iVar2 != 0)) {
          FUN_005d4690(0);
          FUN_005f33b0(*(int *)(iVar1 + 4) + iVar3,local_40);
          FUN_005d46b0();
        }
      }
      local_84 = local_84 + 1;
      iVar3 = iVar3 + 0x68;
    } while (local_84 < (int)(uint)*(byte *)(iVar1 + 8));
  }
  return;
}

