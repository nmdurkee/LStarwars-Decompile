/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bc3a0; label: FUN_005bc3a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005bc3a0(float *param_1,float param_2,float param_3)

{
  char cVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (((param_1 != (float *)0x0) && (cVar1 = *(char *)((int)param_1 + 1), cVar1 < '\b')) &&
     ('\x01' < cVar1)) {
    iVar4 = (int)cVar1;
    iVar3 = 0;
    iVar6 = 0;
    pfVar2 = param_1;
    if (0 < iVar4) {
      do {
        pfVar2 = pfVar2 + 1;
        if (*pfVar2 == param_2) {
          return 0;
        }
        iVar6 = iVar3;
      } while ((*pfVar2 <= param_2) &&
              (iVar3 = iVar3 + 1, iVar6 = 0, iVar3 < *(char *)((int)param_1 + 1)));
    }
    if (3 < (iVar4 - iVar6) + 1) {
      iVar5 = ((iVar4 - iVar6) - 3U >> 2) + 1;
      iVar3 = iVar4 + 8;
      iVar4 = iVar4 + iVar5 * -4;
      pfVar2 = param_1 + iVar3;
      do {
        iVar5 = iVar5 + -1;
        pfVar2[-7] = pfVar2[-8];
        pfVar2[1] = *pfVar2;
        pfVar2[-8] = pfVar2[-9];
        *pfVar2 = pfVar2[-1];
        pfVar2[-9] = pfVar2[-10];
        pfVar2[-1] = pfVar2[-2];
        pfVar2[-10] = pfVar2[-0xb];
        pfVar2[-2] = pfVar2[-3];
        pfVar2 = pfVar2 + -4;
      } while (iVar5 != 0);
    }
    if (iVar6 <= iVar4) {
      iVar3 = (iVar4 - iVar6) + 1;
      pfVar2 = param_1 + iVar4 + 8;
      do {
        iVar3 = iVar3 + -1;
        pfVar2[-7] = pfVar2[-8];
        pfVar2[1] = *pfVar2;
        pfVar2 = pfVar2 + -1;
      } while (iVar3 != 0);
    }
    *(char *)((int)param_1 + 1) = *(char *)((int)param_1 + 1) + '\x01';
    param_1[iVar6 + 1] = param_2;
    param_1[iVar6 + 9] = param_3;
    return 1;
  }
  return 0;
}

