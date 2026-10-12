/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x56a090; label: FUN_0056a090
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056a090(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,int param_7)

{
  int iVar1;
  undefined1 local_c [12];
  
  iVar1 = FUN_00567800(param_2,1,param_3,1,0,1);
  if (iVar1 == 0) {
    if (param_4 != 0) {
      FUN_005b3800(local_c,param_2 + 0x30,param_4 + 0x88);
      FUN_005b3b30(local_c,local_c);
      FUN_0057fc80(param_4,param_4 + 0xac,local_c,param_6);
    }
  }
  else if (param_1 != 0) {
    FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3ecccccd,0);
    FUN_00549f10();
  }
  if (*(int *)(PTR_PTR_008040bc + 8) != 0) {
    (**(code **)(PTR_PTR_008040bc + 8))(param_1,param_5);
  }
  if (param_7 == 1) {
    (**(code **)(PTR_PTR_008040bc + 0xc))(param_4,param_5,0xffffffff,0,0);
    if (*(int *)(param_4 + 4) != 0) {
      FUN_0054a850(**(undefined4 **)(*(int *)(param_4 + 4) + 0xca4),0x3f19999a,0);
    }
    FUN_00580120(param_4,1);
    FUN_0057fe80(param_4);
  }
  return;
}

