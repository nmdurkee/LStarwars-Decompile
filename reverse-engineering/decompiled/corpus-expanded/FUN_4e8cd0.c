/* Ghidra pseudocode, not original source.
 * ev_0e37ff2b068f2f451a629821c3494056628992f54992bdfe8536c4096373c130
 * Entry: 0x4e8cd0; label: FUN_004e8cd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e8cd0(void)

{
  if ((((DAT_00951b50 == 0) && (DAT_0088a558 != 0)) && ((*(byte *)(DAT_0088a558 + 0x2a) & 1) == 0))
     && ((DAT_0087aa5c != 0 && (0.0 < *(float *)(DAT_0087aa5c + 0x28))))) {
    *(ushort *)(DAT_0088a558 + 0x2a) = *(ushort *)(DAT_0088a558 + 0x2a) | 1;
  }
  FUN_005a9d40();
  return;
}

