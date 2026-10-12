/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x614820; label: FUN_00614820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00614820(void)

{
  undefined4 *in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  in_ECX[1] = &PTR_FUN_0076ac30;
  *in_ECX = &PTR_FUN_0076ac6c;
  in_ECX[1] = &PTR_FUN_0076ac44;
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
  DAT_02973b9c = FUN_00613db0;
  return;
}

