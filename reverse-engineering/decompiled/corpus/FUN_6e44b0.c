/* Ghidra analysis pseudocode, not original source.
 * ev_14516b90afd78e4126f0b3f4a370dbc2a5912f8e0102dea09dbec3c8384d0f78
 * Entry: 0x6e44b0; label: FUN_006e44b0
 */

void FUN_006e44b0(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_ECX = 0xffffffff;
  in_ECX[1] = 0xffffffff;
  in_ECX[2] = 0xffffffff;
  in_ECX[3] = 0xffffffff;
  in_ECX[4] = 0xffffffff;
  in_ECX[5] = 0xffffffff;
  in_ECX[6] = 0xffffffff;
  in_ECX[7] = 0xffffffff;
  in_ECX[8] = 0xffffffff;
  in_ECX[9] = 0xffffffff;
  in_ECX[10] = 0xffffffff;
  puVar2 = in_ECX + 0xb;
  for (iVar1 = 0x70; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
  }
  in_ECX[0x7b] = 0xffffffff;
  in_ECX[0x7c] = 0xffffffff;
  in_ECX[0x7d] = 0xffffffff;
  in_ECX[0x7e] = 0xffffffff;
  in_ECX[0x7f] = 0xffffffff;
  in_ECX[0x80] = 0xffffffff;
  in_ECX[0x81] = 0xffffffff;
  in_ECX[0x82] = 0xffffffff;
  in_ECX[0x83] = 0xffffffff;
  in_ECX[0x84] = 0xffffffff;
  in_ECX[0x85] = 0xffffffff;
  in_ECX[0x86] = 0xffffffff;
  in_ECX[0x87] = 0xffffffff;
  return;
}

