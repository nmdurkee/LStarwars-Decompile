/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a1b10; label: FUN_005a1b10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_005a1b10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_c [12];
  
  if (param_1 != 0) {
    iVar1 = FUN_0055acd0(param_2,local_c,param_3,1,param_7,param_8,param_9);
    if (iVar1 != 0) {
      uVar2 = FUN_005a0810(param_1,local_c,param_4,param_5,param_6);
      return uVar2;
    }
  }
  return 0;
}

