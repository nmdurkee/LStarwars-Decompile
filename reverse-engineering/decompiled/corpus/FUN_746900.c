/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x746900; label: FUN_00746900
 */

undefined4 FUN_00746900(byte *param_1)

{
  byte bVar1;
  
  if (((byte)(&DAT_0297daa0)[*param_1] >> 1 & 1) != 0) {
    bVar1 = param_1[1];
    while( true ) {
      if (bVar1 == 0) {
        return 1;
      }
      if (((byte)(&DAT_0297daa0)[bVar1] >> 1 & 1) == 0) break;
      bVar1 = param_1[2];
      param_1 = param_1 + 1;
    }
  }
  return 0;
}

