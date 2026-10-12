/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43be20; label: FUN_0043be20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined * FUN_0043be20(byte param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (param_1 != 0xff) {
    if (param_1 < 10) {
      return (&PTR_s_batman_007fcfbc)[(uint)param_1 * 6];
    }
    iVar4 = 0;
    sVar1 = *DAT_00951374;
    while ((sVar1 != -1 && (iVar4 + iVar3 < 0x40))) {
      iVar2 = FUN_0043bc70();
      if (iVar2 == 0) {
        if (iVar4 + 10U == (uint)param_1) {
          return *(undefined **)
                  (DAT_00951374[(iVar4 + iVar3) * 2] * 0x4c + 0xc + *(int *)(DAT_029130e4 + 0x20));
        }
        iVar4 = iVar4 + 1;
      }
      else {
        iVar3 = iVar3 + 1;
      }
      sVar1 = DAT_00951374[(iVar4 + iVar3) * 2];
    }
  }
  return (undefined *)0x0;
}

