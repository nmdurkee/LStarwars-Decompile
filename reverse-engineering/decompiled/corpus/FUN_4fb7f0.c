/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fb7f0; label: FUN_004fb7f0
 */

uint FUN_004fb7f0(undefined4 param_1)

{
  uint3 in_ECX;
  undefined4 uStack_4;
  
  uStack_4 = (uint)in_ECX;
  FUN_004fb550(param_1,(int)&uStack_4 + 3,1);
  return uStack_4 >> 0x18;
}

