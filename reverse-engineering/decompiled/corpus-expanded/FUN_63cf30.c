/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63cf30; label: FUN_0063cf30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063cf30(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (DAT_0291396c != 0) {
    iVar3 = 0;
    iVar4 = 0;
    iVar1 = DAT_0291396c;
    do {
      if (iVar3 == *(int *)(iVar1 + 0x554)) {
        uVar5 = 0xf0f0f0f0;
        uVar2 = 0x30;
      }
      else {
        uVar5 = 0x60606060;
        uVar2 = 0x10;
      }
      if ((*(int *)(iVar4 + 0xd0 + iVar1) != 0) &&
         (FUN_00623e00(iVar4 + 0xd4 + iVar1,*(undefined4 *)(iVar4 + 0xec + iVar1),uVar5,uVar2,0),
         iVar1 = DAT_0291396c, 0.0 < *(float *)(iVar4 + 0xf0 + DAT_0291396c))) {
        FUN_00623e00(iVar4 + 0xd4 + DAT_0291396c,
                     *(float *)(iVar4 + 0xec + DAT_0291396c) +
                     *(float *)(iVar4 + 0xf0 + DAT_0291396c),uVar5,uVar2,0);
        iVar1 = DAT_0291396c;
      }
      iVar4 = iVar4 + 0x24;
      iVar3 = iVar3 + 1;
    } while (iVar4 < 0x480);
  }
  return;
}

