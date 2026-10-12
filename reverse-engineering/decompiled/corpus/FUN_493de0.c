/* Ghidra analysis pseudocode, not original source.
 * ev_f3574efba8633d4b71eb16d1e05784af9695c720a67aab99b2425d0d63eee0b9
 * Entry: 0x493de0; label: FUN_00493de0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00493de0(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_00574e20();
  if ((DAT_0093b328 == 0) && (iVar1 == -1)) {
    FUN_006d6c40(0x3f);
    FUN_006d6c40(0x40);
    FUN_006d6c40(0x41);
    FUN_006d6c40(0x42);
    iVar1 = DAT_009253b8;
    if (DAT_009253b8 != 0) {
      puVar2 = &DAT_0087b710;
      do {
        *puVar2 = puVar2[-1];
        puVar2 = puVar2 + -1;
      } while (0x87b6d8 < (int)puVar2);
      _DAT_0087b6d8 = iVar1;
      return;
    }
  }
  else {
    _memset(&DAT_0087b6d8,0,0x3c);
  }
  return;
}

