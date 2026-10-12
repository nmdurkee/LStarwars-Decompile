/* Ghidra pseudocode, not original source.
 * ev_1f7273160d1fc2c17e24c11295545580a626ef47c094abd3f1416147cfc2162d
 * Entry: 0x4f8d10; label: FUN_004f8d10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f8d10(short *param_1,undefined4 param_2)

{
  short sVar1;
  char local_204 [256];
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_204;
  FUN_004f2dc0(local_204,param_2);
  _vsprintf(local_104,local_204,&stack0x0000000c);
  FUN_004f2ee0(param_1,local_104);
  sVar1 = *param_1;
  while (sVar1 != 0) {
    param_1 = param_1 + 1;
    sVar1 = *param_1;
  }
  __security_check_cookie(local_4 ^ (uint)local_204);
  return;
}

