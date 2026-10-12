/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5bf4f0; label: FUN_005bf4f0
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

