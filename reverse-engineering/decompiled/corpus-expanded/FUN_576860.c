/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x576860; label: FUN_00576860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00576860(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if ((DAT_009514b8 == 0) || (DAT_009514b8 != param_1)) {
    if (param_1 == 0) {
      DAT_009514b8 = 0;
      return;
    }
    if ((param_2 != 0) ||
       (((*(char *)(param_1 + 0x14) == '\0' || (param_3 != 0)) &&
        (*(float *)(param_1 + 0x18) <= 0.0)))) {
      _DAT_009514c8 = 0;
      _DAT_009514cc = 0;
      DAT_009514b8 = param_1;
      if ((param_2 == 0) && ((*(byte *)(param_1 + 2) & 1) != 0)) {
        *(undefined1 *)(param_1 + 0x14) = 1;
        FUN_005766e0(param_1);
      }
      do {
        iVar1 = FUN_0054fa60();
        uVar2 = (int)(iVar1 + (iVar1 >> 0x1f & 0x3fffU)) >> 0xe;
      } while (uVar2 == DAT_009514bd);
      DAT_009514bd = (byte)uVar2;
      _DAT_009514cc = 0;
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0xc);
      return;
    }
  }
  return;
}

