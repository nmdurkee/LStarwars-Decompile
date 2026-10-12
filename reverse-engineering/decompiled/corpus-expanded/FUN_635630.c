/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x635630; label: FUN_00635630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00635630(int param_1,uint param_2,int *param_3)

{
  if (((param_1 != 0) && (param_3 != (int *)0x0)) && (param_2 < 0x81)) {
    *param_3 = param_2 * 0x8c + 0x10 + param_1;
    return 1;
  }
  return 0;
}

