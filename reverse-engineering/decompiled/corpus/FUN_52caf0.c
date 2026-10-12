/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x52caf0; label: FUN_0052caf0
 */

undefined4 FUN_0052caf0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  if ((((param_1 != 0) && (unaff_ESI != 0)) && (*(int *)(unaff_ESI + 4) != 0)) &&
     (*(int *)(unaff_ESI + 100) < 4)) {
    for (iVar1 = FUN_004f1440(*(int *)(unaff_ESI + 4) + 0x40); iVar1 != 0;
        iVar1 = FUN_004f1460(*(int *)(unaff_ESI + 4) + 0x40,iVar1)) {
      *(undefined1 *)(unaff_ESI + 0x4c) = 1;
      *(undefined1 *)(unaff_ESI + 0x4d) = 1;
      iVar2 = FUN_004f1440(iVar1 + 0x1c);
      if (((iVar2 == 0) || (iVar2 = FUN_0052c880(param_1,iVar1 + 0x1c,param_2), iVar2 != 0)) &&
         (*(int *)(iVar1 + 0xc) != 0)) {
        *(undefined1 *)(unaff_ESI + 0x38) = 1;
        *(undefined1 *)(unaff_ESI + 0x39) = 1;
        iVar2 = FUN_0052c880(param_1,*(int *)(*(int *)(iVar1 + 0xc) + 0x38) + 8,param_2);
        if ((iVar2 != 0) && (*(int *)(iVar2 + 0x24) != *(int *)(*(int *)(iVar1 + 0xc) + 0x38)))
        goto LAB_0052cc52;
      }
    }
    if (*(int *)(unaff_ESI + 8) != 0) {
      iVar2 = *(int *)(unaff_ESI + 8) + 0x1c;
      for (iVar1 = FUN_004f1440(iVar2); iVar1 != 0; iVar1 = FUN_004f1460(iVar2,iVar1)) {
        *(undefined1 *)(unaff_ESI + 0x4c) = 1;
        *(undefined1 *)(unaff_ESI + 0x4d) = 1;
        iVar3 = FUN_004f1440(iVar1 + 0x1c);
        if (((iVar3 == 0) || (iVar3 = FUN_0052c880(param_1,iVar1 + 0x1c,param_2), iVar3 != 0)) &&
           (*(int *)(iVar1 + 0xc) != 0)) {
          *(undefined1 *)(unaff_ESI + 0x38) = 1;
          *(undefined1 *)(unaff_ESI + 0x39) = 1;
          iVar3 = FUN_0052c880(param_1,*(int *)(*(int *)(iVar1 + 0xc) + 0x38) + 8,param_2);
          if ((iVar3 != 0) && (*(int *)(iVar3 + 0x24) != *(int *)(*(int *)(iVar1 + 0xc) + 0x38))) {
LAB_0052cc52:
            *(int *)(unaff_ESI + 0x54 + *(int *)(unaff_ESI + 100) * 4) = iVar1;
            *(int *)(unaff_ESI + 100) = *(int *)(unaff_ESI + 100) + 1;
            FUN_00514640(param_1,param_2);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

