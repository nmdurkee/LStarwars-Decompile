/* Ghidra pseudocode, not original source.
 * ev_4e08cb6b9a05324ae7a2b7ff12e5cd4300e2bf96324e358c1c445da0c9e3f38b
 * Entry: 0x630680; label: FUN_00630680
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00630680(short *param_1,int param_2,int *param_3)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  
  if (param_1 != (short *)0x0) {
    iVar3 = 0;
    sVar2 = *param_1;
    while (sVar2 != -1) {
      if (sVar2 == param_2) {
        if (param_3 != (int *)0x0) {
          *param_3 = iVar3;
        }
        return 1;
      }
      psVar1 = param_1 + 2;
      param_1 = param_1 + 2;
      iVar3 = iVar3 + 1;
      sVar2 = *psVar1;
    }
  }
  if (param_3 != (int *)0x0) {
    *param_3 = -1;
  }
  return 0;
}

