/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x408880; label: FUN_00408880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_00408880(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    piVar2 = &DAT_00854e38;
    iVar1 = 0;
    do {
      if ((*(byte *)((int)piVar2 + 0x1ea) & 1) == 0) {
        *(ushort *)((int)piVar2 + 0x1ea) = *(ushort *)((int)piVar2 + 0x1ea) | 1;
        bVar3 = param_1 == DAT_0093d810;
        *piVar2 = param_1;
        piVar2[1] = param_2;
        if ((bVar3) || (param_1 == DAT_0093d814)) {
          FUN_0054a3e0(PTR_DAT_008021b4,0x3f800000,0,1);
        }
        if (param_3 != 0) {
          FUN_00681f40("TowCable_Fire",param_1 + 0x80);
        }
        return piVar2;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x7b;
    } while (iVar1 < 8);
  }
  return (int *)0x0;
}

