/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x614820; label: FUN_00614820
 */

void FUN_00614820(void)

{
  undefined4 *in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  in_ECX[1] = &PTR_LAB_0076ac30;
  *in_ECX = &PTR_LAB_0076ac6c;
  in_ECX[1] = &PTR_LAB_0076ac44;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  puVar1 = in_ECX + 0x346d;
  iVar2 = 0x3f;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1 = puVar1 + 3;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  in_ECX[3] = 0;
  in_ECX[10] = 0xffffffff;
  in_ECX[0xb] = 0xffffffff;
  DAT_02900a40 = in_ECX;
  DAT_02973b9c = &LAB_00613db0;
  return;
}

