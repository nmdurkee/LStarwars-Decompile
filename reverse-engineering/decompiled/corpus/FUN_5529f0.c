/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x5529f0; label: FUN_005529f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005529f0(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_44;
  _DAT_0092b0b8 = param_1;
  if (param_1 != (int *)0x0) {
    iVar2 = *param_1;
    while (iVar2 != 0) {
      DAT_00924878 = DAT_00924878 + 3 & 0xfffffffc;
      FUN_004f1f10(local_44,"stuff\\ats\\");
      FUN_004f1e80(local_44,*param_1);
      FUN_004f1e80(local_44,&DAT_0076173c);
      uVar1 = FUN_006e6b90();
      iVar2 = FUN_005d2840(local_44,&DAT_00924878,DAT_0092487c,uVar1);
      if (iVar2 == 0) {
        FUN_0054f970(local_44);
      }
      param_1 = param_1 + 1;
      iVar2 = *param_1;
    }
    DAT_00924878 = DAT_00924878 + 0xf & 0xfffffff0;
  }
  __security_check_cookie(local_4 ^ (uint)local_44);
  return;
}

