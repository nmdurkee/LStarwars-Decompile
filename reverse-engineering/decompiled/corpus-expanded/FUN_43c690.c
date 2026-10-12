/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43c690; label: FUN_0043c690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0043c690(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((((param_2 != (int *)0x0) && (param_1 != (int *)0x0)) && (iVar1 = *param_1, iVar1 != 0)) &&
     ((*(char *)((int)param_1 + 0x28b) == '\0' && (*(char *)(iVar1 + 0x7b5) != '+')))) {
    if (*(int *)(iVar1 + 0xcd0) != 0) {
      FUN_0055d720(iVar1,param_2,0,0,0);
      return 1;
    }
    if ((*(uint *)(param_1[0x15] + 4) & 0x200000) == 0) {
      FUN_00561e20(iVar1,param_2,0,0x3f000000,0x3f800000,0);
      return 1;
    }
    param_1[0x23] = *param_2;
    param_1[0x24] = param_2[1];
    param_1[0x25] = param_2[2];
    param_1[0x17] = *param_2;
    param_1[0x18] = param_2[1];
    param_1[0x19] = param_2[2];
    param_1[0x1a] = DAT_0093b0cc;
    param_1[0x1b] = DAT_0093b0d0;
    param_1[0x1c] = DAT_0093b0d4;
    FUN_0041af70(iVar1);
    param_1[0x76] = 0;
  }
  return 1;
}

