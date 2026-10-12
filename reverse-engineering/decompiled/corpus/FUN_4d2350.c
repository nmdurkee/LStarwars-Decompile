/* Ghidra analysis pseudocode, not original source.
 * ev_9ea77467f72f0a730098339cc8760ef11d2ea4126d873e77c8bb761228bbcc9d
 * Entry: 0x4d2350; label: FUN_004d2350
 */

void FUN_004d2350(byte *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  if (((param_1 != (byte *)0x0) && (param_2 != 0)) &&
     ((uVar1 = (uint)*param_1, (int)uVar1 < (int)param_2 || (uVar1 = param_2, -1 < (int)param_2))))
  {
    iVar2 = 1;
    if (0 < (int)uVar1) {
      do {
        FUN_0046d270(0,0,1,0,param_1 + (((uint)*param_1 - iVar2) + 5) * 0xc,&DAT_00802500,0x40a00000
                     ,0xffffffff,0x3f800000,0x49f42400,0,1,0);
        iVar2 = iVar2 + 1;
      } while (iVar2 <= (int)uVar1);
    }
    *param_1 = *param_1 - (char)uVar1;
  }
  return;
}

