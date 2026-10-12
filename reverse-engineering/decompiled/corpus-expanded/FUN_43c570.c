/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43c570; label: FUN_0043c570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0043c570(int *param_1)

{
  int iVar1;
  
  if ((((*(char *)((int)param_1 + 0x28b) == '\0') && ((*(byte *)(param_1[1] + 0x166) & 1) == 0)) &&
      ((param_1[0x7f] & 0x2000U) != 0)) &&
     ((((*(uint *)(param_1[0x15] + 4) & 0x400000) == 0 &&
       (iVar1 = *param_1, *(char *)(iVar1 + 0x7b5) != '+')) &&
      ((*(int *)(iVar1 + 0xcd0) == 0 && (2.0 < (float)param_1[0x76])))))) {
    if ((*(uint *)(param_1[0x15] + 4) & 0x200000) == 0) {
      FUN_00561e20(iVar1,param_1 + 0x73,0,0x3f000000,0x3f800000,0);
      return 0;
    }
    param_1[0x23] = param_1[0x73];
    param_1[0x24] = param_1[0x74];
    param_1[0x17] = param_1[0x73];
    param_1[0x25] = param_1[0x75];
    param_1[0x18] = param_1[0x74];
    param_1[0x19] = param_1[0x75];
    param_1[0x1a] = DAT_0093b0cc;
    param_1[0x1b] = DAT_0093b0d0;
    param_1[0x1c] = DAT_0093b0d4;
    FUN_0041af70(iVar1);
    param_1[0x76] = 0;
  }
  return 0;
}

