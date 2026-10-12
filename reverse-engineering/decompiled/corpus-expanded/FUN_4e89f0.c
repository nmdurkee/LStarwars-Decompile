/* Ghidra pseudocode, not original source.
 * ev_0e37ff2b068f2f451a629821c3494056628992f54992bdfe8536c4096373c130
 * Entry: 0x4e89f0; label: FUN_004e89f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e89f0(int param_1)

{
  if ((DAT_0087a96c != (int *)0x0) && (*DAT_0087a96c != 0)) {
    if ((DAT_0088a288 == '\n') && ((*(byte *)(*DAT_0087a96c + 0x17) & 8) == 0)) {
      FUN_0055a250(*(undefined4 *)(param_1 + 0x2ac8),DAT_0087a96c,1,1);
      return;
    }
    FUN_0055a2b0(*(undefined4 *)(param_1 + 0x2ac8),DAT_0087a96c,0,1);
  }
  return;
}

