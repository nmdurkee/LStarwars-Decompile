/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50b360; label: FUN_0050b360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0050b360(void)

{
  if (DAT_00921d44 != 0) {
    switch((&DAT_00800aa8)[(short)(&DAT_00921454)[DAT_00800944 * 0x70] * 7]) {
    case 0x3e9:
    case 0x3ef:
    case 0x3f1:
    case 0x3f6:
    case 0x3f7:
      return 1;
    }
  }
  return 0;
}

