/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4dfef0; label: FUN_004dfef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004dfef0(void)

{
  int iVar1;
  
  if (DAT_00951b50 == 0) {
    iVar1 = FUN_0055ce20((int)DAT_007f1a08,1,1,1,0);
    if (((iVar1 != 0) && (DAT_00882b34 != 0)) && (*(float *)(DAT_00882b34 + 0x28) == 1.0)) {
      FUN_004ba2d0();
      return;
    }
  }
  return;
}

