/* Ghidra pseudocode, not original source.
 * ev_d64f82d79bd9036ef98f897f1d4209ad19800693bd01752bbb2d417690313147
 * Entry: 0x698710; label: FUN_00698710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

