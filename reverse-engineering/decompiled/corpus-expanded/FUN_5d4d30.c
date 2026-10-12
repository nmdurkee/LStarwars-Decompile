/* Ghidra pseudocode, not original source.
 * ev_e5677de9d32ba70c3e7679a2013183581fdac6be8f175158264fecd59db3931d
 * Entry: 0x5d4d30; label: FUN_005d4d30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d4d30(int param_1,float *param_2)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = FUN_005be2d0(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 4));
  *param_2 = (float)iVar1;
  iVar1 = FUN_006e6b90();
  FUN_005b35a0(&local_c,param_1,-iVar1);
  iVar1 = FUN_005be2d0(local_c,local_8);
  param_2[2] = -(float)iVar1;
  return;
}

