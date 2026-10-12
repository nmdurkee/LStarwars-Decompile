/* Ghidra pseudocode, not original source.
 * ev_b2a783233b211c47b682189f4533ad6a7c38bd84c0deaf183226d349bdd9b928
 * Entry: 0x51fc60; label: FUN_0051fc60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0051fc60(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    if (param_3 == 0) {
      if (param_2 != 0) {
        for (param_3 = FUN_004f1440(param_1 + 0x10); param_3 != 0;
            param_3 = FUN_004f1460(param_1 + 0x10,param_3)) {
          iVar1 = FUN_004f8b80(param_2,param_3 + 8,0x20);
          if (iVar1 == 0) goto LAB_0051fcb9;
        }
      }
    }
    else {
LAB_0051fcb9:
      if (param_3 != 0) {
        return param_3;
      }
    }
    iVar1 = FUN_004f1440(param_1 + 8);
    if (iVar1 != 0) {
      FUN_004f1410(param_1 + 8,iVar1);
      FUN_004f1310(param_1 + 0x10,iVar1);
      FUN_004f1f40(iVar1 + 8,param_2,0x20);
    }
  }
  return iVar1;
}

