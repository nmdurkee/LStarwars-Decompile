/* Ghidra analysis pseudocode, not original source.
 * ev_a85358c7a67f9df9af49bd13a9e5d6f2df9e1c4faca93f034535aa61df0d1386
 * Entry: 0x5f8fd0; label: FUN_005f8fd0
 */

void FUN_005f8fd0(void)

{
  undefined4 *puVar1;
  
  if (DAT_0080e980 == -1) {
    puVar1 = (undefined4 *)
             FUN_004eef40(0x28,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nutex_pc.cpp",0xd9)
    ;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[9] = 0;
    puVar1[7] = s_DDS___0080c0f0;
    puVar1[8] = 0x2080;
    DAT_0080e980 = FUN_005e5210(puVar1);
  }
  return;
}

