/* Ghidra pseudocode, not original source.
 * ev_d4a7937fff77c5bbe199b0bfbeb7b7598feaf173902b06fa34e0deca16dde16c
 * Entry: 0x68d120; label: FUN_0068d120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068d120(void)

{
  int iVar1;
  undefined2 uVar2;
  
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    uVar2 = FUN_006e6b90();
    *(undefined2 *)(iVar1 + 0x16) = uVar2;
    FUN_0068cfd0();
  }
  return;
}

