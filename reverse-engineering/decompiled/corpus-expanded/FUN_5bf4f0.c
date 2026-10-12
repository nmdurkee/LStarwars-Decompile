/* Ghidra pseudocode, not original source.
 * ev_36c2cdffab22dec35ae5154a8d67af88b00f5702395280041def6b77535d68b9
 * Entry: 0x5bf4f0; label: FUN_005bf4f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bf4f0(undefined4 *param_1,undefined4 *param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8 [4];
  undefined4 local_4;
  
  iVar1 = FUN_005be2d0(param_1[1],*param_1);
  *param_5 = iVar1;
  FUN_005b6ee0(-iVar1,*param_1,param_1[1],&local_c,local_8);
  local_4 = param_1[2];
  FUN_005b6ee0(-iVar1,*param_2,param_2[1],&local_18,&local_14);
  local_10 = param_2[2];
  iVar1 = FUN_005be2d0(local_4,local_c);
  *param_4 = -iVar1;
  FUN_005b6ee0(-iVar1,local_18,local_10,&local_18,&local_10);
  iVar1 = FUN_005be2d0(local_14,local_10);
  *param_3 = -iVar1;
  return;
}

