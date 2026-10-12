/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b7260; label: FUN_006b7260
 */

void FUN_006b7260(void)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float *unaff_ESI;
  int unaff_EDI;
  int local_4;
  
  iVar5 = 2;
  *unaff_ESI = *unaff_ESI * 0.5;
  local_4 = unaff_EDI;
  if (1 < unaff_EDI) {
    do {
      local_4 = local_4 + -1;
      iVar3 = unaff_EDI;
      if (3 < local_4) {
        iVar4 = ((unaff_EDI - iVar5) - 3U >> 2) + 1;
        iVar3 = unaff_EDI + iVar4 * -4;
        pfVar2 = unaff_ESI + unaff_EDI + -2;
        do {
          fVar1 = pfVar2[2];
          iVar4 = iVar4 + -1;
          *pfVar2 = *pfVar2 - fVar1;
          pfVar2[2] = fVar1 + fVar1;
          fVar1 = pfVar2[1];
          pfVar2[-1] = pfVar2[-1] - fVar1;
          pfVar2[1] = fVar1 + fVar1;
          fVar1 = *pfVar2;
          pfVar2[-2] = pfVar2[-2] - fVar1;
          *pfVar2 = fVar1 + fVar1;
          fVar1 = pfVar2[-1];
          pfVar2[-3] = pfVar2[-3] - fVar1;
          pfVar2[-1] = fVar1 + fVar1;
          pfVar2 = pfVar2 + -4;
        } while (iVar4 != 0);
      }
      for (; iVar5 <= iVar3; iVar3 = iVar3 + -1) {
        fVar1 = unaff_ESI[iVar3];
        unaff_ESI[iVar3 + -2] = unaff_ESI[iVar3 + -2] - fVar1;
        unaff_ESI[iVar3] = fVar1 + fVar1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= unaff_EDI);
  }
  return;
}

