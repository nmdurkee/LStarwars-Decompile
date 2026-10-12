/* Ghidra analysis pseudocode, not original source.
 * ev_b2ae0094aac4233f18363a226dc902c019a1728ce7ff5cc7e95ded3ed7c5c2a8
 * Entry: 0x68eb60; label: FUN_0068eb60
 */

void FUN_0068eb60(int param_1)

{
  undefined4 uVar1;
  char *_Format;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  char local_64 [32];
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_74;
  local_74 = 0x80000000;
  local_70 = 0x80ff0000;
  local_6c = 0x80808080;
  local_68 = 0x80404040;
  if (DAT_00810ad8 == -1) goto LAB_0068ecff;
  uVar1 = *(undefined4 *)(DAT_0296209c + DAT_00810ad8 * 4);
  DAT_02948ee0 = FUN_00619250(0x46,0x46,300,0xfa,DAT_02912e80,&LAB_0066ab30,"Clipboard Menu");
  if (DAT_02948ee0 == 0) goto LAB_0068ecff;
  if (DAT_0292118b == '\0') {
    _Format = "General List";
LAB_0068ec12:
    _sprintf(local_64,_Format);
  }
  else {
    if (DAT_0292118b == '\x01') {
      _Format = "Level List";
      goto LAB_0068ec12;
    }
    if (DAT_0292118b == '\x05') {
      _Format = "Char List";
      goto LAB_0068ec12;
    }
  }
  if (DAT_00810aec == -1) {
    _sprintf(local_44,"Cut %s from %s",uVar1,local_64);
    uVar1 = FUN_00627a80(1,&local_74,0,0,&LAB_006628d0,local_44);
    FUN_00618e10(DAT_02948ee0,uVar1);
  }
  else {
    _sprintf(local_44,"Paste %s into %s",*(undefined4 *)(DAT_0296209c + DAT_00810aec * 4),local_64);
    uVar1 = FUN_00627a80(1,&local_74,0,0,&LAB_00662880,local_44);
    FUN_00618e10(DAT_02948ee0,uVar1);
    uVar1 = FUN_00627a80(1,&local_74,0,0,&LAB_0068cf70,"Empty Clipboard");
    FUN_00618e10(DAT_02948ee0,uVar1);
  }
  FUN_006279b0(param_1,DAT_02948ee0);
  *(int *)(DAT_02948ee0 + 0x14) = *(int *)(param_1 + 0x14) + 10;
  *(int *)(DAT_02948ee0 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
LAB_0068ecff:
  __security_check_cookie(local_4 ^ (uint)&local_74);
  return;
}

