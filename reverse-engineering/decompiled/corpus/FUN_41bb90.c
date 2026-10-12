/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41bb90; label: FUN_0041bb90
 */

void FUN_0041bb90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  iVar1 = 0;
  local_8 = 0;
  local_4 = 0x3e4ccccd;
  if (0 < DAT_0093d818) {
    do {
      local_18 = param_1;
      local_14 = param_2;
      local_10 = param_3;
      FUN_005b37d0(&local_18,&local_18,&local_c);
      FUN_0041b420((&DAT_0093d7f0)[iVar1],1,&local_18,1);
      FUN_005b3620(&local_c,&local_c,0x2000);
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_0093d818);
  }
  return;
}

