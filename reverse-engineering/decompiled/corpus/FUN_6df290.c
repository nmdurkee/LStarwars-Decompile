/* Ghidra analysis pseudocode, not original source.
 * ev_a56cd9785cea8d5ba50d25e7433193a9772fbb2aad70e3222a3c6b4dc2863d32
 * Entry: 0x6df290; label: FUN_006df290
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_006df290(void)

{
  switch(DAT_00826494) {
  default:
    return (float10)1.3333334;
  case 1:
    return (float10)1.7777778;
  case 2:
    return (float10)1.6;
  case 3:
    return (float10)_DAT_02976bf8;
  }
}

