/* Ghidra analysis pseudocode, not original source.
 * ev_01db8885f86fbb74a531da5bb10d328a9b146c5a63264b26651b6a27e7cc1924
 * Entry: 0x7449f0; label: FUN_007449f0
 */

void FUN_007449f0(uint *param_1,undefined1 param_2)

{
  short sVar1;
  uint uVar2;
  undefined1 local_6c [4];
  undefined1 local_68;
  undefined1 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 local_58;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_6c;
  _memset(local_6c,0,0x68);
  local_68 = param_2;
  local_64 = param_2;
  local_60 = DAT_00854260;
  local_5c = DAT_00854264;
  local_58 = 1;
  sVar1 = FUN_007462f0(local_6c,0x68);
  *param_1 = (int)sVar1 << 0x10;
  uVar2 = FUN_007462b0(local_6c,0x68);
  *param_1 = *param_1 | uVar2 & 0xffff;
  __security_check_cookie(local_4 ^ (uint)local_6c);
  return;
}

