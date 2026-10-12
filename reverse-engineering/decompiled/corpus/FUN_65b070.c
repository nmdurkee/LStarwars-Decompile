/* Ghidra analysis pseudocode, not original source.
 * ev_72b4c015fc5ea067bd8ff7b23618dfd066d3174eed64a8765571f91528d681aa
 * Entry: 0x65b070; label: FUN_0065b070
 */

void FUN_0065b070(undefined4 param_1)

{
  undefined4 uVar1;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  uVar1 = FUN_00543990();
  _sprintf(local_24,"Slots Used = %02d",uVar1);
  FUN_00628d80(param_1,local_24,1);
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

