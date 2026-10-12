/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x554d70; label: FUN_00554d70
 */

void FUN_00554d70(int param_1)

{
  int iVar1;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  FUN_0054a8d0(**(undefined4 **)(param_1 + 0xca4),1,0);
  local_c = *(undefined4 *)(*(int *)(param_1 + 0x798) + 0x5c);
  iVar1 = FUN_0054fa60();
  local_8 = (float)iVar1 * 1.5259022e-05 * 0.25 + 0.15 +
            *(float *)(*(int *)(param_1 + 0x798) + 0x60);
  local_4 = *(undefined4 *)(*(int *)(param_1 + 0x798) + 100);
  FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),(int)DAT_008025be,&local_c);
  FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),(int)DAT_008025c0,&local_c);
  FUN_00547930(0x39,&local_c,0,0);
  return;
}

