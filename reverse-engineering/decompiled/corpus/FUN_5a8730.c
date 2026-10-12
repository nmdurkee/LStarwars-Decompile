/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a8730; label: FUN_005a8730
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a8730(void)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 *in_EAX;
  int in_ECX;
  
  uVar1 = (&DAT_029899a0)[in_ECX + 0x4000 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[in_ECX >> 1 & 0x7fff];
  *in_EAX = _DAT_008065c0;
  in_EAX[1] = _DAT_008065c4;
  in_EAX[2] = _DAT_008065c8;
  in_EAX[3] = _DAT_008065cc;
  in_EAX[4] = 0;
  in_EAX[5] = uVar1;
  in_EAX[6] = fVar2;
  in_EAX[7] = 0;
  in_EAX[8] = 0;
  in_EAX[9] = -fVar2;
  in_EAX[10] = uVar1;
  in_EAX[0xb] = 0;
  in_EAX[0xc] = _DAT_008065f0;
  in_EAX[0xd] = _DAT_008065f4;
  in_EAX[0xe] = _DAT_008065f8;
  in_EAX[0xf] = _DAT_008065fc;
  return;
}

