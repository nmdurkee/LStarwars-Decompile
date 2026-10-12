/* Ghidra pseudocode, not original source.
 * ev_9a3410a9c272a2064cc0564fa84db44ccced53000acc775659afcf5219797551
 * Entry: 0x4e5540; label: FUN_004e5540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e5540(void)

{
  int iVar1;
  float *pfVar2;
  
  if (DAT_0087a9e0 != (uint *)0x0) {
    iVar1 = FUN_005cfd60(&DAT_0087aaf0);
    if (((iVar1 != 0) && (pfVar2 = (float *)FUN_005cf9e0(&DAT_0087aaf0), pfVar2 != (float *)0x0)) &&
       (*pfVar2 < 77.25)) {
      *DAT_0087a9e0 = *DAT_0087a9e0 & 0x7fffffff;
      DAT_0087a9e0[1] = DAT_0087a9e0[1] & 0x7fffffff;
      if (DAT_0087aa5c == 0) {
        return;
      }
      *(undefined4 *)(DAT_0087aa5c + 0x28) = 0x3f800000;
      return;
    }
    *DAT_0087a9e0 = *DAT_0087a9e0 | 0x80000000;
    DAT_0087a9e0[1] = DAT_0087a9e0[1] | 0x80000000;
  }
  return;
}

