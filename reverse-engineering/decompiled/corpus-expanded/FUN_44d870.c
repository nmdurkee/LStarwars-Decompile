/* Ghidra pseudocode, not original source.
 * ev_89fddb9d43176fe460e635fa694f7b202ecc9b6cc52422bc9fe5e2fbe10c5c63
 * Entry: 0x44d870; label: FUN_0044d870
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0044d870(void)

{
  uint uVar1;
  int iVar2;
  
  if (DAT_00876580 == 0) {
    if (DAT_007f39e4 == 0) {
      uVar1 = FUN_00407d00();
    }
    else {
      uVar1 = FUN_004cbf70();
    }
  }
  else {
    uVar1 = FUN_004817e0();
  }
  if (uVar1 == 0) {
    iVar2 = FUN_004f8b10();
    if (iVar2 == 0) {
      return 0x80000000;
    }
    iVar2 = FUN_004f8b10();
    if (iVar2 == 0) {
      return DAT_00950d68;
    }
    iVar2 = FUN_004f8b10();
    if (iVar2 == 0) {
      return DAT_00950d6c;
    }
    iVar2 = FUN_004f8b10();
    uVar1 = ~-(uint)(iVar2 != 0) & _DAT_00950d70;
  }
  return uVar1;
}

