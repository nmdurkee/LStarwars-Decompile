/* Ghidra pseudocode, not original source.
 * ev_1f7273160d1fc2c17e24c11295545580a626ef47c094abd3f1416147cfc2162d
 * Entry: 0x4f83d0; label: FUN_004f83d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f83d0(int param_1,int param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = ~param_3;
  uVar1 = *param_4 + param_3 & uVar2;
  *param_4 = uVar1;
  FUN_004f1500(param_1,param_2,param_3,uVar1);
  *param_4 = *param_4 + (param_1 + param_3 & uVar2) * param_2 + (param_3 + 0x10 & uVar2);
  return;
}

