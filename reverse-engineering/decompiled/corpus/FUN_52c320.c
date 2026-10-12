/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x52c320; label: FUN_0052c320
 */

int FUN_0052c320(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  local_4 = 0;
  FUN_0052bcb0(&local_4);
  iVar1 = local_4;
  DAT_0092223c = 0;
  DAT_00922240 = 0;
  if (local_4 == 0) {
    return 0;
  }
  iVar2 = FUN_004f1440(local_4 + 0x10);
  if (iVar2 != 0) {
    do {
      for (iVar3 = FUN_004f1440(iVar2 + 8); iVar3 != 0; iVar3 = FUN_004f1460(iVar2 + 8,iVar3)) {
        iVar4 = FUN_00512fc0(*(undefined4 *)(iVar3 + 0x20),iVar1);
        *(int *)(iVar3 + 0x24) = iVar4;
        if ((*(int *)(iVar3 + 0x20) != 0) && (iVar4 == 0)) {
          if (DAT_00922248 == 1) {
            FUN_00512860();
          }
          else {
            FUN_00512850(*(int *)(iVar3 + 0x20),*(undefined4 *)(iVar1 + 8),
                         *(undefined4 *)(iVar2 + 0x18));
          }
        }
      }
      iVar3 = iVar1 + 0x10;
      for (iVar4 = FUN_004f1460(iVar3,iVar2); iVar4 != 0; iVar4 = FUN_004f1460(iVar3,iVar4)) {
        iVar5 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar4 + 0x18));
        if (iVar5 == 0) {
          if (DAT_00922248 == 1) {
            FUN_00512860(*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar1 + 8));
          }
          else {
            FUN_00512850(*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar1 + 8));
          }
        }
      }
      iVar2 = FUN_004f1460(iVar3,iVar2);
    } while (iVar2 != 0);
    return iVar1;
  }
  return iVar1;
}

