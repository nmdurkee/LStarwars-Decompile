/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c76d0; label: FUN_004c76d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c76d0(undefined4 *param_1,undefined4 param_2,float param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [48];
  undefined4 local_10;
  float local_c;
  undefined4 local_8;
  
  if (param_1 != (undefined4 *)0x0) {
    iVar1 = FUN_005cfac0(&DAT_0087c560);
    if (iVar1 != 0) {
      FUN_004c0d50();
      local_44 = param_2;
      local_48 = param_2;
      local_4c = param_2;
      FUN_005b45a0(extraout_ECX,&local_4c);
      local_10 = *param_1;
      local_8 = param_1[2];
      local_c = (float)param_1[1] + param_3;
      FUN_005f33b0(&DAT_0087c560,local_40);
    }
  }
  return;
}

