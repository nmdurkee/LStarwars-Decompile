/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4dfdf0; label: thunk_FUN_004ddd60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void thunk_FUN_004ddd60(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  
  iVar3 = 0;
  if ('\0' < *(char *)(DAT_00882b2c + 1)) {
    puVar5 = &DAT_00882ad0;
    do {
      iVar1 = FUN_005cfac0(puVar5);
      if (iVar1 != 0) {
        uVar2 = FUN_005d0330(puVar5);
        FUN_005f33b0(&DAT_00882b60,uVar2);
      }
      iVar3 = iVar3 + 1;
      puVar5 = puVar5 + 0xc;
    } while (iVar3 < *(char *)(DAT_00882b2c + 1));
  }
  iVar3 = 0;
  puVar4 = &DAT_00888fe0;
  do {
    if ((iVar3 == *(char *)(DAT_00882b2c + 3) + -3) || (*(char *)(DAT_00882b2c + 3) == '\0')) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
    FUN_005cfc00(puVar4,uVar2);
    puVar4 = puVar4 + 3;
    iVar3 = iVar3 + 1;
  } while ((int)puVar4 < 0x889004);
  return;
}

