/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x449e10; label: FUN_00449e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00449e10(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = DAT_0291f664;
  if (0 < DAT_0081020c) {
    do {
      if (((*(byte *)(iVar1 + 0x144) & 1) != 0) && (*(code **)(iVar1 + 0x1c0) == FUN_0042d000)) {
        FUN_0064ac90(iVar1,0);
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x220;
    } while (iVar2 < DAT_0081020c);
  }
  return 1;
}

