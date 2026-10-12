/* Ghidra pseudocode, not original source.
 * ev_ad94bec40fb329b942d4f858c664032de23cf17ab2243631134a23feb763d3d7
 * Entry: 0x55bdc0; label: FUN_0055bdc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055bdc0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 int param_5,int param_6)

{
  int iVar1;
  
  if (param_5 != 0) {
    iVar1 = FUN_0057e710();
    if (((iVar1 != 0) && (param_6 != -1)) && (param_6 * 0x9c + DAT_00951354 != DAT_00951364)) {
      param_5 = 0;
    }
  }
  FUN_0062d540(param_1,param_2,param_3,*param_4,param_5);
  return;
}

