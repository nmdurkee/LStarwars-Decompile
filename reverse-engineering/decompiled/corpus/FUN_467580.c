/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x467580; label: FUN_00467580
 */

void FUN_00467580(void)

{
  char *pcVar1;
  float fVar2;
  byte bVar3;
  int iVar4;
  int unaff_ESI;
  float10 fVar5;
  
  if (((((*(byte *)(unaff_ESI + 0xa0) & 0x20) != 0) &&
       (iVar4 = *(int *)(unaff_ESI + 0x40), iVar4 != 0)) &&
      (bVar3 = *(byte *)(iVar4 + 0x26), bVar3 != 0)) &&
     (*(int *)(iVar4 + -4 + (uint)bVar3 * 4) == unaff_ESI)) {
    *(undefined4 *)(iVar4 + (uint)bVar3 * 4) = 0;
    pcVar1 = (char *)(*(int *)(unaff_ESI + 0x40) + 0x26);
    *pcVar1 = *pcVar1 + -1;
    if (*(char *)(*(int *)(unaff_ESI + 0x40) + 0x26) != '\0') {
      fVar2 = *(float *)(*(int *)(unaff_ESI + 0x40) + 0x20);
      fVar5 = (float10)FUN_00467490();
      *(float *)(*(int *)(unaff_ESI + 0x40) + 0x20) = (float)((float10)fVar2 - fVar5);
    }
    *(uint *)(unaff_ESI + 0xa0) = *(uint *)(unaff_ESI + 0xa0) & 0xffffffdf;
    FUN_005a1480(*(undefined4 *)(unaff_ESI + 0x28),&DAT_0093b0cc);
  }
  return;
}

