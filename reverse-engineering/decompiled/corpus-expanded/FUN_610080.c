/* Ghidra pseudocode, not original source.
 * ev_cd751bbce80615e44627de7d2a98b099122eeed2e472d985b2852ac0d20d1b25
 * Entry: 0x610080; label: FUN_00610080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00610080(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (0 < param_3) {
    param_2 = param_2 - (int)param_1;
    do {
      uVar1 = FUN_004f3730(*param_1,*(undefined4 *)(param_2 + (int)param_1),param_4);
      uVar2 = uVar2 | uVar1;
      param_1 = param_1 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return uVar2;
}

