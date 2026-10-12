/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x553780; label: FUN_00553780
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00553780(void)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 *in_EAX;
  int in_ECX;
  
  uVar1 = (&DAT_029899a0)[in_ECX + 0x4000 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[in_ECX >> 1 & 0x7fff];
  *in_EAX = uVar1;
  in_EAX[1] = 0;
  in_EAX[2] = -fVar2;
  in_EAX[3] = 0;
  in_EAX[4] = _DAT_008065d0;
  in_EAX[5] = _DAT_008065d4;
  in_EAX[6] = _DAT_008065d8;
  in_EAX[7] = _DAT_008065dc;
  in_EAX[8] = fVar2;
  in_EAX[9] = 0;
  in_EAX[0xb] = 0;
  in_EAX[10] = uVar1;
  in_EAX[0xc] = _DAT_008065f0;
  in_EAX[0xd] = _DAT_008065f4;
  in_EAX[0xe] = _DAT_008065f8;
  in_EAX[0xf] = _DAT_008065fc;
  return;
}

