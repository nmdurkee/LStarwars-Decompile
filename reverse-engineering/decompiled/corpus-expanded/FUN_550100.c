/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x550100; label: FUN_00550100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00550100(ushort param_1,ushort param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (param_2 != param_1) {
    iVar1 = FUN_006e6b90();
    uVar2 = (uint)param_1;
    iVar3 = param_2 - uVar2;
    if (iVar3 < 0x8001) {
      if (iVar3 < -0x8000) {
        iVar3 = iVar3 + 0x10000;
      }
    }
    else {
      iVar3 = iVar3 + -0x10000;
    }
    if (param_4 != (int *)0x0) {
      *param_4 = iVar3;
    }
    if (iVar3 < 1) {
      if (iVar3 < -iVar1) {
        return uVar2 - iVar1;
      }
    }
    else if (iVar1 < iVar3) {
      return uVar2 + iVar1;
    }
  }
  return (uint)param_2;
}

