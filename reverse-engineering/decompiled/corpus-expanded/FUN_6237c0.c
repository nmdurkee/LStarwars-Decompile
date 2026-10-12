/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x6237c0; label: FUN_006237c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006237c0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  if (param_1 != 0) {
    FUN_004f1f10(s_Title_0080f888,param_1);
  }
  if (param_2 != 0) {
    FUN_004f1f10(&DAT_02912f50,param_2);
  }
  if (param_3 == 0) {
    s___nup_____hgp_0080f8c8[0] = '\0';
  }
  else {
    FUN_004f1f10(s___nup_____hgp_0080f8c8,param_3);
  }
  if (param_4 == 0) {
    s__PC_____360_____PS3__0080f9c8[0] = '\0';
  }
  else {
    FUN_004f1f10(s__PC_____360_____PS3__0080f9c8,param_4);
  }
  DAT_02912f4d = 1;
  DAT_0291305c = param_5;
  DAT_02912f4e = 2;
  return;
}

