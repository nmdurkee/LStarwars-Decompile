/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54bb30; label: FUN_0054bb30
 */

void FUN_0054bb30(uint param_1,undefined4 param_2)

{
  uint uVar1;
  char *pcVar2;
  undefined1 auStack_44 [61];
  char local_7 [3];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_44;
  local_7[1] = (char)param_1 + (char)(param_1 / 10) * -10 + '0';
  pcVar2 = local_7 + 1;
  local_7[2] = 0;
  uVar1 = param_1 / 10;
  while (uVar1 != 0) {
    pcVar2 = pcVar2 + -1;
    *pcVar2 = (char)uVar1 + (char)(uVar1 / 10) * -10 + '0';
    uVar1 = uVar1 / 10;
  }
  FUN_0054ba80(pcVar2,param_2,local_7 + (2 - (int)pcVar2));
  __security_check_cookie(local_4 ^ (uint)auStack_44);
  return;
}

