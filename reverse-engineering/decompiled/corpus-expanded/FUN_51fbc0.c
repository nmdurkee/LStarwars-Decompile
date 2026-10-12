/* Ghidra pseudocode, not original source.
 * ev_b2a783233b211c47b682189f4533ad6a7c38bd84c0deaf183226d349bdd9b928
 * Entry: 0x51fbc0; label: FUN_0051fbc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0051fbc0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    _memset((void *)param_1[1],0,*param_1 * 0x2c);
    iVar2 = 0;
    if (0 < *param_1) {
      iVar1 = 0;
      do {
        FUN_004f1310(param_1 + 2,param_1[1] + iVar1);
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x2c;
      } while (iVar2 < *param_1);
    }
  }
  return;
}

