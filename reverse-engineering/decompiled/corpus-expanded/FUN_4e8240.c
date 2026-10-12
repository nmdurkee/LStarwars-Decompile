/* Ghidra pseudocode, not original source.
 * ev_0e37ff2b068f2f451a629821c3494056628992f54992bdfe8536c4096373c130
 * Entry: 0x4e8240; label: FUN_004e8240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e8240(void)

{
  int iVar1;
  
  if (DAT_00951b50 == 0) {
    iVar1 = FUN_0055ce20((int)DAT_007f1908,1,1,1,0);
    if (iVar1 != 0) {
      if (DAT_0087aa5c == 0) {
        return;
      }
      if (*(float *)(DAT_0087aa5c + 0x28) == 1.0) {
        FUN_004ba2d0();
        return;
      }
    }
    if ((DAT_0087aa5c != 0) && (*(float *)(DAT_0087aa5c + 0x28) == 0.0)) {
      FUN_004ba2d0();
      return;
    }
  }
  return;
}

