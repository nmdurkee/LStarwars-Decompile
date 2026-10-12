/* Ghidra analysis pseudocode, not original source.
 * ev_32b79db0f23450a9ff94a1f71da0489d6fe83df38c9fcaa5c40c5fee2e58dea2
 * Entry: 0x698710; label: FUN_00698710
 */

void FUN_00698710(undefined4 param_1,int param_2)

{
  if (DAT_02972bf0 != param_2) {
    if (DAT_02972bf4 != (void *)0x0) {
      FUN_00696a90();
    }
    DAT_02972bf4 = (void *)FUN_004eef40(param_2 * 2,".\\pc\\nusound.cpp",0x8c4);
    _memset(DAT_02972bf4,0,param_2 * 2);
    DAT_02972bf0 = param_2;
    DAT_02972be8 = param_1;
    return;
  }
  DAT_02972bf0 = param_2;
  DAT_02972be8 = param_1;
  return;
}

