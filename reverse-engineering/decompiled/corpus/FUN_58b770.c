/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58b770; label: FUN_0058b770
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058b770(int param_1)

{
  int iVar1;
  
  if (((('\0' < *(char *)(param_1 + 0x107f)) &&
       ((int)*(char *)(param_1 + 0x107f) < (int)(uint)*(byte *)(param_1 + 0x107e))) &&
      (*(float *)(param_1 + 0x1018) <= 0.0)) &&
     ((*(float *)(param_1 + 0x1000) <= 0.0 &&
      (iVar1 = FUN_0062c350(0x3f800000,_DAT_00925018), 0 < iVar1)))) {
    *(char *)(param_1 + 0x107f) = *(char *)(param_1 + 0x107f) + '\x01';
    FUN_00547930(0x27,param_1 + 0x80,0,0);
    return;
  }
  return;
}

