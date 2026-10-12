/* Ghidra pseudocode, not original source.
 * ev_d2141175d7fdb31f80696454dffb563fb6f914ee7c013e44c78745164b884694
 * Entry: 0x625240; label: FUN_00625240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00625240(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                int param_5,int param_6,int param_7,undefined4 param_8)

{
  int iVar1;
  
  iVar1 = FUN_00625150(param_1,param_2,param_3,param_4,(float)param_5,(float)param_6,(float)param_7,
                       param_8);
  if (iVar1 != 0) {
    FUN_0061d880(iVar1,&DAT_0076af68);
    *(undefined4 *)(iVar1 + 0x68) = 0x3f800000;
    *(code **)(iVar1 + 0x40) = FUN_0061dfd0;
  }
  return iVar1;
}

