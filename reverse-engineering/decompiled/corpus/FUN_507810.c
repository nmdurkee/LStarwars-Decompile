/* Ghidra analysis pseudocode, not original source.
 * ev_198b3c40c86fc47a34e355c4a7b923cf37494fadf6a0e41ec42e09959f8ec2d3
 * Entry: 0x507810; label: FUN_00507810
 */

void FUN_00507810(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  undefined4 extraout_EDX;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  if (param_4 != 0) {
    FUN_004fff10(*param_2);
    *(byte *)(param_3 + 3) = *(byte *)(param_3 + 3) | 1;
    FUN_00507750(*(undefined4 *)(param_1 + 0x14),*param_2,*(undefined4 *)(param_1 + 0x10),param_1);
    __security_check_cookie(local_4 ^ (uint)local_24);
    return;
  }
  _sprintf(local_24,"reset_%s",*param_2);
  FUN_004fff10(*param_2,local_24);
  *(byte *)(param_3 + 3) = *(byte *)(param_3 + 3) & 0xfe;
  FUN_00507750(*(undefined4 *)(param_1 + 0x14),extraout_EDX,*(undefined4 *)(param_1 + 0x10),param_1)
  ;
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

