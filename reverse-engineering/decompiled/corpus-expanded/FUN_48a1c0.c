/* Ghidra pseudocode, not original source.
 * ev_2b5797dc97ed4bbab0de865ef61fef56a3505bfdb1fb7c8af1c17efd4ff63982
 * Entry: 0x48a1c0; label: FUN_0048a1c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048a1c0(int param_1,int param_2)

{
  int iVar1;
  
  if (-1 < param_1) {
    iVar1 = param_1 * 0x2e28;
    _memset((void *)(iVar1 + DAT_0087b2cc),0,0x2e28);
    *(undefined4 *)(iVar1 + 0x2820 + DAT_0087b2cc) = 0;
    *(undefined4 *)(iVar1 + 0x2814 + DAT_0087b2cc) = 0x49f42400;
    if (param_2 != 0) {
      _memcpy((void *)(iVar1 + DAT_0087b2cc),(void *)(param_2 + 0x15c),0x2800);
    }
  }
  FUN_00559af0(0,param_1);
  FUN_005a0570(param_1);
  return;
}

