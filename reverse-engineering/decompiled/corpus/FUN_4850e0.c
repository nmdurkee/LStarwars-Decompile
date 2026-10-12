/* Ghidra analysis pseudocode, not original source.
 * ev_6a5348c5de1b6aa473bf814c408ae5ab94878b8c78b78ea0d14786caa34bcd70
 * Entry: 0x4850e0; label: FUN_004850e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004850e0(void)

{
  int iVar1;
  
  iVar1 = FUN_006e6b90();
  return (float10)((_DAT_007fc310 - _DAT_007fc314) * (float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] +
                  _DAT_007fc314);
}

