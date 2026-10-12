/* Ghidra pseudocode, not original source.
 * ev_e37270f00559fec6395d344dad7372e88dd7c59f9ebe0b46a7132c9ac87d1215
 * Entry: 0x641980; label: FUN_00641980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00641980(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_02913818 == 0) {
    iVar3 = 0;
    iVar2 = 0;
    iVar1 = DAT_0291389c;
    do {
      if ((*(int *)(&DAT_0291350c + (uint)*(byte *)(iVar2 + 0x5c + iVar1) * 4) == 0) &&
         (*(char *)(iVar2 + 0x7e + iVar1) == -1)) {
        FUN_0063ca10(iVar3,0);
        iVar1 = DAT_0291389c;
      }
      iVar2 = iVar2 + 0x8c;
      iVar3 = iVar3 + 1;
    } while (iVar2 < 0x4600);
  }
  else {
    iVar1 = (int)*(char *)(DAT_02913818 + 0x79);
    if (iVar1 != -1) {
      do {
        FUN_0063ca10(iVar1,0);
        iVar1 = (int)*(char *)(iVar1 * 0x8c + 0x7d + DAT_0291389c);
      } while (iVar1 != -1);
      return;
    }
  }
  return;
}

