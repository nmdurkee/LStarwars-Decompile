/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55e340; label: FUN_0055e340
 */

undefined4 FUN_0055e340(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  piVar2 = &DAT_0093d7f0;
  local_8 = 0;
  local_4 = 0;
  local_10 = 0.0;
  do {
    iVar1 = *piVar2;
    if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0)) {
      FUN_005b37d0(&local_c,&local_c,iVar1 + 0x5c);
      local_10 = local_10 + 1.0;
    }
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0x93d7f8);
  if (0.0 < local_10) {
    FUN_005b3830(param_1,&local_c,1.0 / local_10);
    if (param_2 != 0) {
      FUN_00541bc0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),param_1,0xffffffff,0xffffffff,param_2)
      ;
    }
    return 1;
  }
  if (param_2 != 0) {
    *(undefined1 *)(param_2 + 1) = 0xff;
  }
  return 0;
}

