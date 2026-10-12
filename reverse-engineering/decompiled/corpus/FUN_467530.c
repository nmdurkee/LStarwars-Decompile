/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x467530; label: FUN_00467530
 */

void FUN_00467530(void)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  int unaff_ESI;
  float10 fVar4;
  
  if ((((*(byte *)(unaff_ESI + 0xa0) & 0x20) == 0) && (*(int *)(unaff_ESI + 0x40) != 0)) &&
     (bVar2 = *(byte *)(*(int *)(unaff_ESI + 0x40) + 0x26), bVar2 < 8)) {
    if (bVar2 != 0) {
      iVar3 = *(int *)(unaff_ESI + 0x40);
      fVar4 = (float10)FUN_00467490();
      *(float *)(iVar3 + 0x20) = (float)(fVar4 + (float10)*(float *)(iVar3 + 0x20));
    }
    *(int *)(*(int *)(unaff_ESI + 0x40) + (uint)*(byte *)(*(int *)(unaff_ESI + 0x40) + 0x26) * 4) =
         unaff_ESI;
    pcVar1 = (char *)(*(int *)(unaff_ESI + 0x40) + 0x26);
    *pcVar1 = *pcVar1 + '\x01';
    *(uint *)(unaff_ESI + 0xa0) = *(uint *)(unaff_ESI + 0xa0) | 0x20;
  }
  return;
}

