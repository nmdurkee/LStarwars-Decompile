/* Ghidra pseudocode, not original source.
 * ev_e8754f098cec4467dd9989e7d0bc7b4ce6834c9196706effdc433d5dfb6256ff
 * Entry: 0x404f30; label: FUN_00404f30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00404f30(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 int param_5)

{
  int iVar1;
  
  iVar1 = (int)DAT_007f180c;
  *param_2 = 0xff;
  if (param_1 == iVar1) {
    *param_3 = 0;
    *param_4 = 0x1f;
    if (param_5 != 0) {
      FUN_004f1f10(param_5,&DAT_007517ac);
      return;
    }
  }
  else {
    *param_3 = 0xdf;
    *param_4 = 0;
    if (param_5 != 0) {
      FUN_004f1f10(param_5,&DAT_007517a8);
    }
  }
  return;
}

