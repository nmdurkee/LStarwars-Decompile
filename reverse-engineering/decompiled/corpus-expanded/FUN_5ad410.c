/* Ghidra pseudocode, not original source.
 * ev_61672b8aee088191725705707427e6d28989067365c008b5a0fbb4fab739a1ee
 * Entry: 0x5ad410; label: FUN_005ad410
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005ad410(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
    iVar3 = *param_1;
    iVar2 = 0;
    if ((short)param_1[2] != 0) {
      do {
        iVar1 = FUN_004f8b10(iVar3 + 8,param_2);
        if (iVar1 == 0) {
          return iVar3;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x13c;
      } while (iVar2 < (int)(uint)*(ushort *)(param_1 + 2));
    }
  }
  return iVar3;
}

