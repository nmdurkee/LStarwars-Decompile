/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x527740; label: FUN_00527740
 */

void FUN_00527740(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c [2];
  undefined4 local_4;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0x3f800000;
  for (iVar1 = FUN_004f1440(DAT_009238e4 + 0x43814); iVar1 != 0;
      iVar1 = FUN_004f1460(DAT_009238e4 + 0x43814,iVar1)) {
    iVar2 = FUN_005cfac0(iVar1 + 0x20);
    if (iVar2 != 0) {
      uVar3 = FUN_005d0330(iVar1 + 0x20);
      FUN_005b30a0(iVar1 + 8,iVar1 + 0x2c,uVar3);
      FUN_005b3200(local_c,&local_18,uVar3);
      uVar3 = FUN_005be2d0(local_c[0],local_4);
      *(undefined4 *)(iVar1 + 0x3c) = uVar3;
      uVar3 = FUN_005be590(uVar3,*(undefined4 *)(iVar1 + 0x38));
      *(undefined4 *)(iVar1 + 0x3c) = uVar3;
    }
  }
  return;
}

