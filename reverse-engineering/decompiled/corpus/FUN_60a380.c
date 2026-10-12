/* Ghidra analysis pseudocode, not original source.
 * ev_2e9599a270e7c228276daed06211bb9a628229b53b154c3c2f5580fc0ff0e4f1
 * Entry: 0x60a380; label: FUN_0060a380
 */

int FUN_0060a380(int param_1,int param_2,int param_3)

{
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0074fb60;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  local_8 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 8) {
    FUN_0060a240(param_3,param_1);
    param_3 = param_3 + 8;
  }
  *unaff_FS_OFFSET = local_10;
  return param_3;
}

