/* Ghidra pseudocode, not original source.
 * ev_5992982d2bd497dd48371876a88a1935c49ce47518269efcef374836dc281717
 * Entry: 0x499920; label: FUN_00499920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00499920(void)

{
  float local_8;
  float local_4;
  
  local_8 = 0.0;
  if (DAT_00951288 == 0) {
    return (float10)0.0;
  }
  local_4 = 0.0;
  if ((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) {
    local_8 = *(float *)(DAT_0093d7f0 + 0xdc8) + 0.0;
    local_4 = 1.0;
  }
  if ((DAT_0093d7f4 != 0) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) {
    local_8 = *(float *)(DAT_0093d7f4 + 0xdc8) + local_8;
    local_4 = local_4 + 1.0;
  }
  if (1.0 < local_4) {
    local_8 = local_8 / local_4;
  }
  if ((float10)0.25 <= (float10)local_8) {
    return (float10)local_8;
  }
  return (float10)(float)(float10)0.25;
}

