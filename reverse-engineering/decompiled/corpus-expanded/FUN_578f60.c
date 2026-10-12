/* Ghidra pseudocode, not original source.
 * ev_70aa57168a76f6a14ecedad416987a4c285e0af1098fb5505be14bfd88103624
 * Entry: 0x578f60; label: FUN_00578f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00578f60(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004fc900("levelbeforeload",param_2,0xffff);
  if (iVar1 != 0) {
    DAT_00951b74 = param_1;
    FUN_004f1160(iVar1,&PTR_s_mipmapmode_00803bb8,param_3);
    iVar2 = FUN_004fc5b0(iVar1);
    while (iVar2 != 0) {
      iVar2 = FUN_004f7fb0(iVar1);
      if (iVar2 != 0) {
        FUN_004fa020(iVar1);
      }
      iVar2 = FUN_004fc5b0(iVar1);
    }
    FUN_004fa300(iVar1);
  }
  return;
}

