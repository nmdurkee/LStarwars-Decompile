/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x521920; label: FUN_00521920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00521920(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_009238e4;
  *(undefined4 *)(DAT_009238e4 + 0x383c0) = 0;
  *(undefined4 *)(iVar4 + 0x383c4) = 0;
  iVar4 = 0x371b8;
  do {
    FUN_004f1310(DAT_009238e4 + 0x383b8,iVar4 + DAT_009238e4);
    iVar4 = iVar4 + 0x48;
  } while (iVar4 < 0x383b8);
  if (*(int *)(DAT_009238e4 + 100) != 0) {
    iVar4 = *(int *)(DAT_009238e4 + 100);
    iVar2 = 0;
    if (0 < *(int *)(iVar4 + 0x34)) {
      iVar3 = 0;
      do {
        iVar4 = *(int *)(iVar4 + 0x38);
        iVar1 = FUN_00520e10(iVar4 + iVar3 + 0x1c,(int)*(short *)(iVar4 + 0x28 + iVar3),
                             (int)*(char *)(iVar4 + 0x2b + iVar3));
        FUN_004f1f40(iVar1 + 8,iVar4 + iVar3,0x10);
        iVar4 = *(int *)(DAT_009238e4 + 100);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x40;
      } while (iVar2 < *(int *)(iVar4 + 0x34));
    }
  }
  return;
}

