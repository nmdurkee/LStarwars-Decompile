/* Ghidra analysis pseudocode, not original source.
 * ev_49dad5f20e053bf764d7eecccea7d519a0835f455b7dcdd298ee46307ff6e048
 * Entry: 0x60c6e0; label: FUN_0060c6e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060c6e0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  if ((DAT_02854d9c != 0) && (DAT_02854f30 != (int *)0x0)) {
    do {
      piVar5 = DAT_02854f30;
      piVar1 = (int *)*DAT_02854f30;
      puVar2 = (undefined4 *)DAT_02854f30[4];
      puVar4 = (undefined4 *)DAT_02854f30[3];
      while (puVar4 != (undefined4 *)0x0) {
        puVar3 = (undefined4 *)*puVar4;
        FUN_00609b90(puVar4);
        puVar4 = puVar3;
      }
      for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
      }
      if ((int *)piVar5[1] != (int *)0x0) {
        *(int *)piVar5[1] = *piVar5;
      }
      if (*piVar5 != 0) {
        *(int *)(*piVar5 + 4) = piVar5[1];
      }
      _DAT_02854f38 = _DAT_02854f38 + -1;
      DAT_02854f30 = piVar1;
    } while (piVar1 != (int *)0x0);
    DAT_02854f30 = (int *)0x0;
  }
  return;
}

