/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fc360; label: FUN_004fc360
 */

short FUN_004fc360(undefined4 param_1)

{
  byte bVar1;
  short sVar2;
  
  bVar1 = FUN_004fc2d0(param_1);
  sVar2 = FUN_004fc2d0(param_1);
  return sVar2 * 0x100 + (ushort)bVar1;
}

