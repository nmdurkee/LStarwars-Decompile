/* Ghidra analysis pseudocode, not original source.
 * ev_6a5348c5de1b6aa473bf814c408ae5ab94878b8c78b78ea0d14786caa34bcd70
 * Entry: 0x488630; label: FUN_00488630
 */

void FUN_00488630(void)

{
  int *piVar1;
  
  piVar1 = &DAT_0093d7f0;
  do {
    if (*piVar1 != 0) {
      FUN_004882d0(*piVar1,0);
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x93d810);
  return;
}

