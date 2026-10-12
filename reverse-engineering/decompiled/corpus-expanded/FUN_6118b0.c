/* Ghidra pseudocode, not original source.
 * ev_4979805bbb21a8904736e4a261aef1b5206e58d1861917e5f468ac2db6a4df52
 * Entry: 0x6118b0; label: FUN_006118b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006118b0(int param_1)

{
  int in_EAX;
  uint uVar1;
  
  uVar1 = in_EAX - param_1 & 0xffff;
  if (0x7fff < uVar1) {
    uVar1 = uVar1 - 0x10000;
  }
  return uVar1;
}

