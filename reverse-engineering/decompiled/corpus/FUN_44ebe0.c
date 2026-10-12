/* Ghidra analysis pseudocode, not original source.
 * ev_92d4a724e69b6a04034eabfeaec94ac3aa2e75ce908c67016b571f650bed7677
 * Entry: 0x44ebe0; label: FUN_0044ebe0
 */

undefined4 FUN_0044ebe0(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  
  iVar7 = 0;
  iVar6 = 0;
  bVar1 = false;
  bVar2 = false;
  bVar3 = false;
  if (((in_stack_00000018 != 0) && (in_stack_00000014 != 0)) && (0 < in_stack_00000014)) {
    do {
      iVar4 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar7 * 4),"name=");
      if (iVar4 == 0) {
        iVar4 = FUN_004f8b10(*(undefined4 *)(in_stack_00000010 + iVar7 * 4),"backwards");
        if (iVar4 == 0) {
          bVar1 = true;
        }
        else {
          iVar4 = FUN_004f8b10(*(undefined4 *)(in_stack_00000010 + iVar7 * 4),&DAT_00757e88);
          if (iVar4 == 0) {
            bVar2 = true;
          }
          else {
            iVar4 = FUN_004f8b10(*(undefined4 *)(in_stack_00000010 + iVar7 * 4),"Restart");
            if (iVar4 == 0) {
              bVar3 = true;
            }
          }
        }
      }
      else {
        piVar5 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00805ebc,
                                     iVar4 + 5);
        if (piVar5 != (int *)0x0) {
          iVar6 = *piVar5;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < in_stack_00000014);
    if (iVar6 != 0) {
      if (!bVar1) {
        if (!bVar2) {
          if (bVar3) {
            FUN_005a1230(*(undefined4 *)(iVar6 + 0x20));
          }
          FUN_005a1030(*(undefined4 *)(iVar6 + 0x20),0x3f800000,1);
          return 1;
        }
        FUN_005a11f0(*(undefined4 *)(iVar6 + 0x20));
        return 1;
      }
      if (!bVar2) {
        if (bVar3) {
          FUN_005a11f0(*(undefined4 *)(iVar6 + 0x20));
        }
        FUN_005a1030(*(undefined4 *)(iVar6 + 0x20),0xbf800000,1);
        return 1;
      }
      FUN_005a1230(*(undefined4 *)(iVar6 + 0x20));
    }
  }
  return 1;
}

