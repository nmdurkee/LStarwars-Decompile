/* Ghidra analysis pseudocode, not original source.
 * ev_a85358c7a67f9df9af49bd13a9e5d6f2df9e1c4faca93f034535aa61df0d1386
 * Entry: 0x5f8cb0; label: FUN_005f8cb0
 */

void FUN_005f8cb0(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((*DAT_02854bc4 != 0) && ((param_1 & 0x100) != 0)) {
    uVar1 = 1;
  }
  if ((DAT_02854bc4[0x1c] != 0) && ((param_1 & 0x200) != 0)) {
    uVar1 = uVar1 | 6;
  }
  if (uVar1 != 0) {
    FUN_006e45e0(0,0,uVar1,
                 ((((int)param_2 >> 0x18) * 0x100 + (param_2 & 0xff)) * 0x100 +
                 (param_2 >> 8 & 0xff)) * 0x100 + ((int)param_2 >> 0x10 & 0xffU),0x3f800000,0);
  }
  return;
}

