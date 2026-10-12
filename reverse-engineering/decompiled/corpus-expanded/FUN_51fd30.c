/* Ghidra pseudocode, not original source.
 * ev_b2a783233b211c47b682189f4533ad6a7c38bd84c0deaf183226d349bdd9b928
 * Entry: 0x51fd30; label: FUN_0051fd30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0051fd30(int param_1,int param_2,void *param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    return;
  }
  if (param_3 == (void *)0x0) {
    if (param_2 == 0) {
      return;
    }
    param_3 = (void *)FUN_004f1440(param_1 + 0x10);
    if (param_3 == (void *)0x0) {
      return;
    }
    while (iVar1 = FUN_004f8b80(param_2,(int)param_3 + 8,0x20), iVar1 != 0) {
      param_3 = (void *)FUN_004f1460(param_1 + 0x10,param_3);
      if (param_3 == (void *)0x0) {
        return;
      }
    }
    if (param_3 == (void *)0x0) {
      return;
    }
  }
  FUN_004f1410(param_1 + 0x10,param_3);
  _memset(param_3,0,0x2c);
  FUN_004f1310(param_1 + 8,param_3);
  return;
}

