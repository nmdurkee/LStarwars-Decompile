/* Ghidra pseudocode, not original source.
 * ev_62401c78f713d82b54f61245081db5d782857868d5d6aacf9838dab8303215ce
 * Entry: 0x742120; label: FUN_00742120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00742120(void)

{
  float *in_EAX;
  uint in_ECX;
  
  *in_EAX = (float)(in_ECX & 0xff) / 255.0;
  in_EAX[1] = (float)((int)in_ECX >> 8 & 0xff) / 255.0;
  in_EAX[2] = (float)((int)in_ECX >> 0x10 & 0xff) / 255.0;
  in_EAX[3] = (float)((int)in_ECX >> 0x18 & 0xff) / 255.0;
  return;
}

