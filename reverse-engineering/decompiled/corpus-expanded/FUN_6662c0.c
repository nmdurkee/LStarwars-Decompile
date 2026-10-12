/* Ghidra pseudocode, not original source.
 * ev_1085323f9a3cb798a23dfec0c4468a06f744be49385e8c8d18d4e2ca61b2546b
 * Entry: 0x6662c0; label: FUN_006662c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006662c0(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 local_120 [16];
  undefined4 local_110 [68];
  
  if ((((DAT_02962b18 != 0) && (iVar2 = FUN_0061a8c0(DAT_02962b18,local_120,8), iVar2 - 2U < 7)) &&
      (DAT_029231a8 != -1)) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    iVar6 = 0;
    if (3 < iVar2) {
      iVar5 = (iVar2 - 4U >> 2) + 1;
      iVar6 = iVar5 * 4;
      puVar3 = local_110;
      puVar4 = (undefined4 *)(iVar1 + 0x354);
      do {
        puVar4[-1] = puVar3[-4];
        iVar5 = iVar5 + -1;
        *puVar4 = *puVar3;
        puVar4[1] = puVar3[5];
        puVar4[2] = puVar3[9];
        puVar4[3] = puVar3[0xe];
        puVar4[4] = puVar3[0x12];
        puVar4[5] = puVar3[0x17];
        puVar4[6] = puVar3[0x1b];
        puVar3 = puVar3 + 0x24;
        puVar4 = puVar4 + 8;
      } while (iVar5 != 0);
    }
    if (iVar6 < iVar2) {
      iVar2 = iVar2 - iVar6;
      puVar3 = local_110 + iVar6 * 9;
      puVar4 = (undefined4 *)(iVar1 + 0x354 + iVar6 * 8);
      do {
        puVar4[-1] = puVar3[-4];
        iVar2 = iVar2 + -1;
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 9;
        puVar4 = puVar4 + 2;
      } while (iVar2 != 0);
    }
  }
  return;
}

