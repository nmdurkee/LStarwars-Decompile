/* Ghidra pseudocode, not original source.
 * ev_1085323f9a3cb798a23dfec0c4468a06f744be49385e8c8d18d4e2ca61b2546b
 * Entry: 0x6655f0; label: FUN_006655f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006655f0(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  DAT_02962a60 = 0;
  uVar2 = *(uint *)(param_2 + 0xc) >> 0x10;
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    *(uint *)(*(int *)(DAT_0296209c +
                      *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4
                                ) * 4) + (uVar2 * 3 + 0xf9) * 4) =
         *(uint *)(param_2 + 0xc) + uVar2 * -0x10000;
  }
  piVar3 = &DAT_02924b60;
  iVar4 = DAT_029620a4;
  do {
    iVar1 = *piVar3;
    if ((iVar1 != -1) && (iVar1 != 99999)) {
      *(undefined2 *)(iVar1 * 0x330 + 0x2e8 + iVar4) = 9999;
      iVar4 = *(int *)(*(int *)(DAT_0296209c +
                               *(short *)(*piVar3 * 0x330 + 0x182 + DAT_029620a4) * 4) + 0x3e4);
      if ((iVar4 == 4) || (iVar4 == 3)) {
        *(undefined2 *)(*piVar3 * 0x330 + 0x2e8 + DAT_029620a4) = 1;
      }
      *(undefined2 *)(*piVar3 * 0x330 + 0x2ea + DAT_029620a4) = 9999;
      iVar4 = *(int *)(*(int *)(DAT_0296209c +
                               *(short *)(*piVar3 * 0x330 + 0x182 + DAT_029620a4) * 4) + 0x3f0);
      if ((iVar4 == 4) || (iVar4 == 3)) {
        *(undefined2 *)(*piVar3 * 0x330 + 0x2ea + DAT_029620a4) = 1;
      }
      *(undefined2 *)(*piVar3 * 0x330 + 0x2ec + DAT_029620a4) = 9999;
      iVar4 = *(int *)(*(int *)(DAT_0296209c +
                               *(short *)(*piVar3 * 0x330 + 0x182 + DAT_029620a4) * 4) + 0x3fc);
      if ((iVar4 == 4) || (iVar4 == 3)) {
        *(undefined2 *)(*piVar3 * 0x330 + 0x2ec + DAT_029620a4) = 1;
      }
      *(undefined2 *)(*piVar3 * 0x330 + 0x2ee + DAT_029620a4) = 9999;
      iVar1 = *(int *)(*(int *)(DAT_0296209c +
                               *(short *)(*piVar3 * 0x330 + 0x182 + DAT_029620a4) * 4) + 0x408);
      if ((iVar1 == 4) || (iVar4 = DAT_029620a4, iVar1 == 3)) {
        *(undefined2 *)(*piVar3 * 0x330 + 0x2ee + DAT_029620a4) = 1;
        iVar4 = DAT_029620a4;
      }
    }
    piVar3 = piVar3 + 0x16;
  } while ((int)piVar3 < 0x292fb60);
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  return;
}

