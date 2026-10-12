/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x564500; label: FUN_00564500
 */

void FUN_00564500(undefined4 param_1)

{
  int iVar1;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [56];
  undefined4 local_8;
  
  if (DAT_00950708 != 0) {
    iVar1 = FUN_005cfac0(&DAT_0095066c);
    if (iVar1 != 0) {
      local_4c = 0x3e000000;
      local_48 = 0x3e000000;
      local_44 = 0x3e000000;
      FUN_005b45a0(local_40,&local_4c);
      local_8 = 0x3f800000;
      FUN_005ff7a0(&DAT_0095066c,local_40,param_1);
    }
  }
  return;
}

