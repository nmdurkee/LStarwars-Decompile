/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5be590; label: FUN_005be590
 */

uint FUN_005be590(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_2 + param_1 & 0xffff;
  if (0x7fff < uVar1) {
    uVar1 = uVar1 - 0x10000;
  }
  return uVar1;
}

